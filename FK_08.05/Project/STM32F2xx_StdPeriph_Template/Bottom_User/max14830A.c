#include "main.h"
#include "configuration.h"

 u8 Max14830A_RBuf[4][Max14830_RBufLen]={0};  //���ڽ��ջ��λ�����
 u8 Max14830A_RPi[4];   //���ڽ��ջ��λ��������ָ��
 u8 Max14830A_RPo[4];   //���ڽ��ջ��λ���������ָ��

u8 send2Max14830A(u8 num_uart, u8 addr, u8 wr_rd_n, u8 d);



u8 initMax14830A()
{

U8  Result=TRUE;  

       MAX14830A_SPI_init();
     /* Deselect the MAX14830: Chip Select high */
       MAX14830A_CS_HIGH;
	
	MAX14830A_RSTN_LOW;
	Delayms(1);// ��10����
	MAX14830A_RSTN_HIGH;
	Delayms(1);// ��10����	

	if(IsSystemTest == TRUE)
	{
		// ����0
		send2Max14830A(0, 0x1c, 1, MAX14830_BR_115200);// ���ò�����
		send2Max14830A(0, 0x0b, 1, 0x03);// ���ô���ģʽ
		send2Max14830A(0, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(0, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  
		
		// ����1
		send2Max14830A(1, 0x1c, 1, MAX14830_BR_115200);// ���ò�����
		send2Max14830A(1, 0x0b, 1, 0x03);// ���ô���ģʽ
		send2Max14830A(1, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(1, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  	 
		
		// ����2
		send2Max14830A(2, 0x1c, 1, MAX14830_BR_115200);// ���ò�����
		send2Max14830A(2, 0x0b, 1, 0x03);// ���ô���ģʽ
		send2Max14830A(2, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(2, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  
		
		// ����3
		send2Max14830A(3, 0x1c, 1, MAX14830_BR_115200);// ���ò�����
		send2Max14830A(3, 0x0b, 1, 0x03);// ���ô���ģʽ
		send2Max14830A(3, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(3, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  
	}
	else
	{
		// ����0
		send2Max14830A(0, 0x1c, 1, U7_BaudRate);// ���ò�����
		send2Max14830A(0, 0x0b, 1, 0x03);// ���ô���ģʽ	ż	1b ,��0b,   ��03
		send2Max14830A(0, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(0, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  
		
		// ����1
		send2Max14830A(1, 0x1c, 1, U8_BaudRate);// ���ò�����
		send2Max14830A(1, 0x0b, 1, 0x03);// ���ô���ģʽ	ż	1b ,��0b,   ��03
		send2Max14830A(1, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(1, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  	 
		
		// ����2
		send2Max14830A(2, 0x1c, 1, U9_BaudRate);// ���ò�����
		send2Max14830A(2, 0x0b, 1, 0x03);// ���ô���ģʽ	ż	1b ,��0b,   ��03
		send2Max14830A(2, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(2, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  
		
		// ����3
		send2Max14830A(3, 0x1c, 1, UA_BaudRate);// ���ò�����
		send2Max14830A(3, 0x0b, 1, 0x03);// ���ô���ģʽ  //1	8	ż	1b ,��0b,   ��03
		send2Max14830A(3, 0x0a, 1, 0x08);// ����RxEmptyInv ��Ч ���յ��κ��ַ��������ж�
		send2Max14830A(3, 0x01, 1, 0x40);// ����RFifoEmptyEn ��Ч  
	}
	
	send2Max14830A(0, 0x09, 1, 0x80);// �����ж����
	send2Max14830A(1, 0x09, 1, 0x80);// �����ж����
	send2Max14830A(2, 0x09, 1, 0x80);// �����ж����
	send2Max14830A(3, 0x09, 1, 0x80);// �����ж����

	//��ȡ �汾��Ϣ
	send2Max14830A(0, 0x1F, 1, 0xCE) ;
	Result &= (send2Max14830A(0, 0x05, 0, 0) == MAX14830_REVID);  
	send2Max14830A(0, 0x1F, 1, 0xCD) ;   
	return Result;
	
}

void Max14830ASendDat(u8 num_uart, u8 d)
{
	send2Max14830A(num_uart, 0x00, 1, d);
}

u8 Max14830ARcvDat(u8 num_uart)
{
	return send2Max14830A(num_uart, 0x00, 0, 0);
}

void  Max14830ARcvFifo(u8 num_uart, u8 *buf, u8 size)
{
       u8 i;
	MAX14830A_CS_LOW;
	
	MAX14830A_SendByte(((num_uart&0x03) << 5));
	for(i = 0; i < size; i++)
	{
		buf[Max14830A_RPi[num_uart]] = MAX14830A_SendByte(0);		
		Max14830A_RPi[num_uart] = (Max14830A_RPi[num_uart]+1)%Max14830_RBufLen;
	}
	
	MAX14830A_CS_HIGH;	
}


u8 Max14830AReadIRQ(void)
{
	u8 RcvData;
	MAX14830A_CS_LOW;
	RcvData = MAX14830A_SendByte(0x00);	
	MAX14830A_CS_HIGH;
	return RcvData&0x0f;
}

u8 Max14830AReadISR(u8 num_uart)
{
	return send2Max14830A(num_uart, 0x02, 0, 0);
}


u8 Max14830ARFIFOCnt(u8 num_uart)
{
	return (u8)send2Max14830A(num_uart, 0x12, 0, 0);
}


u8 send2Max14830A(u8 num_uart, u8 addr, u8 wr_rd_n, u8 d)
{
	u8 RevData;
       //num_uart ���ں� 0123
       //addr �Ĵ�����ַ
	//wr_rd_n  ��д��־   0��1д
	//d ��д����
	
	MAX14830A_CS_LOW;
  	//comDly(12);
	RevData = MAX14830A_SendByte(((wr_rd_n&0x01) << 7) | ((num_uart&0x03) << 5) | (addr&0x1f));
	RevData = MAX14830A_SendByte(d);
	//comDly(12);
	MAX14830A_CS_HIGH;
	return RevData;
}


