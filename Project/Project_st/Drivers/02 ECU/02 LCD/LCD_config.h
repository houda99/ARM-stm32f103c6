#ifndef		LCD_config_H
#define		LCD_config_H

//connection mode
enum{
	four_bitmode,
	Eight_bitmode
	};
	
#define control_port	PORTA
#define Data_port		PORTB

#define  RW		PIN7
#define  EN		PIN8
#define  RS		PIN11





#define connection_mode  four_bitmode
#endif
