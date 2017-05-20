#ifndef CALIBRATE_ACTION_HPP
#define CALIBRATE_ACTION_HPP

#include "action.hpp"

#include "cartesian.hpp"
#include "gyro.hpp"
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
          Cartesian::instance().setSpeed(1, 0);
        }
        else if(_dir == XNEG) {
          Cartesian::instance().setSpeed(-1, 0);
        }
        else if(_dir == YPOS) {
          Cartesian::instance().setSpeed(0, 1);
        }
        else if(_dir == YNEG) {
          Cartesian::instance().setSpeed(0, -1);
        }
      }
      else if(now - _begining < 4000000) {
        if(_dir == XPOS) {
          Gyro::instance().angle().set(0);
          Cartesian::instance().angle().put(0);
          Cartesian::instance().setSpeed(-1, 0);
        }
        else if(_dir == XNEG) {
          Gyro::instance().angle().set(3.1415);
          Cartesian::instance().angle().put(3.1415);
          Cartesian::instance().setSpeed(1, 0);
        }
        else if(_dir == YPOS) {
          Gyro::instance().angle().set(3.1415/2.0);
          Cartesian::instance().angle().put(3.1415/2.0);
          Cartesian::instance().setSpeed(0, -1);
        }
        else if(_dir == YNEG) {
          Gyro::instance().angle().set(-3.1415/2.0);
          Cartesian::instance().angle().put(-3.1415/2.0);
          Cartesian::instance().setSpeed(0, 1);
        }
      }
      else {
        Cartesian::instance().setSpeed(0, 0);
        setState(END);
      }
    }
  }
};

#endif//CALIBRATE_ACTION_HPP
