#include <stdio.h>
#include <math.h>

#include "xtimer.h"

#include "task.h"
#include "gyro.h"
#include "arm.h"
#include "motors.h"
#include "robot.h"
#include "pull.h"
#include "gp2.h"

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
  check(robot_init());
  check(task_init());

  robot_set_angle(0);
  robot_set_speed(100);

  while(1) {
    int gp2_0 = gp2_value(0);
    int gp2_1 = gp2_value(1);
    int gp2_2 = gp2_value(2);
    int gp2_3 = gp2_value(3);
    int pull = pull_state();
    printf("%3i %3i %3i %3i %3i\n", gp2_0, gp2_1, gp2_2, gp2_3, pull);

    if(gp2_0 < 100 && gp2_1 < 100) {
      robot_set_angle(0);
      robot_set_speed(100);
    }
    else {
      puts("STOP!!");
      robot_set_angle(0);
      robot_set_speed(0);
    }

    xtimer_usleep(200000);
  }

  return 0;
}
