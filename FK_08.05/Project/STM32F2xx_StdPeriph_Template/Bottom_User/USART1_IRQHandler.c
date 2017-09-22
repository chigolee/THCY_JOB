/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/


#include "main.h"
           
U8 U1TxBuf[U1TxBuf_Len]={0};                 //����֡����������ָ��
U16  U1TxBufPi = 0;	                                 //���ͻ��������ָ��	
U16  U1TxBufPo = 0;	                                 //���ͻ���������ָ��

 U8  U1RxBufP = 0;                                //���ջ�����ָ��
 U8  U1RxBuf[U1_RxF_Len]={0};		 //���ջ�����	

 U8 U1RxFBuf[U1_RxF_BufLen][U1_RxF_Len+1] = {0};                 //����֡������
 U8 U1RxFBufPi  =0;                 //����֡���������ָ��
 U8 U1RxFBufPo = 0;                 //����֡����������ָ��

//USART1���ݴ�������


/**************************************************************************************
��������USART1_IRQHandler
������������EXTI0�жϵķ����ӳ���
**************************************************************************************/



void USART1_IRQHandler(void)  
{
    U8 t;
    static U8 FLen = U1_RxF_Len;	

	while((USART1->SR)&0x0020) //�Ƿ�����ж� (���ռĴ����ǿ�)     
	{
	     t = USART1->DR;


	     if(IsSystemTest == TRUE)
	     {
	              USART1_SendData(t);
	     }
	     else
	     	{
                     if ((U1RxBufP == 0)&&(t == U1_DH0) )
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				}
					 
			else if((U1RxBufP == 1)&&(t == U1_DH1))
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				}
			
			else if(U1RxBufP == 2)
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				FLen=t+U1_Len_Plus;
				if(FLen>U1_RxF_Len)
					{FLen=U1_RxF_Len;}					
				}
			
			else if(U1RxBufP>2)
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				if(U1RxBufP>=FLen)	//����һ֡
					{
                                  //����һ֡	   
				      memcpy(U1RxFBuf[U1RxFBufPi], U1RxBuf,  U1RxBufP); 
				      U1RxFBuf[U1RxFBufPi][U1_RxF_Len] = U1RxBufP;		  	
				      U1RxFBufPi =  (U1RxFBufPi+1)%U1_RxF_BufLen;
				      U1RxBufP = 0;
					}
				}
			
			else
				{U1RxBufP=0;}

	     	}

	
	}
	
	 if((USART1->SR)&0x0040) //�Ƿ�������ж�
       {            
	   			
              if(U1TxBufPo != U1TxBufPi)
             	{
                    USART1->DR = U1TxBuf[U1TxBufPo];		     
		      U1TxBufPo = (U1TxBufPo+1)%U1TxBuf_Len;	 		     	  
		}
		//������ϣ��رշ��Ϳ��ж�  
		if(U1TxBufPo == U1TxBufPi)
		      USART1->CR1 &= 0xFFBF;  	
		
	}
	
	//USART1->SR = 0xFFDF;

}






//USART1 ��������
// 1�� �������ֽ�--> U1TxBuf
// 2�� �������Ϳ��ж�

U8 U1InTxBuf(U8 *p, U8 Len)              //  ���������� --> U1TxBuf   
{

U8 i=0;

             if(Len <= U1_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U1TxBuf[U1TxBufPi] = p[i];
				   U1TxBufPi = (U1TxBufPi +1)%U1TxBuf_Len;  //���ָ����λ 
			 }	

			 if(U1TxBufPo!= U1TxBufPi)
			 {
	                       //ʹ��USART1��������ж�	     
	                       USART1->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


/**************************************************************************************
��������USART1_SendData
��������USART1���ͺ���
���롡����
���������
���ء�����
**************************************************************************************/
void USART1_SendData(uint16_t Data)
{ 
	USART1->DR = (Data & (uint16_t)0x01FF);
	
	while(((USART1->SR)&0x0080)==RESET);	
}


#define MAX_TBUF1	100
char tbuf1[MAX_TBUF1]= {0, };
/****************************************************************************
* ���ƣ�USART1_Printf()
* ���ܣ��򴮿ڷ���һ�ַ��� �÷�ͬPrintf()����
* ��ڲ�����format	Ҫ���͵��ַ�����ָ�� ... Ϊ����
* ���ڲ��������͵��ַ������ַ�����
****************************************************************************/
int USART1_Printf(const char *format, ...)
{
	va_list v_list;
	char *ptr;
	int i= 0;


	va_start(v_list, format);     // Initialize variable arguments. 
	vsprintf(tbuf1, format, v_list ); 
	va_end(v_list);


	ptr= tbuf1;
	while( (*ptr) && i<MAX_TBUF1) {
		USART1_SendData( *ptr);
		ptr++;	i++;
	}//while

	return i;
}
 
