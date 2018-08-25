/*
 * D_VL53L1X.c
 *
 *  Created on: 24 août 2018
 *      Author: guillaume
 */


#include "D_VL53L1X.h"


UART_HandleTypeDef 	huart2;
VL53L1_Dev_t		dev;
VL53L1_DEV			Dev = &dev;

int status;



void F_Init_VL53L1X(void)
{
	static VL53L1_RangingMeasurementData_t RangingData;


	uint32_t i = 0;
	uint8_t read_register = 0;
	Dev->I2cHandle = &hi2c2;
	Dev->I2cDevAddr = 0x52;

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
	status = VL53L1_RdByte(Dev, 0x010F, &read_register);
	//F_I2C2_ReadRegister(0x52,0x01,0x10, &read_register);


	status = VL53L1_WaitDeviceBooted(Dev);
	  status = VL53L1_DataInit(Dev);
	  status = VL53L1_StaticInit(Dev);
	  status = VL53L1_SetDistanceMode(Dev, VL53L1_DISTANCEMODE_LONG);
	  status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(Dev, 50000);
	  status = VL53L1_SetInterMeasurementPeriodMilliSeconds(Dev, 500);
	  status = VL53L1_StartMeasurement(Dev);


	  HAL_Delay(5000);

	  do // polling mode
	  		{
	  		  status = VL53L1_WaitMeasurementDataReady(Dev);
	  			if(!status)
	  			{
	  				status = VL53L1_GetRangingMeasurementData(Dev, &RangingData);
	  				if(status==0){
	  					//printf("%d,%d,%.2f,%.2f\n", RangingData.RangeStatus,RangingData.RangeMilliMeter,
	  					//				(RangingData.SignalRateRtnMegaCps/65536.0),RangingData.AmbientRateRtnMegaCps/65336.0);
	  					status = 0;
	  				}
	  				status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
	  			}
	  		}
	  		while (1);


}

void F_Send_CMD_VL53L1X()
{

}
