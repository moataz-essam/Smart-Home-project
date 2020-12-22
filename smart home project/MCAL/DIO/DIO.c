/*
 * DIO.c
 *
 * Created: 9/15/2020 10:27:16 PM
 *  Author: Moataz
 */ 

#include "DIO.h"

/***configure direction of pin***/
void DIO_SetPinDir(uint8 port,uint8 PinNo,STD_Direction dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(dir == OUT)
		{
			SET_BIT(DDR_A,PinNo);
		}
		else
		{
			CLR_BIT(DDR_A,PinNo);
		}
		break;
		
		case 'B':
		case 'b':
		if(dir == OUT)
		{
			SET_BIT(DDR_B,PinNo);
		}
		else
		{
			CLR_BIT(DDR_B,PinNo);
		}
		break;
		
		case 'C':
		case 'c':
		if(dir == OUT)
		{
			SET_BIT(DDR_C,PinNo);
		}
		else
		{
			CLR_BIT(DDR_C,PinNo);
		}
		break;
		
		case 'D':
		case 'd':
		if(dir == OUT)
		{
			SET_BIT(DDR_D,PinNo);
		}
		else
		{
			CLR_BIT(DDR_D,PinNo);
		}
		break;
		
		default:
		//#error WrongPORTName
		break;
	}
}

/***write output to pin***/
void DIO_WritePin(uint8 port,uint8 PinNo,STD_SignalLevel level)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(level == HIGH)
		{
			SET_BIT(PORT_A,PinNo);
		}
		else
		{
			CLR_BIT(PORT_A,PinNo);
		}
		break;
		
		case 'B':
		case 'b':
		if(level == HIGH)
		{
			SET_BIT(PORT_B,PinNo);
		}
		else
		{
			CLR_BIT(PORT_B,PinNo);
		}
		break;
		
		case 'C':
		case 'c':
		if(level == HIGH)
		{
			SET_BIT(PORT_C,PinNo);
		}
		else
		{
			CLR_BIT(PORT_C,PinNo);
		}
		break;
		
		case 'D':
		case 'd':
		if(level == HIGH)
		{
			SET_BIT(PORT_D,PinNo);
		}
		else
		{
			CLR_BIT(PORT_D,PinNo);
		}
		break;
		
		default:
		/*error*/
		break;
	}
}

/***toggle output of the pin***/
void DIO_FlipPin(uint8 port,uint8 PinNo)
{
	switch(port)
	{
		case 'A':
		case 'a':
			TOGGLE_BIT(PORT_A,PinNo);
			break;
		
		case 'B':
		case 'b':
			TOGGLE_BIT(PORT_B,PinNo);
			break;
		
		case 'C':
		case 'c':
			TOGGLE_BIT(PORT_C,PinNo);
			break;
		
		case 'D':
		case 'd':
			TOGGLE_BIT(PORT_D,PinNo);
			break;
		
		default:
			/*error*/
			break;
	}
}

/***read input from pin***/
STD_SignalLevel DIO_ReadPin(uint8 port,uint8 PinNo)
{
	STD_SignalLevel signal;
	switch(port)
	{
		case 'A':
		case 'a':
		signal = GET_BIT(PIN_A,PinNo);
		break;
		
		case 'B':
		case 'b':
		signal = GET_BIT(PIN_B,PinNo);
		break;
		
		case 'C':
		case 'c':
		signal = GET_BIT(PIN_C,PinNo);
		break;
		
		case 'D':
		case 'd':
		signal = GET_BIT(PIN_D,PinNo);
		break;
		
		default:
		/*error*/
		break;
	}
	return signal;
}

/***configure direction of port***/
void DIO_SetPortDir(uint8 port,STD_Direction dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(dir ==  OUT)
		{
			SET_PORT(DDR_A);
		}
		else
		{
			CLR_PORT(DDR_A);
		}
		break;
		
		case 'B':
		case 'b':
		if(dir ==  OUT)
		{
			SET_PORT(DDR_B);
		}
		else
		{
			CLR_PORT(DDR_B);
		}
		break;
		
		case 'C':
		case 'c':
		if(dir ==  OUT)
		{
			SET_PORT(DDR_C);
		}
		else
		{
			CLR_PORT(DDR_C);
		}
		break;
		
		case 'D':
		case 'd':
		if(dir ==  OUT)
		{
			SET_PORT(DDR_D);
		}
		else
		{
			CLR_PORT(DDR_D);
		}
		break;
		
		default:
		/*error*/
		break;
	}
}

/***set output to high or low for the port***/
void DIO_WritePortLvl(uint8 port,STD_SignalLevel level)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(level == HIGH)
		{
			SET_PORT(PORT_A);
		}
		else
		{
			CLR_PORT(PORT_A);
		}
		break;
		
		case 'B':
		case 'b':
		if(level == HIGH)
		{
			SET_PORT(PORT_B);
		}
		else
		{
			CLR_PORT(PORT_B);
		}
		break;
		
		case 'C':
		case 'c':
		if(level == HIGH)
		{
			SET_PORT(PORT_C);
		}
		else
		{
			CLR_PORT(PORT_C);
		}
		break;
		
		case 'D':
		case 'd':
		if(level == HIGH)
		{
			SET_PORT(PORT_D);
		}
		else
		{
			CLR_PORT(PORT_D);
		}
		break;
		
		default:
		/*error*/
		break;
	}
}

/***write output to the port***/
void DIO_WritePortVal(uint8 port,uint8 data)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORT_A = data;
		break;
		
		case 'B':
		case 'b':
		PORT_B = data;
		break;
		
		case 'C':
		case 'c':
		PORT_C = data;
		break;
		
		case 'D':
		case 'd':
		PORT_D = data;
		break;
		
		default:
		/*error*/
		break;
	}
}

/***read input from port***/
uint8 DIO_ReadPort(uint8 port)
{
	uint8 input;
	switch(port)
	{
		case 'A':
		case 'a':
		input = PIN_A;
		break;
		
		case 'B':
		case 'b':
		input = PIN_B;
		break;
		
		case 'C':
		case 'c':
		input = PIN_C;
		break;
		
		case 'D':
		case 'd':
		input = PIN_D;
		break;
		
		default:
		/*error*/
		break;
	}
	return  input;
}

/***configure direction of first 4 pins of port***/
void DIO_SetLowNibDir(uint8 port,STD_Direction dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(dir == OUT)
		{
			SET_LOW_NIB(DDR_A);
		}
		else
		{
			CLR_LOW_NIB(DDR_A);
		}
		break;
		
		case 'B':
		case 'b':
		if(dir == OUT)
		{
			SET_LOW_NIB(DDR_B);
		}
		else
		{
			CLR_LOW_NIB(DDR_B);
		}
		break;
		
		case 'C':
		case 'c':
		if(dir == OUT)
		{
			SET_LOW_NIB(DDR_C);
		}
		else
		{
			CLR_LOW_NIB(DDR_C);
		}
		break;
		
		case 'D':
		case 'd':
		if(dir == OUT)
		{
			SET_LOW_NIB(DDR_D);
		}
		else
		{
			CLR_LOW_NIB(DDR_D);
		}
		break;
		
		default:
		/*error*/
		break;
	}
}

/***configure direction of second 4 pins of port***/
void DIO_SetHighNibDir(uint8 port,STD_Direction dir)
{
	switch(port)
	{
		case 'A':
		case 'a':
		if(dir == OUT)
		{
			SET_HIGH_NIB(DDR_A);
		}
		else
		{
			CLR_HIGH_NIB(DDR_A);
		}
		break;
		
		case 'B':
		case 'b':
		if(dir == OUT)
		{
			SET_HIGH_NIB(DDR_B);
		}
		else
		{
			CLR_HIGH_NIB(DDR_B);
		}
		break;
		
		case 'C':
		case 'c':
		if(dir == OUT)
		{
			SET_HIGH_NIB(DDR_C);
		}
		else
		{
			CLR_HIGH_NIB(DDR_C);
		}
		break;
		
		case 'D':
		case 'd':
		if(dir == OUT)
		{
			SET_HIGH_NIB(DDR_D);
		}
		else
		{
			CLR_HIGH_NIB(DDR_D);
		}
		break;
		
		default:
		/*error*/
		break;
	}
}

/***write output to the first 4 pins of the port***/
void DIO_WriteLowNibVal(uint8 port,uint8 val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORT_A = CLR_LOW_NIB(PORT_A) | CLR_HIGH_NIB(val);
		break;
		
		case 'B':
		case 'b':
		PORT_B = CLR_LOW_NIB(PORT_B) | CLR_HIGH_NIB(val);
		break;
		
		case 'C':
		case 'c':
		PORT_C = CLR_LOW_NIB(PORT_C) | CLR_HIGH_NIB(val);
		break;
		
		case 'D':
		case 'd':
		PORT_D = CLR_LOW_NIB(PORT_D) | CLR_HIGH_NIB(val);
		break;
		
		default:
		/*error*/
		break;
	}
}

/***write output to the second 4 pins of the port***/
void DIO_WriteHighNibVal(uint8 port,uint8 val)
{
	switch(port)
	{
		case 'A':
		case 'a':
		PORT_A = CLR_HIGH_NIB(PORT_A) | CLR_LOW_NIB(val);
		break;
		
		case 'B':
		case 'b':
		PORT_B = CLR_HIGH_NIB(PORT_B) | CLR_LOW_NIB(val);
		break;
		
		case 'C':
		case 'c':
		PORT_C = CLR_HIGH_NIB(PORT_C) | CLR_LOW_NIB(val);
		break;
		
		case 'D':
		case 'd':
		PORT_A = CLR_HIGH_NIB(PORT_D) | CLR_LOW_NIB(val);
		break;
		
		default:
		/*error*/
		break;
	}
}