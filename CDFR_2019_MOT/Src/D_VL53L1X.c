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

//int status;

void F_ReadMeasure_VL53L1X(void)
{
	/*static VL53L1_RangingMeasurementData_t RangingData;
	uint8_t data_ready = 0;

	// Check if new data available
	status = VL53L1_GetMeasurementDataReady(Dev, &data_ready);

	if(data_ready == 1)
	{
		status = VL53L1_GetRangingMeasurementData(Dev, &RangingData);
		if(status==0)
		{
			//printf("%d,%d,%.2f,%.2f\n", RangingData.RangeStatus,RangingData.RangeMilliMeter,
			//				(RangingData.SignalRateRtnMegaCps/65536.0),RangingData.AmbientRateRtnMegaCps/65336.0);
			status = 0;
		}
		status = VL53L1_ClearInterruptAndStartMeasurement(Dev);
	}
*/
}


void F_Init_VL53L1X(void)
{

	/*uint32_t i = 0;
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
	F_I2C2_ReadRegister(0x52,0x01,0x10, &read_register);


	status = VL53L1_WaitDeviceBooted(Dev);
	  status = VL53L1_DataInit(Dev);
	  status = VL53L1_StaticInit(Dev);
	  status = VL53L1_SetDistanceMode(Dev, VL53L1_DISTANCEMODE_LONG);
	  status = VL53L1_SetMeasurementTimingBudgetMicroSeconds(Dev, 50000);
	  status = VL53L1_SetInterMeasurementPeriodMilliSeconds(Dev, 500);
	  status = VL53L1_StartMeasurement(Dev);


	  HAL_Delay(5000);

	  // Initialize Timer 6
	  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;	// Enable Timer 6

	  // RCC APB1 Clock = 84 MHz (1 tick every 12 ns)
	  // 16 bit counter : 65536
	  // So if we want 1 tick every 100µs --> Prescaler = 8400
	  // -------> 84MHz / 8400 --> 10 KHz = 100µs
	  TIM6->PSC = 8400-1;

	  // 1 Interrupt every second
	  // 1s / 100µs = 10000 ticks
	  TIM6->ARR = 10000; // 0 --> TIM6->ARR

	  // Continuous mode
	  TIM6->CR1 &=~TIM_CR1_OPM;
	  // Only overflow generates interrupt
	  TIM6->CR1 |= TIM_CR1_URS;
	  // Only overflow generates interrupt
	  TIM6->CR1 &= ~TIM_CR1_UDIS;

	  // Allow interrupt
	  TIM6->DIER |= TIM_DIER_UIE;

	  // Set TIM6 interrupt priority
	  NVIC_SetPriority(TIM6_DAC_IRQn,10);

	  // Enable TIM6 interrupt
	  NVIC_EnableIRQ(TIM6_DAC_IRQn);


	  // Start Timer
	  TIM6->CR1 |=TIM_CR1_CEN;
*/
}

void F_Send_CMD_VL53L1X()
{

}
