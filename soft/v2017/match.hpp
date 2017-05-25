#ifndef MATCH_HPP
#define MATCH_HPP

#include <singleton.hpp>

class Match : public Singleton<Match> {
private:
  class Updater;

public:
  enum Phase {
    INIT,
    BEFORE,
    MATCH,
    FUNNY
  };

  enum Subphase {
    BEGIN,
    SAFE,
    END
  };

  enum Side {
    YELLOW,
    BLUE
  };

protected:
  Phase _phase;
  Subphase _subphase;
  Side _side;

public:
  inline Match(void)
    : _phase(INIT), _subphase(SAFE), _side(BLUE) {
  }

public:
  inline Phase phase(void) {
    return _phase;
  }

  inline Subphase subphase(void) {
    return _subphase;
  }

  inline Side side(void) {
    return _side;
  }

  inline void setSide(Side s) {
    _side = s;
  }

public:
  inline Updater& updater(void) {
    return *(Updater*)this;
  }
};

class Match::Updater : private Match {
public:
  void update(void);
};

#endif//MATCH_HPP
