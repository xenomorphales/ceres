#ifndef ROBOT_H
#define ROBOT_H

#ifdef __cplusplus
extern "C" {
#endif

int robot_init(void);

void robot_set_speed(float speed);
void robot_set_angle(float angle);

float robot_get_speed(void);
float robot_get_angle(void);

float robot_get_distance(void);

#ifdef __cplusplus
}
#endif

#endif//ROBOT_H
