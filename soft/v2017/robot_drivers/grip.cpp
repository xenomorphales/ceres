#include <arm.hpp>

#include <servo.hpp>

static void _set(uint8_t id, uint16_t pos) {
  dynamixel_t dev;
  dynamixel_init(&dev, &ServoBus::instance().stream(), id);
  dynamixel_write8(&dev, XL320_MAX_TORQUE, 100);
  dynamixel_write8(&dev, XL320_TORQUE_ENABLE, 1);
  dynamixel_write16(&dev, XL320_GOAL_POSITION, pos);
}

void Arm::Left::Grip::open(void) {
  _set(15, 512);
  _set(16, 512);
}

void Arm::Left::Grip::close(void) {
  _set(15, 250);
  _set(16, 750);
}

void Arm::Right::Grip::open(void) {
  _set(25, 512);
  _set(26, 512);
}

void Arm::Right::Grip::close(void) {
  _set(25, 250);
  _set(26, 750);
}
