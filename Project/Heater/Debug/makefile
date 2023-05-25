################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/RTOS/subdir.mk
-include Drivers/02\ ECU/Segment7/subdir.mk
-include Drivers/02\ ECU/EEPROM/subdir.mk
-include Drivers/02\ ECU/BLUETOOTH/subdir.mk
-include Drivers/02\ ECU/03\ Buzzer/subdir.mk
-include Drivers/02\ ECU/02\ LCD/subdir.mk
-include Drivers/02\ ECU/01\ Button/subdir.mk
-include Drivers/02\ ECU/00\ LED/subdir.mk
-include Drivers/01\ MCAL/09\ I2C/subdir.mk
-include Drivers/01\ MCAL/08\ SPI/subdir.mk
-include Drivers/01\ MCAL/07\ USART/subdir.mk
-include Drivers/01\ MCAL/04\ STK/subdir.mk
-include Drivers/01\ MCAL/04\ ADC/subdir.mk
-include Drivers/01\ MCAL/03\ EXTI/subdir.mk
-include Drivers/01\ MCAL/02\ NVIC/subdir.mk
-include Drivers/01\ MCAL/01\ GPIO/subdir.mk
-include Drivers/01\ MCAL/00\ RCC/subdir.mk
-include Drivers/00\ LIB/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Heater
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Heater.elf \

MAP_FILES += \
Heater.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Heater.list \


# All Target
all: main-build

# Main-build Target
main-build: Heater.elf secondary-outputs

# Tool invocations
Heater.elf Heater.map: $(OBJS) $(USER_OBJS) E:\NTI\STM32\Heater\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Heater.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\NTI\STM32\Heater\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Heater.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Heater.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Heater.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Heater.elf Heater.list Heater.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
