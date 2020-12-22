/*
 * KP.c
 *
 * Created: 9/15/2020 10:30:32 PM
 *  Author: Moataz
 */ 

#include "KP.h"

/***multi dimension array for symbols of the key pad***/
uint8 keys[ROWS][COLUMNS]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};

void KP_init()
{
	/***port initialization***/
	DIO_SetLowNibDir(KP_PORT,OUT);
	DIO_SetHighNibDir(KP_PORT,IN);
	
	/***activate pull up resistance***/
	DIO_WritePortLvl(KP_PORT,HIGH);
}

uint8 KP_Get_Key()
{
	volatile uint8 key = ' ';
	uint8 row,col;
	/***loop the output on rows***/
	for(row=0;row<ROWS;row++)
	{
		DIO_WritePortLvl(KP_PORT,HIGH);
		DIO_WritePin(KP_PORT,row,LOW);
		/***loop reading the input on rows***/
		for(col=0;col<COLUMNS;col++)
		{
			if(DIO_ReadPin(KP_PORT,(col+ROWS)) == LOW)
			{
				_delay_ms(20);
				key=keys[row][col];
				break;
			}
		}
	}
	return key;
}