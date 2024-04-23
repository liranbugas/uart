/*
 * gpio.c
 *
 *  Created on: Apr 11, 2024
 *      Author: liran
 */
#include "gpio.h"
static uint32_t* pRcc_Ahb_En = (uint32_t*)(RCC + RCC_AHB);
static uint32_t* pGpioA_Cr = (uint32_t*)(GPIO_A);
static uint32_t* pRcc_Apb1_En = (uint32_t*)(RCC +RCC_APB1);
static uint32_t* pGpio_A_Altf_L= (uint32_t*)(GPIO_A + GPIO_ALTFL);
static uint32_t* pGpio_A_Outype= (uint32_t*)(GPIO_A + GPIO_OUTYPE);
static uint32_t* pGpio_A_Pull_UpDown= (uint32_t*)(GPIO_A + GPIO_PULLDOWN);

void gpio_ini()
//Initialize the pin a2 as tx and a3 as rx
//alf7
//slave select pin is low when choose him
{
	 *pRcc_Ahb_En |= (1<<0);
	 *pRcc_Apb1_En |=(1<<17);
	 //to alternate function pin 2 and 3
	 *pGpioA_Cr &=0x00000000;
	 *pGpioA_Cr |=(1<<5);
	 *pGpioA_Cr |=(1<<7);

	 //open drain
	 *pGpio_A_Outype|=(0x3<<2);

	 //RX as pull up and TX as push pull
	 *pGpio_A_Pull_UpDown&=0x00000000;
	 *pGpio_A_Pull_UpDown|=(1<<7);

	 //alternate function state 7 for uart
	 *pGpio_A_Altf_L|=(7<<8);
	 *pGpio_A_Altf_L|=(7<<12);

}

//void gpio_out(int updown)
////choose high or low
//{
//	if(updown)
//	{
//		*pGpio_B_Out|=(1<<6);
//	}
//	else
//	{
//		*pGpio_B_Out&=~(1<<6);
//	}
//}


