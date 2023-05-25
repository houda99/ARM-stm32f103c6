/*
 * Segment7.c
 *
 *  Created on: May 4, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#include "Std_Types.h"
#include "DIO_interface.h"
#include "STK_interface.h"

#include "../../02 ECU/Segment7/Segment7_interface.h"

u8 NUM[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};



void Segment7_voidInit(u8 Port,u8 startpin)
{
	u8 i;
	for (i = startpin; i < startpin+8;i++)
	{
		DIO_voidSetPinDirection(Port, i, GPIO_OUTPUT_2MHZ_PP);
	}
}

void Segment7_voidSetValue(u8 port,u8 start,u8 data)
{
	if (data < 11)
	{
		DIO_voidWriteValue(port, start, NUM[data]);
		Segment7_voidDisplayOFF(port,start);
	}
}
void Segment7_voidDisplayON(u8 Port,u8 startpin)
{
	DIO_voidSetPinValue(Port, startpin+7, GPIO_LOW);
}
void Segment7_voidDisplayOFF(u8 Port,u8 startpin)
{
	DIO_voidSetPinValue(Port, startpin+7, GPIO_HIGH);
}
/***************Dual Mode******/
void Segment7_voidDualModeInit(u8 Port,u8 startpin)
{
	u8 i;
	for (i = startpin; i < startpin+9;i++)
	{
		DIO_voidSetPinDirection(Port, i, GPIO_OUTPUT_2MHZ_PP);
	}
}

void Segment7_voidDualModeSetValue(u8 port,u8 start,u8 data)
{
	u8 segR = data%10;
	u8 segL = (data-segR)/10;
	// Seg Right digit
	Segment7_voidSetValue(port,start,segR);
	Segment7_voidDisplayOFF(port,start+1);
	Segment7_voidDisplayON(port,start);
	STK_voidSetBusyWait(1000);
    Segment7_voidDisplayOFF(port,start);

    // Seg Left Value
	Segment7_voidSetValue(port,start,segL);
	Segment7_voidDisplayON(port,start+1);
	STK_voidSetBusyWait(1000);
    Segment7_voidDisplayOFF(port,start+1);
}

