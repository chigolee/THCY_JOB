/*************************************************************************/
/**************************DUAL_FUSION_Control    2013.07.27**************************/
/****************************** Main_Control ********************************/

#include "main.h"
           
U8 U5TxBuf[U5TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U5TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U5TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U5RxBufP = 0;                                //接收缓冲区指针
 U8  U5RxBuf[U5_RxF_Len]={0};		 //接收缓冲区	

 U8 U5RxFBuf[U5_RxF_BufLen][U5_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U5RxFBufPi  =0;                 //环形帧缓冲区入口指针
 U8 U5RxFBufPo = 0;                 //环形帧缓冲区出口指针

/**************************************************************************************
函数名：USART5_IRQHandler
描述　：处理EXTI0中断的服务子程序
**************************************************************************************/
void UART5_IRQHandler(void)  
{
	U8 t;
	static U8 FLen = U5_RxF_Len;	
	static U8 FramFlag = 0;	// 1-采集器数据接收中；2-北斗数据接收中

	while((UART5->SR)&0x0020) //是否接收中断 (接收寄存器非空)     
	{
		t = UART5->DR;
		
		if(IsSystemTest == TRUE)
			{
			UART5_SendData(t);
			}
	      else
			{
			
			if(FramFlag<=1)	//未接收、接收采集器数据状态
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
					if(U5RxBufP>=U_5678_Length)	//收满一帧
						{
						//收满一帧	   
						memcpy(U5RxFBuf[U5RxFBufPi], U5RxBuf,  U5RxBufP); 
						U5RxFBuf[U5RxFBufPi][U5_RxF_Len] = U5RxBufP;		  	
						U5RxFBufPi =  (U5RxFBufPi+1)%U5_RxF_BufLen;
						U5RxBufP = 0;	FramFlag=0;
						}
					}
				
				else
					{U5RxBufP=0;	FramFlag=0;}				

				}
			
			else		//接收北斗数据状态
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
					//收满一帧	   
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
						{                                //收错一帧，不要了	   
						U5RxBufP = 0;	FramFlag=0;
						}
					}

				}
			
		     	}
		  
	}
	
	if((UART5->SR)&0x0040) //是否发送完成中断
       {            
	   			
              if(U5TxBufPo != U5TxBufPi)
             	{
                    UART5->DR = U5TxBuf[U5TxBufPo];		     
		      U5TxBufPo = (U5TxBufPo+1)%U5TxBuf_Len;	 		     	  
		}
		//发送完毕，关闭发送空中断  
		if(U5TxBufPo == U5TxBufPi)
		      UART5->CR1 &= 0xFFBF;  	
		
	}
	//UART5->SR = 0xFFDF;

}

//USART5 发送流程
// 1、 待发送字节--> U5TxBuf
// 2、 开启发送空中断

U8 U5InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U5TxBuf   
{

U8 i=0;

             if(Len <= U5_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U5TxBuf[U5TxBufPi] = p[i];
				   U5TxBufPi = (U5TxBufPi +1)%U5TxBuf_Len;  //输出指针移位 
			 }	

			 if(U5TxBufPo!= U5TxBufPi)
			 {
	                       //使能UART4发送完成中断	     
                              UART5->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


/**************************************************************************************
函数名：UART5_SendData
描述　：UART5发送函数
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void UART5_SendData(uint16_t Data)
{ 
	UART5->DR = (Data & (uint16_t)0x01FF);
	while(((UART5->SR)&0x0080)==RESET);
}

 
