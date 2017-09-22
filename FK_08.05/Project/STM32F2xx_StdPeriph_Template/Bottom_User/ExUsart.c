
#include "main.h"

U8 U7TxBuf[U7TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U7TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U7TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U7RxBufP  = 0;                                //接收缓冲区指针
 U8  U7RxBuf[U7_RxF_Len] = {0};		 //接收缓冲区	

 U8 U7RxFBuf[U7_RxF_BufLen][U7_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U7RxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 U7RxFBufPo = 0;                 //环形帧缓冲区出口指针


U8 U8TxBuf[U8TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U8TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U8TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U8RxBufP  = 0;                                //接收缓冲区指针
 U8  U8RxBuf[U8_RxF_Len] = {0};		 //接收缓冲区	

 U8 U8RxFBuf[U8_RxF_BufLen][U8_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U8RxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 U8RxFBufPo = 0;                 //环形帧缓冲区出口指针
 
U8 U9TxBuf[U9TxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  U9TxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  U9TxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  U9RxBufP  = 0;                                //接收缓冲区指针
 U8  U9RxBuf[U9_RxF_Len] = {0};		 //接收缓冲区	

 U8 U9RxFBuf[U9_RxF_BufLen][U9_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 U9RxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 U9RxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UATxBuf[UATxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UATxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UATxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UARxBufP  = 0;                                //接收缓冲区指针
 U8  UARxBuf[UA_RxF_Len] = {0};		 //接收缓冲区	

 U8 UARxFBuf[UA_RxF_BufLen][UA_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UARxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UARxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UBTxBuf[UBTxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UBTxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UBTxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UBRxBufP  = 0;                                //接收缓冲区指针
 U8  UBRxBuf[UB_RxF_Len] = {0};		 //接收缓冲区	

 U8 UBRxFBuf[UB_RxF_BufLen][UB_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UBRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UBRxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UCTxBuf[UCTxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UCTxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UCTxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UCRxBufP  = 0;                                //接收缓冲区指针
 U8  UCRxBuf[UC_RxF_Len] = {0};		 //接收缓冲区	

 U8 UCRxFBuf[UC_RxF_BufLen][UC_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UCRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UCRxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UDTxBuf[UDTxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UDTxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UDTxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UDRxBufP  = 0;                                //接收缓冲区指针
 U8  UDRxBuf[UD_RxF_Len] = {0};		 //接收缓冲区	

 U8 UDRxFBuf[UD_RxF_BufLen][UD_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UDRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UDRxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UETxBuf[UETxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UETxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UETxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UERxBufP  = 0;                                //接收缓冲区指针
 U8  UERxBuf[UE_RxF_Len] = {0};		 //接收缓冲区	

 U8 UERxFBuf[UE_RxF_BufLen][UE_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UERxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UERxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UFTxBuf[UFTxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UFTxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UFTxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UFRxBufP  = 0;                                //接收缓冲区指针
 U8  UFRxBuf[UF_RxF_Len] = {0};		 //接收缓冲区	

 U8 UFRxFBuf[UF_RxF_BufLen][UF_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UFRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UFRxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UGTxBuf[UGTxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UGTxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UGTxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UGRxBufP  = 0;                                //接收缓冲区指针
 U8  UGRxBuf[UG_RxF_Len] = {0};		 //接收缓冲区	

 U8 UGRxFBuf[UG_RxF_BufLen][UG_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UGRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UGRxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UHTxBuf[UHTxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UHTxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UHTxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UHRxBufP  = 0;                                //接收缓冲区指针
 U8  UHRxBuf[UH_RxF_Len] = {0};		 //接收缓冲区	

 U8 UHRxFBuf[UH_RxF_BufLen][UH_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UHRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UHRxFBufPo = 0;                 //环形帧缓冲区出口指针

U8 UITxBuf[UITxBuf_Len]={0};                 //环形帧缓冲区出口指针
U16  UITxBufPi = 0;	                                 //发送缓冲区入口指针	
U16  UITxBufPo = 0;	                                 //发送缓冲区出口指针

 U8  UIRxBufP  = 0;                                //接收缓冲区指针
 U8  UIRxBuf[UI_RxF_Len] = {0};		 //接收缓冲区	

 U8 UIRxFBuf[UI_RxF_BufLen][UI_RxF_Len+1] = {0};                 //环形帧缓冲区
 U8 UIRxFBufPi = 0;                 //环形帧缓冲区入口指针
 U8 UIRxFBufPo = 0;                 //环形帧缓冲区出口指针


//USART7 发送流程
// 1、 待发送字节--> U7TxBuf
// 2、 开启发送空中断

U8 U7InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U7TxBuf   
{

U8 i=0;

             if(Len <= U7_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U7TxBuf[U7TxBufPi] = p[i];
				   U7TxBufPi = (U7TxBufPi +1)%U7TxBuf_Len;  //输出指针移位 
			 }	
			 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }


//USART8 发送流程
// 1、 待发送字节--> U8TxBuf
// 2、 开启发送空中断

U8 U8InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U8TxBuf   
{

U8 i=0;

             if(Len <= U8_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U8TxBuf[U8TxBufPi] = p[i];
				   U8TxBufPi = (U8TxBufPi +1)%U8TxBuf_Len;  //输出指针移位 
			 }	
			 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }

//USART9 发送流程
// 1、 待发送字节--> U9TxBuf
// 2、 开启发送空中断

U8 U9InTxBuf(U8 *p, U8 Len)              //  待发送数据 --> U9TxBuf   
{

U8 i=0;

             if(Len <= U9_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   U9TxBuf[U9TxBufPi] = p[i];
				   U9TxBufPi = (U9TxBufPi +1)%U9TxBuf_Len;  //输出指针移位 
			 }	
			 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }

//USARTA 发送流程
// 1、 待发送字节--> UATxBuf
// 2、 开启发送空中断

U8 UAInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UATxBuf   
{

U8 i=0;

             if(Len <= UA_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UATxBuf[UATxBufPi] = p[i];
				   UATxBufPi = (UATxBufPi +1)%UATxBuf_Len;  //输出指针移位 
			 }	
			 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }

//USARTB 发送流程
// 1、 待发送字节--> UBTxBuf
// 2、 开启发送空中断

U8 UBInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UBTxBuf   
{

U8 i=0;

             if(Len <= UB_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UBTxBuf[UBTxBufPi] = p[i];
				   UBTxBufPi = (UBTxBufPi +1)%UBTxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }


//USARTC 发送流程
// 1、 待发送字节--> UCTxBuf
// 2、 开启发送空中断

U8 UCInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UCTxBuf   
{

U8 i=0;

             if(Len <= UC_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UCTxBuf[UCTxBufPi] = p[i];
				   UCTxBufPi = (UCTxBufPi +1)%UCTxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }


//USARTD 发送流程
// 1、 待发送字节--> UDTxBuf
// 2、 开启发送空中断

U8 UDInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UDTxBuf   
{

U8 i=0;

             if(Len <= UD_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UDTxBuf[UDTxBufPi] = p[i];
				   UDTxBufPi = (UDTxBufPi +1)%UDTxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }

//USARTE 发送流程
// 1、 待发送字节--> UETxBuf
// 2、 开启发送空中断

U8 UEInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UETxBuf   
{

U8 i=0;

             if(Len <= UE_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UETxBuf[UETxBufPi] = p[i];
				   UETxBufPi = (UETxBufPi +1)%UETxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }

//USARTF 发送流程
// 1、 待发送字节--> UFTxBuf
// 2、 开启发送空中断

U8 UFInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UFTxBuf   
{

U8 i=0;

             if(Len <= UF_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UFTxBuf[UFTxBufPi] = p[i];
				   UFTxBufPi = (UFTxBufPi +1)%UFTxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }


//USARTG 发送流程
// 1、 待发送字节--> UGTxBuf
// 2、 开启发送空中断

U8 UGInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UGTxBuf   
{

U8 i=0;

             if(Len <= UG_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UGTxBuf[UGTxBufPi] = p[i];
				   UGTxBufPi = (UGTxBufPi +1)%UGTxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }


//USARTH 发送流程
// 1、 待发送字节--> UHTxBuf
// 2、 开启发送空中断

U8 UHInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UHTxBuf   
{

U8 i=0;

             if(Len <= UH_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UHTxBuf[UHTxBufPi] = p[i];
				   UHTxBufPi = (UHTxBufPi +1)%UHTxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }

//USARTI 发送流程
// 1、 待发送字节--> UITxBuf
// 2、 开启发送空中断

U8 UIInTxBuf(U8 *p, U8 Len)              //  待发送数据 --> UITxBuf   
{

U8 i=0;

             if(Len <= UI_TxF_Len)
             {
			for(i=0;i<Len;i++)			
			 {
				   UITxBuf[UITxBufPi] = p[i];
				   UITxBufPi = (UITxBufPi +1)%UITxBuf_Len;  //输出指针移位 
			 }				 			 
			 return TRUE;
             	}
		else  return FALSE;   		
 }


 void U7_SendData(U8 Data)
 {
       Max14830ASendDat(0,Data);   
 }

  void U8_SendData(U8 Data)
 {
       Max14830ASendDat(1,Data);   
 }

 void U9_SendData(U8 Data)
 {
       Max14830ASendDat(2,Data);   
 }

void UA_SendData(U8 Data)
 {
       Max14830ASendDat(3,Data);   
 }

void UB_SendData(U8 Data)
 {
       Max14830BSendDat(0,Data);   
 }
void UC_SendData(U8 Data)
 {
       Max14830BSendDat(1,Data);   
 }
void UD_SendData(U8 Data)
 {
       Max14830BSendDat(2,Data);   
 }
void UE_SendData(U8 Data)
 {
       Max14830BSendDat(3,Data);   
 }

void UF_SendData(U8 Data)
 {
       Max14830CSendDat(0,Data);   
 }
void UG_SendData(U8 Data)
 {
       Max14830CSendDat(1,Data);   
 }
void UH_SendData(U8 Data)
 {
       Max14830CSendDat(2,Data);   
 }

void UI_SendData(U8 Data)
 {
       Max14830CSendDat(3,Data);   
 }




U8 i_ForExUsart=0;			//8连发用


void ExUsartTXD(void)  //外部扩展串口发送
{
       //第二组串口U7-UA
       if(U7TxBufPo != U7TxBufPi)	   
       {               
	      Max14830ASendDat(0,U7TxBuf[U7TxBufPo]);
	      U7TxBufPo = (U7TxBufPo+1)%U7TxBuf_Len;			       	  
       }
	if(U8TxBufPo != U8TxBufPi)	   
       {               
	      Max14830ASendDat(1,U8TxBuf[U8TxBufPo]);
	      U8TxBufPo = (U8TxBufPo+1)%U8TxBuf_Len;			       	  
       }


	
	if(U9TxBufPo != U9TxBufPi)	 
       {        
		for(i_ForExUsart=0;i_ForExUsart<18;i_ForExUsart++)
			{
			if(U9TxBufPo != U9TxBufPi)	 
				{
				Max14830ASendDat(2,U9TxBuf[U9TxBufPo]);
	      			U9TxBufPo = (U9TxBufPo+1)%U9TxBuf_Len;	
				}
			else
				{break;}
			}
       }


	if(UATxBufPo != UATxBufPi)
		{
		Max14830ASendDat(3,UATxBuf[UATxBufPo]);
	      	UATxBufPo = (UATxBufPo+1)%UATxBuf_Len;	

		}


	if(UBTxBufPo != UBTxBufPi)	   
       {               
		Max14830BSendDat(0,UBTxBuf[UBTxBufPo]);
	      	UBTxBufPo = (UBTxBufPo+1)%UBTxBuf_Len;		
       }




	if(UCTxBufPo != UCTxBufPi)
		{
		Max14830BSendDat(1,UCTxBuf[UCTxBufPo]);
	      	UCTxBufPo = (UCTxBufPo+1)%UCTxBuf_Len;		
		}



	if(UDTxBufPo != UDTxBufPi)	   
     	  	{            
		Max14830BSendDat(2,UDTxBuf[UDTxBufPo]);
	      	UDTxBufPo = (UDTxBufPo+1)%UDTxBuf_Len;			
       	}



	if(UETxBufPo != UETxBufPi)	   
	       {            
		Max14830BSendDat(3,UETxBuf[UETxBufPo]);
		UETxBufPo = (UETxBufPo+1)%UETxBuf_Len;			
	       }

	
	//第四组串口UF-UI
	if(UFTxBufPo != UFTxBufPi)	   
	       {            
		Max14830CSendDat(0,UFTxBuf[UFTxBufPo]);
		UFTxBufPo = (UFTxBufPo+1)%UFTxBuf_Len;			     
	       }




//矢量装置，连发8字节
	if(UGTxBufPo != UGTxBufPi)	   
       {            
		for(i_ForExUsart=0;i_ForExUsart<8;i_ForExUsart++)
			{
			if(UGTxBufPo != UGTxBufPi)
				{Max14830CSendDat(1,UGTxBuf[UGTxBufPo]);
	      			UGTxBufPo = (UGTxBufPo+1)%UGTxBuf_Len;		
				}
			else
				{break;}
			}
       }



	
	if(UHTxBufPo != UHTxBufPi)	   
       {               
	      Max14830CSendDat(2,UHTxBuf[UHTxBufPo]);
	      UHTxBufPo = (UHTxBufPo+1)%UHTxBuf_Len;			       	  
       }
	if(UITxBufPo != UITxBufPi)	   
       {               
	      Max14830CSendDat(3,UITxBuf[UITxBufPo]);
	      UITxBufPo = (UITxBufPo+1)%UITxBuf_Len;			       	  
       }   

}




void U7_RecData(U8 Data)
{
	U8 t;
	static U8 FLen = U7_RxF_Len;	
	static U8 FramFlag = 0;	// 1-采集器数据接收中；2-北斗数据接收中


            t = Data;		
			
            if(IsSystemTest == TRUE)
	     {
	              U7_SendData(t);
	     }
	     else
			{
			if(FramFlag<=1)	//未接收、接收采集器数据状态
				{			
				if(U7RxBufP == 0)
					{
					if(t == U_5678_DH0)
						{
						U7RxBuf[U7RxBufP] = t;
						U7RxBufP++;
						FramFlag=1;
						}
					else if(t == U_5678_BDStart)
						{
						U7RxBuf[U7RxBufP] = t;
						U7RxBufP++;
						FramFlag=2;
						}
					}
				
				else if((U7RxBufP == 1)&&(t == U_5678_DH1))
					{
					U7RxBuf[U7RxBufP] = t;
					U7RxBufP++;
					}
				
				else if(U7RxBufP>=2)
					{
					U7RxBuf[U7RxBufP] = t;
					U7RxBufP++;
					if(U7RxBufP>=U_5678_Length)	//收满一帧
						{
						//收满一帧	   
						memcpy(U7RxFBuf[U7RxFBufPi], U7RxBuf,  U7RxBufP); 
						U7RxFBuf[U7RxFBufPi][U7_RxF_Len] = U7RxBufP;		  	
						U7RxFBufPi =  (U7RxFBufPi+1)%U7_RxF_BufLen;
						U7RxBufP = 0;	FramFlag=0;
						}
					}
				
				else
					{U7RxBufP=0;	FramFlag=0;}				

				}
			
			else		//接收北斗数据状态
				{
				if(t == U_5678_DH0)
					{
					U7RxBufP=0;
					U7RxBuf[U7RxBufP] = t;
					U7RxBufP++;
					FramFlag=1;
					}
				else if(t ==U_5678_BDStart)
					{
					U7RxBufP=0;
					U7RxBuf[U7RxBufP] = t;
					U7RxBufP++;
					FramFlag=2;
					}
				
				else if(t==U_5678_BDEnd)
					{
					U7RxBuf[U7RxBufP] = t;
					U7RxBufP++;
					//收满一帧	   
					memcpy(U7RxFBuf[U7RxFBufPi], U7RxBuf,  U7RxBufP); 
					U7RxFBuf[U7RxFBufPi][U7_RxF_Len] = U7RxBufP;		  	
					U7RxFBufPi =  (U7RxFBufPi+1)%U7_RxF_BufLen;
					U7RxBufP = 0;	FramFlag=0;
					}
				else
					{
					U7RxBuf[U7RxBufP] = t;
					U7RxBufP++;
					if(U7RxBufP>=U7_RxF_Len)
						{                                //收错一帧，不要了	   
						U7RxBufP = 0;	FramFlag=0;
						}
					}

				}
			
		     	}

		 
	     
   
}
void U8_RecData(U8 Data)
{

	U8 t;
	static U8 FLen = U8_RxF_Len;	
	static U8 FramFlag = 0;	// 1-采集器数据接收中；2-北斗数据接收中


            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              U8_SendData(t);
	     }
            else
			{
			if(FramFlag<=1)	//未接收、接收采集器数据状态
				{			
				if(U8RxBufP == 0)
					{
					if(t == U_5678_DH0)
						{
						U8RxBuf[U8RxBufP] = t;
						U8RxBufP++;
						FramFlag=1;
						}
					else if(t == U_5678_BDStart)
						{
						U8RxBuf[U8RxBufP] = t;
						U8RxBufP++;
						FramFlag=2;
						}
					}
				
				else if((U8RxBufP == 1)&&(t == U_5678_DH1))
					{
					U8RxBuf[U8RxBufP] = t;
					U8RxBufP++;
					}
				
				else if(U8RxBufP>=2)
					{
					U8RxBuf[U8RxBufP] = t;
					U8RxBufP++;
					if(U8RxBufP>=U_5678_Length)	//收满一帧
						{
						//收满一帧	   
						memcpy(U8RxFBuf[U8RxFBufPi], U8RxBuf,  U8RxBufP); 
						U8RxFBuf[U8RxFBufPi][U8_RxF_Len] = U8RxBufP;		  	
						U8RxFBufPi =  (U8RxFBufPi+1)%U8_RxF_BufLen;
						U8RxBufP = 0;	FramFlag=0;
						}
					}
				
				else
					{U8RxBufP=0;	FramFlag=0;}				

				}
			
			else		//接收北斗数据状态
				{
				if(t == U_5678_DH0)
					{
					U8RxBufP=0;
					U8RxBuf[U8RxBufP] = t;
					U8RxBufP++;
					FramFlag=1;
					}
				else if(t ==U_5678_BDStart)
					{
					U8RxBufP=0;
					U8RxBuf[U8RxBufP] = t;
					U8RxBufP++;
					FramFlag=2;
					}				
				
				else if(t==U_5678_BDEnd)
					{
					U8RxBuf[U8RxBufP] = t;
					U8RxBufP++;
					//收满一帧	   
					memcpy(U8RxFBuf[U8RxFBufPi], U8RxBuf,  U8RxBufP); 
					U8RxFBuf[U8RxFBufPi][U8_RxF_Len] = U8RxBufP;		  	
					U8RxFBufPi =  (U8RxFBufPi+1)%U8_RxF_BufLen;
					U8RxBufP = 0;	FramFlag=0;
					}
				else
					{
					U8RxBuf[U8RxBufP] = t;
					U8RxBufP++;
					if(U8RxBufP>=U8_RxF_Len)
						{                                //收错一帧，不要了	   
						U8RxBufP = 0;	FramFlag=0;
						}
					}

				}
			
		     	}         
   
}




void U9_RecData(U8 Data)
{
U8 t;
static U8 FLen = U9_RxF_Len;	


            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              U9_SendData(t);
	     }
            else
	     	{
                     if ((U9RxBufP == 0)&&(t == U9_DH0) )
				{
				U9RxBuf[U9RxBufP] = t;
				U9RxBufP++;
				}
                     else if ((U9RxBufP == 1)&&(t == U9_DH1) )
				{
				U9RxBuf[U9RxBufP] = t;
				U9RxBufP++;
				}
			 
			else if(U9RxBufP>=2)
				{
				U9RxBuf[U9RxBufP] = t;
				U9RxBufP++;
				if(U9RxBufP>=U9_Length)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(U9RxFBuf[U9RxFBufPi], U9RxBuf,  U9RxBufP); 
				      U9RxFBuf[U9RxFBufPi][U9_RxF_Len] = U9RxBufP;		  	
				      U9RxFBufPi =  (U9RxFBufPi+1)%U9_RxF_BufLen;
				      U9RxBufP = 0;					  
					}
				}
			
			else
				{U9RxBufP=0;}

	     	}

			
   
}




void UA_RecData(U8 Data)
{
U8 t;
static U8 FLen = UA_RxF_Len;	
static U8 Flag =0;
static U8 UA_Len_Data[2] ={0};
            t = Data;
			
             if(IsSystemTest == TRUE)
	     {
	              UA_SendData(t);
	     }
            else
	     	{
                     if ((UARxBufP == 0)&&(t == UA_DH0_1) )
				{
				UARxBuf[UARxBufP] = t;
				UARxBufP++;
				}

                     else if ((UARxBufP == 1)&&(t == UA_DH0_2) )
				{
				UARxBuf[UARxBufP] = t;
				UARxBufP++;
				}
					 
			else if(UARxBufP == 2)
				{
				//附加长度确定
				if(t==UA_D1_H1)
					{
					Flag=UA_D1_H1;	
					UARxBuf[UARxBufP] = t;
					UARxBufP++;
					}
				else if(t==UA_D2_H1)
					{
					Flag=UA_D2_H1;
					UARxBuf[UARxBufP] = t;
					UARxBufP++;					
					}
				else
					{UARxBufP=0;}
				}
			
			else if(UARxBufP >= 3)
				{
				if((UARxBufP==UA_LengPosi_1)&&(Flag==UA_D1_H1))
					{
					FLen=t+UA_Len_Plus_1;
					if(FLen>UA_RxF_Len){FLen = UA_RxF_Len;}	
					}
				else if ((UARxBufP==UA_LengPosi_2)&&(Flag==UA_D2_H1))
					{
					FLen=t+UA_Len_Plus_2;
					if(FLen>UA_RxF_Len){FLen = UA_RxF_Len;}	
					}

                            UARxBuf[UARxBufP] = t;
			       UARxBufP++;

				if(UARxBufP>=FLen)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UARxFBuf[UARxFBufPi], UARxBuf,  UARxBufP); 
				      UARxFBuf[UARxFBufPi][UA_RxF_Len] = UARxBufP;		  	
				      UARxFBufPi =  (UARxFBufPi+1)%UA_RxF_BufLen;
				      UARxBufP = 0;
					}
				}
			
			else
				{UARxBufP=0;}

	     	}			
   
}





void UB_RecData(U8 Data)
{
U8 t;
static U8 FLen = UB_RxF_Len;	

            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UB_SendData(t);
	     }
            else
	     	{
                     if ((UBRxBufP == 0)&&(t == U_BCDEF_DH0) )
				{
				UBRxBuf[UBRxBufP] = t;
				UBRxBufP++;
				}
					 
			else if((UBRxBufP == 1)&&(t == U_BCDEF_DH1))
				{
				UBRxBuf[UBRxBufP] = t;
				UBRxBufP++;
				}
			
			else if(UBRxBufP>=2)
				{
				UBRxBuf[UBRxBufP] = t;
				UBRxBufP++;
				if(UBRxBufP>=U_BCDEF_Length)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UBRxFBuf[UBRxFBufPi], UBRxBuf,  UBRxBufP); 
				      UBRxFBuf[UBRxFBufPi][UB_RxF_Len] = UBRxBufP;		  	
				      UBRxFBufPi =  (UBRxFBufPi+1)%UB_RxF_BufLen;
				      UBRxBufP = 0;
					}
				}
			
			else
				{UBRxBufP=0;}

	     	}
			
}






void UC_RecData(U8 Data)
{
U8 t;
static U8 FLen = UC_RxF_Len;	

            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UC_SendData(t);
	     }
            else
	     	{
                     if ((UCRxBufP == 0)&&(t == U_BCDEF_DH0) )
				{
				UCRxBuf[UCRxBufP] = t;
				UCRxBufP++;
				}
					 
			else if((UCRxBufP == 1)&&(t == U_BCDEF_DH1))
				{
				UCRxBuf[UCRxBufP] = t;
				UCRxBufP++;
				}
			
			else if(UCRxBufP>=2)
				{
				UCRxBuf[UCRxBufP] = t;
				UCRxBufP++;
				if(UCRxBufP>=U_BCDEF_Length)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UCRxFBuf[UCRxFBufPi], UCRxBuf,  UCRxBufP); 
				      UCRxFBuf[UCRxFBufPi][UC_RxF_Len] = UCRxBufP;		  	
				      UCRxFBufPi =  (UCRxFBufPi+1)%UC_RxF_BufLen;
				      UCRxBufP = 0;
					}
				}
			
			else
				{UCRxBufP=0;}

	     	}			
   
}



void UD_RecData(U8 Data)
{
U8 t;
static U8 FLen = UD_RxF_Len;	

            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UD_SendData(t);
	     }
            else
	     	{
                     if ((UDRxBufP == 0)&&(t == U_BCDEF_DH0) )
				{
				UDRxBuf[UDRxBufP] = t;
				UDRxBufP++;
				}
					 
			else if((UDRxBufP == 1)&&(t == U_BCDEF_DH1))
				{
				UDRxBuf[UDRxBufP] = t;
				UDRxBufP++;
				}
			
			else if(UDRxBufP>=2)
				{
				UDRxBuf[UDRxBufP] = t;
				UDRxBufP++;
				if(UDRxBufP>=U_BCDEF_Length)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UDRxFBuf[UDRxFBufPi], UDRxBuf,  UDRxBufP); 
				      UDRxFBuf[UDRxFBufPi][UD_RxF_Len] = UDRxBufP;		  	
				      UDRxFBufPi =  (UDRxFBufPi+1)%UD_RxF_BufLen;
				      UDRxBufP = 0;
					}
				}
			
			else
				{UDRxBufP=0;}

	     	}			
   
}





void UE_RecData(U8 Data)
{
U8 t;
static U8 FLen = UE_RxF_Len;	

            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UE_SendData(t);
	     }
            else
	     	{
                     if ((UERxBufP == 0)&&(t == U_BCDEF_DH0) )
				{
				UERxBuf[UERxBufP] = t;
				UERxBufP++;
				}
					 
			else if((UERxBufP == 1)&&(t == U_BCDEF_DH1))
				{
				UERxBuf[UERxBufP] = t;
				UERxBufP++;
				}
			
			else if(UERxBufP>=2)
				{
				UERxBuf[UERxBufP] = t;
				UERxBufP++;
				if(UERxBufP>=U_BCDEF_Length)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UERxFBuf[UERxFBufPi], UERxBuf,  UERxBufP); 
				      UERxFBuf[UERxFBufPi][UE_RxF_Len] = UERxBufP;		  	
				      UERxFBufPi =  (UERxFBufPi+1)%UE_RxF_BufLen;
				      UERxBufP = 0;
					}
				}
			
			else
				{UERxBufP=0;}

	     	}		
   
}








void UF_RecData(U8 Data)
{
U8 t;
static U8 FLen = UF_RxF_Len;	


            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UF_SendData(t);
	     }
            else
	     	{	     				
                     if ((UFRxBufP == 0)&&(t == U_BCDEF_DH0) )
				{
				UFRxBuf[UFRxBufP] = t;
				UFRxBufP++;
				}
					 
			else if((UFRxBufP == 1)&&(t == U_BCDEF_DH1))
				{
				UFRxBuf[UFRxBufP] = t;
				UFRxBufP++;
				}
			
			else if(UFRxBufP>=2)
				{
				UFRxBuf[UFRxBufP] = t;
				UFRxBufP++;
				if(UFRxBufP>=U_BCDEF_Length)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UFRxFBuf[UFRxFBufPi], UFRxBuf,  UFRxBufP); 
				      UFRxFBuf[UFRxFBufPi][UF_RxF_Len] = UFRxBufP;		  	
				      UFRxFBufPi =  (UFRxFBufPi+1)%UF_RxF_BufLen;
				      UFRxBufP = 0;
					}
				}
			
			else
				{UFRxBufP=0;}

	     	}   
}





void UG_RecData(U8 Data)
{
U8 t;
static U8 FLen = UG_RxF_Len;	
static U8 Flag =0;


            t = Data;

       if(IsSystemTest == TRUE)
	     {
	              UG_SendData(t);
	     }
            else
	     {
		 
                     if ((t == UG_DH0) && (UGRxBufP == 0))
				{
				UGRxBuf[UGRxBufP] = t;
				UGRxBufP++;
				}
					 
			else if (UGRxBufP == 1)
				{
				if (t == UG_DH1_1)
					{
					UGRxBuf[UGRxBufP] = t;
					UGRxBufP++;
					Flag=UG_DH1_1;						
					}
				else if (t == UG_DH1_2)
					{
					UGRxBuf[UGRxBufP] = t;
					UGRxBufP++;
					Flag  =UG_DH1_2;
					FLen=UG_Len_2;
					}
				else
					{
					UGRxBufP = 0;
					}
				}

			else if (UGRxBufP == UG_Len_1_Addr)
				{
				UGRxBuf[UGRxBufP] = t;
				UGRxBufP++;

				if(Flag==UG_DH1_1)
					{
					FLen=t+5;
					if(FLen>UG_RxF_Len)
						{UGRxBufP=0;}
					}
				}

			else	
				{
				UGRxBuf[UGRxBufP] = t;
				UGRxBufP++;
				}



			if(UGRxBufP >= FLen)
				{
				//收满一帧	   
				memcpy(UGRxFBuf[UGRxFBufPi], UGRxBuf,  UGRxBufP); 
				UGRxFBuf[UGRxFBufPi][UG_RxF_Len] = UGRxBufP;		  	
				UGRxFBufPi =  (UGRxFBufPi+1)%UG_RxF_BufLen;
				UGRxBufP = 0;
				}
					
	     }

			
   
}


void UH_RecData(U8 Data)
{
 U8 t;
 static U8 FLen = UH_RxF_Len;	

            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UH_SendData(t);
	     }
            else
	     	{
                     if ((UHRxBufP == 0)&&(t == UH_DH0) )
				{
				UHRxBuf[UHRxBufP] = t;
				UHRxBufP++;
				}
					 
			else if((UHRxBufP == 1)&&(t == UH_DH1))
				{
				UHRxBuf[UHRxBufP] = t;
				UHRxBufP++;
				}
			
			else if(UHRxBufP == 2)
				{
				UHRxBuf[UHRxBufP] = t;
				UHRxBufP++;
				FLen=t+UH_Len_Plus;
				if(FLen>UH_RxF_Len)
					{FLen=UH_RxF_Len;}					
				}
			
			else if(UHRxBufP>2)
				{
				UHRxBuf[UHRxBufP] = t;
				UHRxBufP++;
				if(UHRxBufP>=FLen)	//收满一帧
					{
                                  //收满一帧	   
				      memcpy(UHRxFBuf[UHRxFBufPi], UHRxBuf,  UHRxBufP); 
				      UHRxFBuf[UHRxFBufPi][UH_RxF_Len] = UHRxBufP;		  	
				      UHRxFBufPi =  (UHRxFBufPi+1)%UH_RxF_BufLen;
				      UHRxBufP = 0;
					}
				}
			
			else
				{UHRxBufP=0;}

	     	}		 
   
}




void UI_RecData(U8 Data)
{
U8 t;
static U8 Flag =0;


            t = Data;
           
             if(IsSystemTest == TRUE)
	     {
	              UI_SendData(t);
	     }
            else
	     	{
                     
	     	}   
}





void ExUsartRXD(void)  //外部扩展串口接收
{

         if(Max14830A_RPo[0] != Max14830A_RPi[0])
         {
                 U7_RecData(Max14830A_RBuf[0][Max14830A_RPo[0]]);    
                 Max14830A_RPo[0] = (Max14830A_RPo[0]+1)%Max14830_RBufLen;
	  }
	  if(Max14830A_RPo[1] != Max14830A_RPi[1])
         {
                 U8_RecData(Max14830A_RBuf[1][Max14830A_RPo[1]]);    
                 Max14830A_RPo[1] = (Max14830A_RPo[1]+1)%Max14830_RBufLen;	  }
	  if(Max14830A_RPo[2] != Max14830A_RPi[2])
         {
                 U9_RecData(Max14830A_RBuf[2][Max14830A_RPo[2]]);    
                 Max14830A_RPo[2] = (Max14830A_RPo[2]+1)%Max14830_RBufLen;
	  }
	  if(Max14830A_RPo[3] != Max14830A_RPi[3])
         {
                 UA_RecData(Max14830A_RBuf[3][Max14830A_RPo[3]]);    
                 Max14830A_RPo[3] = (Max14830A_RPo[3]+1)%Max14830_RBufLen;
	  }
	  
 	  if(Max14830B_RPo[0] != Max14830B_RPi[0])
         {
                 UB_RecData(Max14830B_RBuf[0][Max14830B_RPo[0]]);    
                 Max14830B_RPo[0] = (Max14830B_RPo[0]+1)%Max14830_RBufLen;
	  }
	  if(Max14830B_RPo[1] != Max14830B_RPi[1])
         {
                 UC_RecData(Max14830B_RBuf[1][Max14830B_RPo[1]]);    
                 Max14830B_RPo[1] = (Max14830B_RPo[1]+1)%Max14830_RBufLen;	  }
	  if(Max14830B_RPo[2] != Max14830B_RPi[2])
         {
                 UD_RecData(Max14830B_RBuf[2][Max14830B_RPo[2]]);    
                 Max14830B_RPo[2] = (Max14830B_RPo[2]+1)%Max14830_RBufLen;
	  }
	  if(Max14830B_RPo[3] != Max14830B_RPi[3])
         {
                 UE_RecData(Max14830B_RBuf[3][Max14830B_RPo[3]]);    
                 Max14830B_RPo[3] = (Max14830B_RPo[3]+1)%Max14830_RBufLen;
	  }

	  if(Max14830C_RPo[0] != Max14830C_RPi[0])
         {
                 UF_RecData(Max14830C_RBuf[0][Max14830C_RPo[0]]);    
                 Max14830C_RPo[0] = (Max14830C_RPo[0]+1)%Max14830_RBufLen;
	  }
	  if(Max14830C_RPo[1] != Max14830C_RPi[1])
         {
                 UG_RecData(Max14830C_RBuf[1][Max14830C_RPo[1]]);    
                 Max14830C_RPo[1] = (Max14830C_RPo[1]+1)%Max14830_RBufLen;	  }
	  if(Max14830C_RPo[2] != Max14830C_RPi[2])
         {
                 UH_RecData(Max14830C_RBuf[2][Max14830C_RPo[2]]);    
                 Max14830C_RPo[2] = (Max14830C_RPo[2]+1)%Max14830_RBufLen;
	  }
	  if(Max14830C_RPo[3] != Max14830C_RPi[3])
         {
                 UI_RecData(Max14830C_RBuf[3][Max14830C_RPo[3]]);    
                 Max14830C_RPo[3] = (Max14830C_RPo[3]+1)%Max14830_RBufLen;
	  }

}

void ExUsartIRQ(void)  //外部扩展串口接收中断处理
{
  u8 uart_num = 0, port = 0;//max14830
  u8 RFIFOCn=0;

     if(!MAX14830A_IRQ)
	  {
	      //MAX14830A数据接收
		uart_num = Max14830AReadIRQ();
		for(port = 0; port < 4; port++)
		{
			if((~uart_num) & (1<<port))// 如果该串口有中断
			{			       	       
				if(Max14830AReadISR(port)&0x40)
				{
				      while(RFIFOCn = Max14830ARFIFOCnt(port))
				      	{
					      
					      Max14830ARcvFifo(port,Max14830A_RBuf[port],RFIFOCn);					      
					      /*
					      测试用，收发闭环
					      while(Max14830A_RPo[port] != Max14830A_RPi[port])
						{
							Max14830ASendDat(port, Max14830A_RBuf[port][Max14830A_RPo[port] ]);
							Max14830A_RPo[port] = (Max14830A_RPo[port]+1)%Max14830_RBufLen;
						}  
						*/					     
				      	}
				}
				
			}
		}
	  }  
	  
  	  if(!MAX14830B_IRQ)
	  {
		uart_num = Max14830BReadIRQ();
		for(port = 0; port < 4; port++)
		{
			if((~uart_num) & (1<<port))// 如果该串口有中断
			{			      		       
				if(Max14830BReadISR(port)&0x40)
				{
				      while(RFIFOCn = Max14830BRFIFOCnt(port))
				      	{					      
					      Max14830BRcvFifo(port,Max14830B_RBuf[port],RFIFOCn);

					       /*
					      测试用，收发闭环
					      while(Max14830B_RPo[port] != Max14830B_RPi[port])
						{
							Max14830BSendDat(port, Max14830B_RBuf[port][Max14830B_RPo[port] ]);
							Max14830B_RPo[port] = (Max14830B_RPo[port]+1)%Max14830_RBufLen;
						}  
						*/					      
				      	}
				}
				
			}
		}
	  }
	  if(!MAX14830C_IRQ)
	  {
		uart_num = Max14830CReadIRQ();
		for(port = 0; port < 4; port++)
		{
			if((~uart_num) & (1<<port))// 如果该串口有中断
			{			       		       
				if(Max14830CReadISR(port)&0x40)
				{
				      while(RFIFOCn = Max14830CRFIFOCnt(port))
				      	{					      
					      Max14830CRcvFifo(port,Max14830C_RBuf[port],RFIFOCn);
					       /*
					      测试用，收发闭环
					      while(Max14830C_RPo[port] != Max14830C_RPi[port])
						{
							Max14830CSendDat(port, Max14830C_RBuf[port][Max14830C_RPo[port] ]);
							Max14830C_RPo[port] = (Max14830C_RPo[port]+1)%Max14830_RBufLen;
						}  
					      */
				      	}
				}
				
			}
		}
	  }


}






