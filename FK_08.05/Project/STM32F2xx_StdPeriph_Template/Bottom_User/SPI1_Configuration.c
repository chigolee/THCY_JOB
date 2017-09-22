/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/


#include "main.h"
#include "Configuration.h"

/**************************************************************************************
函数名：SPI1_Configuration
描述　：配置SPI1
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void SPI1_Configuration(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
   
  /* Enable SPI1 and GPIOA clocks */
  /* Enable SPI1 and GPIOA clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	/* Configure SPI1 pins: NSS, SCK, MISO and MOSI */
       /*PA5,PA6,PA7开漏复用功能*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
 
 
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;   //SPI设置为双线单向接收
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					   //主设备配置
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  //16为数据长度
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;  //空闲时SCK为低电平   CPOL=0
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; //数据采样从第一个时钟边沿开始	   CPHA=0
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	   //软件从设备管理使能，NSS引脚输入被CR1中SSI位中的值替代
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;   //APB1时钟30M ,2分频15M
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   //先发送高位
  SPI_InitStructure.SPI_CRCPolynomial = 7;					  //多项式为7
  SPI_Init(SPI1, &SPI_InitStructure);
  
  
  /* Enable SPI1  */
  SPI_Cmd(SPI1, ENABLE);   							  //使能SPI1
 
  
}

/**************************************************************************************
函数名：SPI1_SendByte
描述　：SPI1发送
输入　：无
输出　：无
返回　：无
**************************************************************************************/
u8 SPI1_SendByte(u8 byte)
{
	/* Loop while DR register in not emplty */   
	while((SPI1->SR & 0x02) == 0);
	/* Send byte through the SPI2 peripheral */
	SPI1->DR = byte;
	/* Wait to receive a byte */
	while((SPI1->SR & 0x01) == 0);	
	/* Return the byte read from the SPI bus */
	return (SPI1->DR);
}
