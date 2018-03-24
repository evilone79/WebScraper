################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utility/TaskQueue.cpp \
../utility/TaskRunner.cpp 

OBJS += \
./utility/TaskQueue.o \
./utility/TaskRunner.o 

CPP_DEPS += \
./utility/TaskQueue.d \
./utility/TaskRunner.d 


# Each subdirectory must supply rules for building sources it contributes
utility/%.o: ../utility/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


