/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"

              
U8 U2TxBuf[U2TxBuf_Len]={0};                 //����֡����������ָ��
U16  U2TxBufPi = 0;	                                 //���ͻ��������ָ��	
U16  U2TxBufPo = 0;	                                 //���ͻ���������ָ��

 U8  U2RxBufP = 0;                                //���ջ�����ָ��
 U8  U2RxBuf[U2_RxF_Len]={0};		 //���ջ�����	

 U8 U2RxFBuf[U2_RxF_BufLen][U2_RxF_Len+1] = {0};                 //����֡������
 U8 U2RxFBufPi  =0;                 //����֡���������ָ��
 U8 U2RxFBufPo = 0;                 //����֡����������ָ��








/**************************************************************************************
��������USART2_IRQHandler
������������EXTI0�жϵķ����ӳ���
**************************************************************************************/
void USART2_IRQHandler(void)  
{
U8 t;

static U8 FLen = U2_RxF_Len;	
static U8 Flag =0;


	
	while((USART2->SR)&0x0020) //�Ƿ�����ж� (���ռĴ����ǿ�)     
	{
		 	
	   t = USART2->DR;	
	   
	     if(IsSystemTest == TRUE)
	     {
	              USART2_SendData(t);
	     }
	     else
		 {
                     if ((U2RxBufP == 0)&&(t == U2_DH0_1) )
				{
				U2RxBuf[U2RxBufP] = t;
				U2RxBufP++;
				}

                     else if ((U2RxBufP == 1)&&(t == U2_DH0_2) )
				{
				U2RxBuf[U2RxBufP] = t;
				U2RxBufP++;
				}
					 
			else if(U2RxBufP == 2)
				{
				//���ӳ���ȷ��
				if(t==U2_D1_H1)
					{
					Flag=U2_D1_H1;	
					U2RxBuf[U2RxBufP] = t;
					U2RxBufP++;
					}
				else if(t==U2_D2_H1)
					{
					Flag=U2_D2_H1;
					U2RxBuf[U2RxBufP] = t;
					U2RxBufP++;					
					}
				else
					{U2RxBufP=0;}
				}
			
			else if(U2RxBufP >= 3)
				{
				if((U2RxBufP==U2_LengPosi_1)&&(Flag==U2_D1_H1))
					{
					FLen=t+U2_Len_Plus_1;
					if(FLen>U2_RxF_Len){FLen = U2_RxF_Len;}	
					}
				else if ((U2RxBufP==U2_LengPosi_2)&&(Flag==U2_D2_H1))
					{
					FLen=t+U2_Len_Plus_2;
					if(FLen>U2_RxF_Len){FLen = U2_RxF_Len;}	
					}

                            U2RxBuf[U2RxBufP] = t;
			       U2RxBufP++;

				if(U2RxBufP>=FLen)	//����һ֡
					{
                                  //����һ֡	   
				      memcpy(U2RxFBuf[U2RxFBufPi], U2RxBuf,  U2RxBufP); 
				      U2RxFBuf[U2RxFBufPi][U2_RxF_Len] = U2RxBufP;		  	
				      U2RxFBufPi =  (U2RxFBufPi+1)%U2_RxF_BufLen;
				      U2RxBufP = 0;				  
					}
				}
			
			else
				{U2RxBufP=0;}

	     	}



	}
	
        if((USART2->SR)&0x0040) //�Ƿ�������ж�
       {            
	   			
              if(U2TxBufPo != U2TxBufPi)
             	{
                    USART2->DR = U2TxBuf[U2TxBufPo];		     
		      U2TxBufPo = (U2TxBufPo+1)%U2TxBuf_Len;	 		     	  
		}
		//������ϣ��رշ��Ϳ��ж�  
		if(U2TxBufPo == U2TxBufPi)
		      USART2->CR1 &= 0xFFBF;  	
		
	}
	
	
	//USART2->SR = 0xFFDF;

}

//USART2 ��������
// 1�� �������ֽ�--> U2TxBuf
// 2�� �������Ϳ��ж�

U8 U2InTxBuf(U8 *p, U8 Len)              //  ���������� --> U2TxBuf   
{

U8 i=0;

             if(Len <= U2_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U2TxBuf[U2TxBufPi] = p[i];
				   U2TxBufPi = (U2TxBufPi +1)%U2TxBuf_Len;  //���ָ����λ 
			 }	

			 if(U2TxBufPo!= U2TxBufPi)
			 {
	                       //ʹ��USART2��������ж�	     
	                       USART2->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }



/**************************************************************************************
��������USART2_SendData
��������USART2���ͺ���
���롡����
���������
���ء�����
**************************************************************************************/
void USART2_SendData(uint16_t Data)
{ 
	USART2->DR = (Data & (uint16_t)0x01FF);
	while(((USART2->SR)&0x0080)==RESET);	
	
}
 
