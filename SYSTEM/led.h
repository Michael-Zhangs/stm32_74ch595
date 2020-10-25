#ifndef __LED_H
#define __LED_H

#include "bsp_74ch595.h"

#define LED_DS_GPIO_PORT			GPIOA
#define LED_DS_GPIO_CLK				RCC_APB2Periph_GPIOA
#define LED_DS_GPIO_PIN				GPIO_Pin_0

#define LED_STCP_GPIO_PORT		GPIOC
#define LED_STCP_GPIO_CLK			RCC_APB2Periph_GPIOC
#define LED_STCP_GPIO_PIN			GPIO_Pin_14

#define LED_SHCP_GPIO_PORT		GPIOC
#define LED_SHCP_GPIO_CLK			RCC_APB2Periph_GPIOC
#define LED_SHCP_GPIO_PIN			GPIO_Pin_13

#define LED_OE_GPIO_PORT			GPIOC
#define LED_OE_GPIO_CLK				RCC_APB2Periph_GPIOC
#define LED_OE_GPIO_PIN				GPIO_Pin_15

void LED_Config(void);
void LED_WriteData(unsigned char RED, unsigned char BLUE);
void LED_OutputCmd(FunctionalState NewState);

#endif
