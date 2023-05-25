/*
 * RTOS_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#ifndef RTOS_RTOS_INTERFACE_H_
#define RTOS_RTOS_INTERFACE_H_


typedef struct {
	u16 priodicity;
	void (*func_Task)(void);
	u8 state;
	u16 firstdelay;
}task_st;

typedef enum {
	susbend,
	ready
}task_state;

void RTOS_CreateTask(u8 priority,u16 priodicity,void (*func_Task)(void),u8 first_delay);
void RTOS_Scheduler(void);
void RTOS_Start(void);
void Task_Susbend(u8 priority);
void Task_Resume(u8 priority);
void Task_Delete(u8 priority);


#endif /* RTOS_RTOS_INTERFACE_H_ */
