#include "l3g4200d.h"
#include "periph/timer.h"

#define GYRO_MODE        L3G4200D_MODE_100_25
#define GYRO_SCALE       L3G4200D_SCALE_250DPS

#define GYRO_I2C  I2C_DEV(0)
#define GYRO_ADDR 105
#define GYRO_INT  GPIO_PIN(PA, 19)
#define GYRO_DR   GPIO_PIN(PA, 18)

#define UPDATE_TIMER  TIMER_DEV(0)
#define UPDATE_TIMER_FERQ (1000000UL)
#define UPDATE_CHAN   (0)
#define UPDATE_PERIOD (1000000UL/100UL)

static l3g4200d_t dev;
static int32_t angle;

static inline int _timer_set(void) {
  return timer_set(UPDATE_TIMER, UPDATE_CHAN, UPDATE_PERIOD);
}

static void _update(void *arg, int chan) {
  l3g4200d_data_t data;
  l3g4200d_read(&dev, &data);
  angle += data.acc_z;
  _timer_set();
}

int gyro_init(void) {
  if (l3g4200d_init(&dev, GYRO_I2C, GYRO_ADDR, GYRO_INT, GYRO_DR, GYRO_MODE, GYRO_SCALE) != 0) {
    return -1;
  }

  if(timer_init(UPDATE_TIMER, UPDATE_TIMER_FERQ, _update, NULL) < 0) {
    return -2;
  }

  if(_timer_set() < 0) {
    return -2;
  }

  return 0;
}

float gyro_get_angle(void) {
  return angle * 3.1415 / 14000;
}

int gyro_get_angle_deg(void) {
  return angle * 180 / 14000;
}
