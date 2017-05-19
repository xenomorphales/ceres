#include "cartesian.h"

//#include "robot.h"

#include <math.h>

static float _cmd_vx;
static float _cmd_vy;
static float _cmd_a;

void cartesian_update(void) {
  /*
  //robot_set_speed(0);
  if(_cmd_vx != 0 || _cmd_vy != 0) {
    float cmd_a = atan2f(_cmd_vy, _cmd_vx);
    float a = 0;//robot_get_angle();
    float amod = fmod(a, 3.14*2);
    if(amod<-3.14) amod += 3.14;
    if(amod>3.14)  amod -= 3.14;
    float adiv = a - amod;
    float speed_mul = 1;

    if(amod < cmd_a) {
      if(fabs(cmd_a-amod) > fabs(cmd_a-3.14-amod)) {
        cmd_a -= 3.14;
        speed_mul = -1;
      }
    }
    else {
      if(fabs(cmd_a-amod) > fabs(cmd_a+3.14-amod)) {
        cmd_a += 3.14;
        speed_mul = -1;
      }
    }

    //robot_set_angle(cmd_a+adiv);
    if(fabs(cmd_a-amod) < 0.5*3.14/180.0) {
      speed_mul *= cosf(cmd_a-amod);
      //robot_set_speed(speed_mul*sqrt(_cmd_vx*_cmd_vx + _cmd_vy*_cmd_vy));
    }
  }
  else {
    //robot_set_angle(_cmd_a);
  }
  */
}

int cartesian_init(void) {
  _cmd_vx = 0;
  _cmd_vy = 0;
  _cmd_a = 0;

  return 0;
}

void cartesian_set_speed(float vx, float vy) {
  _cmd_vx = vx;
  _cmd_vy = vy;
}

void cartesian_set_angle(float a) {
  _cmd_a = a;
}
