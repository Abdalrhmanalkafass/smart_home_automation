/*
 * buzzer.h
 *
 *  Created on: Oct 6, 2024
 *      Author: alkafass
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "gpio.h"

#define buzzer_port PORTD_ID           //port D
#define buzzer_pin PIN3_ID



void buzzer_init(void) ;
void buzzer_on(void);
void buzzer_off(void);


#endif /* BUZZER_H_ */
