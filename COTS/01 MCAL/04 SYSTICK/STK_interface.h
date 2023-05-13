<<<<<<< HEAD





void	STK_voidInit();
void	STK_voidSetBusyWait(u32	Ticks);
void	STK_voidSetIntervalSingle(u32	Ticks, void (*Pf)(void));
void	STK_voidSetIntervalPeriodic(u32	Ticks, void (*Pf)(void));
void	STK_voidStopInterval();
u32		STK_u32GetElapsedTime();
=======





void	STK_voidInit();
void	STK_voidSetBusyWait(u32	Ticks);
void	STK_voidSetIntervalSingle(u32	Ticks, void (*Pf)(void));
void	STK_voidSetIntervalPeriodic(u32	Ticks, void (*Pf)(void));
void	STK_voidStopInterval();
u32		STK_u32GetElapsedTime();
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
u32		STK_u32GetRemainingTime();