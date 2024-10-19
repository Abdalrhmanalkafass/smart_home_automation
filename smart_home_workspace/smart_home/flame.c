/*
 * flame.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Alkafass
 */
#include "gpio.h"
#include "flame.h"


void FlameSensor_init(void) {
	GPIO_setupPinDirection(flame_port, flame_pin, PIN_INPUT);
}
uint8 FlameSensor_getValue(void) {
	return GPIO_readPin(flame_port, flame_pin);

}

