/*========================================================================================*
 * FILE:                     	SelfDefine_RemoteStruct.h                   
 *========================================================================================*
 *
 * COPYRIGHT 2008-2015 BY 513 ������
 *
 *========================================================================================*
 *
 * ����:  ��ң��ң��Э����ص�ȫ�����壬�����ṹ�塢֡��־���ṹ�峤�ȵȡ�
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
#ifndef M_SelfDefine_RemoteStruct_H
#define M_SelfDefine_RemoteStruct_H


/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_SelfDefine_type.h"

 /*------------------------------------------------------------------------------*
 *								�궨��
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/



/*-----��Ϣ��������------*/
#define		YC_DATA_COUNT				5					/*ң���֡����*/
#define		YC_DATA_COUNTLow			2					/*ң����֡����*/


/*-----����֡-֡��־����------*/
#define FRAMEFLAG_YC_HD01			0x51	/*ң���֡---����01ϵͳ*/	
#define FRAMEFLAG_YC_HD02			0x52	/*ң���֡---����02ϵͳ*/	
#define FRAMEFLAG_YC_TJ			0x53	/*ң���֡---�ƽ�ϵͳ*/	
#define FRAMEFLAG_YC_NY			0x54	/*ң���֡---��Դϵͳ*/	
#define FRAMEFLAG_YC_NT			0x55	/*ң���֡---����ϵͳ*/	

#define FRAMEFLAG_YC_JC01			0x5A	/*ң����֡---�������1*/	
#define FRAMEFLAG_YC_JC02			0x5B	/*ң����֡---�������2*/	

#define FRAMEFLAG_YCNP_ZD01		0x61	/*ң�������---��������*/	
#define FRAMEFLAG_YCNP_ZD02		0x62	/*ң�������---�Ҷ�������*/	

#define FRAMEFLAG_YCZH_QX01		0x71	/*ң�������---�����غ����ݶ�֡1*/	
#define FRAMEFLAG_YCZH_QX02		0x72	/*ң�������---�����غ����ݶ�֡2*/	
#define FRAMEFLAG_YKZH_QX03		0x73	/*ң�ط�����---�����غ�ң�غͻظ�����֡*/	
#define FRAMEFLAG_YKZH_TX712		0x74	/*ң�ط�����---712ͨ���غ�ң�غͻظ�����֡*/	


#define FRAMEFLAG_YK				0x91	/*ң��ָ��֡��־*/	
#define FRAMEFLAG_FK				0x92	/*���п���ָ��֡��־*/	
#define FRAMEFLAG_CX				0xA1	/*���ݲ�ѯ֡��־*/	


/*-----ң��ָ�����------*/
#define	MSGCTRL_YK01_FlightMode				0x01		/*	����ģʽ					*/
#define	MSGCTRL_YK02_WeightAdjust_Lock		0x02		/*	���ص���װ����������	*/
#define	MSGCTRL_YK03_WeightAdjustCtrl			0x03		/*	���ص���װ�ÿ���		*/
#define	MSGCTRL_YK04_NavCtrl					0x04		/*	�ߵ�����					*/
#define	MSGCTRL_YK05_FK_ComputHeart			0x05		/*	�ɿؼ��������			*/
#define	MSGCTRL_YK06_FK_ComputerReset		0x06		/*	�ɿؼ��������			*/
#define	MSGCTRL_YK07_FK_ComuterCtrl			0x07		/*	�ɿؼ��������			*/
#define	MSGCTRL_YK08_LandingParSet			0x08		/*	���������������		*/
#define	MSGCTRL_YK09_AirscrewCtrl				0x09		/*	�ƽ������ͣ����		*/
#define	MSGCTRL_YK0A_PropellerNCtrl			0x0A		/*	�ƽ����ת�ٿ���		*/
#define	MSGCTRL_YK0B_ValveCtrl					0x0B		/*	���巧�ſ���				*/
#define	MSGCTRL_YK0C_BallonetExploderControl	0x0C		/*	���屬�ƿ���				*/
#define	MSGCTRL_YK0D_ValveExplodeCtrl			0x0D		/*	���ű��ƿ���				*/
#define	MSGCTRL_YK0E_BalnetColPreFire			0x0E		/*	����ɼ�Ԥ���			*/
#define	MSGCTRL_YK0F_BalnetColCtrl				0x0F		/*	����ɼ���������		*/
#define	MSGCTRL_YK10_EnergySysCtrl			0x10		/*	��Դϵͳ����				*/
#define	MSGCTRL_YK12_VectorAngelCtrl			0x12		/*	ʸ��װ�ýǶȿ���		*/
#define	MSGCTRL_YK13_VectorParamCtrl			0x13		/*	ʸ��װ�ò�������		*/
#define	MSGCTRL_YK14_MovCameraAngel			0x14		/*	��̨װ�ýǶȿ���		*/
#define	MSGCTRL_YK15_MovCaParamCtrl			0x15		/*	��̨װ�ò�������		*/
#define	MSGCTRL_YK16_ImageSysCtrl				0x16		/*	�Եس���װ�ÿ���		*/
#define	MSGCTRL_YK17_AnalogImageSwitchCtrl	0x17		/*	ģ��ͼ���л�				*/
#define	MSGCTRL_YK18_DigitalImageSwitchCtrl	0x18		/*	����ͼ���л�				*/



/*-----���ݲ�ѯ����------*/
#define	MSGDATA_CX01_FlightCtrl01		0x01		
#define	MSGDATA_CX02_FlightCtrl02		0x02		




/*-----ָ��ִ��״̬����------*/
#define YK_ANSWER_SUCCESS		0x01					//ң��ָ��ִ�гɹ�
#define YK_ANSWER_ERR_CHECK	0x02					//У�����
#define YK_ANSWER_ERR_LACK	0x03					//�������߱��޷�ִ��


#define CX_ANSWER_SUCCESS		0x01					//��ѯ�ɹ�
#define CX_ANSWER_ERR_CHECK	0x02					//У�����
#define CX_ANSWER_ERR_LACK	0x03					//�������߱��޷���ѯ


/*-----����֡����ֽ���------*/
#define	Max_YCBtCount	140		//ң����������ֽڳ���	
#define	Max_YKBtCount	140		//ң�ػظ�֡����ֽڳ���	








/*------------------------------------------------------------------------------*
 *								�ṹ�嶨��
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/







/*-------------------------------ң�����ݽṹ��----------------------------------*/

/*ң�⸱֡1(����01��֡0x51)ң������*/
typedef struct
{
	DEF_UINT8	Count;										/*ѭ������*/
	DEF_UINT8 	FrameFlag;									/*֡��־*/
	DEF_UINT8	CompuState[2];								/*�ɿؼ����Ӳ��״̬1��2*/
	
	DEF_UINT8	TempraCtrl; 									/*�ɿ��¿�״̬0x00-�Զ��¿أ�0x01-���£�0x02-������*/
	DEF_UINT8	WeightAdjust_Lock; 							/*���ص���װ������״̬ bit0-���ص���1�������ƣ�   bit1-���ص���1���ؿ��ƣ�״̬��0-������1-������*/
	DEF_UINT8	WeightAdjustState;							/*���ص���״̬��bit0-���ص���1�������ƣ�   bit1-���ص���1���ؿ��ƣ�״̬��0-������1-������*/
	DEF_UINT8	WeightAdjustOpenTime;						/*��������1����ʱ��*/

	DEF_UINT8 	Reserved_9;									/*�����ֽ�9*/
	DEF_UINT8 	DelayReceiveState[4];						/*��ʱ״̬(1)(2)(3)(4)*/
	DEF_UINT8	CompuRecState;								/*�ɿؼ������¼���*/
	DEF_UINT16	CompuRecBlock;								/*�ɿؼ������¼λ��*/

	DEF_UINT32	CompuSysTime;								/*�ɿؼ����ϵͳʱ��*/
	DEF_INT16	BaricAlt;									/*��ѹ�߶�*/
	DEF_UINT16	BaricAltPressure;							/*�����ѹ*/

	DEF_INT8	BaricAltUpDownSpeed;						/*��ѹ�߶������ٶ�*/
	DEF_UINT8	CompuResetState;							/*�ɿؼ��������״̬ 0x00-ȡ������׼����0x11-����׼��1��0x55-����׼��2��0x66-����������*/
	DEF_INT16	CriticalBaricAlt;								/*���ظ߶�*/

	DEF_UINT16	CKBreakTime;								/*��·�жϼ�ʱ*/
	DEF_UINT8	FKCJChannel;								/*��ǰ�ڲ�ͨ��ͨ��*/
	DEF_UINT8 	SafeCtrlMinite;								/*����ʱ��,��λmin*/
	
	DEF_UINT32	INS_GPS_millisecond;        					/*���ߵ�-GPS����*/
	DEF_FLOAT32 INSLon;										/*���ߵ�-�ߵ�����*/
	DEF_FLOAT32 INSLat;										/*���ߵ�-�ߵ�γ��*/
	
	DEF_UINT16	INS_GPS_week;								/*���ߵ�-GPS��*/
	DEF_INT16 	PitchSpeed;									/*���ߵ�-�������ٶ�*/
	DEF_INT16	RollSpeed;									/*���ߵ�-��ת���ٶ�*/
	DEF_INT16	YawSpeed;									/*���ߵ�-ƫ�����ٶ�*/
	
	DEF_INT16	AX;											/*���ߵ�-X����ٶ�*/	
	DEF_INT16	AY;											/*���ߵ�-Y����ٶ�*/	
	DEF_INT16	AZ;											/*���ߵ�-Z����ٶ�*/
	DEF_INT16 	Roll;										/*���ߵ�-��ת��*/
	
	DEF_INT16	Pitch;										/*���ߵ�-������*/
	DEF_UINT16	Yaw;										/*���ߵ�-�����*/
	DEF_INT16 	INSAlt;										/*���ߵ�-�ߵ��߶�*/
	DEF_INT16	North_V;									/*���ߵ�-�����ٶ�*/
	
	DEF_INT16	East_V;										/*���ߵ�-�����ٶ�*/		
	DEF_INT16	Up_V;										/*���ߵ�-��ֱ�ٶ�*/
	DEF_UINT16	Double_Antenna_Heading;					/*���ߵ�-˫���ߺ���*/	
	DEF_INT16	Double_Antenna_Pitch;						/*���ߵ�-˫���߸���*/	
	
	DEF_UINT16	BaseLineLength;								/*���ߵ�-���߳���*/
	DEF_INT16 	GPSAlt;										/*���ߵ�-GPS�߶�*/
	DEF_FLOAT32	GPSLat;										/*���ߵ�-GPSγ��*/
	DEF_FLOAT32 GPSLon;										/*���ߵ�-GPS����*/
	
	DEF_UINT16	FlightPathAngle;								/*���ߵ�-������*/
	DEF_UINT8	INS_State;									/*���ߵ�-״̬/����ģʽ*/
	DEF_UINT8	INS_SiteSolveState;							/*���ߵ�-���ջ�����״̬*/
	
	DEF_UINT8	ReserAlignType;								/*���ߵ�-����λ����*/
	DEF_UINT8	Double_TrackingNumber;						/*���ߵ�-˫���߸���������*/	
	DEF_UINT8	Double_SatelliteSolveNumber;				/*���ߵ�-˫���߽���������*/
	DEF_UINT8	PrimaAlignType; 							/*���ߵ�-����λ����*/
	
	DEF_UINT8	SatelTrackNumber;							/*���ߵ�-��λ����������*/
	DEF_UINT8	SatelSolveNumber;							/*���ߵ�-��λ����������*/
	DEF_UINT8 	Reserved_99;								/*�����ֽ�99*/
	DEF_UINT8	CheckSum;									/*У���*/
	}_DEFSTRU_HD01YC; 


/*ң�⸱֡2(����02��֡0x52)ң������*/
typedef struct
{
	DEF_UINT8	Count;										/*ѭ������*/
	DEF_UINT8	FrameFlag;									/*֡��־*/
	DEF_UINT8	CompuState[2];								/*�ɼ������Ӳ��״̬1��2*/

	DEF_UINT8	TempraCtrl; 									/*�ɼ��¿�״̬0x00-�Զ��¿أ�0x01-���£�0x02-������*/
	DEF_UINT8 	Reserved_6[2];								/*�����ֽ�6~7*/
	DEF_UINT8	CompuRecState;								/*�ɼ��������¼���*/

	DEF_UINT32	CompuSysTime;								/*�ɼ������ϵͳʱ��*/
	DEF_UINT16	CompuRecBlock;								/*�ɼ��������¼λ��*/
	DEF_UINT8	CompuResetState;							/*�ɼ����������״̬  0x00-ȡ������׼����0x11-����׼��1��0x55-����׼��2��0x66-����������*/
	DEF_UINT8	LoadYCTranSwitch;							/*�غɴ��俪�� ��bit0-���������� bit1-�Ҷ��������� bit2-�����غɣ�bit3-ͨ���غɡ���ʾ��0-�����䣻1-���䡣*/

	DEF_UINT8 	ImageSys_State;							/*����ϵͳ״̬��*/
	DEF_UINT8	ImageSwitchesChannels;						/*ͼ���л���ͨ��  bit0~bit3������ͼ��ͨ����bit4~bit7��ģ��ͼ��ͨ������ʾ��1~8��Ӧͨ��1~8��*/
	DEF_UINT16 	ImageLength_Light;							/*����ϵͳ����(��ѧ����)*/

	DEF_UINT16 	ImageLength_Position;						/*����ϵͳ�۽�(�۽�λ��)*/
	DEF_INT16 	MovCameraAngle[2];							/*��̨װ�ýǶ�ֵ1��2 */
	DEF_INT16 	MovCameraActualN[2];						/*��̨װ�õ��ת�ٲ���ֵ1��2 */	
	DEF_UINT16 	MovCameraState[2];							/*��̨װ�õ��״̬1��2 */
	DEF_INT8 	MovCameraMainwireVol[2];					/*��̨װ�õ��ĸ�ߵ�ѹ1��2 */
	
	DEF_INT8	MovCameraCurrent[2];						/*��̨װ�õ������1��2 */
	DEF_UINT16	SunlightIntensity;							/*����ǿ��*/
	
	DEF_UINT32	INS_GPS_millisecond;     						/*���ߵ�-GPS����*/
	DEF_FLOAT32 InsLon;										/*���ߵ�-�ߵ�����*/
	DEF_FLOAT32 InsLat;										/*���ߵ�-�ߵ�γ��*/

	DEF_UINT16	INS_GPS_week;								/*���ߵ�-GPS��*/
	DEF_INT16 	PitchSpeed;									/*���ߵ�-�������ٶ�*/
	DEF_INT16	RollSpeed;									/*���ߵ�-��ת���ٶ�*/
	DEF_INT16	YawSpeed;									/*���ߵ�-ƫ�����ٶ�*/

	DEF_INT16	AX;											/*���ߵ�-X����ٶ�*/	
	DEF_INT16	AY;											/*���ߵ�-Y����ٶ�*/
	DEF_INT16	AZ;											/*���ߵ�-Z����ٶ�*/
	DEF_INT16 	Roll;										/*���ߵ�-��ת��*/
	
	DEF_INT16	Pitch;										/*���ߵ�-������*/
	DEF_UINT16	Yaw;										/*���ߵ�-�����*/
	DEF_INT16 	InsAlt;										/*���ߵ�-�ߵ��߶�*/
	DEF_INT16	North_V;									/*���ߵ�-�����ٶ�*/
	
	DEF_INT16	East_V;										/*���ߵ�-�����ٶ�*/	
	DEF_INT16	Up_V;										/*���ߵ�-��ֱ�ٶ�*/
	DEF_UINT16	Double_Antenna_Heading;					/*���ߵ�-˫���ߺ���*/	
	DEF_INT16	Double_Antenna_Pitch;						/*���ߵ�-˫���߸���*/

	DEF_UINT16	BaseLineLength;								/*���ߵ�-���߳���*/	
	DEF_UINT8	INS_SatelitNum[2];							/*���ߵ�-����1��2������*/
	
	DEF_UINT8	IMU_State;									/*���ߵ�-IMU����״̬*/
	DEF_UINT8	INSSys_State;								/*���ߵ�-ϵͳ״̬*/
	DEF_UINT8	INS_GNSSFlag;								/*���ߵ�-GNSS_flag*/
	DEF_UINT8	INS_NAVFlag;								/*���ߵ�-NAV_flag*/

	DEF_UINT8 	DelayReceiveState[3];						/*��ʱ״̬1~3*/
	DEF_UINT8	CheckSum;									/*У���*/
}_DEFSTRU_HD02YC;		
	

/*ң�⸱֡3(�ƽ���֡0x53)ң������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	FlightMode;								/*����ģʽ*/
	DEF_UINT8 	FK_UseINS;								/*�ɿ�ʹ�ùߵ� 0x00-���ߵ���0x01-���ߵ���*/
	
	DEF_UINT16 	AirscrewCtrlN[5];							/*�������ת��(��ǰ���,�����,��ǰ���,�Һ���,������)*/
	DEF_UINT16 	AirscrewActualN[5];						/*���ת�ٲ���ֵ(��ǰ���,�����,��ǰ���,�Һ���,������)*/
	
	DEF_UINT8 	AirscrewState[5];						/*���״̬(��ǰ���,�����,��ǰ���,�Һ���,������)*/	
	DEF_UINT8	AirscrewCurrent[5];						/*��������(��ǰ���,�����,��ǰ���,�Һ���,������)*/
	DEF_UINT8 	AirscrewMainwireVol[5];					/*���ĸ�ߵ�ѹ(��ǰ���,�����,��ǰ���,�Һ���,������)*/
	DEF_UINT8	AirscrewRadiatorDutyRatio[5];			/*���������ռ�ձ�(��ǰ���,�����,��ǰ���,�Һ���,������)*/ 
	
	DEF_UINT8	AirscrewCtrlState;						/*�����ͣ״̬bit0~ bit3����ǰ���~�Һ����� bit4����������״̬��0-ֹͣ��1-������*/
	DEF_UINT8 	Reserved_46;							/*�����ֽ�46*/
	DEF_UINT16	PropellerN_Limit;						/*�ƽ����ת���޷�*/ 

	DEF_UINT16	FrontPropelN_Limit;						/*������ת���޷�*/ 
	DEF_INT16 	VectorAngle;							/*ʸ��װ�ýǶ�ֵ*/
	
	DEF_INT16 	VectorActualN;							/*ʸ��װ�õ��ת�ٲ���ֵ*/
	DEF_UINT16 	VectorState;								/*ʸ��װ�õ��״̬*/
	
	DEF_INT8 	VectorMainwireVol;						/*ʸ��װ�õ��ĸ�ߵ�ѹ*/
	DEF_INT8	VectorCurrent;							/*ʸ��װ�õ������*/
	DEF_UINT16	GNSS_GPS_week;						/*GNSS-GPS��*/

	DEF_UINT32	GNSS_GPS_millisecond;            			/*GNSS-GPS����*/
	DEF_FLOAT32 GNSS_GPSLon;							/*GNSS-GPS����*/
	
	DEF_FLOAT32	GNSS_GPSLat;							/*GNSS-GPSγ��*/
	DEF_INT16 	GNSS_GPSAlt;							/*GNSS-GPS�߶�*/
	DEF_UINT8	GNSS_ReceiverState;						/*GNSS-���ջ�״̬*/
	DEF_UINT8	GNNS_AlignType;						/*GNSS��λ����*/

	DEF_UINT8	GNSS_SatelTrackNumber;				/*GNSS-������������*/
	DEF_UINT8	GNSS_SatelSolveNumber;					/*GNSS-��������������*/
	DEF_INT16 	VectorCtrlAngle;							/*ʸ��װ�ÿ��ƽǶ�ֵ*/
	
	DEF_UINT8 	Reserved_81[3];							/*�����ֽ�81~83*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_TJYC;		



/*ң�⸱֡4(��Դ��֡0x54)ң������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8	FrameFlag;								/*֡��־*/
	DEF_UINT16	DCDCOutputVol[3];						/*DC/DC�����ѹ:��ѹ��28V��29V*/
	DEF_UINT16	DCDCOutputCur[3];						/*DC/DC�������:��ѹ��28V��29V*/
	DEF_UINT8	DCDC_State[3];							/*DC/DC״̬:��ѹ��28V��29V*/
	DEF_UINT8 	HighDCWorkMode;						/*��ѹDC����ģʽ*/
	DEF_UINT16	Solar_Vol;								/*��ѹ DC̫�������е�ѹ*/
	
	DEF_UINT16	Solar_Cur;								/*��ѹ DC̫�������е���*/	
	DEF_UINT16	BatteryVol[3];					      		/*���ܵ��1��2��Ӧ��﮵�ص�ѹ*/
	DEF_INT16	BatteryCur[3];							/*���ܵ��1��2��Ӧ��﮵�س�ŵ����*/
	DEF_UINT8	BatterySOC[3];							/*���ܵ��1��2��Ӧ��﮵��SOCֵ*/	
	DEF_UINT8	BatteryHeat[3];							/*���ܵ��1��2��Ӧ��﮵�ؼ���״̬*/	

	DEF_UINT16	BatteryCellVol[2][3];						/*���ܵ��1��2��Ӧ��﮵�ص����ѹ 0-��Сֵ,����ֵ;  1-���ܵ��1�����ܵ��2��Ӧ��﮵��*/	
	DEF_UINT8	BatteryCellVol_ID[2][3];					/*���ܵ��1��2��Ӧ��﮵�ص����ѹ��ֵID:   0-���,���;  1-���ܵ��1�����ܵ��2��Ӧ��﮵��*/	
	DEF_UINT8	Battery_Temp_ID[2][3];					/*���ܵ��1��2��Ӧ��﮵�ص����¶ȼ�ֵID :   0-��ߣ����;  1-���ܵ��1�����ܵ��2��Ӧ��﮵��*/

	DEF_UINT8 	BatteryEorro[3];							/*���ܵ��1��2��Ӧ��﮵�ع���*/
	DEF_UINT8 	BatteryInOut[2];							/*���ܵ��1��2�ŵ�״̬*/
	DEF_UINT8 	PowerReceiPoint;						/*��Դ�豸�����ն�*/	
	DEF_UINT8	DCDC_Temprature[3];					/*DC/DC�¶� :��ѹ��  28V�� 29V*/
	DEF_INT8	AverageBatteryTemperature[3];			/*���ܵ��1��2Ӧ��﮵�ص�����¶Ⱦ�ֵ*/
	
	DEF_INT8	MaxBatteryTemperature[3];				/*���ܵ��1��2Ӧ��﮵�ص�����¶ȼ���ֵ*/
	DEF_INT8	MinBatteryTemperature[3];				/*���ܵ��1��2Ӧ��﮵�ص�����¶ȼ�Сֵ*/
	DEF_UINT8 	Reserved_83;							/*�����ֽ�83*/	
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_NYYC;		



/*ң�⸱֡5(���帱֡0x55)ң������*/
typedef struct
{
	DEF_UINT8 	Count;								/*ѭ������*/
	DEF_UINT8 	FrameFlag;							/*֡��־*/
	DEF_UINT8 	CommandTransBack[4];				/*ָ��ش�(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	Reserve_7[4];						/*�����ֽ�7~10*/
	DEF_UINT8	BalnetPowerVol[4]; 					/*����ɼ������ѹ(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	BalnetBatteryVol[4];					/*����ɼ���ص�ѹ(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	Ballonet_ValveCur[4];				/*���巧�ŵ���(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	ValvePowderState[4];				/*���Ż�Ʒ״̬(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8 	Reserved_27[4];						/*�����ֽ�27~30*/
	DEF_UINT8 	Ballonet_ValveState[4];				/*����״̬(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	BallonetExploderState[4];				/*���屬����״̬(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	BallonetFireState[4];					/*������״̬(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	BallonetWorkState[4];				/*����ɼ�����״̬(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_UINT8	BD_SatelitNum[2];					/*����1��2��λ��������(�в��Ҳ�����ǰ���Ҳ���)*/

	DEF_INT16	BD_Alt[2];							/*����1��2�߶�(�в��Ҳ�����ǰ���Ҳ���)*/
	DEF_FLOAT32	BD_Lon[2];							/*����1��2����(�в��Ҳ�����ǰ���Ҳ���)*/
	DEF_FLOAT32 BD_Lat[2];							/*����1��2γ��(�в��Ҳ�����ǰ���Ҳ���)*/

	DEF_UINT8	BD_state[2];							/*����1��2��λ״̬(�в��Ҳ�����ǰ���Ҳ���)*/
	DEF_INT16	Ballonet_PressureGap[4];				/*����ɼ�����ѹ��(�в��Ҳ���������ǰ���Ҳ�������)*/	
	DEF_INT16	Ballonet_ValveAngle[4];				/*���ŽǶ�(�в��Ҳ���������ǰ���Ҳ�������)*/	
	DEF_UINT8 	Reserved_87;						/*�����ֽ�87*/
	DEF_UINT8	CheckSum;							/*У���*/
}_DEFSTRU_NTYC;



/*ң�⸱֡6(�������01��֡0x5A)ң������*/
typedef struct
{
	DEF_UINT8 	Count;								/*ѭ������*/
	DEF_UINT8	FrameFlag;							/*֡��־*/
	DEF_INT8	CompuTempra; 						/*�ɿؼ�����ڲ��¶�*/
	DEF_UINT8	CabinTemp[3];						/*�����¶�(1)~(3)*/
	DEF_UINT8 	Reserved_7[5];						/*�����ֽ�7~11*/
	DEF_INT8	EnviTemp;							/*�����¶�*/

	DEF_UINT8	Lat_Deviation;						/*���ߵ�γ�ȱ�׼��*/
	DEF_UINT8 	Lon_Deviation;						/*���ߵ�-���ȱ�׼��*/
	DEF_UINT8 	InsAlt_Deviation;					/*���ߵ�-�߶ȱ�׼��*/
	DEF_UINT8	Pitch_Deviation;						/*���ߵ�-�����Ǳ�׼��*/
	
	DEF_UINT8 	Roll_Deviation;						/*���ߵ�-��ת�Ǳ�׼��*/
	DEF_UINT8	Yaw_Deviation;						/*���ߵ�-����Ǳ�׼��*/
	DEF_UINT8	East_V_Deviation;					/*���ߵ�-�����ٶȱ�׼��*/	
	DEF_UINT8	North_V_Deviation;					/*���ߵ�-�����ٶȱ�׼��*/	
	
	DEF_UINT8	Up_V_Deviation;						/*���ߵ�-��ֱ�ٶȱ�׼��*/
	DEF_UINT8	INSTemp;							/*���ߵ�-�ߵ��¶�*/
	DEF_UINT8	INSTempMeasreState;				/*���ߵ�-�¶Ȳ���״̬*/
	DEF_UINT8 	Reserved_24[4];						/*�����ֽ�24,25,26,27*/
	DEF_UINT8 	GNSS_Lat_Deviation;					/*GNSS-γ�ȱ�׼��*/
	
	DEF_UINT8 	GNSS_Lon_Deviation;				/*GNSS-���ȱ�׼��*/
	DEF_UINT8 	GNSS_InsAlt_Deviation;				/*GNSS-�߶ȱ�׼��*/	
	DEF_UINT8	GNSS_CompuTempra; 				/*GNSS-�ڲ��¶�*/
	DEF_UINT8	GNSS_TempMeaState;				/*GNSS-�¶Ȳ���״̬*/
	DEF_INT8	AirscrewCrustTemp[4];				/*��������¶�(��ǰ���,�����,��ǰ���,�Һ���)*/
	
	DEF_INT8	VecAirscrewCrustTemp;				/*�����������¶�*/
	DEF_INT8	AirscrewRadiatorTemp[4][2];			/*���������(��ǰ���,�����,��ǰ���,�Һ���) mos�¶�(1~2)*/ 
	DEF_INT8	VecAirscrewRadiatorTemp;			/*�������������¶�*/
	DEF_UINT8 	Reserved_47[2];						/*�����ֽ�47~48*/
	
	DEF_INT16	VectorRadiatorTemp;					/*ʸ��װ�õ���������¶�*/ 
	DEF_UINT8 	Reserved_51[12];					/*�����ֽ�51~62*/
	DEF_INT8	BalnetColBoardTemp[4];				/*����ɼ��忨�¶�(�в��Ҳ���������ǰ���Ҳ�������)*/
	DEF_INT16	Ballonet_Temp[4][6];					/*����ɼ��¶�(1)~(6)(�����в��Ҳ���������ǰ���Ҳ������¶�1,2,5����ʾ��ǰ���Ҳɱ����¶�1,2����ʾ)*/
	DEF_UINT8 	Reserved_115;						/*�����ֽ�115*/
	DEF_UINT8	CheckSum;							/*У���*/
}_DEFSTRU_JC01YC;

/*ң�⸱֡7(�������02��֡0x5B)ң������*/
typedef struct
{
	DEF_UINT8 	Count;								/*ѭ������*/
	DEF_UINT8	FrameFlag;							/*֡��־*/
	DEF_INT8	CompuTempra; 						/*�ɼ�������ڲ��¶�*/
	DEF_UINT8	InsInnerTemp;						/*���ߵ�-�ڲ��¶�*/
	
	DEF_UINT8	Lat_Deviation;						/*���ߵ�-γ�ȱ�׼��*/
	DEF_UINT8	Lon_Deviation;						/*���ߵ�-���ȱ�׼��*/
	DEF_UINT8	InsAlt_Deviation;					/*���ߵ�-�߶ȱ�׼��*/	
	DEF_UINT8	Pitch_Deviation;						/*���ߵ�-�����Ǳ�׼��*/
	
	DEF_UINT8	Roll_Deviation; 						/*���ߵ�-��ת�Ǳ�׼��*/
	DEF_UINT8	Yaw_Deviation;						/*���ߵ�-����Ǳ�׼��*/
	DEF_UINT8	EastV_Deviation;						/*���ߵ�-�����ٶȱ�׼��*/	
	DEF_UINT8	North_V_Deviation;					/*���ߵ�-�����ٶȱ�׼��*/	
	
	DEF_UINT8	Up_V_Deviation; 					/*���ߵ�-��ֱ�ٶȱ�׼��*/
	DEF_UINT8 	Reserved_14;						/*�����ֽ�14*/
	DEF_INT16	MovCameraRadiatorTemp[2];			/*��̨װ�õ���������¶�1��2 */
	DEF_INT8	DISwitchColBoardTemp[2];			/*����ͼ���л�-�忨�¶�1��2*/
	
	DEF_INT8	AISwitchColBoardTemp[2];			/*ģ��ͼ���л�-�忨�¶�1��2*/
	DEF_UINT8 	ImgTxWorkState;					/*ͼ����̨-����״̬*/
	DEF_INT8 	ImgTxTempra;						/*ͼ����̨-оƬ�¶�*/
	
	DEF_UINT16 	ImgTxLost;							/*ͼ����̨-˥��*/
	DEF_UINT8 	ImgTxOutPower;						/*ͼ����̨-�������*/
	DEF_UINT8 	ImgTxInputForm;					/*ͼ����̨-��Ƶ�����ʽ*/
	
	DEF_UINT8 	ImgTxSource;						/*ͼ����̨-��ƵԴ*/
	DEF_UINT8 	ImgTxInLockState;					/*ͼ����̨-��������״̬*/
	DEF_UINT8 	Reserved_31;						/*�����ֽ�31*/
	DEF_UINT8	CheckSum;							/*У���*/
}_DEFSTRU_JC02YC;




/*-------------------------------ң�����ݽṹ��----------------------------------*/

 

/*1-����ģʽ*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	FlightMode;								/*����ģʽ*/
	DEF_UINT8 	Reserved_6[2];							/*�����ֽ�6~7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK01_FlightMode;	


/*2-���ص���װ������*/
typedef struct
{
	
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	WeightAdjust_LockCtrl;					/*���ص���װ��������bit0-���ص���1�������ƣ�bit1-���ص���1���ؿ��ƣ�״̬��0-������1-������*/
	DEF_UINT8 	Reserved_6[2];							/*�����ֽ�6~7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK02_WeightAdjust_Lock;	



/*3-���ص���װ�ÿ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	WeightAdjustCtrl;						/*���ص���װ�ÿ��ƣ�bit0-���ص���1�������ƣ�bit1-���ص���1���ؿ��ƣ�0-�رգ�1-�򿪡�*/
	DEF_UINT8	WeightAdjustDevCtrl_Time;				/*���ص���װ����������ʱ��*/
	DEF_UINT8 	Reserved_7;								/*�����ֽ�7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK03_WeightAdjustCtrl;	



/*4-�ߵ�����*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	INSCalibrationCtrl;						/*�ߵ����¶�׼���� 0x00-���أ�0x11-���ߵ���׼��0x22-���ߵ���׼��*/
	DEF_UINT8	FK_UseINS;								/*�ɿ�ʹ�ùߵ� 0x00-���أ�0x11-���ߵ���0x22-���ߵ���*/		
	DEF_UINT8 	Reserved_7;								/*�����ֽ�7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK04_NavCtrl;



/*5-�ɿؼ��������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	Heart_Source;							/*������Դ��־,0x01-LƵ�β�أ�  0x02-UƵ�β�أ�  0x03-UƵ���ƶ���ء�*/
	DEF_UINT8 	Reserved_6[2];							/*�����ֽ�6~7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK05_FK_ComputHeart;	



/*6-�ɿؼ��������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	ComputerReset_Effect;					/*����ָ��-��Чλ bit0-�ɿؼ����; bit1-�ɼ������  ��ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	ComputerReset;							/*0x00-ȡ������׼����0x11-����׼��1�� 0x55-����׼��2�� 0x66-��������*/
	DEF_UINT8 	Reserved_7;								/*�����ֽ�7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK06_FK_ComputerReset;	


/*7-���������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	TempraCtrlSelect;						/*�¿���Чλbit0-�ɿؼ����; bit1-�ɼ������*/
	DEF_UINT8	TempraCtrl;								/*�¶ȿ��� �¿�ָ��0-�Զ��¿أ�1-���£�2-������*/
	DEF_UINT8	RecordCtrlSelect;						/*��¼������Чλbit0-�ɿؼ����; bit1-�ɼ������*/
	DEF_UINT8	RecordCtrl;								/*��¼����,0x00����¼,0x01��¼*/
	
	DEF_UINT8	MemClearCtrlSelect;						/*�洢���������Чλbit0-�ɿؼ����; bit1-�ɼ������*/
	DEF_UINT8	MemClearCtrl;							/*�洢�������0x01-�洢�����0x02-ϵͳʱ����㣻0x03-�洢���ͬʱϵͳʱ�����*/
	DEF_UINT8	LoadYCTranSwitch_Effect;				/*�غɴ��俪�� ������Чλ:   0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8	LoadYCTranSwitch;						/*�غɴ��俪�� ��bit0-���������� bit1-�Ҷ��������� bit2-�����غɣ�bit3-ͨ���غɡ���ʾ��0-�����䣻1-����*/

	DEF_UINT8	InChannelCtrl_Effect;					/*�ڲ�ͨ��ͨ������-��Чλ			0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8	InChannelCtrl;							/*0-��ͨ����1-��ͨ����*/
	DEF_UINT8 	PowerReceiPoint_Effect;					
	DEF_UINT8 	PowerReceiPoint;						/*��Դ�豸�����ն�*/	
	
	DEF_UINT8 	Reserved_17[3];							/*�����ֽ�17~19*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK07_FK_ComuterCtrl;	






/*8-���������������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	Effe_SafeCtrlMinite;						/*����ʱ������-��Чλ  0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8 	SafeCtrlMinite;							/*����ʱ��,    ��λmin*/
	DEF_UINT8	Effe_CriticalBaricAlt;						/*���ظ߶�����-��Чλ  0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8 	Reserved_8;								/*�����ֽ�8*/

	DEF_INT16	CriticalBaricAlt;							/*���ظ߶�   ��λ��m*/
	DEF_UINT8 	Reserved_11;							/*�����ֽ�11*/	
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK08_LandingParSet;	


/*9-�ƽ������ͣ����*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	AirscrewCtrlSelect;						/*�����ͣ������Чλ,bit0~ bit3������ǰ���~�Һ�����bit4-��������*/
	DEF_UINT8	AirscrewCtrl[5];							/*�����ͣ����,0x00ֹͣ,0x01����(��ǰ���,�����,��ǰ���,�Һ���,������)*/
	DEF_UINT8 	Reserved_11;							/*�����ֽ�11*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK09_AirscrewCtrl;	


/*10-�ƽ����ת�ٿ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	AirscrewNCtrlSelect;						/*�ƽ����ת�ٿ�����Чλ,bit0~ bit3������ǰ���~�Һ�����bit4-��������*/
	DEF_UINT8 	Reserved_6;								/*�����ֽ�6*/
	DEF_UINT16	AirscrewNCtrl[5];							/*�ƽ����ת�ٿ���(��ǰ���,�����,��ǰ���,�Һ���,������)*/

	DEF_UINT8	PropellerN_LimitSelect;					/*���������ƽ�ת���޷���Чλ0x00��Ч��0xAA��Ч*/
	DEF_UINT8	FrontPropelN_LimitSelect;				/*������ת���޷���Чλ0x00��Ч��0xAA��Ч*/
	DEF_UINT16	PropellerN_Limit;						/*�ƽ����ת���޷�*/
	DEF_UINT16	FrontPropelN_Limit;						/*������ת���޷�*/ 
	DEF_UINT8 	Reserved_23;							/*�����ֽ�23*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK0A_PropellerNCtrl;	





/*11-���巧�ſ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	Ballonet_ValveCtrlSelect;					/*���巧�ſ���-��Чλbit0~bit3�ֱ��Ӧ�������б���ǰ����ǰ������ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	Ballonet_ValveCtrl[4];					/*���巧�ſ���*/
	DEF_UINT8	Ballonet_ValveCtrlTime[4];				/*���巧�ſ���ʱ��*/
	DEF_UINT8 	Reserved_14[2];							/*�����ֽ�14~15*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK0B_ValveCtrl;	



/*12-���屬�ƿ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/
	
	DEF_UINT8	BallonetExploderMode;					/*���屬��ģʽ0x01-��������     ; 0x02-һ�±���   */
	DEF_UINT8	BallonetExploderCtrl[4];					/*���屬�ƿ���0x01~0x04��Ӧ�𱬱�����1~4��*/
	DEF_UINT8	BallSameTimeExpCtrl;					/*����һ�±��ƿ���bit0~bit3�ֱ��Ӧ�������б���ǰ����ǰ������ʾ��0-��Ч��1-һ�±��ơ�*/
	DEF_UINT8 	Reserved_11;							/*�����ֽ�11*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK0C_BallonetExploderControl;	



/*13-���ű��ƿ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	ValveExplodeCtrl;						/*���ű��ƿ���bit0~bit3�ֱ��Ӧ�������б���ǰ����ǰ������ʾ��0-��Ч�� 1-�𱬡�*/
	DEF_UINT8 	Reserved_6[2];							/*�����ֽ�6~7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK0D_ValveExplodeCtrl;	



/*14-����ɼ�Ԥ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	BalnetColPreFire;						/*����ɼ�Ԥ���bit0~bit3�ֱ��Ӧ�������б���ǰ����ǰ������ʾ��0-Ԥ���أ�  1-Ԥ��𿪡�*/
	DEF_UINT8 	Reserved_6[2];							/*�����ֽ�6~7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK0E_BalnetColPreFire;	



/*15-����ɼ���������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	BalnetColWorkCtrlEffect;					/*����ɼ���������-��Чλbit0~bit3�ֱ��Ӧ�������б���ǰ����ǰ������ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	BalnetColWorkCtrl[4];					/*����ɼ���������0x00-������0x01-����*/
	DEF_UINT8	BDYCTransCtrlEffect;						/*����ң���·�����-��Чλbit0~bit3�ֱ��Ӧ�������б���ǰ����ǰ������ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	BDYCTransCtrl[4];						/*����ң���·�����0x00-ֹͣ�·���0x01-�����·�*/
	DEF_UINT8 	Reserved_15;							/*�����ֽ�15*/
	DEF_UINT8	CheckSum;								/*У���*/
	
}_DEFSTRU_YK0F_BalnetColCtrl;	



/*16-��Դ�������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	PowerCtrlSelect;							/*����ѡ��,0x00-�ɿؼ������ 0x01-�ɼ��������*/
	DEF_UINT8 	Reserved_6;								/*�����ֽ�6*/
	DEF_UINT8	DCDCCtrlEffect;							/*DC/DC������Чλ��0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8 	DCDCCtrlByte;							/*DC-DC�����ֽ�	bit0~bit1:��ѹ DC����; 	bit2~bit3: ��ѹ DC����ģʽ;       bit4~bit5:28V_DC����;	bit6~bit7:29V_DC����;00-�أ�01-��*/

	DEF_UINT16	DCDCSetCur;								/*��ѹDC����Ŀ�����*/
	DEF_UINT16	DCDCSetVol;								/*��ѹ DC����Ŀ���ѹ*/

	DEF_UINT8	DCDCTraCtEffect;						/*DC-DC��ʱ�ش�-������Чλ    ��ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	DCDCTraCtrl;							/*DC-DC��ʱ�ش�����   ��ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	BatteryInputCtEffect;						/*���ܵ�س��ڿ���-��Чλ-0xAA*/
	DEF_UINT8	BatteryInputCtrl;							/*���ܵ�س��ڿ��� ��ʾ��0-�رգ�0x01-�򿪡�ע���������ܵ�س���һ��أ�Ӧ��﮵�ز��ء�*/

	DEF_UINT8	BatteryOutputCtEffect;					/*���ܵ�طŵ�ڿ���-��Чλ-0xAA*/
	DEF_UINT8	BatteryOutputCtrl;						/*���ܵ�طŵ�ڿ���   ע���������ܵ�طŵ��һ��أ�Ӧ��﮵�ز��ء�*/
	DEF_UINT8 	Reserved_19;							/*�����ֽ�19*/
	DEF_UINT8	CheckSum;								/*У���*/	
}_DEFSTRU_YK10_EnergySysCtrl;	






/*17-���п������ݴ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	FKData[96];								/*�ɿ�����5~99*/
}_DEFSTRU_YK11_FlightCtrlDataTrans;	


/*18-ʸ��װ�ýǶȿ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_INT16	VectorAngelCtrl;							/*ʸ��װ�ýǶ�*/
	DEF_UINT8 	Reserved_7;								/*�����ֽ�7*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK12_VectorAngelCtrl;	

/*19-ʸ��װ�ò�������*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	Effect_VertorOnOff;						/*ʸ��װ����ͣ����-��Чλ��0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8	VertorOnOff;								/*ʸ��װ����ͣ���ƣ�0x01-ֹͣ;   0x02-����;   0x03-���㡣*/
	DEF_UINT8	Effect_VectorErroClear;					/*ʸ��װ�ù������-��Чλ��0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT8	VectorErroClear;							/*ʸ��װ�ù������, 0x00-�ŷ�;   0x01-����ϰ���*/
	
	DEF_UINT8 	Reserved_9;								/*�����ֽ�9*/
	DEF_UINT8	Effect_VectorNCtrl;						/*ʸ��װ��ת�ٿ���-��Чλ��0x00-��Ч��0xAA-��Ч��*/
	DEF_UINT16	VectorNCtrl;								/*ʸ��װ��ת�ٿ���*/

	DEF_UINT8 	Reserved_13[3];							/*�����ֽ�13~15*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK13_VectorParamCtrl;	

/*20-��̨װ�ýǶȿ���*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_INT16	AngelCtrl[2];								/*��̨װ�ýǶ�1~2*/
	DEF_UINT8	Effect_AngelCtrl;							/*��̨װ�ýǶ�-��Чλ,    bit0-��̨����1��bit1-��̨����2��    ��ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8 	Reserved_10[2];							/*�����ֽ�10~11*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK14_MovCameraAngel;	

/*21-��̨װ�ò�������	*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8	Effect_OnOff;							/*��̨װ����ͣ����-��Чλ�� bit0-��̨����1��bit1-��̨����2��    ��ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	OnOff[2];								/*��̨װ����ͣ����1~2��0x01-ֹͣ;   0x02-����;   0x03-���㡣*/
	DEF_UINT8	Effect_ErroClear;						/*��̨װ�ù������-��Чλ�� bit0-��̨����1��bit1-��̨����2��    ��ʾ��0-��Ч��1-��Ч��*/
	DEF_UINT8	ErroClear[2];							/*��̨װ�ù������1~2, 0x00-��Ч;   0x01-����ϰ���*/
	DEF_UINT8 	Reserved_11;							/*�����ֽ�11*/
	DEF_UINT8	Effect_NCtrl;								/*��̨װ��ת�ٿ���-��Чλ�� bit0-��̨����1��bit1-��̨����2��    ��ʾ��0-��Ч��1-��Ч��*/

	DEF_UINT16	NCtrl[2];									/*��̨װ��ת�ٿ���1~2*/

	DEF_UINT8 	Reserved_17[3];							/*�����ֽ�17~19*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK15_MovCaParamCtrl;	


/*22-�Եس���װ�ÿ���		*/
typedef struct
{
	DEF_UINT8 	Count;									/*ѭ������*/
	DEF_UINT8 	FrameFlag;								/*֡��־*/
	DEF_UINT8	CommandCode;							/*ָ�����*/
	DEF_UINT8	ExecuteState;							/*ִ��״̬*/

	DEF_UINT8 	Image_Comand1;						/*������1*/
	DEF_UINT8 	Image_Comand2;						/*������2*/
	DEF_UINT16 	Image_Height;							/*�߶�*/
	
	DEF_UINT8 	ControlStep;								/*���Ʋ���*/
	DEF_UINT8 	Reserved_10[2];							/*�����ֽ�10~11*/
	DEF_UINT8	CheckSum;								/*У���*/
}_DEFSTRU_YK16_ImageSysCtrl;	





/*23-ģ��ͼ���л�		*/
typedef struct
{
	DEF_UINT8 	Count;									/*	ѭ������	*/
	DEF_UINT8 	FrameFlag;								/*	֡��־		*/
	DEF_UINT8	CommandCode;							/*	ָ�����	*/
	DEF_UINT8	ExecuteState;							/*	ִ��״̬	*/

	DEF_UINT8	SwitchChannel;							/*	�л�ͨ��	*/
	DEF_UINT8 	Reserved_6[2];							/*	�����ֽ�6~7	*/
	DEF_UINT8	CheckSum;								/*	У���		*/
}_DEFSTRU_YK17_AnalogImageSwitchCtrl;

/*24-����ͼ���л�		*/
typedef struct
{
	DEF_UINT8 	Count;									/*	ѭ������	*/
	DEF_UINT8 	FrameFlag;								/*	֡��־		*/
	DEF_UINT8	CommandCode;							/*	ָ�����	*/
	DEF_UINT8	ExecuteState;							/*	ִ��״̬	*/
	
	DEF_UINT8	SwitchChannel;							/*	�л�ͨ��	*/
	DEF_UINT8 	Reserved_6[2];							/*	�����ֽ�6~7	*/
	DEF_UINT8	CheckSum;								/*	У���		*/
}_DEFSTRU_YK18_DigitalImageSwitchCtrl;











/*ң�����ݼ��ϰ�*/
typedef struct
{
_DEFSTRU_HD01YC	HD01;
_DEFSTRU_HD02YC	HD02;
_DEFSTRU_TJYC		TJ;
_DEFSTRU_NYYC		NY;
_DEFSTRU_NTYC		NT;
}_DEFSTRU_YC_All;


/*ң�����ݼ��ϰ�*/
typedef struct
{
_DEFSTRU_JC01YC		JC01;
_DEFSTRU_JC02YC		JC02;
}_DEFSTRU_YC_Low;

/*------------------------------------------------------------------------------*
 *								��������
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/

 extern const DEF_UINT8 g_YC_Date_Length[YC_DATA_COUNT];				//ң�����ݽṹ�峤��
 extern const DEF_UINT8 g_YC_FRAMEFLAG[YC_DATA_COUNT];				//ң������֡��־
 extern _DEFSTRU_YC_All g_YC_Package;								//ң�����ݼ��ϰ�

 extern const DEF_UINT8 g_YCLow_Date_Length[YC_DATA_COUNTLow];				//ң�����ݽṹ�峤��
 extern const DEF_UINT8 g_YCLow_FRAMEFLAG[YC_DATA_COUNTLow];				//ң������֡��־
 extern _DEFSTRU_YC_Low g_YCLowPack;								//ң�����ݼ��ϰ�




//ң��ָ��
extern	_DEFSTRU_YK01_FlightMode						YK01_FlightMode;
extern	_DEFSTRU_YK02_WeightAdjust_Lock				YK02_WeightAdjust_Lock;
extern	_DEFSTRU_YK03_WeightAdjustCtrl				YK03_WeightAdjustCtrl;
extern	_DEFSTRU_YK04_NavCtrl						YK04_NavCtrl;
extern	_DEFSTRU_YK05_FK_ComputHeart				YK05_FK_ComputHeart;
extern	_DEFSTRU_YK06_FK_ComputerReset				YK06_FK_ComputerReset;
extern	_DEFSTRU_YK07_FK_ComuterCtrl					YK07_FK_ComuterCtrl;
extern	_DEFSTRU_YK08_LandingParSet					YK08_LandingParSet;
extern	_DEFSTRU_YK09_AirscrewCtrl					YK09_AirscrewCtrl;
extern	_DEFSTRU_YK0A_PropellerNCtrl					YK0A_PropellerNCtrl;
extern	_DEFSTRU_YK0B_ValveCtrl						YK0B_ValveCtrl;
extern	_DEFSTRU_YK0C_BallonetExploderControl			YK0C_BallonetExploderControl;
extern	_DEFSTRU_YK0D_ValveExplodeCtrl				YK0D_ValveExplodeCtrl;
extern	_DEFSTRU_YK0E_BalnetColPreFire				YK0E_BalnetColPreFire;
extern	_DEFSTRU_YK0F_BalnetColCtrl					YK0F_BalnetColCtrl;
extern	_DEFSTRU_YK10_EnergySysCtrl					YK10_EnergySysCtrl;
extern	_DEFSTRU_YK11_FlightCtrlDataTrans				YK11_FlightCtrlDataTrans;
extern	_DEFSTRU_YK12_VectorAngelCtrl					YK12_VectorAngelCtrl;
extern	_DEFSTRU_YK13_VectorParamCtrl				YK13_VectorParamCtrl;
extern	_DEFSTRU_YK14_MovCameraAngel				YK14_MovCameraAngel;
extern	_DEFSTRU_YK15_MovCaParamCtrl				YK15_MovCaParamCtrl;
extern	_DEFSTRU_YK16_ImageSysCtrl					YK16_ImageSysCtrl;
extern	_DEFSTRU_YK17_AnalogImageSwitchCtrl			YK17_AnalogImageSwitchCtrl;
extern	_DEFSTRU_YK18_DigitalImageSwitchCtrl			YK18_DigitalImageSwitchCtrl;



 
/*------------------------------------------------------------------------------*
 *								��������
void Modelname();
 *------------------------------------------------------------------------------*/
 


#endif 







