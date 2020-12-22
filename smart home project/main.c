/*
 * smart home project.c
 *
 * Created: 10/26/2020 10:39:41 PM
 * Author : Moataz
 
 project for smart home to measure temperature and control the the room lights
 using commands (led1,led2,led3)
 */ 

#include "smart_home.h"
//global variable
uint8 command[5]="";


int main(void)
{
	//declaration of variables
	uint16 Entered_Password = 0;
	STD_Boolean check = FALSE;
	uint8 signal;
	uint8 rec_element;
	//modules initialization
	RoomsLight_init();
	LCD_init();
	KP_init();
	USART_init();
	ADC_init(ADC_A0);
	//////////////////loop for entering password
    while (1) 
    {
		LCD_SendString("Enter Password");
		LCD_GotoXY(1,0);
		Entered_Password = Get_Password();
		check = Check_Password(Entered_Password,PASSWORD);
/////////////////////////////////////////////////////if the password is correct
		if (check == TRUE)
		{
			LCD_ClrScreen();
			LCD_SendString("Correct Password");
			LCD_GotoXY(1,0);
			LCD_SendString("Send Command");
			_delay_ms(1000);
			LCD_ClrScreen();
			//timer1 counter start
			TIMER1_init();
			while (1)
			{
				//get command and display input on LCD
				LCD_GotoXY(1,0);
				for (uint8 i = 0; i<4; i++)
				{
					rec_element = USART_ReceiveData();
					LCD_SendChar(rec_element);
					command[i]=rec_element;
					command[i+1]='\0';
				}
				//check command
				signal = Get_Command(command);
				//reset command
				command[0]='\0';
				//do action of the case for each command
				switch (signal)
				{
				case led1:
						TOGGLE_BIT(PORT_A,PIN2);
						break;
				case led2:
						TOGGLE_BIT(PORT_A,PIN3);
						break;
				case led3:
						TOGGLE_BIT(PORT_B,PIN0);
						break;
				default://case for wrong command
						LCD_GotoXY(1,0);
						LCD_SendString("Wrong Command");
						break;
				}
				//clear command line
				_delay_ms(500);
				LCD_GotoXY(1,0);
				LCD_SendString("             ");
			}
		}
/////////////if the password is wrong
		else
		{
			LCD_ClrScreen();
			LCD_SendString("Wrong Password");
			_delay_ms(1000);
			LCD_ClrScreen();
		}		
	}
}
///interrupt service routine when timer1 overflow to get temperature and display it on LCD
ISR (TIMER1_OVF)
{
	static uint8 temp;
	temp = LM35_ReadTemp();
	Display_Temp(temp);
	LCD_GotoXY(1,0);
	LCD_SendString(command);//resume the input of the command
}