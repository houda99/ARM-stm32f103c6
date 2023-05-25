
#include "APP_interface.h"


u16 ADC_Value;
u8 INBUT_Value = 0;
typedef enum{
	level1,
	level2,
	level3,
	level4,
	level5,
}inictor_levels;
float temperature;
inictor_levels indicator ;


#define levelup
#define leveldown

int main(void)
{

	Heater_systemint();
	ADC_Value	= ADC1->DR &0x0000FFFF;
	temperature=ADC_Value/39.6;
	calibration_ISR();


	while (1)
	{
		DIO_voidSetPinValue(PORTA, PIN12, GPIO_LOW);
		INBUT_Value = BLUETOOTH_u8RecieveData();
		ADC_Value	= ADC1->DR &0x0000FFFF;
		temperature=ADC_Value/39.6;
		Segment7_voidDualModeSetValue(PORTB, PIN6, (u8)temperature);
		//####################Bluetooth vlue check
		if (INBUT_Value!=0){
			if(INBUT_Value=='u'){
				Button_down_ISR();
			}else if (INBUT_Value=='d'){
				Button_up_ISR();
			}else if (INBUT_Value=='c'){
				calibration_ISR();
			}
		}
		//############temperature checking
		if(temperature<20)//level1
		{
			if(indicator>level1){
				//####################work heting element
				LED_on(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
			}else if (indicator==level1){
				//send stble state
				LED_off(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
				SPI_voidSend('1');
			}

		}else if (temperature>20 &&temperature<40) //level 2
		{
			if(indicator>level2){
				//####################work heating element
				LED_on(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
			}
			else if(indicator<level2){
				//######################## work cooling element
				LED_off(PORTB, PIN3);//heating element
				LED_on(PORTB, PIN4);//cooling elemnt

			}else if (indicator==level2){
				//send stble state
				LED_off(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
				SPI_voidSend('2');
			}
		}else if (temperature>40 &&temperature<60) //level 3
		{
			if(indicator>level3){
				//####################work heating element
				LED_on(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
			}else if(indicator<level3){
				//######################## work cooling element
				LED_off(PORTB, PIN3);//heating element
				LED_on(PORTB, PIN4);//cooling elemnt

			}else if (indicator==level3){
				//send stble state
				LED_off(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
				SPI_voidSend('3');
			}


		}else if (temperature>60 &&temperature<80) //level 4
		{
			if(indicator>level4){
				//####################work heting element
				LED_on(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
			}else if(indicator<level4){
				//######################## work cooling element
				LED_off(PORTB, PIN3);//heating element
				LED_on(PORTB, PIN4);//cooling elemnt

			}else if (indicator==level4){
				//send stble state
				LED_off(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
				SPI_voidSend('4');
			}
		}else if (temperature>80 &&temperature<100) //level 5
		{

			if(indicator>level5){
				//####################work heting element
				LED_on(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
			}else if(indicator<level5){
				//######################## work cooling element
				LED_off(PORTB, PIN3);//heating element
				LED_on(PORTB, PIN4);//cooling elemnt
			}else if (indicator==level5){
				//send stble state
				LED_off(PORTB, PIN3);//heating element
				LED_off(PORTB, PIN4);//cooling elemnt
				SPI_voidSend('5');
			}
		}
		//######################################################################
		//#######################water level checking#############################3


				if(DIO_u8GetPinValue(PORTA,PIN12)==1)//level 3 // buzzer off //full tnk
				{
					//full tank
					LED_off(PORTA, PIN11);
					LED_off(PORTB, PIN5);
					Buzzer_off(PORTB,PIN0);
					SPI_voidSend('f');

				}else if(DIO_u8GetPinValue(PORTA,PIN8)==1)//level 2 //water level medium
				{
					//medium tank sate
					LED_on(PORTA, PIN11);//medium tank led
					LED_off(PORTB, PIN5);
					Buzzer_off(PORTB,PIN0);
					SPI_voidSend('m');
					DIO_voidSetPinValue(PORTA, PIN8, GPIO_LOW);
				}else if(DIO_u8GetPinValue(PORTA,PIN3)==1)//level 1 //water level very low
				{
					//very low tank state
					LED_on(PORTA, PIN11);//medium tank led
					LED_on(PORTB, PIN5);// low tank led
					Buzzer_off(PORTB,PIN0);
					SPI_voidSend('l');
					DIO_voidSetPinValue(PORTA, PIN3, GPIO_LOW);
				}else{
					//emty tank state
					LED_toogle(PORTA, PIN11);//medium tank led
					LED_toogle(PORTB, PIN5);// low tank led
					Buzzer_on(PORTB,PIN0);
					SPI_voidSend('v');
				}



	}

}

void calibration_ISR(void){

	LED_off(PORTC, PIN13);
	_delay_ms(100);
	LED_on(PORTC, PIN13);

	if(temperature<20)//level1
	{
		indicator = level1;
	}else if (temperature>20 &&temperature<40) //level 2
	{
		indicator = level2;
	}else if (temperature>40 &&temperature<60) //level 3
	{
		indicator = level3;
	}else if (temperature>60 &&temperature<80) //level 4
	{
		indicator = level4;
	}else if (temperature>80 &&temperature<100) //level 5
	{
		indicator = level5;
	}

}

void Button_up_ISR(void){

	LED_off(PORTC, PIN13);
	_delay_ms(100);
	LED_on(PORTC, PIN13);
	if(indicator !=4){
		indicator++;
	}


}
void Button_down_ISR(void){

	LED_off(PORTC, PIN13);
	_delay_ms(100);
	LED_on(PORTC, PIN13);
	if(indicator !=0){
		indicator--;
	}
}




//spi to secand mc

//error status on 1st and secand mc

//difrent between temp high buzzer on

//i2c to eerom


