/*========================================================================================*
 * FILE:                     	B_Ballonet_Operate.h                   
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
#ifndef M_B_Ballonet_Operate_H
#define M_B_Ballonet_Operate_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_GlobalDefine.h"

 
 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/
#define	MaxTransAscllCount	14
#define	MaxTransComaCount	14

/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/

 typedef struct  
{
	DEF_UINT8			FrameHead1;		//----(字节1)
	DEF_UINT8			FrameHead2;
	DEF_UINT8 			BalloonNO;			//囊体号				
	DEF_UINT8 			CommandReturn;	//指令回传		

	DEF_UINT16			BoardTem;			//板卡温度1 ----(字节5)
	DEF_UINT16			Pressure;			//压差

	DEF_UINT16			Vol28V;         		//28V电压----(字节9)
	DEF_UINT16			Vol16V;         		//16V电压

	DEF_UINT16			ValveCurrent;		//阀门电流----(字节13)
	DEF_UINT16			W100Temp;			//温度W100

	DEF_UINT16			W50Temp;			//温度W50----(字节17)
	DEF_UINT16			Temp[6];			//温度6~1
	DEF_UINT8 			Parameter_1;		//参数1
	DEF_UINT8 			State_2;				//状态2

	DEF_UINT16			angle;				//旋变	----(字节33)
	DEF_UINT8			ValveState;			//阀门状态
	DEF_UINT8			FirePointState;		//火头1-8状态	

	DEF_UINT8			FireCtlState;			//点火1-8控制状态----(字节37)
	DEF_UINT8 			State_1;				//状态1
	DEF_UINT16 			TimerFire;			//点火计时器计数

	DEF_UINT8 			Parameter_2;		//参数2----(字节41)
	DEF_UINT8			XorChecksum;		//校验异或和
	DEF_UINT8			End1;				//帧尾1
	DEF_UINT8			End2;				//帧尾2	
}_DEFSTRU_BallColRecivePacage;	//注意高字节在前，低字节在后




//囊体采集器发送数据结构体
 typedef struct  
{
	DEF_UINT8	head[2];			//z帧头
	DEF_UINT8	StaticByte;			//固定填0x11
	DEF_UINT8	Command[3];		//控制指令，相同有效
	DEF_UINT8	ValveCtrlTime[2];	//阀门控制时间，相同有效
	
	DEF_UINT8	CommandVert[3];	//取反校验，相同有效
	DEF_UINT8	reserved[2];			//备用
	DEF_UINT8	Checksum;			//校验和，3~13字节
	DEF_UINT8	end[2];			//帧尾	
}_DEFSTRU_BallCoCtrlSend;			




/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

 
/*------------------------------------------------------------------------------*
 *								函数声明
void Modelname();
 *------------------------------------------------------------------------------*/
 

/*----------囊体采集数据接收，输入为采集器号1~4  -----------*/
void Task_Ballonet_Operate(DEF_UINT8 Collector_NO);

/*----------囊体采集遥控指令发送( 1-采集器号;     2-指令;     3-阀门时间0.1s  . )  -----------*/
void Ballonet_CtrlSend(DEF_UINT8 Collector_NO,  DEF_UINT8 Comand, DEF_UINT8 Time);


 /*异或 校验和----输出为单字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT8 XorSum1(DEF_UINT8 *start , DEF_UINT8 count);

 

DEF_FLOAT32	TransAscllToFloat(DEF_UINT8* Ascll, DEF_UINT8*TansState);


#endif 























