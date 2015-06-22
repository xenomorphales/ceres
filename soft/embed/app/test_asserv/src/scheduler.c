#include "scheduler.h"

#include <stm32f4_discovery.h>
#include <stm32f4xx_hal.h>

TIM_HandleTypeDef hTIM2;

void scheduler_init(void) {
	__TIM2_CLK_ENABLE();

	hTIM2.Instance = TIM2;
	hTIM2.Init.Prescaler = 400;
	hTIM2.Init.CounterMode = TIM_COUNTERMODE_UP;
	hTIM2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV2;
	hTIM2.Init.Period = 1000;
    TIM2->CCR1 = 1000;
	HAL_TIM_Base_Init(&hTIM2);

	HAL_NVIC_SetPriority(TIM2_IRQn, 3,3);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	HAL_TIM_Base_Start_IT(&hTIM2);

}

void scheduler_tick(void) {
	static uint8_t counter = 0;
	counter++;
	if(counter == 100) {
		counter = 0;
	}

	// 100 Hz

	// 10 Hz
	if(counter % 10 == 0) {
		asserv_ad_tick();
	}

	// 20 Hz
	if(counter % 5 == 0) {
		asserv_tick();
		odo_tick();
	}

	// 1 Hz
	if(counter == 0) {

	}
}
