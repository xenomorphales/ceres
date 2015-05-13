#ifndef ENCODER_H
#define ENCODER_H

#include <stm32f4_discovery.h>
#include <stm32f4xx_hal.h>

void encoder1_init(void);
int encoder1_get_value(void);
short encoder1_get_value_short(void);

void encoder2_init(void);
int encoder2_get_value(void);
short encoder2_get_value_short(void);

extern TIM_HandleTypeDef hTIM3;

#define ENC_GPIO GPIOC
#define ENC_PIN_CHA GPIO_PIN_6
#define ENC_PIN_CHB GPIO_PIN_7



#endif//ENCODER_H
