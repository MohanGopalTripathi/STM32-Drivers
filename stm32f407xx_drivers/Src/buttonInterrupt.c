/*
 * buttonInterrupt.c
*  Author: MohaN
 */

#include "stm32f407xx.h"
#include "stm32f407_gpio_drivers.h"


#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void)
{
	//200ms of delay ---- 16MHz
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
	GpioBtn.pGPIOx = GPIOD;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	//Interrupt mode with falling edge
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	//pull up configuration
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPd = GPIO_PIN_PU;

	GPIO_PeriClkCntrl(GPIOD, ENABLE);
	GPIO_InIt(&GpioBtn);

	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI9_5, NVIC_IRQ_PRI15 );
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI9_5, ENABLE);





	while(1);
}



void EXTI9_5_IRQHandler(void)
{
	delay();
	GPIO_IRQHandler(GPIO_PIN_NO_5);
	GPIO_ToggleOutputPin(GPIOD,GPIO_PIN_NO_12);



}



