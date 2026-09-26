/**
 * @file gpio_map.h
 * @brief Memory map and registers for Blue Pill's GPIOx peripheral
 * @author Alex
 */

#ifndef GPIO_MAP_H
#define GPIO_MAP_H

#include "stm32f1xx.h"
#include <stdint.h>


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
void Gpio_Pin_Toggle(GPIO_t* pGPIO, uint8_t PinNumber);


#endif
