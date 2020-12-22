/*
 * LCD.c
 *
 * Created: 9/15/2020 10:30:56 PM
 *  Author: Moataz
 */ 

#include "LCD.h"

void LCD_Enable()
{
	DIO_WritePin(LCD_Ctrl,LCD_En,HIGH);
	_delay_us(10);
	DIO_WritePin(LCD_Ctrl,LCD_En,LOW);
}

void LCD_init()
{
	/***data port initialization***/
	DIO_SetHighNibDir(LCD_Data,OUT);
	
	/***control port initialization***/
	DIO_SetPinDir(LCD_Ctrl,LCD_RS,OUT);
	DIO_SetPinDir(LCD_Ctrl,LCD_RW,OUT);
	DIO_SetPinDir(LCD_Ctrl,LCD_En,OUT);
	
	/***LCD initialization***/
	_delay_ms(15);
	
	LCD_SendCommand(0x33);
	LCD_SendCommand(0x32);

	LCD_SendCommand(LCD_FUNCTION_4BIT_2LINES);
	/*display on*/
	LCD_SendCommand(LCD_DISP_ON);
	/*display clear*/
	LCD_SendCommand(LCD_CLEAR_SCREEN);
	/*entry mode set(increment and shift)*/
	LCD_SendCommand(LCD_ENTRY_MODE);
}

void LCD_ClrScreen()
{
	LCD_SendCommand(LCD_CLEAR_SCREEN);
}

void LCD_SendCommand(uint8 cmd)
{
	//1-set RS=0 RW=0
	DIO_WritePin(LCD_Ctrl,LCD_RS,LOW);
	DIO_WritePin(LCD_Ctrl,LCD_RW,LOW);
	
	//2-put second half of command on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,cmd);
	
	//3-enable falling edge
	LCD_Enable();
	
	//4-put the first half of command on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,cmd<<4);
	
	//5-enable falling edge
	LCD_Enable();
	
	_delay_ms(5);
}

void LCD_SendChar(uint8 data)
{
	//1-set RS=1 RW=0
	DIO_WritePin(LCD_Ctrl,LCD_RS,HIGH);
	DIO_WritePin(LCD_Ctrl,LCD_RW,LOW);
	
	//2-put second half of data on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,data);

	//3-enable falling edge
	LCD_Enable();
	
	//4-put the first half of data on LCD pins 4-->7
	DIO_WriteHighNibVal(LCD_Data,(data<<4));
	
	//5-enable falling edge
	LCD_Enable();
	
	_delay_ms(5);
}

void LCD_SendString(uint8 *string)
{
	uint8 i = 0;
	while(string[i] != '\0')
	{
		LCD_SendChar(string[i]);
		i++;
	}
}

void LCD_SendNumber(uint16 number)
{
	uint8 ascii[10] = {'0','1','2','3','4','5','6','7','8','9'};//array for ascii code of each integer
	uint8 stringofnumber[16],temp_string[16];
	uint8 k,temp,i = 0;
	//loop to get each individual number of the big number
	if (number == 0)
	{
		temp_string[i] = ascii[0];
		i++;
	}
	else
	{
		while(number != 0)
		{
			temp = number % 10;
			temp_string[i] = ascii[temp];//get the number as ascii code
			number /= 10;
			i++;
		}
	}
	stringofnumber[i] = '\0';//put null in the last element of the array
	//loop to reverse the order of numbers
	for(k=0; k<i; k++)
	{
		stringofnumber[i-k-1]=temp_string[k];
	}
	LCD_SendString(stringofnumber);
}

void LCD_SendRealNumber (float32  Number)
{
	if(Number < 0)
	{
		LCD_SendChar('-');
		Number = 0 - Number;
	}
	else{}
	uint16 integr = Number;
	LCD_SendNumber(integr);
	LCD_SendChar('.');
	float32 fraction = Number-integr;
	uint16 integrFrac = fraction * 10000;
	while((integrFrac % 10) == 0)
	{
		integrFrac /= 10;
	}
	//uint16 integrFrac = fraction * 1000;
	LCD_SendNumber(integrFrac);
}

void LCD_GotoXY(uint8 x,uint8 y)
{
	if (x==0)
	{
		LCD_SendCommand((LCD_BEGIN_AT_FIRST_ROW)+y);
	}
	else
	{
		LCD_SendCommand((LCD_BEGIN_AT_SECOND_ROW)+y);
	}
}