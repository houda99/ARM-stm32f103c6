/*
 * USART_interface.h
 *
 *  Created on: May 14, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

 void UART_init(void);
 void UART_enableTX(void);
 void UART_enableRX(void);
 void UART_TXdata(u32 data);
 u32 UART_RXdata (void);
 void UART1_voidSendString(u8 * const str);
 u8 * const UART1_StrReceiveString(void);
#endif
