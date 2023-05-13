<<<<<<< HEAD


#ifndef LCD_H_
#define LCD_H_
//INCLUDING PART   
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/delay/DELAY.h"
#include "../../MCAL/GIE/GIE.h"
// function prototype
// initialize function 
void LCD_8init( ) ;
//write data 
void LCD_8writechar(uint8_t data) ;
//write command 
void LCD_8writecmd(uint8_t cmd)  ;
//function to write string on LCD 
void LCD_8writestring(uint8_t *str);
//select the position you need to display on lcd
void LCD_8goto(uint8_t row, uint8_t col);
//function to writer number on LCD 
void LCD_8writernumber(uint16_t number) ;
//function to customize  char  

void LCD_8customchar(uint8_t x , uint8_t y ); 

#define  RS					 PIN_0
#define  RW					 PIN_1
#define  EN                  PIN_2
#define  CONTROL_PORT        PORTA
#define  DATA_PORT           PORTB





=======


#ifndef LCD_H_
#define LCD_H_
//INCLUDING PART   
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/delay/DELAY.h"
#include "../../MCAL/GIE/GIE.h"
// function prototype
// initialize function 
void LCD_8init( ) ;
//write data 
void LCD_8writechar(uint8_t data) ;
//write command 
void LCD_8writecmd(uint8_t cmd)  ;
//function to write string on LCD 
void LCD_8writestring(uint8_t *str);
//select the position you need to display on lcd
void LCD_8goto(uint8_t row, uint8_t col);
//function to writer number on LCD 
void LCD_8writernumber(uint16_t number) ;
//function to customize  char  

void LCD_8customchar(uint8_t x , uint8_t y ); 

#define  RS					 PIN_0
#define  RW					 PIN_1
#define  EN                  PIN_2
#define  CONTROL_PORT        PORTA
#define  DATA_PORT           PORTB





>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
#endif /* LCD_H_ */