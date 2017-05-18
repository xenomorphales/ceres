#ifndef MOTORS_H
#define MOTORS_H

#ifdef __cplusplus
extern "C" {
#endif

int motors_init(void);
void motors_set_left(int pwm);
void motors_set_right(int pwm);

#ifdef __cplusplus
}
#endif

#endif//MOTORS_H
