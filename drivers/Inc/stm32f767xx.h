/**
 ******************************************************************************
 * @file           : stm32f767xx.h
 * @author         : Deepak Reddy
 * @brief          : MCU specific header file
 ******************************************************************************
 * @attention
 ******************************************************************************/



#ifndef INC_STM32F767XX_H_
#define INC_STM32F767XX_H_

#include <stdint.h>

/******************************************************************************
							GENERAL PURPOSE MACROS
 *******************************************************************************/
#define __vo				volatile

#define ENABLE				1
#define DISABLE				0

#define SET					ENABLE
#define RESET				DISABLE



 /******************************************************************************
							STORAGE MEMORY ADDRESSES
 *******************************************************************************/
#define SRAM1_BASE_ADDR							0x20020000U
#define SRAM2_BASE_ADDR							0x2007C000U
#define FLASH_MEM_BASE_ADDR						0X08000000U
#define ROM_BASE_ADDR							0x00100000U		/*Aka - system memory*/


 /******************************************************************************
						AHB1 PERIPHERALS BASES ADDRESSES
 *******************************************************************************/
#define GPIOA_BASE_ADDR							0x40020000U
#define GPIOB_BASE_ADDR							0x40020400U
#define GPIOC_BASE_ADDR							0x40020800U
#define GPIOD_BASE_ADDR							0x40020C00U
#define GPIOE_BASE_ADDR							0x40021000U
#define GPIOF_BASE_ADDR							0x40021400U
#define GPIOG_BASE_ADDR							0x40021800U
#define GPIOH_BASE_ADDR							0x40021C00U
#define GPIOI_BASE_ADDR							0x40022000U
#define GPIOJ_BASE_ADDR							0x40022400U
#define GPIOK_BASE_ADDR							0x40022800U

/*@RCC Register*/
#define RCC_BASE_ADDR							0x40023800U


 /******************************************************************************
						APB2 PERIPHERALS BASES ADDRESSES
 *******************************************************************************/
#define USART1_BASE_ADDR						0x40011000U
#define USART6_BASE_ADDR						0x40011400U

#define ADC_BASE_ADDR							0x40012000U

#define SPI1_BASE_ADDR							0x40013000U
#define SPI4_BASE_ADDR							0x40013400U

#define SYSCFG_BASE_ADDR						0x40013800U

#define EXTI_BASE_ADDR							0x40013C00U

#define SPI5_BASE_ADDR							0x40015000U
#define SPI6_BASE_ADDR							0x40015400U



/******************************************************************************
						APB1 PERIPHERALS BASES ADDRESSES
*******************************************************************************/
#define SPI2_BASE_ADDR							0x40003800U
#define SPI3_BASE_ADDR							0x40003C00U

#define USART2_BASE_ADDR						0x40004400U
#define USART3_BASE_ADDR						0x40004800U

#define UART4_BASE_ADDR							0x40004C00U
#define UART5_BASE_ADDR							0x40005000U

#define I2C1_BASE_ADDR							0x40005400U
#define I2C2_BASE_ADDR							0x40005800U
#define I2C3_BASE_ADDR							0x40005C00U
#define I2C4_BASE_ADDR							0x40006000U



/******************************************************************************
							RCC REGISTER MAP
*******************************************************************************/
typedef struct
{
	__vo uint32_t CR;					/*	RCC clock control register */
	__vo uint32_t PLLCFGR;				/*	RCC PLL configuration register */
	__vo uint32_t CFGR;					/*	RCC clock configuration register */
	__vo uint32_t CIR;					/*	RCC clock interrupt register */
	__vo uint32_t AHB1RSTR;				/*	RCC AHB1 peripheral reset register */
	__vo uint32_t AHB2RSTR;				/*	RCC AHB2 peripheral reset register */
	__vo uint32_t AHB3RSTR;				/*	RCC AHB3 peripheral reset register */
	uint32_t RESERVED00;				/*	Reserved */
	__vo uint32_t APB1RSTR;				/*	RCC APB1 peripheral reset register */
	__vo uint32_t APB2RSTR;				/*	RCC APB2 peripheral reset register */
	uint32_t RESERVED01;				/*	Reserved */
	uint32_t RESERVED02;				/*	Reserved */
	__vo uint32_t AHB1ENR;				/*	RCC AHB1 peripheral clock register */
	__vo uint32_t AHB2ENR;				/*	RCC AHB2 peripheral clock register */
	__vo uint32_t AHB3ENR;				/*	RCC AHB3 peripheral clock register */
	uint32_t RESERVED03;				/*	Reserved */
	__vo uint32_t APB1ENR;				/*	RCC APB1 peripheral clock enable register */
	__vo uint32_t APB2ENR;				/*	RCC APB2 peripheral clock enable register */
	uint32_t RESERVED04;				/*	Reserved */
	uint32_t RESERVED05;				/*	Reserved */
	__vo uint32_t AHB1LPENR;			/*	RCC AHB1 peripheral clock enable in low-power mode register */
	__vo uint32_t AHB2LPENR;			/*	RCC AHB2 peripheral clock enable in low-power mode register */
	__vo uint32_t AHB3LPENR;			/*	RCC AHB3 peripheral clock enable in low-power mode register */
	uint32_t RESERVED06;				/*	Reserved */
	__vo uint32_t APB1LPENR;			/*	RCC APB1 peripheral clock enable in low-power mode register */
	__vo uint32_t APB2LPENR;			/*	RCC APB2 peripheral clock enable in low-power mode register */
	uint32_t RESERVED07;				/*	Reserved */
	uint32_t RESERVED08;				/*	Reserved */
	__vo uint32_t BDCR;					/*	RCC backup domain control register */
	__vo uint32_t CSR;					/*	RCC clock control & status register */
	uint32_t RESERVED09;				/*	Reserved */
	uint32_t RESERVED10;				/*	Reserved */
	__vo uint32_t SSCGR;				/*	RCC spread spectrum clock generation register */
	__vo uint32_t PLLI2SCFGR;			/*	RCC PLLI2S configuration register */
	__vo uint32_t PLLSAICFGR;			/*	RCC PLLSAI configuration register */
	__vo uint32_t DCKCFGR1;				/*	RCC dedicated clocks configuration register */
	__vo uint32_t DCKCFGR2;				/*	RCC dedicated clocks configuration register */
}RCC_RegMap_t;

#define RCC								( (RCC_RegMap_t *)RCC_BASE_ADDR )

/******************************************************************************
								GPIO REGISTER MAP
*******************************************************************************/

typedef struct
{
	__vo uint32_t MODER;				/*	GPIO port mode register */
	__vo uint32_t OTYPER;				/*	GPIO port output type register */
	__vo uint32_t OSPEEDR;				/*	GPIO port output speed register */
	__vo uint32_t PUPDR;				/*	GPIO port pull-up/pull-down register */
	__vo uint32_t IDR;					/*	GPIO port input data register */
	__vo uint32_t ODR;					/*	GPIO port output data register */
	__vo uint32_t BSRR;					/*	GPIO port bit set/reset register */
	__vo uint32_t LCKR;					/*	GPIO port configuration lock register */
	__vo uint32_t AFRL;					/*	GPIO alternate function low register */
	__vo uint32_t AFRH;					/*	GPIO alternate function high register */
}GPIO_RegMap_t;


/******************************************************************************
								ENABLE GPIO PORTS
*******************************************************************************/

#define GPIOA_CLK_EN()					( RCC->AHB1ENR |= (1<<0) )
#define GPIOB_CLK_EN()					( RCC->AHB1ENR |= (1<<1) )
#define GPIOC_CLK_EN()					( RCC->AHB1ENR |= (1<<2) )
#define GPIOD_CLK_EN()					( RCC->AHB1ENR |= (1<<3) )
#define GPIOE_CLK_EN()					( RCC->AHB1ENR |= (1<<4) )
#define GPIOF_CLK_EN()					( RCC->AHB1ENR |= (1<<5) )
#define GPIOG_CLK_EN()					( RCC->AHB1ENR |= (1<<6) )
#define GPIOH_CLK_EN()					( RCC->AHB1ENR |= (1<<7) )
#define GPIOI_CLK_EN()					( RCC->AHB1ENR |= (1<<8) )
#define GPIOJ_CLK_EN()					( RCC->AHB1ENR |= (1<<9) )
#define GPIOK_CLK_EN()					( RCC->AHB1ENR |= (1<<10))



/******************************************************************************
								DISABLE GPIO PORTS
*******************************************************************************/

#define GPIOA_CLK_DI()					( RCC->AHB1ENR &= ~(1<<0) )
#define GPIOB_CLK_DI()					( RCC->AHB1ENR &= ~(1<<1) )
#define GPIOC_CLK_DI()					( RCC->AHB1ENR &= ~(1<<2) )
#define GPIOD_CLK_DI()					( RCC->AHB1ENR &= ~(1<<3) )
#define GPIOE_CLK_DI()					( RCC->AHB1ENR &= ~(1<<4) )
#define GPIOF_CLK_DI()					( RCC->AHB1ENR &= ~(1<<5) )
#define GPIOG_CLK_DI()					( RCC->AHB1ENR &= ~(1<<6) )
#define GPIOH_CLK_DI()					( RCC->AHB1ENR &= ~(1<<7) )
#define GPIOI_CLK_DI()					( RCC->AHB1ENR &= ~(1<<8) )
#define GPIOJ_CLK_DI()					( RCC->AHB1ENR &= ~(1<<9) )
#define GPIOK_CLK_DI()					( RCC->AHB1ENR &= ~(1<<10))


/******************************************************************************
								DISABLE PORTS
 *******************************************************************************/

#define GPIOA_REG_RST()							do{( RCC->AHB1RSTR |= (1<<0) );  ( RCC->AHB1RSTR &= ~(1<<0) );}while(0);
#define GPIOB_REG_RST()							do{( RCC->AHB1RSTR |= (1<<1) );  ( RCC->AHB1RSTR &= ~(1<<1) );}while(0);
#define GPIOC_REG_RST()							do{( RCC->AHB1RSTR |= (1<<2) );  ( RCC->AHB1RSTR &= ~(1<<2) );}while(0);
#define GPIOD_REG_RST()							do{( RCC->AHB1RSTR |= (1<<3) );  ( RCC->AHB1RSTR &= ~(1<<3) );}while(0);
#define GPIOE_REG_RST()							do{( RCC->AHB1RSTR |= (1<<4) );  ( RCC->AHB1RSTR &= ~(1<<4) );}while(0);
#define GPIOF_REG_RST()							do{( RCC->AHB1RSTR |= (1<<5) );  ( RCC->AHB1RSTR &= ~(1<<5) );}while(0);
#define GPIOG_REG_RST()							do{( RCC->AHB1RSTR |= (1<<6) );  ( RCC->AHB1RSTR &= ~(1<<6) );}while(0);
#define GPIOH_REG_RST()							do{( RCC->AHB1RSTR |= (1<<7) );  ( RCC->AHB1RSTR &= ~(1<<7) );}while(0);
#define GPIOI_REG_RST()							do{( RCC->AHB1RSTR |= (1<<8) );  ( RCC->AHB1RSTR &= ~(1<<8) );}while(0);
#define GPIOJ_REG_RST()							do{( RCC->AHB1RSTR |= (1<<9) );  ( RCC->AHB1RSTR &= ~(1<<9) );}while(0);
#define GPIOK_REG_RST()							do{( RCC->AHB1RSTR |= (1<<10) );  ( RCC->AHB1RSTR &= ~(1<<10) );}while(0);

#endif /* INC_STM32F767XX_H_ */
