#include "arm.hpp"

#include "feetech.h"
#include "dynamixel.h"

#include "thread.h"
#include "xtimer.h"

#include <stdint.h>

#define ARM_SERVO_NUMOF (5)

#define SERVO_DELTA (10)

typedef enum {
  RETRACTED       = 0,
  DEPLOYED_MIDDLE = 1,
  DEPLOYED_DOWN   = 2,
} pose_t;

typedef enum {
  STATE_OFF,
  STATE_INIT,
  STATE_RETRACTED,
  STATE_DEPLOYED,
  STATE_MOVING_RETRACT_1,
  STATE_MOVING_RETRACT_2,
  STATE_MOVING_DEPLOY_1,
  STATE_MOVING_DEPLOY_2,

  STATE_ERROR
} state_t;

typedef enum {
  EVENT_INIT,
  EVENT_DEPLOY,
  EVENT_RETRACT,
  EVENT_DONE,

  EVENT_EMPTY
} event_t;

static uint8_t _left_ids[ARM_SERVO_NUMOF] = {
  10, 11, 12, 13, 14
};

static uint8_t _right_ids[ARM_SERVO_NUMOF] = {
  20, 21, 22, 23, 24
};

static uint16_t _left_poses[3][ARM_SERVO_NUMOF] = {
  {170,  80, 540, 270, 200}, // RETRACTED
  {512, 512, 630, 270, 130}, // DEPLOYED_MIDDLE
  {512, 512, 100, 270, 130}, // DEPLOYED_DOWN
};

static uint16_t _right_poses[3][ARM_SERVO_NUMOF] = {
  {140, 140, 540, 270, 200}, // RETRACTED
  {512, 512, 512, 270, 150}, // DEPLOYED_MIDDLE
  {512, 512, 100, 270, 150}, // DEPLOYED_DOWN
};

static uint8_t _buffer[64];
uart_half_duplex_t _stream;

static state_t _left_state = STATE_OFF;
static event_t _left_event = EVENT_EMPTY;

static state_t _right_state = STATE_OFF;
static event_t _right_event = EVENT_EMPTY;

static char arm_thread_stack[THREAD_STACKSIZE_MAIN];

void _servo_enable(uint8_t id) {
  feetech_t dev;
  feetech_init(&dev, &_stream, id);
  feetech_write8(&dev, SCS15_TORQUE_ENABLE, 1);
  feetech_write16(&dev, SCS15_GOAL_TIME, 512);
}

void _servo_set_angle(uint8_t id, uint16_t angle) {
  feetech_t dev;
  feetech_init(&dev, &_stream, id);
  feetech_write16(&dev, SCS15_GOAL_POSITION, angle);
}

bool _servo_check_angle(uint8_t id, uint16_t angle) {
  uint16_t res = 0xFFFF;
  feetech_t dev;
  feetech_init(&dev, &_stream, id);
  feetech_read16(&dev, SCS15_PRESENT_POSITION, &res);

  return abs((int)res-(int)angle) < SERVO_DELTA;
}

void _arm_enable(uint8_t ids[ARM_SERVO_NUMOF]) {
  for(size_t i = 0 ; i < ARM_SERVO_NUMOF ; i++) {
    _servo_enable(ids[i]);
  }
}

void _arm_set_pose(uint8_t ids[ARM_SERVO_NUMOF], uint16_t pose[ARM_SERVO_NUMOF]) {
  for(size_t i = 0 ; i < ARM_SERVO_NUMOF ; i++) {
    _servo_set_angle(ids[i], pose[i]);
  }
}

bool _arm_check_pose(uint8_t ids[ARM_SERVO_NUMOF], uint16_t pose[ARM_SERVO_NUMOF]) {
  for(size_t i = 0 ; i < ARM_SERVO_NUMOF ; i++) {
    if(!_servo_check_angle(ids[i], pose[i])) {
      return false;
    }
  }
  return true;
}

static inline event_t _update_event(uint8_t ids[ARM_SERVO_NUMOF], uint16_t poses[3][ARM_SERVO_NUMOF], state_t state) {
  if(state == STATE_OFF) {
  }
  else if(state == STATE_INIT) {
    return EVENT_DONE;
  }
  else if(state == STATE_MOVING_DEPLOY_1) {
    if(_arm_check_pose(ids, poses[DEPLOYED_MIDDLE])) {
      return EVENT_DONE;
    }
  }
  else if(state == STATE_MOVING_DEPLOY_2) {
    if(_arm_check_pose(ids, poses[DEPLOYED_DOWN])) {
      return EVENT_DONE;
    }
  }
  else if(state == STATE_MOVING_RETRACT_1) {
    if(_arm_check_pose(ids, poses[DEPLOYED_MIDDLE])) {
      return EVENT_DONE;
    }
  }
  else if(state == STATE_MOVING_RETRACT_2) {
    if(_arm_check_pose(ids, poses[RETRACTED])) {
      return EVENT_DONE;
    }
  }

  return EVENT_EMPTY;
}

static inline state_t _update_state(uint8_t ids[ARM_SERVO_NUMOF], uint16_t poses[3][ARM_SERVO_NUMOF], state_t state, event_t event) {
  if(state == STATE_OFF) {
    if(event == EVENT_INIT) {
      _arm_enable(ids);
      return STATE_INIT;
    }
  }
  else if(state == STATE_INIT) {
    if(event == EVENT_DONE) {
      _arm_set_pose(ids, poses[DEPLOYED_MIDDLE]);
      return STATE_MOVING_RETRACT_1;
    }
  }
  else if(state == STATE_RETRACTED) {
    if(event == EVENT_DEPLOY) {
      _arm_set_pose(ids, poses[DEPLOYED_MIDDLE]);
      return STATE_MOVING_DEPLOY_1;
    }
  }
  else if(state == STATE_DEPLOYED) {
    if(event == EVENT_RETRACT) {
      _arm_set_pose(ids, poses[DEPLOYED_MIDDLE]);
      return STATE_MOVING_RETRACT_1;
    }
  }
  else if(state == STATE_MOVING_DEPLOY_1) {
    if(event == EVENT_DONE) {
      _arm_set_pose(ids, poses[DEPLOYED_DOWN]);
      return STATE_MOVING_DEPLOY_2;
    }
  }
  else if(state == STATE_MOVING_DEPLOY_2) {
    if(event == EVENT_DONE) {
      return STATE_DEPLOYED;
    }
  }
  else if(state == STATE_MOVING_RETRACT_1) {
    if(event == EVENT_DONE) {
      _arm_set_pose(ids, poses[RETRACTED]);
      return STATE_MOVING_RETRACT_2;
    }
  }
  else if(state == STATE_MOVING_RETRACT_2) {
    if(event == EVENT_DONE) {
      return STATE_RETRACTED;
    }
  }

  return state;
}

static inline Arm::ArmState _arm_state(state_t state) {
  switch(state) {
    case STATE_DEPLOYED:
      return Arm::ARM_DEPLOYED;
    case STATE_RETRACTED:
      return Arm::ARM_RETRACTED;
    case STATE_INIT:
    case STATE_MOVING_DEPLOY_1:
    case STATE_MOVING_DEPLOY_2:
    case STATE_MOVING_RETRACT_1:
    case STATE_MOVING_RETRACT_2:
      return Arm::ARM_MOVING;
    case STATE_OFF:
      return Arm::ARM_DISABLED;
    default:
      return Arm::ARM_ERROR;
  }
  return Arm::ARM_ERROR;
}

static void* _arm_update_thread(void* arg) {
  (void) arg;
  xtimer_ticks32_t last_wakeup = xtimer_now();

  while(1) {
    xtimer_periodic_wakeup(&last_wakeup, 1000000UL/10UL);

    // LEFT
    if(_left_event == EVENT_EMPTY) {
      _left_event = _update_event(_left_ids, _left_poses, _left_state);
    }

    _left_state = _update_state(_left_ids, _left_poses, _left_state, _left_event);
    _left_event = EVENT_EMPTY;

    // RIGHT
    if(_right_event == EVENT_EMPTY) {
      _right_event = _update_event(_right_ids, _right_poses, _right_state);
    }

    _right_state = _update_state(_right_ids, _right_poses, _right_state, _right_event);
    _right_event = EVENT_EMPTY;
  }

  return NULL;
}

Arm::Arm(void) {
  uart_half_duplex_params_t params = {};
  params.uart = UART_DEV(1);
  params.baudrate = 1000000;
  params.dir = UART_HALF_DUPLEX_DIR_NONE;

  int ret = uart_half_duplex_init(&_stream, _buffer, sizeof(_buffer), &params);
  if(ret != UART_HALF_DUPLEX_OK) {
    setState(ERROR);
  }

  _left_event = EVENT_INIT;
  _right_event = EVENT_INIT;

  thread_create(arm_thread_stack, sizeof(arm_thread_stack),
                THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_STACKTEST,
                _arm_update_thread, NULL, "arm");
}

void Arm::Left::deploy(void) {
  _left_event = EVENT_DEPLOY;
}

void Arm::Left::retract(void) {
  _left_event = EVENT_RETRACT;
}

Arm::ArmState Arm::Left::state(void) {
  return _arm_state(_left_state);
}

void Arm::Right::deploy(void) {
  _right_event = EVENT_DEPLOY;
}

void Arm::Right::retract(void) {
  _right_event = EVENT_RETRACT;
}

Arm::ArmState Arm::Right::state(void) {
  return _arm_state(_right_state);
}
