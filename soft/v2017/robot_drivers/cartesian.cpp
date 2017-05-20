#include "cartesian.hpp"

#include "robot.hpp"
#include "gyro.hpp"

#include <math.h>

void Cartesian::Updater::update(void) {
  if(Robot::instance().state() != RUN) {
    setState(STOP);
  }

  if(Gyro::instance().state() != RUN) {
    setState(STOP);
  }

  if(state() == RUN) {
    Robot::instance().speed().put(0);
    if(_cmd_vx != 0 || _cmd_vy != 0) {
      float cmd_a = atan2f(_cmd_vy, _cmd_vx);
      float a = Gyro::instance().angle().get();
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

      Robot::instance().angle().put(cmd_a+adiv);
      if(fabs(cmd_a-amod) < 0.5*3.14/180.0) {
        speed_mul *= cosf(cmd_a-amod);
        Robot::instance().speed().put(speed_mul*sqrt(_cmd_vx*_cmd_vx + _cmd_vy*_cmd_vy));
      }
    }
    else {
      Robot::instance().angle().put(_cmd_a);
    }
  }
}
