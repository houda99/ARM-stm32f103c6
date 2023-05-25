/*
 * SPI_interface.h
 *
 *  Created on: May 18, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#include "SPI_config.h"
#include "SPI_private.h"


void SPI1_voidInit(void);
void SPI_voidSend(u8 data);
u8   SPI_voidRecieve(void);
#endif /* 01_MCAL_08_SPI_SPI_INTERFACE_H_ */
