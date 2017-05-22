#include <stdlib.h>
#include <xtimer.h>
#include <robot.hpp>
#include <funny.hpp>

int cmd_test_speed(int argc, char** argv) {
  if(argc != 3) {
    printf("usage : %s speed time_s\n", argv[0]);
    return -1;
  }

  const float speed = ((float)atoi(argv[1])) / 1000.0;
  const int time = atoi(argv[2]) * 1000000;

  const float prev_dist = Robot::instance().distance().get();

  const uint32_t begining = xtimer_now_usec();
  Robot::instance().speed().put(speed);

  const uint32_t ending = begining + time;
  while(xtimer_now_usec() < ending);

  Robot::instance().speed().put(0);

  const float new_dist = Robot::instance().distance().get();
  const int dist = (new_dist - prev_dist) * 1000.0;

  printf("dist : %i\n", dist);

  return 0;
}

int cmd_test_funny(int argc, char** argv) {
  (void) argc;
  (void) argv;

  Funny::instance().release();
  xtimer_sleep(1);
  Funny::instance().disable();
  return 0;
}
