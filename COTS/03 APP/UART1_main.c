/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/
void UART_init() {
	/*
		
	*/
}
  
//enable transmitter
void UART_enableTX(void) {
	
}
//enable receiver
void UART_enableRX(void) {

}
//transmit data
void UART_TXdata(uint8_t data){
//	 while(!get_bit(UCSRA,UCSRA_UDRE)) ;
//	 UDR = data ;
}
//receive data
void UART_RXdata (uint8_t *data ) {
//	while(!get_bit(UCSRA ,UCSRA_RXC)) ;
//	*data = UDR ;
	
}

void UART1_voidSendString(u8 * const str)
{
	
}
u8 * const UART1_StrReceiveString()
{
	return;
}



/*
1- to connect Rx with Tx pin

Sendchar ('a');
u8 Rx = reciveChar();
if(Rx == 'a')
{
	Led on
	Delay();
}
else
{
	Led Off
	Delay();
}
*/