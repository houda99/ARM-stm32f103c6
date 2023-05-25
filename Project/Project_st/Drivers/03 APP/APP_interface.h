
#ifndef _App_INTERFACE_H_
#define _App_INTERFACE_H_
//LIB
#include	"Std_Types.h"
#include	"Bit_Math.h"

//MCALS
#include  "RCC_interface.h"
#include  "DIO_interface.h"
#include  "EXTI_interface.h"
#include  "NVIC_interface.h"
#include  "ADC_interface.h"
#include  "STK_interface.h"
#include  "LED_interfce.h"
#include "button_Interface.h"
#include "Buzzer_interfce.h"
#include "BLUETOOTH_interface.h"
#include "Segment7_interface.h"
#include "SPI_interface.h"

void Heater_systemint(void);

#endif /* _App_INTERFACE_H_ */
