#ifndef FUNNY_HPP
#define FUNNY_HPP

#include "singleton.hpp"
#include "service.hpp"

class Funny : public Singleton<Funny>, public Service {
private:
  enum FunnyState {
    DISABLED,
    RETRACTED,
    RELEASED,
    MOVING,
  };

public:
  Funny(void);

public:
  void disable(void);
  void release(void);
  void retract(void);

public:
  FunnyState state(void);
};

#endif//FUNNY_HPP
