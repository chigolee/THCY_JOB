/*========================================================================================*
 * FILE:                     	SelfDefine_RemoteStruct.h                   
 *========================================================================================*
 *
 * COPYRIGHT 2008-2015 BY 513 教研室
 *
 *========================================================================================*
 *
 * 名称:  和遥控遥测协议相关的全部定义，包括结构体、帧标志、结构体长度等。
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
#ifndef M_SelfDefine_RemoteStruct_H
#define M_SelfDefine_RemoteStruct_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_SelfDefine_type.h"

 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/



/*-----消息个数定义------*/
#define		YC_DATA_COUNT				5					/*遥测快帧个数*/
#define		YC_DATA_COUNTLow			2					/*遥测慢帧个数*/


/*-----数据帧-帧标志定义------*/
#define FRAMEFLAG_YC_HD01			0x51	/*遥测快帧---航电01系统*/	
#define FRAMEFLAG_YC_HD02			0x52	/*遥测快帧---航电02系统*/	
#define FRAMEFLAG_YC_TJ			0x53	/*遥测快帧---推进系统*/	
#define FRAMEFLAG_YC_NY			0x54	/*遥测快帧---能源系统*/	
#define FRAMEFLAG_YC_NT			0x55	/*遥测快帧---囊体系统*/	

#define FRAMEFLAG_YC_JC01			0x5A	/*遥测慢帧---监测数据1*/	
#define FRAMEFLAG_YC_JC02			0x5B	/*遥测慢帧---监测数据2*/	

#define FRAMEFLAG_YCNP_ZD01		0x61	/*遥测非周期---左动力测量*/	
#define FRAMEFLAG_YCNP_ZD02		0x62	/*遥测非周期---右动力测量*/	

#define FRAMEFLAG_YCZH_QX01		0x71	/*遥测非周期---气象载荷数据短帧1*/	
#define FRAMEFLAG_YCZH_QX02		0x72	/*遥测非周期---气象载荷数据短帧2*/	
#define FRAMEFLAG_YKZH_QX03		0x73	/*遥控非周期---气象载荷遥控和回复数据帧*/	
#define FRAMEFLAG_YKZH_TX712		0x74	/*遥控非周期---712通信载荷遥控和回复数据帧*/	


#define FRAMEFLAG_YK				0x91	/*遥控指令帧标志*/	
#define FRAMEFLAG_FK				0x92	/*飞行控制指令帧标志*/	
#define FRAMEFLAG_CX				0xA1	/*数据查询帧标志*/	


/*-----遥控指令代码------*/
#define	MSGCTRL_YK01_FlightMode				0x01		/*	飞行模式					*/
#define	MSGCTRL_YK02_WeightAdjust_Lock		0x02		/*	自重调节装置锁定控制	*/
#define	MSGCTRL_YK03_WeightAdjustCtrl			0x03		/*	自重调节装置控制		*/
#define	MSGCTRL_YK04_NavCtrl					0x04		/*	惯导控制					*/
#define	MSGCTRL_YK05_FK_ComputHeart			0x05		/*	飞控计算机心跳			*/
#define	MSGCTRL_YK06_FK_ComputerReset		0x06		/*	飞控计算机重启			*/
#define	MSGCTRL_YK07_FK_ComuterCtrl			0x07		/*	飞控计算机设置			*/
#define	MSGCTRL_YK08_LandingParSet			0x08		/*	自主降落参数设置		*/
#define	MSGCTRL_YK09_AirscrewCtrl				0x09		/*	推进电机启停控制		*/
#define	MSGCTRL_YK0A_PropellerNCtrl			0x0A		/*	推进电机转速控制		*/
#define	MSGCTRL_YK0B_ValveCtrl					0x0B		/*	囊体阀门控制				*/
#define	MSGCTRL_YK0C_BallonetExploderControl	0x0C		/*	囊体爆破控制				*/
#define	MSGCTRL_YK0D_ValveExplodeCtrl			0x0D		/*	阀门爆破控制				*/
#define	MSGCTRL_YK0E_BalnetColPreFire			0x0E		/*	囊体采集预点火			*/
#define	MSGCTRL_YK0F_BalnetColCtrl				0x0F		/*	囊体采集工作设置		*/
#define	MSGCTRL_YK10_EnergySysCtrl			0x10		/*	能源系统控制				*/
#define	MSGCTRL_YK12_VectorAngelCtrl			0x12		/*	矢量装置角度控制		*/
#define	MSGCTRL_YK13_VectorParamCtrl			0x13		/*	矢量装置参数设置		*/
#define	MSGCTRL_YK14_MovCameraAngel			0x14		/*	云台装置角度控制		*/
#define	MSGCTRL_YK15_MovCaParamCtrl			0x15		/*	云台装置参数设置		*/
#define	MSGCTRL_YK16_ImageSysCtrl				0x16		/*	对地成像装置控制		*/
#define	MSGCTRL_YK17_AnalogImageSwitchCtrl	0x17		/*	模拟图像切换				*/
#define	MSGCTRL_YK18_DigitalImageSwitchCtrl	0x18		/*	数字图像切换				*/



/*-----数据查询代码------*/
#define	MSGDATA_CX01_FlightCtrl01		0x01		
#define	MSGDATA_CX02_FlightCtrl02		0x02		




/*-----指令执行状态定义------*/
#define YK_ANSWER_SUCCESS		0x01					//遥控指令执行成功
#define YK_ANSWER_ERR_CHECK	0x02					//校验错误
#define YK_ANSWER_ERR_LACK	0x03					//条件不具备无法执行


#define CX_ANSWER_SUCCESS		0x01					//查询成功
#define CX_ANSWER_ERR_CHECK	0x02					//校验错误
#define CX_ANSWER_ERR_LACK	0x03					//条件不具备无法查询


/*-----数据帧最大字节数------*/
#define	Max_YCBtCount	140		//遥测数据最大字节长度	
#define	Max_YKBtCount	140		//遥控回复帧最大字节长度	








/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/







/*-------------------------------遥测数据结构体----------------------------------*/

/*遥测副帧1(航电01副帧0x51)遥测数据*/
typedef struct
{
	DEF_UINT8	Count;										/*循环计数*/
	DEF_UINT8 	FrameFlag;									/*帧标志*/
	DEF_UINT8	CompuState[2];								/*飞控计算机硬件状态1、2*/
	
	DEF_UINT8	TempraCtrl; 									/*飞控温控状态0x00-自动温控，0x01-加温，0x02-不加温*/
	DEF_UINT8	WeightAdjust_Lock; 							/*自重调节装置锁定状态 bit0-自重调节1连续控制；   bit1-自重调节1开关控制；状态：0-锁定，1-解锁。*/
	DEF_UINT8	WeightAdjustState;							/*自重调节状态，bit0-自重调节1连续控制；   bit1-自重调节1开关控制；状态：0-锁定，1-解锁。*/
	DEF_UINT8	WeightAdjustOpenTime;						/*自重连续1打开总时间*/

	DEF_UINT8 	Reserved_9;									/*备用字节9*/
	DEF_UINT8 	DelayReceiveState[4];						/*超时状态(1)(2)(3)(4)*/
	DEF_UINT8	CompuRecState;								/*飞控计算机记录情况*/
	DEF_UINT16	CompuRecBlock;								/*飞控计算机记录位置*/

	DEF_UINT32	CompuSysTime;								/*飞控计算机系统时间*/
	DEF_INT16	BaricAlt;									/*气压高度*/
	DEF_UINT16	BaricAltPressure;							/*外界气压*/

	DEF_INT8	BaricAltUpDownSpeed;						/*气压高度升降速度*/
	DEF_UINT8	CompuResetState;							/*飞控计算机重启状态 0x00-取消重启准备；0x11-重启准备1；0x55-重启准备2；0x66-进行重启。*/
	DEF_INT16	CriticalBaricAlt;								/*安控高度*/

	DEF_UINT16	CKBreakTime;								/*链路中断计时*/
	DEF_UINT8	FKCJChannel;								/*当前内部通信通道*/
	DEF_UINT8 	SafeCtrlMinite;								/*安控时间,单位min*/
	
	DEF_UINT32	INS_GPS_millisecond;        					/*主惯导-GPS毫秒*/
	DEF_FLOAT32 INSLon;										/*主惯导-惯导经度*/
	DEF_FLOAT32 INSLat;										/*主惯导-惯导纬度*/
	
	DEF_UINT16	INS_GPS_week;								/*主惯导-GPS周*/
	DEF_INT16 	PitchSpeed;									/*主惯导-俯仰角速度*/
	DEF_INT16	RollSpeed;									/*主惯导-滚转角速度*/
	DEF_INT16	YawSpeed;									/*主惯导-偏航角速度*/
	
	DEF_INT16	AX;											/*主惯导-X轴加速度*/	
	DEF_INT16	AY;											/*主惯导-Y轴加速度*/	
	DEF_INT16	AZ;											/*主惯导-Z轴加速度*/
	DEF_INT16 	Roll;										/*主惯导-滚转角*/
	
	DEF_INT16	Pitch;										/*主惯导-俯仰角*/
	DEF_UINT16	Yaw;										/*主惯导-航向角*/
	DEF_INT16 	INSAlt;										/*主惯导-惯导高度*/
	DEF_INT16	North_V;									/*主惯导-北向速度*/
	
	DEF_INT16	East_V;										/*主惯导-东向速度*/		
	DEF_INT16	Up_V;										/*主惯导-垂直速度*/
	DEF_UINT16	Double_Antenna_Heading;					/*主惯导-双天线航向*/	
	DEF_INT16	Double_Antenna_Pitch;						/*主惯导-双天线俯仰*/	
	
	DEF_UINT16	BaseLineLength;								/*主惯导-基线长度*/
	DEF_INT16 	GPSAlt;										/*主惯导-GPS高度*/
	DEF_FLOAT32	GPSLat;										/*主惯导-GPS纬度*/
	DEF_FLOAT32 GPSLon;										/*主惯导-GPS经度*/
	
	DEF_UINT16	FlightPathAngle;								/*主惯导-航迹角*/
	DEF_UINT8	INS_State;									/*主惯导-状态/工作模式*/
	DEF_UINT8	INS_SiteSolveState;							/*主惯导-接收机解算状态*/
	
	DEF_UINT8	ReserAlignType;								/*主惯导-备定位类型*/
	DEF_UINT8	Double_TrackingNumber;						/*主惯导-双天线跟踪卫星数*/	
	DEF_UINT8	Double_SatelliteSolveNumber;				/*主惯导-双天线解算卫星数*/
	DEF_UINT8	PrimaAlignType; 							/*主惯导-主定位类型*/
	
	DEF_UINT8	SatelTrackNumber;							/*主惯导-定位跟踪卫星数*/
	DEF_UINT8	SatelSolveNumber;							/*主惯导-定位解算卫星数*/
	DEF_UINT8 	Reserved_99;								/*备用字节99*/
	DEF_UINT8	CheckSum;									/*校验和*/
	}_DEFSTRU_HD01YC; 


/*遥测副帧2(航电02副帧0x52)遥测数据*/
typedef struct
{
	DEF_UINT8	Count;										/*循环计数*/
	DEF_UINT8	FrameFlag;									/*帧标志*/
	DEF_UINT8	CompuState[2];								/*采集计算机硬件状态1、2*/

	DEF_UINT8	TempraCtrl; 									/*采集温控状态0x00-自动温控，0x01-加温，0x02-不加温*/
	DEF_UINT8 	Reserved_6[2];								/*备用字节6~7*/
	DEF_UINT8	CompuRecState;								/*采集计算机记录情况*/

	DEF_UINT32	CompuSysTime;								/*采集计算机系统时间*/
	DEF_UINT16	CompuRecBlock;								/*采集计算机记录位置*/
	DEF_UINT8	CompuResetState;							/*采集计算机重启状态  0x00-取消重启准备；0x11-重启准备1；0x55-重启准备2；0x66-进行重启。*/
	DEF_UINT8	LoadYCTranSwitch;							/*载荷传输开关 ，bit0-左动力测量； bit1-右动力测量； bit2-气象载荷；bit3-通信载荷。表示：0-不传输；1-传输。*/

	DEF_UINT8 	ImageSys_State;							/*成像系统状态字*/
	DEF_UINT8	ImageSwitchesChannels;						/*图像切换器通道  bit0~bit3：数字图像通道；bit4~bit7：模拟图像通道。表示：1~8对应通道1~8。*/
	DEF_UINT16 	ImageLength_Light;							/*成像系统焦距(光学焦距)*/

	DEF_UINT16 	ImageLength_Position;						/*成像系统聚焦(聚焦位置)*/
	DEF_INT16 	MovCameraAngle[2];							/*云台装置角度值1、2 */
	DEF_INT16 	MovCameraActualN[2];						/*云台装置电机转速测量值1、2 */	
	DEF_UINT16 	MovCameraState[2];							/*云台装置电机状态1、2 */
	DEF_INT8 	MovCameraMainwireVol[2];					/*云台装置电机母线电压1、2 */
	
	DEF_INT8	MovCameraCurrent[2];						/*云台装置电机电流1、2 */
	DEF_UINT16	SunlightIntensity;							/*辅照强度*/
	
	DEF_UINT32	INS_GPS_millisecond;     						/*备惯导-GPS毫秒*/
	DEF_FLOAT32 InsLon;										/*备惯导-惯导经度*/
	DEF_FLOAT32 InsLat;										/*备惯导-惯导纬度*/

	DEF_UINT16	INS_GPS_week;								/*备惯导-GPS周*/
	DEF_INT16 	PitchSpeed;									/*备惯导-俯仰角速度*/
	DEF_INT16	RollSpeed;									/*备惯导-滚转角速度*/
	DEF_INT16	YawSpeed;									/*备惯导-偏航角速度*/

	DEF_INT16	AX;											/*备惯导-X轴加速度*/	
	DEF_INT16	AY;											/*备惯导-Y轴加速度*/
	DEF_INT16	AZ;											/*备惯导-Z轴加速度*/
	DEF_INT16 	Roll;										/*备惯导-滚转角*/
	
	DEF_INT16	Pitch;										/*备惯导-俯仰角*/
	DEF_UINT16	Yaw;										/*备惯导-航向角*/
	DEF_INT16 	InsAlt;										/*备惯导-惯导高度*/
	DEF_INT16	North_V;									/*备惯导-北向速度*/
	
	DEF_INT16	East_V;										/*备惯导-东向速度*/	
	DEF_INT16	Up_V;										/*备惯导-垂直速度*/
	DEF_UINT16	Double_Antenna_Heading;					/*备惯导-双天线航向*/	
	DEF_INT16	Double_Antenna_Pitch;						/*备惯导-双天线俯仰*/

	DEF_UINT16	BaseLineLength;								/*备惯导-基线长度*/	
	DEF_UINT8	INS_SatelitNum[2];							/*备惯导-天线1、2卫星数*/
	
	DEF_UINT8	IMU_State;									/*备惯导-IMU工作状态*/
	DEF_UINT8	INSSys_State;								/*备惯导-系统状态*/
	DEF_UINT8	INS_GNSSFlag;								/*备惯导-GNSS_flag*/
	DEF_UINT8	INS_NAVFlag;								/*备惯导-NAV_flag*/

	DEF_UINT8 	DelayReceiveState[3];						/*超时状态1~3*/
	DEF_UINT8	CheckSum;									/*校验和*/
}_DEFSTRU_HD02YC;		
	

/*遥测副帧3(推进副帧0x53)遥测数据*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	FlightMode;								/*飞行模式*/
	DEF_UINT8 	FK_UseINS;								/*飞控使用惯导 0x00-主惯导；0x01-备惯导。*/
	
	DEF_UINT16 	AirscrewCtrlN[5];							/*电机控制转速(左前电机,左后电机,右前电机,右后电机,航向电机)*/
	DEF_UINT16 	AirscrewActualN[5];						/*电机转速测量值(左前电机,左后电机,右前电机,右后电机,航向电机)*/
	
	DEF_UINT8 	AirscrewState[5];						/*电机状态(左前电机,左后电机,右前电机,右后电机,航向电机)*/	
	DEF_UINT8	AirscrewCurrent[5];						/*电机相电流(左前电机,左后电机,右前电机,右后电机,航向电机)*/
	DEF_UINT8 	AirscrewMainwireVol[5];					/*电机母线电压(左前电机,左后电机,右前电机,右后电机,航向电机)*/
	DEF_UINT8	AirscrewRadiatorDutyRatio[5];			/*电机驱动器占空比(左前电机,左后电机,右前电机,右后电机,航向电机)*/ 
	
	DEF_UINT8	AirscrewCtrlState;						/*电机启停状态bit0~ bit3：左前电机~右后电机； bit4：航向电机。状态：0-停止；1-启动。*/
	DEF_UINT8 	Reserved_46;							/*备用字节46*/
	DEF_UINT16	PropellerN_Limit;						/*推进电机转速限幅*/ 

	DEF_UINT16	FrontPropelN_Limit;						/*航向电机转速限幅*/ 
	DEF_INT16 	VectorAngle;							/*矢量装置角度值*/
	
	DEF_INT16 	VectorActualN;							/*矢量装置电机转速测量值*/
	DEF_UINT16 	VectorState;								/*矢量装置电机状态*/
	
	DEF_INT8 	VectorMainwireVol;						/*矢量装置电机母线电压*/
	DEF_INT8	VectorCurrent;							/*矢量装置电机电流*/
	DEF_UINT16	GNSS_GPS_week;						/*GNSS-GPS周*/

	DEF_UINT32	GNSS_GPS_millisecond;            			/*GNSS-GPS毫秒*/
	DEF_FLOAT32 GNSS_GPSLon;							/*GNSS-GPS经度*/
	
	DEF_FLOAT32	GNSS_GPSLat;							/*GNSS-GPS纬度*/
	DEF_INT16 	GNSS_GPSAlt;							/*GNSS-GPS高度*/
	DEF_UINT8	GNSS_ReceiverState;						/*GNSS-接收机状态*/
	DEF_UINT8	GNNS_AlignType;						/*GNSS定位类型*/

	DEF_UINT8	GNSS_SatelTrackNumber;				/*GNSS-跟踪卫星数量*/
	DEF_UINT8	GNSS_SatelSolveNumber;					/*GNSS-解算用卫星数量*/
	DEF_INT16 	VectorCtrlAngle;							/*矢量装置控制角度值*/
	
	DEF_UINT8 	Reserved_81[3];							/*备用字节81~83*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_TJYC;		



/*遥测副帧4(能源副帧0x54)遥测数据*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8	FrameFlag;								/*帧标志*/
	DEF_UINT16	DCDCOutputVol[3];						/*DC/DC输出电压:高压，28V，29V*/
	DEF_UINT16	DCDCOutputCur[3];						/*DC/DC输出电流:高压，28V，29V*/
	DEF_UINT8	DCDC_State[3];							/*DC/DC状态:高压，28V，29V*/
	DEF_UINT8 	HighDCWorkMode;						/*高压DC工作模式*/
	DEF_UINT16	Solar_Vol;								/*高压 DC太阳能阵列电压*/
	
	DEF_UINT16	Solar_Cur;								/*高压 DC太阳能阵列电流*/	
	DEF_UINT16	BatteryVol[3];					      		/*储能电池1、2和应急锂电池电压*/
	DEF_INT16	BatteryCur[3];							/*储能电池1、2和应急锂电池充放电电流*/
	DEF_UINT8	BatterySOC[3];							/*储能电池1、2和应急锂电池SOC值*/	
	DEF_UINT8	BatteryHeat[3];							/*储能电池1、2和应急锂电池加热状态*/	

	DEF_UINT16	BatteryCellVol[2][3];						/*储能电池1、2和应急锂电池单体电压 0-极小值,极大值;  1-储能电池1，储能电池2，应急锂电池*/	
	DEF_UINT8	BatteryCellVol_ID[2][3];					/*储能电池1、2和应急锂电池单体电压极值ID:   0-最高,最低;  1-储能电池1，储能电池2，应急锂电池*/	
	DEF_UINT8	Battery_Temp_ID[2][3];					/*储能电池1、2和应急锂电池单体温度极值ID :   0-最高，最低;  1-储能电池1，储能电池2，应急锂电池*/

	DEF_UINT8 	BatteryEorro[3];							/*储能电池1、2和应急锂电池故障*/
	DEF_UINT8 	BatteryInOut[2];							/*储能电池1、2放电状态*/
	DEF_UINT8 	PowerReceiPoint;						/*能源设备接收终端*/	
	DEF_UINT8	DCDC_Temprature[3];					/*DC/DC温度 :高压、  28V、 29V*/
	DEF_INT8	AverageBatteryTemperature[3];			/*储能电池1、2应急锂电池电池组温度均值*/
	
	DEF_INT8	MaxBatteryTemperature[3];				/*储能电池1、2应急锂电池电池组温度极大值*/
	DEF_INT8	MinBatteryTemperature[3];				/*储能电池1、2应急锂电池电池组温度极小值*/
	DEF_UINT8 	Reserved_83;							/*备用字节83*/	
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_NYYC;		



/*遥测副帧5(囊体副帧0x55)遥测数据*/
typedef struct
{
	DEF_UINT8 	Count;								/*循环计数*/
	DEF_UINT8 	FrameFlag;							/*帧标志*/
	DEF_UINT8 	CommandTransBack[4];				/*指令回传(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	Reserve_7[4];						/*备用字节7~10*/
	DEF_UINT8	BalnetPowerVol[4]; 					/*囊体采集供电电压(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	BalnetBatteryVol[4];					/*囊体采集电池电压(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	Ballonet_ValveCur[4];				/*囊体阀门电流(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	ValvePowderState[4];				/*阀门火工品状态(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8 	Reserved_27[4];						/*备用字节27~30*/
	DEF_UINT8 	Ballonet_ValveState[4];				/*阀门状态(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	BallonetExploderState[4];				/*囊体爆破索状态(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	BallonetFireState[4];					/*囊体点火状态(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	BallonetWorkState[4];				/*囊体采集工作状态(中部囊采主，备和前部囊采主，备)*/
	DEF_UINT8	BD_SatelitNum[2];					/*北斗1、2定位卫星数量(中部囊采主和前部囊采主)*/

	DEF_INT16	BD_Alt[2];							/*北斗1、2高度(中部囊采主和前部囊采主)*/
	DEF_FLOAT32	BD_Lon[2];							/*北斗1、2经度(中部囊采主和前部囊采主)*/
	DEF_FLOAT32 BD_Lat[2];							/*北斗1、2纬度(中部囊采主和前部囊采主)*/

	DEF_UINT8	BD_state[2];							/*北斗1、2定位状态(中部囊采主和前部囊采主)*/
	DEF_INT16	Ballonet_PressureGap[4];				/*囊体采集内外压差(中部囊采主，备和前部囊采主，备)*/	
	DEF_INT16	Ballonet_ValveAngle[4];				/*阀门角度(中部囊采主，备和前部囊采主，备)*/	
	DEF_UINT8 	Reserved_87;						/*备用字节87*/
	DEF_UINT8	CheckSum;							/*校验和*/
}_DEFSTRU_NTYC;



/*遥测副帧6(监测数据01副帧0x5A)遥测数据*/
typedef struct
{
	DEF_UINT8 	Count;								/*循环计数*/
	DEF_UINT8	FrameFlag;							/*帧标志*/
	DEF_INT8	CompuTempra; 						/*飞控计算机内部温度*/
	DEF_UINT8	CabinTemp[3];						/*吊舱温度(1)~(3)*/
	DEF_UINT8 	Reserved_7[5];						/*备用字节7~11*/
	DEF_INT8	EnviTemp;							/*环境温度*/

	DEF_UINT8	Lat_Deviation;						/*主惯导纬度标准差*/
	DEF_UINT8 	Lon_Deviation;						/*主惯导-经度标准差*/
	DEF_UINT8 	InsAlt_Deviation;					/*主惯导-高度标准差*/
	DEF_UINT8	Pitch_Deviation;						/*主惯导-俯仰角标准差*/
	
	DEF_UINT8 	Roll_Deviation;						/*主惯导-滚转角标准差*/
	DEF_UINT8	Yaw_Deviation;						/*主惯导-航向角标准差*/
	DEF_UINT8	East_V_Deviation;					/*主惯导-东向速度标准差*/	
	DEF_UINT8	North_V_Deviation;					/*主惯导-北向速度标准差*/	
	
	DEF_UINT8	Up_V_Deviation;						/*主惯导-垂直速度标准差*/
	DEF_UINT8	INSTemp;							/*主惯导-惯导温度*/
	DEF_UINT8	INSTempMeasreState;				/*主惯导-温度测量状态*/
	DEF_UINT8 	Reserved_24[4];						/*备用字节24,25,26,27*/
	DEF_UINT8 	GNSS_Lat_Deviation;					/*GNSS-纬度标准差*/
	
	DEF_UINT8 	GNSS_Lon_Deviation;				/*GNSS-经度标准差*/
	DEF_UINT8 	GNSS_InsAlt_Deviation;				/*GNSS-高度标准差*/	
	DEF_UINT8	GNSS_CompuTempra; 				/*GNSS-内部温度*/
	DEF_UINT8	GNSS_TempMeaState;				/*GNSS-温度测量状态*/
	DEF_INT8	AirscrewCrustTemp[4];				/*电机本体温度(左前电机,左后电机,右前电机,右后电机)*/
	
	DEF_INT8	VecAirscrewCrustTemp;				/*航向电机本体温度*/
	DEF_INT8	AirscrewRadiatorTemp[4][2];			/*电机驱动器(左前电机,左后电机,右前电机,右后电机) mos温度(1~2)*/ 
	DEF_INT8	VecAirscrewRadiatorTemp;			/*航向电机驱动器温度*/
	DEF_UINT8 	Reserved_47[2];						/*备用字节47~48*/
	
	DEF_INT16	VectorRadiatorTemp;					/*矢量装置电机驱动器温度*/ 
	DEF_UINT8 	Reserved_51[12];					/*备用字节51~62*/
	DEF_INT8	BalnetColBoardTemp[4];				/*囊体采集板卡温度(中部囊采主、备和前部囊采主、备)*/
	DEF_INT16	Ballonet_Temp[4][6];					/*囊体采集温度(1)~(6)(其中中部囊采主、备、前部囊采主的温度1,2,5不显示，前部囊采备的温度1,2不显示)*/
	DEF_UINT8 	Reserved_115;						/*备用字节115*/
	DEF_UINT8	CheckSum;							/*校验和*/
}_DEFSTRU_JC01YC;

/*遥测副帧7(监测数据02副帧0x5B)遥测数据*/
typedef struct
{
	DEF_UINT8 	Count;								/*循环计数*/
	DEF_UINT8	FrameFlag;							/*帧标志*/
	DEF_INT8	CompuTempra; 						/*采集计算机内部温度*/
	DEF_UINT8	InsInnerTemp;						/*备惯导-内部温度*/
	
	DEF_UINT8	Lat_Deviation;						/*备惯导-纬度标准差*/
	DEF_UINT8	Lon_Deviation;						/*备惯导-经度标准差*/
	DEF_UINT8	InsAlt_Deviation;					/*备惯导-高度标准差*/	
	DEF_UINT8	Pitch_Deviation;						/*备惯导-俯仰角标准差*/
	
	DEF_UINT8	Roll_Deviation; 						/*备惯导-滚转角标准差*/
	DEF_UINT8	Yaw_Deviation;						/*备惯导-航向角标准差*/
	DEF_UINT8	EastV_Deviation;						/*备惯导-东向速度标准差*/	
	DEF_UINT8	North_V_Deviation;					/*备惯导-北向速度标准差*/	
	
	DEF_UINT8	Up_V_Deviation; 					/*备惯导-垂直速度标准差*/
	DEF_UINT8 	Reserved_14;						/*备用字节14*/
	DEF_INT16	MovCameraRadiatorTemp[2];			/*云台装置电机驱动器温度1、2 */
	DEF_INT8	DISwitchColBoardTemp[2];			/*数字图像切换-板卡温度1、2*/
	
	DEF_INT8	AISwitchColBoardTemp[2];			/*模拟图像切换-板卡温度1、2*/
	DEF_UINT8 	ImgTxWorkState;					/*图传电台-运行状态*/
	DEF_INT8 	ImgTxTempra;						/*图传电台-芯片温度*/
	
	DEF_UINT16 	ImgTxLost;							/*图传电台-衰减*/
	DEF_UINT8 	ImgTxOutPower;						/*图传电台-输出功率*/
	DEF_UINT8 	ImgTxInputForm;					/*图传电台-视频输入格式*/
	
	DEF_UINT8 	ImgTxSource;						/*图传电台-视频源*/
	DEF_UINT8 	ImgTxInLockState;					/*图传电台-输入锁定状态*/
	DEF_UINT8 	Reserved_31;						/*备用字节31*/
	DEF_UINT8	CheckSum;							/*校验和*/
}_DEFSTRU_JC02YC;




/*-------------------------------遥控数据结构体----------------------------------*/

 

/*1-飞行模式*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	FlightMode;								/*飞行模式*/
	DEF_UINT8 	Reserved_6[2];							/*备用字节6~7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK01_FlightMode;	


/*2-自重调节装置锁定*/
typedef struct
{
	
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	WeightAdjust_LockCtrl;					/*自重调节装置锁定，bit0-自重调节1连续控制；bit1-自重调节1开关控制；状态：0-锁定，1-解锁。*/
	DEF_UINT8 	Reserved_6[2];							/*备用字节6~7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK02_WeightAdjust_Lock;	



/*3-自重调节装置控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	WeightAdjustCtrl;						/*自重调节装置控制，bit0-自重调节1连续控制；bit1-自重调节1开关控制；0-关闭，1-打开。*/
	DEF_UINT8	WeightAdjustDevCtrl_Time;				/*自重调节装置连续控制时间*/
	DEF_UINT8 	Reserved_7;								/*备用字节7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK03_WeightAdjustCtrl;	



/*4-惯导控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	INSCalibrationCtrl;						/*惯导重新对准控制 0x00-不控；0x11-主惯导对准；0x22-备惯导对准。*/
	DEF_UINT8	FK_UseINS;								/*飞控使用惯导 0x00-不控；0x11-主惯导；0x22-备惯导。*/		
	DEF_UINT8 	Reserved_7;								/*备用字节7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK04_NavCtrl;



/*5-飞控计算机心跳*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	Heart_Source;							/*心跳来源标志,0x01-L频段测控；  0x02-U频段测控；  0x03-U频段移动测控。*/
	DEF_UINT8 	Reserved_6[2];							/*备用字节6~7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK05_FK_ComputHeart;	



/*6-飞控计算机重启*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	ComputerReset_Effect;					/*重启指令-有效位 bit0-飞控计算机; bit1-采集计算机  表示：0-无效；1-有效。*/
	DEF_UINT8	ComputerReset;							/*0x00-取消重启准备；0x11-重启准备1； 0x55-重启准备2； 0x66-进行重启*/
	DEF_UINT8 	Reserved_7;								/*备用字节7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK06_FK_ComputerReset;	


/*7-计算机设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	TempraCtrlSelect;						/*温控有效位bit0-飞控计算机; bit1-采集计算机*/
	DEF_UINT8	TempraCtrl;								/*温度控制 温控指令0-自动温控，1-加温，2-不加温*/
	DEF_UINT8	RecordCtrlSelect;						/*记录控制有效位bit0-飞控计算机; bit1-采集计算机*/
	DEF_UINT8	RecordCtrl;								/*记录控制,0x00不记录,0x01记录*/
	
	DEF_UINT8	MemClearCtrlSelect;						/*存储清除控制有效位bit0-飞控计算机; bit1-采集计算机*/
	DEF_UINT8	MemClearCtrl;							/*存储清除控制0x01-存储清除；0x02-系统时间归零；0x03-存储清除同时系统时间归零*/
	DEF_UINT8	LoadYCTranSwitch_Effect;				/*载荷传输开关 控制有效位:   0x00-无效；0xAA-有效。*/
	DEF_UINT8	LoadYCTranSwitch;						/*载荷传输开关 ，bit0-左动力测量； bit1-右动力测量； bit2-气象载荷；bit3-通信载荷。表示：0-不传输；1-传输*/

	DEF_UINT8	InChannelCtrl_Effect;					/*内部通信通道设置-有效位			0x00-无效；0xAA-有效。*/
	DEF_UINT8	InChannelCtrl;							/*0-主通道；1-备通道。*/
	DEF_UINT8 	PowerReceiPoint_Effect;					
	DEF_UINT8 	PowerReceiPoint;						/*能源设备接收终端*/	
	
	DEF_UINT8 	Reserved_17[3];							/*备用字节17~19*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK07_FK_ComuterCtrl;	






/*8-自主降落参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	Effe_SafeCtrlMinite;						/*安控时间设置-有效位  0x00-无效；0xAA-有效。*/
	DEF_UINT8 	SafeCtrlMinite;							/*安控时间,    单位min*/
	DEF_UINT8	Effe_CriticalBaricAlt;						/*安控高度设置-有效位  0x00-无效；0xAA-有效。*/
	DEF_UINT8 	Reserved_8;								/*备用字节8*/

	DEF_INT16	CriticalBaricAlt;							/*安控高度   单位：m*/
	DEF_UINT8 	Reserved_11;							/*备用字节11*/	
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK08_LandingParSet;	


/*9-推进电机启停控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	AirscrewCtrlSelect;						/*电机启停控制有效位,bit0~ bit3代表左前电机~右后电机；bit4-航向电机。*/
	DEF_UINT8	AirscrewCtrl[5];							/*电机启停控制,0x00停止,0x01启动(左前电机,左后电机,右前电机,右后电机,航向电机)*/
	DEF_UINT8 	Reserved_11;							/*备用字节11*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK09_AirscrewCtrl;	


/*10-推进电机转速控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	AirscrewNCtrlSelect;						/*推进电机转速控制有效位,bit0~ bit3代表左前电机~右后电机；bit4-航向电机。*/
	DEF_UINT8 	Reserved_6;								/*备用字节6*/
	DEF_UINT16	AirscrewNCtrl[5];							/*推进电机转速控制(左前电机,左后电机,右前电机,右后电机,航向电机)*/

	DEF_UINT8	PropellerN_LimitSelect;					/*自主控制推进转速限幅有效位0x00无效，0xAA有效*/
	DEF_UINT8	FrontPropelN_LimitSelect;				/*航向电机转速限幅有效位0x00无效，0xAA有效*/
	DEF_UINT16	PropellerN_Limit;						/*推进电机转速限幅*/
	DEF_UINT16	FrontPropelN_Limit;						/*航向电机转速限幅*/ 
	DEF_UINT8 	Reserved_23;							/*备用字节23*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK0A_PropellerNCtrl;	





/*11-囊体阀门控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	Ballonet_ValveCtrlSelect;					/*囊体阀门控制-有效位bit0~bit3分别对应中主、中备、前主、前备。表示：0-无效；1-有效。*/
	DEF_UINT8	Ballonet_ValveCtrl[4];					/*囊体阀门控制*/
	DEF_UINT8	Ballonet_ValveCtrlTime[4];				/*囊体阀门控制时间*/
	DEF_UINT8 	Reserved_14[2];							/*备用字节14~15*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK0B_ValveCtrl;	



/*12-囊体爆破控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/
	
	DEF_UINT8	BallonetExploderMode;					/*囊体爆破模式0x01-单个爆破     ; 0x02-一致爆破   */
	DEF_UINT8	BallonetExploderCtrl[4];					/*囊体爆破控制0x01~0x04对应起爆爆破索1~4。*/
	DEF_UINT8	BallSameTimeExpCtrl;					/*囊体一致爆破控制bit0~bit3分别对应中主、中备、前主、前备。表示：0-无效；1-一致爆破。*/
	DEF_UINT8 	Reserved_11;							/*备用字节11*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK0C_BallonetExploderControl;	



/*13-阀门爆破控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	ValveExplodeCtrl;						/*阀门爆破控制bit0~bit3分别对应中主、中备、前主、前备。表示：0-无效； 1-起爆。*/
	DEF_UINT8 	Reserved_6[2];							/*备用字节6~7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK0D_ValveExplodeCtrl;	



/*14-囊体采集预点火*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	BalnetColPreFire;						/*囊体采集预点火bit0~bit3分别对应中主、中备、前主、前备。表示：0-预点火关，  1-预点火开。*/
	DEF_UINT8 	Reserved_6[2];							/*备用字节6~7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK0E_BalnetColPreFire;	



/*15-囊体采集工作设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	BalnetColWorkCtrlEffect;					/*囊体采集工作控制-有效位bit0~bit3分别对应中主、中备、前主、前备。表示：0-无效；1-有效。*/
	DEF_UINT8	BalnetColWorkCtrl[4];					/*囊体采集工作控制0x00-工作；0x01-休眠*/
	DEF_UINT8	BDYCTransCtrlEffect;						/*北斗遥测下发控制-有效位bit0~bit3分别对应中主、中备、前主、前备。表示：0-无效；1-有效。*/
	DEF_UINT8	BDYCTransCtrl[4];						/*北斗遥测下发控制0x00-停止下发；0x01-启动下发*/
	DEF_UINT8 	Reserved_15;							/*备用字节15*/
	DEF_UINT8	CheckSum;								/*校验和*/
	
}_DEFSTRU_YK0F_BalnetColCtrl;	



/*16-能源供电控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	PowerCtrlSelect;							/*控制选择,0x00-飞控计算机， 0x01-采集计算机。*/
	DEF_UINT8 	Reserved_6;								/*备用字节6*/
	DEF_UINT8	DCDCCtrlEffect;							/*DC/DC控制有效位，0x00-无效，0xAA-有效。*/
	DEF_UINT8 	DCDCCtrlByte;							/*DC-DC控制字节	bit0~bit1:高压 DC控制; 	bit2~bit3: 高压 DC工作模式;       bit4~bit5:28V_DC控制;	bit6~bit7:29V_DC控制;00-关，01-开*/

	DEF_UINT16	DCDCSetCur;								/*高压DC给定目标电流*/
	DEF_UINT16	DCDCSetVol;								/*高压 DC给定目标电压*/

	DEF_UINT8	DCDCTraCtEffect;						/*DC-DC定时回传-控制有效位    表示：0-无效；1-有效。*/
	DEF_UINT8	DCDCTraCtrl;							/*DC-DC定时回传控制   表示：0-无效；1-有效。*/
	DEF_UINT8	BatteryInputCtEffect;						/*储能电池充电口控制-有效位-0xAA*/
	DEF_UINT8	BatteryInputCtrl;							/*储能电池充电口控制 表示：0-关闭；0x01-打开。注：两个储能电池充电口一起控，应急锂电池不控。*/

	DEF_UINT8	BatteryOutputCtEffect;					/*储能电池放电口控制-有效位-0xAA*/
	DEF_UINT8	BatteryOutputCtrl;						/*储能电池放电口控制   注：两个储能电池放电口一起控，应急锂电池不控。*/
	DEF_UINT8 	Reserved_19;							/*备用字节19*/
	DEF_UINT8	CheckSum;								/*校验和*/	
}_DEFSTRU_YK10_EnergySysCtrl;	






/*17-飞行控制数据传输*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	FKData[96];								/*飞控数据5~99*/
}_DEFSTRU_YK11_FlightCtrlDataTrans;	


/*18-矢量装置角度控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_INT16	VectorAngelCtrl;							/*矢量装置角度*/
	DEF_UINT8 	Reserved_7;								/*备用字节7*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK12_VectorAngelCtrl;	

/*19-矢量装置参数设置*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	Effect_VertorOnOff;						/*矢量装置启停控制-有效位，0x00-无效；0xAA-有效。*/
	DEF_UINT8	VertorOnOff;								/*矢量装置启停控制，0x01-停止;   0x02-启动;   0x03-回零。*/
	DEF_UINT8	Effect_VectorErroClear;					/*矢量装置故障清除-有效位，0x00-无效；0xAA-有效。*/
	DEF_UINT8	VectorErroClear;							/*矢量装置故障清除, 0x00-伺服;   0x01-清除障碍。*/
	
	DEF_UINT8 	Reserved_9;								/*备用字节9*/
	DEF_UINT8	Effect_VectorNCtrl;						/*矢量装置转速控制-有效位，0x00-无效；0xAA-有效。*/
	DEF_UINT16	VectorNCtrl;								/*矢量装置转速控制*/

	DEF_UINT8 	Reserved_13[3];							/*备用字节13~15*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK13_VectorParamCtrl;	

/*20-云台装置角度控制*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_INT16	AngelCtrl[2];								/*云台装置角度1~2*/
	DEF_UINT8	Effect_AngelCtrl;							/*云台装置角度-有效位,    bit0-云台机构1；bit1-云台机构2。    表示：0-无效，1-有效。*/
	DEF_UINT8 	Reserved_10[2];							/*备用字节10~11*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK14_MovCameraAngel;	

/*21-云台装置参数设置	*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8	Effect_OnOff;							/*云台装置启停控制-有效位， bit0-云台机构1；bit1-云台机构2。    表示：0-无效，1-有效。*/
	DEF_UINT8	OnOff[2];								/*云台装置启停控制1~2，0x01-停止;   0x02-启动;   0x03-回零。*/
	DEF_UINT8	Effect_ErroClear;						/*云台装置故障清除-有效位， bit0-云台机构1；bit1-云台机构2。    表示：0-无效，1-有效。*/
	DEF_UINT8	ErroClear[2];							/*云台装置故障清除1~2, 0x00-无效;   0x01-清除障碍。*/
	DEF_UINT8 	Reserved_11;							/*备用字节11*/
	DEF_UINT8	Effect_NCtrl;								/*云台装置转速控制-有效位， bit0-云台机构1；bit1-云台机构2。    表示：0-无效，1-有效。*/

	DEF_UINT16	NCtrl[2];									/*云台装置转速控制1~2*/

	DEF_UINT8 	Reserved_17[3];							/*备用字节17~19*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK15_MovCaParamCtrl;	


/*22-对地成像装置控制		*/
typedef struct
{
	DEF_UINT8 	Count;									/*循环计数*/
	DEF_UINT8 	FrameFlag;								/*帧标志*/
	DEF_UINT8	CommandCode;							/*指令代码*/
	DEF_UINT8	ExecuteState;							/*执行状态*/

	DEF_UINT8 	Image_Comand1;						/*命令字1*/
	DEF_UINT8 	Image_Comand2;						/*命令字2*/
	DEF_UINT16 	Image_Height;							/*高度*/
	
	DEF_UINT8 	ControlStep;								/*控制步长*/
	DEF_UINT8 	Reserved_10[2];							/*备用字节10~11*/
	DEF_UINT8	CheckSum;								/*校验和*/
}_DEFSTRU_YK16_ImageSysCtrl;	





/*23-模拟图像切换		*/
typedef struct
{
	DEF_UINT8 	Count;									/*	循环计数	*/
	DEF_UINT8 	FrameFlag;								/*	帧标志		*/
	DEF_UINT8	CommandCode;							/*	指令代码	*/
	DEF_UINT8	ExecuteState;							/*	执行状态	*/

	DEF_UINT8	SwitchChannel;							/*	切换通道	*/
	DEF_UINT8 	Reserved_6[2];							/*	备用字节6~7	*/
	DEF_UINT8	CheckSum;								/*	校验和		*/
}_DEFSTRU_YK17_AnalogImageSwitchCtrl;

/*24-数字图像切换		*/
typedef struct
{
	DEF_UINT8 	Count;									/*	循环计数	*/
	DEF_UINT8 	FrameFlag;								/*	帧标志		*/
	DEF_UINT8	CommandCode;							/*	指令代码	*/
	DEF_UINT8	ExecuteState;							/*	执行状态	*/
	
	DEF_UINT8	SwitchChannel;							/*	切换通道	*/
	DEF_UINT8 	Reserved_6[2];							/*	备用字节6~7	*/
	DEF_UINT8	CheckSum;								/*	校验和		*/
}_DEFSTRU_YK18_DigitalImageSwitchCtrl;











/*遥测数据集合包*/
typedef struct
{
_DEFSTRU_HD01YC	HD01;
_DEFSTRU_HD02YC	HD02;
_DEFSTRU_TJYC		TJ;
_DEFSTRU_NYYC		NY;
_DEFSTRU_NTYC		NT;
}_DEFSTRU_YC_All;


/*遥测数据集合包*/
typedef struct
{
_DEFSTRU_JC01YC		JC01;
_DEFSTRU_JC02YC		JC02;
}_DEFSTRU_YC_Low;

/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/

 extern const DEF_UINT8 g_YC_Date_Length[YC_DATA_COUNT];				//遥测数据结构体长度
 extern const DEF_UINT8 g_YC_FRAMEFLAG[YC_DATA_COUNT];				//遥测数据帧标志
 extern _DEFSTRU_YC_All g_YC_Package;								//遥测数据集合包

 extern const DEF_UINT8 g_YCLow_Date_Length[YC_DATA_COUNTLow];				//遥测数据结构体长度
 extern const DEF_UINT8 g_YCLow_FRAMEFLAG[YC_DATA_COUNTLow];				//遥测数据帧标志
 extern _DEFSTRU_YC_Low g_YCLowPack;								//遥测数据集合包




//遥控指令
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
 *								函数声明
void Modelname();
 *------------------------------------------------------------------------------*/
 


#endif 







