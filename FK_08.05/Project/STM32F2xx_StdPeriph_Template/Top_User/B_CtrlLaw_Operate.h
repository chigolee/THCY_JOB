/*========================================================================================*
 * FILE:                     	B_CtrlLaw_Operate.h                   
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
 * 2017/02/26 ����	Created.
 *========================================================================================*/ 
#ifndef M_B_CtrlLaw_Operate_H
#define M_B_CtrlLaw_Operate_H


/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
 #include "B_GlobalDefine.h"
 #include "math.h"
 #include "B_SelfDefine_RemoteStruct.h"

 /*------------------------------------------------------------------------------*
 *								�궨��
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/
#define 	CtrlSys_MtMk					637.6725				//�����������֮һrad���׵Ļ��㵥λ
//#define 	CtrlSys_LTLK					1					// �任ϵ�� ֻ��һ�� //�������任������cos(γ��)
//CtrlSys_LTLK=cos((double)GPS_Lat_Z*3.14/180.0/600000.0);

#define 	CtrlSys_HoverWay				6					//��������
#define 	CtrlSys_LastPoint				1					//ǰһ������
#define 	CtrlSys_CurrentPoint			2					//��ǰ����
#define 	CtrlSys_TempPoint				0					//��ʱ�Ĵ溽��

#define  	MaxPathNum						5					//�������Ŀ
#define  	MaxPointNum						20					//��󺽵���Ŀ

#define		CtrlSys_PI						3.1415926

#define		CtrlSys_TakeOff					0x00				//����ģʽ�����ա�����
#define		CtrlSys_RC						0x01				//����ģʽ��ң��
#define		CtrlSys_AUTO					0x02				//����ģʽ������

#define		CtrlSys_UNNORMAL				0x00				//����״̬��������
#define		CtrlSys_NORMAL					0x01				//����״̬������

#define		CtrlSys_Vect_Limit				900					// ʸ�����޷�����λ0.1��



#define		CtrlSys_l1						12					//ǰ���ž�X�����
#define		CtrlSys_l2						48					//�����ž����ľ���

#define		CtrlSys_Pro_Max					600					//����������ת������,600r/min
#define		CtrlSys_Pro_Min					50					//����������ת������,600r/min
#define		CtrlSys_Fan_Max				3000				//ǰ������������ת������,3000r/min
#define		CtrlSys_Fan_Min					100					//ǰ������������ת������,3000r/min

#define		CtrlSys_Fan_change				300					//ǰ������������ת��ÿ��仯,100r/min

//������ز�������
#define		CtrlSys_kyth					300					//�ڻ������ηֽ���
#define		CtrlSys_iyth					150					//�ڻ�������Ч����
#define		CtrlSys_kcth					60					//�⻷�����ηֽ���
#define		CtrlSys_icth					50					//�⻷������Ч����


//ң��ģʽ��������

#define		RC_Tail_Plus					0x01				//ǰ��������ת��+
#define		RC_Tail_Minus					0x02				//ǰ��������ת��-

#define		RC_Vector_Reset					0x01				//ǰ��ʸ������

 //����ģʽ����
#define		FlightModel_Flyup				0x10				//����ģʽ

#define		FlightModel_RCCtrl_Normal		0x01				//ң�ط��У���׼ģʽ
#define		FlightModel_RCCtrl_Mix			0x02				//ң�ط��У���ϵ���ģʽ
#define		FlightModel_RCCtrl_Fault			0x03				//ң�ط��У�����ģʽ

#define		FlightModel_Stay_Area			0x30				//��������פ��
#define		FlightModel_SetDirection		0x31				//����������
#define		FlightModel_Stay				0x32				//��������פ��
#define		FlightModel_GoPoint_1			0x33				//�������㺽��1Ѳ��
#define		FlightModel_GoPoint_2			0x34				//�������㺽��2Ѳ��
#define		FlightModel_GoPoint_3			0x35				//�������㺽��3Ѳ��
#define		FlightModel_GoPoint_4			0x36				//�������㺽��4Ѳ��
#define		FlightModel_GoPoint_5			0x37				//�������㺽��5Ѳ��
#define		FlightModel_FlyRound			0x38				//����Բ�켣

#define		FlightModel_Getdown				0x4e				//����ģʽ





/*-----�ɿ����ָ�����-----*/
#define	CtrlLaw_FlightPathInput					0x01		/*	����ע��				*/
#define	CtrlLaw_CruiseCirclePara				0x02		/*	Ѳ��Բ��������			*/
#define	CtrlLaw_StayModePara					0x03		/*	פ��ģʽ��������		*/
#define	CtrlLaw_TrajPlanPara					0x04		/*	�Ƶ����Ʋ�������		*/
#define	CtrlLaw_CruiseDirection					0x05		/*	�������������			*/
#define	CtrlLaw_GesturePara						0x06		/*	��̬���Ʋ�������		*/
#define	CtrlLaw_CtrlAllocatePara				0x07		/*	���Ʒ����������		*/
#define	CtrlLaw_SpeedPara						0x08		/*	�ٶȿ��Ʋ�������		*/
#define	CtrlLaw_WindSpDirection					0x09		/*	���ٷ�������			*/
#define	CtrlLaw_EngineState						0x0A		/*	����ϵͳ������Ϣ		*/
#define	CtrlLaw_RemoteCtrl						0x0B		/*	�ֱ�ң�ؿ���ָ��		*/
#define	CtrlLaw_NavEKFPara						0x0C		/*	�ߵ��˲���������		*/


/*-----���ݲ�ѯ����------*/
#define	MSGDATA_CX01_FlightCtrl01		0x01		
#define	MSGDATA_CX02_FlightCtrl02		0x02		
#define	MSGDATA_CX03_FlightCtrl03		0x03		
#define	MSGDATA_CX04_FlightCtrl04		0x04
/*------------------------------------------------------------------------------*
 *								�ṹ�嶨��
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/


/* 1-���п�������-- ����ע��*/
typedef struct
{

	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_UINT8	PathNO;									/*���߱��*/
	DEF_UINT8	PointCount;								/*������Ŀ*/
	DEF_UINT8	PointNO;								/*������*/
	DEF_UINT8	PointTask;								/*��������*/
	
	DEF_INT32	PointLong;								/*���㾭��*/
	DEF_INT32	PointLat;								/*����γ��*/

	DEF_UINT16	PreTurningLen;							/*��ǰת����*/
	DEF_UINT8	PathChange;								/*�����л�*/
	DEF_UINT8	PathRestart;								/*����ѭ��*/
	
	DEF_UINT8 	Reserved_21[3];							/*�����ֽ�21~23*/
	DEF_UINT8	CheckSum;								/*У���*/	

}_DEFSTRU_CtrlLaw01_FlightPathInput;	



/* 2-���п�������-- Ѳ��Բ��������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_INT32	CruiseCircleLong;						/*ԲѲ��Բ�ľ���*/
	DEF_INT32	CruiseCircleLat;							/*ԲѲ��Բ��γ��*/
	
	DEF_UINT16	CruiseCircleRadius;						/*ԲѲ��Բ�뾶R*/
	DEF_UINT16	PreTurningLen;							/*ԲѲ����ǰת����*/

	DEF_UINT8 	Reserved_17[3];							/*�����ֽ�17~19*/
	DEF_UINT8	CheckSum;								/*У���*/

}_DEFSTRU_CtrlLaw02_CruiseCirclePara;	


/* 3-���п�������-- פ��ģʽ��������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_INT32	HomeLong;								/*פ���㾭��*/
	DEF_INT32	HomeLat;								/*פ����γ��*/
	DEF_INT16	HomeHeight;								/*פ����߶�*/
	DEF_UINT16	CoreAreaDist;							/*פ�������������뾶*/
	DEF_UINT16	TotalAreaDist;							/*פ�������ܰ뾶*/
	DEF_UINT16	BufferAreaDist;							/*פ������߽绺�����*/

	DEF_UINT8 	Reserved_21[3];							/*�����ֽ�21~23*/
	DEF_UINT8	CheckSum;								/*У���*/	
	
}_DEFSTRU_CtrlLaw03_StayModePara;	


/* 4-���п�������-- �Ƶ����Ʋ�������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_FLOAT32	Para_kcpt;								/*�Ƶ����Ʋ����ܱ���*/
	DEF_FLOAT32	Para_kcp1;								/*�Ƶ����Ʋ�������1 ��*/
	DEF_FLOAT32	Para_kcp2;								/*�Ƶ����Ʋ�������2 ��*/
	DEF_FLOAT32	Para_kci;								/*�Ƶ����Ʋ���*/
	DEF_FLOAT32	Para_kcd;								/*�Ƶ����Ʋ���*/
	DEF_FLOAT32	Para_kcth;								/*�Ƶ����Ʋ�����������ֵ*/
	DEF_FLOAT32	Para_kclimit;							/*�Ƶ������������λ*/

	DEF_UINT8 	Reserved_33[3];							/*�����ֽ�33~35*/
	DEF_UINT8	CheckSum;								/*У���*/	
	
}_DEFSTRU_CtrlLaw04_TrajPlanPara;	



/* 5-���п�������-- �������������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_FLOAT32	CruiseDirection;							/*Ѳ������*/
	
	DEF_UINT8 	Reserved_9[3];							/*�����ֽ�9~11*/
	DEF_UINT8	CheckSum;								/*У���*/	
	
}_DEFSTRU_CtrlLaw05_CruiseDirection;	



/* 6-���п�������-- ��̬���Ʋ�������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_FLOAT32	Para_kypt;								/*������Ʋ����ܱ���kypt*/
	DEF_FLOAT32	Para_kyp1;								/*������Ʋ�������1 ��*/
	DEF_FLOAT32	Para_kyp2;								/*������Ʋ�������2 ��*/
	DEF_FLOAT32	Para_kyi;								/*������Ʋ���kyi*/
	DEF_FLOAT32	Para_kyd;								/*������Ʋ���kyd*/
	DEF_FLOAT32	Para_kyth;								/*������Ʋ�����������ֵkyth*/
	DEF_FLOAT32 Para_kylimit;							/*��������������λ*/

	DEF_UINT8 	Reserved_33[3];							/*�����ֽ�33~35*/
	DEF_UINT8	CheckSum;								/*У���*/	

}_DEFSTRU_CtrlLaw06_GesturePara;	



/* 7-���п�������-- ���Ʒ����������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_FLOAT32	CAPara1;								/*���Ʒ������1*/
	DEF_FLOAT32	CAPara2;								/*���Ʒ������2*/
	DEF_FLOAT32	CAPara3;								/*���Ʒ������3*/
	DEF_FLOAT32	CAPara4;								/*���Ʒ������4*/
	DEF_FLOAT32	CAPara5;								/*���Ʒ������5*/
	DEF_FLOAT32	CAPara6;								/*���Ʒ������6*/

	DEF_UINT8 	Reserved_29[3];							/*�����ֽ�29~31*/
	DEF_UINT8	CheckSum;								/*У���*/	
	
}_DEFSTRU_CtrlLaw07_CtrlAllocatePara;	



/* 8-���п�������-- �ٶȿ��Ʋ�������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_FLOAT32	Para_kvp;								/*�ٶȿ��Ʋ���kvp*/
	DEF_FLOAT32	Para_kvi;								/*�ٶȿ��Ʋ���kvi*/
	DEF_FLOAT32	Para_kvd;								/*�ٶȿ��Ʋ���kvd*/
	DEF_UINT16	CruiseSpeed;							/*Ѳ���ٶ�*/

	DEF_UINT8 	Reserved_19;							/*�����ֽ�19*/
	DEF_UINT8	CheckSum;								/*У���*/	

}_DEFSTRU_CtrlLaw08_SpeedPara;	



/* 9-���п�������-- ���ٷ�������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_FLOAT32	WindSet_H_Angle;						/*�趨ˮƽ�����*/
	DEF_INT16	WindSpSet_V;							/*�趨�������*/
	DEF_INT16	WindSpSet_H;							/*�趨ˮƽ����*/

	DEF_UINT8 	Reserved_13[3];							/*�����ֽ�13~15*/
	DEF_UINT8	CheckSum;								/*У���*/	
	
}_DEFSTRU_CtrlLaw09_WindSpDirection;	



/* 10-���п�������-- ����ϵͳ������Ϣ*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_UINT8 	Propeller1;								/*���������1 ״̬*/
	DEF_UINT8 	Propeller2;								/*���������2 ״̬*/
	DEF_UINT8 	Propeller3;								/*���������3 ״̬*/
	DEF_UINT8 	Propeller4;								/*���������4 ״̬*/	
	DEF_UINT8 	Propeller_Front;							/*ǰ������״̬*/
	DEF_UINT8 	Vertor;									/*ʸ��װ��״̬*/
	DEF_UINT8 	EnginState;								/*����ϵͳ����ģʽ*/
	
	DEF_UINT8	CheckSum;								/*У���*/	

}_DEFSTRU_CtrlLaw0A_EngineState;	



/* 11-���п�������-- �ֱ�ң�ؿ���ָ��*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_UINT8	CtrlMode;								/*ң��ģʽ*/

	DEF_UINT8 	Reserved_6;								/*�����ֽ�6*/
	
	DEF_UINT16 	Propeller_Left;							/*������ת��*/
	DEF_UINT16 	Propeller_Right;						/*������ת��*/
	DEF_UINT8 	Propeller_Front;						/*ǰ���������״̬*/
	DEF_UINT8 	Reserved_12;							/*�����ֽ�12*/
	
	DEF_INT16	VertorAngle;							/*ʸ��װ��ת��*/	
	DEF_UINT8	VectorReset;							/*ʸ��װ�ù��㰴ť״̬*/	
	
	DEF_UINT8	CheckSum;								/*У���*/		
}_DEFSTRU_CtrlLaw0B_RemoteCtrl;	


/* 12-���п�������-- �ߵ��˲���������*/
typedef struct
{

	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_FLOAT32 PitchAngleQ;      //������״̬Э����
	DEF_FLOAT32 PitchAngleRateQ;  //�������ٶ�״̬Э����
	DEF_FLOAT32 PitchAngleR;      //���������Э����
	DEF_FLOAT32 PitchAngleRateR;  //�������ٶ����Э����

	DEF_FLOAT32 YawAngleQ;		 //ƫ����״̬Э����
	DEF_FLOAT32 YawAngleRateQ;    //ƫ�����ٶ�״̬Э����
	DEF_FLOAT32 YawAngleR;        //ƫ�������Э����
	DEF_FLOAT32 YawAngleRateR;    //ƫ�����ٶ����Э����

	DEF_FLOAT32 RollAngleQ;       //��ת��״̬Э����
	DEF_FLOAT32 RollAngleRateQ;   //��ת���ٶ�״̬Э����
	DEF_FLOAT32 RollAngleR;       //��ת�����Э����
	DEF_FLOAT32 RollAngleRateR;   //��ת���ٶ����Э����

	DEF_FLOAT32 VelocityOutputQ1;  //�ٶ����Э����1
	DEF_FLOAT32 VelocityOutputQ2;  //�ٶ����Э����2

	DEF_UINT8	IsEKF;			   //�˲���Чλ  0x01 ��Ч, 0x00 ��Ч
	DEF_UINT8	Reserved_62[2];		
	DEF_UINT8	CheckSum;			/*У���*/		

}_DEFSTRU_CtrlLaw0C_NavEKFPara;




/* 13-���п�������-- �ɿ���״̬����*/
typedef struct
{
	DEF_UINT8		FlightMode;
	DEF_UINT8		Reserved_2;

	DEF_INT16		Height;
	DEF_INT32		FlightLong;
	DEF_INT32		FlightLat;
		
	DEF_INT16		EastVelo;
	DEF_INT16		NorthVelo;
	DEF_INT16		VertiVelo;
	
	DEF_INT16		PitchAngle;
	DEF_INT16		RollAngle;
	DEF_UINT16		HeadAngle;	
	
	DEF_INT16		XAngleRate;	
	DEF_INT16		YAngleRate;
	DEF_INT16		ZAngleRate;

	DEF_UINT16 		Propeller_LeftFront;	
	DEF_UINT16 		Propeller_LeftBack;	
	DEF_UINT16	 	Propeller_RightFront;	
	DEF_UINT16 		Propeller_RightBack;	
	DEF_UINT16 		Propeller_Front;	
	DEF_INT16		VectorAngle;	

}_DEFSTRU_CtrlLaw0D_FlightCtroInfor;	




/* 14-���п�������--�ߵ����ԭʼ����*/
typedef struct
{
    DEF_INT16 		PitchAngle;       //������
	DEF_INT16 		RollAngle;        //��ת��
	DEF_UINT16 		HeadAngle;        //�����
	DEF_INT16 		PitchAngleRate;   //�������ٶ�
	DEF_INT16 		YawAngleRate;     //ƫ�����ٶ�
	DEF_INT16 		RollAngleRate;    //��ת���ٶ�
	DEF_INT16	 	PitchDA;          //˫���߸���
	DEF_UINT16  	YawDA;            //˫���ߺ��� 
	//DEF_DOUBLE64 	PitchCov;         //�����Ƿ���
	//DEF_DOUBLE64 	YawCov;           //ƫ���Ƿ���
	
} _DEFSTRU_CtrlLaw0E_AttitudeDataOrigin;




/* 15-���п�������--�˲����������*/
typedef struct
{
    DEF_INT16 	PitchAngle;       //������
	DEF_INT16 	RollAngle;        //��ת��
	DEF_UINT16 	HeadAngle;        //�����
	DEF_INT16 	PitchAngleRate;   //�������ٶ�
	DEF_INT16 	YawAngleRate;     //ƫ�����ٶ�
	DEF_UINT16 	RollAngleRate;    //��ת���ٶ�	
	
} _DEFSTRU_CtrlLaw0F_AttitudeDataDealed;


/* 16-���п��Ʒ������ݣ���������ṹ��-------------*/
typedef struct
{
	DEF_UINT8	FrameHead_1;
	DEF_UINT8	FrameHead_2;
	DEF_UINT8	FrameLength;
	DEF_UINT8	CircleCount;

	DEF_UINT16	PropellerRate1;
	DEF_UINT16	PropellerRate2;
	DEF_UINT16	PropellerRate3;
	DEF_UINT16	PropellerRate4;
	DEF_UINT16	PropellerRate_Front;
	DEF_INT16	VectorAngle;
	DEF_UINT8	Reserved_17;		//����
	DEF_UINT8	CheckSum;

}_DEFSTRU_CtrlLaw0G_SemSimFKtoMAT;



/* 17-���п��Ʒ������ݣ����淵�ؽṹ��-------------*/
typedef struct
{
	DEF_UINT8	FrameHead_1;
	DEF_UINT8	FrameHead_2;
	DEF_UINT8	FrameLength;
	DEF_UINT8	CircleCount;
	
	DEF_FLOAT32		FlightLong;
	DEF_FLOAT32		FlightLat;
	DEF_FLOAT32		FlightAlt;
		
	DEF_FLOAT32		EastVelo;
	DEF_FLOAT32		NorthVelo;
	DEF_FLOAT32		VertiVelo;
	
	DEF_FLOAT32		PitchAngle;
	DEF_FLOAT32		RollAngle;
	DEF_FLOAT32		HeadAngle;	
	
	DEF_FLOAT32		XAngleRate;	
	DEF_FLOAT32		YAngleRate;
	DEF_FLOAT32		ZAngleRate;

	DEF_UINT8		Reserved_53[3];		//����
	DEF_UINT8		CheckSum;			/*У���*/	

}_DEFSTRU_CtrlLaw0H_SemSimMATtoFK;





/*-----------��ѯָ��-------------*/
/*���п������ݲ�ѯ*/
typedef struct
{

	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*��ѯ״̬*/

	DEF_UINT8 	Reserved_5[3];							/*�����ֽ�5~7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_CX_FlightCtrlData;	


/*���߲�ѯ�ظ�֡*/
typedef struct
{
	
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_UINT8	PathNO;									/*���߱��*/
	DEF_UINT8	PointCount;								/*������Ŀ*/
	DEF_UINT8	PointNO;								/*������*/
	DEF_UINT8	PointTask;								/*��������*/
	
	DEF_INT32	PointLong;								/*���㾭��*/
	DEF_INT32	PointLat;								/*����γ��*/

	DEF_UINT16	PreTurningLen;							/*��ǰת����*/
	DEF_UINT8	PathChange;								/*�����л�*/
	DEF_UINT8	PathRestart;							/*����ѭ��*/
	
	DEF_UINT8 	Reserved_21[3];							/*�����ֽ�21~23*/
	DEF_UINT8	CheckSum;								/*У���*/	

	

}_DEFSTRU_CXHF01_FlightCtrlData;



/*�ɿز�����ѯ�ظ�֡1*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*��ѯ״̬*/

	DEF_INT32	CruiseCircleLong;						/*ԲѲ��Բ�ľ���*/
	DEF_INT32	CruiseCircleLat;							/*ԲѲ��Բ��γ��*/	
	DEF_UINT16	CruiseCircleRadius;						/*ԲѲ��Բ�뾶R*/
	DEF_UINT16	PreTurningLen;							/*ԲѲ����ǰת����*/
	
	DEF_INT32	HomeLong;								/*פ���㾭��*/
	DEF_INT32	HomeLat;								/*פ����γ��*/
	DEF_INT16	HomeHeight;								/*פ����߶�*/
	DEF_UINT16	CoreAreaDist;							/*פ�������������뾶*/
	DEF_UINT16	TotalAreaDist;							/*פ�������ܰ뾶*/
	DEF_UINT16	BufferAreaDist;							/*פ������߽绺�����*/
	
	DEF_FLOAT32	Para_kcpt;								/*�Ƶ����Ʋ����ܱ���*/
	DEF_FLOAT32	Para_kcp1;								/*�Ƶ����Ʋ�������1 ��*/
	DEF_FLOAT32	Para_kcp2;								/*�Ƶ����Ʋ�������2 ��*/
	DEF_FLOAT32	Para_kci;								/*�Ƶ����Ʋ���*/
	DEF_FLOAT32	Para_kcd;								/*�Ƶ����Ʋ���*/
	DEF_FLOAT32	Para_kcth;								/*�Ƶ����Ʋ�����������ֵ*/
	DEF_FLOAT32	Para_kclimit;							/*�Ƶ������������λ*/	

	DEF_FLOAT32	CruiseDirection;						/*Ѳ������*/	

	DEF_FLOAT32	Para_kypt;								/*������Ʋ����ܱ���kypt*/
	DEF_FLOAT32	Para_kyp1;								/*������Ʋ�������1 ��*/
	DEF_FLOAT32	Para_kyp2;								/*������Ʋ�������2 ��*/
	DEF_FLOAT32	Para_kyi;								/*������Ʋ���kyi*/
	DEF_FLOAT32	Para_kyd;								/*������Ʋ���kyd*/
	DEF_FLOAT32	Para_kyth;								/*������Ʋ�����������ֵkyth*/
	DEF_FLOAT32	Para_kylimit;							/*��������������λ*/
	
	DEF_UINT8	Reserved_93[3];							/*�����ֽ�93~95*/
	DEF_UINT8	CheckSum;								/*У���*/
	

}_DEFSTRU_CXHF02_FlightCtrlData;


/*�ɿز�����ѯ�ظ�֡2*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*��ѯ״̬*/
	
	DEF_FLOAT32	CAPara1;								/*���Ʒ������1*/
	DEF_FLOAT32	CAPara2;								/*���Ʒ������2*/
	DEF_FLOAT32	CAPara3;								/*���Ʒ������3*/
	DEF_FLOAT32	CAPara4;								/*���Ʒ������4*/
	DEF_FLOAT32	CAPara5;								/*���Ʒ������5*/
	DEF_FLOAT32	CAPara6;								/*���Ʒ������6*/

	DEF_FLOAT32	Para_kvp;								/*�ٶȿ��Ʋ���kvp*/
	DEF_FLOAT32	Para_kvi;								/*�ٶȿ��Ʋ���kvi*/
	DEF_FLOAT32	Para_kvd;								/*�ٶȿ��Ʋ���kvd*/
	DEF_UINT16	CruiseSpeed;							/*Ѳ���ٶ�*/
	
	DEF_UINT8	Reserved_43[2];							/*�����ֽ�43~44*/

	DEF_FLOAT32	WindSet_H_Angle;						/*�趨ˮƽ�����*/
	DEF_INT16	WindSpSet_V;							/*�趨�������*/
	DEF_INT16	WindSpSet_H;							/*�趨ˮƽ����*/

	DEF_UINT8 	Propeller1;								/*���������1 ״̬*/
	DEF_UINT8 	Propeller2;								/*���������2 ״̬*/
	DEF_UINT8 	Propeller3;								/*���������3 ״̬*/
	DEF_UINT8 	Propeller4;								/*���������4 ״̬*/		
	DEF_UINT8 	Propeller_Front;						/*ǰ������״̬*/
	DEF_UINT8 	Vertor;									/*ʸ��װ��״̬*/
	DEF_UINT8 	EnginState;								/*����ϵͳ����ģʽ*/
	
	DEF_UINT8	CheckSum;								/*У���*/
	
	
}_DEFSTRU_CXHF03_FlightCtrlData;


/*�ɿز�����ѯ�ظ�֡3*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*��ѯ״̬*/

	DEF_FLOAT32 PitchAngleQ;     						//������״̬Э����
	DEF_FLOAT32 PitchAngleRateQ;  						//�������ٶ�״̬Э����
	DEF_FLOAT32 PitchAngleR;      						//���������Э����
	DEF_FLOAT32 PitchAngleRateR;   						//�������ٶ����Э����
   
	DEF_FLOAT32 YawAngleQ;		  						//ƫ����״̬Э����
	DEF_FLOAT32 YawAngleRateQ;     						//ƫ�����ٶ�״̬Э����
	DEF_FLOAT32 YawAngleR;         						//ƫ�������Э����
	DEF_FLOAT32 YawAngleRateR;     						//ƫ�����ٶ����Э����

	DEF_FLOAT32 RollAngleQ;        						//��ת��״̬Э����
	DEF_FLOAT32 RollAngleRateQ;    						//��ת���ٶ�״̬Э����
	DEF_FLOAT32 RollAngleR;        						//��ת�����Э����
	DEF_FLOAT32 RollAngleRateR;    						//��ת���ٶ����Э����

	DEF_FLOAT32 VelocityOutputQ1;   					//�ٶ����Э����1
	DEF_FLOAT32 VelocityOutputQ2;   					//�ٶ����Э����2

	DEF_UINT8	IsEKF;			    					//�˲���Чλ  0x01 ��Ч, 0x00 ��Ч
	DEF_UINT8	Reserved_62[2];		

	DEF_UINT8	CheckSum;								/*У���*/
	
	
}_DEFSTRU_CXHF04_FlightCtrlData;



/* 17-���п��Ʒ������ݣ����淵�ؽṹ��-------------*/
typedef struct
{
	DEF_UINT8	FrameHead_1;
	DEF_UINT8	FrameHead_2;
	DEF_UINT8	FrameLength;
	DEF_UINT8	CircleCount;

	DEF_FLOAT32		FlightLong;
	DEF_FLOAT32		FlightLat;
	DEF_FLOAT32		FlightAlt;
		
	DEF_FLOAT32		EastVelo;
	DEF_FLOAT32		NorthVelo;
	DEF_FLOAT32		VertiVelo;
	
	DEF_FLOAT32		PitchAngle;
	DEF_FLOAT32		RollAngle;
	DEF_FLOAT32		HeadAngle;	
	
	DEF_FLOAT32		XAngleRate;	
	DEF_FLOAT32		YAngleRate;
	DEF_FLOAT32		ZAngleRate;

	DEF_UINT8		Reserved_53[3];		//����
	DEF_UINT8		CheckSum;			/*У���*/	

}_DEFSTRU_Matlab_Recieve;



/* 17---------�˲�����������-------------*/
typedef struct
{
	DEF_UINT8	FrameHead_1;
	DEF_UINT8	FrameHead_2;
	DEF_UINT8	FrameLength;
	DEF_UINT8	CircleCount;

	DEF_FLOAT32		MatPitchAngleOrigin;
	DEF_FLOAT32		MatRollAngleOrigin;
	DEF_FLOAT32		MatYawAngleOrigin;
		
	DEF_FLOAT32		MatPitchAngleRateOrigin;
	DEF_FLOAT32		MatYawAngleRateOrigin;
	DEF_FLOAT32		MatRollAngleRateOrigin;
	
	DEF_FLOAT32		MatPitchAngleDealed;
	DEF_FLOAT32		MatRollAngleDealed;
	DEF_FLOAT32		MatYawAngleDealed;
		
	DEF_FLOAT32		MatPitchAngleRateDealed;
	DEF_FLOAT32		MatYawAngleRateDealed;
	DEF_FLOAT32		MatRollAngleRateDealed;

	DEF_UINT8		Reserved_53[3];		//����
	DEF_UINT8		CheckSum;			/*У���*/	

}_DEFSTRU_CtrlLaw0I_Matlab_Recieve1;








//�ɿ��������
extern	_DEFSTRU_CtrlLaw01_FlightPathInput			CtrlLaw01_FlightPathInput;
extern	_DEFSTRU_CtrlLaw02_CruiseCirclePara			CtrlLaw02_CruiseCirclePara;
extern	_DEFSTRU_CtrlLaw03_StayModePara				CtrlLaw03_StayModePara;
extern	_DEFSTRU_CtrlLaw04_TrajPlanPara				CtrlLaw04_TrajPlanPara;
extern	_DEFSTRU_CtrlLaw05_CruiseDirection			CtrlLaw05_CruiseDirection;
extern	_DEFSTRU_CtrlLaw06_GesturePara				CtrlLaw06_GesturePara;
extern	_DEFSTRU_CtrlLaw07_CtrlAllocatePara			CtrlLaw07_CtrlAllocatePara;
extern	_DEFSTRU_CtrlLaw08_SpeedPara				CtrlLaw08_SpeedPara;
extern	_DEFSTRU_CtrlLaw09_WindSpDirection			CtrlLaw09_WindSpDirection;
extern	_DEFSTRU_CtrlLaw0A_EngineState				CtrlLaw0A_EngineState;
extern	_DEFSTRU_CtrlLaw0B_RemoteCtrl				CtrlLaw0B_RemoteCtrl;
extern	_DEFSTRU_CtrlLaw0C_NavEKFPara				CtrlLaw0C_NavEKFPara;


extern	_DEFSTRU_CtrlLaw0D_FlightCtroInfor			CtrlLaw0D_FlightCtroInfor;
extern  _DEFSTRU_CtrlLaw0E_AttitudeDataOrigin		CtrlLaw0E_AttitudeDataOrigin;
extern  _DEFSTRU_CtrlLaw0F_AttitudeDataDealed		CtrlLaw0F_AttitudeDataDealed;

extern	_DEFSTRU_CtrlLaw0G_SemSimFKtoMAT			CtrlLaw0G_SemSimFKtoMAT;
extern	_DEFSTRU_CtrlLaw0H_SemSimMATtoFK			CtrlLaw0H_SemSimMATtoFK;
extern	_DEFSTRU_CtrlLaw0I_Matlab_Recieve1			CtrlLaw0I_Matlab_Recieve1;        

	

//��ѯ�ṹ��
extern	_DEFSTRU_CX_FlightCtrlData					CX_FlightCtrlData;
//��ѯ�ظ�֡
extern	_DEFSTRU_CXHF01_FlightCtrlData				CXHF01_FlightCtrlData;
extern	_DEFSTRU_CXHF02_FlightCtrlData				CXHF02_FlightCtrlData;
extern	_DEFSTRU_CXHF03_FlightCtrlData				CXHF03_FlightCtrlData;
extern	_DEFSTRU_CXHF04_FlightCtrlData				CXHF04_FlightCtrlData;

extern	_DEFSTRU_CtrlLaw01_FlightPathInput	FlightPath_Package[5][20];		//����ң��ָ��洢
extern	DEF_UINT8	FlightPath_PointCount[5];							//�������ߺ������




/*------------------------------------------------------------------------------*
 *								��������
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

extern DEF_UINT8  g_CtrlSys_CWn;    //��ǰ���߱��
extern DEF_UINT8  g_CtrlSys_CPn;    //��ǰ������

 
/*------------------------------------------------------------------------------*
 *								��������
void Modelname();
 *------------------------------------------------------------------------------*/

 DEF_UINT8		Navigation(void);
 DEF_UINT8		SwitchWP(void);
 DEF_UINT8		NavInit(DEF_UINT8 ID);
 DEF_UINT8		WPInit(DEF_UINT8 Wn, DEF_UINT8 Pn);
 DEF_INT16		Cal_Point(DEF_INT32 P1Lo, DEF_INT32 P1La, DEF_INT32 P2Lo, DEF_INT32 P2La,DEF_FLOAT32 *plen);
 DEF_FLOAT32		Cal_LineError(DEF_INT16 destcou,DEF_INT16 linecou, DEF_FLOAT32 plen);
 DEF_FLOAT32		Cal_LineDist(DEF_INT16 destcou,DEF_INT16 linecou, DEF_FLOAT32 plen);

 void			Line_Guidance_Law(void);
 void			Circle_Guidance_Law(void); 
 void			OutLoop_Track(void);
 void			Yaw_Track(void);
 void			Brennschluss(void);
 void			Wind_Resist(void);
 void			Line_Path_Track(void);
 void			Circle_Path_Track(void);
 void			Remote_Control(void);
 void			Constant_headangle(void);
 void			Reside_Mode(void);

 void			CtrlLaw_ini(void);				//�����ɳ�ʼ��������ÿ�θı����ģʽ��Ҫ����һ��
 void			Task_CtrlLaw_Operate(void);				//�����ɺ�����ÿ0.5s����һ��
 void			Ctrl_Para_Init(void);						//�����ɲ�����ʼ����������������һ��
 void			CtrlInfor_Update(void);					//�������������ݸ���
 void			CtrlInfor_EKF(void);
 void			Send2Matlab(void);
 void			SemSim_Update(void);
 
 

 DEF_UINT8 		CopyWP(_DEFSTRU_CtrlLaw01_FlightPathInput *P1, _DEFSTRU_CtrlLaw01_FlightPathInput *P2);
 DEF_UINT8 		ReadWP(DEF_UINT8 Wn, DEF_UINT8 Pn, _DEFSTRU_CtrlLaw01_FlightPathInput *P);




//�����ú���
void Task_Mat2FK_Recieve();	
void Task_FK2Mat_Send();
void Task_FK2Mat_Filter_Send();

DEF_UINT8 ChangeHighLowBytes(DEF_UINT8 *p, DEF_UINT8 Count);





void Dowork_YK11_FlightCtrlDataTrans();
void Dowork_CX_FlightCtrlData();



DEF_DOUBLE64 GetLimitValue(DEF_DOUBLE64 CtrlValue, DEF_DOUBLE64 CurrentValue, DEF_FLOAT32 LimitValue);


#endif 




