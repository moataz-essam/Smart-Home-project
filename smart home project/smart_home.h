/*
 * smart_home.h
 *
 * Created: 10/27/2020 3:14:38 AM
 *  Author: Moataz
 */ 


#ifndef SMART_HOME_H_
#define SMART_HOME_H_

#define F_CPU	16000000ul

#include "HAL/LCD/LCD.h"
#include "HAL/KP/KP.h"
#include "MCAL/USART/USART.h"
#include "MCAL/TIMER1/TIMER1.h"
#include "MCAL/ADC/ADC.h"
#include "HAL/LM35/LM35.h"
//password for program
#define PASSWORD	1111
//commands shortcut
#define led1		1
#define led2		2
#define led3		3


void RoomsLight_init(void);
uint16 Get_Password(void);
STD_Boolean Check_Password(uint16 password,uint16 correct_password);
void Display_Temp (uint8 temperature);
uint8 Get_Command(uint8* command);
STD_Boolean check_command(uint8* command, uint8* strng);
void Do_Action(uint8 command);





#endif /* SMART_HOME_H_ */