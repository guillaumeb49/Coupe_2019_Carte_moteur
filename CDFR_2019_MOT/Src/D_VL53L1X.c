/*
 * D_VL53L1X.c
 *
 *  Created on: 24 août 2018
 *      Author: guillaume
 */


#include "D_VL53L1X.h"

void F_Init_VL53L1X(void)
{
	uint32_t i = 0;
	uint8_t read_register = 0;

	// Enable clock on GPIOF (Normally should already be the case)
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

	// Configure PF2 as output to drive the Xshunt pin of the VL53L1
	GPIOF->MODER &= ~GPIO_MODER_MODE2;
	GPIOF->MODER |= GPIO_MODER_MODE2_0;

	// Set PF2 low
	GPIOF->ODR &=~ GPIO_ODR_OD2;

	// small delay
	for(i=0;i<65000;i++)
	{
		__asm("NOP");
	}

	// Set PF2 high
	GPIOF->ODR |= GPIO_ODR_OD2;

	F_I2C2_ReadRegister(0x52,0x01,0x10, &read_register);


}

void F_Send_CMD_VL53L1X()
{

}
