#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "STK_interface.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"
#include    "EXTI_interface.h"
#include    "USART_interface.h"

#include    "SPI_interface.h"

int main (void)
{
    RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 2);
	RCC_voidEnablePerClk(RCC_APB2, 4);
	RCC_voidEnablePerClk(RCC_APB2, 0);
	RCC_voidEnablePerClk(RCC_APB2, 12);
	DIO_voidSetPinDirection(PORTA,PIN6,GPIO_OUTPUT_2MHZ_AFPP);//MOSI
	DIO_voidSetPinDirection(PORTA,PIN7,GPIO_INPUT_FLOAT); // MISO
	DIO_voidSetPinDirection(PORTA,PIN5,GPIO_INPUT_FLOAT); //clk
	DIO_voidSetPinDirection(PORTA,PIN4,GPIO_INPUT_FLOAT); // ss
	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_10MHZ_PP);
	SPI1_voidInit();
	while (1)
	{
		u8 recive = 0;
		recive = SPI_voidRecieve();
		if ('s' == recive)
		{
			DIO_voidSetPinValue(PORTC, PIN0, GPIO_HIGH);
		}
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







