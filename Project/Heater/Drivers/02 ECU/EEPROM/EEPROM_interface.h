/*
 * EEPROM_interface.h
 *
 *  Created on: May 25, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWriteChar(u8 location,u8 data);
u8 EEPROM_voidReciveChar(u8 location);
#endif /* 02_ECU_EEPROM_INTERFACE_H_ */
