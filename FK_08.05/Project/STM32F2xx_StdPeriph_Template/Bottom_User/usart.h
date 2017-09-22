/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/
#include "Configuration.h"	
#include "User_Uart.h"



extern void USART1_SendData(uint16_t Data);
extern void USART2_SendData(uint16_t Data);
extern void USART3_SendData(uint16_t Data);
extern void UART4_SendData(uint16_t Data);
extern void UART5_SendData(uint16_t Data);
extern void USART6_SendData(uint16_t Data);


extern int  USART1_Printf(const char *format, ...);


#define U1TxBuf_Len    (3*U1_TxF_Len)
extern U8 U1TxBuf[U1TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U1TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U1TxBufPo;	                          //发送缓冲区出口指针

extern U8  U1RxBufP ;                                //接收缓冲区指针
extern U8  U1RxBuf[U1_RxF_Len];		 //接收缓冲区	

#define U2TxBuf_Len    (3*U2_TxF_Len)
extern U8 U2TxBuf[U2TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U2TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U2TxBufPo;	                          //发送缓冲区出口指针

extern U8  U2RxBufP ;                                //接收缓冲区指针
extern U8  U2RxBuf[U2_RxF_Len];		 //接收缓冲区	


#define U3TxBuf_Len    (6*U3_TxF_Len)
extern U8 U3TxBuf[U3TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U3TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U3TxBufPo;	                          //发送缓冲区出口指针

extern U8  U3RxBufP ;                                //接收缓冲区指针
extern U8  U3RxBuf[U3_RxF_Len];		 //接收缓冲区

#define U4TxBuf_Len    (10*U4_TxF_Len)
extern U8 U4TxBuf[U4TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U4TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U4TxBufPo;	                          //发送缓冲区出口指针

extern U8  U4RxBufP ;                                //接收缓冲区指针
extern U8  U4RxBuf[U4_RxF_Len];		 //接收缓冲区

#define U5TxBuf_Len    (3*U5_TxF_Len)
extern U8 U5TxBuf[U5TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U5TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U5TxBufPo;	                          //发送缓冲区出口指针

extern U8  U5RxBufP ;                                //接收缓冲区指针
extern U8  U5RxBuf[U5_RxF_Len];		 //接收缓冲区


#define U6TxBuf_Len    (3*U6_TxF_Len)
extern U8 U6TxBuf[U6TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U6TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U6TxBufPo;	                          //发送缓冲区出口指针

extern U8  U6RxBufP ;                                //接收缓冲区指针
extern U8  U6RxBuf[U6_RxF_Len];		 //接收缓冲区


/***************************************************************
**串口相关变量
***************************************************************/
#ifndef USARTVAR
#define USARTVAR



#endif //USARTVAR



