#ifndef __RC522_H
#define __RC522_H			  	 
#include "sys.h"




/***************************引脚定义****************************/
/*
RC522SPI引脚,RST和CS可随意更改
RST-PC5
CS-PA4
SCK-PA5
MISO-PA6
MOSI-PA7
*/

//Reset
#define RC522_RST_Pin      GPIO_PIN_5
#define RC522_RST_GPIO_Port     GPIOC
#define RC522_GPIO_Reset_CLK_ENABLE() \
    do { __HAL_RCC_GPIOA_CLK_ENABLE(); } while(0)

//CS片选，模块SDA引脚，SPI通信时用作NSS
#define RC522_GPIO_CS_PIN      GPIO_PIN_4
#define RC522_GPIO_CS_PORT     GPIOA
#define RC522_GPIO_CS_CLK_ENABLE() \
    do { __HAL_RCC_GPIOA_CLK_ENABLE(); } while(0)


	
/***********************RC522 函数宏定义**********************/	
	
#define RC522_Reset_Disable() HAL_GPIO_WritePin(RC522_RST_GPIO_Port, RC522_RST_Pin, GPIO_PIN_SET);
#define RC522_Reset_Enable() HAL_GPIO_WritePin(RC522_RST_GPIO_Port, RC522_RST_Pin, GPIO_PIN_RESET);

#define RC522_CS_Enable() HAL_GPIO_WritePin(RC522_GPIO_CS_PORT, RC522_GPIO_CS_PIN, GPIO_PIN_RESET);
#define RC522_CS_Disable() HAL_GPIO_WritePin(RC522_GPIO_CS_PORT, RC522_GPIO_CS_PIN, GPIO_PIN_SET);

#define readID  1//读
#define writeID 2//写	
	
	
/***************************自定义函数****************************/
void RC522_Init(void);
void RC522_Start(uint8_t block,uint8_t option,uint8_t *Write_Card_Data);
void RC522_SPI_GPIO_Init(void);
	
	
	
	
	
	
	
/***************************RC522指令集****************************/
//MF522命令字
#define PCD_IDLE              0x00               //取消当前命令
#define PCD_AUTHENT           0x0E               //验证密钥
#define PCD_RECEIVE           0x08               //接收数据
#define PCD_TRANSMIT          0x04               //发送数据
#define PCD_TRANSCEIVE        0x0C               //发送并接收数据
#define PCD_RESETPHASE        0x0F               //复位
#define PCD_CALCCRC           0x03               //CRC计算

//Mifare_One卡片命令字
#define PICC_REQIDL           0x26               //寻天线区内未进入休眠状态
#define PICC_REQALL           0x52               //寻天线区内全部卡
#define PICC_ANTICOLL1        0x93               //防冲撞
#define PICC_ANTICOLL2        0x95               //防冲撞
#define PICC_AUTHENT1A        0x60               //验证A密钥
#define PICC_AUTHENT1B        0x61               //验证B密钥
#define PICC_READ             0x30               //读块
#define PICC_WRITE            0xA0               //写块
#define PICC_DECREMENT        0xC0               //扣款
#define PICC_INCREMENT        0xC1               //充值
#define PICC_RESTORE          0xC2               //调块数据到缓冲区
#define PICC_TRANSFER         0xB0               //保存缓冲区中数据
#define PICC_HALT             0x50               //休眠

//MF522 FIFO长度定义
#define DEF_FIFO_LENGTH       64                 //FIFO size=64byte


//MF522寄存器定义
// PAGE 0
#define     RFU00                 0x00
#define     CommandReg            0x01
#define     ComIEnReg             0x02
#define     DivlEnReg             0x03
#define     ComIrqReg             0x04
#define     DivIrqReg             0x05
#define     ErrorReg              0x06
#define     Status1Reg            0x07
#define     Status2Reg            0x08
#define     FIFODataReg           0x09
#define     FIFOLevelReg          0x0A
#define     WaterLevelReg         0x0B
#define     ControlReg            0x0C
#define     BitFramingReg         0x0D
#define     CollReg               0x0E
#define     RFU0F                 0x0F
// PAGE 1
#define     RFU10                 0x10
#define     ModeReg               0x11
#define     TxModeReg             0x12
#define     RxModeReg             0x13
#define     TxControlReg          0x14
#define     TxAutoReg             0x15
#define     TxSelReg              0x16
#define     RxSelReg              0x17
#define     RxThresholdReg        0x18
#define     DemodReg              0x19
#define     RFU1A                 0x1A
#define     RFU1B                 0x1B
#define     MifareReg             0x1C
#define     RFU1D                 0x1D
#define     RFU1E                 0x1E
#define     SerialSpeedReg        0x1F
// PAGE 2
#define     RFU20                 0x20
#define     CRCResultRegM         0x21
#define     CRCResultRegL         0x22
#define     RFU23                 0x23
#define     ModWidthReg           0x24
#define     RFU25                 0x25
#define     RFCfgReg              0x26
#define     GsNReg                0x27
#define     CWGsCfgReg            0x28
#define     ModGsCfgReg           0x29
#define     TModeReg              0x2A
#define     TPrescalerReg         0x2B
#define     TReloadRegH           0x2C
#define     TReloadRegL           0x2D
#define     TCounterValueRegH     0x2E
#define     TCounterValueRegL     0x2F
// PAGE 3
#define     RFU30                 0x30
#define     TestSel1Reg           0x31
#define     TestSel2Reg           0x32
#define     TestPinEnReg          0x33
#define     TestPinValueReg       0x34
#define     TestBusReg            0x35
#define     AutoTestReg           0x36
#define     VersionReg            0x37
#define     AnalogTestReg         0x38
#define     TestDAC1Reg           0x39
#define     TestDAC2Reg           0x3A
#define     TestADCReg            0x3B
#define     RFU3C                 0x3C
#define     RFU3D                 0x3D
#define     RFU3E                 0x3E
#define     RFU3F		  0x3F

//和MF522通讯时返回的错误代码
#define MI_OK                          0
#define MI_NOTAGERR                    1 
#define MI_ERR                         2 

//缓冲数组大小
#define MAXRLEN                       18


/*******************************内部调用函数**************************************/	
char PcdRequest(uint8_t req_code,uint8_t *pTagType);
char PcdAnticoll(uint8_t *pSnr);
char PcdSelect(uint8_t *pSnr);
char PcdAuthState(uint8_t auth_mode,uint8_t addr,uint8_t *pKey,uint8_t *pSnr);
char PcdRead(uint8_t addr,uint8_t *pData);
char PcdWrite(uint8_t addr,uint8_t *pData);
char PcdValue(uint8_t dd_mode,uint8_t addr,uint8_t *pValue);
char PcdBakValue(uint8_t sourceaddr, uint8_t goaladdr);
char PcdHalt(void);
void CalulateCRC(uint8_t *pIndata,uint8_t len,uint8_t *pOutData);
char PcdReset(void);
uint8_t ReadRawRC(uint8_t Address);
void WriteRawRC(uint8_t Address, uint8_t value);
void SetBitMask(uint8_t reg,uint8_t mask);
void ClearBitMask(uint8_t reg,uint8_t mask);
char PcdComMF522(uint8_t Command,uint8_t *pInData,uint8_t InLenByte,uint8_t *pOutData,unsigned int *pOutLenBit);
void PcdAntennaOn(void);
void PcdAntennaOff(void);
void RC522_Config(uint8_t Card_Type);

#endif 

