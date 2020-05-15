################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32f407_gpio_drivers.c 

OBJS += \
./drivers/Src/stm32f407_gpio_drivers.o 

C_DEPS += \
./drivers/Src/stm32f407_gpio_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/stm32f407_gpio_drivers.o: ../drivers/Src/stm32f407_gpio_drivers.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -DDEBUG -c -I../Inc -I"E:/stm32Workspace/stm32f407Drivers/stm32f407xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32f407_gpio_drivers.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

