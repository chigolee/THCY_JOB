/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"

         
U8 U6TxBuf[U6TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U6TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U6TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U6RxBufP = 0;                                //接收缓冲区指针
 U8  U6RxBuf[U6_RxF_Len]={0};		 //接收缓冲区	

 U8 U6RxFBuf[U6_RxF_BufLen][U6_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U6RxFBufPi  =0;                 //环形帧缓冲区入口指针
 U8 U6RxFBufPo = 0;                 //环形帧缓冲区出口指针
		
/**************************************************************************************
函数名：USART6_IRQHandler
描述　：处理EXTI0中断的服务子程序
**************************************************************************************/
void USART6_IRQHandler(void)  
{
	U8 t;
	static U8 FLen = U6_RxF_Len;	
	static U8 FramFlag = 0;	// 1-采集器数据接收中；2-北斗数据接收中
	
	while((USART6->SR)&0x0020) //是否接收中断 (接收寄存器非空)     
	{
		t = USART6->DR;
		if(IsSystemTest == TRUE)
	      {
	              USART6_SendData(t);
	      }
		else

			{
			if(FramFlag<=1)	//未接收、接收采集器数据状态
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
					if(U6RxBufP>=U_5678_Length)	//收满一帧
						{
						//收满一帧	   
						memcpy(U6RxFBuf[U6RxFBufPi], U6RxBuf,  U6RxBufP); 
						U6RxFBuf[U6RxFBufPi][U6_RxF_Len] = U6RxBufP;		  	
						U6RxFBufPi =  (U6RxFBufPi+1)%U6_RxF_BufLen;
						U6RxBufP = 0;	FramFlag=0;
						}
					}
				
				else
					{U6RxBufP=0;	FramFlag=0;}				

				}
			
			else		//接收北斗数据状态
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
					//收满一帧	   
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
						{                                //收错一帧，不要了	   
						U6RxBufP = 0;	FramFlag=0;
						}
					}

				}
			
		     	}
		
	}

	if((USART6->SR)&0x0040) //是否发送完成中断
       {            
	   			
              if(U6TxBufPo != U6TxBufPi)
             	{
                    USART6->DR = U6TxBuf[U6TxBufPo];		     
		      U6TxBufPo = (U6TxBufPo+1)%U6TxBuf_Len;	 		     	  
		}
		//发送完毕，关闭发送空中断  
		if(U6TxBufPo == U6TxBufPi)
		      USART6->CR1 &= 0xFFBF;  			
	}
	
	//USART6->SR = 0xFFDF;	 
}

//USART6 发送流程
// 1、 待发送字节--> U6TxBuf
// 2、 开启发送空中断

U8 U6InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U6TxBuf   
{

U8 i=0;

             if(Len <= U6_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U6TxBuf[U6TxBufPi] = p[i];
				   U6TxBufPi = (U6TxBufPi +1)%U6TxBuf_Len;  //输出指针移位 
			 }	

			 if(U6TxBufPo!= U6TxBufPi)
			 {
	                       //使能USART6发送完成中断	     
                              USART6->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


  
 /**************************************************************************************
函数名：USART6_SendData
描述　：USART6发送函数
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void USART6_SendData(uint16_t Data)
{ 
	USART6->DR = (Data & (uint16_t)0x01FF);
	
	while(((USART6->SR)&0x0080)==RESET);	
}


 
