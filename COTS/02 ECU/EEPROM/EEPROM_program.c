#include "EEPROM_interface.h"
#include "I2C.h"
#include "EEPROM_private.h"

void EEPROM_Write(u16 location_Address,u8 Copy_Data){
	u8 location_adress_packet= EEPROM_FIXED_ADDRESS | (A2_Connection<<2) |(u8)(Copy_Data>>8);
	//send start

	I2C_Start();
	//send address Packet
	I2C_Address(location_adress_packet);
	//send rest of  8bit location
	I2C_Write((u8)location_Address);
	//send data
	I2C_Write(Copy_Data);
	//stop condition
	I2C_Stop();
	_delay_ms(10);
}

u8 EEPROM_Read(u16 location_Address){
	u8 data;
	u8 location_adress_packet= EEPROM_FIXED_ADDRESS | (A2_Connection<<2) |(u8)(location_Address>>8);
	//send start
	I2C_Start();
	//send address Packet
	I2C_Address(location_adress_packet);
	//send rest of  8bit location
	I2C_Write((u8)location_adress_packet);
	//send data
	I2C_Read(location_adress_packet,&data,1);
	//stop condition
	I2C_Stop();
	return data;
}
