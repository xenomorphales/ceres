#ifndef ROBOT_H
#define ROBOT_H

#include "singleton.hpp"
#include "service.hpp"
#include "device.hpp"

class Robot : public Singleton<Robot>, public Service {
private:
  class Angle;
  class Speed;
  class Distance;
  class Updater;

private:
  struct Config {
    float speed_cmd_coeff = 100.0/(49.0/2.0);
    float speed_cmd_min = 27.5/2.0;
    float speed_cmd_max = 60.0/2.0;
    float angle_p = 100;
  };

protected:
  float _speed_cmd = 0;
  float _angle_cmd = 0;

  float _distance = 0;

  Config _config;

public:
  Robot(void);

public:
  inline Angle& angle(void) { return *(Angle*)this; }
  inline Speed& speed(void) { return *(Speed*)this; }
  inline Distance& distance(void) { return *(Distance*)this; }
  inline Updater& updater(void) { return *(Updater*)this; }
  inline Config& config(void) { return _config; }
};

class Robot::Angle : private Robot, public Output<float> {
public:
  void put(float val) {
    _angle_cmd = val;
  }
};

class Robot::Speed : private Robot, public Input<float>, public Output<float> {
public:
  inline void put(float val) {
    if(val > _config.speed_cmd_min) {
      if(val < _config.speed_cmd_max) {
        _speed_cmd = val;
      }
      else {
        _speed_cmd = _config.speed_cmd_max;
      }
    }
    else {
      _speed_cmd = 0;
    }
  }

  inline float get(void) {
    return _speed_cmd;
  }
};

class Robot::Distance : private Robot, public Input<float> {
public:
  inline float get(void) {
    return _distance;
  }
};

class Robot::Updater : private Robot {
public:
  static const int FREQ = 20;

public:
  void update(void);
};

#endif//ROBOT_H
