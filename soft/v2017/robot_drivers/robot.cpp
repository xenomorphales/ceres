#include "robot.hpp"

#include "gyro.hpp"
#include "motors.hpp"

#include <stdint.h>

static float _speed_p = 1;

static float _angle_p = 100;
static const float _angle_i = 0;
static const float _angle_d = 0;

static float _angle_err_sum = 0;
static float _angle_err_last = 0;

void Robot::Updater::update(void) {
  if(Gyro::instance().state() != RUN) {
    setState(STOP);
  }

  if(Motors::instance().state() != RUN) {
    setState(STOP);
  }

  if(state() == RUN) {
    _distance += _speed_cmd;

    const float cur = Gyro::instance().angle().get();
    const float err = _angle_cmd - cur;

    const float diff = _angle_err_last - err;
    _angle_err_sum += err;

    const float p = err * _angle_p;
    const float i = _angle_err_sum * _angle_i;
    const float d = diff * _angle_d;

    const int angle = (p+i+d);
    const int dist = _speed_cmd * _speed_p;

    const int left  = dist + angle;
    const int right = dist - angle;

    Motors::instance().left().put(left);
    Motors::instance().right().put(right);

    _angle_err_last = err;
  }
}

Robot::Robot(void) {
  _angle_cmd = Gyro::instance().angle().get();
  _speed_cmd = 0;
  _distance = 0;
  _angle_err_sum = 0;
  _angle_err_last = 0;
}
