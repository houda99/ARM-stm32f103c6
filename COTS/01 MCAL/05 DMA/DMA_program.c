#include "Common_Function.h"
#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_Private.h"

void	DMA1_voidChannelInit(u8 ChannelN)
{
	/*
	Memory to Memory
	priority very high
	Size (Source & Destination) u32
	MINC, PINC enabled
	Direction read from Peripheral
	Transfer Complete Interrupt
	Channel Disable
	*/

//	DMA1 ->	Channel[0].CCR = 0x00007AC2;

	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,0);
	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,1);// TCI enable
	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,4);//read from prephiral
#if SDMODE == MemorytoMemory
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,14);
#else
	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,14);
#endif

#if TrigMode == Circular
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,5);
#endif

#if mode == ARR2ARR
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,6);
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,7);
#elif mode == PREPH2ARR
	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,6);
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,7);
#elif mode == ARR2PREPH
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,6);
	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,7);
#elif mode == PREPH2PREPH
	CLR_BIT(DMA1 ->Channel[ChannelN].CCR,6)
	SET_BIT(DMA1 ->Channel[ChannelN].CCR,7);
#endif

#if msize == BIT32
		SET_BIT(DMA1 ->Channel[ChannelN].CCR,11);
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,10);
#elif msize == BIT16
	    CLR_BIT(DMA1 ->Channel[ChannelN].CCR,11);
	    SET_BIT(DMA1 ->Channel[ChannelN].CCR,10);
#elif msize == BIT8
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,11);
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,10);
#endif



#if psize == BIT32
		SET_BIT(DMA1 ->Channel[ChannelN].CCR,9);
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,8);
#elif psize == BIT16
	    CLR_BIT(DMA1 ->Channel[ChannelN].CCR,9);
	    SET_BIT(DMA1 ->Channel[ChannelN].CCR,8);
#elif (psize == BIT8)
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,9);
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,8);
#endif

#if (per == vhigh)
		SET_BIT(DMA1 ->Channel[ChannelN].CCR,13);
		SET_BIT(DMA1 ->Channel[ChannelN].CCR,12);
#elif (per == high)
		SET_BIT(DMA1 ->Channel[ChannelN].CCR,13);
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,12);
#elif (per == mid)
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,13);
		SET_BIT(DMA1 ->Channel[ChannelN].CCR,12);
#elif (per == low)
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,13);
		CLR_BIT(DMA1 ->Channel[ChannelN].CCR,12);
#endif


}

void	DMA1_voidStartChannel(u32  SrcAdd,u32  DestAdd,u16 BlockLength)
{
	/*	Load the Block Length				*/
		DMA1 -> Channel[0].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  disabled */
	//CLR_BIT(DMA1 -> Channel[0].CCR,0);
	
	DMA1 -> Channel[0].CPAR	=	SrcAdd;
	DMA1 -> Channel[0].CMAR	=	DestAdd;
	

	/*		Make Sure that the channel is  Enabled to start transfer*/
	SET_BIT(DMA1 -> Channel[0].CCR,0);	
}








