
#include "Common_Function.h"

void I2C_Config (void);

void I2C_Start (void);

void I2C_Write (u8 data);

void I2C_Address (u8 Address);

void I2C_Stop (void);

void I2C_WriteMulti (u8 *data, u8 size);

void I2C_Read (u8 Address, u8 *buffer, u8 size);
