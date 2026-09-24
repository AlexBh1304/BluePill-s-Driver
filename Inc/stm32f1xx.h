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


#define GPIOA			((Gpio_t*) GPIOA_BASE_ADDRESS)			
#define GPIOB			((Gpio_t*) GPIOB_BASE_ADDRESS)			
#define GPIOC			((Gpio_t*) GPIOC_BASE_ADDRESS)			
#define GPIOD			((Gpio_t*) GPIOD_BASE_ADDRESS)			
#define GPIOE			((Gpio_t*) GPIOE_BASE_ADDRESS)			

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

#define RCC			((Rcc_t*) RCC_BASE_ADDRESS)			

#endif
