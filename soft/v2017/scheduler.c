#include "periph/timer.h"

#include <stdint.h>

#define SCHEDULER_TIMER      TIMER_DEV(0)
#define SCHEDULER_CHAN       (0)
#define SCHEDULER_TIMER_FERQ (1000000UL)
#define SCHEDULER_FREQ       (100UL)
#define SCHEDULER_TIMEOUT    (SCHEDULER_TIMER_FERQ/SCHEDULER_FREQ)

#define GYRO_FREQ (100UL)
extern void gyro_update(void);

#define ARM_FREQ (2UL)
extern void arm_update(void);

static uint32_t _counter = 0;

static inline int _timer_set(void) {
  return timer_set(SCHEDULER_TIMER, SCHEDULER_CHAN, SCHEDULER_TIMEOUT);
}

static void _update(void *arg, int chan) {
  _counter++;
  _timer_set();
  if(_counter % (SCHEDULER_FREQ/GYRO_FREQ)) gyro_update();
  if(_counter % (SCHEDULER_FREQ/ARM_FREQ))  arm_update();
}

int scheduler_init(void) {
  if(timer_init(SCHEDULER_TIMER, SCHEDULER_TIMER_FERQ, _update, NULL) < 0) {
    return -2;
  }

  if(_timer_set() < 0) {
    return -2;
  }

  return 0;
}
