#include "stm32f10x.h"
#include "bsp_74ch595.h"
#include "led.h"

void Delayms(u16 ms)
{
  u16 i,j;
  u8 k;
  for(i=0;i<ms;i++)
    for(j=0;j<0x0500;j++) k++;
}

int main()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	int test,min = 50;
	
	LED_Config();
	LED_OutputCmd(ENABLE);
	while(1)
	{
		for(test=60;test>=0;test--)
		{
			LED_WriteData(min, test);
			Delayms(1000);
		}
		if(min==0)
			break;
		min--;
	}
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	while(1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		Delayms(10);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		Delayms(10);
	}
}
