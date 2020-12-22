/*
 * TIMER1.c
 *
 * Created: 12/21/2020 6:47:28 PM
 *  Author: Moataz
 */ 

#include "TIMER1.h"

void TIMER1_init(void)
{
	//set direction to output for OC1A and OC1B pin
	SET_BIT(OC1_DIR,OC1B_PIN);
	SET_BIT(OC1_DIR,OC1A_PIN);
	//clear TCCR1
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	//set timer mode
	////NORMAL MODE
	//set compare output mode
	/////NO COMPARE
	//enable interrupt
	TIMER1_INT_EN();
	
	//set pre-scaler
	TCCR1B &= TIMER1_PRESCALER_CLR;
	TCCR1B |= TIMER1_PRESCALER_SELECTED;
	
	//add preset value to count from it to the max
	TIMER1_PRELOAD_COUNTER(TIMER1_PRELOADED_COUNTER);
	//set compare point
	//TIMER1_OutputCompare(TIMER1_PointOfCompare);
}

void TIMER1_clr_counter(void)
{
	TCNT1H = 0x00;
	TCNT1L = 0x00;
}

void TIMER1_PRELOAD_COUNTER(uint16 preload_count)
{
	if (preload_count > 255)
	{
		TCNT1H = preload_count - 255;
		TCNT1L = 255;
	} 
	else
	{
		TCNT1H = 0;
		TCNT1L = preload_count;
	}
}

void TIMER1_OutputCompare(uint16 PointOfCompareA,uint16 PointOfCompareB)
{
	if (PointOfCompareA > 255)
	{
		OCR1AH = PointOfCompareA - 255;
		OCR1AL = 255;
	} 
	else
	{
		OCR1AH = 0;
		OCR1AL = PointOfCompareA;
	}
	if (PointOfCompareB > 255)
	{
		OCR1AH = PointOfCompareB - 255;
		OCR1AL = 255;
	} 
	else
	{
		OCR1AH = 0;
		OCR1AL = PointOfCompareB;
	}
}

void TIMER1_INT_EN(void)
{
	GLOBAL_INT_EN;
	SET_BIT(TIMSK,TOIE1);
}

void TIMER1_INT_DIS(void)
{
	CLR_BIT(TIMSK,TOIE1);
}