/*
 * motor.h
 *
 *  Created on: Oct 7, 2024
 *      Author: Admin
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "gpio.h"

typedef enum {
    STOP,           // Motor is stopped
    CW,             // Clockwise direction
    A_CW            // Anti-clockwise direction
} DcMotor_State;

#define H_bridge_input1_port PORTB_ID
#define H_bridge_input2_port PORTB_ID
#define H_bridge_enable_port PORTB_ID
#define H_bridge_input1_pin PIN0_ID
#define H_bridge_input2_pin PIN1_ID
#define H_bridge_enable_pin PIN2_ID


void DcMotor_Init(void) ;
void DcMotor_Rotate(DcMotor_State , uint8 speed);

#endif /* MOTOR_H_ */
