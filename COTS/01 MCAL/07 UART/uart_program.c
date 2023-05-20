#include "Common_Function.h"
#include "uart1_config.h""
#include "uart1_interface.h""
#include "uart1_private.h"

void UART_init(void) {
	// set Baud rate
	UART1 -> BRR =BAUDRATE;
	// Enable RXNEIE
	//UART1 -> CR1 = 1 << RXNEIE;
	// enable transmission complete interrupt
	//UART1 -> CR1 = 1 << TCIE;
	// UART1 -> CR1 = 1 << TXEIE;
#if UART1_PARITY == PARITY_NO
	SET_BIT(UART1 -> CR1,PCE);
#elif UART1_PARITY_TYPE == PARITY_ODD
	SET_BIT(UART1 -> CR1,PS);
#endif
	UART1 -> CR1 |= UART1_DATA_LENGTH << M;
	UART1 -> CR2 |= UART1_STOP_LENGTH << STOP;
	UART1 -> CR1 |= 1 << UE;
}

//enable transmitter
void UART_enableTX(void) {
	SET_BIT(UART1->CR1,TE);
}
//enable receiver
void UART_enableRX(void) {
	SET_BIT(UART1->CR1,RE);
}
//transmit data
void UART_TXdata(u32 data){
//	 while(!get_bit(UCSRA,UCSRA_UDRE)) ;
//	 UDR = data ;
	while(!GET_BIT(UART1->SR,7));
	UART1->DR = data ;
	while (!GET_BIT(UART1->SR,6));
}
//receive data
u32 UART_RXdata (void) {
//	while(!get_bit(UCSRA ,UCSRA_RXC)) ;
//	*data = UDR ;
	u32 data = 0;
	while (!GET_BIT(UART1 -> SR , 5));
	data = UART1 -> DR; ;
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
	u16 buffer = 0;
	u16 data[30];
	while (data[buffer] != '\0')
	{
		data[buffer] = UART_RXdata();
		buffer++;
	}
	return data;
}
