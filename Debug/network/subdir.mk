################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../network/HttpSecureSession.cpp \
../network/HttpSecureSessionFactory.cpp 

OBJS += \
./network/HttpSecureSession.o \
./network/HttpSecureSessionFactory.o 

CPP_DEPS += \
./network/HttpSecureSession.d \
./network/HttpSecureSessionFactory.d 


# Each subdirectory must supply rules for building sources it contributes
network/%.o: ../network/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


