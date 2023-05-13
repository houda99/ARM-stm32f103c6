/*
 * SevenSEG.c
 *
 * Created: 2/24/2023 6:47:05 PM
 *  Author:  Ahmed Nour
 */

#include "SEVEN_int.h"
#include "Common_Function.h"
void sev_segment_init()
{
	DIO_voidSetPinDirection(seven_SEG_Port,PIN1,GPIO_OUTPUT_10MHZ_PP);//A
	DIO_voidSetPinDirection(seven_SEG_Port,PIN2,GPIO_OUTPUT_10MHZ_PP);//B
	DIO_voidSetPinDirection(seven_SEG_Port,PIN3,GPIO_OUTPUT_10MHZ_PP);//C
	DIO_voidSetPinDirection(seven_SEG_Port,PIN4,GPIO_OUTPUT_10MHZ_PP);//D
	DIO_voidSetPinDirection(seven_SEG_Port,PIN5,GPIO_OUTPUT_10MHZ_PP);//E
	DIO_voidSetPinDirection(seven_SEG_Port,PIN6,GPIO_OUTPUT_10MHZ_PP);//F
	DIO_voidSetPinDirection(seven_SEG_Port,PIN7,GPIO_OUTPUT_10MHZ_PP);//G


}

void seven_segment_enable(EN_Enable_segment EN)
{
	if(EN<=EN2)
	switch (EN)
	{
		case EN1 :DIO_voidSetPinDirection(Enable_seven_port,PIN1,GPIO_OUTPUT_10MHZ_PP); DIO_voidSetPinValue(Enable_seven_port,PIN1,GPIO_HIGH) ; break;
		case EN2 :DIO_voidSetPinDirection(Enable_seven_port,PIN2,GPIO_OUTPUT_10MHZ_PP); DIO_voidSetPinValue(Enable_seven_port,PIN2,GPIO_HIGH) ; break;
	}
}

void seven_segment_Disable(EN_Enable_segment EN)
{
	if(EN<=EN2)
	switch (EN)
	{
		case EN1 :DIO_voidSetPinValue(Enable_seven_port,PIN1,GPIO_LOW) ; break;
		case EN2 : DIO_voidSetPinValue(Enable_seven_port,PIN2,GPIO_LOW) ; break;
	}
}

void seven_segment_write_NO(u8 No)
{
	//No =3  ----> 0b0000 0011
	//					  dcba
	if(No<10)
	{
		DIO_voidSetPinValue(seven_SEG_Port,PIN4,GET_BIT(No,0));  //a
		DIO_voidSetPinValue(seven_SEG_Port,PIN5,GET_BIT(No,1));  //b
		DIO_voidSetPinValue(seven_SEG_Port,PIN6,GET_BIT(No,2));  //c
		DIO_voidSetPinValue(PIN7,seven_SEG_Port,GET_BIT(No,3));  //d
	}
}

void two_sev_seg(u8 No)
{
	//please don't forget the INIT fun.
	//NO = 48 ----> 4  8 use remender and divider

	u8 right=No%10;
	u8 left=No/10;
	//seven_segment_Disable(EN1);
	//seven_segment_Disable(EN2);
	seven_segment_write_NO(right);
	seven_segment_enable(EN1);
	_delay_ms(100);
	seven_segment_Disable(EN1);
	seven_segment_write_NO(left);
	seven_segment_enable(EN2);
	_delay_ms(100);
	seven_segment_Disable(EN2);
}
