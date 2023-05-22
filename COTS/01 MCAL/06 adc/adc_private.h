#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define		ADC_BASE_ADD			0x40012400


typedef		struct
{
	u32				SR;
	u32				CR1;
	u32				CR2;
	u32				SMPR1;
	u32				SMPR2;
	u32				JOFR1;
	u32				JOFR2;
	u32				JOFR3;
	u32				JOFR4;
	u32				HTR;
	u32				LTR;
	u32				SQR1;
	u32				SQR2;
	u32				SQR3;
	u32				JSQR;
	u32				JDR1;
	u32				JDR2;
	u32				JDR3;
	u32				JDR4;
	u32				DR;
}ADC1_Type;
#define			ADC1				((volatile ADC1_Type*)(ADC_BASE_ADD))

#define single 0
#define continuous 1
#define enabled 1
#define disabled 0
#endif
