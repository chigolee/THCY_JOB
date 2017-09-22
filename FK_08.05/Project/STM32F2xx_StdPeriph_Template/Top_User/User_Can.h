#include "main.h"

#define Can1_TxF_BufLen   20           //发送数据帧缓冲区长度(以帧为单位计数)
extern void Can1InTxFBuf(CanTxMsg *p);     //将待发送CAN帧压入缓冲区


#define Can1_RxF_BufLen   20           //接收数据帧缓冲区长度(以帧为单位计数)
extern CanRxMsg  Can1RxFBuf[Can1_RxF_BufLen];    //桢接收缓冲区 
extern U8  Can1RxFBufPi;                                        //桢接收缓冲区输入指针
extern U8  Can1RxFBufPo;                                       //桢接收缓冲区输入指针


#define Can2_TxF_BufLen   20           //发送数据帧缓冲区长度(以帧为单位计数)
extern void Can2InTxFBuf(CanTxMsg *p);     //将待发送CAN帧压入缓冲区


#define Can2_RxF_BufLen   20           //接收数据帧缓冲区长度(以帧为单位计数)
extern CanRxMsg  Can2RxFBuf[Can2_RxF_BufLen];    //桢接收缓冲区 
extern U8  Can2RxFBufPi;                                        //桢接收缓冲区输入指针
extern U8  Can2RxFBufPo;                                       //桢接收缓冲区输入指针

 

