/*
 * ledButton.c
*  Author: MohaN
 */

#include "stm32f407xx.h"
#include "stm32f407_gpio_drivers.h"


#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void)
{
	for(uint32_t i = 0; i<=500000/2;i++);

}


int main(void)
{
	GPIO_Handle_t GpioLed,GpioBtn;

	//led configuration
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPd = GPIO_NO_PUPD;

	GPIO_PeriClkCntrl(GPIOD, ENABLE);
	GPIO_InIt(&GpioLed);

	//button configuration
	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPd = GPIO_NO_PUPD;

	GPIO_PeriClkCntrl(GPIOA, ENABLE);
	GPIO_InIt(&GpioBtn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == BTN_PRESSED )
		{
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 1);

		}
		else
		{
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);

		}

	}



	return 0;
}

