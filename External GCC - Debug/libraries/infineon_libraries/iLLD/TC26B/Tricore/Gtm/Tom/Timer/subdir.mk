################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.c 

C_DEPS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.d 

OBJS += \
./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.o 


# Each subdirectory must supply rules for building sources it contributes
libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/%.o: ../libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/%.c libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-gcc -std=c99 "@D:/Infineon/library/TC264_Library-master/Seekfree_TC264_Opensource_Library/Seekfree_TC264_general_Opensource_Library/Seekfree_TC264_Opensource_Library/External GCC - Debug/AURIX_GCC_Compiler-Include_paths__-I_.opt" -O0 -g3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Gtm-2f-Tom-2f-Timer

clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Gtm-2f-Tom-2f-Timer:
	-$(RM) ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.d ./libraries/infineon_libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.o

.PHONY: clean-libraries-2f-infineon_libraries-2f-iLLD-2f-TC26B-2f-Tricore-2f-Gtm-2f-Tom-2f-Timer

