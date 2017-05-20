#include <stdio.h>
#include <math.h>

#include "xtimer.h"

#include "task.h"
#include "gyro.hpp"
#include "arm.hpp"
#include "motors.hpp"
#include "robot.hpp"
#include "pull.hpp"
#include "gp2.hpp"

#include "calibrate_action.hpp"

void check(int ret) {
  if(ret < 0) {
    puts("ERROR!!");
  }
}

int main(void) {
  check(task_init());

  Robot::instance().angle().put(0);
  Robot::instance().speed().put(100);

  while(1) {
    int gp2_0 = GP2::gp2[0].get();
    int gp2_1 = GP2::gp2[1].get();
    int gp2_2 = GP2::gp2[2].get();
    int gp2_3 = GP2::gp2[3].get();
    int pull = Pull::instance().state();
    printf("%3i %3i %3i %3i %3i\n", gp2_0, gp2_1, gp2_2, gp2_3, pull);

    if(gp2_0 < 100 && gp2_1 < 100) {
      Robot::instance().angle().put(0);
      Robot::instance().speed().put(100);
    }
    else {
      puts("STOP!!");
      Robot::instance().angle().put(0);
      Robot::instance().speed().put(0);
    }

    xtimer_usleep(200000);
  }

  return 0;
}
