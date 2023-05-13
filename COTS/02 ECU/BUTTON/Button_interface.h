/*
 * button.h
 *
 * Created: 2/7/2023 12:55:02 PM
 *  Author: Mahmoud Osama
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_
#include "DIO_interface.h"

//button pin and port
#define BUTTON1_PORT PORT_D
#define BUTTON1_PIN 2

//BUTTON STATE
#define RELEASED 0
#define PRESSED	1


void BUTTON_init(u8 buttonPort,u8 buttonpin);
u8 BUTTON_read(u8 buttonPort,u8 buttonpin);





#endif /* BUTTON_INTERFACE_H_ */
