/*
 * button.c
 *
 * Created: 2/7/2023 12:54:49 PM
 *  Author: Mahmoud Osama
 */ 
#include "DIO_interface.h"
#include "Button_interface.h"

void BUTTON_init(u8 buttonport,u8 buttonpin)
{
	DIO_voidSetPinDirection(buttonport,buttonpin,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(buttonport,buttonpin,GPIO_HIGH);
}

u8 BUTTON_read(u8 buttonPort,u8 buttonpin)
{
	u8 value;
	value=DIO_u8GetPinValue(buttonPort,buttonpin);
	return value;
}
