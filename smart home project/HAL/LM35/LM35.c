/*
 * LM35.c
 *
 * Created: 10/28/2020 1:50:23 AM
 *  Author: Moataz
 */ 

#include "LM35.h"
#include "../../MCAL/ADC/ADC.h"

uint16 LM35_ReadSample(void)
{
	uint16 u16data = 0;
	//ADC_INT_EN();
	u16data = ADC_ReadChannel(ADC_A0);
	return u16data;
}

uint8 LM35_ReadTemp(void)
{
	uint8 temperature = 0;
	temperature = LM35_ReadSample()/2;
	return temperature;
}
