/*
 * led.h
 *
 *  Created on: Oct 6, 2024
 *      Author: Admin
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include "gpio.h"


#define red_led 0
#define green_led 1
#define blue_led 2

#define red_pin PIN5_ID
#define green_pin PIN6_ID
#define blue_pin PIN7_ID
#define red_port PORTB_ID
#define green_port PORTB_ID
#define blue_port PORTB_ID

#define connection_led 1  //1:positive logic , 0:negative logic

uint8 led_id ;

void leds_init (void) ;
void leds_on(led_id) ;
void leds_off(led_id) ;


#endif /* LED_H_ */
