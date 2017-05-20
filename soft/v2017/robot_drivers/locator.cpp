#include "locator.hpp"

#include "robot.hpp"
#include "gyro.hpp"

#include <math.h>

void Locator::Updater::update(void) {
  if(state() == RUN) {
    float angle = Gyro::instance().angle().get();
    float speed = Robot::instance().speed().get();

    _x += cosf(angle) * speed;
    _y += sinf(angle) * speed;
  }
}
