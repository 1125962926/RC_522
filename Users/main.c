#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "oled.h"
#include "rc522.h"

//要写入的数据
uint8_t Write_Card_Data[16]={0};

int main(void)
{
    HAL_Init();                    	 			    
	delay_init(72);
    Stm32_Clock_Init(RCC_PLL_MUL9);   			
	led_init();
	key_init();
	uart_init(115200);
	OLED_Init();

    RC522_Init();
	uint8_t key;

	while(1)
	{
		key = key_scan();
		if(key==1)
		{
			RC522_Start(5,readID,Write_Card_Data);
		}
		else if(key==2)
		{
			RC522_Start(5,writeID,Write_Card_Data);
		}
		delay_ms(100);
		LED0=!LED0;
	}
}
