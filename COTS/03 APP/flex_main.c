#include "Common_Function.h"
#include "DIO_interface.h"
#include "RCC_interface.h"
#include "adc_interface.h"
#include "adc_private.h"
#include "DMA_interface.h"
#include "LED_interface.h"
//#include "LCD4BIT.h"


float Temperature,level ;
u16 RxData[3];

int main(){
	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, 4);
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 2);
	RCC_voidEnablePerClk(RCC_AHB,0);
	ADC_void_init();
	ADC_enable();
	DMA1_voidChannelInit(0);
	DMA1_voidStartChannel((u32 )&ADC1->DR, (u32 )RxData, 3);
	ADC_Start();
	LED_init(PORTB, 0);
	LED_init(PORTB, 1);
	LED_init(PORTB, 5);
		while (1)
		{

			level=ADC1->DR;
			//Temperature = ((1.43 - ((float)(3.3*RxData[2]/(float)4095))) / 0.0043) + 25;
					if(level <2000)
					{
					LED_off(PORTB, 0);
					LED_off(PORTB, 1);
					LED_off(PORTB, 5);

					}
					else if(level < 2500)
					{
					LED_on(PORTB, 0);
					LED_off(PORTB, 1);
					LED_off(PORTB, 5);
					}
					else if(level < 3000)
					{
						LED_on(PORTB, 0);
						LED_on(PORTB, 1);
						LED_off(PORTB, 5);

					}
					else if(level < 4000)
					{
						LED_on(PORTB, 0);
						LED_on(PORTB, 1);
						LED_on(PORTB, 5);
					}
				_delay_ms(1000);
		}

	return 0;
}
