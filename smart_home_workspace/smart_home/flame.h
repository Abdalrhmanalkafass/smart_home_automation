/*
 * flame.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Alkafass
 */

#ifndef FLAME_H_
#define FLAME_H_
#include "std_types.h"
#include "gpio.h"

#define flame_port PORTD_ID
#define flame_pin  PIN2_ID



void FlameSensor_init(void) ;
uint8 FlameSensor_getValue(void) ;


#endif /* FLAME_H_ */
