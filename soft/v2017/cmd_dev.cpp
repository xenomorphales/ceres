#include <motors.hpp>
#include <gyro.hpp>
#include <robot.hpp>
#include <locator.hpp>
#include <cartesian.hpp>

#include <device.hpp>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct Dev {
  const char* path;
  inline Dev(const char* path) : path(path) {}

  virtual void write(const char* in) = 0;
  virtual void print(void) = 0;
};

#define FLOAT_COEFF (1000.0)

void put(float* dev, int val) { (*dev) = ((float)val)/FLOAT_COEFF; }
void put(uint8_t* dev, int val) { (*dev) = val; }
void put(uint16_t* dev, int val) { (*dev) = val; }
void put(uint32_t* dev, int val) { (*dev) = val; }
void put(uint64_t* dev, int val) { (*dev) = val; }
void put(int8_t* dev, int val) { (*dev) = val; }
void put(int16_t* dev, int val) { (*dev) = val; }
void put(int32_t* dev, int val) { (*dev) = val; }
void put(int64_t* dev, int val) { (*dev) = val; }
void put(int* dev, int val) { (*dev) = val; }

int get(float* dev) { return ((*dev)*FLOAT_COEFF); }
int get(uint8_t* dev) { return (*dev); }
int get(uint16_t* dev) { return (*dev); }
int get(uint32_t* dev) { return (*dev); }
int get(uint64_t* dev) { return (*dev); }
int get(int8_t* dev) { return (*dev); }
int get(int16_t* dev) { return (*dev); }
int get(int32_t* dev) { return (*dev); }
int get(int64_t* dev) { return (*dev); }
int get(int* dev) { return (*dev); }

template<class IO> struct _GetType {};
template<typename T> struct _GetType<Output<T>> { using Type = T; };
template<typename T> struct _GetType<Input<T>> { using Type = T; };
template<class IO> using GetType = typename _GetType<IO>::Type;

template<class IO>
struct PutIfOutput {
  template<typename T>
  static void put(Output<T>* dev, int val) {
    (*(IO*)dev).put(val);
  }

  static void put(Output<float>* dev, int val) {
    (*(IO*)dev).put(((float)val)/FLOAT_COEFF);
  }

  static void put(...) {}
};

template<class IO>
struct GetIfInput {
  template<typename T>
  static int get(Input<T>* dev) {
    return (*(IO*)dev).get();
  }

  static int get(Input<float>* dev) {
    return (*(IO*)dev).get()*FLOAT_COEFF;
  }

  static int get(...) { return 0; }
};

template<typename T>
void put(T* dev, int val) {
  PutIfOutput<T>::put(dev, val);
}

template<typename T>
int get(T* dev) {
  return GetIfInput<T>::get(dev);
}

template<typename T>
struct IntDev : Dev {
  T& _dev;

  IntDev(const char* path, T& dev)
    : Dev(path), _dev(dev) {
  }

  void write(const char* in) {
    put(&_dev, atoi(in));
  }

  void print(void) {
    printf("%i\n", (int)get(&_dev));
  }
};

template<typename T>
IntDev<T> make_dev(const char* p, T& dev) {
  return IntDev<T>(p, dev);
}

auto lmot_dev = make_dev("motors.left", Motors::instance().left());
auto rmot_dev = make_dev("motors.right", Motors::instance().right());

auto gyro_dev = make_dev("gyro.angle", Gyro::instance().angle());
auto gyro2rad_dev = make_dev("gyro.config.gyro2rad", Gyro::instance().config().gyro2rad);

auto abot_dev = make_dev("robot.angle", Robot::instance().angle());
auto sbot_dev = make_dev("robot.speed", Robot::instance().speed());
auto capbot_dev = make_dev("robot.config.angle_p", Robot::instance().config().angle_p);
auto csccbot_dev = make_dev("robot.config.speed_cmd_coeff", Robot::instance().config().speed_cmd_coeff);
auto cscmibot_dev = make_dev("robot.config.speed_cmd_min", Robot::instance().config().speed_cmd_min);
auto cscmabot_dev = make_dev("robot.config.speed_cmd_max", Robot::instance().config().speed_cmd_max);

auto xloc_dev = make_dev("locator.x", Locator::instance().x());
auto yloc_dev = make_dev("locator.y", Locator::instance().y());

static Dev* dev_list[] {
  &lmot_dev,
  &rmot_dev,

  &gyro_dev,
  &gyro2rad_dev,

  &abot_dev,
  &sbot_dev,
  &capbot_dev,
  &csccbot_dev,
  &cscmibot_dev,
  &cscmabot_dev,

  &xloc_dev,
  &yloc_dev,
};

#define AR_SIZE(ar) (sizeof(ar)/sizeof(ar[0]))

int cmd_read(int argc, char** argv) {
  if(argc != 2) {
    puts("ERROR");
    return -1;
  }

  for(size_t i = 0 ; i < AR_SIZE(dev_list) ; i++) {
    if(strcmp(dev_list[i]->path, argv[1]) == 0) {
      dev_list[i]->print();
    }
  }

  return 0;
}

int cmd_write(int argc, char** argv) {
  if(argc != 3) {
    puts("ERROR");
    return -1;
  }

  for(size_t i = 0 ; i < AR_SIZE(dev_list) ; i++) {
    if(strcmp(dev_list[i]->path, argv[1]) == 0) {
      dev_list[i]->write(argv[2]);
    }
  }

  return 0;
}

int cmd_ls(int argc, char** argv) {
  for(size_t i = 0 ; i < AR_SIZE(dev_list) ; i++) {
      printf("%s\n", dev_list[i]->path);
  }

  return 0;
}
