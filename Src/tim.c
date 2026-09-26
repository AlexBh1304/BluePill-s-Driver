
/**
 *
 *
 *
 * @brief Timer related functions
 *
 *
 *
 *
 */


#include "tim.h"

void TimInit(Timer_Config* pTimConfig, TIM_t* TIMx){

	TIMx->ARR = pTimConfig->ARR;
	TIMx->PSC = pTimConfig->PSC;

}

void TimEnable(TIM_t* TIMx){
	TIMx->CR1 |= (1 << TIMx_CR1_CEN); 
}

void TimDisable(TIM_t* TIMx){

	TIMx->CR1 &= ~(1 << TIMx_CR1_CEN); 
}

void TimSetFrecuency(uint32_t UpdateFrecuency, TIM_t* TIMx){
	
	uint32_t temp;
	
	temp = ((8000000UL)/((UpdateFrecuency) * (1000UL))) - 1; 
	
	TIMx->PSC = temp;
	
	TIMx->ARR = 999UL;

}

uint8_t TimFlagStatus(TIM_t* TIMx, uint8_t FlagMask){
	
	if((TIMx->SR) & FlagMask){
	return 1;
	}else{
	return 0;
	}
}

void TimClearFlag(TIM_t* TIMx, uint8_t FlagMask){

	TIMx->SR &= ~(1 << FlagMask);

}
