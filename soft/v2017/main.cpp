#include <stdio.h>
#include <math.h>
#include <string.h>

#include <shell.h>

#include "task.h"

extern int cmd_read(int argc, char** argv);
extern int cmd_write(int argc, char** argv);
extern int cmd_ls(int argc, char** argv);

extern int cmd_service(int argc, char** argv);
extern int cmd_servo(int argc, char **argv);

extern int cmd_test_speed(int argc, char** argv);
extern int cmd_test_funny(int argc, char** argv);

static const shell_command_t shell_commands[] = {
  { "read", "", cmd_read },
  { "write", "", cmd_write },
  { "ls", "", cmd_ls },

  { "service", "Service management", cmd_service },
  { "servo", "Servo management", cmd_servo },

  { "test", "Move at some speed during some time", cmd_test_speed},
  { "funny", "Test funny action", cmd_test_funny},
  { NULL, NULL, NULL }
};

int main(void) {
  task_init();

  puts("Starting the shell");

  char line_buf[SHELL_DEFAULT_BUFSIZE];
  shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

  return 0;
}
