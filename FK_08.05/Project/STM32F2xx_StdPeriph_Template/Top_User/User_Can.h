#include "main.h"

#define Can1_TxF_BufLen   20           //��������֡����������(��֡Ϊ��λ����)
extern void Can1InTxFBuf(CanTxMsg *p);     //��������CAN֡ѹ�뻺����


#define Can1_RxF_BufLen   20           //��������֡����������(��֡Ϊ��λ����)
extern CanRxMsg  Can1RxFBuf[Can1_RxF_BufLen];    //����ջ����� 
extern U8  Can1RxFBufPi;                                        //����ջ���������ָ��
extern U8  Can1RxFBufPo;                                       //����ջ���������ָ��


#define Can2_TxF_BufLen   20           //��������֡����������(��֡Ϊ��λ����)
extern void Can2InTxFBuf(CanTxMsg *p);     //��������CAN֡ѹ�뻺����


#define Can2_RxF_BufLen   20           //��������֡����������(��֡Ϊ��λ����)
extern CanRxMsg  Can2RxFBuf[Can2_RxF_BufLen];    //����ջ����� 
extern U8  Can2RxFBufPi;                                        //����ջ���������ָ��
extern U8  Can2RxFBufPo;                                       //����ջ���������ָ��

 

