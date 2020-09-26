/**
 ******************************************************************************
 * @file           : stm32f767xx_hal_gpio.h
 * @author         : Deepak Reddy
 * @brief          : GPIO HAL Header File
 ******************************************************************************
 * @attention
 ******************************************************************************/

#ifndef INC_STM32F767XX_HAL_GPIO_H_
#define INC_STM32F767XX_HAL_GPIO_H_

#include "stm32f767xx.h"


/******************************************************************************
								GPIO PORTS
 *******************************************************************************/

#define GPIOA				(GPIO_RegMap_t *)GPIOA_BASE_ADDR
#define GPIOB				(GPIO_RegMap_t *)GPIOB_BASE_ADDR
#define GPIOC				(GPIO_RegMap_t *)GPIOC_BASE_ADDR
#define GPIOD				(GPIO_RegMap_t *)GPIOD_BASE_ADDR
#define GPIOE				(GPIO_RegMap_t *)GPIOE_BASE_ADDR
#define GPIOF				(GPIO_RegMap_t *)GPIOF_BASE_ADDR
#define GPIOG				(GPIO_RegMap_t *)GPIOG_BASE_ADDR
#define GPIOH				(GPIO_RegMap_t *)GPIOH_BASE_ADDR
#define GPIOI				(GPIO_RegMap_t *)GPIOI_BASE_ADDR
#define GPIOJ				(GPIO_RegMap_t *)GPIOJ_BASE_ADDR
#define GPIOK				(GPIO_RegMap_t *)GPIOK_BASE_ADDR

/******************************************************************************
								GPIO PINS
 *******************************************************************************/

#define GPIO_PIN_1			1
#define GPIO_PIN_2			2
#define GPIO_PIN_3			3
#define GPIO_PIN_4			4
#define GPIO_PIN_5			5
#define GPIO_PIN_6			6
#define GPIO_PIN_7			7
#define GPIO_PIN_8			8
#define GPIO_PIN_9			9
#define GPIO_PIN_10			10
#define GPIO_PIN_11			11
#define GPIO_PIN_12			12
#define GPIO_PIN_13			13
#define GPIO_PIN_14			14
#define GPIO_PIN_15			15



/******************************************************************************
								GPIO MODES
*******************************************************************************/

#define GPIO_MODE_IN				0
#define GPIO_MODE_OUT				1
#define GPIO_MODE_AF				2
#define GPIO_MODE_AN				3


/******************************************************************************
							GPIO OUTPUT TYPE
*******************************************************************************/

#define GPIO_OUT_PUSH_PULL			0
#define GPIO_OUT_OPEN_DRAIN			1


/******************************************************************************
								GPIO SPEEDS
*******************************************************************************/

#define GPIO_SPEED_LOW				0
#define GPIO_SPEED_MEDIUM			1
#define GPIO_SPEED_HIGH				2
#define GPIO_SPEED_FAST				3



/******************************************************************************
								GPIO PULL-UP/PULL-DOWN
*******************************************************************************/

#define GPIO_NO_PU_PD				0
#define GPIO_PULL_UP				1
#define GPIO_PULL_DOWN				2


/******************************************************************************
								GPIO PIN VALUES
 *******************************************************************************/

#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0



/******************************************************************************
						STRUCTURE TO HANDLE GPIO PIN SETTINGS
*******************************************************************************/

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_Out_Type;
	uint8_t GPIO_Out_Speed;
	uint8_t GPIO_PuPd;
	uint8_t GPIO_AF_Mode;

}GPIO_PinConfig_t;

/******************************************************************************
						STRUCTURE TO CONFIG GPIO PORT AND PIN
*******************************************************************************/
typedef struct
{
	GPIO_RegMap_t *pGPIOx;
	GPIO_PinConfig_t pinConfig;

}GPIO_Handle_t;


/******************************************************************************
							SUPPORTED APIs
*******************************************************************************/

void GPIO_Set_PClk(GPIO_RegMap_t *pGPIOx, uint8_t state);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegMap_t *pGPIOx);


void GPIO_Write_Output_Pin(GPIO_RegMap_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_Write_Output_Port(GPIO_RegMap_t *pGPIOx, uint8_t Value);
void GPIO_Toggle_Output_Pin(GPIO_RegMap_t *pGPIOx, uint8_t PinNumber);

uint8_t GPIO_Read_Output_Pin(GPIO_RegMap_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_Read_Output_Port(GPIO_RegMap_t *pGPIOx);



#endif /* INC_STM32F767XX_HAL_GPIO_H_ */
