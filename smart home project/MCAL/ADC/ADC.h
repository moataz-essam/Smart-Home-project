/*
 * ADC.h
 *
 * Created: 9/21/2020 9:10:08 PM
 *  Author: Moataz
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_HW.h"
#include "ADC_types.h"
#include "../../config/ADC_cfg.h"

/*=========================================================
 * ADC Prescaler Select Bits
 *=========================================================*/
#define ADC_Prescaler_clr			0b11111000
#define ADC_Prescaler_2				0b00000001
#define ADC_Prescaler_4				0b00000010
#define ADC_Prescaler_8				0b00000011
#define ADC_Prescaler_16			0b00000100
#define ADC_Prescaler_32			0b00000101
#define ADC_Prescaler_64			0b00000110
#define ADC_Prescaler_128			0b00000111
//
/*=========================================================
 * Reference Selection Bits
 *=========================================================*/
#define ADC_VoltRef_clr				0b00111111
#define ADC_VoltRef_AREF			0b00000000
#define ADC_VoltRef_AVCC			0b01000000
#define ADC_VoltRef_2_56V			0b11000000
//
/*=========================================================
 * ADC Left Adjust Result
 *=========================================================*/
#define ADC_Adjust_clr				0b11011111
#define ADC_RightAdjust				0b00000000
#define ADC_LeftAdjust				0b00100000
//
/*=========================================================
 * ADC Auto Trigger Enable
 *=========================================================*/
#define ADC_Mode_clr				0b11011111
#define ADC_SingleConversion		0b00000000
#define ADC_AutoTrigging			0b00100000
//
/*=========================================================
 * ADC Auto Trigger Source
 *=========================================================*/
#define ADC_Trigger_clr							0b00011111
#define ADC_Trigger_Free_Running_mode			0b00000000
#define ADC_Trigger_Analog_Comparator			0b00100000
#define ADC_Trigger_Exti0						0b01000000
#define ADC_Trigger_Timer0Comp					0b01100000
#define ADC_Trigger_Timer0OVF					0b10000000
#define ADC_Trigger_Timer1CompB					0b10100000
#define ADC_Trigger_Timer1OVF					0b11000000
#define ADC_Trigger_Timer1CAPT					0b11100000

/*=========================================================
 * ADC input channel
 *=========================================================*/
#define ADC_channel_clr							0b11100000

void ADC_init(ADC_Ch_type channel);
void ADC_StartConversion (void);
uint16 ADC_ReadChannel(ADC_Ch_type channel);
void ADC_INT_EN(void);
void ADC_INT_DIS(void);
float32 ADC_getAnalog_readings(ADC_Ch_type channel);

#endif /* ADC_H_ */