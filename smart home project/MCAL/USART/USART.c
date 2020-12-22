/*
 * USART.c
 *
 * Created: 10/21/2020 11:20:16 PM
 *  Author: Moataz
 */ 

#include "USART.h"

void USART_init(void)
{
	//Set Baud Rate
	//uint8 u8BaudReg = (FREQ/(16*BAUD)-1);

	UBRRL = 103;
	
	//set pins for recieving and transmitting
	CLR_BIT(TRX_DIR,RXD);
	SET_BIT(TRX_DIR,TXD);
	
	UCSRA = 0x00;
	UCSRB = 0x00;
	//set char type number of bits
	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	//stop bit
	//parity flag enable
	//Async or Sync
	//enable recieve and transmit
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void USART_SendData(uint8 u8Data)
{
	//wait flag --> transmit finish --> UDR empty
	while(!GET_BIT(UCSRA,UDRE));
	//send data //UDR
	UDR = u8Data;
}

void USART_SendString(uint8 *au8Str)
{
	// Write your code here
	uint8 i = 0;
	while(au8Str[i] != '\0')
	{
		USART_SendData(au8Str[i]);
		i++;
	}
}

uint8 USART_ReceiveData(void)
{
	uint8 u8RecData;
	//wait recieve finish
	while(!GET_BIT(UCSRA,RXC));
	u8RecData = UDR;
	//return data,UDR
	return u8RecData;
}

uint8 *USART_ReceiveString(void)
{
	//write your code here
	uint8 *au8Str;
	uint8 i = 0;
	while(au8Str[i] != '\0')
	{
		au8Str[i] = USART_ReceiveData();
		i++;
	}
	return *au8Str;
}