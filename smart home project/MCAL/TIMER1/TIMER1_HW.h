/*
 * TIMER1_HW.h
 *
 * Created: 12/21/2020 6:48:23 PM
 *  Author: Moataz
 */ 


#ifndef TIMER1_HW_H_
#define TIMER1_HW_H_

#include "../../utils/STD_types.h"

#define OC1_DIR		*((volatile uint8*)0x31)

#define OC1B_PIN	4
#define OC1A_PIN	5

#define TCCR1A		*((volatile uint8*)0x4F)
#define TCCR1B		*((volatile uint8*)0x4E)
#define TCNT1H		*((volatile uint8*)0x4D)
#define TCNT1L		*((volatile uint8*)0x4C)
#define OCR1AH		*((volatile uint8*)0x4B)
#define OCR1AL		*((volatile uint8*)0x4A)
#define OCR1BH		*((volatile uint8*)0x49)
#define OCR1BL		*((volatile uint8*)0x48)
#define ICR1H		*((volatile uint8*)0x47)
#define ICR1L		*((volatile uint8*)0x46)
#define TIMSK		*((volatile uint8*)0x59)
#define TIFR		*((volatile uint8*)0x58)
//#define SFIOR		*((volatile uint8*)0x50)

#endif /* TIMER1_HW_H_ */