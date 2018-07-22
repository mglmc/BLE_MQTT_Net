################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../dbus/gattlib.c \
../dbus/org-bluez-adaptater1.c \
../dbus/org-bluez-device1.c \
../dbus/org-bluez-gattcharacteristic1.c \
../dbus/org-bluez-gattdescriptor1.c \
../dbus/org-bluez-gattservice1.c 

OBJS += \
./dbus/gattlib.o \
./dbus/org-bluez-adaptater1.o \
./dbus/org-bluez-device1.o \
./dbus/org-bluez-gattcharacteristic1.o \
./dbus/org-bluez-gattdescriptor1.o \
./dbus/org-bluez-gattservice1.o 

C_DEPS += \
./dbus/gattlib.d \
./dbus/org-bluez-adaptater1.d \
./dbus/org-bluez-device1.d \
./dbus/org-bluez-gattcharacteristic1.d \
./dbus/org-bluez-gattdescriptor1.d \
./dbus/org-bluez-gattservice1.d 


# Each subdirectory must supply rules for building sources it contributes
dbus/%.o: ../dbus/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


