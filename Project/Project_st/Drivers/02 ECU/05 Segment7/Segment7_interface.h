/*
 * Segment7_interface.h
 *
 *  Created on: May 4, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef SEGMENT7_INTERFACE_H_
#define SEGMENT7_INTERFACE_H_

#define ZERO 	0x3F
#define ONE		0x06
#define TWO 	0x5B
#define THREE 	0x4F
#define FOUR 	0x66
#define FIVE 	0x6D
#define SIX 	0x7D
#define SEVEN 	0x07
#define EIGHT 	0x7F
#define NINE 	0x6F

void Segment7_voidInit(u8 Port,u8 startpin);
void Segment7_voidSetValue(u8 port,u8 start,u8 data);
void Segment7_voidDisplayON(u8 Port,u8 startpin);
void Segment7_voidDisplayOFF(u8 Port,u8 startpin);

void Segment7_voidDualModeInit(u8 Port,u8 startpin);
void Segment7_voidDualModeSetValue(u8 port,u8 start,u8 data);

#endif /* SEGMENT7_INTERFACE_H_ */
