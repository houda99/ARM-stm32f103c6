#ifndef		DMA_PRIVATE_H
#define		DMA_PRIVATE_H
#define		DMA_BASE_ADD			0x40020000


typedef		struct
{
	u32		CCR;
	u32		CNDTR;
	u32		CPAR;
	u32		CMAR;
	u32		Reserved;
}DMA_Channel;

typedef		struct
{
	u32				ISR;
	u32				IFCR;
	DMA_Channel		Channel[7]	;
}DMA1_Type;

#define		DMA1		((volatile DMA1_Type*)(DMA_BASE_ADD))

#define		MemorytoMemory			0
#define		prepherialtoMemory		1
#define		MemorytoPrepherial		2
#define		PrepherialtoPrepherial	3

#define		TriggerSource			0
#define		FreeRunning	 			1
#define		Circular				2

#define		ARR2ARR					0
#define		PREPH2ARR	 			1
#define		ARR2PREPH 				2
#define		PREPH2PREPH 			3

#define 	BIT8					0
#define 	BIT16					1
#define 	BIT32 					2

#define 	low					0
#define 	mid					1
#define 	high				2
#define 	vhigh				3

#endif
