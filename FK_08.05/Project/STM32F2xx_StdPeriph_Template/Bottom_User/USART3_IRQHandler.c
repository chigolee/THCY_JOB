/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"
           
U8 U3TxBuf[U3TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U3TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U3TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U3RxBufP = 0;                                //接收缓冲区指针
 U8  U3RxBuf[U3_RxF_Len]={0};		 //接收缓冲区	

 U8 U3RxFBuf[U3_RxF_BufLen][U3_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U3RxFBufPi  =0;                 //环形帧缓冲区入口指针
 U8 U3RxFBufPo = 0;                 //环形帧缓冲区出口指针

 

/**************************************************************************************
函数名：USART3_IRQHandler
描述　：处理EXTI0中断的服务子程序
**************************************************************************************/
void USART3_IRQHandler(void)  
{
 U8 t;
 static U8 FLen = U3_RxF_Len;	


	while((USART3->SR)&0x0020) //是否接收中断 (接收寄存器非空)     
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
				if(U3RxBufP>=FLen)	//收满一帧
					{
                                  //收满一帧	   
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
	
	if((USART3->SR)&0x0040) //是否发送完成中断
       {            
	   			
              if(U3TxBufPo != U3TxBufPi)
             	{
                    USART3->DR = U3TxBuf[U3TxBufPo];		     
		      U3TxBufPo = (U3TxBufPo+1)%U3TxBuf_Len;	 		     	  
		}
		//发送完毕，关闭发送空中断  
		if(U3TxBufPo == U3TxBufPi)
		      USART3->CR1 &= 0xFFBF;  	
		
	}
	//USART3->SR = 0xFFDF;

}


//USART3 发送流程
// 1、 待发送字节--> U3TxBuf
// 2、 开启发送空中断

U8 U3InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U3TxBuf   
{

U8 i=0;

             if(Len <= U3_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U3TxBuf[U3TxBufPi] = p[i];
				   U3TxBufPi = (U3TxBufPi +1)%U3TxBuf_Len;  //输出指针移位 
			 }	

			 if(U3TxBufPo!= U3TxBufPi)
			 {
	                       //使能USART3发送完成中断	     
                              USART3->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


/**************************************************************************************
函数名：USART3_SendData
描述　：USART3发送函数
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void USART3_SendData(uint16_t Data)
{ 
	USART3->DR = (Data & (uint16_t)0x01FF);
	while(((USART3->SR)&0x0080)==RESET);	
}

