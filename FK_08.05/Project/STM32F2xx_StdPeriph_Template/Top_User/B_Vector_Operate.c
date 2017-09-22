/*========================================================================================*
 * FILE:                     	B_Vector_Operate.c                   
 *========================================================================================*
 *
 * COPYRIGHT 2008-2015 BY 513 ������
 *
 *========================================================================================*
 *
 * ����:  
 *
 * ����: 	
 *			
 *
 *				
 *
 *----------------------------------------------------------------------------------------*
 *          
 * HISTORY:   
 *
 *   Date    By     Comments
 * --------  -----  ------------------------------------------------------------
 * 2015/03/26  ������	Created.
 *========================================================================================*/ 

/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
 #include "Modelname.h"
 *------------------------------------------------------------------------------*/
 #include "B_Vector_Operate.h"


/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
#define VectorSendGroupNO	5

DEF_UINT8 Vector_DataSend[VectorSendGroupNO][8];
DEF_UINT8 In_Vector_DataSend=0;
DEF_UINT8 Out_Vector_DataSend=0;


/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/




//ʸ��װ������֡����֡ͷ��βУ�飬ע��ʸ��װ�ø��ֽ���ǰ�����ֽ��ں�
struct 
{
DEF_INT16 	A1_VectorActualN;					/*ʸ��װ�õ��1-ת�ٲ���ֵ*/
DEF_INT16 	A1_VectorAngle;						/*ʸ��װ�ýǶ�ֵ1-*/	
DEF_UINT16	A1_Reserve_2;						/*���üĴ�����ַ2*/
DEF_INT16	A1_VectorRadiatorTemp;				/*ʸ��װ�õ��1-�������¶�*/ 

DEF_INT16 	A1_VectorMainwireVol;				/*ʸ��װ�õ��1-ĸ�ߵ�ѹ*/
DEF_INT16 	A1_VectorCurrent;					/*ʸ��װ�õ��1-�������*/

DEF_UINT16 	A1_VectorState;						/*ʸ��װ�õ��1-״̬*/	
DEF_UINT16	A1_Reserve_7[3];					/*���üĴ�����ַ7~9*/	
}TransNoHead_Vector_Recieve;

DEF_UINT8	Vector_Data_Recieve[45];	//ʸ��װ�ý���ȫ������
DEF_UINT16	Vector_CRC_Recieve=0;

 /*--------------ʸ��װ�����ݽ���----------------*/
 void Task_Vector_Recieve()
 	{
 	int a=0;
	int b=0;
 	}







DEF_UINT8	Vector_Data_Require[8];
DEF_UINT16	Vector_CRC_Send=0;
/*-----ʸ��װ�ÿ���ָ���/������������----*/
 void Task_Vector_DataSend()
{
	if(Out_Vector_DataSend != In_Vector_DataSend)
		{
		//���͵�ǰλ�ÿ���ָ��
		UGInTxBuf((U8*)&(Vector_DataSend[Out_Vector_DataSend][0]),8);
		Out_Vector_DataSend=(Out_Vector_DataSend+1)%VectorSendGroupNO;
		}
	
	else
		{
		//������������
		Vector_Data_Require[0]=UG_DH0;
		Vector_Data_Require[1]=UG_DH1_1;
		Vector_Data_Require[2]=0x00;
		Vector_Data_Require[3]=0x00;
		Vector_Data_Require[4]=0x00;
		Vector_Data_Require[5]=10;		
		Vector_CRC_Send=modbus_crc16((DEF_UINT8*)&(Vector_Data_Require[0]),6);
		bcopy((&Vector_CRC_Send),(&(Vector_Data_Require[6])),2);
		
		UGInTxBuf((U8*)&(Vector_Data_Require[0]),8);
		}
}











DEF_INT16	VectorCtrl_Trans[4];		//ң�������ݴ棬ע��ߵ�λ��ʸ��װ�����ݸ�λ��ǰ��CRC��λ��ǰ��
DEF_UINT16	VectorCtrlCRC=0;

//CtrlType��Param
// 0x01-�Ƕ�			���Ƕ�ֵ����λ�㣬�з��ţ�����0.1 ����Param=Ҫ���ƽǶ�*10   ��
// 0x02-����			��0
// 0x03-����			��0
// 0x04-ֹͣ			��0
// 0x05-�������	��0
// 0x06-ת�ٿ���	��ת��ֵ����λr/min���з��ţ�����0.1 ����Param=Ҫ����ת��*10   

 /*--------------ʸ��װ�ÿ���----------------*/
void Vector_Control(DEF_UINT8 CtrlType, DEF_INT16 Param)
 {
	VectorCtrl_Trans[0]=(0x0600+UG_DH0);		//��λ��ǰ21 , 06

	if(CtrlType==0x01)	//�Ƕ�
		{
		VectorCtrl_Trans[1]=0x2200;		//�Ĵ�����ַ0x0022
		if(Param>900)
			{VectorCtrl_Trans[2]=900;}
		else if(Param<-900)
			{VectorCtrl_Trans[2]=-900;}
		else
			{VectorCtrl_Trans[2]=Param;}
		g_YC_Package.TJ.VectorCtrlAngle=VectorCtrl_Trans[2];
		VectorCtrl_Trans[2]=ChangeWordByte((DEF_UINT16)(VectorCtrl_Trans[2]));	
		}

	else if(CtrlType==0x02)//����
		{
		VectorCtrl_Trans[1]=0x1F00;		//�Ĵ�����ַ0x1F00
		VectorCtrl_Trans[2]=0x0200;		//ʸ�����ֽ���ǰ

		}

	else if(CtrlType==0x03)//����
		{
		VectorCtrl_Trans[1]=0x1F00;		//�Ĵ�����ַ0x1F00
		VectorCtrl_Trans[2]=0x0300;		//ʸ�����ֽ���ǰ
		}

	else if(CtrlType==0x04)//ֹͣ
		{
		VectorCtrl_Trans[1]=0x1F00;		//�Ĵ�����ַ0x1F00
		VectorCtrl_Trans[2]=0x0100;		//ʸ�����ֽ���ǰ
		}

	else if(CtrlType==0x05)//�������
		{
		VectorCtrl_Trans[1]=0x2000;		//�Ĵ�����ַ0x2000
		VectorCtrl_Trans[2]=0xffff;		//ʸ�����ֽ���ǰ
		}

	else if(CtrlType==0x06)//ת�ٿ���
		{
		VectorCtrl_Trans[1]=0x2100;		//�Ĵ�����ַ0x2100
		if((Param>50)||(Param<0))
			{VectorCtrl_Trans[2]=50;}
		else
			{VectorCtrl_Trans[2]=Param;}
		VectorCtrl_Trans[2]=ChangeWordByte((DEF_UINT16)(VectorCtrl_Trans[2]));	
		}

	VectorCtrl_Trans[3]=modbus_crc16((DEF_UINT8*)&(VectorCtrl_Trans[0]),6);

	//���ͻ���
	bcopy((DEF_UINT8*)&(VectorCtrl_Trans[0]),(DEF_UINT8*)&(Vector_DataSend[In_Vector_DataSend][0]),8);
	In_Vector_DataSend=(In_Vector_DataSend+1)%VectorSendGroupNO;

 }





























