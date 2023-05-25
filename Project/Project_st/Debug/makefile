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
-include Drivers/03\ APP/subdir.mk
-include Drivers/02\ ECU/05\ Segment7/subdir.mk
-include Drivers/02\ ECU/04\ BLUETOOTH/subdir.mk
-include Drivers/02\ ECU/03\ Buzzer/subdir.mk
-include Drivers/02\ ECU/02\ LCD/subdir.mk
-include Drivers/02\ ECU/01\ Button/subdir.mk
-include Drivers/02\ ECU/00\ LED/subdir.mk
-include Drivers/01\ MCAL/08\ SPI/subdir.mk
-include Drivers/01\ MCAL/07\ I2C/subdir.mk
-include Drivers/01\ MCAL/06\ USART/subdir.mk
-include Drivers/01\ MCAL/05\ STK/subdir.mk
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


BUILD_ARTIFACT_NAME := Project_st
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Project_st.elf \

MAP_FILES += \
Project_st.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Project_st.list \


# All Target
all: main-build

# Main-build Target
main-build: Project_st.elf secondary-outputs

# Tool invocations
Project_st.elf Project_st.map: $(OBJS) $(USER_OBJS) E:\embeded\ learn\Nit\ embeded\ arm\NTI_Workspace\Project_st\STM32F103C6TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Project_st.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\embeded learn\Nit embeded arm\NTI_Workspace\Project_st\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Project_st.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Project_st.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Project_st.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Project_st.elf Project_st.list Project_st.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
