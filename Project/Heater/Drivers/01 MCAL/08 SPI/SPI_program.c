/*
 * SPI_program.c
 *
 *  Created on: May 18, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#include "Std_Types.h"
#include "Bit_Math.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void SPI1_voidInit(void)
{
//	SPI1 -> CR1 |= 0b1000000;
	// Select Clock Phase (default first clock transmit)
	// Select Clock Polarity (default 1 in idle)
#if CLOCK_POARITY == TRANSITION_SECOND
	SPI1 -> CR1 |= (1 << CR1_CPOL);
#endif
#if CLOCK_PHASE == IDLE_HIGH
	SPI1 -> CR1 |= (1 << CR1_CPHA);
#endif
	// Master Slave Select
#if M_S == MASTER
	SPI1 -> CR1 |= (1 << CR1_MSTR);
	// Baud Rate Select
	SPI1 -> CR1 |= (BAUD_RATE << CR1_BR);
	// 8Bit data
	SPI1 -> CR1 |= (DATA_LEN << CR1_DFF);
	// Enable Slave Select
	SET_BIT(SPI1->CR1,9);
	SET_BIT(SPI1->CR1,8);
#endif
	// Enable SPI
	SPI1 -> CR1 |= (1 << CR1_SPE);
	asm("NOP");
}
void SPI_voidSend(u8 data)
{
	while(!GET_BIT(SPI1 -> SR,SR_TXE))
	{
		asm("NOP");
	}
	SPI1 -> DR = data;
}
u8   SPI_voidRecieve(void)
{
	u8 data = 0;
	while (GET_BIT(SPI1 -> SR,SR_BSY))
	{
		asm("NOP");
	}
	data = SPI1 -> DR;
	return data;
}
