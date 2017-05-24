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

protected:
  Phase _phase;
  Subphase _subphase;

public:
  inline Match(void)
    : _phase(INIT), _subphase(SAFE) {
  }

public:
  inline Phase phase(void) {
    return _phase;
  }

  inline Subphase subphase(void) {
    return _subphase;
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
