/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"
           
U8 U5TxBuf[U5TxBuf_Len]={0};                 //����֡����������ָ��
U16  U5TxBufPi = 0;	                                 //���ͻ��������ָ��	
U16  U5TxBufPo = 0;	                                 //���ͻ���������ָ��

 U8  U5RxBufP = 0;                                //���ջ�����ָ��
 U8  U5RxBuf[U5_RxF_Len]={0};		 //���ջ�����	

 U8 U5RxFBuf[U5_RxF_BufLen][U5_RxF_Len+1] = {0};                 //����֡������
 U8 U5RxFBufPi  =0;                 //����֡���������ָ��
 U8 U5RxFBufPo = 0;                 //����֡����������ָ��

/**************************************************************************************
��������USART5_IRQHandler
������������EXTI0�жϵķ����ӳ���
**************************************************************************************/
void UART5_IRQHandler(void)  
{
	U8 t;
	static U8 FLen = U5_RxF_Len;	
	static U8 FramFlag = 0;	// 1-�ɼ������ݽ����У�2-�������ݽ�����

	while((UART5->SR)&0x0020) //�Ƿ�����ж� (���ռĴ����ǿ�)     
	{
		t = UART5->DR;
		
		if(IsSystemTest == TRUE)
			{
			UART5_SendData(t);
			}
	      else
			{
			
			if(FramFlag<=1)	//δ���ա����ղɼ�������״̬
				{			
				if(U5RxBufP == 0)
					{
					if(t == U_5678_DH0)
						{
						U5RxBuf[U5RxBufP] = t;
						U5RxBufP++;
						FramFlag=1;
						}
					else if(t == U_5678_BDStart)
						{
						U5RxBuf[U5RxBufP] = t;
						U5RxBufP++;
						FramFlag=2;
						}
					}
				
				else if((U5RxBufP == 1)&&(t == U_5678_DH1))
					{
					U5RxBuf[U5RxBufP] = t;
					U5RxBufP++;
					}
				
				else if(U5RxBufP>=2)
					{
					U5RxBuf[U5RxBufP] = t;
					U5RxBufP++;
					if(U5RxBufP>=U_5678_Length)	//����һ֡
						{
						//����һ֡	   
						memcpy(U5RxFBuf[U5RxFBufPi], U5RxBuf,  U5RxBufP); 
						U5RxFBuf[U5RxFBufPi][U5_RxF_Len] = U5RxBufP;		  	
						U5RxFBufPi =  (U5RxFBufPi+1)%U5_RxF_BufLen;
						U5RxBufP = 0;	FramFlag=0;
						}
					}
				
				else
					{U5RxBufP=0;	FramFlag=0;}				

				}
			
			else		//���ձ�������״̬
				{
				if(t == U_5678_DH0)
					{
					U5RxBufP=0;
					U5RxBuf[U5RxBufP] = t;
					U5RxBufP++;
					FramFlag=1;
					}
				else if(t ==U_5678_BDStart)
					{
					U5RxBufP=0;
					U5RxBuf[U5RxBufP] = t;
					U5RxBufP++;
					FramFlag=2;
					}
				
				else if(t==U_5678_BDEnd)
					{
					U5RxBuf[U5RxBufP] = t;
					U5RxBufP++;
					//����һ֡	   
					memcpy(U5RxFBuf[U5RxFBufPi], U5RxBuf,  U5RxBufP); 
					U5RxFBuf[U5RxFBufPi][U5_RxF_Len] = U5RxBufP;		  	
					U5RxFBufPi =  (U5RxFBufPi+1)%U5_RxF_BufLen;
					U5RxBufP = 0;	FramFlag=0;
					}
				else
					{
					U5RxBuf[U5RxBufP] = t;
					U5RxBufP++;
					if(U5RxBufP>=U5_RxF_Len)
						{                                //�մ�һ֡����Ҫ��	   
						U5RxBufP = 0;	FramFlag=0;
						}
					}

				}
			
		     	}
		  
	}
	
	if((UART5->SR)&0x0040) //�Ƿ�������ж�
       {            
	   			
              if(U5TxBufPo != U5TxBufPi)
             	{
                    UART5->DR = U5TxBuf[U5TxBufPo];		     
		      U5TxBufPo = (U5TxBufPo+1)%U5TxBuf_Len;	 		     	  
		}
		//������ϣ��رշ��Ϳ��ж�  
		if(U5TxBufPo == U5TxBufPi)
		      UART5->CR1 &= 0xFFBF;  	
		
	}
	//UART5->SR = 0xFFDF;

}

//USART5 ��������
// 1�� �������ֽ�--> U5TxBuf
// 2�� �������Ϳ��ж�

U8 U5InTxBuf(U8 *p, U8 Len)              //  ���������� --> U5TxBuf   
{

U8 i=0;

             if(Len <= U5_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U5TxBuf[U5TxBufPi] = p[i];
				   U5TxBufPi = (U5TxBufPi +1)%U5TxBuf_Len;  //���ָ����λ 
			 }	

			 if(U5TxBufPo!= U5TxBufPi)
			 {
	                       //ʹ��UART4��������ж�	     
                              UART5->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


/**************************************************************************************
��������UART5_SendData
��������UART5���ͺ���
���롡����
���������
���ء�����
**************************************************************************************/
void UART5_SendData(uint16_t Data)
{ 
	UART5->DR = (Data & (uint16_t)0x01FF);
	while(((UART5->SR)&0x0080)==RESET);
}

 
