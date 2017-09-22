/*========================================================================================*
 * FILE:                     	B_YKYC_Operate.h                   
 *========================================================================================*
 *
 * COPYRIGHT 2008-2015 BY 513 教研室
 *
 *========================================================================================*
 *
 * 名称:  
 *
 * 描述: 	
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
 * 2015/03/26  聂春雨	Created.
 *========================================================================================*/ 
#ifndef M_B_YKYC_Operate_H
#define M_B_YKYC_Operate_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_GlobalDefine.h"

 
 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/
 #define	YK_AnStoreCount	40		//遥控回复环形队列长度
 #define	YCFramFastSlow		11		//快慢帧比例+1
/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/
  /*遥测副帧1(快帧)遥测数据*/
typedef struct
{
	DEF_UINT8 	m_SycCode1;								/*同步码1*/
	DEF_UINT8 	m_SycCode2;								/*同步码2*/
	DEF_UINT8 	m_StationNum;								/*站编号*/
	DEF_UINT8 	m_FrameFlag;								/*帧标志*/
	
	DEF_UINT8 	m_Count;									/*循环计数*/
	DEF_UINT8 	m_Reserved_6;								/*备用字节6*/
	DEF_INT16 	m_BaricAlt1;								/*气压高度1*/
	
	DEF_INT32 	m_INSLon;										/*经度*/
	DEF_INT32 	m_INSLat;										/*纬度*/

	DEF_INT16 	m_InsAlt;									/*惯导高度*/
	DEF_INT16 	m_GPSAlt;									/*GPS高度*/
	DEF_INT16 	m_Pitch;									/*俯仰角*/
	DEF_INT16 	m_Roll;										/*滚转角*/
	
	DEF_UINT16	m_Heading;									/*真航向*/
	DEF_UINT8 	m_UpFreq;									/*当前上行频点*/
	DEF_UINT8 	m_DownFreq;								/*当前下行频点*/
	
	DEF_UINT8 	m_TerminalState1;							/*机载终端状态1*/
	DEF_UINT8 	m_TerminalState2;							/*机载终端状态2*/
	DEF_UINT8 	m_Reserved;								/*备用字节*/
	DEF_UINT8 	m_CheckSum;								/*校验和*/
}_SJZYC001_FastFrame;										/*遥测数据组SJZYC_001*/

/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 extern _DEFSTRU_YC_All All_YCFast_Package;				
 extern _DEFSTRU_YC_Low All_YCLowPack;			

 extern DEF_UINT16	YC_Date_StepBegain[YC_DATA_COUNT];	//遥测数据节点位置
 extern DEF_UINT16	YC_Date_StepBegain_Low[YC_DATA_COUNTLow];	//遥测数据节点位置
 extern DEF_UINT8		*P_ForYCPackge;				//遥测数据包指针

 
/*------------------------------------------------------------------------------*
 *								函数声明
void Modelname();
 *------------------------------------------------------------------------------*/
 
/*------------采集计算机数据接收---------*/
void	Task_CJComputer_Receive();


void All_YCPackgeRenew();

/*------------遥测数据和遥控回复发送任务 ------------*/
void Task_YCYKBack_Send();

/*-------遥测数据发送-----------*/
void Only_YC_Send();

/* ------------L频段测控---遥控指令接收------------*/
void Task_LlinkCK_Reiceive();

/* ------------U频段测控---遥控指令接收------------*/
void Task_UlinkCK_Reiceive();


/*遥控指令执行*/
void Only_YK_Operate();

void UComFKSendCJ(DEF_UINT8 *BuffP, DEF_UINT8 SendCount);


/*加入遥控回复队列*/
void YKCX_Answer_State_Date(DEF_UINT8 *ykcx_struct, DEF_UINT8 count, DEF_UINT8 ykcx_state);

/*-----U频段测控---数据发送----------*/
void ReserveCK_Send(DEF_UINT8 *p, DEF_UINT8 Length);



/* ------------U频段测控---链路测试帧发送------------*/
void	Task_Ulink_SendTestFram();


/*--------------具体遥控指令执行--------------*/
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








