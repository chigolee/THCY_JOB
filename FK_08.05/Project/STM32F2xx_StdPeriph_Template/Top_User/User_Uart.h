#include "Configuration.h"	





//�������ֽ�
//USART ��������
//  ��������֡ѹ��֡���ͻ�����
//p     ����������ָ֡��
//Len  ���������ݳ���

//��һ�鴮��U1-U6
#define U1_TxF_Len   140           //���������ݵĵ�֡������󳤶�<=255
extern U8 U1InTxBuf(U8 *p, U8 Len);                //  ���������� --> U1TxBuf  
#define U1_RxF_Len   140           //�������ݵĵ�֡������󳤶�<=255
#define U1_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 U1RxFBuf[U1_RxF_BufLen][U1_RxF_Len+1];                 //����֡������
extern U8 U1RxFBufPi;                 //����֡���������ָ��
extern U8 U1RxFBufPo;                 //����֡����������ָ��


#define U2_TxF_Len   248           //���������ݵĵ�֡������󳤶� <=255
extern U8 U2InTxBuf(U8 *p, U8 Len);                //  ���������� --> U2TxBuf   
#define U2_RxF_Len   248           //�������ݵĵ�֡������󳤶�<=255
#define U2_RxF_BufLen   3          //��������֡����������(��֡Ϊ��λ����)
extern U8 U2RxFBuf[U2_RxF_BufLen][U2_RxF_Len+1];                 //����֡������
extern U8 U2RxFBufPi;                 //����֡���������ָ��
extern U8 U2RxFBufPo;                 //����֡����������ָ��


#define U3_TxF_Len   140           //���������ݵĵ�֡������󳤶� <=255
extern U8 U3InTxBuf(U8 *p, U8 Len);                //  ���������� --> U3TxBuf  
#define U3_RxF_Len   140           //�������ݵĵ�֡������󳤶�<=255
#define U3_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 U3RxFBuf[U3_RxF_BufLen][U3_RxF_Len+1];                 //����֡������
extern U8 U3RxFBufPi;                 //����֡���������ָ��
extern U8 U3RxFBufPo;                 //����֡����������ָ��


#define U4_TxF_Len   32           //���������ݵĵ�֡������󳤶�<=255
extern U8 U4InTxBuf(U8 *p, U8 Len);                //  ���������� --> U4TxBuf   
#define U4_RxF_Len   32           //�������ݵĵ�֡������󳤶�<=255
#define U4_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 U4RxFBuf[U4_RxF_BufLen][U4_RxF_Len+1];                 //����֡������
extern U8 U4RxFBufPi;                 //����֡���������ָ��
extern U8 U4RxFBufPo;                 //����֡����������ָ��


#define U5_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 U5InTxBuf(U8 *p, U8 Len);                //  ���������� --> U5TxBuf   
#define U5_RxF_Len   120           //�������ݵĵ�֡������󳤶�<=255
#define U5_RxF_BufLen   5           //��������֡����������(��֡Ϊ��λ����)
extern U8 U5RxFBuf[U5_RxF_BufLen][U5_RxF_Len+1];                 //����֡������
extern U8 U5RxFBufPi;                 //����֡���������ָ��
extern U8 U5RxFBufPo;                 //����֡����������ָ��

#define U6_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 U6InTxBuf(U8 *p, U8 Len);                //  ���������� --> U6TxBuf   
#define U6_RxF_Len   120           //�������ݵĵ�֡������󳤶�<=255
#define U6_RxF_BufLen   5           //��������֡����������(��֡Ϊ��λ����)
extern U8 U6RxFBuf[U6_RxF_BufLen][U6_RxF_Len+1];                 //����֡������
extern U8 U6RxFBufPi;                 //����֡���������ָ��
extern U8 U6RxFBufPo;                 //����֡����������ָ��

//�ڶ��鴮��U7-UA
#define U7_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 U7InTxBuf(U8 *p, U8 Len);                //  ���������� --> U7TxBuf   
#define U7_RxF_Len   120           //�������ݵĵ�֡������󳤶�<=255
#define U7_RxF_BufLen   5           //��������֡����������(��֡Ϊ��λ����)
extern U8 U7RxFBuf[U7_RxF_BufLen][U7_RxF_Len+1];                 //����֡������
extern U8 U7RxFBufPi;                 //����֡���������ָ��
extern U8 U7RxFBufPo;                 //����֡����������ָ��

#define U8_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 U8InTxBuf(U8 *p, U8 Len);                //  ���������� --> U8TxBuf   
#define U8_RxF_Len   120           //�������ݵĵ�֡������󳤶�<=255
#define U8_RxF_BufLen   5           //��������֡����������(��֡Ϊ��λ����)
extern U8 U8RxFBuf[U8_RxF_BufLen][U8_RxF_Len+1];                 //����֡������
extern U8 U8RxFBufPi;                 //����֡���������ָ��
extern U8 U8RxFBufPo;                 //����֡����������ָ��

#define U9_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 U9InTxBuf(U8 *p, U8 Len);                //  ���������� --> U9TxBuf 
#define U9_RxF_Len   120           //�������ݵĵ�֡������󳤶�<=255
#define U9_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 U9RxFBuf[U9_RxF_BufLen][U9_RxF_Len+1];                 //����֡������
extern U8 U9RxFBufPi;                 //����֡���������ָ��
extern U8 U9RxFBufPo;                 //����֡����������ָ��

#define UA_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 UAInTxBuf(U8 *p, U8 Len);                //  ���������� --> UATxBuf   
#define UA_RxF_Len   120           //�������ݵĵ�֡������󳤶�<=255
#define UA_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UARxFBuf[UA_RxF_BufLen][UA_RxF_Len+1];                 //����֡������
extern U8 UARxFBufPi;                 //����֡���������ָ��
extern U8 UARxFBufPo;                 //����֡����������ָ��

//�����鴮��UB-UE
#define UB_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 UBInTxBuf(U8 *p, U8 Len);                //  ���������� --> UBTxBuf   
#define UB_RxF_Len   16           //�������ݵĵ�֡������󳤶�<=255
#define UB_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UBRxFBuf[UB_RxF_BufLen][UB_RxF_Len+1];                 //����֡������
extern U8 UBRxFBufPi;                 //����֡���������ָ��
extern U8 UBRxFBufPo;                 //����֡����������ָ��

#define UC_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 UCInTxBuf(U8 *p, U8 Len);                //  ���������� --> UCTxBuf   
#define UC_RxF_Len   16           //�������ݵĵ�֡������󳤶�<=255
#define UC_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UCRxFBuf[UC_RxF_BufLen][UC_RxF_Len+1];                 //����֡������
extern U8 UCRxFBufPi;                 //����֡���������ָ��
extern U8 UCRxFBufPo;                 //����֡����������ָ��

#define UD_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 UDInTxBuf(U8 *p, U8 Len);                //  ���������� --> UDTxBuf   
#define UD_RxF_Len   16           //�������ݵĵ�֡������󳤶�<=255
#define UD_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UDRxFBuf[UD_RxF_BufLen][UD_RxF_Len+1];                 //����֡������
extern U8 UDRxFBufPi;                 //����֡���������ָ��
extern U8 UDRxFBufPo;                 //����֡����������ָ��

#define UE_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 UEInTxBuf(U8 *p, U8 Len);                //  ���������� --> UETxBuf   
#define UE_RxF_Len   16           //�������ݵĵ�֡������󳤶�<=255
#define UE_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UERxFBuf[UE_RxF_BufLen][UE_RxF_Len+1];                 //����֡������
extern U8 UERxFBufPi;                 //����֡���������ָ��
extern U8 UERxFBufPo;                 //����֡����������ָ��

//�����鴮��UF-UI
#define UF_TxF_Len   120           //���������ݵĵ�֡������󳤶�<=255
extern U8 UFInTxBuf(U8 *p, U8 Len);                //  ���������� --> UFTxBuf   
#define UF_RxF_Len   16           //�������ݵĵ�֡������󳤶�<=255
#define UF_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UFRxFBuf[UF_RxF_BufLen][UF_RxF_Len+1];                 //����֡������
extern U8 UFRxFBufPi;                 //����֡���������ָ��
extern U8 UFRxFBufPo;                 //����֡����������ָ��

#define UG_TxF_Len   140           //���������ݵĵ�֡������󳤶�<=255
extern U8 UGInTxBuf(U8 *p, U8 Len);                //  ���������� --> UGTxBuf   

#define UG_RxF_Len   140           //�������ݵĵ�֡������󳤶�<=255
#define UG_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UGRxFBuf[UG_RxF_BufLen][UG_RxF_Len+1];                 //����֡������
extern U8 UGRxFBufPi;                 //����֡���������ָ��
extern U8 UGRxFBufPo;                 //����֡����������ָ��

#define UH_TxF_Len   140           //���������ݵĵ�֡������󳤶�<=255
extern U8 UHInTxBuf(U8 *p, U8 Len);                //  ���������� --> UHTxBuf   
#define UH_RxF_Len   140           //�������ݵĵ�֡������󳤶�<=255
#define UH_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UHRxFBuf[UH_RxF_BufLen][UH_RxF_Len+1];                 //����֡������
extern U8 UHRxFBufPi;                 //����֡���������ָ��
extern U8 UHRxFBufPo;                 //����֡����������ָ��

#define UI_TxF_Len   140           //���������ݵĵ�֡������󳤶�<=255
extern U8 UIInTxBuf(U8 *p, U8 Len);                //  ���������� --> UITxBuf   

#define UI_RxF_Len   140           //�������ݵĵ�֡������󳤶�<=255
#define UI_RxF_BufLen   3           //��������֡����������(��֡Ϊ��λ����)
extern U8 UIRxFBuf[UI_RxF_BufLen][UI_RxF_Len+1];                 //����֡������
extern U8 UIRxFBufPi;                 //����֡���������ָ��
extern U8 UIRxFBufPo;                 //����֡����������ָ��






