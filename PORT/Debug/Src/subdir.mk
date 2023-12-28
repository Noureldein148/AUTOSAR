################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Det.c \
../Src/Port.c \
../Src/Port_PBCFG.c \
../Src/RCC_Prog.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Det.o \
./Src/Port.o \
./Src/Port_PBCFG.o \
./Src/RCC_Prog.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Det.d \
./Src/Port.d \
./Src/Port_PBCFG.d \
./Src/RCC_Prog.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/Det.cyclo ./Src/Det.d ./Src/Det.o ./Src/Det.su ./Src/Port.cyclo ./Src/Port.d ./Src/Port.o ./Src/Port.su ./Src/Port_PBCFG.cyclo ./Src/Port_PBCFG.d ./Src/Port_PBCFG.o ./Src/Port_PBCFG.su ./Src/RCC_Prog.cyclo ./Src/RCC_Prog.d ./Src/RCC_Prog.o ./Src/RCC_Prog.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

