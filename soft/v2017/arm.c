#include "arm.h"

#include "feetech.h"
#include "dynamixel.h"

#include <stdint.h>

#define ARM_SERVO_NUMOF (5)

#define SERVO_DELTA (10)

typedef enum {
  RETRACTED       = 0,
  DEPLOYED_MIDDLE = 1,
  DEPLOYED_DOWN   = 2,

  NONE            = -1,
  ERROR           = -2,
} state_t;

static uint8_t _left_ids[ARM_SERVO_NUMOF] = {
  10, 11, 12, 13, 14
};

static uint8_t _right_ids[ARM_SERVO_NUMOF] = {
  20, 21, 22, 23, 24
};

static uint16_t _left_states[3][ARM_SERVO_NUMOF] = {
  {256,  80, 512, 270, 130}, // RETRACTED
  {512, 512, 512, 270, 130}, // DEPLOYED_MIDDLE
  {512, 512, 100, 270, 130}, // DEPLOYED_DOWN
};

static uint16_t _right_states[3][ARM_SERVO_NUMOF] = {
  {256,  80, 512, 270, 150}, // RETRACTED
  {512, 512, 512, 270, 150}, // DEPLOYED_MIDDLE
  {512, 512, 100, 270, 150}, // DEPLOYED_DOWN
};

static uint8_t _buffer[32];
static uart_half_duplex_t _stream;

static state_t _left_cur_state = NONE;
static state_t _right_cur_state = NONE;

static state_t _left_goal_state = NONE;
static state_t _right_goal_state = NONE;

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

void _arm_set_state(uint8_t ids[ARM_SERVO_NUMOF], uint16_t state[ARM_SERVO_NUMOF]) {
  for(size_t i = 0 ; i < ARM_SERVO_NUMOF ; i++) {
    _servo_set_angle(ids[i], state[i]);
  }
}

bool _arm_check_state(uint8_t ids[ARM_SERVO_NUMOF], uint16_t state[ARM_SERVO_NUMOF]) {
  for(size_t i = 0 ; i < ARM_SERVO_NUMOF ; i++) {
    if(!_servo_check_angle(ids[i], state[i])) {
      return false;
    }
  }
  return true;
}

static inline void _update(uint8_t ids[ARM_SERVO_NUMOF], uint16_t states[3][ARM_SERVO_NUMOF], state_t* cur, state_t goal) {
  if(*cur != goal) {
    if(*cur != DEPLOYED_MIDDLE) {
      if(goal == RETRACTED) {
        _arm_set_state(ids, states[DEPLOYED_MIDDLE]);
        *cur = DEPLOYED_MIDDLE;
      }
    }
    else {
      if(_arm_check_state(_left_ids, _left_states[DEPLOYED_MIDDLE])) {
        if(goal == DEPLOYED_DOWN || goal == RETRACTED) {
          _arm_set_state(ids, states[goal]);
          *cur = goal;
        }
      }
    }
  }
}

void arm_update(void) {
  _update(_left_ids, _left_states, &_left_cur_state, _left_goal_state);
  _update(_right_ids, _right_states, &_right_cur_state, _right_goal_state);
}

int arm_init(void) {
  uart_half_duplex_params_t params = {
    .uart = UART_DEV(1),
    .baudrate = 1000000,
    .dir = UART_HALF_DUPLEX_DIR_NONE,
  };

  int ret = uart_half_duplex_init(&_stream, _buffer, sizeof(_buffer), &params);
  if(ret != UART_HALF_DUPLEX_OK) {
    return -1;
  }

  _arm_enable(_left_ids);

  _arm_set_state(_left_ids, _left_states[DEPLOYED_MIDDLE]);
  while(!_arm_check_state(_left_ids, _left_states[DEPLOYED_MIDDLE]));

  _arm_set_state(_left_ids, _left_states[RETRACTED]);
  while(!_arm_check_state(_left_ids, _left_states[RETRACTED]));

  _left_cur_state = RETRACTED;
  _left_goal_state = RETRACTED;

  _arm_enable(_right_ids);

  _arm_set_state(_right_ids, _right_states[DEPLOYED_MIDDLE]);
  while(!_arm_check_state(_right_ids, _right_states[DEPLOYED_MIDDLE]));

  _arm_set_state(_right_ids, _right_states[RETRACTED]);
  while(!_arm_check_state(_right_ids, _right_states[RETRACTED]));

  _right_cur_state = RETRACTED;
  _right_goal_state = RETRACTED;

  return 0;
}
