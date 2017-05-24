#include "match.hpp"

#include <pull.hpp>
#include <xtimer.h>

#define SEC(sec) (sec*1000000)

static uint64_t _begin = 0;

void Match::Updater::update(void) {
  if(Pull::instance().state() == Pull::IN) {
    _phase = BEFORE;
    _subphase = SAFE;
    return;
  }

  if(_phase == BEFORE) {
    if(Pull::instance().state() == Pull::OUT) {
      _begin = xtimer_now_usec64();
      _phase = MATCH;
      _subphase = BEGIN;
    }
    return;
  }

  if(_phase == MATCH) {
    if(xtimer_now_usec64() - _begin > SEC(90)) {
      _phase = FUNNY;
      _subphase = BEGIN;
      return;
    }
    if(xtimer_now_usec64() - _begin > SEC(88)) {
      _subphase = END;
      return;
    }
    if(xtimer_now_usec64() - _begin > SEC(10)) {
      _subphase = SAFE;
      return;
    }
    return;
  }

  if(_phase == FUNNY) {
    if(xtimer_now_usec64() - _begin > SEC(95)) {
      _phase = INIT;
      _subphase = SAFE;
      return;
    }
    if(xtimer_now_usec64() - _begin > SEC(94)) {
      _subphase = END;
      return;
    }
    if(xtimer_now_usec64() - _begin > SEC(91)) {
      _subphase = SAFE;
      return;
    }
    return;
  }
}
