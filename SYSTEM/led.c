#include "led.h"

HC595_InitTypeDef HC595_LED_InitStructure;

void LED_Config()
{
	HC595_LED_InitStructure.SHCP_GPIO_CLK = LED_SHCP_GPIO_CLK;
	HC595_LED_InitStructure.SHCP_GPIO_PIN = LED_SHCP_GPIO_PIN;
	HC595_LED_InitStructure.SHCP_GPIO_PORT = LED_SHCP_GPIO_PORT;
	
	HC595_LED_InitStructure.STCP_GPIO_CLK = LED_STCP_GPIO_CLK;
	HC595_LED_InitStructure.STCP_GPIO_PIN = LED_STCP_GPIO_PIN;
	HC595_LED_InitStructure.STCP_GPIO_PORT = LED_STCP_GPIO_PORT;
	
	HC595_LED_InitStructure.OE_GPIO_CLK = LED_OE_GPIO_CLK;
	HC595_LED_InitStructure.OE_GPIO_PIN = LED_OE_GPIO_PIN;
	HC595_LED_InitStructure.OE_GPIO_PORT = LED_OE_GPIO_PORT;
	
	HC595_LED_InitStructure.DS_GPIO_CLK = LED_DS_GPIO_CLK;
	HC595_LED_InitStructure.DS_GPIO_PIN = LED_DS_GPIO_PIN;
	HC595_LED_InitStructure.DS_GPIO_PORT = LED_DS_GPIO_PORT;
	
	HC595_Init(&HC595_LED_InitStructure);
}

void LED_WriteData(unsigned char RED, unsigned char BLUE)
{
	HC595_WriteData(&HC595_LED_InitStructure,BLUE);
	HC595_WriteData(&HC595_LED_InitStructure,RED);
	HC595_WriteBuff(&HC595_LED_InitStructure);
}

void LED_OutputCmd(FunctionalState NewState)
{
	HC595_OutputCmd(&HC595_LED_InitStructure, NewState);
}	
