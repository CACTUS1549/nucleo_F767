/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Deepak Reddy
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 ******************************************************************************
 */

#include "stm32f767xx.h"
#include "stm32f767xx_hal_gpio.h"

void delay(void);

int main(void)
{
	GPIO_Set_PClk(GPIOB, ENABLE);

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOB;
	GpioLed.pinConfig.GPIO_PinNumber = GPIO_PIN_7;
	GpioLed.pinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.pinConfig.GPIO_Out_Type = GPIO_OUT_PUSH_PULL;
	GpioLed.pinConfig.GPIO_PuPd = GPIO_NO_PU_PD;
	GpioLed.pinConfig.GPIO_Out_Speed = GPIO_SPEED_LOW;

	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_Toggle_Output_Pin(GPIOB, GPIO_PIN_7);
		delay();
	}
}

void delay(void)
{
	for (uint32_t i = 0; i < 500000; i++)
	{
		;
	}
}
