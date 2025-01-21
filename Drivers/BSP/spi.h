#ifndef __SPI_H
#define __SPI_H
#include "sys.h"

extern SPI_HandleTypeDef SPI1_Handler;  //SPI句柄

/* SPI1 引脚 定义 */

#define SPI1_SCK_GPIO_PORT              GPIOA
#define SPI1_SCK_GPIO_PIN               GPIO_PIN_5
#define SPI1_SCK_GPIO_CLK_ENABLE()      do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)   

#define SPI1_MISO_GPIO_PORT             GPIOA
#define SPI1_MISO_GPIO_PIN              GPIO_PIN_6
#define SPI1_MISO_GPIO_CLK_ENABLE()     do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)   

#define SPI1_MOSI_GPIO_PORT             GPIOA
#define SPI1_MOSI_GPIO_PIN              GPIO_PIN_7
#define SPI1_MOSI_GPIO_CLK_ENABLE()     do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)   

/* SPI1相关定义 */
#define SPI1_SPI                        SPI1
#define SPI1_SPI_CLK_ENABLE()           do{ __HAL_RCC_SPI1_CLK_ENABLE(); }while(0)    


void SPI1_Init(void);
void SPI1_SetSpeed(u8 SPI_BaudRatePrescaler);
u8 SPI1_ReadWriteByte(u8 TxData);
#endif
