/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/


#include "main.h"
#include "Configuration.h"

/**************************************************************************************
��������SPI1_Configuration
������������SPI1
���롡����
���������
���ء�����
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
       /*PA5,PA6,PA7��©���ù���*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
 
 
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;   //SPI����Ϊ˫�ߵ������
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					   //���豸����
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  //16Ϊ���ݳ���
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;  //����ʱSCKΪ�͵�ƽ   CPOL=0
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; //���ݲ����ӵ�һ��ʱ�ӱ��ؿ�ʼ	   CPHA=0
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	   //������豸����ʹ�ܣ�NSS�������뱻CR1��SSIλ�е�ֵ���
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;   //APB1ʱ��30M ,2��Ƶ15M
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   //�ȷ��͸�λ
  SPI_InitStructure.SPI_CRCPolynomial = 7;					  //����ʽΪ7
  SPI_Init(SPI1, &SPI_InitStructure);
  
  
  /* Enable SPI1  */
  SPI_Cmd(SPI1, ENABLE);   							  //ʹ��SPI1
 
  
}

/**************************************************************************************
��������SPI1_SendByte
��������SPI1����
���롡����
���������
���ء�����
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
