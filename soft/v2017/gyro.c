#include "l3g4200d.h"
#include "periph/timer.h"

#define GYRO_MODE        L3G4200D_MODE_100_25
#define GYRO_SCALE       L3G4200D_SCALE_250DPS

#define GYRO_I2C  I2C_DEV(0)
#define GYRO_ADDR 105
#define GYRO_INT  GPIO_PIN(PA, 19)
#define GYRO_DR   GPIO_PIN(PA, 18)

static l3g4200d_t dev;
static int32_t angle;

void gyro_update(void) {
  l3g4200d_data_t data;
  l3g4200d_read(&dev, &data);
  angle += data.acc_z;
}

int gyro_init(void) {
  if (l3g4200d_init(&dev, GYRO_I2C, GYRO_ADDR, GYRO_INT, GYRO_DR, GYRO_MODE, GYRO_SCALE) != 0) {
    return -1;
  }

  return 0;
}

float gyro_get_angle(void) {
  return angle * 3.1415 / 14000;
}

int gyro_get_angle_deg(void) {
  return angle * 180 / 14000;
}

void gyro_set_angle(float val) {
  angle = (val / 3.1415) * 14000;
}
