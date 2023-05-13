
//including part
#include "LED_interface.h"


 //initialize function

 void LED_init(u8 ledport  , u8 ledpin) {
	 DIO_voidSetPinDirection(ledport , ledpin, GPIO_OUTPUT_2MHZ_PP) ;
 }

 //function to on led

 void LED_on (u8 ledport  , u8 ledpin ) {
	 DIO_voidSetPinValue(ledport ,ledpin , GPIO_HIGH) ;

 }

 //function to led off

void LED_off (u8 ledport , u8 ledpin ) {
	DIO_voidSetPinValue(ledport , ledpin ,GPIO_LOW) ;
}

 //toggle led function

// void LED_toggLE (u8 ledport , u8 ledpin ){
//	 DIO_togglepin(ledport ,ledpin ) ;
// }
