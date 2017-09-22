#ifndef M_User_Data_H
#define M_User_Data_H

//״̬���� Bottom ---> Top
extern U16 AinData[16];  //16ͨ��AD     AinData[0]-AIN1
extern U8 DIData; //8·DI   1bit��Ӧ1·  bit0-DI_D1

extern U8 Hardware_State1;//Ӳ��״̬���ֽ�
extern U8 Hardware_State2;//Ӳ��״̬���ֽ�

//Hardware_State1
//bit0 ADC      0���� 1����
//bit1 NVRAM    0���� 1����
//bit2 NandFlash1    0���� 1����
//bit3 NandFlash2    0���� 1����
//bit4 VCC3            0���� 1����
//bit5 VCC5            0���� 1����
//bit6 OVCC3          0���� 1����
//bit7 OVCC5          0���� 1����

//Hardware_State2
//bit0 CAN1      0���� 1����
//bit1 CAN2     0���� 1����
//bit2 MAX14830A    0���� 1����
//bit3 MAX14830B    0���� 1����
//bit4 MAX14830C         0���� 1����
//bit5 Tmp100                0���� 1����
//bit6 U1&U2 Switch       0:U1����,U2����     1:U2����,U1����
//bit7 ���ô���״̬   0���� 1����


extern S8 InnerTmp;//�ڲ��¶�   ��λ��


//��������Top  ---> Bottom
extern U8 DOData;//8·DO   1bit��Ӧ1· bit0-DO_C1    

extern U8 ComSW_CMD;//�����л�����    0:  �Զ��л�  1: Usart1  2:Usart2
extern U8 TmpCtrl_CMD;//�¿�����    0:  �Զ��¿�  1: ���� 2:������




//20150619�������ݼ�¼���
//���ݼ�¼������10Hz
//�������ز�����20Hz

#define RecordF_Len  140	//���ݼ�¼����֡����
extern U8 RecordData[RecordF_Len];  //���ݼ�¼����֡
extern U8 DownLoadData[RecordF_Len];  //������������֡
extern U32 Current_RecordBlock;  //��ǰ���ڼ�¼��Block
extern U32 Current_DownloadBlock;  //��ǰ�������ص�Block
extern U8 IsNandScanCMD; //ɨ������




//�ֳ���������
typedef __packed struct _ProData
      {

		U8     HeadByte1;          // ��ͷ1    �����ж����ݶ�д�Ƿ����� 
              U8     HeadByte2;          // ��ͷ2    �����ж����ݶ�д�Ƿ����� 
              
              U8     CtrlByte;          // ������              
              //bit0   �Ƿ񱣻��ֳ�  0������   1����  
              //������Խ׶ο��Բ�����������״̬Ҫ����
              //bit1-bit7   ����
              U32 SystemTime;  //ϵͳ������  ��λ10ms
	       
		/******* �������ݴ���ӣ�ע�����˳����ò�Ҫ�Ҹ�********/             
		U32	Current_RecordBlock;	//��ǰ�洢λ��
		
		S16	CriticalBaricAlt;			/*�ٽ���ѹ�߶�*/
		U16	PropellerN_Limit;		/*���������ƽ�ת���޷�*/ 

		U16	FrontPropelN_Limit;		/*������ת���޷�*/ 			
		U8	FlightMode;				/*����ģʽ*/
		U8	CompuRecState;			/*�������¼���*/
		
		U8 	SafeCtrlMinite;			/*����ʱ��,��λmin*/
		U8	AirscrewCtrlState;		/*�����ͣ״̬bit0~ bit3����ǰ���~�Һ����� bit4����������״̬��0-ֹͣ��1-������*/
	  
	}Pro_Datat;

extern Pro_Datat  Pro_Data;

//���м�¼����

extern U8 ProData_Flag;//�ֳ��������ݸ��±�־


extern U32 SystemTime;  //ϵͳ������  ��λ10ms
extern U32 SystemTimems;  // //ϵͳ������  ��λ1ms

extern U8 LED2_Flag;//LED2״̬����   0 �� 1 ��2����

extern U8 Record_Flag;//�������ݼ�¼/����״̬  0   ������  1  ��¼  2���� Ĭ��0

extern U8 IsSystemTest;  //ϵͳ���Ա�־

#define Heat_StartT    -25   //�����¶����� ��λ��
#define Heat_StopT    0   //ֹͣ�����¶����� ��λ��

extern void FCS(void);//Ԥ�������п����õĺ���





#endif 

