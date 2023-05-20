#ifndef		EEPROM_interface_H
#define		EEPROM_interface_H
#include "I2C.h"


void EEPROM_Write(u16 location_Address,u8 Copy_Data);

u8 EEPROM_Read(u16 location_Address);

#endif
