#include <stdio.h>
#include <math.h>
#include <string.h>

#include <shell.h>

#include "task.h"
#include "gyro.hpp"
#include "arm.hpp"
#include "motors.hpp"
#include "robot.hpp"
#include "pull.hpp"
#include "gp2.hpp"

#include "calibrate_action.hpp"

extern int cmd_service(int argc, char** argv);
extern int cmd_servo(int argc, char **argv);

static const shell_command_t shell_commands[] = {
  { "service", "Service management", cmd_service },
  { "servo", "Servo management", cmd_servo },
  { NULL, NULL, NULL }
};

int main(void) {
  task_init();

  puts("Starting the shell");

  char line_buf[SHELL_DEFAULT_BUFSIZE];
  shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

  return 0;
}
