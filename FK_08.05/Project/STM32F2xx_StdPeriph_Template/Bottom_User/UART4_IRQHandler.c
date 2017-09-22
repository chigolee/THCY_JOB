/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"

         
U8 U4TxBuf[U4TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U4TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U4TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U4RxBufP = 0;                                //接收缓冲区指针
 U8  U4RxBuf[U4_RxF_Len]={0};		 //接收缓冲区	

 U8 U4RxFBuf[U4_RxF_BufLen][U4_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U4RxFBufPi  =0;                 //环形帧缓冲区入口指针
 U8 U4RxFBufPo = 0;                 //环形帧缓冲区出口指针

/**************************************************************************************
函数名：USART4_IRQHandler
描述　：处理EXTI0中断的服务子程序
**************************************************************************************/
void UART4_IRQHandler(void)  
{
	U8 t;
	static U8 FLen = U4_RxF_Len;	// 

	while((UART4->SR)&0x0020) //是否接收中断 (接收寄存器非空)     
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
				if(U4RxBufP>=FLen)	//收满一帧
					{
                                  //收满一帧	   
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

	if((UART4->SR)&0x0040) //是否发送完成中断
       {            
	   			
              if(U4TxBufPo != U4TxBufPi)
             	{
                    UART4->DR = U4TxBuf[U4TxBufPo];		     
		      U4TxBufPo = (U4TxBufPo+1)%U4TxBuf_Len;	 		     	  
		}
		//发送完毕，关闭发送空中断  
		if(U4TxBufPo == U4TxBufPi)
		      UART4->CR1 &= 0xFFBF;  	
		
	}
	
	//UART4->SR = 0xFFDF;

}



//USART4 发送流程
// 1、 待发送字节--> U4TxBuf
// 2、 开启发送空中断

U8 U4InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U4TxBuf   
{

U8 i=0;

             if(Len <= U4_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U4TxBuf[U4TxBufPi] = p[i];
				   U4TxBufPi = (U4TxBufPi +1)%U4TxBuf_Len;  //输出指针移位 
			 }	

			 if(U4TxBufPo!= U4TxBufPi)
			 {
	                       //使能UART4发送完成中断	     
                              UART4->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


 /**************************************************************************************
函数名：UART4_SendData
描述　：UART4发送函数
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void UART4_SendData(uint16_t Data)
{ 
	UART4->DR = (Data & (uint16_t)0x01FF);
	while(((UART4->SR)&0x0080)==RESET);
	
}



 
 
