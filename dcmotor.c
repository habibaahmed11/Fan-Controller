/*
 * dcmotor.c
 *
 *  Created on: Jun 25, 2023
 *      Author: habiba
 */


#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "dcmotor.h"
#include "gpio.h"
#include "std_types.h"
#include "pwm.h"
#include <avr/io.h>


void DcMotor_Init(void)
{
	/* setup pin direction */
	GPIO_setupPinDirection(DC_IN_PORT_ID, DC_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_IN_PORT_ID, DC_IN2_PIN_ID, PIN_OUTPUT);

	/* Stop motor */
//	GPIO_writePin(DC_IN_PORT_ID , DC_IN1_PIN_ID , LOGIC_LOW);
//	GPIO_writePin(DC_IN_PORT_ID , DC_IN2_PIN_ID , LOGIC_LOW);
	DcMotor_Rotate(STOP,0);


}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	Timer0_PWM_Init(speed);

	GPIO_writePin(DC_IN_PORT_ID, DC_IN1_PIN_ID, GET_BIT(state,0));
	GPIO_writePin(DC_IN_PORT_ID, DC_IN2_PIN_ID, GET_BIT(state,1));


}
