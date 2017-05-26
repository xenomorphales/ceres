#include "strategy.hpp"

#include <motors.hpp>
#include <gyro.hpp>
#include <robot.hpp>
#include <funny.hpp>
#include <gp2.hpp>
#include <arm.hpp>

#include <feetech.h>
#include <servo.hpp>

#include "match.hpp"

#include <thread.h>
#include <xtimer.h>

using StrategyState = int;

static StrategyState _state;

static char _strategy_thread_stack[THREAD_STACKSIZE_MAIN];

bool goto_d(float dist) {
  if(dist < 0) {
    Robot::instance().speed().put(-25.0);
  }
  else {
    Robot::instance().speed().put(25.0);
  }
  if(fabs(Robot::instance().distance().get()) > fabs(dist)) {
    Robot::instance().speed().put(0);
    Robot::instance().distance().put(0);
    _state++;
    return true;
  }
  return false;
}

bool goto_a(float angle) {
  Robot::instance().speed().put(0.0);
  Robot::instance().angle().put(angle);
  if(fabs(Gyro::instance().angle().get() - angle) < 0.2) {
    _state++;
    return true;
  }
  return false;
}

int _side_counter = 0;

void ping_side(void) {
  if(feetech_ping(&ServoBus::instance().stream(), 24) == FEETECH_OK) {
    if(_side_counter < 3) _side_counter++;
  }
  else {
    if(_side_counter > -3) _side_counter--;
  }

  if(_side_counter >= 0) {
    Match::instance().setSide(Match::YELLOW);
  }
  else {
    Match::instance().setSide(Match::BLUE);
  }
}

static void _update(void) {
  Match::instance().updater().update();

  const Match::Phase phase = Match::instance().phase();
  const Match::Subphase subphase = Match::instance().subphase();
  const Match::Side side = Match::instance().side();

  if(phase == Match::MATCH) {
    Motors::instance().start();
    Gyro::instance().start();
    Robot::instance().start();
    Arm::instance().start();

    if(subphase == Match::BEGIN) {
      Gyro::instance().angle().put(0);
      Robot::instance().angle().put(0);
      Robot::instance().speed().put(0);
      Robot::instance().distance().put(0);
    }
    else if(subphase == Match::SAFE) {
      if(side == Match::YELLOW) {
        if(_state == 0) {
          if(goto_d(-20)) {
            Arm::instance().left().grip().close();
            Arm::instance().right().grip().close();
            Arm::instance().left().retract();
            Arm::instance().right().retract();
          }
        }
        else if(_state == 1) {
          goto_a(-M_PI/2);
        }
        else if(_state == 2) {
          goto_d(-20);
        }
        else if(_state == 3) {
          if(goto_a(0)) {
            Arm::instance().left().setAngles(0, 0);
            Arm::instance().left().deploy();
          }
        }
        else if(_state == 4) {
          if(Arm::instance().left().state() == Arm::ARM_DEPLOYED) {
            _state++;
          }
        }
        else if(_state == 5) {
          goto_a(-100*M_PI);
        }
        else {
          Robot::instance().speed().put(0.0);
        }
      }
      else if(side == Match::BLUE) {
        if(_state == 0) {
          if(goto_d(-20)) {
            Arm::instance().left().grip().close();
            Arm::instance().right().grip().close();
            Arm::instance().left().retract();
            Arm::instance().right().retract();
          }
        }
        else if(_state == 1) {
          goto_a(M_PI/2);
        }
        else if(_state == 2) {
          goto_d(-20);
        }
        else if(_state == 3) {
          if(goto_a(0)) {
            Arm::instance().left().setAngles(0, 0);
            Arm::instance().left().deploy();
          }
        }
        else if(_state == 4) {
          if(Arm::instance().left().state() == Arm::ARM_DEPLOYED) {
            _state++;
          }
        }
        else if(_state == 5) {
          goto_a(100*M_PI);
        }
        else {
          Robot::instance().speed().put(0.0);
        }
      }

      if(GP2::gp2[0].get() > 110) {
        Robot::instance().speed().put(0.0);
      }
      if(GP2::gp2[1].get() > 110) {
        Robot::instance().speed().put(0.0);
      }
    }
  }
  else {
    _state = 0;

    Motors::instance().start();
    Gyro::instance().stop();
    Robot::instance().stop();

    Motors::instance().left().put(0);
    Motors::instance().right().put(0);

    ping_side();
  }

  if(phase == Match::FUNNY) {
    Funny::instance().start();
    if(subphase == Match::SAFE) {
      Funny::instance().release();
    }
    if(subphase == Match::END) {
      Funny::instance().disable();
    }
  }
  else {
    Funny::instance().stop();
  }
}

static void* _strategy_update_thread(void* arg) {
  (void) arg;
  xtimer_ticks32_t last_wakeup = xtimer_now();

  while(1) {
    xtimer_periodic_wakeup(&last_wakeup, 1000000UL/5UL);
    if(Strategy::instance().state() == Service::RUN) {
      _update();
    }
  }

  return NULL;
}

Strategy::Strategy(void) {
  thread_create(_strategy_thread_stack, sizeof(_strategy_thread_stack),
                THREAD_PRIORITY_MAIN - 1, THREAD_CREATE_STACKTEST,
                _strategy_update_thread, NULL, "arm");
}
