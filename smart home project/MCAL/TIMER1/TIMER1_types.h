/*
 * TIMER1_types.h
 *
 * Created: 12/21/2020 6:48:47 PM
 *  Author: Moataz
 */ 


#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

typedef enum
{
	WGM10,
	WGM11,
	FOC1B,
	FOC1A,
	COM1B0,
	COM1B1,
	COM1A0,
	COM1A1
}TIMER1_TCCR1A_BITS;

typedef enum
{
	CS10,
	CS11,
	CS12,
	WGM12,
	WGM13,
	
	ICES1=6,
	ICNC1
}TIMER1_TCCR1B_BITS;

typedef enum
{
	TOIE1=2,
	OCIE1B,
	OCIE1A,
	TICIE1
}TIMER1_TIMSK_BITS;

typedef enum
{
	TOV1=2,
	OCF1B,
	OCF1A,
	ICF1
}TIMER1_TIFR_BITS;

#endif /* TIMER1_TYPES_H_ */