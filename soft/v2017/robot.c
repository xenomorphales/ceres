#include "robot.h"

#include "gyro.h"
#include "motors.h"

#include <stdint.h>

static float _speed_cmd = 0;
static float _distance = 0;
static float _speed_p = 1;

static float _angle_cmd = 0;

static float _angle_p = 100;
static const float _angle_i = 0;
static const float _angle_d = 0;

static float _angle_err_sum = 0;
static float _angle_err_last = 0;

void robot_update(void) {
  _distance += _speed_cmd;

  const float cur = gyro_get_angle();
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

  motors_set_left(left);
  motors_set_right(right);

  _angle_err_last = err;
}

int robot_init(void) {
  if(gyro_init() < 0) {
    return -1;
  }

  if(motors_init() < 0) {
    return -2;
  }

  _angle_cmd = robot_get_angle();
  _speed_cmd = 0;
  _distance = 0;
  _angle_err_sum = 0;
  _angle_err_last = 0;

  return 0;
}

void robot_set_speed(float speed) {
  _speed_cmd = speed;
}

void robot_set_angle(float angle) {
  _angle_cmd = angle;
}

float robot_get_speed(void) {
  return _speed_cmd;
}

float robot_get_angle(void) {
  return gyro_get_angle();
}

float robot_get_distance(void) {
  return _distance;
}
