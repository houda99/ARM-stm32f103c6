
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "DIO_interface.h"
#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI0_CallBack)	(void)	= NULL;

void		EXTI0_voidInit(void)
{
		/*  */
#ifndef			AFIO_EXTICR
		#define		AFIO_BASE_ADD		(0x40010000)
		#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
		#define		AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
		#define		AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
		#define		AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))
#endif

EXTI_voidportselect(PORTA, 0);
EXTI_voidChangeSenseMode(0,RISING_EDGE);


}
void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}
void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR,line_num);
}

void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}

void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI0_CallBack = Fptr;
	}

}

void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
}
void EXTI_voidportselect(u8 line_Port,u8 line_num){
if(line_num==0){
	switch(line_Port){
	case PORTA: CLR_BIT(AFIO_EXTICR1,0);
				CLR_BIT(AFIO_EXTICR1,1);
				CLR_BIT(AFIO_EXTICR1,2);
				CLR_BIT(AFIO_EXTICR1,3);break;
	case PORTB: SET_BIT(AFIO_EXTICR1,0);
				CLR_BIT(AFIO_EXTICR1,1);
				CLR_BIT(AFIO_EXTICR1,2);
				CLR_BIT(AFIO_EXTICR1,3);break;
	case PORTC: CLR_BIT(AFIO_EXTICR1,0);
				SET_BIT(AFIO_EXTICR1,1);
				CLR_BIT(AFIO_EXTICR1,2);
				CLR_BIT(AFIO_EXTICR1,3);break;
	}

}else if(line_num==1){
	switch(line_Port){
	case PORTA: CLR_BIT(AFIO_EXTICR1,4);CLR_BIT(AFIO_EXTICR1,5);CLR_BIT(AFIO_EXTICR1,6);break;
	case PORTB: SET_BIT(AFIO_EXTICR1,4);CLR_BIT(AFIO_EXTICR1,5);CLR_BIT(AFIO_EXTICR1,6);break;
	case PORTC: CLR_BIT(AFIO_EXTICR1,4);SET_BIT(AFIO_EXTICR1,5);CLR_BIT(AFIO_EXTICR1,6);break;
	}
}else {if(line_num==2){
	switch(line_Port){
	case PORTA: CLR_BIT(AFIO_EXTICR1,8);CLR_BIT(AFIO_EXTICR1,9);CLR_BIT(AFIO_EXTICR1,10);break;
	case PORTB: SET_BIT(AFIO_EXTICR1,8);CLR_BIT(AFIO_EXTICR1,9);CLR_BIT(AFIO_EXTICR1,10);break;
	case PORTC: CLR_BIT(AFIO_EXTICR1,8);SET_BIT(AFIO_EXTICR1,9);CLR_BIT(AFIO_EXTICR1,10);break;
	}
}
}
}

