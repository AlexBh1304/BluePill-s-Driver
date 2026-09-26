
#include "rcc.h"


void GPIOxClockControl(GPIO_t* pGPIO, uint8_t Action){
	if(Action == ENABLE){
		switch ((uint32_t)pGPIO){
			case GPIOA_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 2);
			break;

			case GPIOB_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 3);
			break;

			case GPIOC_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 4);
			break;

			case GPIOD_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 5);
			break;

			case GPIOE_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 6);
			break;
		}
	}else if(Action == DISABLE){
		switch ((uint32_t)pGPIO){
			case GPIOA_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 2);
			break;

			case GPIOB_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 3);
			break;

			case GPIOC_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 4);
			break;

			case GPIOD_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 5);
			break;

			case GPIOE_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 6);
			break;
		}
	
	}


}


void TIMxClockControl(TIM_t* pTIM, uint8_t Action){
	if(Action == ENABLE){
		switch ((uint32_t)pTIM){
			case TIM1_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 11);
			break;

			case TIM2_BASE_ADDRESS:
			RCC->APB1ENR |= (1 << 0);
			break;

			case TIM3_BASE_ADDRESS:
			RCC->APB1ENR |= (1 << 1);
			break;

			case TIM4_BASE_ADDRESS:
			RCC->APB1ENR |= (1 << 2);
			break;

		}
	}else if(Action == DISABLE){
		switch ((uint32_t)pTIM){
			case TIM1_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 11);
			break;

			case TIM2_BASE_ADDRESS:
			RCC->APB1ENR &= ~(1 << 0);
			break;

			case TIM3_BASE_ADDRESS:
			RCC->APB1ENR &= ~(1 << 1);
			break;

			case TIM4_BASE_ADDRESS:
			RCC->APB1ENR &= ~(1 << 2);
			break;

		}
	}


void TIMxClockControl(TIM_t* pTIM, uint8_t Action);}


