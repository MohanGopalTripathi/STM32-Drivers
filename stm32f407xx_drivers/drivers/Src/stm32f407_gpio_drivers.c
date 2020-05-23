/*
 * stm32f407_dpio_drivers.c
 *
 *  Created on: 15-Apr-2020
 *      Author: MohaNeha
 */


#include"stm32f407_gpio_drivers.h"


/************************************************************************************************************
 ************************************************************************************************************
 * Peripheral clock control
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_PeriClkCntrl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_PeriClkCntrl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		else if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		else if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
		else if(pGPIOx == GPIOI)
		{
			GPIOI_PCLK_DI();
		}
	}


}


/************************************************************************************************************
 ************************************************************************************************************
 * GPIO initialize
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_InIt
 *
 * @brief             - This function initialize the GPIO
 *
 * @param[in]         -
 * @return            -  none
 *
 * @Note              -  none

 */

void GPIO_InIt(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0; //temporary register

	//1. configuring GPIO pin mode

	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//this is non interrupt mode see macro for GPIO Mode anything less than ANalog 0r 3 is non interrupt
		temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle ->pGPIOx ->MODER &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);  //clearing
		pGPIOHandle ->pGPIOx ->MODER |= temp;
	}
	else
	{
		if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_FT)
		{
			//1. Configure FTSR (falling trigger selection register)
			EXTI ->FTSR |= (1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);
			// clear the corresponding RTSR bit
			EXTI ->RTSR &= ~(1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);

		}
		else if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_IT_RT)
		{
			//1. Configure RTSR (rising trigger selection register)
			EXTI ->RTSR |= (1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);
			// clear the corresponding RTSR bit
			EXTI ->FTSR &= ~(1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);
		}

		else if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_RFT)
		{
			//1. Configure both RTSR and FTSR
			EXTI ->FTSR |= (1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);
			EXTI ->RTSR |= (1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);


		}

		//2. configure SYSCFG_EXTICR for selecting GPIO port

		//3. enable the EXTI interrupt delivery using IMR (Interrupt mask register)
		EXTI ->IMR |= (1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);




	}

	temp = 0;

	//2. speed

	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle ->pGPIOx ->OSPEEDR &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);  //clearing
	pGPIOHandle ->pGPIOx ->OSPEEDR |= temp;

	temp = 0;


	//3. pull up pull down

	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinPuPd << (2 * pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle ->pGPIOx ->PUPDR &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);  //clearing
	pGPIOHandle ->pGPIOx ->PUPDR |= temp;

	temp = 0;


	//4. output type

	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle ->pGPIOx ->OTYPER &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);  //clearing
	pGPIOHandle ->pGPIOx ->OTYPER |= temp;

	temp = 0;

	//5. alternate functionality

	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFUNC)
	{
		uint8_t temp1, temp2;

		temp1 = pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle ->pGPIOx ->AFR[temp1] &= ~(0xF << (4 * temp2)); //clearing
		pGPIOHandle ->pGPIOx ->AFR[temp1] |= pGPIOHandle ->GPIO_PinConfig.GPIO_PinAltFnMode << (4 * temp2);


	}

}


/************************************************************************************************************
 ************************************************************************************************************
 * GPIO de-initialize
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_DeInIt
 *
 * @brief             - This function initialize the GPIO
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */


void GPIO_DeInIt(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	else if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	else if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
	else if(pGPIOx == GPIOI)
	{
		GPIOI_REG_RESET();
	}


}



/************************************************************************************************************
 ************************************************************************************************************
 * GPIO Read Pin
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_ReadFromInputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -  0 or 1
 *
 * @Note              -  none

 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber ) & 0x00000001);
	return value;

}

/************************************************************************************************************
 ************************************************************************************************************
 * GPIO Read Port
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_ReadFromInputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  none

 */


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;

}


/************************************************************************************************************
 ************************************************************************************************************
 * GPIO Write Pin
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_WriteToIOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  none

 */


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		//write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx ->ODR |= (1 << PinNumber);
	}
	else
	{
		//write 0
		pGPIOx ->ODR &= ~(1 << PinNumber);
	}

}



/************************************************************************************************************
 ************************************************************************************************************
 * GPIO Write Port
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_WriteToOutputPort
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  none

 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx ->ODR = Value;

}

/************************************************************************************************************
 ************************************************************************************************************
 * GPIO Toggle Output
 ************************************************************************************************************
 ***********************************************************************************************************/
/*
 * @fn      		  - GPIO_ToggleOutputPin
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -  none

 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx ->ODR ^= (1 << PinNumber);

}




/*
 * Interrupt configuration and IRQ handler
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}


void GPIO_IRQHandler(uint8_t PinNumber)
{

}
