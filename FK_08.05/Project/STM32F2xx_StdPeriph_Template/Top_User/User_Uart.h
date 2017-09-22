#include "Configuration.h"	





//待发送字节
//USART 发送流程
//  将待发送帧压入帧发送缓冲区
//p     待发送数据帧指针
//Len  待发送数据长度

//第一组串口U1-U6
#define U1_TxF_Len   140           //待发送数据的单帧数据最大长度<=255
extern U8 U1InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U1TxBuf  
#define U1_RxF_Len   140           //接收数据的单帧数据最大长度<=255
#define U1_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U1RxFBuf[U1_RxF_BufLen][U1_RxF_Len+1];                 //环形帧缓冲区
extern U8 U1RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U1RxFBufPo;                 //环形帧缓冲区出口指针


#define U2_TxF_Len   248           //待发送数据的单帧数据最大长度 <=255
extern U8 U2InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U2TxBuf   
#define U2_RxF_Len   248           //接收数据的单帧数据最大长度<=255
#define U2_RxF_BufLen   3          //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U2RxFBuf[U2_RxF_BufLen][U2_RxF_Len+1];                 //环形帧缓冲区
extern U8 U2RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U2RxFBufPo;                 //环形帧缓冲区出口指针


#define U3_TxF_Len   140           //待发送数据的单帧数据最大长度 <=255
extern U8 U3InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U3TxBuf  
#define U3_RxF_Len   140           //接收数据的单帧数据最大长度<=255
#define U3_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U3RxFBuf[U3_RxF_BufLen][U3_RxF_Len+1];                 //环形帧缓冲区
extern U8 U3RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U3RxFBufPo;                 //环形帧缓冲区出口指针


#define U4_TxF_Len   32           //待发送数据的单帧数据最大长度<=255
extern U8 U4InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U4TxBuf   
#define U4_RxF_Len   32           //接收数据的单帧数据最大长度<=255
#define U4_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U4RxFBuf[U4_RxF_BufLen][U4_RxF_Len+1];                 //环形帧缓冲区
extern U8 U4RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U4RxFBufPo;                 //环形帧缓冲区出口指针


#define U5_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 U5InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U5TxBuf   
#define U5_RxF_Len   120           //接收数据的单帧数据最大长度<=255
#define U5_RxF_BufLen   5           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U5RxFBuf[U5_RxF_BufLen][U5_RxF_Len+1];                 //环形帧缓冲区
extern U8 U5RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U5RxFBufPo;                 //环形帧缓冲区出口指针

#define U6_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 U6InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U6TxBuf   
#define U6_RxF_Len   120           //接收数据的单帧数据最大长度<=255
#define U6_RxF_BufLen   5           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U6RxFBuf[U6_RxF_BufLen][U6_RxF_Len+1];                 //环形帧缓冲区
extern U8 U6RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U6RxFBufPo;                 //环形帧缓冲区出口指针

//第二组串口U7-UA
#define U7_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 U7InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U7TxBuf   
#define U7_RxF_Len   120           //接收数据的单帧数据最大长度<=255
#define U7_RxF_BufLen   5           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U7RxFBuf[U7_RxF_BufLen][U7_RxF_Len+1];                 //环形帧缓冲区
extern U8 U7RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U7RxFBufPo;                 //环形帧缓冲区出口指针

#define U8_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 U8InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U8TxBuf   
#define U8_RxF_Len   120           //接收数据的单帧数据最大长度<=255
#define U8_RxF_BufLen   5           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U8RxFBuf[U8_RxF_BufLen][U8_RxF_Len+1];                 //环形帧缓冲区
extern U8 U8RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U8RxFBufPo;                 //环形帧缓冲区出口指针

#define U9_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 U9InTxBuf(U8 *p, U8 Len);                //  待发送数据 --> U9TxBuf 
#define U9_RxF_Len   120           //接收数据的单帧数据最大长度<=255
#define U9_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 U9RxFBuf[U9_RxF_BufLen][U9_RxF_Len+1];                 //环形帧缓冲区
extern U8 U9RxFBufPi;                 //环形帧缓冲区入口指针
extern U8 U9RxFBufPo;                 //环形帧缓冲区出口指针

#define UA_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 UAInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UATxBuf   
#define UA_RxF_Len   120           //接收数据的单帧数据最大长度<=255
#define UA_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UARxFBuf[UA_RxF_BufLen][UA_RxF_Len+1];                 //环形帧缓冲区
extern U8 UARxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UARxFBufPo;                 //环形帧缓冲区出口指针

//第三组串口UB-UE
#define UB_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 UBInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UBTxBuf   
#define UB_RxF_Len   16           //接收数据的单帧数据最大长度<=255
#define UB_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UBRxFBuf[UB_RxF_BufLen][UB_RxF_Len+1];                 //环形帧缓冲区
extern U8 UBRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UBRxFBufPo;                 //环形帧缓冲区出口指针

#define UC_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 UCInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UCTxBuf   
#define UC_RxF_Len   16           //接收数据的单帧数据最大长度<=255
#define UC_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UCRxFBuf[UC_RxF_BufLen][UC_RxF_Len+1];                 //环形帧缓冲区
extern U8 UCRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UCRxFBufPo;                 //环形帧缓冲区出口指针

#define UD_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 UDInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UDTxBuf   
#define UD_RxF_Len   16           //接收数据的单帧数据最大长度<=255
#define UD_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UDRxFBuf[UD_RxF_BufLen][UD_RxF_Len+1];                 //环形帧缓冲区
extern U8 UDRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UDRxFBufPo;                 //环形帧缓冲区出口指针

#define UE_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 UEInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UETxBuf   
#define UE_RxF_Len   16           //接收数据的单帧数据最大长度<=255
#define UE_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UERxFBuf[UE_RxF_BufLen][UE_RxF_Len+1];                 //环形帧缓冲区
extern U8 UERxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UERxFBufPo;                 //环形帧缓冲区出口指针

//第四组串口UF-UI
#define UF_TxF_Len   120           //待发送数据的单帧数据最大长度<=255
extern U8 UFInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UFTxBuf   
#define UF_RxF_Len   16           //接收数据的单帧数据最大长度<=255
#define UF_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UFRxFBuf[UF_RxF_BufLen][UF_RxF_Len+1];                 //环形帧缓冲区
extern U8 UFRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UFRxFBufPo;                 //环形帧缓冲区出口指针

#define UG_TxF_Len   140           //待发送数据的单帧数据最大长度<=255
extern U8 UGInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UGTxBuf   

#define UG_RxF_Len   140           //接收数据的单帧数据最大长度<=255
#define UG_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UGRxFBuf[UG_RxF_BufLen][UG_RxF_Len+1];                 //环形帧缓冲区
extern U8 UGRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UGRxFBufPo;                 //环形帧缓冲区出口指针

#define UH_TxF_Len   140           //待发送数据的单帧数据最大长度<=255
extern U8 UHInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UHTxBuf   
#define UH_RxF_Len   140           //接收数据的单帧数据最大长度<=255
#define UH_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UHRxFBuf[UH_RxF_BufLen][UH_RxF_Len+1];                 //环形帧缓冲区
extern U8 UHRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UHRxFBufPo;                 //环形帧缓冲区出口指针

#define UI_TxF_Len   140           //待发送数据的单帧数据最大长度<=255
extern U8 UIInTxBuf(U8 *p, U8 Len);                //  待发送数据 --> UITxBuf   

#define UI_RxF_Len   140           //接收数据的单帧数据最大长度<=255
#define UI_RxF_BufLen   3           //接收数据帧缓冲区长度(以帧为单位计数)
extern U8 UIRxFBuf[UI_RxF_BufLen][UI_RxF_Len+1];                 //环形帧缓冲区
extern U8 UIRxFBufPi;                 //环形帧缓冲区入口指针
extern U8 UIRxFBufPo;                 //环形帧缓冲区出口指针






