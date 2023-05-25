/*
 * RTOS_program.c
 *
 *  Created on: May 22, 2023
 *      Author: es-MohamedHAbdelAziz
 */

#include "Std_Types.h"
#include "Bit_Math.h"
#include "RTOS_interface.h"
#include "STK_interface.h"


task_st task[20] ={0};
u8 tick = 0;

void RTOS_CreateTask(u8 priority,u16 priodicity,void (*func_Task)(void),u8 first_delay)
{
	task[priority].priodicity = priodicity;
	task[priority].func_Task = func_Task;
	task[priority].state = ready;
	task[priority].firstdelay = first_delay;

}

void RTOS_Scheduler(void)
{
	for (int i =0; i < 3;i++)
	{
		if (task[i].state == susbend)
		{
			continue;
		}
		if (task[i].firstdelay == 0)
		{
			task[i].func_Task();
			task[i].firstdelay = task[i].priodicity - 1;
		}
		else
		{
			task[i].firstdelay--;
		}
	}
}
void RTOS_Start(void)
{
	RTOS_Scheduler();
	STK_voidSetBusyWait(1000000);
}

void Task_Susbend(u8 priority)
{
	task[priority].state = susbend;
}
void Task_Resume(u8 priority)
{
	task[priority].state = ready;
}
void Task_Delete(u8 priority)
{
	task[priority].state = 0;
}
