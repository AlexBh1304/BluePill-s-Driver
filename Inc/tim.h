/**
 *
 *
 * @brief Header file for timer basic peripherals
 *
 *
 *
 *
 */

#ifndef TIM_H
#define TIM_H

#include "stm32f1xx.h"


typedef struct{

	uint16_t ARR;
	uint16_t PSC;
	uint16_t MODE;
	
}Timer_Config;

void TimInit(Timer_Config* pTimConfig, TIM_t* TIMx);
void TimEnable(TIM_t* TIMx);
void TimDisable(TIM_t* TIMx);
void TimSetFrecuency(uint32_t UpdateFrecuency, TIM_t* TIMx);
uint8_t TimFlagStatus(TIM_t* TIMx, uint8_t FlagMask);

void TimClearFlag(TIM_t* TIMx, uint8_t FlagMask);
#define TIM_SR_FLAG_UI	0x01U

#endif
