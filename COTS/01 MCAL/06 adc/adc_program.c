#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
//#include "DIO_private.h"

#include	"adc_interface.h"
#include	"adc_private.h"
#include	"adc_config.h"

void	ADC_void_init(void){
	RCC_voidEnablePerClk(RCC_APB2, 9);
	/*set scan mode*/
	SET_BIT(ADC1->CR1,8);
	#if adc_convert_mode == continuous
	/*continuous conversion*/
	//ADC1->CR2 = (1<<1);
	SET_BIT(ADC1->CR2,1);
	#elif adc_convert_mode== single
	 CLR_BIT(ADC1->CR2,1);
	#endif
	/* EXTERNAL trigger SWSTART*/
	SET_BIT(ADC1->CR2,17);
	SET_BIT(ADC1->CR2,18);
	SET_BIT(ADC1->CR2,19);
	/*right data alignment */
	CLR_BIT(ADC1->CR2,11);
	// Enable DMA for ADC
	#if DMA_mode == enabled
	set_BIT(ADC1->CR2,8);
	#elif DMA_mode == disabled
		CLR_BIT(ADC1->CR2,8);
	#endif 
	/*enable continuous requests*/
	SET_BIT(ADC1->CR2,9);
	/**/
	SET_BIT(ADC1->CR2,20);
	//SET_BIT(ADC1->CR1,5);
	/*SET CONVERISIOPN TIME*/
	/*CHANNEL 1 1.5CYCLES*/
	CLR_BIT(ADC1->SMPR2,3);
	CLR_BIT(ADC1->SMPR2,4);
	CLR_BIT(ADC1->SMPR2,5);
	/*CHANNEL 4 1.5CYCLES*/
	CLR_BIT(ADC1->SMPR2,12);
	CLR_BIT(ADC1->SMPR2,13);
	CLR_BIT(ADC1->SMPR2,14);
	/*Sequence*/
	SET_BIT(ADC1->SQR1,21);//L=2 3 CONVERSIONs

	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_ANALOG);
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_INPUT_ANALOG);
	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_INPUT_ANALOG);

//	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_INPUT_ANALOG);
//	/**********************************/
//	/*for temperature sensor */
//	ADC1->SMPR1 |= (7<<18);  // Sampling time (71.5 cycles) of 7 us for channel 16.. It should be <17.1 us
//
//	// Set the TSVREFE Bit to wake the sensor
//	ADC1->CR2 |= (1<<23);
//
//	// Enable DMA for ADC
//		ADC1->CR2 |= (1<<8);
//	// Channel Sequence
//	ADC1->SQR3 |= (1<<0);  // SEQ1 for Channel 1
//	ADC1->SQR3 |= (4<<5);  // SEQ2 for CHannel 4
//	ADC1->SQR3 |= (16<<10);
//
	SET_BIT(ADC1->CR2 , 2);
	_delay_ms(10);
//	//while(GET_BIT(ADC1->CR2 , 2) != 0);

}
void 	ADC_enable(void){
	SET_BIT(ADC1->CR2,0);
	_delay_ms(10);

}
void 	ADC_Start(void){
	ADC1->SR = 0;  // Clear Status register
	ADC1->CR2 |= 1<<22;
	//while(GET_BIT(ADC1->SR , 1) != 1);
	// Start conversion

}

