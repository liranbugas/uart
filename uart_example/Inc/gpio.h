/*
 * gpio.h
 *
 *  Created on: Apr 11, 2024
 *      Author: liran
 */

#ifndef GPIO_H_
#define GPIO_H_


#define GPIO_A 0x40020000
#define RCC 0x40023800
#define RCC_AHB  0x30
#define RCC_APB1 0x40
#define USART2 0x40004400
#define GPIO_ALTFL 0x20
#define GPIO_PULLDOWN 0x0C
#define GPIO_OUTYPE 0x04
#include <stdint.h>
void gpio_ini();
//void gpio_out(int);
#endif /* GPIO_H_ */
