/**
  ******************************************************************************
  * File Name          : I2C.c
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;
I2C_HandleTypeDef hi2c3;

/* I2C1 init function */
void MX_I2C1_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;	// Enable peripheral clock

	I2C1->CR2 &= ~I2C_CR2_FREQ;
	I2C1->CR2 |=  10;					// Set peripheral clock speed to 30Mhz

	I2C1->CCR &= ~I2C_CCR_FS ;			// Low speed mode : 100kHz
	I2C1->CCR |= 200 ;

	I2C1->CR1 |= I2C_CR1_PE;
	I2C1->CR1 |= I2C_CR1_ACK;

//	hi2c1.Instance = I2C1;
//	hi2c1.Init.ClockSpeed = 100000;
//	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
//	hi2c1.Init.OwnAddress1 = 0;
//	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
//	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
//	hi2c1.Init.OwnAddress2 = 0;
//	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
//	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
//	if (HAL_I2C_Init(&hi2c1) != HAL_OK)
//	{
//	_Error_Handler(__FILE__, __LINE__);
//	}

}
/* I2C2 init function */
void MX_I2C2_Init(void)
{

  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}
/* I2C3 init function */
void MX_I2C3_Init(void)
{

  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(i2cHandle->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspInit 0 */

  /* USER CODE END I2C1_MspInit 0 */

    /**I2C1 GPIO Configuration
    PB8     ------> I2C1_SCL
    PB9     ------> I2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* I2C1 clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();

    /* I2C1 interrupt Init */
    HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_SetPriority(I2C1_ER_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspInit 1 */

  /* USER CODE END I2C1_MspInit 1 */
  }
  else if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

    /**I2C2 GPIO Configuration
    PF0     ------> I2C2_SDA
    PF1     ------> I2C2_SCL
    */
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    /* I2C2 clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();

    /* I2C2 interrupt Init */
    HAL_NVIC_SetPriority(I2C2_EV_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_SetPriority(I2C2_ER_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C2_ER_IRQn);
  /* USER CODE BEGIN I2C2_MspInit 1 */

  /* USER CODE END I2C2_MspInit 1 */
  }
  else if(i2cHandle->Instance==I2C3)
  {
  /* USER CODE BEGIN I2C3_MspInit 0 */

  /* USER CODE END I2C3_MspInit 0 */

    /**I2C3 GPIO Configuration
    PC9     ------> I2C3_SDA
    PA8     ------> I2C3_SCL
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C3;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C3;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* I2C3 clock enable */
    __HAL_RCC_I2C3_CLK_ENABLE();

    /* I2C3 interrupt Init */
    HAL_NVIC_SetPriority(I2C3_EV_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C3_EV_IRQn);
    HAL_NVIC_SetPriority(I2C3_ER_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(I2C3_ER_IRQn);
  /* USER CODE BEGIN I2C3_MspInit 1 */

  /* USER CODE END I2C3_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspDeInit 0 */

  /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();

    /**I2C1 GPIO Configuration
    PB8     ------> I2C1_SCL
    PB9     ------> I2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8|GPIO_PIN_9);

    /* I2C1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }
  else if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PF0     ------> I2C2_SDA
    PF1     ------> I2C2_SCL
    */
    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_0|GPIO_PIN_1);

    /* I2C2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(I2C2_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C2_ER_IRQn);
  /* USER CODE BEGIN I2C2_MspDeInit 1 */

  /* USER CODE END I2C2_MspDeInit 1 */
  }
  else if(i2cHandle->Instance==I2C3)
  {
  /* USER CODE BEGIN I2C3_MspDeInit 0 */

  /* USER CODE END I2C3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C3_CLK_DISABLE();

    /**I2C3 GPIO Configuration
    PC9     ------> I2C3_SDA
    PA8     ------> I2C3_SCL
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_9);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_8);

    /* I2C3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(I2C3_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C3_ER_IRQn);
  /* USER CODE BEGIN I2C3_MspDeInit 1 */

  /* USER CODE END I2C3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/**
 * @brief
 *
 * @param[in]
 * @param[in]
 * @return
 *
 */
int Write_I2C1(uint8_t slave_adress, uint8_t *tab_to_send, uint8_t size){
	uint16_t i2c_status = 0;
	uint32_t timeout = 0;
	uint16_t i = 0;
	int status = I2C_STATUS_OK;	// Init return value to error

	// Send start
	I2C1->CR1 |= 0x0100; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB))	// wait for START condition (SB=1)
	{	if(timeout > I2C_TIMEOUT)
		{
			return I2C_STATUS_KO;
		}
		timeout++;
	}
		timeout = 0;

	// Send slave address
	I2C1->DR = (slave_adress << 1) & 0xFE;
	while (!(I2C1->SR1 & I2C_SR1_ADDR)) // wait for ADDRESS sent (ADDR=1)
	{
		if(timeout > I2C_TIMEOUT)
		{
			return I2C_STATUS_KO;
		}
		timeout++;
	}
	timeout = 0;
	i2c_status = I2C1->SR2; // read status to clear flag


	for(i=0;i<size;i++)
	{
		I2C1->DR = tab_to_send[i]; 			// Address in chip -> DR & write
		while ((!(I2C1->SR1 & I2C_SR1_TXE)) && (!(I2C1->SR1 & I2C_SR1_BTF))) // wait for DR empty (TxE)
		{
			if(timeout > I2C_TIMEOUT)
			{
				return 0;
			}
			timeout++;
		}
		timeout = 0;
	}

		I2C1->CR1 |= I2C_CR1_STOP; // send STOP bit
	return status;
}
/**
 * Write a single value in a slave register
 */
int F_I2C1_WriteRegister(uint8_t slave_addr, uint8_t register_addr, uint8_t value){
	int i2c_status = I2C_STATUS_OK;
	uint32_t timeout = 0;
//	uint16_t i = 0;

	// Send start
	I2C1->CR1 |= I2C_CR1_START; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB)){	// wait for START condition (SB=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Start Condition \n");
			return I2C_STATUS_KO;
		}
	timeout++;
	}
	timeout=0;
	// Send slave address
	I2C1->DR = (slave_addr<<1) & 0xFE  ;	// address + write
	while (!(I2C1->SR1 & I2C_SR1_ADDR)){// wait for ADDRESS sent (ADDR=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave address \n");
			return I2C_STATUS_KO;
		}
		timeout++;
	}
	timeout=0;
	i2c_status = I2C1->SR2; // read status to clear flag

	// Send register address
	I2C1->DR = register_addr;
	while ((!(I2C1->SR1 & I2C_SR1_TXE)) && (!(I2C1->SR1 & I2C_SR1_BTF))); // wait for DR empty (TxE)

		// Send new value to write to the register
	I2C1->DR = value;
	while ((!(I2C1->SR1 & I2C_SR1_TXE)) && (!(I2C1->SR1 & I2C_SR1_BTF))); // wait for DR empty (TxE)

	I2C1->CR1 |= I2C_CR1_STOP; // send STOP bit
	return i2c_status;
}

/**
 * Write a single value in a slave register
 */
int F_I2C1_WriteValue(uint8_t slave_addr, uint8_t value){
	int i2c_status = I2C_STATUS_OK;
	uint32_t timeout = 0;
//	uint16_t i = 0;

	// Send start
	I2C1->CR1 |= I2C_CR1_START; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB)){	// wait for START condition (SB=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Start Condition \n");
			return I2C_STATUS_KO;
		}
	timeout++;
	}
	timeout=0;
	// Send slave address
	I2C1->DR = (slave_addr<<1) & 0xFE  ;	// address + write
	while (!(I2C1->SR1 & I2C_SR1_ADDR)){// wait for ADDRESS sent (ADDR=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave address \n");
			return I2C_STATUS_KO;
		}
		timeout++;
	}
	timeout=0;
	i2c_status = I2C1->SR2; // read status to clear flag

	// Send register address
	I2C1->DR = value;
	while ((!(I2C1->SR1 & I2C_SR1_TXE)) && (!(I2C1->SR1 & I2C_SR1_BTF))); // wait for DR empty (TxE)


	I2C1->CR1 |= I2C_CR1_STOP; // send STOP bit
	return i2c_status;
}
/**
 * Read a single value from a slave register
 */
int F_I2C1_ReadRegister(uint8_t slave_addr, uint8_t register_addr, uint8_t *value_read){
	int i2c_status = I2C_STATUS_OK;	// Init return value to error
	int timeout=0;

	// Send start
	I2C1->CR1 |= I2C_CR1_START; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB)){	// wait for START condition (SB=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave start \n");
			return I2C_STATUS_KO;
		}
	timeout++;
	}
	// Send slave address
	I2C1->DR = slave_addr & 0xFE  ;	// address + write
	while (!(I2C1->SR1 & I2C_SR1_ADDR)){// wait for ADDRESS sent (ADDR=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave address \n");
			return I2C_STATUS_KO;
		}
		timeout++;
	}

	i2c_status = I2C1->SR2; // read status to clear flag

	// Send register address
	I2C1->DR = register_addr;
	while ((!(I2C1->SR1 & I2C_SR1_TXE)) && (!(I2C1->SR1 & I2C_SR1_BTF))); // wait for DR empty (TxE)

	// Send repeated start
	I2C1->CR1 |= I2C_CR1_START; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB));	// wait for START condition (SB=1)

	timeout=0;
	// Send slave address
	I2C1->DR = slave_addr | 1;	// address + read
	while (!(I2C1->SR1 & I2C_SR1_ADDR)){ // wait for ADDRESS sent (ADDR=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave address \n");
			return I2C_STATUS_KO;
		}
		timeout++;
	}
	i2c_status = I2C1->SR2; // read status to clear flag

	// prepare NACK
	I2C1->CR1 &= ~I2C_CR1_ACK;

	// Wait for Data available
	while (!(I2C1->SR1 & I2C_SR1_RXNE));
	*value_read = I2C1->DR; 			// Address in chip -> DR & write

	// send STOP bit
	I2C1->CR1 |= I2C_CR1_STOP;
	return i2c_status;
}

int F_I2C1_ReadMultipleRegister(uint8_t slave_addr, uint8_t register_addr, uint8_t nbData ,uint8_t *value_read){

	int i2c_status = I2C_STATUS_OK;	// Init return value to error
	int err_status;
	int timeout=0;

	// Send start
	I2C1->CR1 |= I2C_CR1_START; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB)){	// wait for START condition (SB=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave start \n");
			return I2C_STATUS_KO;
		}
	timeout++;
	}
	// Send slave address
	I2C1->DR = slave_addr & 0xFE  ;	// address + write
	while (!(I2C1->SR1 & I2C_SR1_ADDR)){// wait for ADDRESS sent (ADDR=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave address \n");
			return I2C_STATUS_KO;
		}
		timeout++;
	}

	err_status = I2C1->SR2; // read status to clear flag

	// Send register address
	I2C1->DR = register_addr;
	while ((!(I2C1->SR1 & I2C_SR1_TXE)) && (!(I2C1->SR1 & I2C_SR1_BTF))); // wait for DR empty (TxE)

	// Send repeated start
	I2C1->CR1 |= I2C_CR1_START; // send START bit
	while (!(I2C1->SR1 & I2C_SR1_SB));	// wait for START condition (SB=1)

	timeout=0;
	// Send slave address
	I2C1->DR = slave_addr | 1;	// address + read
	while (!(I2C1->SR1 & I2C_SR1_ADDR)){ // wait for ADDRESS sent (ADDR=1)
		if(timeout > I2C_TIMEOUT){
			printf("Erreur : Send slave address \n");
			return I2C_STATUS_KO;
		}
		timeout++;
	}
	err_status = I2C1->SR2; // read status to clear flag

	// Read multiple register
	for(int i=0 ; i<nbData ; i++){
		// if last byte send NACK
		if(i == (nbData-1)){
			I2C1->CR1 &= ~I2C_CR1_ACK;	// prepare NACK
		}else{
			I2C1->CR1 |= I2C_CR1_ACK;	// prepare ACK
		}

		while (!(I2C1->SR1 & I2C_SR1_RXNE)); // Data available

		value_read[i] = I2C1->DR ; 			// Address in chip -> DR & write
	}
	// send STOP bit
	I2C1->CR1 |= I2C_CR1_STOP;
	return i2c_status;
}

/* USER CODE END 1 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
