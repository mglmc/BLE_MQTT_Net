################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dbus/bluez5/lib/uuid.c 

OBJS += \
./dbus/bluez5/lib/uuid.o 

C_DEPS += \
./dbus/bluez5/lib/uuid.d 


# Each subdirectory must supply rules for building sources it contributes
dbus/bluez5/lib/%.o: ../dbus/bluez5/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


