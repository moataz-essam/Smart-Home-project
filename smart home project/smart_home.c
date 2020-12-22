/*
 * smart_home.c
 *
 * Created: 10/27/2020 3:14:15 AM
 *  Author: Moataz
 */ 

#include "smart_home.h"
//initialization for ports of leds
void RoomsLight_init(void)
{
	DIO_SetPinDir('B',PIN0,OUT);
	DIO_SetPinDir('A',PIN2,OUT);
	DIO_SetPinDir('A',PIN3,OUT);
}
//function to input password using keypad
uint16 Get_Password(void)
{
	uint8 count = 0;
	uint8 num = 0;
	uint16 password =0;
	while (count < 4)
	{
		if (KP_Get_Key() != ' ')
		{
			num = KP_Get_Key();
			//calculate the number
			password = (password * 10) + num;
			LCD_SendChar('*');
			count++;
			_delay_ms(300);
		}
	}
	return password;
}
//function to compare input password with correct password and return true or false
STD_Boolean Check_Password(uint16 password,uint16 correct_password)
{
	STD_Boolean check;
	if (password == correct_password)
	{
		check = TRUE;
	}
	else
	{
		check = FALSE;
	}
	return check;
}
//function to display the temperature
void Display_Temp (uint8 temperature)
{
	LCD_GotoXY(0,0);
	LCD_SendString("Temperature=");
	LCD_SendNumber(temperature);
	LCD_SendChar('C');
}
//function to compare the input command with saved commands
STD_Boolean check_command(uint8* command, uint8* strng)
{
	STD_Boolean check;
	uint8 i = 0;
	while (command[i]!='\0')
	{
		if (command[i] == strng[i])
		{
			check = TRUE;
			i++;
		}
		else
		{
			check = FALSE;
			break;
		}
	}
	return check;
}
//function to get the command value
uint8 Get_Command(uint8* command)
{
	uint8 output = 0;
	if (check_command(command,"led1"))
	{
		output = 1;
	}
	else if (check_command(command,"led2"))
	{
		output = 2;
	}
	else if (check_command(command,"led3"))
	{
		output = 3;
	}
	else
	{
		output = 0;
	}
	return output;
}