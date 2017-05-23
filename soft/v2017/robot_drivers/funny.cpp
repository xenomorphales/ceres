#include "funny.hpp"

#include "servo.hpp"

static void _disable(int id) {
  feetech_t dev;
  feetech_init(&dev, &ServoBus::instance().stream(), id);
  feetech_write8(&dev, SCS15_TORQUE_ENABLE, 0);
}

static void _set(int id, int angle, bool slow = false) {
  feetech_t dev;
  feetech_init(&dev, &ServoBus::instance().stream(), id);
  feetech_write8(&dev, SCS15_TORQUE_ENABLE, 1);
  if(slow) {
    feetech_write16(&dev, SCS15_GOAL_TIME, 512);
  }
  else {
    feetech_write16(&dev, SCS15_GOAL_TIME, 0);
  }
  feetech_write16(&dev, SCS15_GOAL_POSITION, angle);
}

Funny::Funny(void) {
  /*
  if(feetech_ping(&ServoBus::instance().stream(), 30) != FEETECH_OK) {
    setState(ERROR);
    return;
  }

  if(feetech_ping(&ServoBus::instance().stream(), 31) != FEETECH_OK) {
    setState(ERROR);
    return;
  }
  */

  setState(RUN);
  //disable();
}

void Funny::disable(void) {
  _disable(30);
  _disable(31);
}

void Funny::release(void) {
  if(state() == RUN) {
    _set(30, 512, false);
    _set(31, 512, true);
  }
}
