/*========================================================================================*
 * FILE:                     	B_Ballonet_Operate.h                   
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
#ifndef M_B_Ballonet_Operate_H
#define M_B_Ballonet_Operate_H


/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_GlobalDefine.h"

 
 /*------------------------------------------------------------------------------*
 *								�궨��
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/
#define	MaxTransAscllCount	14
#define	MaxTransComaCount	14

/*------------------------------------------------------------------------------*
 *								�ṹ�嶨��
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/

 typedef struct  
{
	DEF_UINT8			FrameHead1;		//----(�ֽ�1)
	DEF_UINT8			FrameHead2;
	DEF_UINT8 			BalloonNO;			//�����				
	DEF_UINT8 			CommandReturn;	//ָ��ش�		

	DEF_UINT16			BoardTem;			//�忨�¶�1 ----(�ֽ�5)
	DEF_UINT16			Pressure;			//ѹ��

	DEF_UINT16			Vol28V;         		//28V��ѹ----(�ֽ�9)
	DEF_UINT16			Vol16V;         		//16V��ѹ

	DEF_UINT16			ValveCurrent;		//���ŵ���----(�ֽ�13)
	DEF_UINT16			W100Temp;			//�¶�W100

	DEF_UINT16			W50Temp;			//�¶�W50----(�ֽ�17)
	DEF_UINT16			Temp[6];			//�¶�6~1
	DEF_UINT8 			Parameter_1;		//����1
	DEF_UINT8 			State_2;				//״̬2

	DEF_UINT16			angle;				//����	----(�ֽ�33)
	DEF_UINT8			ValveState;			//����״̬
	DEF_UINT8			FirePointState;		//��ͷ1-8״̬	

	DEF_UINT8			FireCtlState;			//���1-8����״̬----(�ֽ�37)
	DEF_UINT8 			State_1;				//״̬1
	DEF_UINT16 			TimerFire;			//����ʱ������

	DEF_UINT8 			Parameter_2;		//����2----(�ֽ�41)
	DEF_UINT8			XorChecksum;		//У������
	DEF_UINT8			End1;				//֡β1
	DEF_UINT8			End2;				//֡β2	
}_DEFSTRU_BallColRecivePacage;	//ע����ֽ���ǰ�����ֽ��ں�




//����ɼ����������ݽṹ��
 typedef struct  
{
	DEF_UINT8	head[2];			//z֡ͷ
	DEF_UINT8	StaticByte;			//�̶���0x11
	DEF_UINT8	Command[3];		//����ָ���ͬ��Ч
	DEF_UINT8	ValveCtrlTime[2];	//���ſ���ʱ�䣬��ͬ��Ч
	
	DEF_UINT8	CommandVert[3];	//ȡ��У�飬��ͬ��Ч
	DEF_UINT8	reserved[2];			//����
	DEF_UINT8	Checksum;			//У��ͣ�3~13�ֽ�
	DEF_UINT8	end[2];			//֡β	
}_DEFSTRU_BallCoCtrlSend;			




/*------------------------------------------------------------------------------*
 *								��������
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

 
/*------------------------------------------------------------------------------*
 *								��������
void Modelname();
 *------------------------------------------------------------------------------*/
 

/*----------����ɼ����ݽ��գ�����Ϊ�ɼ�����1~4  -----------*/
void Task_Ballonet_Operate(DEF_UINT8 Collector_NO);

/*----------����ɼ�ң��ָ���( 1-�ɼ�����;     2-ָ��;     3-����ʱ��0.1s  . )  -----------*/
void Ballonet_CtrlSend(DEF_UINT8 Collector_NO,  DEF_UINT8 Comand, DEF_UINT8 Time);


 /*��� У���----���Ϊ���ֽ�,����Ϊ  (�׸��ֽڵ�ַ,�ֽڸ���)    */
DEF_UINT8 XorSum1(DEF_UINT8 *start , DEF_UINT8 count);

 

DEF_FLOAT32	TransAscllToFloat(DEF_UINT8* Ascll, DEF_UINT8*TansState);


#endif 























