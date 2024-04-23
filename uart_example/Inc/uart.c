/*
 * uart.c
 *
 *  Created on: Apr 23, 2024
 *      Author: liran
 */

#include "uart.h"
static uint32_t* pUart_Cr1 = (uint32_t*)(USART2 + USART_CR1);
static uint32_t* pUart_Brr =(uint32_t*)(USART2 + USART_BRR);
static uint32_t* pUart_Dr =(uint32_t*)(USART2 +USART_DR);
static uint32_t* pUart_Sr =(uint32_t*)(USART2);
void uart_ini()
//initialize uart protocol
{
	//enable tx,rx, usart
	*pUart_Cr1 =0;
	*pUart_Cr1 |= (1<<13);
	*pUart_Cr1 |=(1<<3);
	*pUart_Cr1 |=(1<<2);

	//baud rate 115200
	*pUart_Brr |=(8<<4);
}
void uart_send()
//send data
{
	//send 9 number
	*pUart_Dr = 9;
	//wait for transmission complete tc =1
	while(!(*pUart_Sr)&(1<<6));
}

void uart_recieve()
//recieve data
{
	uint8_t temp;
	while(!(*pUart_Sr)&(1<<5));
	temp = *pUart_Dr;
}
