#include "encoder.h"

TIM_HandleTypeDef hTIM3;
TIM_HandleTypeDef hTIM4;

void encoder1_init(void) {
  GPIO_InitTypeDef gpio_init;
  gpio_init.Pin = ENC_PIN_CHA;
  gpio_init.Pull = GPIO_PULLUP;
  gpio_init.Speed = GPIO_SPEED_HIGH;
  gpio_init.Mode = GPIO_MODE_AF_PP;
  gpio_init.Alternate = GPIO_AF2_TIM3;

  __GPIOC_CLK_ENABLE();
  HAL_GPIO_Init(ENC_GPIO, &gpio_init);

  gpio_init.Pin = ENC_PIN_CHB;
  HAL_GPIO_Init(ENC_GPIO, &gpio_init);

  __TIM3_CLK_ENABLE();

  hTIM3.Instance = TIM3;
//  hTIM3.Init.Prescaler = (SystemCoreClock/65535) - 1; // 1s
//  hTIM3.Init.CounterMode = TIM_COUNTERMODE_UP;
//  hTIM3.Init.ClockDivision = 0;
  hTIM3.Init.Period = 65535;
  //hTIM3.Channel = HAL_TIM_ACTIVE_CHANNEL_1 | HAL_TIM_ACTIVE_CHANNEL_2;
  //HAL_TIM_Base_Init(&hTIM3);

  TIM_Encoder_InitTypeDef enc_init;
  enc_init.EncoderMode = TIM_ENCODERMODE_TI12;

  enc_init.IC1Polarity = TIM_INPUTCHANNELPOLARITY_RISING;
  enc_init.IC2Polarity = TIM_INPUTCHANNELPOLARITY_RISING;

  enc_init.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  enc_init.IC2Selection = TIM_ICSELECTION_DIRECTTI;

  enc_init.IC1Prescaler = TIM_ICPSC_DIV1;
  enc_init.IC2Prescaler = TIM_ICPSC_DIV1;

  enc_init.IC1Filter = 0;
  enc_init.IC2Filter = 0;

  HAL_TIM_Encoder_Init(&hTIM3, &enc_init);

  __HAL_TIM_SetCounter(&hTIM3,0);
  HAL_TIM_Encoder_Start(&hTIM3, TIM_CHANNEL_1 | TIM_CHANNEL_2);
}

void encoder2_init(void) {
  GPIO_InitTypeDef gpio_init;
  gpio_init.Pin = GPIO_PIN_12;
  gpio_init.Pull = GPIO_PULLUP;
  gpio_init.Speed = GPIO_SPEED_HIGH;
  gpio_init.Mode = GPIO_MODE_AF_PP;
  gpio_init.Alternate = GPIO_AF2_TIM4;

  __GPIOD_CLK_ENABLE();
  HAL_GPIO_Init(GPIOD, &gpio_init);

  gpio_init.Pin = GPIO_PIN_13;
  HAL_GPIO_Init(GPIOD, &gpio_init);

  __TIM4_CLK_ENABLE();

  hTIM4.Instance = TIM4;
  //  hTIM4.Init.Prescaler = (SystemCoreClock/65535) - 1; // 1s
  //  hTIM4.Init.CounterMode = TIM_COUNTERMODE_UP;
  //  hTIM4.Init.ClockDivision = 0;
  hTIM4.Init.Period = 65535;
  //hTIM4.Channel = HAL_TIM_ACTIVE_CHANNEL_1 | HAL_TIM_ACTIVE_CHANNEL_2;
  //HAL_TIM_Base_Init(&hTIM4);

  TIM_Encoder_InitTypeDef enc_init;
  enc_init.EncoderMode = TIM_ENCODERMODE_TI12;

  enc_init.IC1Polarity = TIM_INPUTCHANNELPOLARITY_RISING;
  enc_init.IC2Polarity = TIM_INPUTCHANNELPOLARITY_RISING;

  enc_init.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  enc_init.IC2Selection = TIM_ICSELECTION_DIRECTTI;

  enc_init.IC1Prescaler = TIM_ICPSC_DIV1;
  enc_init.IC2Prescaler = TIM_ICPSC_DIV1;

  enc_init.IC1Filter = 0;
  enc_init.IC2Filter = 0;

  HAL_TIM_Encoder_Init(&hTIM4, &enc_init);

  __HAL_TIM_SetCounter(&hTIM4,0);
  HAL_TIM_Encoder_Start(&hTIM4, TIM_CHANNEL_1 | TIM_CHANNEL_2);
}

int encoder1_get_value(void) {
  return TIM3->CNT;
}

short encoder1_get_value_short(void) {
  return (short)encoder1_get_value();
}

int encoder2_get_value(void) {
  return TIM4->CNT;
}

short encoder2_get_value_short(void) {
  return (short)encoder2_get_value();
}


void TIM3_IRQHandler(void) {
  BSP_LED_Toggle(LED5);
  HAL_TIM_IRQHandler(&hTIM3);
}

void TIM4_IRQHandler(void) {
  BSP_LED_Toggle(LED5);
  HAL_TIM_IRQHandler(&hTIM4);
}

