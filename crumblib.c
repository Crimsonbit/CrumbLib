#include "crumblib.h"
#include <avr/io.h>
const uint8_t TIMER0 = 0;

void setNearestPrescaler(volatile uint8_t *, uint8_t , uint16_t, const uint16_t *, uint8_t);

CRUMBLIB_TIMER(0, led_blink1);
int main() {
	crumblib_timer_led_blink1_disable();	
}

void setNearestPrescaler(volatile uint8_t *TCCRB, uint8_t CSx0, uint16_t presc, const uint16_t *selectable_prescs, uint8_t numPresc){
	uint8_t i;
	for(i = numPresc; i > 0; i--){
		if(selectable_prescs[i] > presc){
			i = i & 0b111;
			//Assume CS Bits are consecutive in TCCRxB
			i <<= CSx0; 
			*TCCRB |= i;
			return;
		}
	}
}
