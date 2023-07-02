/*
 * adc.c
 *
 *  Created on: Jun 25, 2023
 *      Author: habiba
 */

#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	//Adjust ADMUX register bits
	ADMUX = ( ADMUX & 0x3F ) |(Config_Ptr -> ref_volt); //adjust reference voltage
	ADMUX = ( ADMUX & 0xE0 ) ;

	//Adjust ADCSRA register bits
	SET_BIT(ADCSRA, 7 ); // enable ADC
	CLEAR_BIT(ADCSRA, 3); //disable interrupts

	ADCSRA = ( ADCSRA & 0xF8 ) |(Config_Ptr -> prescaler); //adjust pre-scalar

}

uint16 ADC_readChannel(uint8 channel_num)
{

	channel_num &= 0x07; // number must be 0 -> 7
	ADMUX = ( ADMUX & 0xE0 ) |( channel_num ); //adjust channel number
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */




}
