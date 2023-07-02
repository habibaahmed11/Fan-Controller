/*
 * MiniProject3.c
 *
 *  Created on: Jun 25, 2023
 *      Author: habiba
 */

#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "dcmotor.h"
#include "pwm.h"
#include <avr/io.h>

int main(void)
{
	uint8 temp;
	uint8 speed;
	Timer0_PWM_Init(100);
	DcMotor_Init();

	ADC_ConfigType ADC_Configurations = {INTERNAL,F_ADC_8};

	LCD_init(); /* initialize LCD driver */

	ADC_init(&ADC_Configurations); /* initialize ADC driver */


	LCD_displayString("FAN IS    ");
	LCD_displayStringRowColumn(1,0,"Temp =    C");



	while(1)
	{

		/* Read the temperature and control the DC motor depending on it */
		temp = LM35_getTemperature();
		if (temp < 30) {
			DcMotor_Rotate(STOP, 0);
			LCD_displayStringRowColumn(0, 3, "Fan is OFF");
		} else if (temp >= 120) {
			DcMotor_Rotate(CLOCKWISE, 100);
			LCD_displayStringRowColumn(0, 3, "Fan is ON ");
		} else if (temp >= 90) {
			DcMotor_Rotate(CLOCKWISE, 75);
			LCD_displayStringRowColumn(0, 3, "Fan is ON ");
		} else if (temp >= 60) {
			DcMotor_Rotate(CLOCKWISE, 50);
			LCD_displayStringRowColumn(0, 3, "Fan is ON ");
		} else if (temp >= 30) {
			DcMotor_Rotate(CLOCKWISE, 25);
			LCD_displayStringRowColumn(0, 3, "Fan is ON ");
		}
		/* Print the temperature on the LCD */
		LCD_displayStringRowColumn(1, 3, "Temp = ");
		LCD_intgerToString(temp);
		if (temp < 100) {
			LCD_displayCharacter(' ');
		}
		LCD_displayString("C");
	}
	return 0;
}
