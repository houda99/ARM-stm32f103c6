/*
 * LED.h
 *
 * Created: 2/7/2023 12:18:47 PM
 *  Author: Mahmoud Osama
 */ 
#include "DIO_interface.h"
#include    "Common_Function.h"
#ifndef LED_H_
#define LED_H_
#define LED1_PIN	4
#define LED1_Port PORT_A

void LED_init(u8 ledPort,u8 ledPin);
void LED_on(u8 ledPort,u8 ledPin);
void LED_off(u8 ledPort,u8 ledPin);
void LED_toggle(u8 ledPort,u8 ledPin);

#endif /* LED_H_ */
