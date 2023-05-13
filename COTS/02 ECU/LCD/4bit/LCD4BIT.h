<<<<<<< HEAD
/*
 * LCD4BIT.h
 *
 * Created: 3/13/2023 1:55:17 AM
 *  Author: ahmed
 */ 


#ifndef LCD4BIT_H_
#define LCD4BIT_H_
//INCLUDING PART
//#include	"Std_Types.h"
//#include	"Bit_Math.h"
#include	"Common_Function.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
// function prototype
// initialize function
void LCD_init(void ) ;
//write data
void LCD_writechar(u8 data) ;
//write command
void LCD_writecmd(u8 cmd)  ;
//function to write string on LCD
void LCD_writestring(u8 *str);
//select the position you need to display on lcd
void LCD_goto(u8 row, u8 col);
//function to writer number on LCD
void LCD_writernumber(u16 number) ;
//function to customize  char

void LCD_customchar(u8 x , u8 y );

#define  RS					 PIN13
#define  RW					 PIN14
#define  EN                  PIN15
#define  CONTROL_PORT        PORTC
#define  DATA_PORT           PORTB





#endif /* LCD4BIT_H_ */
=======
/*
 * LCD4BIT.h
 *
 * Created: 3/13/2023 1:55:17 AM
 *  Author: ahmed
 */ 


#ifndef LCD4BIT_H_
#define LCD4BIT_H_
//INCLUDING PART
//#include	"Std_Types.h"
//#include	"Bit_Math.h"
#include	"Common_Function.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
// function prototype
// initialize function
void LCD_init(void ) ;
//write data
void LCD_writechar(u8 data) ;
//write command
void LCD_writecmd(u8 cmd)  ;
//function to write string on LCD
void LCD_writestring(u8 *str);
//select the position you need to display on lcd
void LCD_goto(u8 row, u8 col);
//function to writer number on LCD
void LCD_writernumber(u16 number) ;
//function to customize  char

void LCD_customchar(u8 x , u8 y );

#define  RS					 PIN13
#define  RW					 PIN14
#define  EN                  PIN15
#define  CONTROL_PORT        PORTC
#define  DATA_PORT           PORTB





#endif /* LCD4BIT_H_ */
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
