/**
 * @file gpio_map.h
 * @brief Memory map and registers for Blue Pill's GPIOx peripheral
 * @author Alex
 */

#ifndef GPIO_MAP_H
#define GPIO_MAP_H

#include "stm32f1xx.h"



/**
 * @brief Configuration struct for a gpio
 *
 */

typedef struct{

	uint8_t Pin;
	uint8_t Mode;
	uint8_t OutputSpeed;

}GPIOx_Config_t;



//Pin number definitions


#define GPIO_PIN0	(0x00)
#define GPIO_PIN1	(0x01)
#define GPIO_PIN2	(0x02)
#define GPIO_PIN3	(0x03)
#define GPIO_PIN4	(0x04)
#define GPIO_PIN5	(0x05)
#define GPIO_PIN6	(0x06)
#define GPIO_PIN7	(0x07)
#define GPIO_PIN8	(0x08)
#define GPIO_PIN9	(0x09)
#define GPIO_PIN10	(0x0A)
#define GPIO_PIN11	(0x0B)
#define GPIO_PIN12	(0x0C)
#define GPIO_PIN13	(0x0D)
#define GPIO_PIN14	(0x0E)
#define GPIO_PIN15	(0x0F)

// Pin Modes

#define GENERAL_PURPOSE_OUTPUT_PP	((0b00 << 2) | 0b1)
#define GENERAL_PURPOSE_OUTPUT_OD	((0b01 << 2) | 0b1)
#define ALTERNATE_FUNCTION_OUTPUT_PP	((0b10 << 2) | 0b1)
#define ALTERNATE_FUNCTION_OUTPUT_OD	((0b11 << 2) | 0b1)

#define ANALOG				((0b00 << 2) | 0b00)
#define INPUT_FLOATING			((0b01 << 2) | 0b00)
#define INPUT_PU_PD			((0b10 << 2) | 0b00)



//Output Speed
#define OUTPUT_SPEED_10MHZ		(0x01)
#define OUTPUT_SPEED_2MHZ		(0x02)
#define OUTPUT_SPEED_50MHZ		(0x03)


//Functions


void Gpio_Init(GPIOx_Config_t* pGpioConfig, GPIO_t* pGPIO);
void Gpio_Pin_Set(GPIO_t* pGPIO, uint8_t PinNumber);
void Gpio_Pin_Reset(GPIO_t* pGPIO, uint8_t PinNumber);
void Gpio_Pin_Toggle(GPIO_t* pGPIO, uint9_t PinNumber);


#endif
/**
 *
 * @brief Source file for the Gpio Driver
 * @author Alex
 */



#include "gpio.h"

/**
 * @brief This function Initialices a Specific Gpio Pin 
 * @param pGpioConfig Pointer to the configuration struct from the user
 * @param pGPIO Pointer to the peripheral base address
 */

void Gpio_Init(GPIOx_Config_t* pGpioConfig, GPIO_t* pGPIO){
	//Check if the pin is from the CRL or CRH register
	
	//CRL
	if(pGpioConfig->Pin < 8){

	//Check if its configured as an output or as an input checking wether the first bit is a 1 (output) 0 (input)
	
	//Output
	if((pGPIOConfig->Mode) & (0b1)){
	

	pGPIO->CRL &= ~(0xF << (pGPIOConfig->Pin * 4));
	pGPIO->CRL |= (((((pGPIOConfig->Mode) & ~(0b1)) | pGPIOConfig->Speed) << (pGPIOConfig->Pin * 4) );

	}else{//Input
	pGPIO->CRL &= ~(0xF << (pGPIOConfig->Pin * 4));
	pGPIO->CRL |= (pGPIOConfig->Mode << (pGPIOConfig->Pin * 4);
	}

	}else if( pGpioConfig->Pin > 7 && pGpioConfig->Pin < 16){
	
	//Check if its configured as an output or as an input checking wether the first bit is a 1 (output) 0 (input)
	
	//Output
	if((pGPIOConfig->Mode) & (0b1)){
	

	pGPIO->CRH &= ~(0xF << ((pGPIOConfig->Pin % 8) * 4));
	pGPIO->CRH |= (((((pGPIOConfig->Mode) & ~(0b1)) | pGPIOConfig->Speed) << ((pGPIOConfig->Pin % 8) * 4) );

	}else{//Input

	pGPIO->CRH &= ~(0xF << ((pGPIOConfig->Pin % 8) * 4));
	pGPIO->CRH |= (pGPIOConfig->Mode << ((pGPIOConfig->Pin % 8) * 4);
	}

	}

}
/**
 *
 * @brief Set a specific GPIO pin
 *
 *
 *
 *
 *
 */
void Gpio_Pin_Set(GPIO_t* pGPIO, uint8_t PinNumber){
	pGPIO->BSRR |= (1 << PinNumber);
	pGPIO->BSRR &= ~(1 << PinNumber);

}

/**
 *
 * @brief Reset a specific GPIO pin
 *
 *
 */
void Gpio_Pin_Reset(GPIO_t* pGPIO, uint8_t PinNumber){
	pGPIO->BSRR |= (1 << (PinNumber + 16));
	pGPIO->BSRR &= ~(1 << (PinNumber + 16));

}

/**
 *
 * @brief Toggle a specific GPIO pin
 *
 *
 *
 *
 *
 */
void Gpio_Pin_Toggle(GPIO_t* pGPIO, uint8_t PinNumber){
	
	if(pGPIO->ODR & (1 << PinNumber)){

	Gpio_Pin_Reset(pGPIO, PinNumber);

	}else{
	
	Gpio_Pin_Set(pGPIO, PinNumber);

	}

}
