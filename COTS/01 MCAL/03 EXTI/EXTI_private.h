<<<<<<< HEAD







#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))
#define RISING_EDGE 0
#define FALLING_EDGE 1
#define IOC 2



=======







#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))
#define RISING_EDGE 0
#define FALLING_EDGE 1
#define IOC 2



>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
