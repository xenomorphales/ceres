#include <stdlib.h>
#include <xtimer.h>
#include <motors.hpp>
#include <gyro.hpp>
#include <robot.hpp>
#include <locator.hpp>
#include <funny.hpp>
#include <arm.hpp>

#include "match.hpp"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int cmd_test_all(int, char**) {
  Motors::instance().start();
  Gyro::instance().start();
  Robot::instance().start();
  Locator::instance().start();

  return 0;
}

int cmd_test_speed(int argc, char** argv) {
  if(argc != 3) {
    printf("usage : %s speed time_s\n", argv[0]);
    return -1;
  }

  const float speed = ((float)atoi(argv[1])) / 1000.0;
  const int time = atoi(argv[2]) * 1000000;

  const float prev_dist = Robot::instance().distance().get();

  const uint32_t begining = xtimer_now_usec();
  Robot::instance().speed().put(speed);

  const uint32_t ending = begining + time;
  while(xtimer_now_usec() < ending);

  Robot::instance().speed().put(0);

  const float new_dist = Robot::instance().distance().get();
  const int dist = (new_dist - prev_dist) * 1000.0;

  printf("dist : %i\n", dist);

  return 0;
}

int cmd_test_funny(int argc, char** argv) {
  (void) argc;
  (void) argv;

  Funny::instance().release();
  xtimer_sleep(1);
  Funny::instance().disable();
  return 0;
}

int cmd_test_grip(int argc, char** argv) {
  if(argc == 2) {
    if(strcmp(argv[1], "left") == 0) {
      printf("%i\n", (int)Arm::instance().left().grip().hold());
    }
    if(strcmp(argv[1], "right") == 0) {
      printf("%i\n", (int)Arm::instance().right().grip().hold());
    }
    return 0;
  }

  if(argc != 3) {
    puts("ERROR");
    return -1;
  }

  if(strcmp(argv[1], "left") == 0) {
    if(strcmp(argv[2], "open") == 0) {
      Arm::instance().left().grip().open();
      return 0;
    }
    else if(strcmp(argv[2], "close") == 0) {
      Arm::instance().left().grip().close();
      return 0;
    }
  }
  else if(strcmp(argv[1], "right") == 0) {
    if(strcmp(argv[2], "open") == 0) {
      Arm::instance().right().grip().open();
      return 0;
    }
    else if(strcmp(argv[2], "close") == 0) {
      Arm::instance().right().grip().close();
      return 0;
    }
  }

  puts("ERROR");
  return 0;
}

int cmd_test_arm(int argc, char** argv) {
  if(argc == 4) {
    const int ia1 = atoi(argv[2]);
    const int ia2 = atoi(argv[3]);

    const float a1 = ia1 / 1000.0;
    const float a2 = ia2 / 1000.0;

    if(strcmp(argv[1], "left") == 0) {
      Arm::instance().left().setAngles(a1, a2);
    }
    if(strcmp(argv[1], "right") == 0) {
      Arm::instance().right().setAngles(a1, a2);
    }
    return 0;
  }

  if(argc != 3) {
    puts("ERROR");
    return -1;
  }

  if(strcmp(argv[1], "left") == 0) {
    if(strcmp(argv[2], "deploy") == 0) {
      Arm::instance().left().deploy();
      return 0;
    }
    else if(strcmp(argv[2], "retract") == 0) {
      Arm::instance().left().retract();
      return 0;
    }
  }
  else if(strcmp(argv[1], "right") == 0) {
    if(strcmp(argv[2], "deploy") == 0) {
      Arm::instance().right().deploy();
      return 0;
    }
    else if(strcmp(argv[2], "retract") == 0) {
      Arm::instance().right().retract();
      return 0;
    }
  }

  puts("ERROR");
  return 0;
}

int cmd_test_side(int argc, char** argv) {
  if(argc == 1) {
    if(Match::instance().side() == Match::YELLOW) {
      puts("YELLOW");
    }
    else if(Match::instance().side() == Match::BLUE) {
      puts("BLUE");
    }
  }

  if(argc != 2) {
    puts("ERROR");
    return -1;
  }

  if(strcmp(argv[1], "yellow") == 0) {
    Match::instance().setSide(Match::YELLOW);
  }
  else if(strcmp(argv[1], "blue") == 0) {
    Match::instance().setSide(Match::BLUE);
  }
  else {
    puts("ERROR");
    return -1;
  }

  return 0;
}
