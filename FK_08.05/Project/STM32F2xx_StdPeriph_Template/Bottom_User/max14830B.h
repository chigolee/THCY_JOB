#ifndef __MAX14830B__H__
#define __MAX14830B__H__

/*
 MAX_RST1   PA4
 MAX_IRQ1   PC4
 MAX_CS1    PC5
*/

#define MAX14830B_CS_LOW 	GPIOC->BSRRH = GPIO_Pin_5     //Ƭѡ�ź�������͵�ƽ
#define MAX14830B_CS_HIGH	GPIOC->BSRRL = GPIO_Pin_5		//����ߵ�ƽ

#define MAX14830B_RSTN_LOW   GPIOA->BSRRH = GPIO_Pin_4  //�õ�
#define MAX14830B_RSTN_HIGH  GPIOA->BSRRL = GPIO_Pin_4  //�ø�

#define MAX14830B_IRQ			(GPIOC->IDR & GPIO_Pin_4)



#define MAX14830B_SendByte(x)      SPI1_SendByte((x))  //SPI��������
#define MAX14830B_SPI_init      SPI1_Configuration  //SPI����


u8 initMax14830B(void);
void Max14830BSendDat(u8 num_uart, u8 d);
u8 Max14830BRcvDat(u8 num_uart);
u8 Max14830BRFIFOCnt(u8 num_uart);
u8 Max14830BReadIRQ(void);
u8 Max14830BReadISR(u8 num_uart);

extern void  Max14830BRcvFifo(u8 num_uart, u8 *buf, u8 size);

extern u8 Max14830B_RBuf[4][Max14830_RBufLen];  //���ڽ��ջ��λ�����
extern u8 Max14830B_RPi[4];   //���ڽ��ջ��λ��������ָ��
extern u8 Max14830B_RPo[4];   //���ڽ��ջ��λ���������ָ��


#endif

