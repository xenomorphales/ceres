#include <stdio.h>
#include <math.h>

#include "xtimer.h"

#include "task.h"
#include "gyro.hpp"
#include "arm.h"
#include "motors.hpp"
#include "robot.hpp"
#include "pull.h"
#include "gp2.h"

#include "calibrate_action.hpp"

void check(int ret) {
  if(ret < 0) {
    puts("ERROR!!");
  }
}

int main(void) {
  check(gp2_init());
  check(pull_init());
  check(arm_init());
  //check(motors_init());
  //check(gyro_init());
  //check(robot_init());
  check(task_init());

  Robot::instance().angle().put(0);
  Robot::instance().speed().put(100);

  while(1) {
    int gp2_0 = gp2_value(0);
    int gp2_1 = gp2_value(1);
    int gp2_2 = gp2_value(2);
    int gp2_3 = gp2_value(3);
    int pull = pull_state();
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
