#ifndef GYRO_H
#define GYRO_H

int gyro_init(void);
float gyro_get_angle(void);
int gyro_get_angle_deg(void);
void gyro_set_angle(float val);

#endif//GYRO_H
