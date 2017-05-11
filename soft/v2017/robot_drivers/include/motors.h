#ifndef MOTORS_H
#define MOTORS_H

int motors_init(void);
void motors_set_left(int pwm);
void motors_set_right(int pwm);

#endif//MOTORS_H
