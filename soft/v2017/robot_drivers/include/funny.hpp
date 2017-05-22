#ifndef FUNNY_HPP
#define FUNNY_HPP

#include "singleton.hpp"
#include "service.hpp"

class Funny : public Singleton<Funny>, public Service {
public:
  Funny(void);

public:
  void disable(void);
  void release(void);
};

#endif//FUNNY_HPP
