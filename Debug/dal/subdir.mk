################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dal/ProductDalDummy.cpp \
../dal/ProductDalMySql.cpp 

OBJS += \
./dal/ProductDalDummy.o \
./dal/ProductDalMySql.o 

CPP_DEPS += \
./dal/ProductDalDummy.d \
./dal/ProductDalMySql.d 


# Each subdirectory must supply rules for building sources it contributes
dal/%.o: ../dal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


