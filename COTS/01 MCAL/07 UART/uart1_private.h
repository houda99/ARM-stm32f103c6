#ifndef UART_PRIVATE_
#define UART_PRIVATE_
#define		UART1_BASE_ADD  0X40013800
typedef struct  {
    u32 SR;             /**< Status register */
    u32 DR;             /**< Data register */
    u32 BRR;            /**< Baud rate register */
    u32 CR1;            /**< Control register 1 */
    u32 CR2;            /**< Control register 2 */
    u32 CR3;            /**< Control register 3 */
    u32 GTPR;           /**< Guard time and prescaler register */
} usart_type;
#define UART1 ((volatile usart_type*)(UART1_BASE_ADD))

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


#define CLK8 0
#define CLK72 1

#define BAUD9600 0
#define BAUD115200 1

#define PARITY_NO             0
#define PARITY_YES            1

#define PARITY_EVEN           0
#define PARITY_ODD            1

#define DATA_LEN_8            1
#define DATA_LEN_9            0

#define STOP_BIT_1            0b00
#define STOP_BIT_2            0b10
#endif
