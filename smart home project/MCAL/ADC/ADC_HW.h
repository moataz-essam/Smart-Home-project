/*
 * ADC_HW.h
 *
 * Created: 9/21/2020 9:09:55 PM
 *  Author: Moataz
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

#include "../../utils/STD_types.h"

#define ADC_PORT_DIR	*((volatile uint8*)0x3A)
#define ADC_PORT_IN		*((volatile uint8*)0x39)
#define ADC_PORT_OUT	*((volatile uint8*)0x3B)

#define	ADMUX			*((volatile uint8*)0x27)
#define ADCSRA			*((volatile uint8*)0x26)

#define ADC				*((volatile uint16*)0x24)
#define ADCL			*((volatile uint8*)0x24)
#define ADCH			*((volatile uint8*)0x25)

#define SFIOR			*((volatile uint8*)0x50)

#endif /* ADC_HW_H_ */