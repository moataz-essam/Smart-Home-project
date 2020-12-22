/*
 * TIMER1.h
 *
 * Created: 12/21/2020 6:47:57 PM
 *  Author: Moataz
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "../../utils/BitMath.h"
#include "../../utils/interrupts.h"
#include "TIMER1_HW.h"
#include "TIMER1_types.h"
#include "../../config/TIMER1_cfg.h"

////////////*****clock prescaling*****////////////////////////////
#define TIMER1_PRESCALER_CLR			0b11111000
#define TIMER1_PRESCALER_1				0b00000001
#define TIMER1_PRESCALER_8				0b00000010
#define TIMER1_PRESCALER_64				0b00000011
#define TIMER1_PRESCALER_256			0b00000100
#define TIMER1_PRESCALER_1024			0b00000101
#define TIMER1_ExtClock_FALLING			0b00000110
#define TIMER1_ExtClock_RISING			0b00000111

////////////*****Timer 1  modes*****////////////////////////////
#define TIMER0_MODE_CLR					0b10110111
#define TIMER0_MODE_NORMAL				0b00000000
#define TIMER0_MODE_PHASE_CORRECT		0b01000000
#define TIMER0_MODE_CTC					0b00001000
#define TIMER0_MODE_FAST_PWM			0b01001000

////////////*****compare modes*****////////////////////////////
#define CMP_MODE_CLR					0b11001111
//compare modes if mode selected is fast PWM
#define CMP_MODE_NON_INVERT				0b00100000
#define CMP_MODE_INVERT					0b00110000
//compare modes if the selected mode is phase correct PWM
#define CMP_MODE_ClrUp_SetDown			0b00100000
#define CMP_MODE_SetUp_ClrDown			0b00110000
//compare mode if mode selected is normal PWM or CTC
#define CMP_MODE_TOGGLE_OC0				0b00100000
#define CMP_MODE_CLR_OC0				0b00110000
#define CMP_MODE_SET_OC0				0b00110000
////////////**********************////////////////////////////

void TIMER1_init(void);
void TIMER1_clr_counter(void);
void TIMER1_PRELOAD_COUNTER(uint16 preload_count);
void TIMER1_OutputCompare(uint16 PointOfCompareA,uint16 PointOfCompareB);
void TIMER1_INT_EN(void);
void TIMER1_INT_DIS(void);
//uint8 TIMER0_readCounterSteps(void);

#endif /* TIMER1_H_ */