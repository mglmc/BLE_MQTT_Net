################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MQTT/Clients.c \
../MQTT/Heap.c \
../MQTT/LinkedList.c \
../MQTT/Log.c \
../MQTT/MQTTAsync.c \
../MQTT/MQTTPacket.c \
../MQTT/MQTTPacketOut.c \
../MQTT/MQTTPersistence.c \
../MQTT/MQTTPersistenceDefault.c \
../MQTT/MQTTProtocolClient.c \
../MQTT/MQTTProtocolOut.c \
../MQTT/Messages.c \
../MQTT/Socket.c \
../MQTT/SocketBuffer.c \
../MQTT/StackTrace.c \
../MQTT/Thread.c \
../MQTT/Tree.c \
../MQTT/utf-8.c 

OBJS += \
./MQTT/Clients.o \
./MQTT/Heap.o \
./MQTT/LinkedList.o \
./MQTT/Log.o \
./MQTT/MQTTAsync.o \
./MQTT/MQTTPacket.o \
./MQTT/MQTTPacketOut.o \
./MQTT/MQTTPersistence.o \
./MQTT/MQTTPersistenceDefault.o \
./MQTT/MQTTProtocolClient.o \
./MQTT/MQTTProtocolOut.o \
./MQTT/Messages.o \
./MQTT/Socket.o \
./MQTT/SocketBuffer.o \
./MQTT/StackTrace.o \
./MQTT/Thread.o \
./MQTT/Tree.o \
./MQTT/utf-8.o 

C_DEPS += \
./MQTT/Clients.d \
./MQTT/Heap.d \
./MQTT/LinkedList.d \
./MQTT/Log.d \
./MQTT/MQTTAsync.d \
./MQTT/MQTTPacket.d \
./MQTT/MQTTPacketOut.d \
./MQTT/MQTTPersistence.d \
./MQTT/MQTTPersistenceDefault.d \
./MQTT/MQTTProtocolClient.d \
./MQTT/MQTTProtocolOut.d \
./MQTT/Messages.d \
./MQTT/Socket.d \
./MQTT/SocketBuffer.d \
./MQTT/StackTrace.d \
./MQTT/Thread.d \
./MQTT/Tree.d \
./MQTT/utf-8.d 


# Each subdirectory must supply rules for building sources it contributes
MQTT/%.o: ../MQTT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -DBLUEZ_VERSION_MAJOR=5 -DBLUEZ_VERSION_MINOR=43 -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/MQTT" -I"/home/parallels/eclipse-workspace/../pi/usr/lib/arm-linux-gnueabihf/glib-2.0/include" -I"/home/parallels/eclipse-workspace/../pi/usr/include/gio-unix-2.0/" -I"/home/parallels/eclipse-workspace/../pi/usr/include/glib-2.0" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/include" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/JSON" -I"/home/parallels/eclipse-workspace/TFG_16_04_18.zip_expanded/PruebaBTLE2_MQTT/dbus" -O0 -g3 -Wall -c -fmessage-length=0 --sysroot=/home/parallels/pi -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


