################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: gpp_testing.axf

# Tool invocations
gpp_testing.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/palash/Documents/MCUXpressoIDE_11.4.0_6237/workspace/CMSIS_CORE_LPC17xx/Debug" -Xlinker -Map="gpp_testing.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "gpp_testing_Debug.ld" -o "gpp_testing.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) gpp_testing.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "gpp_testing.axf"; # arm-none-eabi-objcopy -v -O binary "gpp_testing.axf" "gpp_testing.bin" ; # checksum -p LPC1769 -d "gpp_testing.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
