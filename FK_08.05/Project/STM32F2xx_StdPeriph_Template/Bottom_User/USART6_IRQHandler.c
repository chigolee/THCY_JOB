/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"

         
U8 U6TxBuf[U6TxBuf_Len]={0};                 //����֡����������ָ��
U16  U6TxBufPi = 0;	                                 //���ͻ��������ָ��	
U16  U6TxBufPo = 0;	                                 //���ͻ���������ָ��

 U8  U6RxBufP = 0;                                //���ջ�����ָ��
 U8  U6RxBuf[U6_RxF_Len]={0};		 //���ջ�����	

 U8 U6RxFBuf[U6_RxF_BufLen][U6_RxF_Len+1] = {0};                 //����֡������
 U8 U6RxFBufPi  =0;                 //����֡���������ָ��
 U8 U6RxFBufPo = 0;                 //����֡����������ָ��
		
/**************************************************************************************
��������USART6_IRQHandler
������������EXTI0�жϵķ����ӳ���
**************************************************************************************/
void USART6_IRQHandler(void)  
{
	U8 t;
	static U8 FLen = U6_RxF_Len;	
	static U8 FramFlag = 0;	// 1-�ɼ������ݽ����У�2-�������ݽ�����
	
	while((USART6->SR)&0x0020) //�Ƿ�����ж� (���ռĴ����ǿ�)     
	{
		t = USART6->DR;
		if(IsSystemTest == TRUE)
	      {
	              USART6_SendData(t);
	      }
		else

			{
			if(FramFlag<=1)	//δ���ա����ղɼ�������״̬
				{			
				if(U6RxBufP == 0)
					{
					if(t == U_5678_DH0)
						{
						U6RxBuf[U6RxBufP] = t;
						U6RxBufP++;
						FramFlag=1;
						}
					else if(t == U_5678_BDStart)
						{
						U6RxBuf[U6RxBufP] = t;
						U6RxBufP++;
						FramFlag=2;
						}
					}
				
				else if((U6RxBufP == 1)&&(t == U_5678_DH1))
					{
					U6RxBuf[U6RxBufP] = t;
					U6RxBufP++;
					}
				
				else if(U6RxBufP>=2)
					{
					U6RxBuf[U6RxBufP] = t;
					U6RxBufP++;
					if(U6RxBufP>=U_5678_Length)	//����һ֡
						{
						//����һ֡	   
						memcpy(U6RxFBuf[U6RxFBufPi], U6RxBuf,  U6RxBufP); 
						U6RxFBuf[U6RxFBufPi][U6_RxF_Len] = U6RxBufP;		  	
						U6RxFBufPi =  (U6RxFBufPi+1)%U6_RxF_BufLen;
						U6RxBufP = 0;	FramFlag=0;
						}
					}
				
				else
					{U6RxBufP=0;	FramFlag=0;}				

				}
			
			else		//���ձ�������״̬
				{
				if(t == U_5678_DH0)
					{
					U6RxBufP=0;
					U6RxBuf[U6RxBufP] = t;
					U6RxBufP++;
					FramFlag=1;
					}
				else if(t ==U_5678_BDStart)
					{
					U6RxBufP=0;
					U6RxBuf[U6RxBufP] = t;
					U6RxBufP++;
					FramFlag=2;
					}
				
				else if(t==U_5678_BDEnd)
					{
					U6RxBuf[U6RxBufP] = t;
					U6RxBufP++;
					//����һ֡	   
					memcpy(U6RxFBuf[U6RxFBufPi], U6RxBuf,  U6RxBufP); 
					U6RxFBuf[U6RxFBufPi][U6_RxF_Len] = U6RxBufP;		  	
					U6RxFBufPi =  (U6RxFBufPi+1)%U6_RxF_BufLen;
					U6RxBufP = 0;	FramFlag=0;
					}
				else
					{
					U6RxBuf[U6RxBufP] = t;
					U6RxBufP++;
					if(U6RxBufP>=U6_RxF_Len)
						{                                //�մ�һ֡����Ҫ��	   
						U6RxBufP = 0;	FramFlag=0;
						}
					}

				}
			
		     	}
		
	}

	if((USART6->SR)&0x0040) //�Ƿ�������ж�
       {            
	   			
              if(U6TxBufPo != U6TxBufPi)
             	{
                    USART6->DR = U6TxBuf[U6TxBufPo];		     
		      U6TxBufPo = (U6TxBufPo+1)%U6TxBuf_Len;	 		     	  
		}
		//������ϣ��رշ��Ϳ��ж�  
		if(U6TxBufPo == U6TxBufPi)
		      USART6->CR1 &= 0xFFBF;  			
	}
	
	//USART6->SR = 0xFFDF;	 
}

//USART6 ��������
// 1�� �������ֽ�--> U6TxBuf
// 2�� �������Ϳ��ж�

U8 U6InTxBuf(U8 *p, U8 Len)              //  ���������� --> U6TxBuf   
{

U8 i=0;

             if(Len <= U6_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U6TxBuf[U6TxBufPi] = p[i];
				   U6TxBufPi = (U6TxBufPi +1)%U6TxBuf_Len;  //���ָ����λ 
			 }	

			 if(U6TxBufPo!= U6TxBufPi)
			 {
	                       //ʹ��USART6��������ж�	     
                              USART6->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


  
 /**************************************************************************************
��������USART6_SendData
��������USART6���ͺ���
���롡����
���������
���ء�����
**************************************************************************************/
void USART6_SendData(uint16_t Data)
{ 
	USART6->DR = (Data & (uint16_t)0x01FF);
	
	while(((USART6->SR)&0x0080)==RESET);	
}


 
