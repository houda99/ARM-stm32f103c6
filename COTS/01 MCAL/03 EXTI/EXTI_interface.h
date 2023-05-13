<<<<<<< HEAD

#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H

#include 	"Common_Function.h"


void		EXTI0_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);
void 		EXTI_voidportselect(u8 line_Port,u8 line_num);

void		EXTI0_voidSetCallBack(void (*Fptr)(void));
#endif
=======

#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H

#include 	"Common_Function.h"


void		EXTI0_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);
void 		EXTI_voidportselect(u8 line_Port,u8 line_num);

void		EXTI0_voidSetCallBack(void (*Fptr)(void));
#endif
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
