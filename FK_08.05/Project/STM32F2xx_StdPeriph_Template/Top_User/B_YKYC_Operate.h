/*========================================================================================*
 * FILE:                     	B_YKYC_Operate.h                   
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
#ifndef M_B_YKYC_Operate_H
#define M_B_YKYC_Operate_H


/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_GlobalDefine.h"

 
 /*------------------------------------------------------------------------------*
 *								�궨��
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/
 #define	YK_AnStoreCount	40		//ң�ػظ����ζ��г���
 #define	YCFramFastSlow		11		//����֡����+1
/*------------------------------------------------------------------------------*
 *								�ṹ�嶨��
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/
  /*ң�⸱֡1(��֡)ң������*/
typedef struct
{
	DEF_UINT8 	m_SycCode1;								/*ͬ����1*/
	DEF_UINT8 	m_SycCode2;								/*ͬ����2*/
	DEF_UINT8 	m_StationNum;								/*վ���*/
	DEF_UINT8 	m_FrameFlag;								/*֡��־*/
	
	DEF_UINT8 	m_Count;									/*ѭ������*/
	DEF_UINT8 	m_Reserved_6;								/*�����ֽ�6*/
	DEF_INT16 	m_BaricAlt1;								/*��ѹ�߶�1*/
	
	DEF_INT32 	m_INSLon;										/*����*/
	DEF_INT32 	m_INSLat;										/*γ��*/

	DEF_INT16 	m_InsAlt;									/*�ߵ��߶�*/
	DEF_INT16 	m_GPSAlt;									/*GPS�߶�*/
	DEF_INT16 	m_Pitch;									/*������*/
	DEF_INT16 	m_Roll;										/*��ת��*/
	
	DEF_UINT16	m_Heading;									/*�溽��*/
	DEF_UINT8 	m_UpFreq;									/*��ǰ����Ƶ��*/
	DEF_UINT8 	m_DownFreq;								/*��ǰ����Ƶ��*/
	
	DEF_UINT8 	m_TerminalState1;							/*�����ն�״̬1*/
	DEF_UINT8 	m_TerminalState2;							/*�����ն�״̬2*/
	DEF_UINT8 	m_Reserved;								/*�����ֽ�*/
	DEF_UINT8 	m_CheckSum;								/*У���*/
}_SJZYC001_FastFrame;										/*ң��������SJZYC_001*/

/*------------------------------------------------------------------------------*
 *								��������
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 extern _DEFSTRU_YC_All All_YCFast_Package;				
 extern _DEFSTRU_YC_Low All_YCLowPack;			

 extern DEF_UINT16	YC_Date_StepBegain[YC_DATA_COUNT];	//ң�����ݽڵ�λ��
 extern DEF_UINT16	YC_Date_StepBegain_Low[YC_DATA_COUNTLow];	//ң�����ݽڵ�λ��
 extern DEF_UINT8		*P_ForYCPackge;				//ң�����ݰ�ָ��

 
/*------------------------------------------------------------------------------*
 *								��������
void Modelname();
 *------------------------------------------------------------------------------*/
 
/*------------�ɼ���������ݽ���---------*/
void	Task_CJComputer_Receive();


void All_YCPackgeRenew();

/*------------ң�����ݺ�ң�ػظ��������� ------------*/
void Task_YCYKBack_Send();

/*-------ң�����ݷ���-----------*/
void Only_YC_Send();

/* ------------LƵ�β��---ң��ָ�����------------*/
void Task_LlinkCK_Reiceive();

/* ------------UƵ�β��---ң��ָ�����------------*/
void Task_UlinkCK_Reiceive();


/*ң��ָ��ִ��*/
void Only_YK_Operate();

void UComFKSendCJ(DEF_UINT8 *BuffP, DEF_UINT8 SendCount);


/*����ң�ػظ�����*/
void YKCX_Answer_State_Date(DEF_UINT8 *ykcx_struct, DEF_UINT8 count, DEF_UINT8 ykcx_state);

/*-----UƵ�β��---���ݷ���----------*/
void ReserveCK_Send(DEF_UINT8 *p, DEF_UINT8 Length);



/* ------------UƵ�β��---��·����֡����------------*/
void	Task_Ulink_SendTestFram();


/*--------------����ң��ָ��ִ��--------------*/
void Dowork_YK01_FlightMode();
void Dowork_YK02_WeightAdjust_Lock();
void Dowork_YK03_WeightAdjustCtrl();
void Dowork_YK04_NavCtrl();
void Dowork_YK05_FK_ComputHeart();
void Dowork_YK06_FK_ComputerReset();
void Dowork_YK07_FK_ComuterCtrl();
void Dowork_YK08_LandingParSet();
void Dowork_YK09_AirscrewCtrl();
void Dowork_YK0A_PropellerNCtrl();
void Dowork_YK0B_ValveCtrl();
void Dowork_YK0C_BallonetExploderControl();
void Dowork_YK0D_ValveExplodeCtrl();
void Dowork_YK0E_BalnetColPreFire();
void Dowork_YK0F_BalnetColCtrl();
void Dowork_YK10_EnergySysCtrl();

void Dowork_YK12_VectorAngelCtrl();
void Dowork_YK13_VectorParamCtrl();







#endif 








