/*
 * VL53L1X.h
 *
 *  Created on: 24 août 2018
 *      Author: guillaume
 */

#ifndef D_VL53L1X_H_
#define D_VL53L1X_H_

#include "stm32f429xx.h"
#include "i2c.h"
#include "../Drivers/API_VL53L1X/core/VL53L1X_api.h"

void F_ReadMeasure_VL53L1X(void);
void F_Init_VL53L1X(void);


#endif /* D_VL53L1X_H_ */
