/*
 * ldr.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Alkafass
 */

#ifndef LDR_H_
#define LDR_H_
#include "std_types.h"
#include "gpio.h"
#define ldr_pin PIN0_ID
#define ldr_port PORTA_ID
#define ldr_max_volt 2.56
/*
 * This represents the maximum voltage output of the LDR sensor when exposed to the
lowest possible light intensity (darkness). In a voltage divider circuit, the LDR's resistance
decreases with increasing light, resulting in maximum voltage in darkness. This value
may vary based on the circuit configuration
 */

#define ldr_max_intensity 100
/*
 This represents the maximum light intensity the sensor can measure (0% → 100%
 */


uint16 LDR_getLightIntensity(void) ;

#endif /* LDR_H_ */
