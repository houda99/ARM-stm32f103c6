/*
 * i2c_main.c
 *
 *  Created on: May 18, 2023
 *      Author: ommmm
 */
#include "Common_Function.h"
#include "I2C.h"
#include "RCC_interface.h"
#include "LED_interface.h"
#include "EEPROM_interface.h"
int main(){
	u8 read_data=0;
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 0);
	LED_init(PORTB, 0);
	I2C_Config();
	I2C_Start();
	I2C_Address(0b10100100);
	_delay_ms(100);
	I2C_Write(0X00);
	_delay_ms(100);
	I2C_Write(0x09);
	I2C_Stop();
	_delay_ms(1000);
	I2C_Start();
	I2C_Address(0b10100101);
	_delay_ms(1000);
	I2C_Read(0b10100101, &read_data, 1);

	while(1){
//		EEPROM_Write(100, 0x09);
//		LED_on(PORTB, 0);
//		_delay_ms(1000);
//		LED_off(PORTB, 0);
//		if(EEPROM_Read(100)==0x09){
//			LED_on(PORTB, 0);
//		}

	}
	return 0;
}
