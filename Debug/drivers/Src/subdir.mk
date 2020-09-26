################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/stm32f767xx_hal_gpio.c 

OBJS += \
./drivers/Src/stm32f767xx_hal_gpio.o 

C_DEPS += \
./drivers/Src/stm32f767xx_hal_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/stm32f767xx_hal_gpio.o: ../drivers/Src/stm32f767xx_hal_gpio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"/Users/deepakreddy/Documents/STM32/stm32f767xx_drivers/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"drivers/Src/stm32f767xx_hal_gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

