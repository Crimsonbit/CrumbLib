#ifndef _CRUMBLIB_INCLUDED

#ifndef __AVR_ATmega644PA__
#define __AVR_ATmega644PA__
#endif

#include <avr/io.h>
#define _CRUMBLIB_INCLUDED_

#define TIMER0_PRESCS 1, 8, 64, 256, 1024
#define TIMER1_PRESCS 1, 8, 64, 256, 1024
#define TIMER2_PRESCS 1, 8, 32, 64, 128, 256, 1024

#define CRUMBLIB_TIMER(Number, name)                                       \
	static inline void crumblib_timer_##name##_disable(void) {             \
		TCCR##Number##B &= ~(1 << CS##Number##2) & ~(1 << CS##Number##1) & \
		                   ~(1 << CS##Number##0);                            \
		(void)crumblib_timer_##name##_disable;                             \
	} \
	static inline void crumblib_timer_##Number##_set_presc(uint16_t presc) \
{  \
	const uint16_t a[] = { TIMER##Number##_PRESCS };\
	setNearestPrescaler(&TCCR##Number##B, CS##Number##0, presc, a, sizeof(a)/sizeof(a[0]));\
}  \

#endif
