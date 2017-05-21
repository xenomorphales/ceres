#include "robot.hpp"

#include "gyro.hpp"
#include "motors.hpp"

#include <stdint.h>

void Robot::Updater::update(void) {
  if(Gyro::instance().state() != RUN) {
    setState(STOP);
  }

  if(Motors::instance().state() != RUN) {
    setState(STOP);
  }

  if(state() == RUN) {
    _distance += _speed_cmd / FREQ;

    const float cur = Gyro::instance().angle().get();
    const float err = _angle_cmd - cur;

    const float p = err * _config.angle_p;

    const int angle = (p);
    const int dist = _speed_cmd * _config.speed_cmd_coeff;

    const int left  = dist + angle;
    const int right = dist - angle;

    Motors::instance().left().put(left);
    Motors::instance().right().put(right);
  }
}

Robot::Robot(void) {
  _angle_cmd = Gyro::instance().angle().get();
  _speed_cmd = 0;
  _distance = 0;
}
