#include "locator.hpp"

#include "robot.hpp"
#include "gyro.hpp"

#include <math.h>

void Locator::Updater::update(void) {
  if(Robot::instance().state() != RUN) {
    setState(STOP);
  }

  if(Gyro::instance().state() != RUN) {
    setState(STOP);
  }

  if(state() == RUN) {
    float angle = Gyro::instance().angle().get();
    float dist = Robot::instance().speed().get() / FREQ;

    _x += cosf(angle) * dist;
    _y += sinf(angle) * dist;
  }
}
