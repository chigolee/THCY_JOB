/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"
           
U8 U3TxBuf[U3TxBuf_Len]={0};                 //����֡����������ָ��
U16  U3TxBufPi = 0;	                                 //���ͻ��������ָ��	
U16  U3TxBufPo = 0;	                                 //���ͻ���������ָ��

 U8  U3RxBufP = 0;                                //���ջ�����ָ��
 U8  U3RxBuf[U3_RxF_Len]={0};		 //���ջ�����	

 U8 U3RxFBuf[U3_RxF_BufLen][U3_RxF_Len+1] = {0};                 //����֡������
 U8 U3RxFBufPi  =0;                 //����֡���������ָ��
 U8 U3RxFBufPo = 0;                 //����֡����������ָ��

 

/**************************************************************************************
��������USART3_IRQHandler
������������EXTI0�жϵķ����ӳ���
**************************************************************************************/
void USART3_IRQHandler(void)  
{
 U8 t;
 static U8 FLen = U3_RxF_Len;	


	while((USART3->SR)&0x0020) //�Ƿ�����ж� (���ռĴ����ǿ�)     
	{
		t = USART3->DR;
		
		if(IsSystemTest == TRUE)
	      {
	              USART3_SendData(t);
	      }
             else
	     	{
                     if ((U3RxBufP == 0)&&(t == U3_DH0) )
				{
				U3RxBuf[U3RxBufP] = t;
				U3RxBufP++;
				}
					 
			else if((U3RxBufP == 1)&&(t == U3_DH1))
				{
				U3RxBuf[U3RxBufP] = t;
				U3RxBufP++;
				}
			
			else if(U3RxBufP == 2)
				{
				U3RxBuf[U3RxBufP] = t;
				U3RxBufP++;
				FLen=t+U3_Len_Plus;
				if(FLen>U3_RxF_Len)
					{FLen=U3_RxF_Len;}					
				}
			
			else if(U3RxBufP>2)
				{
				U3RxBuf[U3RxBufP] = t;
				U3RxBufP++;
				if(U3RxBufP>=FLen)	//����һ֡
					{
                                  //����һ֡	   
				      memcpy(U3RxFBuf[U3RxFBufPi], U3RxBuf,  U3RxBufP); 
				      U3RxFBuf[U3RxFBufPi][U3_RxF_Len] = U3RxBufP;		  	
				      U3RxFBufPi =  (U3RxFBufPi+1)%U3_RxF_BufLen;
				      U3RxBufP = 0;
					}
				}
			
			else
				{U3RxBufP=0;}

	     	}	      
		
	}
	
	if((USART3->SR)&0x0040) //�Ƿ�������ж�
       {            
	   			
              if(U3TxBufPo != U3TxBufPi)
             	{
                    USART3->DR = U3TxBuf[U3TxBufPo];		     
		      U3TxBufPo = (U3TxBufPo+1)%U3TxBuf_Len;	 		     	  
		}
		//������ϣ��رշ��Ϳ��ж�  
		if(U3TxBufPo == U3TxBufPi)
		      USART3->CR1 &= 0xFFBF;  	
		
	}
	//USART3->SR = 0xFFDF;

}


//USART3 ��������
// 1�� �������ֽ�--> U3TxBuf
// 2�� �������Ϳ��ж�

U8 U3InTxBuf(U8 *p, U8 Len)              //  ���������� --> U3TxBuf   
{

U8 i=0;

             if(Len <= U3_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U3TxBuf[U3TxBufPi] = p[i];
				   U3TxBufPi = (U3TxBufPi +1)%U3TxBuf_Len;  //���ָ����λ 
			 }	

			 if(U3TxBufPo!= U3TxBufPi)
			 {
	                       //ʹ��USART3��������ж�	     
                              USART3->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


/**************************************************************************************
��������USART3_SendData
��������USART3���ͺ���
���롡����
���������
���ء�����
**************************************************************************************/
void USART3_SendData(uint16_t Data)
{ 
	USART3->DR = (Data & (uint16_t)0x01FF);
	while(((USART3->SR)&0x0080)==RESET);	
}

