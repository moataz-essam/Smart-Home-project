/*
 * KP.h
 *
 * Created: 9/15/2020 10:30:21 PM
 *  Author: Moataz
 */ 


#ifndef KP_H_
#define KP_H_

#include <util/delay.h>
#include "..\..\MCAL\DIO\DIO.h"
#include "..\..\config\KP_cfg.h"



/***functions prototype***/
void KP_init();
uint8 KP_Get_Key();

#endif /* KP_H_ */