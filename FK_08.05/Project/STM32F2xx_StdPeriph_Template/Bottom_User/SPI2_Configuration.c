/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/

#include "main.h"
#include "Configuration.h"

/**************************************************************************************
函数名：SPI2_Configuration
描述　：配置SPI2
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void SPI2_Configuration(void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable SPI2 and GPIOI clocks */	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource1, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource2, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOI, GPIO_PinSource3, GPIO_AF_SPI2);
	/* Configure SPI2 pins: SCK, MISO and MOSI */
	/*PI1,PI2,PI3开漏复用功能*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOI, &GPIO_InitStructure);
	
	/* SPI2configuration */ 
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;   //SPI设置为双线单向接收
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					   //主设备配置
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  //16为数据长度
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;  //空闲时SCK为低电平   CPOL=0
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; //数据采样从第一个时钟边沿开始	   CPHA=0
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	   //软件从设备管理使能，NSS引脚输入被CR1中SSI位中的值替代
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;   //APB1时钟30M ,2分频15
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   //先发送高位
	SPI_InitStructure.SPI_CRCPolynomial = 7;							  //多项式为7				  //多项式为7
	SPI_Init(SPI2, &SPI_InitStructure);
	
	/* Enable SPI2  */
	SPI_Cmd(SPI2, ENABLE);   		
	
}

/*******************************************************************************
* Function Name  : SPI2_SendByte
* Description    : Sends a byte through the SPI interface and return the byte 
*                  received from the SPI bus.
* Input          : byte : byte to send.
* Output         : None
* Return         : The value of the received byte.
*******************************************************************************/
u8 SPI2_SendByte(u8 byte)
{
       /* Loop while DR register in not emplty */
      while((SPI2->SR & 0x02) == 0);
	/* Send byte through the SPI peripheral */
	SPI2->DR = byte;  
	/* Wait to receive a byte */
	while((SPI2->SR & 0x01) == 0);
	/* Return the byte read from the SPI bus */
	return (SPI2->DR);	
}




