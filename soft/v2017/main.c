#include <stdio.h>
#include <math.h>

#include "xtimer.h"

#include "task.h"
#include "robot.h"
#include "arm.h"

int main(void) {
  robot_init();
  task_init();

  int i = 0;

  while(1) {
    robot_set_angle(3.1415*i/2.0);
    robot_set_speed(80);
    xtimer_sleep(3);
    i++;
  }

  return 0;
}
