
//LIB
#include	"Std_Types.h"
#include	"Bit_Math.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

#include "LCD_interface.h"



int main(void)
{
	// RCC_Enable
	RCC_voidSysClkInt();
	// RCC_Enable PORTA
	RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_DIOA);
	// RCC_Enable PORTB
	RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_DIOB);
	// RCC_Enable SPI
	RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_SPI1);
	// RCC_Enable AFIO
	RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_AFIO);

	LCD_4_bit_intalize();
	LCD_4_bit_sendstring("Welome");
	LCD_4_bit_sendcommand(clear_display);
	STK_voidSetBusyWait(1000);
	SPI1_voidInit();
	u8 old_read  = 0;
	while (1)
	{
		u8 x = 0 ;
		x = SPI_voidRecieve();
		if (old_read != x)
		{
		switch (x)
		{
		case '1':/*Warning High Temperature*/
			LCD_4_bit_sendcommand(clear_display);
			LCD_4_bit_sendstring("Temp Level 1");
			break;
		case '2':/*Warning High Temperature*/
			LCD_4_bit_sendcommand(clear_display);
			LCD_4_bit_sendstring("Temp Level 2");
			break;
		case '3':/*Warning High Temperature*/
			LCD_4_bit_sendcommand(clear_display);
			LCD_4_bit_sendstring("Temp Level 3");
			break;
		case '4':/*Warning High Temperature*/
			LCD_4_bit_sendcommand(clear_display);
			LCD_4_bit_sendstring("Temp Level 4");
			break;
		case '5':/*Warning High Temperature*/
			LCD_4_bit_sendcommand(clear_display);
			LCD_4_bit_sendstring("Warning OverHeat!");
			break;
		}
		}
		old_read = x;
	}
}







