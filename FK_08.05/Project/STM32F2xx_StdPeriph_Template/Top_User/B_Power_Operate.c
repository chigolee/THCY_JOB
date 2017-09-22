/*========================================================================================*
 * FILE:                     	B_Power_Operate.c                   
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

/*------------------------------------------------------------------------------*
 *								头文件
 #include "Modelname.h"
 *------------------------------------------------------------------------------*/
 #include "B_Power_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/
 
CanRxMsg	Power_RecieveTrans;	//能源设备接收数据暂存
/*----------能源设备数据接收------------*/
void Task_CAN_Power_Recieve()
{
}








/*---锂电池数据处理转存---*/
//锂电池编号:	0-大锂电池1；    1-大锂电池2；   2-应急锂电池。
void LionBetteryOperate(DEF_UINT8 LiNO)
{
if(LiNO<=2)
	{
	switch(Power_RecieveTrans.StdId&0x000F)
		{
		//数据帧A
		case 0x06:
				{	g_YC_Package.NY.BatteryVol[LiNO]=(DEF_INT32)((0x010000*Power_RecieveTrans.Data[2]+0x0100*Power_RecieveTrans.Data[1]+Power_RecieveTrans.Data[0])/10.0);
					bcopy(&(Power_RecieveTrans.Data[3]),&(g_YC_Package.NY.BatteryCur[LiNO]),2);
					g_YC_Package.NY.BatterySOC[LiNO]=Power_RecieveTrans.Data[5];
					g_YC_Package.NY.BatteryHeat[LiNO]=Power_RecieveTrans.Data[6];
					if(LiNO<=1){g_YC_Package.NY.BatteryInOut[LiNO]=Power_RecieveTrans.Data[7];}
					break;}

		//数据帧B
		case 0x07:
				{	
					bcopy(&(Power_RecieveTrans.Data[0]),&(g_YC_Package.NY.BatteryCellVol[0][LiNO]),2);
					bcopy(&(Power_RecieveTrans.Data[2]),&(g_YC_Package.NY.BatteryCellVol[1][LiNO]),2);					
					g_YC_Package.NY.BatteryCellVol_ID[0][LiNO]=Power_RecieveTrans.Data[6];
					g_YC_Package.NY.BatteryCellVol_ID[1][LiNO]=Power_RecieveTrans.Data[7];
					break;}


		//数据帧C
		case 0x08:
				{	
					g_YC_Package.NY.AverageBatteryTemperature[LiNO]=(DEF_INT32)(((Power_RecieveTrans.Data[1])*256+Power_RecieveTrans.Data[0]-400.0)/10.0);
					g_YC_Package.NY.MaxBatteryTemperature[LiNO]=(DEF_INT32)(((Power_RecieveTrans.Data[3])*256+Power_RecieveTrans.Data[2]-400.0)/10.0);
					g_YC_Package.NY.MinBatteryTemperature[LiNO]=(DEF_INT32)(((Power_RecieveTrans.Data[5])*256+Power_RecieveTrans.Data[4]-400.0)/10.0);
					g_YC_Package.NY.Battery_Temp_ID[0][LiNO]=Power_RecieveTrans.Data[6];
					g_YC_Package.NY.Battery_Temp_ID[1][LiNO]=Power_RecieveTrans.Data[7];
					break;}

		//故障信息
		case 0x09:
				{	
					g_YC_Package.NY.BatteryEorro[LiNO]=Power_RecieveTrans.Data[1];
					break;}

	default:break;
		}
	}

}










