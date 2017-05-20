#ifndef CARTESIAN_H
#define CARTESIAN_H

#include "singleton.hpp"
#include "service.hpp"
#include "device.hpp"

class Cartesian : public Singleton<Cartesian>, public Service {
private:
  class Angle;
  class VX;
  class VY;
  class Updater;

protected:
  float _cmd_vx;
  float _cmd_vy;
  float _cmd_a;

public:
  inline Cartesian(void)
    : _cmd_vx(0), _cmd_vy(0), _cmd_a(0) {
  }

public:
  inline Angle& angle(void) { return *(Angle*)this; }
  inline VX& vx(void) { return *(VX*)this; }
  inline VY& vy(void) { return *(VY*)this; }
  inline Updater& updater(void) { return *(Updater*)this; }

public:
  inline void setSpeed(float vx, float vy) {
    _cmd_vx = vx;
    _cmd_vy = vy;
  }
};

class Cartesian::Angle : private Cartesian, public Output<float> {
public:
  inline void put(float val) {
    _cmd_a = val;
  }
};

class Cartesian::VX : private Cartesian, public Output<float> {
public:
  inline void put(float val) {
    _cmd_vx = val;
  }
};

class Cartesian::VY : private Cartesian, public Output<float> {
public:
  inline void put(float val) {
    _cmd_vy = val;
  }
};

class Cartesian::Updater : private Cartesian {
public:
  static const int FREQ = 5;

public:
  void update(void);
};

#endif//CARTESIAN_H
