#ifndef __BSP_74HC595_H
#define __BSP_74HC595_H

#include "stm32f10x.h"

typedef struct
{
	uint16_t SHCP_GPIO_PIN;
	GPIO_TypeDef* SHCP_GPIO_PORT;
	uint32_t SHCP_GPIO_CLK;
	
	uint16_t STCP_GPIO_PIN;
	GPIO_TypeDef* STCP_GPIO_PORT;
	uint32_t STCP_GPIO_CLK;
	
	uint16_t OE_GPIO_PIN;
	GPIO_TypeDef* OE_GPIO_PORT;
	uint32_t OE_GPIO_CLK;
	
	uint16_t DS_GPIO_PIN;
	GPIO_TypeDef* DS_GPIO_PORT;
	uint32_t DS_GPIO_CLK;
}HC595_InitTypeDef;

void HC595_Init(HC595_InitTypeDef* HC595_InitStruct);
void HC595_WriteData(HC595_InitTypeDef* HC595_InitStruct, unsigned char Data);
void HC595_WriteBuff(HC595_InitTypeDef* HC595_InitStruct);
void HC595_OutputCmd(HC595_InitTypeDef* HC595_InitStruct, FunctionalState NewState);

#endif
