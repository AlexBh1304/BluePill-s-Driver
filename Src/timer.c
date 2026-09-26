
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


#include "timer.h"

void TimInit(Timer_Config* pTimConfig, TIM_t* TIMx){

	TIMx->ARR = pTimConfig->ARR;
	TIMx->PSC = pTimConfig->PSC;

}

void TimEnable(Timer_Config* pTimConfig, TIM_t* TIMx){
	TIMx->CR1 |= (1 << TIMx_CR1_CEN); 
}

void TimDisable(Timer_Config* pTimConfig, TIM_t* TIMx){

	TIMx->CR1 &= ~(1 << TIMx_CR1_CEN); 
}

