#include "periph/timer.h"

#include <stdint.h>

#define TASK_TIMER      TIMER_DEV(0)
#define TASK_CHAN       (0)
#define TASK_TIMER_FERQ (1000000UL)
#define TASK_FREQ       (100UL)
#define TASK_TIMEOUT    (TASK_TIMER_FERQ/TASK_FREQ)

#define GYRO_FREQ (100UL)
extern void gyro_update(void);

#define ROBOT_FREQ (10UL)
extern void robot_update(void);

static uint32_t _counter = 0;

static inline const uint32_t count(const uint32_t freq) {
  return TASK_FREQ/freq;
}

static inline int _timer_set(void) {
  return timer_set(TASK_TIMER, TASK_CHAN, TASK_TIMEOUT);
}

static void _update(void *arg, int chan) {
  _counter++;
  _timer_set();
  if(_counter % count(GYRO_FREQ) == 0) gyro_update();
  if(_counter % count(ROBOT_FREQ) == 0) robot_update();
}

int task_init(void) {
  if(timer_init(TASK_TIMER, TASK_TIMER_FERQ, _update, NULL) < 0) {
    return -1;
  }

  if(_timer_set() < 0) {
    return -2;
  }

  return 0;
}
