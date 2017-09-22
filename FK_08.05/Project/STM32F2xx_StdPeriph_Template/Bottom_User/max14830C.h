#ifndef __MAX14830C__H__
#define __MAX14830C__H__

/*
 MAX_RST3  PF6
 MAX_IRQ3  PF7
 MAX_CS3   PF8	
*/

#define MAX14830C_CS_LOW 	GPIOF->BSRRH = GPIO_Pin_8    //片选信号线输出低电平
#define MAX14830C_CS_HIGH	GPIOF->BSRRL = GPIO_Pin_8		//输出高电平

#define MAX14830C_RSTN_LOW   GPIOF->BSRRH = GPIO_Pin_6  //置低
#define MAX14830C_RSTN_HIGH  GPIOF->BSRRL = GPIO_Pin_6  //置高

#define MAX14830C_IRQ			(GPIOF->IDR & GPIO_Pin_7)




#define MAX14830C_SendByte(x)      SPI3_SendByte((x))  //SPI操作函数
#define MAX14830C_SPI_init      SPI3_Configuration  //SPI配置


u8 initMax14830C(void);
void Max14830CSendDat(u8 num_uart, u8 d);
u8 Max14830CRcvDat(u8 num_uart);
u8 Max14830CRFIFOCnt(u8 num_uart);
u8 Max14830CReadIRQ(void);
u8 Max14830CReadISR(u8 num_uart);

extern void  Max14830CRcvFifo(u8 num_uart, u8 *buf, u8 size);



extern u8 Max14830C_RBuf[4][Max14830_RBufLen];  //串口接收环形缓冲区
extern u8 Max14830C_RPi[4];   //串口接收环形缓冲区入口指针
extern u8 Max14830C_RPo[4];   //串口接收环形缓冲区出口指针

#endif

