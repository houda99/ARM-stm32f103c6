/*
 * SPI_private.h
 *
 *  Created on: May 17, 2023
 *      Author: Mohamed Dwedar
 */

#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

typedef struct {
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
}SPI_type;


#define SPI1 ((volatile SPI_type *)(0x40013000))

// CR1
#define CR1_CPHA              0
#define CR1_CPOL              1
#define CR1_MSTR              2
#define CR1_BR                3
#define CR1_SPE               6
#define CR1_LSBFIRST          7
#define CR1_SSI               8
#define CR1_SSM               9
#define CR1_RXONLY            10
#define CR1_DFF               11
#define CR1_CRCNEXT           12
#define CR1_CRCEN             13
#define CR1_BIDIOE            14
#define CR1_BIDIMODE          15

//CR2
#define CR2_RXDMAEN           0
#define CR2_TXDMAEN           1
#define CR2_SSOE              2
#define CR2_ERRIE             5
#define CR2_RXNEIE            6
#define CR2_TXEIE             7

//SR
#define SR_RXNE               0
#define SR_TXE                1
#define SR_CHSIDE             2
#define SR_UDR                3
#define SR_CRCERR             4
#define SR_MODF               5
#define SR_OVR                6
#define SR_BSY                7


// I2SFGR
#define I2SFGR_CHLEN          0
#define I2SFGR_DATLEN         1
#define I2SFGR_CKPOL          3
#define I2SFGR_I2SSTD         4
#define I2SFGR_PCMSYNC        7
#define I2SFGR_I2SCFG         8
#define I2SFGR_I2SE           10
#define I2SFGR_I2SMOD         11



// I2SPR
#define I2SPR_I2SDIV          0
#define I2SPR_ODD             8
#define I2SPR_MCKOE           9

// MS
#define MASTER                0
#define SLAVE                 1

// BaudRate
#define Fplck_2               0
#define Fplck_4               1
#define Fplck_8               2
#define Fplck_16              3
#define Fplck_32              4
#define Fplck_64              5
#define Fplck_128             6
#define Fplck_256             7

// Clock Phase & polarity
#define IDLE_HIGH             0
#define IDLE_LOW              1
#define TRANSITION_FISRT      0
#define TRANSITION_SECOND     1


#define BIT_8                 0
#endif /* 01_MCAL_08_SPI_SPI_PRIVATE_H_ */
