
#include "DIO_interface.h"
#include"RCC_interface.h"
#include "LED_interface.h"
//#include "LCD4BIT.h"

#include "Common_Function.h"


int main(){
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 4);
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 2);

	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinValue(PORTA, PIN0, GPIO_LOW);
	DIO_voidSetPinValue(PORTA, PIN1, GPIO_LOW);
	DIO_voidSetPinValue(PORTA, PIN2, GPIO_LOW);
	//LCD_init();

	LED_init(PORTB, 0);
	LED_init(PORTB, 1);
	LED_init(PORTB, 3);
	//LED_init(PORTC, 13);
	while(1){
		if(DIO_u8GetPinValue(PORTA, PIN0)==1){
			LED_on(PORTB, 0);
			_delay_ms(500);
			//LCD_writestring('WATER LEVEL 1');
		}
		if(DIO_u8GetPinValue(PORTA, PIN0)==1 && DIO_u8GetPinValue(PORTA, PIN1)==1){
			LED_on(PORTB, 0);
			LED_on(PORTB, 1);
			_delay_ms(500);
			//LCD_writestring('WATER LEVEL 2');

		}if(DIO_u8GetPinValue(PORTA, PIN0)==1 && DIO_u8GetPinValue(PORTA, PIN1)==1&&DIO_u8GetPinValue(PORTA, PIN2)==1){
			LED_on(PORTB, 0);
			LED_on(PORTB, 1);
			LED_on(PORTB, 3);
			_delay_ms(500);}
			//LCD_writestring('WATER LEVEL 3');
//		}else{
//			LED_off(PORTC, 13);
//			//LCD_writestring('ERROR');
//		}
	}
	return 0;
}
