#ifndef GYRO_H
#define GYRO_H

#ifdef __cplusplus
extern "C" {
#endif

int gyro_init(void);
float gyro_get_angle(void);
int gyro_get_angle_deg(void);
void gyro_set_angle(float val);

#ifdef __cplusplus
}
#endif

#endif//GYRO_H
