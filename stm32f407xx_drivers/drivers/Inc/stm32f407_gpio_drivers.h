/*
 * stm32f407_gpio_drivers.h
 *
 *  Created on: 15-Apr-2020
 *  Author: MohaN
 */

#ifndef INC_STM32F407_GPIO_DRIVERS_H_
#define INC_STM32F407_GPIO_DRIVERS_H_


#include"stm32f407xx.h"

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinPuPd;			//pull up and pull down
	uint8_t GPIO_PinAltFnMode;		//alternate functionality


}GPIO_PinConfig_t;


/*
 * Creating Handle Structure
 */

typedef struct
{

	//1. pointer to hold the address of the GPIO peripheral register
	GPIO_RegDef_t *pGPIOx;
	//2. Details of setting of configuring a pin
	GPIO_PinConfig_t GPIO_PinConfig;

}GPIO_Handle_t;


/*
 * API's supported by this driver
 * Prototypes of the API
 */

/*
 * Peripheral clock control
 */

void GPIO_PeriClkCntrl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);


/*
 * GPIO initialize and de-initialize
 */

void GPIO_InIt(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInIt(GPIO_RegDef_t *pGPIOx);

/*
 * GPIO read and write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_TogglrOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * Interrupt configuration and IRQ handler
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandler(uint8_t PinNumber);























#endif /* INC_STM32F407_GPIO_DRIVERS_H_ */
