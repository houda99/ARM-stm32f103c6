#ifndef SPI_H_
#define SPI_H_
#include "DIO_interface.h"

#define MOSI     PIN7
#define MISO     PIN6
#define SCK      PIN5
#define SS 	     PIN4

#define SPI_PORT PORTA
#define MODE  MASTER
#define DATAMODE FULLDUPLEX

void SPI_init(void);
void SPI_MasterInit(void);
void SPI_MasterTransmit(u8 cData);
u8 SPI_MasterReceive(void);
void SPI_SlaveInit(void);
u8 SPI_SlaveReceive(void);



#endif /* SPI_H_ */
