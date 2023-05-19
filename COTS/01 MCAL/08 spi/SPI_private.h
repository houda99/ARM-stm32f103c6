#ifndef SPI_PRIVATE_
#define SPI_PRIVATE_
#define		SPI1_BASE_ADD  0x40013000
typedef struct  {
    u32 CR1;
    u32 CR2;
    u32 SR;
    u32 DR;
    u32 CRCPR;
    u32 RXCRCR;
    u32 TXCRCR;
    u32 I2SCFGR;
    u32 I2SPR;
} SPI_type;
#define SPI1 ((volatile SPI_type*)(SPI1_BASE_ADD))

#define FCLK2 0
#define FCLK4 1
#define FCLK8 2
#define FCLK16 3
#define FCLK32 4
#define FCLK64 5
#define FCLK128 6
#define FCLK256 7

#define MASTER 0
#define SLAVE 1


#endif
