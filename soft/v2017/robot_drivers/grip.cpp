#include <arm.hpp>

#include <servo.hpp>

static void _set(uint8_t id, uint16_t pos) {
  dynamixel_t dev;
  dynamixel_init(&dev, &ServoBus::instance().stream(), id);
  dynamixel_write16(&dev, XL320_MAX_TORQUE, 150);
  dynamixel_write16(&dev, XL320_GOAL_TORQUE, 1023);
  dynamixel_write16(&dev, XL320_GOAL_VELOCITY, 800);
  dynamixel_write8(&dev, XL320_TORQUE_ENABLE, 1);
  dynamixel_write16(&dev, XL320_GOAL_POSITION, pos);
}

static int _get_pos_diff(uint8_t id) {
  uint16_t goal = 0;
  uint16_t present = 0;

  dynamixel_t dev;
  dynamixel_init(&dev, &ServoBus::instance().stream(), id);
  dynamixel_read16(&dev, XL320_GOAL_POSITION, &goal);
  dynamixel_read16(&dev, XL320_PRESENT_POSITION, &present);

  return (int)goal - (int)present;
}

static inline bool _not_reached(uint8_t id) {
  return abs(_get_pos_diff(id)) > 20;
}

static bool _moving(uint8_t id) {
  uint16_t speed = 0;

  dynamixel_t dev;
  dynamixel_init(&dev, &ServoBus::instance().stream(), id);
  dynamixel_read16(&dev, XL320_PRESENT_SPEED, &speed);

  if(abs(speed) < 4) {
    return false;
  }

  return true;
}

void Arm::Left::Grip::open(void) {
  _set(15, 512);
  _set(16, 512);
}

#define CLOSE_POS (280)

void Arm::Left::Grip::close(void) {
  _set(15, CLOSE_POS);
  _set(16, 1024-CLOSE_POS);
}

void Arm::Right::Grip::open(void) {
  _set(25, 512);
  _set(26, 512);
}

void Arm::Right::Grip::close(void) {
  _set(25, CLOSE_POS);
  _set(26, 1024-CLOSE_POS);
}

Arm::GripHoldState Arm::Right::Grip::hold(void) {
  bool left = false;
  if(!_moving(25) && _not_reached(25)) {
    left = true;
  }

  bool right = false;
  if(!_moving(26) && _not_reached(26)) {
    right = true;
  }

  if(right && left) {
    return Arm::BOTH;
  }
  else if(right) {
    return Arm::RIGHT;
  }
  else if(left) {
      return Arm::LEFT;
  }

  return Arm::NONE;
}

Arm::GripHoldState Arm::Left::Grip::hold(void) {
  bool left = false;
  if(!_moving(15) && _not_reached(15)) {
    left = true;
  }

  bool right = false;
  if(!_moving(16) && _not_reached(16)) {
    right = true;
  }

  if(right && left) {
    return Arm::BOTH;
  }
  else if(right) {
    return Arm::RIGHT;
  }
  else if(left) {
      return Arm::LEFT;
  }

  return Arm::NONE;
}
