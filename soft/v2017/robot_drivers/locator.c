#include "locator.h"

//#include "robot.h"
//#include "gyro.h"

#include <math.h>

static float x;
static float y;

void locator_update(void) {
  /*
  float angle = robot_get_angle();
  float speed = robot_get_speed();

  x += cosf(angle) * speed;
  y += sinf(angle) * speed;
  */
}

int locator_init(void) {
  x = 0;
  y = 0;

  return 0;
}

float locator_get_x(void) {
  return x;
}

float locator_get_y(void) {
  return y;
}

void locator_reset(float new_x, float new_y, float new_angle) {
  //gyro_set_angle(new_angle);
  x = new_x;
  y = new_y;
}
