#ifndef GYRO_HPP
#define GYRO_HPP

#include "singleton.hpp"
#include "service.hpp"

#include <stdint.h>

class Gyro : public Singleton<Gyro>, public Service {
private:
  class Angle;
  class Updater;

protected:
  int32_t _angle;

public:
  Gyro(void);

public:
  inline Angle& angle(void) { return *(Angle*)this; }
  inline Updater& updater(void) { return *(Updater*)this; }
};

class Gyro::Angle : private Gyro {
public:
  inline float get(void) {
    return _angle * 3.1415 / 14000;
  }

  inline void set(float val) {
    _angle = (val / 3.1415) * 14000;
  }
};

class Gyro::Updater : private Gyro {
public:
  void update(void);
};

#endif//GYRO_HPP
