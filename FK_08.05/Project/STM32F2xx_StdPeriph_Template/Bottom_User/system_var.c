#include "main.h"

u8 Is_WDG= FALSE; //���Ź���־
u8 Is_DIO= FALSE; //DIO��ʾ
U8 Is_ADC = FALSE;  //ADCת����־
U8 Is_ExUsartSend = FALSE;  //�ⲿ��չ���ڷ���
U8 Is_CAN1Send = FALSE;  //CAN����֡���ͱ�־
U8 Is_CAN2Send = FALSE;  //CAN����֡���ͱ�־
U8 Is_TmpCtrl = FALSE;  //�¶ȿ��Ʊ�־

U8 Is_FCS= FALSE;  //���п��Ʊ�־
u8 IsTest = FALSE; ////���Ա�ʾ
U32 rstdly =0;                //������ʱ����
u8 TestData1; ////��������
u8 TestData2; ////��������
u8 TestData3; ////��������
u8 TestData4; ////��������
u8 TestData5; ////��������
u8 TestData6; ////��������



U16 VCC3_Volt = 0;   //�ڲ�3.3V��ѹ
U16 VCC5_Volt = 0;   //�ڲ�5V��ѹ
U16 OAGND_Volt = 0; //�ⲿģ���V��ѹ
U16 OVCC3_Volt = 0; //�ⲿ3.3V��ѹ
U16 OVCC5_Volt = 0; //�ⲿ5V��ѹ
U16 MVCC_Volt = 0;  //�����Դ��ѹ
U16 OAVCC12_Volt = 0; //�ⲿģ��12V��Դ��ѹ


