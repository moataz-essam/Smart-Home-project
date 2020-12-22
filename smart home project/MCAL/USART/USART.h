/*
 * USART.h
 *
 * Created: 10/21/2020 11:19:56 PM
 *  Author: Moataz
 */ 


#ifndef USART_H_
#define USART_H_

#include "../../utils/STD_types.h"
#include "../../utils/BitMath.h"
//#include "DIO.h"
#include "USART_HW.h"

void USART_init(void);
void USART_SendData(uint8 u8Data);
void USART_SendString(uint8 *au8Str);
uint8 USART_ReceiveData(void);
uint8 *USART_ReceiveString(void);

#endif /* USART_H_ */