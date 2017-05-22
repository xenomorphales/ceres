#include "funny.hpp"

#include "servo.hpp"

static void _disable(int id) {
  feetech_t dev;
  feetech_init(&dev, &ServoBus::instance().stream(), id);
  feetech_write8(&dev, SCS15_TORQUE_ENABLE, 0);
}

static void _set(int id, int angle) {
  feetech_t dev;
  feetech_init(&dev, &ServoBus::instance().stream(), id);
  feetech_write8(&dev, SCS15_TORQUE_ENABLE, 1);
  feetech_write16(&dev, SCS15_GOAL_TIME, 512);
  feetech_write16(&dev, SCS15_GOAL_POSITION, angle);
}

Funny::Funny(void) {
  if(feetech_ping(&ServoBus::instance().stream(), 30) != FEETECH_OK) {
    setState(ERROR);
    return;
  }

  if(feetech_ping(&ServoBus::instance().stream(), 31) != FEETECH_OK) {
    setState(ERROR);
    return;
  }

  disable();

  setState(RUN);
}

void Funny::disable(void) {
  _disable(30);
  _disable(31);
}

void Funny::release(void) {
  _set(30, 512);
  _set(31, 512);
}
