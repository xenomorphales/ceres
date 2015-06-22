#include "motor.h"

#include <stm32f4_discovery.h>

TIM_HandleTypeDef hTIM5;

static void _motor_way_init(void) {
  GPIO_InitTypeDef gpio_init;
  gpio_init.Pull = GPIO_NOPULL;
  gpio_init.Speed = GPIO_SPEED_HIGH;
  gpio_init.Mode = GPIO_MODE_OUTPUT_PP;

  gpio_init.Pin = GPIO_PIN_2;
  HAL_GPIO_Init(GPIOA, &gpio_init);
  gpio_init.Pin = GPIO_PIN_3;
  HAL_GPIO_Init(GPIOA, &gpio_init);
  gpio_init.Pin = GPIO_PIN_4;
  HAL_GPIO_Init(GPIOA, &gpio_init);
  gpio_init.Pin = GPIO_PIN_5;
  HAL_GPIO_Init(GPIOA, &gpio_init);

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

void motor_init(void) {
  GPIO_InitTypeDef gpio_init;
  gpio_init.Pin = GPIO_PIN_0;
  gpio_init.Pull = GPIO_PULLDOWN;
  gpio_init.Speed = GPIO_SPEED_HIGH;
  gpio_init.Mode = GPIO_MODE_AF_PP;
  gpio_init.Alternate = GPIO_AF2_TIM5;

  __GPIOA_CLK_ENABLE();
  HAL_GPIO_Init(GPIOA, &gpio_init);

  gpio_init.Pin = GPIO_PIN_1;
  HAL_GPIO_Init(GPIOA, &gpio_init);

  __TIM5_CLK_ENABLE();

  hTIM5.Instance = TIM5;
  hTIM5.Init.Prescaler = 1;
  hTIM5.Init.CounterMode = TIM_COUNTERMODE_UP;
  hTIM5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV4;
  hTIM5.Init.Period = 0xFFFF >> 6;
  //HAL_TIM_Base_Init(&hTIM5);
  HAL_TIM_OC_Init(&hTIM5);

  TIM_OC_InitTypeDef oc_enable;
  oc_enable.OCMode = TIM_OCMODE_PWM1;
  oc_enable.OCPolarity = TIM_OCPOLARITY_HIGH;
  oc_enable.OCFastMode = TIM_OCFAST_DISABLE;
  oc_enable.Pulse = 0;
  HAL_TIM_OC_ConfigChannel(&hTIM5, &oc_enable, TIM_CHANNEL_1);
  HAL_TIM_OC_ConfigChannel(&hTIM5, &oc_enable, TIM_CHANNEL_2);

  HAL_NVIC_SetPriority(TIM5_IRQn, 0, 0);
  HAL_NVIC_ClearPendingIRQ(TIM5_IRQn);
  HAL_NVIC_EnableIRQ(TIM5_IRQn);

  __HAL_TIM_SetCounter(&hTIM5,0);
  HAL_TIM_OC_Start(&hTIM5, TIM_CHANNEL_1);
  HAL_TIM_OC_Start(&hTIM5, TIM_CHANNEL_2);
  //HAL_TIM_OC_Start_IT(&hTIM5, TIM_CHANNEL_1);

  _motor_way_init();
}

void motor1_set_value(int cmd) {
  if(cmd < 0) {
    TIM5->CCR1 = -cmd;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
  }
  else {
    TIM5->CCR1 = cmd;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
  }
}

void motor2_set_value(int cmd) {
  if(cmd < 0) {
    TIM5->CCR2 = -cmd;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
  }
  else {
    TIM5->CCR2 = cmd;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
  }
}


void TIM5_IRQHandler(void) {
  BSP_LED_Toggle(LED4);
  HAL_TIM_IRQHandler(&hTIM5);
}
