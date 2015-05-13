#ifndef MOTOR_H
#define MOTOR_H

#include <stm32f4xx_hal.h>

void motor_init(void);

void motor1_set_value(int cmd);
void motor2_set_value(int cmd);

extern TIM_HandleTypeDef hTIM5;


#endif//MOTOR_H
