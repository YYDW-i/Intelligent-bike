################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Assert.c \
../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.c 

C_DEPS += \
./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Assert.d \
./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.d 

OBJS += \
./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Assert.o \
./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.o 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/%.o: ../libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/%.c libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Infineon/library/TC264_Library-master/Seekfree_TC264_Opensource_Library/Seekfree_TC264_general_Opensource_Library/Seekfree_TC264_Opensource_Library/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-libraries-2f-infineon_libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Bsp

clean-libraries-2f-infineon_libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Bsp:
	-$(RM) ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Assert.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Assert.o ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.d ./libraries/infineon_libraries/Service/CpuGeneric/SysSe/Bsp/Bsp.o

.PHONY: clean-libraries-2f-infineon_libraries-2f-Service-2f-CpuGeneric-2f-SysSe-2f-Bsp

