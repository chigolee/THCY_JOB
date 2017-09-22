#include "main.h"
#include "configuration.h"

 u8 Max14830C_RBuf[4][Max14830_RBufLen]={0};  //串口接收环形缓冲区
 u8 Max14830C_RPi[4];   //串口接收环形缓冲区入口指针
 u8 Max14830C_RPo[4];   //串口接收环形缓冲区出口指针

u8 send2Max14830C(u8 num_uart, u8 addr, u8 wr_rd_n, u8 d);



u8 initMax14830C(void)
{
 U8  Result=TRUE;  

      MAX14830C_SPI_init();
     /* Deselect the MAX14830: Chip Select high */
      MAX14830C_CS_HIGH;
	
	MAX14830C_RSTN_LOW;
	Delayms(1);// 等10毫秒
	MAX14830C_RSTN_HIGH;	
	
	Delayms(1);// 等10毫秒	
	
      if(IsSystemTest == TRUE)
      	{
		// 串口0
		send2Max14830C(0, 0x1c, 1, MAX14830_BR_115200);// 设置波特率
		send2Max14830C(0, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(0, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(0, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  
		
		// 串口1
		send2Max14830C(1, 0x1c, 1, MAX14830_BR_115200);// 设置波特率
		send2Max14830C(1, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(1, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(1, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  	 
		
		// 串口2
		send2Max14830C(2, 0x1c, 1, MAX14830_BR_115200);// 设置波特率
		send2Max14830C(2, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(2, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(2, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  
		
		// 串口3
		send2Max14830C(3, 0x1c, 1, MAX14830_BR_115200);// 设置波特率
		send2Max14830C(3, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(3, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(3, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  
      	}
	else
	{
		// 串口0
		send2Max14830C(0, 0x1c, 1, UF_BaudRate);// 设置波特率
		send2Max14830C(0, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(0, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(0, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效
		
		
		// 串口1
		send2Max14830C(1, 0x1c, 1, UG_BaudRate);// 设置波特率
		send2Max14830C(1, 0x0b, 1, 0x1b);// 设置串口模式,偶	1b ,奇0b,   无03
		send2Max14830C(1, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(1, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  	 
		
		// 串口2
		send2Max14830C(2, 0x1c, 1, UH_BaudRate);// 设置波特率
		send2Max14830C(2, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(2, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(2, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  
		
		// 串口3
		send2Max14830C(3, 0x1c, 1, UI_BaudRate);// 设置波特率
		send2Max14830C(3, 0x0b, 1, 0x03);// 设置串口模式
		send2Max14830C(3, 0x0a, 1, 0x08);// 设置RxEmptyInv 有效 接收到任何字符即产生中断
		send2Max14830C(3, 0x01, 1, 0x40);// 设置RFifoEmptyEn 有效  
      	}
	send2Max14830C(0, 0x09, 1, 0x80);// 打开总中断输出
	send2Max14830C(1, 0x09, 1, 0x80);// 打开总中断输出
	send2Max14830C(2, 0x09, 1, 0x80);// 打开总中断输出
	send2Max14830C(3, 0x09, 1, 0x80);// 打开总中断输出
	
	//读取 版本信息	
	send2Max14830C(0, 0x1F, 1, 0xCE) ;
	Result &= (send2Max14830C(0, 0x05, 0, 0) == MAX14830_REVID);    
	send2Max14830C(0, 0x1F, 1, 0xCD) ;   
	return Result;
	
}

void Max14830CSendDat(u8 num_uart, u8 d)
{
	send2Max14830C(num_uart, 0x00, 1, d);
}

u8 Max14830CRcvDat(u8 num_uart)
{
	return send2Max14830C(num_uart, 0x00, 0, 0);
}


u8 Max14830CReadIRQ(void)
{
	u8 RcvData;
	MAX14830C_CS_LOW;
	RcvData = MAX14830C_SendByte(0x00);	
	MAX14830C_CS_HIGH;
	return RcvData&0x0f;
}

u8 Max14830CReadISR(u8 num_uart)
{
	return send2Max14830C(num_uart, 0x02, 0, 0);
}


u8 Max14830CRFIFOCnt(u8 num_uart)
{
	return send2Max14830C(num_uart, 0x12, 0, 0);
}

void  Max14830CRcvFifo(u8 num_uart, u8 *buf, u8 size)
{
       u8 i;
	MAX14830C_CS_LOW;
	
	MAX14830C_SendByte(((num_uart&0x03) << 5));
	for(i = 0; i < size; i++)
	{
		buf[Max14830C_RPi[num_uart]] = MAX14830C_SendByte(0);		
		Max14830C_RPi[num_uart] = (Max14830C_RPi[num_uart]+1)%Max14830_RBufLen;
	}
	
	MAX14830C_CS_HIGH;	
}
u8 send2Max14830C(u8 num_uart, u8 addr, u8 wr_rd_n, u8 d)
{
	u8 RevData;
	MAX14830C_CS_LOW;
  	//comDly(12);
	RevData = MAX14830C_SendByte(((wr_rd_n&0x01) << 7) | ((num_uart&0x03) << 5) | (addr&0x1f));
	RevData = MAX14830C_SendByte(d);
	//comDly(12);
	MAX14830C_CS_HIGH;
	return RevData;
}




