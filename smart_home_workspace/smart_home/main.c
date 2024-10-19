/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: ALKAFASS
 */

#include "buzzer.h"
#include "lcd.h"
#include "led.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "std_types.h"
#include "util/delay.h"

void controlFan(uint8 temp) {
	if (temp < 25) {
		DcMotor_Rotate(STOP, 0);  // Fan is OFF
		LCD_moveCursor(0, 0);
		LCD_displayString("    FAN is OFF   "); // Ensure 12 characters for clearing old text
	} else {
		LCD_moveCursor(0, 0);
		LCD_displayString("    FAN is ON    "); // Ensure 12 characters for clearing old text
		if (temp < 30) {
			DcMotor_Rotate(CW, 25);  // Low speed
		} else if (temp < 35) {
			DcMotor_Rotate(CW, 50);  // Medium speed
		} else if (temp < 40) {
			DcMotor_Rotate(CW, 75);  // High speed
		} else {
			DcMotor_Rotate(CW, 100);  // Maximum speed
		}
	}
}

int main(void) {
	uint8 alert_fire = LOGIC_LOW;

	// Initialize modules
	buzzer_init();
	DcMotor_Init();
	FlameSensor_init();
	leds_init();
	LCD_init();
	ADC_init();  // Initialize ADC for light sensor (LDR)

	// Main loop
	while (1) {
		// Flame sensor check
		if (FlameSensor_getValue()) {
			alert_fire = LOGIC_HIGH;
		} else {
			alert_fire = LOGIC_LOW;
		}

		// If fire is detected, display warning and turn on buzzer
		if (alert_fire == LOGIC_HIGH) {
			LCD_displayStringRowColumn(0, 0, "  WARNING! FIRE     ");
			LCD_displayStringRowColumn(1, 0, "                          ");
			buzzer_on();
		} else {
			uint8 temp = LM35_getTemperature();
			uint8 intensity_ldr = LDR_getLightIntensity();

			buzzer_off();
			LCD_moveCursor(1, 0);
			LCD_displayString("Temp=");
			if (temp < 10) {
				LCD_intgerToString(temp);
				LCD_displayStringRowColumn(1, 6, "  ");
			} else if (temp < 100) {
				LCD_intgerToString(temp);
				LCD_displayStringRowColumn(1, 7, " ");
			} else {
				LCD_intgerToString(temp);
			}
			// Control LEDs based on light intensity
			if (intensity_ldr < 15) {
				leds_on(red_led);
				leds_on(green_led);
				leds_on(blue_led);
			} else if (intensity_ldr < 50) {
				leds_on(red_led);
				leds_on(green_led);
				leds_off(blue_led);
			} else if (intensity_ldr < 70) {
				leds_on(red_led);
				leds_off(green_led);
				leds_off(blue_led);
			} else {
				leds_off(red_led);
				leds_off(green_led);
				leds_off(blue_led);
			}

			// Control fan based on temperature
			controlFan(temp);

			LCD_moveCursor(1, 8); // Adjust the position for the light intensity
			LCD_displayString("LDR=");
			if (intensity_ldr < 10) {
				LCD_intgerToString(intensity_ldr);
				LCD_displayString("%  ");
			} else if (intensity_ldr < 100) {
				LCD_intgerToString(intensity_ldr);
				LCD_displayString("% ");
			} else {
				LCD_intgerToString(intensity_ldr);
				LCD_displayString("%");
			}

		}
	}

	return 0;
}

