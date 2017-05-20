#ifndef ROBOT_H
#define ROBOT_H

#include "singleton.hpp"
#include "service.hpp"

class Robot : public Singleton<Robot>, public Service {
private:
  class Angle;
  class Speed;
  class Distance;
  class Updater;

protected:
  float _speed_cmd = 0;
  float _angle_cmd = 0;

  float _distance = 0;

public:
  Robot(void);

public:
  inline Angle& angle(void) { return *(Angle*)this; }
  inline Speed& speed(void) { return *(Speed*)this; }
  inline Distance& distance(void) { return *(Distance*)this; }
  inline Updater& updater(void) { return *(Updater*)this; }
};

class Robot::Angle : private Robot {
public:
  void put(float val) {
    _angle_cmd = val;
  }
};

class Robot::Speed : private Robot {
public:
  inline void put(float val) {
    _speed_cmd = val;
  }

  inline float get(void) {
    return _speed_cmd;
  }
};

class Robot::Distance : private Robot {
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
