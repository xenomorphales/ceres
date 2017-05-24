#include <stdio.h>
#include <math.h>
#include <string.h>

#include <shell.h>

#include "task.h"

#include "strategy.hpp"

extern int cmd_read(int argc, char** argv);
extern int cmd_write(int argc, char** argv);
extern int cmd_ls(int argc, char** argv);

extern int cmd_service(int argc, char** argv);

extern int cmd_feetech(int argc, char **argv);
extern int cmd_dxl(int argc, char **argv);

extern int cmd_test_all(int, char**);
extern int cmd_test_speed(int argc, char** argv);
extern int cmd_test_funny(int argc, char** argv);

static const shell_command_t shell_commands[] = {
  { "read", "", cmd_read },
  { "write", "", cmd_write },
  { "ls", "", cmd_ls },

  { "service", "Service management", cmd_service },

  { "feetech", "Feetech management", cmd_feetech },
  { "dxl", "Dynamixel management", cmd_dxl },

  { "init_all", "Init all services", cmd_test_all},
  { "test", "Test speed*time", cmd_test_speed},
  { "funny", "Test funny action", cmd_test_funny},
  { NULL, NULL, NULL }
};

int main(void) {
  task_init();

  puts("Starting the shell");

  Strategy::instance().start();
  char line_buf[SHELL_DEFAULT_BUFSIZE];
  shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

  return 0;
}
