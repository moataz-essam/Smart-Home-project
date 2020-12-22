/*
 * ADC.c
 *
 * Created: 9/21/2020 9:10:41 PM
 *  Author: Moataz
 */ 

#include "../../utils/BitMath.h"
#include "../../utils/interrupts.h"
#include "ADC.h"


void ADC_init(ADC_Ch_type channel)
{
	//setting direction of selected ADC channel
	SET_BIT(ADC_PORT_DIR,channel);
	
	//turn on the ADC module
	SET_BIT(ADCSRA,ADEN);
	
	//select conversion speed (prescaler)
	ADCSRA &= ADC_Prescaler_clr;
	ADCSRA |= ADC_Prescaler_Selected;
	
	//select voltage reference
	ADMUX &= ADC_VoltRef_clr;
	ADMUX |= ADC_VoltRef_Selected;
	
	//select the adjust of the ADC conversion result in the ADC Data Register(right or left)
	ADMUX &= ADC_Adjust_clr;
	ADMUX |= ADC_Adjust_Selected;
	
	//mode selected for ADC
	ADMUX &= ADC_Mode_clr;
	ADCSRA |= ADC_Mode_Selected;
	
#if ADC_Mode_Selected==ADC_AutoTrigging
	SFIOR &= ADC_Trigger_clr;
	SFIOR |= ADC_Trigger_Selected;
#endif
	//select ADC input channels
	ADMUX &= ADC_channel_clr;
	ADMUX |= channel;
}

void ADC_StartConversion (void)
{
	SET_BIT(ADCSRA,ADSC);
}

uint16 ADC_ReadChannel(ADC_Ch_type channel)
{
	uint16 read_value = 0;
	/***start conversion if ADC mode is single conversion***/
#if ADC_Mode_Selected == ADC_SingleConversion
	/* ADC Selection */
	ADMUX &= ADC_channel_clr;
	ADMUX |= channel;
#endif
	/* Start Conversion */
	ADC_StartConversion ();
	/*wait until conversion is done */
	while((GET_BIT(ADCSRA,ADIF)) == 0);
	
	//Get Results
	read_value = ADCL;
	read_value |= (ADCH<<8);

	return read_value;
}

void ADC_INT_EN(void)
{
	GLOBAL_INT_EN;
	SET_BIT(ADCSRA,ADIE);
}

void ADC_INT_DIS(void)
{
	CLR_BIT(ADCSRA,ADIE);
}

float32 ADC_getAnalog_readings(ADC_Ch_type channel)
{
	uint16 StepsNum,InputVolt;
	StepsNum = ADC_ReadChannel(channel);
	InputVolt = StepsNum*(ADC_VoltRef_mv/ADC_TOTAL_STEPS);
	return InputVolt;
}