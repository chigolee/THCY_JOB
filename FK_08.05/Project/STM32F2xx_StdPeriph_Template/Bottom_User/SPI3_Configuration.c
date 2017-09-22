/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/

#include "main.h"
#include "Configuration.h"

/**************************************************************************************
��������SPI3_Configuration
������������SPI3
���롡����
���������
���ء�����
**************************************************************************************/
void SPI3_Configuration(void)
{
	SPI_InitTypeDef  SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	

       
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	/* Enable SPI3 and GPIOI clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE);
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI3);
	
	/* Configure SPI3 pins: SCK, MISO and MOSI */
	/*PB3,PB4,PB5��©���ù���*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* SPI3 configuration */ 
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;   //SPI����Ϊ˫�ߵ������
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					   //���豸����
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  //16Ϊ���ݳ���
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;  //����ʱSCKΪ�͵�ƽ   CPOL=0
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; //���ݲ����ӵ�һ��ʱ�ӱ��ؿ�ʼ	   CPHA=0
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	   //������豸����ʹ�ܣ�NSS�������뱻CR1��SSIλ�е�ֵ���
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;   //APB1ʱ��30M ,2��Ƶ15
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   //�ȷ��͸�λ
	SPI_InitStructure.SPI_CRCPolynomial = 7;							  //����ʽΪ7
	SPI_Init(SPI3, &SPI_InitStructure);
	
	/* Enable SPI3  */
	SPI_Cmd(SPI3, ENABLE);  
}

/*******************************************************************************
* Function Name  : SPI3_SendByte
* Description    : Sends a byte through the SPI interface and return the byte 
*                  received from the SPI bus.
* Input          : byte : byte to send.
* Output         : None
* Return         : The value of the received byte.
*******************************************************************************/
u8 SPI3_SendByte(u8 byte)
{
      while((SPI3->SR & 0x02) == 0);
	/* Send byte through the SPI peripheral */
	SPI3->DR = byte;  
	/* Wait to receive a byte */
	while((SPI3->SR & 0x01) == 0);
	/* Return the byte read from the SPI bus */
	return (SPI3->DR);		
}
