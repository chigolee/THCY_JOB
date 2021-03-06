/*========================================================================================*
 * FILE:                     	B_Airscrew_Operate.h                   
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
#ifndef M_B_Airscrew_Operate_H
#define M_B_Airscrew_Operate_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_GlobalDefine.h"

 
 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/

 typedef struct  
{
DEF_UINT8	Head1;
DEF_UINT8	Head2;
DEF_UINT8	Flag;
DEF_UINT8 	AirscrewState;						/*螺旋桨电机状态*/	

DEF_INT16	AirscrewCrustTemp;					/*螺旋桨电机本体温度, 航向电机为备用*/
DEF_INT16	AirscrewRadiatorTemp[2];			/*螺旋桨驱动器mos温度，航向电机为驱动器/电机温度*/ 
DEF_UINT8	AirscrewCurrent;						/*螺旋桨电机相电流*/
DEF_UINT8 	AirscrewMainwireVol;				/*螺旋桨电机母线电压*/

DEF_UINT8	AirscrewRadiatorDutyRatio;			/*螺旋桨驱动器占空比*/ 
DEF_UINT8 	AirscrewActualN_Low;				/*螺旋桨电机转速测量值,低字节*/
DEF_UINT8 	AirscrewActualN_High;				/*螺旋桨电机转速测量值,高字节*/
DEF_UINT8 	Checksum;							/*校验和1~15*/	
}_DEFSTRU_AirscrewRecivePacage;


 typedef struct  
{
DEF_UINT8	Head1;
DEF_UINT8	Head2;
DEF_UINT8	Flag;
DEF_UINT8	CtrlByte1;

DEF_UINT8	CtrlByte2;
DEF_UINT8 	Checksum;	
}_DEFSTRU_AirscrewCtrlSend;

/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

 
/*------------------------------------------------------------------------------*
 *								函数声明
void Modelname();
 *------------------------------------------------------------------------------*/
 
//推进电机数据接收,输入为(电机号)    1、2、3、4。
void Task_Airscrew_Recieve(DEF_UINT8 Numb);

void Airscrew_CtrlSend(DEF_UINT8 Numb,  DEF_UINT8 Comand, DEF_UINT16 Speed);







#endif 





