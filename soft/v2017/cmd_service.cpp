#include <motors.hpp>
#include <gyro.hpp>
#include <robot.hpp>
#include <locator.hpp>
#include <cartesian.hpp>
#include <arm.hpp>
#include <funny.hpp>

#include <stdio.h>
#include <string.h>

struct ServiceName {
  const char* name;
  Service* service;
};

static const ServiceName sn[] = {
  {"motors", &Motors::instance()},
  {"gyro", &Gyro::instance()},
  {"robot", &Robot::instance()},
  {"locator", &Locator::instance()},
  {"cartesian", &Cartesian::instance()},
  {"arm", &Arm::instance()},
  {"funny", &Funny::instance()},
};

#define AR_SIZE(ar) (sizeof(ar)/sizeof(ar[0]))

static inline const char* str(Service::State s) {
  switch(s) {
    case Service::RUN: return "RUN"; break;
    case Service::STOP: return "STOP"; break;
    case Service::ERROR: return "ERROR"; break;
  };
  return "";
}

int cmd_service(int argc, char** argv) {
  if(argc == 1) {
    for(size_t i = 0 ; i < AR_SIZE(sn) ; i++) {
      printf("%10s : %s\n", sn[i].name, str(sn[i].service->state()));
    }
  }
  else {
    for(size_t i = 0 ; i < AR_SIZE(sn) ; i++) {
      if(strcmp(sn[i].name, argv[1]) == 0) {
        if(argc == 2) {
          printf("%s : %s\n", sn[i].name, str(sn[i].service->state()));
        }
        else {
          if(strcmp("start", argv[2]) == 0) {
            puts("Starting");
            sn[i].service->start();
          }
          else if(strcmp("stop", argv[2]) == 0) {
            puts("Stopping");
            sn[i].service->stop();
          }
        }
        return 0;
      }
    }

    puts("Service name not found");
    return -1;
  }

  return 0;
}
