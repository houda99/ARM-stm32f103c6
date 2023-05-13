<<<<<<< HEAD
#ifndef		STK_PRIVATE_H
#define		STK_PRIVATE_H

#define		STK_AHB_DIV_8			0
#define		STK_AHB					1

#define		STK_SINGLE_INTERVAL		0
#define		STK_PERIOD_INTERVAL		1

typedef struct
{
	u32		CTRL;
	u32		LOAD;
	u32		VAL;
	u32		CALIB;
	
}STK_Type;

#define	STK	  ((STK_Type *)(0xE000E010))
#endif
=======
#ifndef		STK_PRIVATE_H
#define		STK_PRIVATE_H

#define		STK_AHB_DIV_8			0
#define		STK_AHB					1

#define		STK_SINGLE_INTERVAL		0
#define		STK_PERIOD_INTERVAL		1

typedef struct
{
	u32		CTRL;
	u32		LOAD;
	u32		VAL;
	u32		CALIB;
	
}STK_Type;

#define	STK	  ((STK_Type *)(0xE000E010))
#endif
>>>>>>> 81f24b8ec317b796073e6525e6dd9a2900465ae9
