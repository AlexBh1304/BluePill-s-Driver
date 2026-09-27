
#include "nvic.h"

void EnableIRQ(uint8_t irqnumber){

	NVIC->ISER[0] |= (1 << irqnumber);

}
