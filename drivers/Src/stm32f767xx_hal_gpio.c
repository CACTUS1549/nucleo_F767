/**
 ******************************************************************************
 * @file           : stm32f767xx_hal_gpio.c
 * @author         : Deepak Reddy
 * @brief          : GPIO HAL SOURCE File
 ******************************************************************************
 * @attention
 ******************************************************************************/

#include "stm32f767xx_hal_gpio.h"
#include <stdint.h>

void GPIO_Set_PClk(GPIO_RegMap_t *pGPIOx, uint8_t state)
{
	if(state == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_CLK_EN();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_CLK_EN();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_CLK_EN();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_CLK_EN();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_CLK_EN();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_CLK_EN();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_CLK_EN();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_CLK_EN();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_CLK_EN();
		}else if(pGPIOx == GPIOJ)
		{
			GPIOJ_CLK_EN();
		}else if(pGPIOx == GPIOK)
		{
			GPIOK_CLK_EN();
		}
	} else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_CLK_DI();
		}else if(pGPIOx == GPIOB)
		{
			GPIOB_CLK_DI();
		}else if(pGPIOx == GPIOC)
		{
			GPIOC_CLK_DI();
		}else if(pGPIOx == GPIOD)
		{
			GPIOD_CLK_DI();
		}else if(pGPIOx == GPIOE)
		{
			GPIOE_CLK_DI();
		}else if(pGPIOx == GPIOF)
		{
			GPIOF_CLK_DI();
		}else if(pGPIOx == GPIOG)
		{
			GPIOG_CLK_DI();
		}else if(pGPIOx == GPIOH)
		{
			GPIOH_CLK_DI();
		}else if(pGPIOx == GPIOI)
		{
			GPIOI_CLK_DI();
		}else if(pGPIOx == GPIOJ)
		{
			GPIOJ_CLK_DI();
		}else if(pGPIOx == GPIOK)
		{
			GPIOK_CLK_DI();
		}
	}
}

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	if(pGPIOHandle->pinConfig.GPIO_PinMode != GPIO_MODE_AN)
	{
		//1. Configure the mode
		pGPIOHandle->pGPIOx->MODER	&= ~(pGPIOHandle->pinConfig.GPIO_PinMode << (2 * pGPIOHandle->pinConfig.GPIO_PinNumber));//reset
		pGPIOHandle->pGPIOx->MODER	|= (pGPIOHandle->pinConfig.GPIO_PinMode << (2 * pGPIOHandle->pinConfig.GPIO_PinNumber));//set

		//2. Configure the output type
		pGPIOHandle->pGPIOx->OTYPER &= ~(pGPIOHandle->pinConfig.GPIO_Out_Type << pGPIOHandle->pinConfig.GPIO_PinNumber);//reset
		pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->pinConfig.GPIO_Out_Type << pGPIOHandle->pinConfig.GPIO_PinNumber);//set

		//3. Configure the speed
		pGPIOHandle->pGPIOx->OSPEEDR &= ~(pGPIOHandle->pinConfig.GPIO_Out_Speed << (2* pGPIOHandle->pinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->pinConfig.GPIO_Out_Speed << (2* pGPIOHandle->pinConfig.GPIO_PinNumber));

		//4. Configure Pull-up/Pull-down/No-Pull
		pGPIOHandle->pGPIOx->PUPDR &= ~(pGPIOHandle->pinConfig.GPIO_PuPd << (2* pGPIOHandle->pinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->pinConfig.GPIO_PuPd << (2* pGPIOHandle->pinConfig.GPIO_PinNumber));


	}else{
		//TODO:- Alternate function mode
	}
}

void GPIO_DeInit(GPIO_RegMap_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RST();
	}else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RST();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RST();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RST();
	}else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RST();
	}else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RST();
	}else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RST();
	}else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RST();
	}else if(pGPIOx == GPIOI)
	{
		GPIOI_REG_RST();
	}else if(pGPIOx == GPIOJ)
	{
		GPIOJ_REG_RST();
	}else if(pGPIOx == GPIOK)
	{
		GPIOK_REG_RST();
	}
}


void GPIO_Write_Output_Pin(GPIO_RegMap_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//write 1 to ODR at the bit field corresponding to the output pin
		pGPIOx->ODR |= (1 << PinNumber);
	} else
	{
		//write 0 to ODR at the bit field corresponding to the output pin
		pGPIOx->ODR &= ~(1<< PinNumber);
	}
}


void GPIO_Write_Output_Port(GPIO_RegMap_t *pGPIOx, uint8_t Value)
{
	pGPIOx -> ODR |= Value;
}


void GPIO_Toggle_Output_Pin(GPIO_RegMap_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}



uint8_t GPIO_Read_Output_Pin(GPIO_RegMap_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;

	value = (uint8_t)( (pGPIOx->IDR >> PinNumber) & 0x00000001 ); //right shift the interested bit to the least sig bit position and mask the remaining bits and read the final value

	return value;
}



uint16_t GPIO_Read_Output_Port(GPIO_RegMap_t *pGPIOx)
{
	uint16_t value;

	value = (uint16_t) pGPIOx->IDR;

	return value;
}

