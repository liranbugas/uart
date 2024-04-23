/*
 * uart.h
 *
 *  Created on: Apr 23, 2024
 *      Author: liran
 */

#ifndef UART_H_
#define UART_H_

//#define RCC 0x40023800
//#define RCC_APB1 0x40
#define USART2 0x40004400
#define USART_DR 0x04
#define USART_CR1 0x0C
#define USART_CR2 0x10
#define USART_BRR 0x08
#include <stdint.h>
void uart_ini();
void uart_send();
void uart_recieve();
#endif /* UART_H_ */
