/*
 * SPI.c
 *
 * Created: 4/27/2023 3:47:48 PM
 *  Author: Mahmoud Osama
 */
#include "SPI_interface.h"
#include "SPI_private.h"
#include "spi_config.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "Common_Function.h"
void SPI_init(void){

	//RCC_voidSysClkInt()
	//RCC_voidDisablePerClk(RCC_APB2, 12);
	// RISING EDGE
	SET_BIT(SPI1->CR1,1);//CPOL=1
	SET_BIT(SPI1->CR1,0);//CPHA=1
	/*set clock*/
#if SPICLOCK==FCLK2
	CLR_BIT(SPI1->CR1,3;
	CLR_BIT(SPI1->CR1,4);
	CLR_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK4
		SET_BIT(SPI1->CR1,3);
		CLR_BIT(SPI1->CR1,4);
		CLR_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK8
		CLR_BIT(SPI1->CR1,3);
		SET_BIT(SPI1->CR1,4);
		CLR_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK16
		SET_BIT(SPI1->CR1,3);
		SET_BIT(SPI1->CR1,4);
		CLR_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK32
		CLR_BIT(SPI1->CR1,3);
		CLR_BIT(SPI1->CR1,4);
		SET_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK64
		SET_BIT(SPI1->CR1,3);
		CLR_BIT(SPI1->CR1,4);
		SET_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK128
		CLR_BIT(SPI1->CR1,3);
		SET_BIT(SPI1->CR1,4);
		SET_BIT(SPI1->CR1,5);
#elif SPICLOCK==FCLK256
		SET_BIT(SPI1->CR1,3);
		SET_BIT(SPI1->CR1,4);
		SET_BIT(SPI1->CR1,5);
#endif
//software slave
SET_BIT(SPI1->CR1,9);
SET_BIT(SPI1->CR1,8);



#if DATAMODE == FULLDUPLEX
	CLR_BIT(SPI1->CR1,15);
	CLR_BIT(SPI1->CR1,10);
#endif
#if MODE == MASTER
	SET_BIT(SPI1->CR1,2);
#else
	CLR_BIT(SPI1->CR1,2);
#endif
	// SPI ENABLE
	SET_BIT(SPI1->CR1,6);
	//DISABLE ALL INTERRUPT
	SPI1->CR2=0;
}

void SPI_MasterTransmit(u8 cData)
{
	//DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW); //SET SS PIN TO LOW
	SPI1->DR = cData;
}
u8 SPI_MasterReceive(void)
{
	u8 rx_data=0;
	while(GET_BIT(SPI1->SR,7)){asm("NOP");}
	rx_data = SPI1->DR;
	//DIO_voidSetPinValue(PORTA, PIN4, GPIO_HIGH);
	return rx_data;
}
void SPI_SlaveInit(void)
{

}
u8 SPI_SlaveReceive(void)
{
return 0;
}
