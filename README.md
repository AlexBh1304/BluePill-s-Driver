# Blue Pill Peripheral Drivers (STM32F103)

Bare-metal peripheral drivers for the **Blue Pill** board, whose microcontroller is the **STM32F103C8T6** (ARM Cortex-M3). Written in C at register level.

## Current peripheral support

| Peripheral | Status | Details |
|------------|--------|---------|
| **RCC** | Supported | Clock enable / disable for GPIOA to GPIOE, TIM1 to TIM4 and ADC1 / ADC2. System clock switch to the PLL using the external crystal (HSE) |
| **GPIO** | Supported | Init, set, reset and toggle on any pin. Modes: general-purpose and alternate-function outputs (push-pull / open-drain), analog, floating and pull-up / pull-down inputs. Speeds: 2, 10 and 50 MHz |
| **TIM** | Supported | Init (prescaler, auto-reload, CCR1), enable / disable, update frequency, flag status and clear, update and capture/compare interrupt enable |
| **NVIC** | Supported | Enable an interrupt by IRQ number (TIM1 update and TIM1 capture/compare defined) |
| ADC | In progress | Clock control done, driver not implemented yet |
| USART | Not yet | |
| I2C | Not yet | |
| SPI | Not yet | |

## Layout

```
Inc/   Headers (register definitions in stm32f1xx.h, one header per driver)
Src/   Driver sources: gpio.c, rcc.c, tim.c, nvic.c, adc.c
```

## Example

```c
#include "gpio.h"
#include "rcc.h"

int main(void)
{
    GPIOx_Config_t led;

    GPIOxClockControl(GPIOC, ENABLE);

    led.Pin         = GPIO_PIN13;
    led.Mode        = GENERAL_PURPOSE_OUTPUT_PP;
    led.OutputSpeed = OUTPUT_SPEED_2MHZ;
    Gpio_Init(&led, GPIOC);

    while (1)
    {
        Gpio_Pin_Toggle(GPIOC, GPIO_PIN13);
        for (volatile uint32_t i = 0; i < 200000; i++);
    }
}
```

## Build

Toolchain: `arm-none-eabi-gcc` (Cortex-M3).
Add `Inc/` to the include path and compile the files in `Src/` together with your own `main.c`, startup code and linker script.

## Used in

- [scara-robot-firmware](https://github.com/AlexBh1304/scara-robot-firmware): 3-axis robot arm firmware (STM32F103, porting to STM32F411)
