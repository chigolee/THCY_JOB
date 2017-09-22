/*========================================================================================*
 * FILE:                     	B_CtrlLaw_Operate.h                   
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
 * 2017/02/26 陈天	Created.
 *========================================================================================*/ 
#ifndef M_B_CtrlLaw_Operate_H
#define M_B_CtrlLaw_Operate_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
 #include "B_GlobalDefine.h"
 #include "math.h"
 #include "B_SelfDefine_RemoteStruct.h"

 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/
#define 	CtrlSys_MtMk					637.6725				//经度线上万分之一rad到米的换算单位
//#define 	CtrlSys_LTLK					1					// 变换系数 只求一次 //经度做变换，乘以cos(纬度)
//CtrlSys_LTLK=cos((double)GPS_Lat_Z*3.14/180.0/600000.0);

#define 	CtrlSys_HoverWay				6					//盘旋航线
#define 	CtrlSys_LastPoint				1					//前一个航点
#define 	CtrlSys_CurrentPoint			2					//当前航点
#define 	CtrlSys_TempPoint				0					//临时寄存航点

#define  	MaxPathNum						5					//最大航线数目
#define  	MaxPointNum						20					//最大航点数目

#define		CtrlSys_PI						3.1415926

#define		CtrlSys_TakeOff					0x00				//飞行模式，升空、降落
#define		CtrlSys_RC						0x01				//飞行模式，遥控
#define		CtrlSys_AUTO					0x02				//飞行模式，自主

#define		CtrlSys_UNNORMAL				0x00				//飞行状态，不正常
#define		CtrlSys_NORMAL					0x01				//飞行状态，正常

#define		CtrlSys_Vect_Limit				900					// 矢量角限幅，单位0.1度



#define		CtrlSys_l1						12					//前油门距X轴距离
#define		CtrlSys_l2						48					//后油门距重心距离

#define		CtrlSys_Pro_Max					600					//主推螺旋桨转速限制,600r/min
#define		CtrlSys_Pro_Min					50					//主推螺旋桨转速限制,600r/min
#define		CtrlSys_Fan_Max				3000				//前部风扇螺旋桨转速限制,3000r/min
#define		CtrlSys_Fan_Min					100					//前部风扇螺旋桨转速限制,3000r/min

#define		CtrlSys_Fan_change				300					//前部风扇螺旋桨转速每秒变化,100r/min

//控制相关参数定义
#define		CtrlSys_kyth					300					//内环比例段分界线
#define		CtrlSys_iyth					150					//内环积分有效门限
#define		CtrlSys_kcth					60					//外环比例段分界线
#define		CtrlSys_icth					50					//外环积分有效门限


//遥控模式参数定义

#define		RC_Tail_Plus					0x01				//前部螺旋桨转速+
#define		RC_Tail_Minus					0x02				//前部螺旋桨转速-

#define		RC_Vector_Reset					0x01				//前部矢量归零

 //飞行模式定义
#define		FlightModel_Flyup				0x10				//升空模式

#define		FlightModel_RCCtrl_Normal		0x01				//遥控飞行，标准模式
#define		FlightModel_RCCtrl_Mix			0x02				//遥控飞行，组合调姿模式
#define		FlightModel_RCCtrl_Fault			0x03				//遥控飞行，故障模式

#define		FlightModel_Stay_Area			0x30				//自主区域驻留
#define		FlightModel_SetDirection		0x31				//自主定航向
#define		FlightModel_Stay				0x32				//自主抗风驻留
#define		FlightModel_GoPoint_1			0x33				//自主航点航线1巡航
#define		FlightModel_GoPoint_2			0x34				//自主航点航线2巡航
#define		FlightModel_GoPoint_3			0x35				//自主航点航线3巡航
#define		FlightModel_GoPoint_4			0x36				//自主航点航线4巡航
#define		FlightModel_GoPoint_5			0x37				//自主航点航线5巡航
#define		FlightModel_FlyRound			0x38				//自主圆轨迹

#define		FlightModel_Getdown				0x4e				//降落模式





/*-----飞控相关指令代码-----*/
#define	CtrlLaw_FlightPathInput					0x01		/*	航线注入				*/
#define	CtrlLaw_CruiseCirclePara				0x02		/*	巡航圆参数设置			*/
#define	CtrlLaw_StayModePara					0x03		/*	驻留模式参数设置		*/
#define	CtrlLaw_TrajPlanPara					0x04		/*	制导控制参数设置		*/
#define	CtrlLaw_CruiseDirection					0x05		/*	期望航向角设置			*/
#define	CtrlLaw_GesturePara						0x06		/*	姿态控制参数设置		*/
#define	CtrlLaw_CtrlAllocatePara				0x07		/*	控制分配参数设置		*/
#define	CtrlLaw_SpeedPara						0x08		/*	速度控制参数设置		*/
#define	CtrlLaw_WindSpDirection					0x09		/*	风速风向设置			*/
#define	CtrlLaw_EngineState						0x0A		/*	动力系统故障信息		*/
#define	CtrlLaw_RemoteCtrl						0x0B		/*	手柄遥控控制指令		*/
#define	CtrlLaw_NavEKFPara						0x0C		/*	惯导滤波参数设置		*/


/*-----数据查询代码------*/
#define	MSGDATA_CX01_FlightCtrl01		0x01		
#define	MSGDATA_CX02_FlightCtrl02		0x02		
#define	MSGDATA_CX03_FlightCtrl03		0x03		
#define	MSGDATA_CX04_FlightCtrl04		0x04
/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/


/* 1-飞行控制数据-- 航线注入*/
typedef struct
{

	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_UINT8	PathNO;									/*航线编号*/
	DEF_UINT8	PointCount;								/*航点数目*/
	DEF_UINT8	PointNO;								/*航点编号*/
	DEF_UINT8	PointTask;								/*航点任务*/
	
	DEF_INT32	PointLong;								/*航点经度*/
	DEF_INT32	PointLat;								/*航点纬度*/

	DEF_UINT16	PreTurningLen;							/*提前转弯量*/
	DEF_UINT8	PathChange;								/*航线切换*/
	DEF_UINT8	PathRestart;								/*航线循环*/
	
	DEF_UINT8 	Reserved_21[3];							/*备用字节21~23*/
	DEF_UINT8	CheckSum;								/*校验和*/	

}_DEFSTRU_CtrlLaw01_FlightPathInput;	



/* 2-飞行控制数据-- 巡航圆参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_INT32	CruiseCircleLong;						/*圆巡航圆心经度*/
	DEF_INT32	CruiseCircleLat;							/*圆巡航圆心纬度*/
	
	DEF_UINT16	CruiseCircleRadius;						/*圆巡航圆半径R*/
	DEF_UINT16	PreTurningLen;							/*圆巡航提前转弯量*/

	DEF_UINT8 	Reserved_17[3];							/*备用字节17~19*/
	DEF_UINT8	CheckSum;								/*校验和*/

}_DEFSTRU_CtrlLaw02_CruiseCirclePara;	


/* 3-飞行控制数据-- 驻留模式参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_INT32	HomeLong;								/*驻留点经度*/
	DEF_INT32	HomeLat;								/*驻留点纬度*/
	DEF_INT16	HomeHeight;								/*驻留点高度*/
	DEF_UINT16	CoreAreaDist;							/*驻留区域核心区域半径*/
	DEF_UINT16	TotalAreaDist;							/*驻留区域总半径*/
	DEF_UINT16	BufferAreaDist;							/*驻留区域边界缓冲距离*/

	DEF_UINT8 	Reserved_21[3];							/*备用字节21~23*/
	DEF_UINT8	CheckSum;								/*校验和*/	
	
}_DEFSTRU_CtrlLaw03_StayModePara;	


/* 4-飞行控制数据-- 制导控制参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_FLOAT32	Para_kcpt;								/*制导控制参数总比例*/
	DEF_FLOAT32	Para_kcp1;								/*制导控制参数比例1 段*/
	DEF_FLOAT32	Para_kcp2;								/*制导控制参数比例2 段*/
	DEF_FLOAT32	Para_kci;								/*制导控制参数*/
	DEF_FLOAT32	Para_kcd;								/*制导控制参数*/
	DEF_FLOAT32	Para_kcth;								/*制导控制参数开启门限值*/
	DEF_FLOAT32	Para_kclimit;							/*制导控制输出总限位*/

	DEF_UINT8 	Reserved_33[3];							/*备用字节33~35*/
	DEF_UINT8	CheckSum;								/*校验和*/	
	
}_DEFSTRU_CtrlLaw04_TrajPlanPara;	



/* 5-飞行控制数据-- 期望航向角设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_FLOAT32	CruiseDirection;							/*巡航航向*/
	
	DEF_UINT8 	Reserved_9[3];							/*备用字节9~11*/
	DEF_UINT8	CheckSum;								/*校验和*/	
	
}_DEFSTRU_CtrlLaw05_CruiseDirection;	



/* 6-飞行控制数据-- 姿态控制参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_FLOAT32	Para_kypt;								/*航向控制参数总比例kypt*/
	DEF_FLOAT32	Para_kyp1;								/*航向控制参数比例1 段*/
	DEF_FLOAT32	Para_kyp2;								/*航向控制参数比例2 段*/
	DEF_FLOAT32	Para_kyi;								/*航向控制参数kyi*/
	DEF_FLOAT32	Para_kyd;								/*航向控制参数kyd*/
	DEF_FLOAT32	Para_kyth;								/*航向控制参数开启门限值kyth*/
	DEF_FLOAT32 Para_kylimit;							/*航向控制输出总限位*/

	DEF_UINT8 	Reserved_33[3];							/*备用字节33~35*/
	DEF_UINT8	CheckSum;								/*校验和*/	

}_DEFSTRU_CtrlLaw06_GesturePara;	



/* 7-飞行控制数据-- 控制分配参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_FLOAT32	CAPara1;								/*控制分配参数1*/
	DEF_FLOAT32	CAPara2;								/*控制分配参数2*/
	DEF_FLOAT32	CAPara3;								/*控制分配参数3*/
	DEF_FLOAT32	CAPara4;								/*控制分配参数4*/
	DEF_FLOAT32	CAPara5;								/*控制分配参数5*/
	DEF_FLOAT32	CAPara6;								/*控制分配参数6*/

	DEF_UINT8 	Reserved_29[3];							/*备用字节29~31*/
	DEF_UINT8	CheckSum;								/*校验和*/	
	
}_DEFSTRU_CtrlLaw07_CtrlAllocatePara;	



/* 8-飞行控制数据-- 速度控制参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_FLOAT32	Para_kvp;								/*速度控制参数kvp*/
	DEF_FLOAT32	Para_kvi;								/*速度控制参数kvi*/
	DEF_FLOAT32	Para_kvd;								/*速度控制参数kvd*/
	DEF_UINT16	CruiseSpeed;							/*巡航速度*/

	DEF_UINT8 	Reserved_19;							/*备用字节19*/
	DEF_UINT8	CheckSum;								/*校验和*/	

}_DEFSTRU_CtrlLaw08_SpeedPara;	



/* 9-飞行控制数据-- 风速风向设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_FLOAT32	WindSet_H_Angle;						/*设定水平风向角*/
	DEF_INT16	WindSpSet_V;							/*设定垂向风速*/
	DEF_INT16	WindSpSet_H;							/*设定水平风速*/

	DEF_UINT8 	Reserved_13[3];							/*备用字节13~15*/
	DEF_UINT8	CheckSum;								/*校验和*/	
	
}_DEFSTRU_CtrlLaw09_WindSpDirection;	



/* 10-飞行控制数据-- 动力系统故障信息*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_UINT8 	Propeller1;								/*螺旋桨电机1 状态*/
	DEF_UINT8 	Propeller2;								/*螺旋桨电机2 状态*/
	DEF_UINT8 	Propeller3;								/*螺旋桨电机3 状态*/
	DEF_UINT8 	Propeller4;								/*螺旋桨电机4 状态*/	
	DEF_UINT8 	Propeller_Front;							/*前部风扇状态*/
	DEF_UINT8 	Vertor;									/*矢量装置状态*/
	DEF_UINT8 	EnginState;								/*动力系统工作模式*/
	
	DEF_UINT8	CheckSum;								/*校验和*/	

}_DEFSTRU_CtrlLaw0A_EngineState;	



/* 11-飞行控制数据-- 手柄遥控控制指令*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_UINT8	CtrlMode;								/*遥控模式*/

	DEF_UINT8 	Reserved_6;								/*备用字节6*/
	
	DEF_UINT16 	Propeller_Left;							/*左主推转速*/
	DEF_UINT16 	Propeller_Right;						/*右主推转速*/
	DEF_UINT8 	Propeller_Front;						/*前部电机控制状态*/
	DEF_UINT8 	Reserved_12;							/*备用字节12*/
	
	DEF_INT16	VertorAngle;							/*矢量装置转角*/	
	DEF_UINT8	VectorReset;							/*矢量装置归零按钮状态*/	
	
	DEF_UINT8	CheckSum;								/*校验和*/		
}_DEFSTRU_CtrlLaw0B_RemoteCtrl;	


/* 12-飞行控制数据-- 惯导滤波参数设置*/
typedef struct
{

	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_FLOAT32 PitchAngleQ;      //俯仰角状态协方差
	DEF_FLOAT32 PitchAngleRateQ;  //俯仰角速度状态协方差
	DEF_FLOAT32 PitchAngleR;      //俯仰角输出协方差
	DEF_FLOAT32 PitchAngleRateR;  //俯仰角速度输出协方差

	DEF_FLOAT32 YawAngleQ;		 //偏航角状态协方差
	DEF_FLOAT32 YawAngleRateQ;    //偏航角速度状态协方差
	DEF_FLOAT32 YawAngleR;        //偏航角输出协方差
	DEF_FLOAT32 YawAngleRateR;    //偏航角速度输出协方差

	DEF_FLOAT32 RollAngleQ;       //滚转角状态协方差
	DEF_FLOAT32 RollAngleRateQ;   //滚转角速度状态协方差
	DEF_FLOAT32 RollAngleR;       //滚转角输出协方差
	DEF_FLOAT32 RollAngleRateR;   //滚转角速度输出协方差

	DEF_FLOAT32 VelocityOutputQ1;  //速度输出协方差1
	DEF_FLOAT32 VelocityOutputQ2;  //速度输出协方差2

	DEF_UINT8	IsEKF;			   //滤波有效位  0x01 有效, 0x00 无效
	DEF_UINT8	Reserved_62[2];		
	DEF_UINT8	CheckSum;			/*校验和*/		

}_DEFSTRU_CtrlLaw0C_NavEKFPara;




/* 13-飞行控制数据-- 飞控用状态数据*/
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




/* 14-飞行控制数据--惯导输出原始数据*/
typedef struct
{
    DEF_INT16 		PitchAngle;       //俯仰角
	DEF_INT16 		RollAngle;        //滚转角
	DEF_UINT16 		HeadAngle;        //航向角
	DEF_INT16 		PitchAngleRate;   //俯仰角速度
	DEF_INT16 		YawAngleRate;     //偏航角速度
	DEF_INT16 		RollAngleRate;    //滚转角速度
	DEF_INT16	 	PitchDA;          //双天线俯仰
	DEF_UINT16  	YawDA;            //双天线航向 
	//DEF_DOUBLE64 	PitchCov;         //俯仰角方差
	//DEF_DOUBLE64 	YawCov;           //偏航角方差
	
} _DEFSTRU_CtrlLaw0E_AttitudeDataOrigin;




/* 15-飞行控制数据--滤波后输出数据*/
typedef struct
{
    DEF_INT16 	PitchAngle;       //俯仰角
	DEF_INT16 	RollAngle;        //滚转角
	DEF_UINT16 	HeadAngle;        //航向角
	DEF_INT16 	PitchAngleRate;   //俯仰角速度
	DEF_INT16 	YawAngleRate;     //偏航角速度
	DEF_UINT16 	RollAngleRate;    //滚转角速度	
	
} _DEFSTRU_CtrlLaw0F_AttitudeDataDealed;


/* 16-飞行控制仿真数据，控制输出结构体-------------*/
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
	DEF_UINT8	Reserved_17;		//备用
	DEF_UINT8	CheckSum;

}_DEFSTRU_CtrlLaw0G_SemSimFKtoMAT;



/* 17-飞行控制仿真数据，仿真返回结构体-------------*/
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

	DEF_UINT8		Reserved_53[3];		//备用
	DEF_UINT8		CheckSum;			/*校验和*/	

}_DEFSTRU_CtrlLaw0H_SemSimMATtoFK;





/*-----------查询指令-------------*/
/*飞行控制数据查询*/
typedef struct
{

	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*查询状态*/

	DEF_UINT8 	Reserved_5[3];							/*备用字节5~7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_CX_FlightCtrlData;	


/*航线查询回复帧*/
typedef struct
{
	
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_UINT8	PathNO;									/*航线编号*/
	DEF_UINT8	PointCount;								/*航点数目*/
	DEF_UINT8	PointNO;								/*航点编号*/
	DEF_UINT8	PointTask;								/*航点任务*/
	
	DEF_INT32	PointLong;								/*航点经度*/
	DEF_INT32	PointLat;								/*航点纬度*/

	DEF_UINT16	PreTurningLen;							/*提前转弯量*/
	DEF_UINT8	PathChange;								/*航线切换*/
	DEF_UINT8	PathRestart;							/*航线循环*/
	
	DEF_UINT8 	Reserved_21[3];							/*备用字节21~23*/
	DEF_UINT8	CheckSum;								/*校验和*/	

	

}_DEFSTRU_CXHF01_FlightCtrlData;



/*飞控参数查询回复帧1*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*查询状态*/

	DEF_INT32	CruiseCircleLong;						/*圆巡航圆心经度*/
	DEF_INT32	CruiseCircleLat;							/*圆巡航圆心纬度*/	
	DEF_UINT16	CruiseCircleRadius;						/*圆巡航圆半径R*/
	DEF_UINT16	PreTurningLen;							/*圆巡航提前转弯量*/
	
	DEF_INT32	HomeLong;								/*驻留点经度*/
	DEF_INT32	HomeLat;								/*驻留点纬度*/
	DEF_INT16	HomeHeight;								/*驻留点高度*/
	DEF_UINT16	CoreAreaDist;							/*驻留区域核心区域半径*/
	DEF_UINT16	TotalAreaDist;							/*驻留区域总半径*/
	DEF_UINT16	BufferAreaDist;							/*驻留区域边界缓冲距离*/
	
	DEF_FLOAT32	Para_kcpt;								/*制导控制参数总比例*/
	DEF_FLOAT32	Para_kcp1;								/*制导控制参数比例1 段*/
	DEF_FLOAT32	Para_kcp2;								/*制导控制参数比例2 段*/
	DEF_FLOAT32	Para_kci;								/*制导控制参数*/
	DEF_FLOAT32	Para_kcd;								/*制导控制参数*/
	DEF_FLOAT32	Para_kcth;								/*制导控制参数开启门限值*/
	DEF_FLOAT32	Para_kclimit;							/*制导控制输出总限位*/	

	DEF_FLOAT32	CruiseDirection;						/*巡航航向*/	

	DEF_FLOAT32	Para_kypt;								/*航向控制参数总比例kypt*/
	DEF_FLOAT32	Para_kyp1;								/*航向控制参数比例1 段*/
	DEF_FLOAT32	Para_kyp2;								/*航向控制参数比例2 段*/
	DEF_FLOAT32	Para_kyi;								/*航向控制参数kyi*/
	DEF_FLOAT32	Para_kyd;								/*航向控制参数kyd*/
	DEF_FLOAT32	Para_kyth;								/*航向控制参数开启门限值kyth*/
	DEF_FLOAT32	Para_kylimit;							/*航向控制输出总限位*/
	
	DEF_UINT8	Reserved_93[3];							/*备用字节93~95*/
	DEF_UINT8	CheckSum;								/*校验和*/
	

}_DEFSTRU_CXHF02_FlightCtrlData;


/*飞控参数查询回复帧2*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*查询状态*/
	
	DEF_FLOAT32	CAPara1;								/*控制分配参数1*/
	DEF_FLOAT32	CAPara2;								/*控制分配参数2*/
	DEF_FLOAT32	CAPara3;								/*控制分配参数3*/
	DEF_FLOAT32	CAPara4;								/*控制分配参数4*/
	DEF_FLOAT32	CAPara5;								/*控制分配参数5*/
	DEF_FLOAT32	CAPara6;								/*控制分配参数6*/

	DEF_FLOAT32	Para_kvp;								/*速度控制参数kvp*/
	DEF_FLOAT32	Para_kvi;								/*速度控制参数kvi*/
	DEF_FLOAT32	Para_kvd;								/*速度控制参数kvd*/
	DEF_UINT16	CruiseSpeed;							/*巡航速度*/
	
	DEF_UINT8	Reserved_43[2];							/*备用字节43~44*/

	DEF_FLOAT32	WindSet_H_Angle;						/*设定水平风向角*/
	DEF_INT16	WindSpSet_V;							/*设定垂向风速*/
	DEF_INT16	WindSpSet_H;							/*设定水平风速*/

	DEF_UINT8 	Propeller1;								/*螺旋桨电机1 状态*/
	DEF_UINT8 	Propeller2;								/*螺旋桨电机2 状态*/
	DEF_UINT8 	Propeller3;								/*螺旋桨电机3 状态*/
	DEF_UINT8 	Propeller4;								/*螺旋桨电机4 状态*/		
	DEF_UINT8 	Propeller_Front;						/*前部风扇状态*/
	DEF_UINT8 	Vertor;									/*矢量装置状态*/
	DEF_UINT8 	EnginState;								/*动力系统工作模式*/
	
	DEF_UINT8	CheckSum;								/*校验和*/
	
	
}_DEFSTRU_CXHF03_FlightCtrlData;


/*飞控参数查询回复帧3*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*查询状态*/

	DEF_FLOAT32 PitchAngleQ;     						//俯仰角状态协方差
	DEF_FLOAT32 PitchAngleRateQ;  						//俯仰角速度状态协方差
	DEF_FLOAT32 PitchAngleR;      						//俯仰角输出协方差
	DEF_FLOAT32 PitchAngleRateR;   						//俯仰角速度输出协方差
   
	DEF_FLOAT32 YawAngleQ;		  						//偏航角状态协方差
	DEF_FLOAT32 YawAngleRateQ;     						//偏航角速度状态协方差
	DEF_FLOAT32 YawAngleR;         						//偏航角输出协方差
	DEF_FLOAT32 YawAngleRateR;     						//偏航角速度输出协方差

	DEF_FLOAT32 RollAngleQ;        						//滚转角状态协方差
	DEF_FLOAT32 RollAngleRateQ;    						//滚转角速度状态协方差
	DEF_FLOAT32 RollAngleR;        						//滚转角输出协方差
	DEF_FLOAT32 RollAngleRateR;    						//滚转角速度输出协方差

	DEF_FLOAT32 VelocityOutputQ1;   					//速度输出协方差1
	DEF_FLOAT32 VelocityOutputQ2;   					//速度输出协方差2

	DEF_UINT8	IsEKF;			    					//滤波有效位  0x01 有效, 0x00 无效
	DEF_UINT8	Reserved_62[2];		

	DEF_UINT8	CheckSum;								/*校验和*/
	
	
}_DEFSTRU_CXHF04_FlightCtrlData;



/* 17-飞行控制仿真数据，仿真返回结构体-------------*/
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

	DEF_UINT8		Reserved_53[3];		//备用
	DEF_UINT8		CheckSum;			/*校验和*/	

}_DEFSTRU_Matlab_Recieve;



/* 17---------滤波参数测试用-------------*/
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

	DEF_UINT8		Reserved_53[3];		//备用
	DEF_UINT8		CheckSum;			/*校验和*/	

}_DEFSTRU_CtrlLaw0I_Matlab_Recieve1;








//飞控相关数据
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

	

//查询结构体
extern	_DEFSTRU_CX_FlightCtrlData					CX_FlightCtrlData;
//查询回复帧
extern	_DEFSTRU_CXHF01_FlightCtrlData				CXHF01_FlightCtrlData;
extern	_DEFSTRU_CXHF02_FlightCtrlData				CXHF02_FlightCtrlData;
extern	_DEFSTRU_CXHF03_FlightCtrlData				CXHF03_FlightCtrlData;
extern	_DEFSTRU_CXHF04_FlightCtrlData				CXHF04_FlightCtrlData;

extern	_DEFSTRU_CtrlLaw01_FlightPathInput	FlightPath_Package[5][20];		//航线遥控指令存储
extern	DEF_UINT8	FlightPath_PointCount[5];							//各条航线航点计数




/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

extern DEF_UINT8  g_CtrlSys_CWn;    //当前航线编号
extern DEF_UINT8  g_CtrlSys_CPn;    //当前航点编号

 
/*------------------------------------------------------------------------------*
 *								函数声明
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

 void			CtrlLaw_ini(void);				//控制律初始化函数，每次改变飞行模式需要调用一次
 void			Task_CtrlLaw_Operate(void);				//控制律函数，每0.5s调用一次
 void			Ctrl_Para_Init(void);						//控制律参数初始化函数，开机调用一次
 void			CtrlInfor_Update(void);					//控制律所用数据更新
 void			CtrlInfor_EKF(void);
 void			Send2Matlab(void);
 void			SemSim_Update(void);
 
 

 DEF_UINT8 		CopyWP(_DEFSTRU_CtrlLaw01_FlightPathInput *P1, _DEFSTRU_CtrlLaw01_FlightPathInput *P2);
 DEF_UINT8 		ReadWP(DEF_UINT8 Wn, DEF_UINT8 Pn, _DEFSTRU_CtrlLaw01_FlightPathInput *P);




//仿真用函数
void Task_Mat2FK_Recieve();	
void Task_FK2Mat_Send();
void Task_FK2Mat_Filter_Send();

DEF_UINT8 ChangeHighLowBytes(DEF_UINT8 *p, DEF_UINT8 Count);





void Dowork_YK11_FlightCtrlDataTrans();
void Dowork_CX_FlightCtrlData();



DEF_DOUBLE64 GetLimitValue(DEF_DOUBLE64 CtrlValue, DEF_DOUBLE64 CurrentValue, DEF_FLOAT32 LimitValue);


#endif 




