#include "key.h"

void key_init(void)
{
	GPIO_InitTypeDef GPIO_Initure;
	
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	GPIO_Initure.Pin=GPIO_PIN_0; 				//WK_UP
    GPIO_Initure.Mode=GPIO_MODE_INPUT;  	//推挽输出
    GPIO_Initure.Pull=GPIO_PULLDOWN;          	//下拉
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
	
	GPIO_Initure.Pin=GPIO_PIN_3|GPIO_PIN_4; 				//KEY0,1
    GPIO_Initure.Mode=GPIO_MODE_INPUT;  	//推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          	//上拉
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);

}

u8 key_scan(void)
{
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
	{
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1)
		{
			while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 1);
			HAL_Delay(10);
			return 3;//WK_UP
		}
	}
	else if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
	{
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
		{
			while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0);
			HAL_Delay(10);
			return 1;
		}
	}
	else if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 0)
	{
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 0)
		{
			while(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 0);
			HAL_Delay(10);
			return 2;
		}
	}
	return 0;
}
