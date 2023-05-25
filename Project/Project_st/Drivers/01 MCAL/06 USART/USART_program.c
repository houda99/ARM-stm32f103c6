/*
 * USART_program.c
 *
 *  Created on: May 14, 2023
 *      Author: es-MohamedHAbdelAziz
 */


/*
 *
 *
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "../06 USART/USART_config.h"
#include "../06 USART/USART_interface.h"
#include "../06 USART/USART_private.h"

void UART_init(void) {
	// set Baud rate
	USART1 -> BRR = USART1_BAUDRATE;
	// Enable RXNEIE
	//USART1 -> CR1 = 1 << RXNEIE;
	// enable transmission complete interrupt
	//USART1 -> CR1 = 1 << TCIE;
	// USART1 -> CR1 = 1 << TXEIE;
#if USART1_PARITY == PARITY_NO
	USART1 -> CR1 |= 1 << PCE;
#if USART1_PARITY_TYPE == PARITY_ODD
	USART1 -> CR1 |= 1 << PS;
#endif
#endif
	USART1 -> CR1 |= USART1_DATA_LENGTH << M;
	USART1 -> CR2 |= USART1_STOP_LENGTH << STOP;
	USART1 -> CR1 |= 1 << UE;
}

//enable transmitter
void UART_enableTX(void) {
	USART1 -> CR1 |= 1 << TE;
}
//enable receiver
void UART_enableRX(void) {
	USART1 -> CR1 |= 1 << RE;
}
//transmit data
void UART_TXdata(u32 data){
//	 while(!get_bit(UCSRA,UCSRA_UDRE)) ;
//	 UDR = data ;
	while(!GET_BIT(USART1->SR,7));
	USART1->DR = data ;
	while (!GET_BIT(USART1->SR,6));
}
//receive data
u32 UART_RXdata (void) {
//	while(!get_bit(UCSRA ,UCSRA_RXC)) ;
//	*data = UDR ;
	u32 data = 0;
	//while (!GET_BIT(USART1 -> SR , 5));
	if (GET_BIT(USART1 -> SR, 5))
	{
			data = USART1 -> DR;
	}
	USART1 -> DR = 0;
	return data;
}

void UART1_voidSendString(u8 * const str)
{
	u16 buffer = 0;
	while (str[buffer] != '\0')
	{
		UART_TXdata(str[buffer]);
		buffer++;
	}
}
u8 * const UART1_StrReceiveString(void)
{
	u8 buffer = 0;
	u8 static data[30];
	while (data[buffer] != '\0')
	{
		data[buffer] = UART_RXdata();
		buffer++;
	}
	return data;
}
