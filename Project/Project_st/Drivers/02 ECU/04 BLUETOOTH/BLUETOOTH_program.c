/*
 * BLUETOOTH_program.c
 *
 *  Created on: May 24, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#include "Bit_Math.h"
#include "Std_Types.h"

#include "../../01 MCAL/06 USART/USART_interface.h"

#include "../04 BLUETOOTH/BLUETOOTH_interface.h"
void BLUETOOTH_voidinit(void)
{
	UART_init();
	UART_enableTX();
	UART_enableRX();
}
void BLUETOOTH_voidSendData(u8 data)
{
	UART_TXdata(data);
}
u8 BLUETOOTH_u8RecieveData(void)
{
	u8 data = 0;
	data =  UART_RXdata();
	return data;
}
