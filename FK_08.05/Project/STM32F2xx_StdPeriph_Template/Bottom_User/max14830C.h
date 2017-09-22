#ifndef __MAX14830C__H__
#define __MAX14830C__H__

/*
 MAX_RST3  PF6
 MAX_IRQ3  PF7
 MAX_CS3   PF8	
*/

#define MAX14830C_CS_LOW 	GPIOF->BSRRH = GPIO_Pin_8    //Ƭѡ�ź�������͵�ƽ
#define MAX14830C_CS_HIGH	GPIOF->BSRRL = GPIO_Pin_8		//����ߵ�ƽ

#define MAX14830C_RSTN_LOW   GPIOF->BSRRH = GPIO_Pin_6  //�õ�
#define MAX14830C_RSTN_HIGH  GPIOF->BSRRL = GPIO_Pin_6  //�ø�

#define MAX14830C_IRQ			(GPIOF->IDR & GPIO_Pin_7)




#define MAX14830C_SendByte(x)      SPI3_SendByte((x))  //SPI��������
#define MAX14830C_SPI_init      SPI3_Configuration  //SPI����


u8 initMax14830C(void);
void Max14830CSendDat(u8 num_uart, u8 d);
u8 Max14830CRcvDat(u8 num_uart);
u8 Max14830CRFIFOCnt(u8 num_uart);
u8 Max14830CReadIRQ(void);
u8 Max14830CReadISR(u8 num_uart);

extern void  Max14830CRcvFifo(u8 num_uart, u8 *buf, u8 size);



extern u8 Max14830C_RBuf[4][Max14830_RBufLen];  //���ڽ��ջ��λ�����
extern u8 Max14830C_RPi[4];   //���ڽ��ջ��λ��������ָ��
extern u8 Max14830C_RPo[4];   //���ڽ��ջ��λ���������ָ��

#endif

