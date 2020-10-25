#include "bsp_74ch595.h"

void HC595_Init(HC595_InitTypeDef* HC595_InitStruct)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(	HC595_InitStruct->DS_GPIO_CLK|
													HC595_InitStruct->STCP_GPIO_CLK|
													HC595_InitStruct->SHCP_GPIO_CLK|
													HC595_InitStruct->OE_GPIO_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = HC595_InitStruct->DS_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HC595_InitStruct->DS_GPIO_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(HC595_InitStruct->DS_GPIO_PORT, HC595_InitStruct->DS_GPIO_PIN);
	
	GPIO_InitStructure.GPIO_Pin = HC595_InitStruct->STCP_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HC595_InitStruct->STCP_GPIO_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(HC595_InitStruct->STCP_GPIO_PORT, HC595_InitStruct->STCP_GPIO_PIN);
	
	GPIO_InitStructure.GPIO_Pin = HC595_InitStruct->SHCP_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HC595_InitStruct->SHCP_GPIO_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(HC595_InitStruct->SHCP_GPIO_PORT, HC595_InitStruct->SHCP_GPIO_PIN);
	
	GPIO_InitStructure.GPIO_Pin = HC595_InitStruct->OE_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HC595_InitStruct->OE_GPIO_PORT, &GPIO_InitStructure);
	GPIO_SetBits(HC595_InitStruct->OE_GPIO_PORT, HC595_InitStruct->OE_GPIO_PIN);
}

void HC595_WriteData(HC595_InitTypeDef* HC595_InitStruct, unsigned char Data)
{
	int a;
	for(a=0;a<8;a++)
	{
		if(Data & (1 << (7 - a)))
			GPIO_SetBits(HC595_InitStruct->DS_GPIO_PORT, HC595_InitStruct->DS_GPIO_PIN);
		else
			GPIO_ResetBits(HC595_InitStruct->DS_GPIO_PORT, HC595_InitStruct->DS_GPIO_PIN);
		GPIO_SetBits(HC595_InitStruct->SHCP_GPIO_PORT, HC595_InitStruct->SHCP_GPIO_PIN);
		GPIO_ResetBits(HC595_InitStruct->SHCP_GPIO_PORT, HC595_InitStruct->SHCP_GPIO_PIN);
	}
}

void HC595_WriteBuff(HC595_InitTypeDef* HC595_InitStruct)
{
	GPIO_SetBits(HC595_InitStruct->STCP_GPIO_PORT, HC595_InitStruct->STCP_GPIO_PIN);
	GPIO_ResetBits(HC595_InitStruct->STCP_GPIO_PORT, HC595_InitStruct->STCP_GPIO_PIN);
}

void HC595_OutputCmd(HC595_InitTypeDef* HC595_InitStruct, FunctionalState NewState)
{
	if(NewState)
		GPIO_ResetBits(HC595_InitStruct->OE_GPIO_PORT, HC595_InitStruct->OE_GPIO_PIN);
	else
		GPIO_SetBits(HC595_InitStruct->OE_GPIO_PORT, HC595_InitStruct->OE_GPIO_PIN);
}
