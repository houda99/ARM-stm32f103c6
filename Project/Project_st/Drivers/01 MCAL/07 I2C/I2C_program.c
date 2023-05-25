/*
 * I2C_program.c
 *
 *  Created on: May 17, 2023
 *      Author: Mohamed Dwedar
 */

#include "Std_Types.h"
#include "Bit_Math.h"

#include "../07 I2C/I2C_config.h"
#include "../07 I2C/I2C_Interface.h"
#include "../07 I2C/I2C_private.h"
void static Reset(void);
void static Reset(void)
{
	I2C1 -> CR1  |= (1 << CR1_SWRST);
	CLR_BIT(I2C1 -> CR1, CR1_SWRST);
}

void I2C1_voidMasterInit(void)
{
	// Reset I2C
	Reset();
	// Enable Ack

	// Select Frequency
	I2C1 -> CR2   |= (8  << CR2_FREQ);
	I2C1 -> CCR   |= (40 << CCR_CCR);
	I2C1 -> TRISE |= 9;
	// Enable I2C
	I2C1 -> CR1   |= (1 << CR1_PE);
}

void I2C1_voidStart(void)
{
	I2C1 -> CR1   |= (1 << CR1_ACK);
	I2C1 -> CR1 |= (1 << CR1_START);
	while(!GET_BIT(I2C1 -> SR1,SR1_SB));
	//CLR_BIT(I2C1 -> SR1 , SR1_SB);
}

void I2C1_voidSendAddress(u8 address_copy)
{
	I2C1 -> DR  = address_copy;
	while(!GET_BIT(I2C1 -> SR1,SR1_ADDR));
}

void I2C1_voidSendData(u8 data_copy)
{
	while(!GET_BIT(I2C1 -> SR1 ,SR1_TXE));
	I2C1 -> DR  = data_copy;
	while(!GET_BIT(I2C1 -> SR1,SR1_BTF));
}

u8   I2C1_voidRecieveData(void)
{
	while(!(GET_BIT(I2C1 -> SR1,SR1_RXEN)));
	return I2C1 -> DR;
}

void I2C1_voidStop(void)
{
	I2C1 -> CR1 |= 1 << CR1_STOP;
	//CLR_BIT(I2C1 -> CR1, CR1_STOP);
}
