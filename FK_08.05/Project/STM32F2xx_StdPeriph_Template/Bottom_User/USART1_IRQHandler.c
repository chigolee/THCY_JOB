/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/


#include "main.h"
           
U8 U1TxBuf[U1TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U1TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U1TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U1RxBufP = 0;                                //接收缓冲区指针
 U8  U1RxBuf[U1_RxF_Len]={0};		 //接收缓冲区	

 U8 U1RxFBuf[U1_RxF_BufLen][U1_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U1RxFBufPi  =0;                 //环形帧缓冲区入口指针
 U8 U1RxFBufPo = 0;                 //环形帧缓冲区出口指针

//USART1数据传输需求


/**************************************************************************************
函数名：USART1_IRQHandler
描述　：处理EXTI0中断的服务子程序
**************************************************************************************/



void USART1_IRQHandler(void)  
{
    U8 t;
    static U8 FLen = U1_RxF_Len;	

	while((USART1->SR)&0x0020) //是否接收中断 (接收寄存器非空)     
	{
	     t = USART1->DR;


	     if(IsSystemTest == TRUE)
	     {
	              USART1_SendData(t);
	     }
	     else
	     	{
                     if ((U1RxBufP == 0)&&(t == U1_DH0) )
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				}
					 
			else if((U1RxBufP == 1)&&(t == U1_DH1))
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				}
			
			else if(U1RxBufP == 2)
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				FLen=t+U1_Len_Plus;
				if(FLen>U1_RxF_Len)
					{FLen=U1_RxF_Len;}					
				}
			
			else if(U1RxBufP>2)
				{
				U1RxBuf[U1RxBufP] = t;
				U1RxBufP++;
				if(U1RxBufP>=FLen)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(U1RxFBuf[U1RxFBufPi], U1RxBuf,  U1RxBufP); 
				      U1RxFBuf[U1RxFBufPi][U1_RxF_Len] = U1RxBufP;		  	
				      U1RxFBufPi =  (U1RxFBufPi+1)%U1_RxF_BufLen;
				      U1RxBufP = 0;
					}
				}
			
			else
				{U1RxBufP=0;}

	     	}

	
	}
	
	 if((USART1->SR)&0x0040) //是否发送完成中断
       {            
	   			
              if(U1TxBufPo != U1TxBufPi)
             	{
                    USART1->DR = U1TxBuf[U1TxBufPo];		     
		      U1TxBufPo = (U1TxBufPo+1)%U1TxBuf_Len;	 		     	  
		}
		//发送完毕，关闭发送空中断  
		if(U1TxBufPo == U1TxBufPi)
		      USART1->CR1 &= 0xFFBF;  	
		
	}
	
	//USART1->SR = 0xFFDF;

}






//USART1 发送流程
// 1、 待发送字节--> U1TxBuf
// 2、 开启发送空中断

U8 U1InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U1TxBuf   
{

U8 i=0;

             if(Len <= U1_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U1TxBuf[U1TxBufPi] = p[i];
				   U1TxBufPi = (U1TxBufPi +1)%U1TxBuf_Len;  //输出指针移位 
			 }	

			 if(U1TxBufPo!= U1TxBufPi)
			 {
	                       //使能USART1发送完成中断	     
	                       USART1->CR1 |= 0x0040;		
			 }
			 
			 return TRUE;
             	}
		else  return FALSE;   
		
 }


/**************************************************************************************
函数名：USART1_SendData
描述　：USART1发送函数
输入　：无
输出　：无
返回　：无
**************************************************************************************/
void USART1_SendData(uint16_t Data)
{ 
	USART1->DR = (Data & (uint16_t)0x01FF);
	
	while(((USART1->SR)&0x0080)==RESET);	
}


#define MAX_TBUF1	100
char tbuf1[MAX_TBUF1]= {0, };
/****************************************************************************
* 名称：USART1_Printf()
* 功能：向串口发送一字符串 用法同Printf()函数
* 入口参数：format	要发送的字符串的指针 ... 为参数
* 出口参数：发送的字符串的字符个数
****************************************************************************/
int USART1_Printf(const char *format, ...)
{
	va_list v_list;
	char *ptr;
	int i= 0;


	va_start(v_list, format);     // Initialize variable arguments. 
	vsprintf(tbuf1, format, v_list ); 
	va_end(v_list);


	ptr= tbuf1;
	while( (*ptr) && i<MAX_TBUF1) {
		USART1_SendData( *ptr);
		ptr++;	i++;
	}//while

	return i;
}
 
