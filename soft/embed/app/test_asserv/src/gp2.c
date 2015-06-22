#include "gp2.h"
#include <stm32f4xx_hal.h>


ADC_HandleTypeDef hADC;

void gp2_init(void) {
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_0;
	gpio_init.Pull = GPIO_PULLDOWN;
	gpio_init.Mode = GPIO_MODE_ANALOG;

	__GPIOC_CLK_ENABLE();
	HAL_GPIO_Init(GPIOC, &gpio_init);

	gpio_init.Pin = GPIO_PIN_1;
	HAL_GPIO_Init(GPIOC, &gpio_init);

	gpio_init.Pin = GPIO_PIN_2;
	HAL_GPIO_Init(GPIOC, &gpio_init);

	gpio_init.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOC, &gpio_init);

	hADC.Instance = ADC1;

	hADC.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV4;
	hADC.Init.Resolution = ADC_RESOLUTION_12B;
	hADC.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hADC.Init.ScanConvMode = DISABLE;
	hADC.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	hADC.Init.ContinuousConvMode = DISABLE;
	hADC.Init.DMAContinuousRequests = DISABLE;
	hADC.Init.NbrOfConversion = 1;
	hADC.Init.DiscontinuousConvMode = DISABLE;
	hADC.Init.NbrOfDiscConversion = 1;
	hADC.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hADC.Init.ExternalTrigConvEdge = ADC_SOFTWARE_START;

	__ADC1_CLK_ENABLE();
	HAL_ADC_Init(&hADC);
}

uint32_t gp2_get_lf(void) {
	ADC_ChannelConfTypeDef conf;

	conf.Channel = ADC_CHANNEL_10;
	conf.Rank = 1;
	conf.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	conf.Offset = 0;

	HAL_ADC_ConfigChannel(&hADC, &conf);

	HAL_ADC_Start(&hADC);

	HAL_StatusTypeDef status = HAL_ADC_PollForConversion(&hADC, 1000);

	return HAL_ADC_GetValue(&hADC);
}

uint32_t gp2_get_rf(void) {
	ADC_ChannelConfTypeDef conf;

	conf.Channel = ADC_CHANNEL_11;
	conf.Rank = 1;
	conf.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	conf.Offset = 0;

	HAL_ADC_ConfigChannel(&hADC, &conf);

	HAL_ADC_Start(&hADC);

	HAL_StatusTypeDef status = HAL_ADC_PollForConversion(&hADC, 1000);

	return HAL_ADC_GetValue(&hADC);
}

uint32_t gp2_get_lb(void) {
	ADC_ChannelConfTypeDef conf;

	conf.Channel = ADC_CHANNEL_12;
	conf.Rank = 1;
	conf.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	conf.Offset = 0;

	HAL_ADC_ConfigChannel(&hADC, &conf);

	HAL_ADC_Start(&hADC);

	HAL_StatusTypeDef status = HAL_ADC_PollForConversion(&hADC, 1000);

	return HAL_ADC_GetValue(&hADC);
}

uint32_t gp2_get_rb(void) {
	ADC_ChannelConfTypeDef conf;

	conf.Channel = ADC_CHANNEL_13;
	conf.Rank = 1;
	conf.SamplingTime = ADC_SAMPLETIME_56CYCLES;
	conf.Offset = 0;

	HAL_ADC_ConfigChannel(&hADC, &conf);

	HAL_ADC_Start(&hADC);

	HAL_StatusTypeDef status = HAL_ADC_PollForConversion(&hADC, 1000);

	return HAL_ADC_GetValue(&hADC);
}
