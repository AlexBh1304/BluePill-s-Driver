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
#include <stdint.h>

void GPIOxClockControl(GPIO_t* pGPIO, uint8_t Action);

#endif
