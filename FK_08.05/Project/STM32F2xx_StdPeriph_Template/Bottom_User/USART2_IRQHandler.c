/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"

              
U8 U2TxBuf[U2TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U2TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U2TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U2RxBufP = 0;                                //接收缓冲区指针
 U8  U2RxBuf[U2_RxF_Len]={0};		 //接收缓冲区	

 U8 U2RxFBuf[U2_RxF_BufLen][U2_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U2RxFBufPi  =0;                 //环形帧缓冲区入口指针
 U8 U2RxFBufPo = 0;                 //环形帧缓冲区出口指针








/**************************************************************************************
函数名：USART2_IRQHandler
描述　：处理EXTI0中断的服务子程序
**************************************************************************************/
void USART2_IRQHandler(void)  
{
U8 t;

static U8 FLen = U2_RxF_Len;	
static U8 Flag =0;


	
	while((USART2->SR)&0x0020) //是否接收中断 (接收寄存器非空)     
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
				//附加长度确定
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

				if(U2RxBufP>=FLen)	//收满一帧
					{
                                  //收满一帧	   
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
	
        if((USART2->SR)&0x0040) //是否发送完成中断
       {            
	   			
              if(U2TxBufPo != U2TxBufPi)
             	{
                    USART2->DR = U2TxBuf[U2TxBufPo];		     
		      U2TxBufPo = (U2TxBufPo+1)%U2TxBuf_Len;	 		     	  
		}
		//发送完毕，关闭发送空中断  
		if(U2TxBufPo == U2TxBufPi)
		      USART2->CR1 &= 0xFFBF;  	
		
	}
	
	
	//USART2->SR = 0xFFDF;

}

//USART2 发送流程
// 1、 待发送字节--> U2TxBuf
// 2、 开启发送空中断

U8 U2InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U2TxBuf   
{

U8 i=0;

             if(Len <= U2_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U2TxBuf[U2TxBufPi] = p[i];
				   U2TxBufPi = (U2TxBufPi +1)%U2TxBuf_Len;  //输出指针移位 
			 }	

			 if(U2TxBufPo!= U2TxBufPi)
			 {
	                       //使能USART2发送完成中断	     
	                       USART2->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }



/**************************************************************************************
函数名：USART2_SendData
描述　：USART2发送函数
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void USART2_SendData(uint16_t Data)
{ 
	USART2->DR = (Data & (uint16_t)0x01FF);
	while(((USART2->SR)&0x0080)==RESET);	
	
}
 
