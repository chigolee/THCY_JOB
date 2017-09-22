//第二组串口U7-UA
#define U7TxBuf_Len    (3*U7_TxF_Len)
extern U8 U7TxBuf[U7TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U7TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U7TxBufPo;	                          //发送缓冲区出口指针

extern U8  U7RxBufP ;                                //接收缓冲区指针
extern U8  U7RxBuf[U7_RxF_Len];		 //接收缓冲区	

#define U8TxBuf_Len    (3*U8_TxF_Len)
extern U8 U8TxBuf[U8TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U8TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U8TxBufPo;	                          //发送缓冲区出口指针

extern U8  U8RxBufP ;                                //接收缓冲区指针
extern U8  U8RxBuf[U8_RxF_Len];		 //接收缓冲区	

#define U9TxBuf_Len    (3*U9_TxF_Len)
extern U8 U9TxBuf[U9TxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  U9TxBufPi;	                          //发送缓冲区入口指针	
extern U16  U9TxBufPo;	                          //发送缓冲区出口指针

extern U8  U9RxBufP ;                                //接收缓冲区指针
extern U8  U9RxBuf[U9_RxF_Len];		 //接收缓冲区	

#define UATxBuf_Len    (3*UA_TxF_Len)
extern U8 UATxBuf[UATxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UATxBufPi;	                          //发送缓冲区入口指针	
extern U16  UATxBufPo;	                          //发送缓冲区出口指针

extern U8  UARxBufP ;                                //接收缓冲区指针
extern U8  UARxBuf[UA_RxF_Len];		 //接收缓冲区	

//第三组串口UB-UE
#define UBTxBuf_Len    (3*UB_TxF_Len)
extern U8 UBTxBuf[UBTxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UBTxBufPi;	                          //发送缓冲区入口指针	
extern U16  UBTxBufPo;	                          //发送缓冲区出口指针

extern U8  UBRxBufP ;                                //接收缓冲区指针
extern U8  UBRxBuf[UB_RxF_Len];		 //接收缓冲区	

#define UCTxBuf_Len    (3*UC_TxF_Len)
extern U8 UCTxBuf[UCTxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UCTxBufPi;	                          //发送缓冲区入口指针	
extern U16  UCTxBufPo;	                          //发送缓冲区出口指针

extern U8  UCRxBufP ;                                //接收缓冲区指针
extern U8  UCRxBuf[UC_RxF_Len];		 //接收缓冲区	

#define UDTxBuf_Len    (3*UD_TxF_Len)
extern U8 UDTxBuf[UDTxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UDTxBufPi;	                          //发送缓冲区入口指针	
extern U16  UDTxBufPo;	                          //发送缓冲区出口指针

extern U8  UDRxBufP ;                                //接收缓冲区指针
extern U8  UDRxBuf[UD_RxF_Len];		 //接收缓冲区	

#define UETxBuf_Len    (3*UE_TxF_Len)
extern U8 UETxBuf[UETxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UETxBufPi;	                          //发送缓冲区入口指针	
extern U16  UETxBufPo;	                          //发送缓冲区出口指针

extern U8  UERxBufP ;                                //接收缓冲区指针
extern U8  UERxBuf[UE_RxF_Len];		 //接收缓冲区	

//第四组串口UF-UI
#define UFTxBuf_Len    (3*UF_TxF_Len)
extern U8 UFTxBuf[UFTxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UFTxBufPi;	                          //发送缓冲区入口指针	
extern U16  UFTxBufPo;	                          //发送缓冲区出口指针

extern U8  UFRxBufP ;                                //接收缓冲区指针
extern U8  UFRxBuf[UF_RxF_Len];		 //接收缓冲区	

#define UGTxBuf_Len    (3*UG_TxF_Len)
extern U8 UGTxBuf[UGTxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UGTxBufPi;	                          //发送缓冲区入口指针	
extern U16  UGTxBufPo;	                          //发送缓冲区出口指针

extern U8  UGRxBufP ;                                //接收缓冲区指针
extern U8  UGRxBuf[UG_RxF_Len];		 //接收缓冲区	

#define UHTxBuf_Len    (3*UH_TxF_Len)
extern U8 UHTxBuf[UHTxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UHTxBufPi;	                          //发送缓冲区入口指针	
extern U16  UHTxBufPo;	                          //发送缓冲区出口指针

extern U8  UHRxBufP ;                                //接收缓冲区指针
extern U8  UHRxBuf[UH_RxF_Len];		 //接收缓冲区	

#define UITxBuf_Len    (3*UI_TxF_Len)
extern U8 UITxBuf[UITxBuf_Len];                 //环形帧缓冲区出口指针
extern U16  UITxBufPi;	                          //发送缓冲区入口指针	
extern U16  UITxBufPo;	                          //发送缓冲区出口指针

extern U8  UIRxBufP ;                                //接收缓冲区指针
extern U8  UIRxBuf[UI_RxF_Len];		 //接收缓冲区	


extern void U7_SendData(U8 Data);
extern void U8_SendData(U8 Data);
extern void U9_SendData(U8 Data);
extern void UA_SendData(U8 Data);
extern void UB_SendData(U8 Data);
extern void UC_SendData(U8 Data);
extern void UD_SendData(U8 Data);
extern void UE_SendData(U8 Data);
extern void UF_SendData(U8 Data);
extern void UG_SendData(U8 Data);
extern void UH_SendData(U8 Data);
extern void UI_SendData(U8 Data);
extern void U7_SendData(U8 Data);

extern void U7_RecData(U8 Data);
extern void U8_RecData(U8 Data);
extern void U9_RecData(U8 Data);
extern void UA_RecData(U8 Data);
extern void UB_RecData(U8 Data);
extern void UC_RecData(U8 Data);
extern void UD_RecData(U8 Data);
extern void UE_RecData(U8 Data);
extern void UF_RecData(U8 Data);
extern void UG_RecData(U8 Data);
extern void UH_RecData(U8 Data);
extern void UI_RecData(U8 Data);


extern void ExUsartTXD(void);  //外部扩展串口发送
extern void ExUsartRXD(void);  //外部扩展串口接收
extern void ExUsartIRQ(void);  //外部扩展串口接收中断处理


