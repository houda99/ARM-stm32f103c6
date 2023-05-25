#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include    "DIO_interface.h"

#include	"NVIC_interface.h"
#include    "EXTI_interface.h"
#include    "USART_interface.h"
#include    "SPI_interface.h"
#include    "I2C_Interface.h"
#include    "EEPROM_interface.h"

int main (void)
{
    RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 2);
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 4);
	RCC_voidEnablePerClk(RCC_APB2, 0);
	RCC_voidEnablePerClk(RCC_APB1, 21);
	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_HIGH);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_HIGH);

	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_LOW);


	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_LOW);

	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN7, GPIO_HIGH);

	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_HIGH);

	DIO_voidSetPinValue(PORTB, PIN7, GPIO_LOW);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_LOW);

	EEPROM_voidInit();
	EEPROM_voidWriteChar(1,'A');
	u8 x = 0;
	while (1)
	{
		x = EEPROM_voidReciveChar(1);
	}
	return 1;
}

//void	EXTI0_IRQHandler(void)
//{
//	//EXTI0_CallBack();
//	/*		Led On		*/
//			DIO_voidSetPinValue(PORTA,PIN1,GPIO_HIGH);
//			_delay_ms(1000);
//			/*		Led Off		*/
//			DIO_voidSetPinValue(PORTA,PIN1,GPIO_LOW);
//			_delay_ms(1000);
//	/*	Clear EXTI0 Flag	*/
//	//SET_BIT(EXTI -> PR,0);
//}







