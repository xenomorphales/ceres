#ifndef CARTESIAN_H
#define CARTESIAN_H

#ifdef __cplusplus
extern "C" {
#endif

int cartesian_init(void);

void cartesian_set_speed(float vx, float vy);
void cartesian_set_angle(float a);

#ifdef __cplusplus
}
#endif

#endif//CARTESIAN_H
