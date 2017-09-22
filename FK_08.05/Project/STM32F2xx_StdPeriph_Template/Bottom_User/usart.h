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
extern U8 U1TxBuf[U1TxBuf_Len];                 //����֡����������ָ��
extern U16  U1TxBufPi;	                          //���ͻ��������ָ��	
extern U16  U1TxBufPo;	                          //���ͻ���������ָ��

extern U8  U1RxBufP ;                                //���ջ�����ָ��
extern U8  U1RxBuf[U1_RxF_Len];		 //���ջ�����	

#define U2TxBuf_Len    (3*U2_TxF_Len)
extern U8 U2TxBuf[U2TxBuf_Len];                 //����֡����������ָ��
extern U16  U2TxBufPi;	                          //���ͻ��������ָ��	
extern U16  U2TxBufPo;	                          //���ͻ���������ָ��

extern U8  U2RxBufP ;                                //���ջ�����ָ��
extern U8  U2RxBuf[U2_RxF_Len];		 //���ջ�����	


#define U3TxBuf_Len    (6*U3_TxF_Len)
extern U8 U3TxBuf[U3TxBuf_Len];                 //����֡����������ָ��
extern U16  U3TxBufPi;	                          //���ͻ��������ָ��	
extern U16  U3TxBufPo;	                          //���ͻ���������ָ��

extern U8  U3RxBufP ;                                //���ջ�����ָ��
extern U8  U3RxBuf[U3_RxF_Len];		 //���ջ�����

#define U4TxBuf_Len    (10*U4_TxF_Len)
extern U8 U4TxBuf[U4TxBuf_Len];                 //����֡����������ָ��
extern U16  U4TxBufPi;	                          //���ͻ��������ָ��	
extern U16  U4TxBufPo;	                          //���ͻ���������ָ��

extern U8  U4RxBufP ;                                //���ջ�����ָ��
extern U8  U4RxBuf[U4_RxF_Len];		 //���ջ�����

#define U5TxBuf_Len    (3*U5_TxF_Len)
extern U8 U5TxBuf[U5TxBuf_Len];                 //����֡����������ָ��
extern U16  U5TxBufPi;	                          //���ͻ��������ָ��	
extern U16  U5TxBufPo;	                          //���ͻ���������ָ��

extern U8  U5RxBufP ;                                //���ջ�����ָ��
extern U8  U5RxBuf[U5_RxF_Len];		 //���ջ�����


#define U6TxBuf_Len    (3*U6_TxF_Len)
extern U8 U6TxBuf[U6TxBuf_Len];                 //����֡����������ָ��
extern U16  U6TxBufPi;	                          //���ͻ��������ָ��	
extern U16  U6TxBufPo;	                          //���ͻ���������ָ��

extern U8  U6RxBufP ;                                //���ջ�����ָ��
extern U8  U6RxBuf[U6_RxF_Len];		 //���ջ�����


/***************************************************************
**������ر���
***************************************************************/
#ifndef USARTVAR
#define USARTVAR



#endif //USARTVAR



