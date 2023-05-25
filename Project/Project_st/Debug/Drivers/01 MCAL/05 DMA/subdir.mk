################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/01\ MCAL/05\ DMA/DMA_program.c 

OBJS += \
./Drivers/01\ MCAL/05\ DMA/DMA_program.o 

C_DEPS += \
./Drivers/01\ MCAL/05\ DMA/DMA_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/01\ MCAL/05\ DMA/DMA_program.o: ../Drivers/01\ MCAL/05\ DMA/DMA_program.c Drivers/01\ MCAL/05\ DMA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/00 LIB" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/01 MCAL/00 RCC" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/01 MCAL/01 GPIO" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/01 MCAL/02 NVIC" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/01 MCAL/03 EXTI" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/02 ECU/00 LED" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/02 ECU/01 Button" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/02 ECU/03 Buzzer" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/01 MCAL/04 ADC" -I"E:/embeded learn/Nit embeded arm/NTI_Workspace/Project_st/Drivers/01 MCAL/05 DMA" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/01 MCAL/05 DMA/DMA_program.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-01-20-MCAL-2f-05-20-DMA

clean-Drivers-2f-01-20-MCAL-2f-05-20-DMA:
	-$(RM) ./Drivers/01\ MCAL/05\ DMA/DMA_program.cyclo ./Drivers/01\ MCAL/05\ DMA/DMA_program.d ./Drivers/01\ MCAL/05\ DMA/DMA_program.o ./Drivers/01\ MCAL/05\ DMA/DMA_program.su

.PHONY: clean-Drivers-2f-01-20-MCAL-2f-05-20-DMA

