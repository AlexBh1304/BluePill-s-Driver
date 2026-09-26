/**
 *
 *
 * @brief Functions to enable peripheral clocks
 *
 */


#ifndef RCC_H
#define RCC_H

#include "stm32f1xx.h"
#include "gpio.h"
#include "tim.h"
#include <stdint.h>

void GPIOxClockControl(GPIO_t* pGPIO, uint8_t Action);
void TIMxClockControl(TIM_t* pTIM, uint8_t Action);
#endif
