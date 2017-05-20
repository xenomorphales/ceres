#ifndef ARM_H
#define ARM_H

#include "singleton.hpp"
#include "service.hpp"

class Arm : public Singleton<Arm>, public Service {
private:
  class Left;
  class Right;

public:
  enum ArmState {
    ARM_DISABLED,
    ARM_RETRACTED,
    ARM_DEPLOYED,
    ARM_MOVING,
    ARM_ERROR
  };

public:
  Arm(void);

public:
  inline Left& left(void) { return *(Left*)this; }
  inline Right& right(void) { return *(Right*)this; }
};

class Arm::Left : private Arm {
public:
  void deploy(void);
  void retract(void);

public:
  void setAngles(float a1, float a2);

public:
  ArmState state(void);
};

class Arm::Right : private Arm {
public:
  void deploy(void);
  void retract(void);

public:
  void setAngles(float a1, float a2);

public:
  ArmState state(void);
};

#endif//ARM_H
