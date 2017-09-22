/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/

#include "main.h"
#include "Configuration.h"

/**************************************************************************************
��������SPI2_Configuration
������������SPI2
���롡����
���������
���ء�����
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
	/*PI1,PI2,PI3��©���ù���*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOI, &GPIO_InitStructure);
	
	/* SPI2configuration */ 
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;   //SPI����Ϊ˫�ߵ������
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;					   //���豸����
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;				  //16Ϊ���ݳ���
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;  //����ʱSCKΪ�͵�ƽ   CPOL=0
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; //���ݲ����ӵ�һ��ʱ�ӱ��ؿ�ʼ	   CPHA=0
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;	   //������豸����ʹ�ܣ�NSS�������뱻CR1��SSIλ�е�ֵ���
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;   //APB1ʱ��30M ,2��Ƶ15
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   //�ȷ��͸�λ
	SPI_InitStructure.SPI_CRCPolynomial = 7;							  //����ʽΪ7				  //����ʽΪ7
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




