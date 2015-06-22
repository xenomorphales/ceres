#ifndef UART_H
#define UART_H

#include <stm32f4xx_hal.h>

void uart_init(int baud);
void uart_write_int(int val);
void uart_putchar(char c);

char uart_getchar(void);

extern UART_HandleTypeDef my_uart;

#endif//UART_H
