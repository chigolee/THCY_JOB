/*========================================================================================*
 * FILE:                     	B_Power_Operate.h                   
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
#ifndef M_B_Power_Operate_H
#define M_B_Power_Operate_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
#include "B_GlobalDefine.h"

 
 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/

//当前使用大锂电池--对应编号
// 4 选2 ，大锂1-0x10；大锂2-0x20；大锂3-0x30；大锂4-0x40。
 #define	CANOperBigBet_1	0x10
 #define	CANOperBigBet_2	0x20




/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/
 
/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

 
/*------------------------------------------------------------------------------*
 *								函数声明
void Modelname();
 *------------------------------------------------------------------------------*/
 
/*---能源设备数据接收---*/
void Task_CAN_Power_Recieve();	


/*---锂电池数据处理转存---*/
//锂电池编号:	0-大锂电池1；    1-大锂电池2；   2-应急锂电池。
void LionBetteryOperate(DEF_UINT8 LiNO);



















#endif 



