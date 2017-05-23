#include "strategy.hpp"

#include <pull.hpp>
#include <motors.hpp>
#include <gyro.hpp>
#include <robot.hpp>
#include <funny.hpp>
#include <gp2.hpp>

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

static StrategyState _state = START;
static uint64_t _begin = 0;

static void _update(void) {
  if(xtimer_now_usec64() - _begin > 91000000) {
    Motors::instance().start();
    Gyro::instance().stop();
    Robot::instance().stop();
    Funny::instance().start();

    Motors::instance().left().put(0);
    Motors::instance().right().put(0);

    Funny::instance().release();
    _state = FUNNY;
  }

  if(xtimer_now_usec64() - _begin > 95000000) {
    _state = START;
  }

  if(_state == START) {
    if(Pull::instance().state() == Pull::OUT) {
      _state = START_PULL_OUT;
    }
    else {
      _state = START_PULL_IN;
    }
  }
  else if(_state == START_PULL_OUT) {
    if(Pull::instance().state() == Pull::IN) {
      _state = START_PULL_IN;
    }
  }
  else if(_state == START_PULL_IN) {
    if(Pull::instance().state() == Pull::OUT) {
      Motors::instance().start();
      Gyro::instance().start();
      Robot::instance().start();
      Funny::instance().start();

      Gyro::instance().angle().put(0);
      Robot::instance().distance().put(0);
      Robot::instance().angle().put(0);
      Robot::instance().speed().put(0);
      Funny::instance().disable();

      _begin = xtimer_now_usec64();
      _state = WAIT_PMI;
    }
  }
  else if(_state == WAIT_PMI) {
    if(xtimer_now_usec64() - _begin > 5000000) {
      _state = GO_OUT;
    }
  }
  else if(_state == GO_OUT) {
    if(GP2::gp2[0].get() > 150) {
      Robot::instance().speed().put(0);
    }
    else {
      Robot::instance().speed().put(-25.0);
    }

    if(Robot::instance().distance().get() < -50.0) {
      _state = WAIT_END;
    }
  }
  else if(_state == WAIT_END) {
    Motors::instance().start();
    Gyro::instance().stop();
    Robot::instance().stop();
    Funny::instance().stop();

    Motors::instance().left().put(0);
    Motors::instance().right().put(0);
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
