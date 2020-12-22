/*
 * USART_HW.h
 *
 * Created: 10/21/2020 11:19:41 PM
 *  Author: Moataz
 */ 


#ifndef USART_HW_H_
#define USART_HW_H_

#define TRX_DIR			*((volatile uint8*)0x31)
#define TRX_TRANSMIT	*((volatile uint8*)0x32)
#define TRX_RECIEVE		*((const volatile uint8*)0x30)
#define TXD				1
#define RXD				0

#define UBRRH			*((uint8 volatile *const) 0x40)
#define UBRRL			*((uint8 volatile *const) 0x29)
#define UCSRA			*((uint8 volatile *const) 0x2B)
#define UCSRB			*((uint8 volatile *const) 0x2A)
#define UCSRC			*((uint8 volatile *const) 0x40)
#define UDR 			*((uint8 volatile *const) 0x2C)

typedef enum
{
	MPCM,
	U2X,
	PE,
	DOR,
	FE,
	UDRE,
	TXC,
	RXC
}UCSRA_BITS;

typedef enum
{
	TXB8,
	RXB8,
	UCSZ2,
	TXEN,
	RXEN,
	UDRIE,
	TXCIE,
	RXCIE
}UCSRB_BITS;

typedef enum
{
	UCPOL,
	UCSZ0,
	UCSZ1,
	USBS,
	UPM0,
	UPM1,
	UMSEL,
	URSEL
}UCSRC_BITS;

#endif /* USART_HW_H_ */