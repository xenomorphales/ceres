#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stm32f4xx_hal.h>

extern TIM_HandleTypeDef hTIM2;

void scheduler_init(void);

// User function
void asserv_tick(void);
void odo_tick(void);

void asserv_ad_tick(void);

#endif//SCHEDULER_H
