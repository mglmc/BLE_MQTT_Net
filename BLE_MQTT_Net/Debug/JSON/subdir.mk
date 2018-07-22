################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../JSON/frozen.c 

OBJS += \
./JSON/frozen.o 

C_DEPS += \
./JSON/frozen.d 


# Each subdirectory must supply rules for building sources it contributes
JSON/%.o: ../JSON/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -DBLUEZ_VERSION_MAJOR=5 -DBLUEZ_VERSION_MINOR=43 -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/MQTT" -I"/home/parallels/eclipse-workspace/../pi/usr/lib/arm-linux-gnueabihf/glib-2.0/include" -I"/home/parallels/eclipse-workspace/../pi/usr/include/gio-unix-2.0/" -I"/home/parallels/eclipse-workspace/../pi/usr/include/glib-2.0" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/include" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/JSON" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/dbus" -O0 -g3 -Wall -c -fmessage-length=0 --sysroot=/home/parallels/pi -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


