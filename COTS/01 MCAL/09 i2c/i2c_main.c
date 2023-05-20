/*
 * i2c_main.c
 *
 *  Created on: May 18, 2023
 *      Author: ommmm
 */
#include "Common_Function.h"
#include "I2C.h"
int main(){
	I2C_Config();
	while(1){
		I2C_Start();
		I2C_Address(0b10000000);
		I2C_Write(9);
		I2C_Stop();
		_delay_ms(1000);
	}
	return 0;
}
