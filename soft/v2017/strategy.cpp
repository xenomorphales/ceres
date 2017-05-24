#include "strategy.hpp"

#include <motors.hpp>
#include <gyro.hpp>
#include <robot.hpp>
#include <funny.hpp>
#include <gp2.hpp>

#include "match.hpp"

#include <thread.h>
#include <xtimer.h>

enum StrategyState {
  START,
  START_PULL_OUT,
  START_PULL_IN,
  WAIT_PMI,
  GO_OUT,
  WAIT_END,
  FUNNY,
};

static char _strategy_thread_stack[THREAD_STACKSIZE_MAIN];

static void _update(void) {
  Match::instance().updater().update();

  const Match::Phase phase = Match::instance().phase();
  const Match::Subphase subphase = Match::instance().subphase();

  if(phase == Match::MATCH) {
    Motors::instance().start();
    Gyro::instance().start();
    Robot::instance().start();
    if(subphase == Match::BEGIN) {
      Gyro::instance().angle().put(0);
      Robot::instance().angle().put(0);
      Robot::instance().speed().put(0);
      Robot::instance().distance().put(0);
    }
    else if(subphase == Match::SAFE) {
      if(Robot::instance().distance().get() > -50.0) {
        if(GP2::gp2[0].get() > 110) {
          Robot::instance().speed().put(0);
        }
        else if(GP2::gp2[1].get() > 110) {
          Robot::instance().speed().put(0);
        }
        else {
          Robot::instance().speed().put(-25.0);
        }
      }
      else {
        Robot::instance().speed().put(0);
      }
    }
  }
  else {
    Motors::instance().start();
    Gyro::instance().stop();
    Robot::instance().stop();

    Motors::instance().left().put(0);
    Motors::instance().right().put(0);
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
