/*
 * I2C_Interface.h
 *
 *  Created on: May 17, 2023
 *      Author: Mohamed Dwedar
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_










void I2C1_voidMasterInit(void);
void I2C1_voidStart(void);
void I2C1_voidSendAddress(u8 address_copy);
void I2C1_voidSendData(u8 data_copy);
u8   I2C1_voidRecieveData(void);
void I2C1_voidStop(void);


#endif /* 01_MCAL_09_I2C_I2C_INTERFACE_H_ */
