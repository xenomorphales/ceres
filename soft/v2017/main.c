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

    int cmd_a = -90;
    int err_a = cmd_a-a;

    int cmd_d = 0;
    int err_d = cmd_d;

    motors_set_left(err_d + err_a);
    motors_set_right(err_d - err_a);
  }

  return 0;
}
