<<<<<<< HEAD


#ifndef KEYPAD__INTERFACE_H_
#define KEYPAD__INTERFACE_H_
//include part
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include    "DIO_interface.h"
//initialize function
void KEYPAD_init(void );
//read function
u8 KEYPAD_getpresskey();

#define KEY_PORT     PORTA


#endif /* KEYPAD__INTERFACE_H_ */
=======


#ifndef KEYPAD__INTERFACE_H_
#define KEYPAD__INTERFACE_H_
//include part
#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include    "DIO_interface.h"
//initialize function
void KEYPAD_init(void );
//read function
u8 KEYPAD_getpresskey();

#define KEY_PORT     PORTA


#endif /* KEYPAD__INTERFACE_H_ */
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
