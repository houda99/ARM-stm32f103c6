################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c 

OBJS += \
./Src/main.o 

C_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/00 RCC" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/01 GPIO" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/02 NVIC" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/03 EXTI" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/04 ADC" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/07 USART" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/00 LED" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/01 Button" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/03 Buzzer" -I"E:/NTI/STM32/Heater/Drivers/RTOS" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/04 STK" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/Segment7" -I"E:/NTI/STM32/Heater/Debug/Drivers/00 LIB" -I"E:/NTI/STM32/Heater/Inc" -I"E:/NTI/STM32/Heater/Drivers/00 LIB" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/BLUETOOTH" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/02 LCD" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/08 SPI" -I"E:/NTI/STM32/Heater/Drivers/01 MCAL/09 I2C" -I"E:/NTI/STM32/Heater/Drivers/02 ECU/EEPROM" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su

.PHONY: clean-Src

