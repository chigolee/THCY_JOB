
extern CanTxMsg  Can1TxFBuf[Can1_TxF_BufLen];   //桢发送缓冲区
extern U8  Can1TxFBufPi;                                       //桢发送缓冲区输入指针
extern U8  Can1TxFBufPo;                                      //桢发送缓冲区输出指针	

void Can1OutTxFBuf(void);      

extern CanTxMsg  Can2TxFBuf[Can2_TxF_BufLen];   //桢发送缓冲区
extern U8  Can2TxFBufPi;                                       //桢发送缓冲区输入指针
extern U8  Can2TxFBufPo;                                      //桢发送缓冲区输出指针	

void Can2OutTxFBuf(void);      


