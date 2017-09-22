/*========================================================================================*
 * FILE:                     	B_Power_Operate.c                   
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

/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
 #include "Modelname.h"
 *------------------------------------------------------------------------------*/
 #include "B_Power_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/
 
CanRxMsg	Power_RecieveTrans;	//��Դ�豸���������ݴ�
/*----------��Դ�豸���ݽ���------------*/
void Task_CAN_Power_Recieve()
{
//��ȡ����
if(Can1RxFBufPo!=Can1RxFBufPi)
	{	
	bcopy(&(Can1RxFBuf[Can1RxFBufPo]),&(Power_RecieveTrans),sizeof(Power_RecieveTrans));
	Can1RxFBufPo=(Can1RxFBufPo+1)%Can1_TxF_BufLen;

//----DC-DC ����
	if(Power_RecieveTrans.StdId<=0xFF)
		{
		switch(Power_RecieveTrans.StdId)
			{
		//DC-DC��ѹ���������¶ȡ�״̬
			case 0x89:
			case 0x8A:
			case 0x8B:
					{	DelaySecond_Healthy[1][4+Power_RecieveTrans.StdId-0x89]=0;	//��ʱ������0 
						bcopy(&(Power_RecieveTrans.Data[0]),&(g_YC_Package.NY.DCDCOutputVol[Power_RecieveTrans.StdId-0x89]),2);
						bcopy(&(Power_RecieveTrans.Data[2]),&(g_YC_Package.NY.DCDCOutputCur[Power_RecieveTrans.StdId-0x89]),2);
						g_YC_Package.NY.DCDC_Temprature[Power_RecieveTrans.StdId-0x89]=Power_RecieveTrans.Data[4];
						g_YC_Package.NY.DCDC_State[Power_RecieveTrans.StdId-0x89]=Power_RecieveTrans.Data[6];
						break;}

		//̫�������������ѹ������
			case 0x8C: 
					{	DelaySecond_Healthy[1][4]=0;	//��ʱ������0 
						bcopy(&(Power_RecieveTrans.Data[0]),&(g_YC_Package.NY.Solar_Vol),2);
						bcopy(&(Power_RecieveTrans.Data[2]),&(g_YC_Package.NY.Solar_Cur),2);
						g_YC_Package.NY.HighDCWorkMode=Power_RecieveTrans.Data[4];
						break;}
		default:break;			
			}
		}

//-----﮵������
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








/*---﮵�����ݴ���ת��---*/
//﮵�ر��:	0-��﮵��1��    1-��﮵��2��   2-Ӧ��﮵�ء�
void LionBetteryOperate(DEF_UINT8 LiNO)
{
if(LiNO<=2)
	{
	switch(Power_RecieveTrans.StdId&0x000F)
		{
		//����֡A
		case 0x06:
				{	g_YC_Package.NY.BatteryVol[LiNO]=(DEF_INT32)((0x010000*Power_RecieveTrans.Data[2]+0x0100*Power_RecieveTrans.Data[1]+Power_RecieveTrans.Data[0])/10.0);
					bcopy(&(Power_RecieveTrans.Data[3]),&(g_YC_Package.NY.BatteryCur[LiNO]),2);
					g_YC_Package.NY.BatterySOC[LiNO]=Power_RecieveTrans.Data[5];
					g_YC_Package.NY.BatteryHeat[LiNO]=Power_RecieveTrans.Data[6];
					if(LiNO<=1){g_YC_Package.NY.BatteryInOut[LiNO]=Power_RecieveTrans.Data[7];}
					break;}

		//����֡B
		case 0x07:
				{	
					bcopy(&(Power_RecieveTrans.Data[0]),&(g_YC_Package.NY.BatteryCellVol[0][LiNO]),2);
					bcopy(&(Power_RecieveTrans.Data[2]),&(g_YC_Package.NY.BatteryCellVol[1][LiNO]),2);					
					g_YC_Package.NY.BatteryCellVol_ID[0][LiNO]=Power_RecieveTrans.Data[6];
					g_YC_Package.NY.BatteryCellVol_ID[1][LiNO]=Power_RecieveTrans.Data[7];
					break;}


		//����֡C
		case 0x08:
				{	
					g_YC_Package.NY.AverageBatteryTemperature[LiNO]=(DEF_INT32)(((Power_RecieveTrans.Data[1])*256+Power_RecieveTrans.Data[0]-400.0)/10.0);
					g_YC_Package.NY.MaxBatteryTemperature[LiNO]=(DEF_INT32)(((Power_RecieveTrans.Data[3])*256+Power_RecieveTrans.Data[2]-400.0)/10.0);
					g_YC_Package.NY.MinBatteryTemperature[LiNO]=(DEF_INT32)(((Power_RecieveTrans.Data[5])*256+Power_RecieveTrans.Data[4]-400.0)/10.0);
					g_YC_Package.NY.Battery_Temp_ID[0][LiNO]=Power_RecieveTrans.Data[6];
					g_YC_Package.NY.Battery_Temp_ID[1][LiNO]=Power_RecieveTrans.Data[7];
					break;}

		//������Ϣ
		case 0x09:
				{	
					g_YC_Package.NY.BatteryEorro[LiNO]=Power_RecieveTrans.Data[1];
					break;}

	default:break;
		}
	}

}










