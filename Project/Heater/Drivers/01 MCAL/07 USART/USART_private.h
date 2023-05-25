/*
 * USART_private.h
 *
 *  Created on: May 14, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}USART_type;


#define USART1       ((volatile USART_type *)(0x40013800))

#define BAUD_RATE_9600        0x341
#define BAUD_RATE_115200      0x45

#define PARITY_NO             0
#define PARITY_YES            1

#define PARITY_EVEN           0
#define PARITY_ODD            1

#define DATA_LEN_8            1
#define DATA_LEN_9            0

#define STOP_BIT_1            0b00
#define STOP_BIT_2            0b10



//SR REGISTER
#define PE      0
#define FE      1
#define NE      2
#define ORE     3
#define IDLE    4
#define RXNE    5
#define TC      6
#define TXE     7
#define LBD     8
#define CTS     9


//CR1
#define SBK          0
#define RWU          1
#define RE           2
#define TE           3
#define IDLEIE       4
#define RXNEIE       5
#define TCIE         6
#define TCEIE        7
#define PEIE         8
#define PS           9
#define PCE          10
#define WAKe         11
#define M            12
#define UE           13

//CR2
#define ADD          0
#define LBDL         5
#define LBDIE        6
#define LBCL         8
#define CPHA         9
#define CPOL         10
#define CLKEN        11
#define STOP         12
#define LINEN        14

//CR3
#define EIE          0
#define IREN         1
#define IRLP         2
#define HDSEL        3
#define NACK         4
#define SCEN         5
#define DMAR         6
#define DMAT         7
#define RTSE         8
#define CTSE         9
#define CTSIE        10


//GTPR
#define PSC         0
#define GT          8


#endif /* 01_MCAL_USART_USART_PRIVATE_H_ */
