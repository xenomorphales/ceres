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
  void put(float);
};

class Robot::Speed : private Robot {
public:
  void put(float);
  float get(void);
};

class Robot::Distance : private Robot {
public:
  float get(void);
};

class Robot::Updater : private Robot {
public:
  static const int FREQ = 20;

public:
  void update(void);
};

#endif//ROBOT_H
