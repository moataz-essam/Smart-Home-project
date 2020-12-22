/*
 * ADC_types.h
 *
 * Created: 9/21/2020 9:10:25 PM
 *  Author: Moataz
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

typedef enum
{
	ADC_A0,
	ADC_A1,
	ADC_A2,
	ADC_A3,
	ADC_A4,
	ADC_A5,
	ADC_A6,
	ADC_A7,
}ADC_Ch_type;

typedef enum
{
	MUX0,
	MUX1,
	MUX2,
	MUX3,
	MUX4,
	ADLAR,
	REFS0,
	REFS1	
}ADC_ADMUX_BITS;

typedef enum
{
	ADPS0,
	ADPS1,
	ADPS2,
	ADIE,
	ADIF,
	ADATE,
	ADSC,
	ADEN
}ADC_ADCSRA_BITS;

typedef enum
{
	RESERVED = 4,
	ADTS0,
	ADTS1,
	ADTS2
}ADC_SFIOR_BITS;

#endif /* ADC_TYPES_H_ */