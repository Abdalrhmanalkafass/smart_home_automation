/*
 * pwm.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Alkafass
 */
#include "pwm.h"
#include "avr/io.h"



void PWM_Timer0_Start(uint8 duty_cycle) {

	TCCR0 = 0b01101101;
	TCNT0 = 0;
	OCR0 = (duty_cycle / 100.00) * 255;
	DDRB |= (1 << PB3);

}
