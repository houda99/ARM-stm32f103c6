<<<<<<< HEAD
#ifndef		DMA_PRIVATE_H
#define		DMA_PRIVATE_H
#define		DMA_BASE_ADD			0x40020000


typedef struct {
	volatile	u32		CCR;
	volatile	u32		CNDTR;
	volatile	u32		CPAR;
	volatile	u32		RESERVE;
}DMA_Channel;
typedef struct
{
	volatile	u32		ISR;
	volatile	u32		IFCR;
	DMA_Channel 		Channel[7];
	
}DMA1_Type;

#define			DMA1				((DMA1_Type *)(DMA_BASE_ADD))
=======
#ifndef		DMA_PRIVATE_H
#define		DMA_PRIVATE_H
#define		DMA_BASE_ADD			0x40020000


typedef struct {
	volatile	u32		CCR;
	volatile	u32		CNDTR;
	volatile	u32		CPAR;
	volatile	u32		RESERVE;
}DMA_Channel;
typedef struct
{
	volatile	u32		ISR;
	volatile	u32		IFCR;
	DMA_Channel 		Channel[7];
	
}DMA1_Type;

#define			DMA1				((DMA1_Type *)(DMA_BASE_ADD))
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
#endif