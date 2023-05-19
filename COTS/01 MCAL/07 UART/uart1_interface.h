#ifndef UART_interface_
#define UART_interface_

void UART_init();
void UART_enableTX(void);
void UART_enableRX(void);
void UART_TXdata(u8 data);
void UART_RXdata (u8 *data );
void UART1_voidSendString(u8 * const str);
u8 * const UART1_StrReceiveString();

#endif
