/*
 * motor.c
 *
 *  Created on: Oct 7, 2024
 *      Author: Alkafass
 */

#include "motor.h"
#include "pwm.h"

void DcMotor_Init(void) {
	GPIO_setupPinDirection(H_bridge_input1_port, H_bridge_input1_pin,
			PIN_OUTPUT);
	GPIO_setupPinDirection(H_bridge_input2_port, H_bridge_input2_pin,
			PIN_OUTPUT);
	GPIO_setupPinDirection(H_bridge_enable_port, H_bridge_enable_pin,
			PIN_OUTPUT);
	GPIO_writePin(H_bridge_input1_port, H_bridge_input1_pin, LOGIC_LOW);
	GPIO_writePin(H_bridge_input2_port, H_bridge_input2_pin, LOGIC_LOW);

}
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	PWM_Timer0_Start(speed);


	switch (state) {
	case CW:
		GPIO_writePin(H_bridge_input1_port, H_bridge_input1_pin, LOGIC_HIGH);
		GPIO_writePin(H_bridge_input2_port, H_bridge_input2_pin, LOGIC_LOW);

		break;
	case A_CW:
		GPIO_writePin(H_bridge_input1_port, H_bridge_input1_pin, LOGIC_LOW);
		GPIO_writePin(H_bridge_input2_port, H_bridge_input2_pin, LOGIC_HIGH);

		break;
	case STOP:
		GPIO_writePin(H_bridge_input1_port, H_bridge_input1_pin, LOGIC_LOW);
		GPIO_writePin(H_bridge_input2_port, H_bridge_input2_pin, LOGIC_LOW);

		break;
	}

}

