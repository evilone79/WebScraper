################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main/PageDownloader.cpp \
../main/ProductFinder.cpp \
../main/SearchRuleCache.cpp \
../main/SimpleUrlProvider.cpp \
../main/WebScraper.cpp 

OBJS += \
./main/PageDownloader.o \
./main/ProductFinder.o \
./main/SearchRuleCache.o \
./main/SimpleUrlProvider.o \
./main/WebScraper.o 

CPP_DEPS += \
./main/PageDownloader.d \
./main/ProductFinder.d \
./main/SearchRuleCache.d \
./main/SimpleUrlProvider.d \
./main/WebScraper.d 


# Each subdirectory must supply rules for building sources it contributes
main/%.o: ../main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O2 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main/SearchRuleCache.o: ../main/SearchRuleCache.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"main/SearchRuleCache.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


