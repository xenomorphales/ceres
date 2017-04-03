#include <stdio.h>
#include <math.h>

#include "motors.h"
#include "gyro.h"

int main(void) {
  printf("motors_init : %i\n", motors_init());
  printf("gyro_init : %i\n", gyro_init());

  while (1) {
    const int a = gyro_get_angle_deg();
    printf("angle: %6i\n", a);

    int cmd = 0;
    int err = cmd-a;

    motors_set_left(10*err);
    motors_set_right(-10*err);
  }

  return 0;
}
