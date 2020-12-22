/*
 * ADC_cfg.h
 *
 * Created: 9/21/2020 9:09:37 PM
 *  Author: Moataz
 */ 


#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*=========================================================
 * ADC Pre-scaler Select
 ***********************
ADC_Prescaler_2
ADC_Prescaler_4
ADC_Prescaler_8
ADC_Prescaler_16
ADC_Prescaler_32
ADC_Prescaler_64
ADC_Prescaler_128
=========================================================*/
//selected pre-scaler for the ADC
#define ADC_Prescaler_Selected		ADC_Prescaler_128
#define ADC_Prescaler_Value			128
////////////////////////////////////////////////////////////////////////

/*=========================================================
 * Reference Selection Bits
 **************************
 *ADC_VoltRef_AREF
 *ADC_VoltRef_AVCC
 *ADC_VoltRef_2_56V
=========================================================*/
//selected voltage reference for the ADC
#define ADC_VoltRef_Selected		ADC_VoltRef_AVCC

/*=========================================================
 * ADC Left Adjust Result
**************************
ADC_RightAdjust
ADC_LeftAdjust
 *=========================================================*/
//selected presentation of the ADC conversion result in the ADC Data Register
#define ADC_Adjust_Selected			ADC_RightAdjust

/*=========================================================
 * ADC Auto Trigger Enable
 **************************
ADC_SingleConversion
ADC_AutoTrigging
 *=========================================================*/
//selected mode for ADC
#define ADC_Mode_Selected			ADC_AutoTrigging

/*=========================================================
 * ADC Auto Trigger Source
***************************
ADC_Trigger_Free_Running_mode
ADC_Trigger_Analog_Comparator
ADC_Trigger_Exti0
ADC_Trigger_Timer0Comp
ADC_Trigger_Timer0OVF
ADC_Trigger_Timer1CompB
ADC_Trigger_Timer1OVF
ADC_Trigger_Timer1CAPT
 *=========================================================*/
//select auto trigger source for the ADC
#define ADC_Trigger_Selected					ADC_Trigger_Free_Running_mode

#define ADC_VoltRef_mv 							5000

/*--------------------------
 * choose between 255, 1023
 * --------------------------*/
#define ADC_TOTAL_STEPS							1023

#endif /* ADC_CFG_H_ */