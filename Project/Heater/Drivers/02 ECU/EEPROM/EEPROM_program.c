/*
 * EEPROM_program.c
 *
 *  Created on: May 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */
#include "Std_Types.h"
#include "Bit_Math.h"

#include "I2C_Interface.h"
#include "EEPROM_interface.h"
#include "STK_interface.h"

void EEPROM_voidInit(void)
{
	I2C1_voidMasterInit();
}
void EEPROM_voidWriteChar(u8 location,u8 data)
{
	STK_voidSetBusyWait(5000);
	I2C1_voidStart();
	STK_voidSetBusyWait(5000);
	I2C1_voidSendAddress(0b10100100);
	STK_voidSetBusyWait(5000);
	I2C1_voidSendData(location);
	STK_voidSetBusyWait(5000);
	I2C1_voidSendData(data);
	STK_voidSetBusyWait(5000);
	I2C1_voidStop();
	STK_voidSetBusyWait(5000);
}
u8 EEPROM_voidReciveChar(u8 location)
{
	//read from eeprom
	u8 readI2C = 0;
	I2C1_voidStart();
	STK_voidSetBusyWait(5000);
	I2C1_voidSendAddress(0b10100100);
	STK_voidSetBusyWait(5000);
	I2C1_voidSendData(location);
	STK_voidSetBusyWait(5000);
	I2C1_voidStart();
	STK_voidSetBusyWait(5000);
	I2C1_voidSendAddress(0b10100100+1);
	readI2C = I2C1_voidRecieveData();
	I2C1_voidStop();
	STK_voidSetBusyWait(5000);
	return readI2C;
}
