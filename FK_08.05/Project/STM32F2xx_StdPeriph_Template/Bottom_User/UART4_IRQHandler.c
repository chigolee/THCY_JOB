/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"

         
U8 U4TxBuf[U4TxBuf_Len]={0};                 //����֡����������ָ��
U16  U4TxBufPi = 0;	                                 //���ͻ��������ָ��	
U16  U4TxBufPo = 0;	                                 //���ͻ���������ָ��

 U8  U4RxBufP = 0;                                //���ջ�����ָ��
 U8  U4RxBuf[U4_RxF_Len]={0};		 //���ջ�����	

 U8 U4RxFBuf[U4_RxF_BufLen][U4_RxF_Len+1] = {0};                 //����֡������
 U8 U4RxFBufPi  =0;                 //����֡���������ָ��
 U8 U4RxFBufPo = 0;                 //����֡����������ָ��

/**************************************************************************************
��������USART4_IRQHandler
������������EXTI0�жϵķ����ӳ���
**************************************************************************************/
void UART4_IRQHandler(void)  
{
	U8 t;
	static U8 FLen = U4_RxF_Len;	// 

	while((UART4->SR)&0x0020) //�Ƿ�����ж� (���ռĴ����ǿ�)     
	{
		t = UART4->DR;
		if(IsSystemTest == TRUE)
	      {
	              UART4_SendData(t);
	      }
		else
	     	{			
                     if ((U4RxBufP == 0)&&(t == U4_DH0) )
				{
				U4RxBuf[U4RxBufP] = t;
				U4RxBufP++;
				}
					 
			else if((U4RxBufP == 1)&&(t == U4_DH1))
				{
				U4RxBuf[U4RxBufP] = t;
				U4RxBufP++;
				FLen=U4_Length;
				if(FLen>U4_RxF_Len){FLen = U4_RxF_Len;}
				}
			
			else if(U4RxBufP>=2)
				{
				U4RxBuf[U4RxBufP] = t;
				U4RxBufP++;
				if(U4RxBufP>=FLen)	//����һ֡
					{
                                  //����һ֡	   
				      memcpy(U4RxFBuf[U4RxFBufPi], U4RxBuf,  U4RxBufP); 
				      U4RxFBuf[U4RxFBufPi][U4_RxF_Len] = U4RxBufP;		  	
				      U4RxFBufPi =  (U4RxFBufPi+1)%U4_RxF_BufLen;
				      U4RxBufP = 0;
					}
				}
			
			else
				{U4RxBufP=0;}

	     	}
		

	}

	if((UART4->SR)&0x0040) //�Ƿ�������ж�
       {            
	   			
              if(U4TxBufPo != U4TxBufPi)
             	{
                    UART4->DR = U4TxBuf[U4TxBufPo];		     
		      U4TxBufPo = (U4TxBufPo+1)%U4TxBuf_Len;	 		     	  
		}
		//������ϣ��رշ��Ϳ��ж�  
		if(U4TxBufPo == U4TxBufPi)
		      UART4->CR1 &= 0xFFBF;  	
		
	}
	
	//UART4->SR = 0xFFDF;

}



//USART4 ��������
// 1�� �������ֽ�--> U4TxBuf
// 2�� �������Ϳ��ж�

U8 U4InTxBuf(U8 *p, U8 Len)              //  ���������� --> U4TxBuf   
{

U8 i=0;

             if(Len <= U4_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U4TxBuf[U4TxBufPi] = p[i];
				   U4TxBufPi = (U4TxBufPi +1)%U4TxBuf_Len;  //���ָ����λ 
			 }	

			 if(U4TxBufPo!= U4TxBufPi)
			 {
	                       //ʹ��UART4��������ж�	     
                              UART4->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


 /**************************************************************************************
��������UART4_SendData
��������UART4���ͺ���
���롡����
���������
���ء�����
**************************************************************************************/
void UART4_SendData(uint16_t Data)
{ 
	UART4->DR = (Data & (uint16_t)0x01FF);
	while(((UART4->SR)&0x0080)==RESET);
	
}



 
 
