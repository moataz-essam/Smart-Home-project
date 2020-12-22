/*
 * DIO_HW.h
 *
 * Created: 9/15/2020 10:26:46 PM
 *  Author: Moataz
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_

/***commonly used register values***/
#define U8_REG_LOW		0x00
#define LOW_NIB_HIGH	0x0F
#define HIGH_NIB_HIGH	0xF0
#define U8_REG_HIGH		0xFF

/***direction registers***/
#define DDR_A	*((volatile uint8*)0x3A)
#define DDR_B	*((volatile uint8*)0x37)
#define DDR_C	*((volatile uint8*)0x34)
#define DDR_D	*((volatile uint8*)0x31)

/***output registers***/
#define PORT_A	*((volatile uint8*)0x3B)
#define PORT_B	*((volatile uint8*)0x38)
#define PORT_C	*((volatile uint8*)0x35)
#define PORT_D	*((volatile uint8*)0x32)

/***input registers***/
#define PIN_A	*((const volatile uint8*)0x39)
#define PIN_B	*((const volatile uint8*)0x36)
#define PIN_C	*((const volatile uint8*)0x33)
#define PIN_D	*((const volatile uint8*)0x30)

/***enum for the pins numbers***/
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_PinNo;

#endif /* DIO_HW_H_ */