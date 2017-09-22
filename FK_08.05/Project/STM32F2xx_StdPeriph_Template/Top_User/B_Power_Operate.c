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
//收取数据
if(Can1RxFBufPo!=Can1RxFBufPi)
	{	
	bcopy(&(Can1RxFBuf[Can1RxFBufPo]),&(Power_RecieveTrans),sizeof(Power_RecieveTrans));
	Can1RxFBufPo=(Can1RxFBufPo+1)%Can1_TxF_BufLen;

//----DC-DC 数据
	if(Power_RecieveTrans.StdId<=0xFF)
		{
		switch(Power_RecieveTrans.StdId)
			{
		//DC-DC电压、电流、温度、状态
			case 0x89:
			case 0x8A:
			case 0x8B:
					{	DelaySecond_Healthy[1][4+Power_RecieveTrans.StdId-0x89]=0;	//超时计数置0 
						bcopy(&(Power_RecieveTrans.Data[0]),&(g_YC_Package.NY.DCDCOutputVol[Power_RecieveTrans.StdId-0x89]),2);
						bcopy(&(Power_RecieveTrans.Data[2]),&(g_YC_Package.NY.DCDCOutputCur[Power_RecieveTrans.StdId-0x89]),2);
						g_YC_Package.NY.DCDC_Temprature[Power_RecieveTrans.StdId-0x89]=Power_RecieveTrans.Data[4];
						g_YC_Package.NY.DCDC_State[Power_RecieveTrans.StdId-0x89]=Power_RecieveTrans.Data[6];
						break;}

		//太阳能阵列输入电压、电流
			case 0x8C: 
					{	DelaySecond_Healthy[1][4]=0;	//超时计数置0 
						bcopy(&(Power_RecieveTrans.Data[0]),&(g_YC_Package.NY.Solar_Vol),2);
						bcopy(&(Power_RecieveTrans.Data[2]),&(g_YC_Package.NY.Solar_Cur),2);
						g_YC_Package.NY.HighDCWorkMode=Power_RecieveTrans.Data[4];
						break;}
		default:break;			
			}
		}

//-----锂电池数据
	else if(((Power_RecieveTrans.StdId&0x0F00)==0x300)||((Power_RecieveTrans.StdId&0x0F00)==0x200))
		{
		switch(Power_RecieveTrans.StdId&0x00F0)
			{
			case CANOperBigBet_1:	{DelaySecond_Healthy[2][0]=0;LionBetteryOperate(0);break;}
			case CANOperBigBet_2:	{DelaySecond_Healthy[2][1]=0;LionBetteryOperate(1);break;}
			
			case 0x60:	
			case 0x70:	
			case 0x80:				{DelaySecond_Healthy[2][2]=0;LionBetteryOperate(2);break;}

		default:break;
			}
		}
	
	}

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










