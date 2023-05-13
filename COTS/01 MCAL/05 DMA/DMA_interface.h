
#ifndef DMA_INTER_H
#define DMA_INTER_H
//#include "Common_Function.h"

void	DMA1_voidChannelInit();
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);

#endif
