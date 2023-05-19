#include "Common_Function.h"
#include "DIO_interface.h"
#include "RCC_interface.h"
//#include "adc_interface.h"
#include "DMA_interface.h"
#include "LED_interface.h"
#include "SPI_interface.h"
//#include "LCD4BIT.h"



int main(){
		RCC_voidSysClkInt();
		RCC_voidEnablePerClk(RCC_APB2,2);//port A
		RCC_voidEnablePerClk(RCC_APB2,3);//port 3
		RCC_voidEnablePerClk(RCC_APB2,12);//SPI
		RCC_voidEnablePerClk(RCC_APB2,0);//AF
		LED_init(PORTB,PIN5); //LED0
		SPI_init();
		DIO_voidSetPinDirection(PORTA,PIN7,GPIO_OUTPUT_2MHZ_AFPP); // MOSI
		DIO_voidSetPinDirection(PORTA,PIN6,GPIO_INPUT_FLOAT); //MISO
		DIO_voidSetPinDirection(PORTA,PIN5,GPIO_OUTPUT_2MHZ_AFPP); //clk
		DIO_voidSetPinDirection(PORTA,PIN4,GPIO_OUTPUT_2MHZ_AFPP); // ss

		while(1){
			SPI_MasterTransmit('A');
			u8 Rx =0;
			Rx=SPI_MasterReceive();
			if(Rx!='A'){
				LED_off(PORTB, PIN5);
				_delay_ms(10000);
			}else{
				LED_on(PORTB , PIN5);
				_delay_ms(10000);
			}
		}

		return 0;

}
