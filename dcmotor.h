/*
 * dcmotor.h
 *
 *  Created on: Jun 25, 2023
 *      Author: habiba
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


typedef enum
{
	STOP,CLOCKWISE,ANTICLOCKWISE
}DcMotor_State;

typedef struct{
	DcMotor_State state;
	uint8 speed;
}DCMOTOR_ConfigType;


#define DC_IN1_PIN_ID               PIN0_ID
#define DC_IN2_PIN_ID               PIN1_ID
#define DC_EN1_PIN_ID               PIN3_ID


#define DC_IN_PORT_ID               PORTB_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


 void DcMotor_Init(void);
 void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DCMOTOR_H_ */
