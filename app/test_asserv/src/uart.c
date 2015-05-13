#include "uart.h"

UART_HandleTypeDef my_uart;

uint8_t RxBuffer[128];
uint16_t RxSize = 128;

void uart_init(int baud) {
  GPIO_InitTypeDef gpio_init;
  gpio_init.Pin = GPIO_PIN_5;
  gpio_init.Pull = GPIO_NOPULL;
  gpio_init.Speed = GPIO_SPEED_HIGH;
  gpio_init.Mode = GPIO_MODE_AF_PP;
  gpio_init.Alternate = GPIO_AF7_USART2;

  __GPIOD_CLK_ENABLE();
  HAL_GPIO_Init(GPIOD, &gpio_init);

  gpio_init.Pin = GPIO_PIN_6;
  HAL_GPIO_Init(GPIOD, &gpio_init);

//  GPIO_InitTypeDef gpio_init;
//  gpio_init.Pin = GPIO_PIN_2;
//  gpio_init.Pull = GPIO_NOPULL;
//  gpio_init.Speed = GPIO_SPEED_HIGH;
//  gpio_init.Mode = GPIO_MODE_AF_OD;
//  gpio_init.Alternate = GPIO_AF7_USART2;

//  __GPIOA_CLK_ENABLE();
//  HAL_GPIO_Init(GPIOA, &gpio_init);

//  gpio_init.Pin = GPIO_PIN_3;
//  HAL_GPIO_Init(GPIOA, &gpio_init);

  __USART2_CLK_ENABLE();

  my_uart.Instance = USART2;
  my_uart.Init.BaudRate = baud;
  my_uart.Init.WordLength = UART_WORDLENGTH_8B;
  my_uart.Init.StopBits = UART_STOPBITS_1;
  my_uart.Init.Parity = UART_PARITY_NONE;
  my_uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  my_uart.Init.Mode = UART_MODE_TX_RX;
  HAL_UART_Init(&my_uart);
}

void uart_write_int(int val) {
#define MAX_BUFF 32
  const int false = 0;
  const int true = 1;
  const int SIGNED = true;
  typedef int bool;

  char str[MAX_BUFF] = {0};
  bool _neg = false;

  // Initialize string
  char* ptr = str + MAX_BUFF;
  *(--ptr) = '\0';

  // Parsing sign and digits
  if(SIGNED && val < 0) {
    val = -val;
    _neg = true;
  }

  while(0 < val && str < ptr) {
    *(--ptr) = '0' + (val % 10);
    val /= 10;
  }

  if(SIGNED && _neg) {
    *(--ptr) = '-';
  }

  // If no digits found
  if(*ptr == '\0') {
    *(--ptr) = '0';
  }

  HAL_UART_Transmit(&my_uart, (uint8_t*)ptr, MAX_BUFF - (ptr - str), 10000);
}

void uart_putchar(char c) {
  HAL_UART_Transmit(&my_uart, (uint8_t*)&c, 1, 10000);
}

char uart_getchar(void) {
  char c = 0;
  HAL_UART_Receive(&my_uart, (uint8_t*)&c, 1, 10000);
  return c;
}
