;
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



}




void ChangeSysClockPLL(){

volatile uint32_t* tempreg;
    uint32_t temp = 0;
    temp = ((1 << RCC_CFGR_PLLSRC)|(0x2 << RCC_CFGR_PLLMUL));
    RCC->CFGR |= temp;
    
    RCC->CR |= (1 << RCC_CR_HSEON); //ENABLE THE HSE CLOCK
    
    //WAIT UNTIL HSE IS READY
    while(!((RCC->CR & (1 << RCC_CR_HSERDY))));

    //ENABLE PLL
    RCC->CR |= (1 << RCC_CR_PLLON);

    //WAIT until PLL is ready
    
    while(!((RCC->CR) & (1 << RCC_CR_PLLRDY)));
    
    //SWITCH system clock source
    tempreg =(volatile uint32_t*)(FLASH_ACR_BASE_ADDRESS);
    *tempreg |= (0x1);

    RCC->CFGR |= (0x2 << RCC_CFGR_SW);
    
    //TURN OFF HSI
    RCC->CR &= ~(1 << RCC_CR_HSION);
}







void ADCxClockControl(ADC_t* pADC, uint8_t Action){
	if(Action == ENABLE){
		switch ((uint32_t)pADC){
			case ADC1_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 9);
			break;

			case ADC2_BASE_ADDRESS:
			RCC->APB2ENR |= (1 << 10);
			break;

		}
	}else if(Action == DISABLE){
		switch ((uint32_t)pADC){
			case ADC1_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 9);
			break;

			case ADC2_BASE_ADDRESS:
			RCC->APB2ENR &= ~(1 << 10);
			break;

		}
	}

}





    
