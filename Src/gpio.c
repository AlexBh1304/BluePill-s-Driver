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
	if((pGpioConfig->Mode) & (0b1)){
	

	pGPIO->CRL &= ~(0xF << (pGpioConfig->Pin * 4));
	pGPIO->CRL |= (((((pGpioConfig->Mode) & ~(0b1)) | pGpioConfig->OutputSpeed) << (pGpioConfig->Pin * 4) ));

	}else{//Input
	pGPIO->CRL &= ~(0xF << (pGpioConfig->Pin * 4));
	pGPIO->CRL |= (pGpioConfig->Mode << (pGpioConfig->Pin * 4));
	}

	}else if(pGpioConfig->Pin < 8){
	
	//Check if its configured as an output or as an input checking wether the first bit is a 1 (output) 0 (input)
	
	//Output
	if((pGpioConfig->Mode) & (0b1)){
	

	pGPIO->CRH &= ~(0xF << ((pGpioConfig->Pin % 8) * 4));
	pGPIO->CRH |= (((((pGpioConfig->Mode) & ~(0b1)) | pGpioConfig->OutputSpeed) << ((pGpioConfig->Pin % 8) * 4) ));

	}else{//Input

	pGPIO->CRH &= ~(0xF << ((pGpioConfig->Pin % 8) * 4));
	pGPIO->CRH |= (pGpioConfig->Mode << ((pGpioConfig->Pin % 8) * 4));
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
	pGPIO->BSRR = (1 << PinNumber);

}

/**
 *
 * @brief Reset a specific GPIO pin
 *
 *
 */
void Gpio_Pin_Reset(GPIO_t* pGPIO, uint8_t PinNumber){
	pGPIO->BSRR = (1 << (PinNumber + 16));

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

