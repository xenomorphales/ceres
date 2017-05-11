#include <stdio.h>
#include <math.h>

#include "xtimer.h"

#include "task.h"
#include "gyro.h"
#include "arm.h"
#include "motors.h"
#include "pull.h"
#include "gp2.h"

int main(void) {
  gp2_init();
  pull_init();
  motors_init();

  while(1) {
    int gp2_0 = gp2_value(0);
    int gp2_1 = gp2_value(1);
    int gp2_2 = gp2_value(2);
    int gp2_3 = gp2_value(3);
    int pull = pull_state();
    printf("%3i %3i %3i %3i %3i\n", gp2_0, gp2_1, gp2_2, gp2_3, pull);

    motors_set_left(gp2_0);
    motors_set_right(gp2_1);

    xtimer_sleep(1);
  }

  return 0;
}
