/*
 * adc.h
 *
 *  Created on: Jun 25, 2023
 *      Author: habiba
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


typedef enum
{
	F_ADC_02, F_ADC_2,F_ADC_4,F_ADC_8,F_ADC_16, F_ADC_32, F_ADC_64,F_ADC_128
}ADC_Prescaler;

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL
}ADC_ReferenceVolatge;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);



#endif /* ADC_H_ */
