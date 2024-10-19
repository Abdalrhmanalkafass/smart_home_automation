/*
 * ldr.c
 *
 *  Created on: Oct 6, 2024
 *      Author: alkafass
 */

#include "ldr.h"
#include "gpio.h"
#include "adc.h"
#include "std_types.h"
#include "adc.h"


uint16 LDR_getLightIntensity(void) {

uint32 reading ;
GPIO_setupPinDirection(ldr_port,ldr_pin,PIN_INPUT) ;
ADC_init();
reading = ADC_readChannel(ldr_pin) ;

float value=0 ;
value = ((reading)/(float)ADC_MAXIMUM_VALUE) * ADC_REF_VOLT_VALUE ;

uint16 intensity = (value/ ldr_max_volt)*ldr_max_intensity ;
return intensity ;
}

