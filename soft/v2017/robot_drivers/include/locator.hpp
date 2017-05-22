#ifndef LOCATOR_H
#define LOCATOR_H

#include "singleton.hpp"
#include "service.hpp"
#include "device.hpp"

class Locator : public Singleton<Locator>, public Service {
private:
  class X;
  class Y;
  class Updater;

protected:
  float _x;
  float _y;

public:
  inline Locator(void)
    : _x(0), _y(0) {
  }

public:
  inline X& x(void) { return *(X*)this; }
  inline Y& y(void) { return *(Y*)this; }
  inline Updater& updater(void) { return *(Updater*)this; }
};

class Locator::X : private Locator, public Input<float>, public Output<float> {
public:
  inline float get(void) {
    return _x;
  }

  inline void put(float val) {
    _x = val;
  }
};

class Locator::Y : private Locator, public Input<float>, public Output<float> {
public:
  inline float get(void) {
    return _y;
  }

  inline void put(float val) {
    _y = val;
  }
};

class Locator::Updater : private Locator {
public:
  static const int FREQ = 100;

public:
  void update(void);
};

#endif//LOCATOR_H
