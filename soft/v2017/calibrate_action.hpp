#ifndef CALIBRATE_ACTION_HPP
#define CALIBRATE_ACTION_HPP

#include "action.hpp"

#include "cartesian.h"
#include "gyro.h"
#include "xtimer.h"

class CalibrateAction : public Action {
public:
  enum Dir { XPOS, XNEG, YPOS, YNEG };

private:
  const Dir _dir;
  const float _coord;

private:
  uint32_t _begining;

public:
  CalibrateAction(Dir dir, float coord)
    : _dir(dir), _coord(coord),
      _begining(0) {
  }

  void update(void) {
    if(state() == WAIT) {
      setState(RUN);
      _begining = xtimer_now_usec();
    }
    else if(state() == RUN) {
      uint32_t now = xtimer_now_usec();

      if(now - _begining < 3000000) {
        if(_dir == XPOS) {
          cartesian_set_speed(1, 0);
        }
        else if(_dir == XNEG) {
          cartesian_set_speed(-1, 0);
        }
        else if(_dir == YPOS) {
          cartesian_set_speed(0, 1);
        }
        else if(_dir == YNEG) {
          cartesian_set_speed(0, -1);
        }
      }
      else if(now - _begining < 4000000) {
        if(_dir == XPOS) {
          gyro_set_angle(0);
          cartesian_set_angle(0);
          cartesian_set_speed(-1, 0);
        }
        else if(_dir == XNEG) {
          gyro_set_angle(3.1415);
          cartesian_set_angle(3.1415);
          cartesian_set_speed(1, 0);
        }
        else if(_dir == YPOS) {
          gyro_set_angle(3.1415/2.0);
          cartesian_set_angle(3.1415/2.0);
          cartesian_set_speed(0, -1);
        }
        else if(_dir == YNEG) {
          gyro_set_angle(-3.1415/2.0);
          cartesian_set_angle(-3.1415/2.0);
          cartesian_set_speed(0, 1);
        }
      }
      else {
        cartesian_set_speed(0, 0);
        setState(END);
      }
    }
  }
};

#endif//CALIBRATE_ACTION_HPP
