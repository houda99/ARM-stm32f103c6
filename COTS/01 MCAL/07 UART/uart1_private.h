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

#define CLK8 0
#define CLK72 1

#define BAUD9600 0
#define BAUD115200 1
#endif
