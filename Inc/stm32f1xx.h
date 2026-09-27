/**
 *
 *
 * @brief Blue pills peripheral definitions
 *
 *
 *
 */
#ifndef STM32F1XX_H
#define STM32F1XX_H

#include <stdint.h>

#define DISABLE 0
#define ENABLE 1

//GPIO

typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_t;

#define GPIOA_BASE_ADDRESS	0x40010800UL
#define GPIOB_BASE_ADDRESS	0x40010C00UL
#define GPIOC_BASE_ADDRESS	0x40011000UL
#define GPIOD_BASE_ADDRESS	0x40011400UL
#define GPIOE_BASE_ADDRESS	0x40011800UL


#define GPIOA			((GPIO_t*) GPIOA_BASE_ADDRESS)			
#define GPIOB			((GPIO_t*) GPIOB_BASE_ADDRESS)			
#define GPIOC			((GPIO_t*) GPIOC_BASE_ADDRESS)			
#define GPIOD			((GPIO_t*) GPIOD_BASE_ADDRESS)			
#define GPIOE			((GPIO_t*) GPIOE_BASE_ADDRESS)			

//RCC


typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t CFGR2;
}RCC_t;

#define RCC_BASE_ADDRESS	0x40021000UL

#define RCC			((RCC_t*) RCC_BASE_ADDRESS)			


typedef struct{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
}TIM_t;

#define TIM1_BASE_ADDRESS	0x40012C00UL
#define TIM2_BASE_ADDRESS	0x40000000UL
#define TIM3_BASE_ADDRESS	0x40000400UL
#define TIM4_BASE_ADDRESS	0x40000800UL

#define TIM1	((TIM_t*)(TIM1_BASE_ADDRESS))
#define TIM2	((TIM_t*)(TIM2_BASE_ADDRESS))
#define TIM3	((TIM_t*)(TIM3_BASE_ADDRESS))
#define TIM4	((TIM_t*)(TIM4_BASE_ADDRESS))

#define TIMx_CR1_CEN	0

typedef struct{

	volatile uint32_t ISER[3] ;

}NVIC_t;


#define NVIC_BASE_ADDRESS	0xE000E100UL

#define NVIC	((NVIC_t*)(NVIC_BASE_ADDRESS))


#endif
