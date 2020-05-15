/*
 * stm32f407xx.h
 *
 *  Created on: Mar 29, 2020
 *  Author: MohaN
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include<stdint.h>

#define __vo volatile


/*
 * base addresses of flash and SRAM
 */

#define FLASH_BASE_ADRR 				0x08000000U      	//U is used after the base address to inform the compiler that the given value or address is unsigned
                                                 	 	 	// by default compiler assumes the value as signed
#define SRAM1_BASE_ADRR 				0x20000000U			//112KB of SRAM1
#define SRAM2_BASE_ADRR 				0x20001C00U			//16KB of SRAM2
#define ROM_BASE_ADRR 					0x1FFF0000U	 		//system memory
#define SRAM          					SRAM1_BASE_ADRR

#define RCC_BASE_ADRR					(AHB1PERIPH_ADRR + 0x3800)


/*
 * Peripheral base address of different buses , APB1&2 and AHB1&2
 */

#define PERIPH_ADRR						0x40000000U
#define APB1PERIPH_ADRR					PERIPH_ADRR
#define APB2PERIPH_ADRR					0x40010000U
#define AHB1PERIPH_ADRR 				0x40020000U
#define AHB2PERIPH_ADRR 				0x50000000U


/*
 * base address of the peripherals on AHB1 bus
 */

// all the peripherals can be given the address but i am mentioning the one i use

// GPIO's A to I

#define GPIOA_BASE_ADRR					(AHB1PERIPH_ADRR + 0x0000)
#define GPIOB_BASE_ADRR					(AHB1PERIPH_ADRR + 0x0400)
#define GPIOC_BASE_ADRR					(AHB1PERIPH_ADRR + 0x0800)
#define GPIOD_BASE_ADRR					(AHB1PERIPH_ADRR + 0x0C00)
#define GPIOE_BASE_ADRR					(AHB1PERIPH_ADRR + 0x1000)
#define GPIOF_BASE_ADRR					(AHB1PERIPH_ADRR + 0x1400)
#define GPIOG_BASE_ADRR					(AHB1PERIPH_ADRR + 0x1800)
#define GPIOH_BASE_ADRR					(AHB1PERIPH_ADRR + 0x1C00)
#define GPIOI_BASE_ADRR					(AHB1PERIPH_ADRR + 0x2000)


/*
 * base address of the peripherals on APB1 bus
 */

// all the peripherals can be given the address but i am mentioning the one i use

// I2C

#define I2C1_BASE_ADRR 					 (APB1PERIPH_ADRR + 0x5400)
#define I2C2_BASE_ADRR 					 (APB1PERIPH_ADRR + 0x5800)
#define I2C3_BASE_ADRR 					 (APB1PERIPH_ADRR + 0x5C00)


//SPI

#define SPI2_BASE_ADRR 					 (APB1PERIPH_ADRR + 0x3800)				//SPI1 is on APB2 bus
#define SPI3_BASE_ADRR 					 (APB1PERIPH_ADRR + 0x3C00)


//USART

#define USART2_BASE_ADRR 				  (APB1PERIPH_ADRR + 0x4400)			//USART1 is on APB2 bus
#define USART3_BASE_ADRR 				  (APB1PERIPH_ADRR + 0x4800)
#define UART4_BASE_ADRR 				  (APB1PERIPH_ADRR + 0x4C00)
#define UART5_BASE_ADRR 				  (APB1PERIPH_ADRR + 0x5000)


/*
 * base address of the peripherals on APB2 bus
 */

// all the peripherals can be given the address but i am mentioning the one i use


//SPI

#define SPI1_BASE_ADRR 					 (APB2PERIPH_ADRR + 0x3000)


//USART

#define USART1_BASE_ADRR 				  (APB2PERIPH_ADRR + 0x1000)
#define USART6_BASE_ADRR 				  (APB2PERIPH_ADRR + 0x1400)

//EXTI

#define EXTI_BASE_ADRR 				  	  (APB2PERIPH_ADRR + 0x3C00)


//SYSCFG

#define SYSCFG_BASE_ADRR 				  (APB2PERIPH_ADRR + 0x3800)



/*
 * Peripheral register definition structure for GPIO
 */

typedef struct
{

	__vo uint32_t MODER;                            //GPIO port mode register               			Address Offset : 0x00
	__vo uint32_t OTYPER;						    //GPIO port output type register					Address Offset : 0x04
	__vo uint32_t OSPEEDR;							//GPIO port output speed register					Address Offset : 0x08
	__vo uint32_t PUPDR;							//GPIO port pull-up/pull-down register				Address Offset : 0x0C
	__vo uint32_t IDR;								//GPIO port input data register						Address Offset : 0x10
	__vo uint32_t ODR;								//GPIO port output data register					Address Offset : 0x14
	__vo uint32_t BSRR;								//GPIO port bit set/reset register					Address Offset : 0x18
	__vo uint32_t LCKR;								//GPIO port configuration lock register				Address Offset : 0x1C
	__vo uint32_t AFR[2];							//GPIO port configuration low register(AFR[1])		Address Offset : 0x20
													//GPIO alternate function high register(AFR[2])     Address Offset : 0x24
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;								//RCC clock control register		Address offset: 0x00
	__vo uint32_t PLLCFGR;							//RCC PLL configuration register	Address offset: 0x04
	__vo uint32_t CFGR;								//RCC clock configuration register	Address offset: 0x08
	__vo uint32_t CIR;								//RCC clock interrupt register		Address offset: 0x0C
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t RESERVED1;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED2;
	uint32_t RESERVED3;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t RESERVED4;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED5;
	uint32_t RESERVED6;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t RESERVED7;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED8;
	uint32_t RESERVED9;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED10;
	uint32_t RESERVED11;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;


}RCC_RegDef_t;


/*
 * peripheral definitions (peripheral base address type casted)
 */

#define GPIOA				( (GPIO_RegDef_t*)GPIOA_BASE_ADRR)
#define GPIOB				( (GPIO_RegDef_t*)GPIOB_BASE_ADRR)
#define GPIOC				( (GPIO_RegDef_t*)GPIOC_BASE_ADRR)
#define GPIOD				( (GPIO_RegDef_t*)GPIOD_BASE_ADRR)
#define GPIOE				( (GPIO_RegDef_t*)GPIOE_BASE_ADRR)
#define GPIOF				( (GPIO_RegDef_t*)GPIOF_BASE_ADRR)
#define GPIOG				( (GPIO_RegDef_t*)GPIOG_BASE_ADRR)
#define GPIOH				( (GPIO_RegDef_t*)GPIOH_BASE_ADRR)
#define GPIOI				( (GPIO_RegDef_t*)GPIOI_BASE_ADRR)


#define RCC 				( (RCC_RegDef_t*)RCC_BASE_ADRR)

/*
 * Clock enable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()			( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()			( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()			( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()			( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()			( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()			( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()			( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()			( RCC->AHB1ENR |= (1 << 7) )
#define GPIOI_PCLK_EN()			( RCC->AHB1ENR |= (1 << 8) )


/*
 * Clock enable macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()			( RCC->APB1ENR |= (1 << 21) )
#define I2C2_PCLK_EN()			( RCC->APB1ENR |= (1 << 22) )
#define I2C3_PCLK_EN()			( RCC->APB1ENR |= (1 << 23) )


/*
 * Clock enable macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()			( RCC->APB2ENR |= (1 << 12) )
#define SPI2_PCLK_EN()			( RCC->APB1ENR |= (1 << 14) )
#define SPI3_PCLK_EN()			( RCC->APB1ENR |= (1 << 15) )

/*
 * Clock enable macros for USARTx peripherals
 */

#define USART1_PCLK_EN()			( RCC->APB2ENR |= (1 << 4) )
#define USART2_PCLK_EN()			( RCC->APB1ENR |= (1 << 17) )
#define USART3_PCLK_EN()			( RCC->APB1ENR |= (1 << 18) )
#define UART4_PCLK_EN()				( RCC->APB1ENR |= (1 << 19) )
#define UART5_PCLK_EN()				( RCC->APB1ENR |= (1 << 20) )
#define USART6_PCLK_EN()			( RCC->APB2ENR |= (1 << 5) )

/*
 * Clock enable macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN()			( RCC->APB2ENR |= (1 << 14) )


/*
 * Clock disable macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 0) )
#define GPIOB_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 1) )
#define GPIOC_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 2) )
#define GPIOD_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 3) )
#define GPIOE_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 4) )
#define GPIOF_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 5) )
#define GPIOG_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 6) )
#define GPIOH_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 7) )
#define GPIOI_PCLK_DI()			( RCC->AHB1ENR &= ~(1 << 8) )


/*
 * Clock disable macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 21) )
#define I2C2_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 22) )
#define I2C3_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 23) )


/*
 * Clock disable macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()			( RCC->APB2ENR &= ~(1 << 12) )
#define SPI2_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 14) )
#define SPI3_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 15) )


/*
 * Clock disable macros for USARTx peripherals
 */

#define USART1_PCLK_DI()			( RCC->APB2ENR &= ~(1 << 4) )
#define USART2_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 17) )
#define USART3_PCLK_DI()			( RCC->APB1ENR &= ~(1 << 18) )
#define UART4_PCLK_DI()				( RCC->APB1ENR &= ~(1 << 19) )
#define UART5_PCLK_DI()				( RCC->APB1ENR &= ~(1 << 20) )
#define USART6_PCLK_DI()			( RCC->APB2ENR &= ~(1 << 5) )


/*
 * Clock disable macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()			( RCC->APB2ENR &= ~(1 << 14) )









#endif /* INC_STM32F407XX_H_ */
