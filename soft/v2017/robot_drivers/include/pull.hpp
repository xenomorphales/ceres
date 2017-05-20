#ifndef PULL_H
#define PULL_H

#include "singleton.hpp"

class Pull : public Singleton<Pull> {
  enum State {
    IN, OUT
  };

public:
  Pull(void);

public:
  State state(void);
};

#endif//PULL_H
