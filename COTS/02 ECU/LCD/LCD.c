//include part 
#include "LCD.h"
// initialize function
void LCD_8init( ){
	delay_10_ms() ;
	delay_10_ms() ;
	delay_10_ms() ;
	delay_1_ms()  ;
	LCD_8writecmd(0x38) ;
	delay_1_ms() ;
	LCD_8writecmd(0x0C) ;
	delay_1_ms() ;
	LCD_8writecmd(0x01) ;
	delay_1_ms() ;
	delay_1_ms();
	LCD_8writecmd(0x06) ;
}
//write data
void LCD_8writechar(uint8_t data) {
	//INTITIALIZE PORT DATA & CONTROL
	DIO_initpin(CONTROL_PORT ,RS , OUT) ;
	DIO_initpin(CONTROL_PORT ,RW , OUT) ;
	DIO_initpin(CONTROL_PORT ,EN , OUT) ;
	DIO_initport(DATA_PORT , OUT      ) ;
	//WRITE ON PORTS
	DIO_writepin(CONTROL_PORT,RS , HIGH) ;
	
	DIO_writepin(CONTROL_PORT,RW , LOW) ;
	DIO_writeport(DATA_PORT,data     ) ;
	DIO_writepin(CONTROL_PORT,EN , HIGH);
	delay_1_ms() ;
	delay_1_ms() ;
	DIO_writepin(CONTROL_PORT,EN ,LOW) ;
	delay_1_ms() ;
	delay_1_ms() ;
	
}
//function to write string on LCD
void LCD_8writestring(uint8_t *str){
	while(*str != NULL)
	{
		LCD_8writechar(*str) ;
		str++ ;
	}
	
	
}
//function to writer number on LCD
void LCD_8writernumber(uint16_t number) {
	 volatile uint16_t sum=0   ;  volatile uint8_t num = 0 ;
	while(number != NULL){
		sum = (number%10) + sum*10  ;
		number=number/10    ;
	}
	while(sum!=NULL){
		num = sum%10;
		LCD_8writechar(0x30+num) ;
		sum = sum/10  ;
	}
}

//select the position you need to display on lcd
void LCD_8goto(uint8_t row, uint8_t col){
	if (row<2 &&col<16)
	{ 
		switch(row){
			case 0 : LCD_8writecmd(0X80+col) ; 
			break;
			case 1: LCD_8writecmd(0XC0+col)  ;
			break;
		}
	}else {
		
	}
}
//write command
void LCD_8writecmd(uint8_t cmd) {
	//INTITIALIZE PORT DATA & CONTROL 
	DIO_initpin(CONTROL_PORT ,RS , OUT) ;
	DIO_initpin(CONTROL_PORT ,RW , OUT) ;
	DIO_initpin(CONTROL_PORT ,EN , OUT) ;
	DIO_initport(DATA_PORT , OUT      ) ;
	//WRITE ON PORTS 
	DIO_writepin(CONTROL_PORT,RS , LOW) ;
	DIO_writepin(CONTROL_PORT,RW , LOW) ;
	
	DIO_writeport(DATA_PORT,cmd      ) ;
	DIO_writepin(CONTROL_PORT,EN , HIGH);
	delay_1_ms() ;
	delay_1_ms() ;
	DIO_writepin(CONTROL_PORT,EN ,LOW) ;
	delay_1_ms() ;
	delay_1_ms() ;
	
}

//function to customize  char

/*void LCD_8customchar(uint8_t x , uint8_t y ){
	uint8_t i    ;
	uint8_t j   ;
	LCD_8writecmd(0x40) ; 
	for (i=0 ; i<64 ; i++)
	{
		LCD_8writechar(make[i]) ;
	}
	//LCD_writecmd(0X80) ;
	LCD_8goto(x,y) ;
	for (j=0 ; j<8 ; j ++)
	{
		LCD_8writechar(j) ;
	}
}*/