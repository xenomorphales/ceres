#include <stdio.h>
#include <math.h>

#include "thread.h"

#include "task.h"
#include "motors.h"
#include "gyro.h"
#include "arm.h"

int main(void) {
  arm_init();

  while(1) {
    while(arm_left_state() != ARM_RETRACTED) thread_yield();
    arm_left_deploy();
    while(arm_left_state() != ARM_DEPLOYED) thread_yield();
    arm_left_retract();
  }

  return 0;
}
