




#include "APP_interface.h"


//interrupt functions declaration
void calibration_ISR(void);
void Button_up_ISR(void);
void Button_down_ISR(void);

void Heater_systemint(void){

	//clock intalizing
		RCC_voidSysClkInt();  //intalize clock
		RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_AFIO); //intalize clock to Alternate functio
		RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_DIOA); //intalize clock for GPIOA
		RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_DIOB); //intalize clock for GPIOb
		RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_DIOC); //intalize clock for GPIOC
		RCC_voidEnablePerClk(RCC_APB2,RCC_APB2_ADC1);
		RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_USART1);
		RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_SPI1); //rcc clock for spi1

		//uart pins intalize
		DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_10MHZ_AFPP);//uart pint tx
		DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_FLOAT);//uart pin rx

		//spi pins intalize
		DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_10MHZ_AFPP); //clk
			DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT);		//MISO
			DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_10MHZ_AFPP);//MOSI
			DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_10MHZ_PP); //ss
			SPI1_voidInit();
			SET_BIT(SPI1->CR1,8)	; //value of this bit forced on the NSS pin
			//DISABLE ALL INTERRUPT
			SPI1->CR2=0;
		//buttons intalizer
		BUTTON_init(PORTA, PIN0, Button_pullup);
		BUTTON_init(PORTA, PIN1, Button_pullup);
		BUTTON_init(PORTA, PIN2, Button_pullup);

		//buzzer inalize
		Buzzer_int(PORTB, PIN0);

		//ADC intalizing

		DIO_voidSetPinDirection(PORTB, PIN1, GPIO_INPUT_ANALOG);
	    RCC_voidEnablePerClk(RCC_APB2, RCC_APB2_ADC1); // enable ADC1 clock
	    RCC_ADC_SETprescaler(divided4);
	   //temp sensor channel config
		 ADC_channelSetup(ADC_channe9,SEQ1,cycles_239_5);
		 ADC_voidInit();
		 ADC_voidEnable();
		 ADC_Start();

	//set the inerupt function
		EXTI_voidSetCallBack(calibration_ISR,EXTI0);//A0
		EXTI_voidSetCallBack(Button_up_ISR,EXTI1);//A1
		EXTI_voidSetCallBack(Button_down_ISR,EXTI2);//A2

	//External interupt intalizer
		EXTI_voidInit(EXTI0,PORTA);
		EXTI_voidInit(EXTI1,PORTA);
		EXTI_voidInit(EXTI2,PORTA);

		EXTI_voidEnableInt(EXTI0);
		EXTI_voidEnableInt(EXTI1);
		EXTI_voidEnableInt(EXTI2);

		EXTI_voidChangeSenseMode(EXTI0,FALLING_EDGE);
		EXTI_voidChangeSenseMode(EXTI1,FALLING_EDGE);
		EXTI_voidChangeSenseMode(EXTI2,FALLING_EDGE);


		//nvic enabler
		NVIC_voidEnablePerInt(6);
		NVIC_voidEnablePerInt(7);
		NVIC_voidEnablePerInt(8);
		 //segment and bluetooth intalize
		Segment7_voidDualModeInit(PORTB, PIN6);

		BLUETOOTH_voidinit();
//#######################wter level intliztion
		//level 1 ...//green led
		DIO_voidSetPinDirection(PORTA, PIN3, GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinValue(PORTA, PIN3, GPIO_LOW);
		//level 2 ...//red led
		DIO_voidSetPinDirection(PORTA, PIN8, GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinValue(PORTA, PIN8, GPIO_LOW);

		//level 3 ...//blue led // buzzer on
		DIO_voidSetPinDirection(PORTA, PIN12, GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinValue(PORTA, PIN12, GPIO_LOW);
//####################spi intalization##################################################3
		SPI1_voidInit();
//######################################################################################################
		//test led
		LED_int(PORTC, PIN13);
		//test ledds adc
		LED_int(PORTB, PIN3);//heating element
		LED_int(PORTB, PIN4);//cooling elemnt
		LED_int(PORTB, PIN5);
		LED_int(PORTA, PIN11);
//######################################################################################################

}




