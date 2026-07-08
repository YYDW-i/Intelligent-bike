################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/Attitude.c \
../code/gnss.c \
../code/key.c \
../code/motor.c \
../code/servo.c \
../code/task.c \
../code/wifi.c 

C_DEPS += \
./code/Attitude.d \
./code/gnss.d \
./code/key.d \
./code/motor.d \
./code/servo.d \
./code/task.d \
./code/wifi.d 

OBJS += \
./code/Attitude.o \
./code/gnss.o \
./code/key.o \
./code/motor.o \
./code/servo.o \
./code/task.o \
./code/wifi.o 


# Each subdirectory must supply rules for building sources it contributes
code/%.o: ../code/%.c code/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Infineon/library/TC264_Library-master/Seekfree_TC264_Opensource_Library/Seekfree_TC264_general_Opensource_Library/Seekfree_TC264_Opensource_Library/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-code

clean-code:
	-$(RM) ./code/Attitude.d ./code/Attitude.o ./code/gnss.d ./code/gnss.o ./code/key.d ./code/key.o ./code/motor.d ./code/motor.o ./code/servo.d ./code/servo.o ./code/task.d ./code/task.o ./code/wifi.d ./code/wifi.o

.PHONY: clean-code

