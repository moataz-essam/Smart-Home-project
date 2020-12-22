/*
 * DIO.h
 *
 * Created: 9/15/2020 10:27:04 PM
 *  Author: Moataz
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "..\..\utils\STD_types.h"
#include "..\..\utils\BitMath.h"
#include "DIO_HW.h"

/***configure single pin***/
void DIO_SetPinDir(uint8 port,uint8 PinNo,STD_Direction dir);
void DIO_WritePin(uint8 port,uint8 PinNo,STD_SignalLevel level);
STD_SignalLevel DIO_ReadPin(uint8 port,uint8 PinNo);
void DIO_FlipPin(uint8 port,uint8 PinNo);

/***configure the port***/
void DIO_SetPortDir(uint8 port,STD_Direction dir);
void DIO_WritePortLvl(uint8 port,STD_SignalLevel level);
void DIO_WritePortVal(uint8 port,uint8 data);
uint8 DIO_ReadPort(uint8 port);

/***configure half the pins of the port***/
void DIO_SetLowNibDir(uint8 port,STD_Direction dir);
void DIO_SetHighNibDir(uint8 port,STD_Direction dir);
void DIO_WriteLowNibVal(uint8 port,uint8 val);
void DIO_WriteHighNibVal(uint8 port,uint8 val);

#endif /* DIO_H_ */