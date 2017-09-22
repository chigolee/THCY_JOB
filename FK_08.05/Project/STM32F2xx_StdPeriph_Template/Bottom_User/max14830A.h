#ifndef __MAX14830A__H__
#define __MAX14830A__H__

/*
MAX_RST2  PE13
MAX_IRQ2  PE14
MAX_CS2    PE15
*/

#define MAX14830A_CS_LOW 	GPIOE->BSRRH = GPIO_Pin_15     //片选信号线输出低电平
#define MAX14830A_CS_HIGH	GPIOE->BSRRL = GPIO_Pin_15		//输出高电平

#define MAX14830A_RSTN_LOW   GPIOE->BSRRH = GPIO_Pin_13  //置低
#define MAX14830A_RSTN_HIGH  GPIOE->BSRRL = GPIO_Pin_13  //置高

#define MAX14830A_IRQ			(GPIOE->IDR & GPIO_Pin_14)


#define MAX14830_BR_4800	96
#define MAX14830_BR_9600	 48
#define MAX14830_BR_19200	24
#define MAX14830_BR_38400	12
#define MAX14830_BR_57600	8
#define MAX14830_BR_115200 	4


#define MAX14830_REVID   0xB3


#define MAX14830A_SendByte(x)      SPI2_SendByte((x))  //SPI操作函数
#define MAX14830A_SPI_init      SPI2_Configuration  //SPI配置


extern u8 initMax14830A(void);
extern void Max14830ASendDat(u8 num_uart, u8 d);
extern u8 Max14830ARcvDat(u8 num_uart);
extern u8 Max14830ARFIFOCnt(u8 num_uart);
extern u8 Max14830AReadIRQ(void);
extern u8 Max14830AReadISR(u8 num_uart);
extern void  Max14830ARcvFifo(u8 num_uart, u8 *buf, u8 size);

#define Max14830_RBufLen	 200

extern u8 Max14830A_RBuf[4][Max14830_RBufLen];  //串口接收环形缓冲区
extern u8 Max14830A_RPi[4];   //串口接收环形缓冲区入口指针
extern u8 Max14830A_RPo[4];   //串口接收环形缓冲区出口指针
	 



#endif

