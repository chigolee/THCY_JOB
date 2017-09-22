/*========================================================================================*
 * FILE:                     	Modelname.c                   
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
 #include "B_YKYC_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
_DEFSTRU_YC_All All_YCFast_Package;				
 _DEFSTRU_YC_Low All_YCLowPack;			

 DEF_UINT8	YK_Msg_Trans[Max_YKBtCount+3];		//ң��ָ���ݴ�λ��,����ͷee ��cc �����ݸ���

 
/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/



_DEFSTRU_YC_All CJ_YC_Package;				
 _DEFSTRU_YC_Low CJ_YCLowPack;			

DEF_UINT8	CJ_Informa_Trans[Max_YKBtCount+3];		//ң��ָ���ݴ�λ��,����ͷee ��cc �����ݸ���
DEF_UINT8	CJ_RecByteCount=0;
DEF_UINT8	*CJ_DelayPoint=(DEF_UINT8*)&(DelaySecond_Healthy[0][3]);
/*------------�ɼ���������ݽ���---------*/
void	Task_CJComputer_Receive()
{
CJ_Informa_Trans[0]=0;
CJ_Informa_Trans[1]=0;

if(g_YC_Package.HD01.FKCJChannel==0x00)	
	{	/*--��ͨ��--*/
	if(U3RxFBufPo!=U3RxFBufPi)
		{	
		CJ_RecByteCount=U3RxFBuf[U3RxFBufPo][U3_RxF_Len];
		if(CJ_RecByteCount<=Max_YKBtCount)
			{
			bcopy(&(U3RxFBuf[U3RxFBufPo][0]),&(CJ_Informa_Trans[0]),CJ_RecByteCount);
			U3RxFBufPo=(U3RxFBufPo+1)%U3_RxF_BufLen;			
			CJ_DelayPoint=(DEF_UINT8*)&(DelaySecond_Healthy[0][3]);
			}
		}
	}

else
	{	/*--����ͨ��--*/
	if(UHRxFBufPo!=UHRxFBufPi)
		{	
		CJ_RecByteCount=UHRxFBuf[UHRxFBufPo][UH_RxF_Len];
		if(CJ_RecByteCount<=Max_YKBtCount)
			{
			bcopy(&(UHRxFBuf[UHRxFBufPo][0]),&(CJ_Informa_Trans[0]),CJ_RecByteCount);
			UHRxFBufPo=(UHRxFBufPo+1)%UH_RxF_BufLen;			
			CJ_DelayPoint=(DEF_UINT8*)&(DelaySecond_Healthy[0][4]);
			}
		}
	}


		if((CJ_Informa_Trans[0]==0xEE)
			&&(CJ_Informa_Trans[1]==0xCC)
			&&(AddSum1(&(CJ_Informa_Trans[3]),(CJ_RecByteCount-4))==CJ_Informa_Trans[CJ_RecByteCount-1]))
			{
			CJ_DelayPoint[0]=0;	//��ʱ��������

			switch(CJ_Informa_Trans[4])
				{
				//�ɼ�ң�����ݽ���
				case	FRAMEFLAG_YC_HD02:{bcopy(&(CJ_Informa_Trans[3]), (DEF_UINT8*)&(CJ_YC_Package.HD02.Count), sizeof(_DEFSTRU_HD02YC));break;}	
				case	FRAMEFLAG_YC_NY:{bcopy(&(CJ_Informa_Trans[3]), (DEF_UINT8*)&(CJ_YC_Package.NY.Count), sizeof(_DEFSTRU_NYYC));break;}					
				case	FRAMEFLAG_YC_JC02:{bcopy(&(CJ_Informa_Trans[3]), (DEF_UINT8*)&(CJ_YCLowPack.JC02.Count), sizeof(_DEFSTRU_JC02YC));break;}		

				//��������ͨ�����ݣ�ֱ�ӽ����´�
				default: {YKCX_Answer_State_Date(&(CJ_Informa_Trans[3]),(CJ_Informa_Trans[2]),(CJ_Informa_Trans[6]));break;}
				}
		
			}

}






/*------------ȫ��ң�����ݸ������� ------------*/
void All_YCPackgeRenew()
{
//------������Դ��֡������ֱ����֡����----
	//�ɿؼ����������ݸ���
	bcopy((DEF_UINT8*)&(g_YC_Package.HD01.Count), (DEF_UINT8*)&(All_YCFast_Package.HD01.Count), sizeof(_DEFSTRU_HD01YC));
	bcopy((DEF_UINT8*)&(g_YC_Package.TJ.Count), (DEF_UINT8*)&(All_YCFast_Package.TJ.Count), sizeof(_DEFSTRU_TJYC));
	bcopy((DEF_UINT8*)&(g_YC_Package.NY.Count), (DEF_UINT8*)&(All_YCFast_Package.NY.Count), sizeof(_DEFSTRU_NYYC));
	bcopy((DEF_UINT8*)&(g_YC_Package.NT.Count), (DEF_UINT8*)&(All_YCFast_Package.NT.Count), sizeof(_DEFSTRU_NTYC));
	bcopy((DEF_UINT8*)&(g_YCLowPack.JC01.Count), (DEF_UINT8*)&(All_YCLowPack.JC01.Count), sizeof(_DEFSTRU_JC01YC));

	//�ɼ������������ݸ���
	bcopy((DEF_UINT8*)&(CJ_YC_Package.HD02.Count), (DEF_UINT8*)&(All_YCFast_Package.HD02.Count), sizeof(_DEFSTRU_HD02YC));
	bcopy((DEF_UINT8*)&(CJ_YCLowPack.JC02.Count), (DEF_UINT8*)&(All_YCLowPack.JC02.Count), sizeof(_DEFSTRU_JC02YC));

	//���Բɼ����������Դ�豸���ݸ���
	// 1-��ѹDC
	if(TestByteBit((g_YC_Package.NY.PowerReceiPoint), 0)==0x01)
		{
		All_YCFast_Package.NY.DCDCOutputVol[0]=CJ_YC_Package.NY.DCDCOutputVol[0];
		All_YCFast_Package.NY.DCDCOutputCur[0]=CJ_YC_Package.NY.DCDCOutputCur[0];
		All_YCFast_Package.NY.DCDC_Temprature[0]=CJ_YC_Package.NY.DCDC_Temprature[0];
		All_YCFast_Package.NY.DCDC_State[0]=CJ_YC_Package.NY.DCDC_State[0];
		All_YCFast_Package.NY.Solar_Vol=CJ_YC_Package.NY.Solar_Vol;
		All_YCFast_Package.NY.Solar_Cur=CJ_YC_Package.NY.Solar_Cur;
		All_YCFast_Package.NY.HighDCWorkMode=CJ_YC_Package.NY.HighDCWorkMode;
		}

	// 2- 28V DC
	if(TestByteBit((g_YC_Package.NY.PowerReceiPoint), 1)==0x01)
		{
		All_YCFast_Package.NY.DCDCOutputVol[1]=CJ_YC_Package.NY.DCDCOutputVol[1];
		All_YCFast_Package.NY.DCDCOutputCur[1]=CJ_YC_Package.NY.DCDCOutputCur[1];
		All_YCFast_Package.NY.DCDC_Temprature[1]=CJ_YC_Package.NY.DCDC_Temprature[1];
		All_YCFast_Package.NY.DCDC_State[1]=CJ_YC_Package.NY.DCDC_State[1];
		}

	// 3- 29V DC
	if(TestByteBit((g_YC_Package.NY.PowerReceiPoint), 2)==0x01)
		{
		All_YCFast_Package.NY.DCDCOutputVol[2]=CJ_YC_Package.NY.DCDCOutputVol[2];
		All_YCFast_Package.NY.DCDCOutputCur[2]=CJ_YC_Package.NY.DCDCOutputCur[2];
		All_YCFast_Package.NY.DCDC_Temprature[2]=CJ_YC_Package.NY.DCDC_Temprature[2];
		All_YCFast_Package.NY.DCDC_State[2]=CJ_YC_Package.NY.DCDC_State[2];
		}

	// 4- ���ܵ��1
	if(TestByteBit((g_YC_Package.NY.PowerReceiPoint), 3)==0x01)
		{
		All_YCFast_Package.NY.BatteryVol[0]=CJ_YC_Package.NY.BatteryVol[0];
		All_YCFast_Package.NY.BatteryCur[0]=CJ_YC_Package.NY.BatteryCur[0];
		All_YCFast_Package.NY.BatterySOC[0]=CJ_YC_Package.NY.BatterySOC[0];
		All_YCFast_Package.NY.BatteryHeat[0]=CJ_YC_Package.NY.BatteryHeat[0];
		All_YCFast_Package.NY.BatteryInOut[0]=CJ_YC_Package.NY.BatteryInOut[0];	//Ӧ�������
		All_YCFast_Package.NY.BatteryCellVol[0][0]=CJ_YC_Package.NY.BatteryCellVol[0][0];
		All_YCFast_Package.NY.BatteryCellVol[1][0]=CJ_YC_Package.NY.BatteryCellVol[1][0];
		All_YCFast_Package.NY.BatteryCellVol_ID[0][0]=CJ_YC_Package.NY.BatteryCellVol_ID[0][0];
		All_YCFast_Package.NY.BatteryCellVol_ID[1][0]=CJ_YC_Package.NY.BatteryCellVol_ID[1][0];
		All_YCFast_Package.NY.AverageBatteryTemperature[0]=CJ_YC_Package.NY.AverageBatteryTemperature[0];
		All_YCFast_Package.NY.MaxBatteryTemperature[0]=CJ_YC_Package.NY.MaxBatteryTemperature[0];
		All_YCFast_Package.NY.MinBatteryTemperature[0]=CJ_YC_Package.NY.MinBatteryTemperature[0];
		All_YCFast_Package.NY.Battery_Temp_ID[0][0]=CJ_YC_Package.NY.Battery_Temp_ID[0][0];
		All_YCFast_Package.NY.Battery_Temp_ID[1][0]=CJ_YC_Package.NY.Battery_Temp_ID[1][0];
		All_YCFast_Package.NY.BatteryEorro[0]=CJ_YC_Package.NY.BatteryEorro[0];
		}

	// 5-���ܵ��2
	if(TestByteBit((g_YC_Package.NY.PowerReceiPoint), 4)==0x01)
		{
		All_YCFast_Package.NY.BatteryVol[1]=CJ_YC_Package.NY.BatteryVol[1];
		All_YCFast_Package.NY.BatteryCur[1]=CJ_YC_Package.NY.BatteryCur[1];
		All_YCFast_Package.NY.BatterySOC[1]=CJ_YC_Package.NY.BatterySOC[1];
		All_YCFast_Package.NY.BatteryHeat[1]=CJ_YC_Package.NY.BatteryHeat[1];
		All_YCFast_Package.NY.BatteryInOut[1]=CJ_YC_Package.NY.BatteryInOut[1];	//Ӧ�������
		All_YCFast_Package.NY.BatteryCellVol[0][1]=CJ_YC_Package.NY.BatteryCellVol[0][1];
		All_YCFast_Package.NY.BatteryCellVol[1][1]=CJ_YC_Package.NY.BatteryCellVol[1][1];
		All_YCFast_Package.NY.BatteryCellVol_ID[0][1]=CJ_YC_Package.NY.BatteryCellVol_ID[0][1];
		All_YCFast_Package.NY.BatteryCellVol_ID[1][1]=CJ_YC_Package.NY.BatteryCellVol_ID[1][1];
		All_YCFast_Package.NY.AverageBatteryTemperature[1]=CJ_YC_Package.NY.AverageBatteryTemperature[1];
		All_YCFast_Package.NY.MaxBatteryTemperature[1]=CJ_YC_Package.NY.MaxBatteryTemperature[1];
		All_YCFast_Package.NY.MinBatteryTemperature[1]=CJ_YC_Package.NY.MinBatteryTemperature[1];
		All_YCFast_Package.NY.Battery_Temp_ID[0][1]=CJ_YC_Package.NY.Battery_Temp_ID[0][1];
		All_YCFast_Package.NY.Battery_Temp_ID[1][1]=CJ_YC_Package.NY.Battery_Temp_ID[1][1];
		All_YCFast_Package.NY.BatteryEorro[1]=CJ_YC_Package.NY.BatteryEorro[1];
		}

	// 6-Ӧ��﮵��
	if(TestByteBit((g_YC_Package.NY.PowerReceiPoint), 5)==0x01)
		{
		All_YCFast_Package.NY.BatteryVol[2]=CJ_YC_Package.NY.BatteryVol[2];
		All_YCFast_Package.NY.BatteryCur[2]=CJ_YC_Package.NY.BatteryCur[2];
		All_YCFast_Package.NY.BatterySOC[2]=CJ_YC_Package.NY.BatterySOC[2];
		All_YCFast_Package.NY.BatteryHeat[2]=CJ_YC_Package.NY.BatteryHeat[2];

		All_YCFast_Package.NY.BatteryCellVol[0][2]=CJ_YC_Package.NY.BatteryCellVol[0][2];
		All_YCFast_Package.NY.BatteryCellVol[1][2]=CJ_YC_Package.NY.BatteryCellVol[1][2];
		All_YCFast_Package.NY.BatteryCellVol_ID[0][2]=CJ_YC_Package.NY.BatteryCellVol_ID[0][2];
		All_YCFast_Package.NY.BatteryCellVol_ID[1][2]=CJ_YC_Package.NY.BatteryCellVol_ID[1][2];
		All_YCFast_Package.NY.AverageBatteryTemperature[2]=CJ_YC_Package.NY.AverageBatteryTemperature[2];
		All_YCFast_Package.NY.MaxBatteryTemperature[2]=CJ_YC_Package.NY.MaxBatteryTemperature[2];
		All_YCFast_Package.NY.MinBatteryTemperature[2]=CJ_YC_Package.NY.MinBatteryTemperature[2];
		All_YCFast_Package.NY.Battery_Temp_ID[0][2]=CJ_YC_Package.NY.Battery_Temp_ID[0][2];
		All_YCFast_Package.NY.Battery_Temp_ID[1][2]=CJ_YC_Package.NY.Battery_Temp_ID[1][2];
		All_YCFast_Package.NY.BatteryEorro[2]=CJ_YC_Package.NY.BatteryEorro[2];
		}

}









DEF_UINT8	YC_YK_Answ_Select=1;	//ң��ң�ⷢ��ѡ��
DEF_UINT8	YK_Answe_Position_Put=0;	//ң�ػظ��洢λ��
DEF_UINT8	YK_Answe_Position_Get=0;	//ң�ػظ���ȡλ��
DEF_UINT8	YK_AnsweStore[YK_AnStoreCount][Max_YKBtCount];			//ң�������ݴ滷�ζ���
/*------------ң�����ݺ�ң�ػظ��������� ------------*/
void Task_YCYKBack_Send()
{
YC_YK_Answ_Select++;
YC_YK_Answ_Select=YC_YK_Answ_Select%2;

	if(YC_YK_Answ_Select==0)
		{
		Only_YC_Send();
		}		//����ң������


	if(YC_YK_Answ_Select==1)
		{
		YK_Answe_Position_Get=YK_Answe_Position_Get%YK_AnStoreCount;
		if(YK_Answe_Position_Get!=YK_Answe_Position_Put)
			{//����ң�ػظ�,YK_AnsweStore[YK_Answe_Position_Get][0]
		
			U1InTxBuf((U8*)&(YK_AnsweStore[YK_Answe_Position_Get][0]),(YK_AnsweStore[YK_Answe_Position_Get][2]+3));
			ReserveCK_Send((U8*)&(YK_AnsweStore[YK_Answe_Position_Get][0]),(YK_AnsweStore[YK_Answe_Position_Get][2]+3));

			//�洢
			Date_Sore_GPSTime((DEF_UINT8*)&(YK_AnsweStore[YK_Answe_Position_Get][0]), (YK_AnsweStore[YK_Answe_Position_Get][2]+3));

			YK_Answe_Position_Get=(YK_Answe_Position_Get+1)%YK_AnStoreCount;
			}
		else
		{
		Only_YC_Send();
		}		//����ң������
	}

}


DEF_UINT8	SignForFastSlow=0;	//����֡ѡ��
DEF_UINT8	*P_ForYCPackge;				//ң�����ݰ�ָ��
DEF_UINT8	i_ForYC_Ini=0;
DEF_UINT8	YC_Fram_Count=0;	//ң�����ݷ���ѭ������
DEF_UINT8	YCYK_Send_Trans[Max_YCBtCount+3];		//ң�����ݡ�ң�ػظ��ݴ�λ��,����ͷee��cc�����ݸ���

DEF_UINT16	YC_Date_StepBegain[YC_DATA_COUNT]={0};	//ң�����ݽڵ�λ��
DEF_UINT16	YC_Date_StepBegain_Low[YC_DATA_COUNTLow]={0};	//ң�����ݽڵ�λ��
DEF_UINT8	YC_Fram_Select=0;	//ң�����ݷ���ѡ��
DEF_UINT8	YC_Fram_Select_Low=0;	//ң�����ݷ���ѡ��

/*----------------ң������ѭ������-------------*/
void Only_YC_Send()
{
//����ң������
All_YCPackgeRenew();

//����֡ѡ��
SignForFastSlow=(SignForFastSlow+1)%YCFramFastSlow;

if(SignForFastSlow==0)
	{/*---------------------������֡-------------------*/
	
	//���ݽڵ㿪ʼλ�ü���
	YC_Date_StepBegain_Low[0]=0;
	for(i_ForYC_Ini=1;i_ForYC_Ini<YC_DATA_COUNTLow;i_ForYC_Ini++)
	{YC_Date_StepBegain_Low[i_ForYC_Ini]=YC_Date_StepBegain_Low[i_ForYC_Ini-1]+g_YCLow_Date_Length[i_ForYC_Ini-1];
	}
	P_ForYCPackge=(DEF_UINT8*)(&All_YCLowPack);
	//ң��֡ѡ��
	YC_Fram_Select_Low++;
	YC_Fram_Select_Low=YC_Fram_Select_Low%YC_DATA_COUNTLow;
	//֡��־��ѭ��������У���
	P_ForYCPackge[(YC_Date_StepBegain_Low[YC_Fram_Select_Low])]=YC_Fram_Count++;
	P_ForYCPackge[(YC_Date_StepBegain_Low[YC_Fram_Select_Low])+1]=g_YCLow_FRAMEFLAG[YC_Fram_Select_Low];
	P_ForYCPackge[(YC_Date_StepBegain_Low[YC_Fram_Select_Low])+(g_YCLow_Date_Length[YC_Fram_Select_Low])-1]=AddSum1((DEF_UINT8*)(&((P_ForYCPackge)[(YC_Date_StepBegain_Low[YC_Fram_Select_Low])])), (g_YCLow_Date_Length[YC_Fram_Select_Low]-1));
	//����EE��CC��"���ݳ���"
	if(g_YCLow_Date_Length[YC_Fram_Select_Low]<=Max_YCBtCount)	
		{
		YCYK_Send_Trans[0]=0xEE;
		YCYK_Send_Trans[1]=0xCC;
		YCYK_Send_Trans[2]=g_YCLow_Date_Length[YC_Fram_Select_Low];
		bcopy(&(P_ForYCPackge[(YC_Date_StepBegain_Low[YC_Fram_Select_Low])]),&(YCYK_Send_Trans[3]),g_YCLow_Date_Length[YC_Fram_Select_Low]);
		}
	}

else
	{/*---------------------���Ϳ�֡-------------------*/
	//���ݽڵ㿪ʼλ�ü���
	YC_Date_StepBegain[0]=0;
	for(i_ForYC_Ini=1;i_ForYC_Ini<YC_DATA_COUNT;i_ForYC_Ini++)
	{YC_Date_StepBegain[i_ForYC_Ini]=YC_Date_StepBegain[i_ForYC_Ini-1]+g_YC_Date_Length[i_ForYC_Ini-1];
	}
	P_ForYCPackge=(DEF_UINT8*)(&All_YCFast_Package);
	//ң��֡ѡ��
	YC_Fram_Select++;
	YC_Fram_Select=YC_Fram_Select%YC_DATA_COUNT;		
	//֡��־��ѭ��������У���
	P_ForYCPackge[(YC_Date_StepBegain[YC_Fram_Select])]=YC_Fram_Count++;
	P_ForYCPackge[(YC_Date_StepBegain[YC_Fram_Select])+1]=g_YC_FRAMEFLAG[YC_Fram_Select];
	P_ForYCPackge[(YC_Date_StepBegain[YC_Fram_Select])+(g_YC_Date_Length[YC_Fram_Select])-1]=AddSum1((DEF_UINT8*)(&((P_ForYCPackge)[(YC_Date_StepBegain[YC_Fram_Select])])), (g_YC_Date_Length[YC_Fram_Select]-1));
	//����EE��CC��"���ݳ���", ����ҪУ��һ��
	if(g_YC_Date_Length[YC_Fram_Select]<=Max_YCBtCount)
		{	
		YCYK_Send_Trans[0]=0xEE;
		YCYK_Send_Trans[1]=0xCC;
		YCYK_Send_Trans[2]=g_YC_Date_Length[YC_Fram_Select];
		bcopy(&(P_ForYCPackge[(YC_Date_StepBegain[YC_Fram_Select])]),&(YCYK_Send_Trans[3]),g_YC_Date_Length[YC_Fram_Select]);
		}

	}
		
		//����
		U1InTxBuf((U8*)(&(YCYK_Send_Trans[0])),(YCYK_Send_Trans[2]+3));
		ReserveCK_Send((U8*)(&(YCYK_Send_Trans[0])),(YCYK_Send_Trans[2]+3));

}




DEF_UINT8	YK_Msg_Checksum=0;		//ң��ָ����Ϣ�����
/*------------ң��ָ��ִ��--------------*/
void Only_YK_Operate()
 {
//����ת��һ�ݸ��ɼ������
UComFKSendCJ((DEF_UINT8*)&(YK_Msg_Trans[0]),(YK_Msg_Trans[2]+3));


//�洢
Date_Sore_GPSTime((DEF_UINT8*)&(YK_Msg_Trans[0]), (YK_Msg_Trans[2]+3));


	//У��(��ͷ�������Ƿ񳬳���У���)
	if((YK_Msg_Trans[0]==0xEE)&&(YK_Msg_Trans[1]==0xCC))
		{
		YK_Msg_Checksum=AddSum1((DEF_UINT8*)(&(YK_Msg_Trans[3])),(YK_Msg_Trans[2]-1));


		//У���ͨ����ִ��ң��ָ�����ֱ�ӻظ�" У�����"
		if(YK_Msg_Checksum==YK_Msg_Trans[(YK_Msg_Trans[2]+2)])
			{
		
			//�ж��Ƿ�Ϊң��ָ��
			if(YK_Msg_Trans[4]==FRAMEFLAG_YK)		
				{
				switch(YK_Msg_Trans[5])
					{					
					case	MSGCTRL_YK01_FlightMode:{bcopy(&(YK_Msg_Trans[3]),&(YK01_FlightMode),sizeof(YK01_FlightMode));if(YK_Msg_Trans[2]==sizeof(YK01_FlightMode)){Dowork_YK01_FlightMode();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK01_FlightMode),sizeof(YK01_FlightMode),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK02_WeightAdjust_Lock:{bcopy(&(YK_Msg_Trans[3]),&(YK02_WeightAdjust_Lock),sizeof(YK02_WeightAdjust_Lock));if(YK_Msg_Trans[2]==sizeof(YK02_WeightAdjust_Lock)){Dowork_YK02_WeightAdjust_Lock();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK02_WeightAdjust_Lock),sizeof(YK02_WeightAdjust_Lock),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK03_WeightAdjustCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK03_WeightAdjustCtrl),sizeof(YK03_WeightAdjustCtrl));if(YK_Msg_Trans[2]==sizeof(YK03_WeightAdjustCtrl)){Dowork_YK03_WeightAdjustCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK03_WeightAdjustCtrl),sizeof(YK03_WeightAdjustCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK04_NavCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK04_NavCtrl),sizeof(YK04_NavCtrl));if(YK_Msg_Trans[2]==sizeof(YK04_NavCtrl)){Dowork_YK04_NavCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK04_NavCtrl),sizeof(YK04_NavCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK05_FK_ComputHeart:{bcopy(&(YK_Msg_Trans[3]),&(YK05_FK_ComputHeart),sizeof(YK05_FK_ComputHeart));if(YK_Msg_Trans[2]==sizeof(YK05_FK_ComputHeart)){Dowork_YK05_FK_ComputHeart();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK05_FK_ComputHeart),sizeof(YK05_FK_ComputHeart),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK06_FK_ComputerReset:{bcopy(&(YK_Msg_Trans[3]),&(YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset));if(YK_Msg_Trans[2]==sizeof(YK06_FK_ComputerReset)){Dowork_YK06_FK_ComputerReset();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK07_FK_ComuterCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK07_FK_ComuterCtrl),sizeof(YK07_FK_ComuterCtrl));if(YK_Msg_Trans[2]==sizeof(YK07_FK_ComuterCtrl)){Dowork_YK07_FK_ComuterCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK07_FK_ComuterCtrl),sizeof(YK07_FK_ComuterCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK08_LandingParSet:{bcopy(&(YK_Msg_Trans[3]),&(YK08_LandingParSet),sizeof(YK08_LandingParSet));if(YK_Msg_Trans[2]==sizeof(YK08_LandingParSet)){Dowork_YK08_LandingParSet();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK08_LandingParSet),sizeof(YK08_LandingParSet),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK09_AirscrewCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK09_AirscrewCtrl),sizeof(YK09_AirscrewCtrl));if(YK_Msg_Trans[2]==sizeof(YK09_AirscrewCtrl)){Dowork_YK09_AirscrewCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK09_AirscrewCtrl),sizeof(YK09_AirscrewCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK0A_PropellerNCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK0A_PropellerNCtrl),sizeof(YK0A_PropellerNCtrl));if(YK_Msg_Trans[2]==sizeof(YK0A_PropellerNCtrl)){Dowork_YK0A_PropellerNCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK0A_PropellerNCtrl),sizeof(YK0A_PropellerNCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK0B_ValveCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK0B_ValveCtrl),sizeof(YK0B_ValveCtrl));if(YK_Msg_Trans[2]==sizeof(YK0B_ValveCtrl)){Dowork_YK0B_ValveCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK0B_ValveCtrl),sizeof(YK0B_ValveCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK0C_BallonetExploderControl:{bcopy(&(YK_Msg_Trans[3]),&(YK0C_BallonetExploderControl),sizeof(YK0C_BallonetExploderControl));if(YK_Msg_Trans[2]==sizeof(YK0C_BallonetExploderControl)){Dowork_YK0C_BallonetExploderControl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK0C_BallonetExploderControl),sizeof(YK0C_BallonetExploderControl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK0D_ValveExplodeCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK0D_ValveExplodeCtrl),sizeof(YK0D_ValveExplodeCtrl));if(YK_Msg_Trans[2]==sizeof(YK0D_ValveExplodeCtrl)){Dowork_YK0D_ValveExplodeCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK0D_ValveExplodeCtrl),sizeof(YK0D_ValveExplodeCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK0E_BalnetColPreFire:{bcopy(&(YK_Msg_Trans[3]),&(YK0E_BalnetColPreFire),sizeof(YK0E_BalnetColPreFire));if(YK_Msg_Trans[2]==sizeof(YK0E_BalnetColPreFire)){Dowork_YK0E_BalnetColPreFire();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK0E_BalnetColPreFire),sizeof(YK0E_BalnetColPreFire),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK0F_BalnetColCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK0F_BalnetColCtrl),sizeof(YK0F_BalnetColCtrl));if(YK_Msg_Trans[2]==sizeof(YK0F_BalnetColCtrl)){Dowork_YK0F_BalnetColCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK0F_BalnetColCtrl),sizeof(YK0F_BalnetColCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK10_EnergySysCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK10_EnergySysCtrl),sizeof(YK10_EnergySysCtrl));if(YK_Msg_Trans[2]==sizeof(YK10_EnergySysCtrl)){Dowork_YK10_EnergySysCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK10_EnergySysCtrl),sizeof(YK10_EnergySysCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK12_VectorAngelCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK12_VectorAngelCtrl),sizeof(YK12_VectorAngelCtrl));if(YK_Msg_Trans[2]==sizeof(YK12_VectorAngelCtrl)){Dowork_YK12_VectorAngelCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK12_VectorAngelCtrl),sizeof(YK12_VectorAngelCtrl),YK_ANSWER_ERR_CHECK);}break;}
					case	MSGCTRL_YK13_VectorParamCtrl:{bcopy(&(YK_Msg_Trans[3]),&(YK13_VectorParamCtrl),sizeof(YK13_VectorParamCtrl));if(YK_Msg_Trans[2]==sizeof(YK13_VectorParamCtrl)){Dowork_YK13_VectorParamCtrl();}else{YKCX_Answer_State_Date((DEF_UINT8*)(&YK13_VectorParamCtrl),sizeof(YK13_VectorParamCtrl),YK_ANSWER_ERR_CHECK);}break;}

					default: break;			
				}

			}

			//�ж��Ƿ�Ϊ�ɿؿ���ָ��
			else if(YK_Msg_Trans[4]==FRAMEFLAG_FK)	
				{
				bcopy(&(YK_Msg_Trans[3]),&(YK11_FlightCtrlDataTrans),(YK_Msg_Trans[2]+3));
				Dowork_YK11_FlightCtrlDataTrans();
				}
			
			//�ж��Ƿ�Ϊ��ѯָ��
			else if(YK_Msg_Trans[4]==FRAMEFLAG_CX)	
				{
				bcopy(&(YK_Msg_Trans[3]),&(CX_FlightCtrlData),sizeof(CX_FlightCtrlData));
				Dowork_CX_FlightCtrlData();
				}

			}	

		else	 if((YK_Msg_Trans[4]==FRAMEFLAG_YK)||(YK_Msg_Trans[4]==FRAMEFLAG_CX))	//���Ϊң�ػ��ѯָ���ֱ�ӻظ�" У�����"	
			{
				YKCX_Answer_State_Date((DEF_UINT8*)&(YK_Msg_Trans[3]), YK_Msg_Trans[2], YK_ANSWER_ERR_CHECK);
			}
		}

 }












DEF_INT8	N_For_ReserveCK_Send;		//��֡��N
DEF_INT8	ifor_ReserveCK_Send;		//��֡���
DEF_UINT8	Buffer_ReserveCK_Send[32];	//�����ݴ�
DEF_UINT8	Count_ReserveCK_Send=0;	//����ѭ������
/*-----10������豸���ݷ���----------*/
void ReserveCK_Send(DEF_UINT8 *p, DEF_UINT8 Length)
{
//���ȼ�⣬����0/����
if(Length!=0)
	{
	if(Length>Max_YCBtCount)
		{Length=Max_YCBtCount;}		

		
	//��֡��Nȷ��	
	if(Length%26==0)	
		{N_For_ReserveCK_Send=Length/26;}
	else	
		{N_For_ReserveCK_Send=(Length/26)+1;}
		
	//��֡ͷ	
	Buffer_ReserveCK_Send[0]=0xEB;	
	Buffer_ReserveCK_Send[1]=0x90;	
		
		
	//������֡	
	for(ifor_ReserveCK_Send=1;ifor_ReserveCK_Send<N_For_ReserveCK_Send;ifor_ReserveCK_Send++)	
		{
		Buffer_ReserveCK_Send[2]=N_For_ReserveCK_Send;
		Buffer_ReserveCK_Send[3]=ifor_ReserveCK_Send;
		Buffer_ReserveCK_Send[4]=Count_ReserveCK_Send++;
		bcopy(&(p[((ifor_ReserveCK_Send-1)*26)]),&(Buffer_ReserveCK_Send[5]),26);
		Buffer_ReserveCK_Send[31]=AddSum1((DEF_UINT8*)&(Buffer_ReserveCK_Send[2]),29);
		//д�뷢�ͻ���
		U4InTxBuf((DEF_UINT8*)&(Buffer_ReserveCK_Send[0]),32) ;
		}
		
	//���Ͳ�֡	
		Buffer_ReserveCK_Send[2]=N_For_ReserveCK_Send;
		Buffer_ReserveCK_Send[3]=N_For_ReserveCK_Send;
		Buffer_ReserveCK_Send[4]=Count_ReserveCK_Send++;
		memset(&(Buffer_ReserveCK_Send[5]), 0, 26);
		bcopy(&(p[((N_For_ReserveCK_Send-1)*26)]),&(Buffer_ReserveCK_Send[5]),(Length-(N_For_ReserveCK_Send-1)*26));
		Buffer_ReserveCK_Send[31]=AddSum1((DEF_UINT8*)&(Buffer_ReserveCK_Send[2]),29);
		//д�뷢�ͻ���
		U4InTxBuf((DEF_UINT8*)&(Buffer_ReserveCK_Send[0]),32) ;

	}

}















/*--------------����ң��ָ��ִ��--------------*/

void Dowork_YK01_FlightMode()
	{
		g_YC_Package.TJ.FlightMode=YK01_FlightMode.FlightMode;

		YKCX_Answer_State_Date((DEF_UINT8*)(&YK01_FlightMode),sizeof(YK01_FlightMode),YK_ANSWER_SUCCESS);
	}



void Dowork_YK02_WeightAdjust_Lock()
	{
		g_YC_Package.HD01.WeightAdjust_Lock=YK02_WeightAdjust_Lock.WeightAdjust_LockCtrl;

		YKCX_Answer_State_Date((DEF_UINT8*)(&YK02_WeightAdjust_Lock),sizeof(YK02_WeightAdjust_Lock),YK_ANSWER_SUCCESS);
	}



void Dowork_YK03_WeightAdjustCtrl()
	{
	//	��������
		if(TestByteBit(((YK03_WeightAdjustCtrl.WeightAdjustCtrl)&(g_YC_Package.HD01.WeightAdjust_Lock)), 0)==0x01)
			{
			g_GroupForSetDoSecond[0]=g_GroupForSetDoSecond[0]+YK03_WeightAdjustCtrl.WeightAdjustDevCtrl_Time;
			g_YC_Package.HD01.WeightAdjustOpenTime=g_YC_Package.HD01.WeightAdjustOpenTime+YK03_WeightAdjustCtrl.WeightAdjustDevCtrl_Time;
			}

	//	���ؿ��ƣ�����������
		if(TestByteBit(((YK03_WeightAdjustCtrl.WeightAdjustCtrl)&(g_YC_Package.HD01.WeightAdjust_Lock)), 1)==0x01)
			{g_GroupForSetDoSecond[1]=5;}

		YKCX_Answer_State_Date((DEF_UINT8*)(&YK03_WeightAdjustCtrl),sizeof(YK03_WeightAdjustCtrl),YK_ANSWER_SUCCESS);
	}



const DEF_UINT8 TransForYKIns[7]={0x72,0x65,0x73,0x65,0x74,0x0D,0x0A};
void Dowork_YK04_NavCtrl()
	{
		if(YK04_NavCtrl.INSCalibrationCtrl==0x11)
			{
			U2InTxBuf((DEF_UINT8*)&(TransForYKIns[0]), 7);
			}

		if((YK04_NavCtrl.FK_UseINS==0x11)||(YK04_NavCtrl.FK_UseINS==0x22))		
			{
			if(YK04_NavCtrl.FK_UseINS==0x11)
				{g_YC_Package.TJ.FK_UseINS=0;}
			else
				{g_YC_Package.TJ.FK_UseINS=0x01;}
			}


		YKCX_Answer_State_Date((DEF_UINT8*)(&YK04_NavCtrl),sizeof(YK04_NavCtrl),YK_ANSWER_SUCCESS);
	}




void Dowork_YK05_FK_ComputHeart()
	{
		if(YK05_FK_ComputHeart.Heart_Source==0x01)
			{DelaySecond_Healthy[0][0]=0;}
		else if(YK05_FK_ComputHeart.Heart_Source==0x02)
			{DelaySecond_Healthy[0][1]=0;}
		else if(YK05_FK_ComputHeart.Heart_Source==0x03)
			{DelaySecond_Healthy[0][2]=0;}
		//������Ҫ�ظ�
	}





void Dowork_YK06_FK_ComputerReset()
	{
		if((YK06_FK_ComputerReset.ComputerReset_Effect)&0x03==0x00)
			{
	//����Ч��ֱ�ӻظ��ɹ�------------
			YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_SUCCESS);
			}

		
		else if(TestByteBit((YK06_FK_ComputerReset.ComputerReset_Effect),0)==0x01)
			{
		//ָ��Ϊȡ������
			if(YK06_FK_ComputerReset.ComputerReset==0x00)		
				{
				g_YC_Package.HD01.CompuResetState=YK06_FK_ComputerReset.ComputerReset;
				//ң�ػظ�ִ�гɹ�
				YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_SUCCESS);	
				}		

		//ָ��Ϊ����׼��1
			else if(YK06_FK_ComputerReset.ComputerReset==0x11)		
				{
				if(g_YC_Package.HD01.CompuResetState==0x00)
					{
					g_YC_Package.HD01.CompuResetState=YK06_FK_ComputerReset.ComputerReset;
					//ң�ػظ�ִ�гɹ�
					YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_SUCCESS);			
					}
				else
					{
					g_YC_Package.HD01.CompuResetState=0x00;
					//ң�ػظ��������߱�
					YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_ERR_LACK);
					}
				}

		//ָ��Ϊ����׼��2
			else if(YK06_FK_ComputerReset.ComputerReset==0x55)		
				{
				if(g_YC_Package.HD01.CompuResetState==0x11)
					{
					g_YC_Package.HD01.CompuResetState=YK06_FK_ComputerReset.ComputerReset;
					//ң�ػظ�ִ�гɹ�
					YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_SUCCESS);			
					}
				else
					{
					g_YC_Package.HD01.CompuResetState=0x00;
					//ң�ػظ��������߱�
					YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_ERR_LACK);
					}
				}

		//ָ��Ϊ��������
			else if(YK06_FK_ComputerReset.ComputerReset==0x66)		
				{
				if(g_YC_Package.HD01.CompuResetState==0x55)
					{
					g_YC_Package.HD01.CompuResetState=YK06_FK_ComputerReset.ComputerReset;
					//ң�ػظ�ִ�гɹ�
					YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_SUCCESS);	

					while(1){};		//������ѭ�����ȴ�Ӳ�����Ź�����
					
					}
				else
					{
					g_YC_Package.HD01.CompuResetState=0x00;
					//ң�ػظ��������߱�
					YKCX_Answer_State_Date((DEF_UINT8*)(&YK06_FK_ComputerReset),sizeof(YK06_FK_ComputerReset),YK_ANSWER_ERR_LACK);
					}
				}

			}
	}





void Dowork_YK07_FK_ComuterCtrl()
	{
	if(TestByteBit((YK07_FK_ComuterCtrl.TempraCtrlSelect),0)==0x01)		//�¶ȿ���
		{TmpCtrl_CMD=YK07_FK_ComuterCtrl.TempraCtrl;	}		

	if(TestByteBit((YK07_FK_ComuterCtrl.RecordCtrlSelect),0)==0x01)		//��¼����
		{g_YC_Package.HD01.CompuRecState=YK07_FK_ComuterCtrl.RecordCtrl;	}

	if(TestByteBit((YK07_FK_ComuterCtrl.MemClearCtrlSelect),0)==0x01)	//�洢�������
		{
		if(YK07_FK_ComuterCtrl.MemClearCtrl==0x01)
			{Current_RecordBlock=0;}
		else if(YK07_FK_ComuterCtrl.MemClearCtrl==0x02)
			{SystemTime=0;}
		else if(YK07_FK_ComuterCtrl.MemClearCtrl==0x03)
			{Current_RecordBlock=0;	SystemTime=0;}
		}

	if(YK07_FK_ComuterCtrl.InChannelCtrl_Effect==0xAA)		//�ɿزɼ�ͨ��ͨ��
		{g_YC_Package.HD01.FKCJChannel=YK07_FK_ComuterCtrl.InChannelCtrl;}

	if(YK07_FK_ComuterCtrl.PowerReceiPoint_Effect==0xAA)		//��Դ�豸�����ն�
		{g_YC_Package.NY.PowerReceiPoint=YK07_FK_ComuterCtrl.PowerReceiPoint;}	

	//ң�ػظ�ִ�гɹ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK07_FK_ComuterCtrl),sizeof(YK07_FK_ComuterCtrl),YK_ANSWER_SUCCESS);	
	}





void Dowork_YK08_LandingParSet()
	{
	if(YK08_LandingParSet.Effe_SafeCtrlMinite==0xAA)
		{
		if(YK08_LandingParSet.SafeCtrlMinite<10){g_YC_Package.HD01.SafeCtrlMinite=10;}
		else if(YK08_LandingParSet.SafeCtrlMinite>120){g_YC_Package.HD01.SafeCtrlMinite=120;}
		else{g_YC_Package.HD01.SafeCtrlMinite=YK08_LandingParSet.SafeCtrlMinite;}
		}

	if(YK08_LandingParSet.Effe_CriticalBaricAlt==0xAA)
		{
		if(YK08_LandingParSet.CriticalBaricAlt<0)
			{g_YC_Package.HD01.CriticalBaricAlt=0;}
		else if(YK08_LandingParSet.CriticalBaricAlt>3000)
			{g_YC_Package.HD01.CriticalBaricAlt=3000;}
		else
			{g_YC_Package.HD01.CriticalBaricAlt=YK08_LandingParSet.CriticalBaricAlt;}
		}

		YKCX_Answer_State_Date((DEF_UINT8*)(&YK08_LandingParSet),sizeof(YK08_LandingParSet),YK_ANSWER_SUCCESS);
	}





DEF_UINT8	iForAircrewCtrl=0;
void Dowork_YK09_AirscrewCtrl()
	{
	for(iForAircrewCtrl=0;iForAircrewCtrl<=4;iForAircrewCtrl++)
		{
		if(TestByteBit((YK09_AirscrewCtrl.AirscrewCtrlSelect),iForAircrewCtrl)==0x01)
			{
			if(YK09_AirscrewCtrl.AirscrewCtrl[iForAircrewCtrl]==0x00)
				{
				Airscrew_CtrlSend((iForAircrewCtrl+1),0x0C,0);

				}
			else if(YK09_AirscrewCtrl.AirscrewCtrl[iForAircrewCtrl]==0x01)
				{
				Airscrew_CtrlSend((iForAircrewCtrl+1),0x0D,0);
				}
			}
		}

	YKCX_Answer_State_Date((DEF_UINT8*)(&YK09_AirscrewCtrl),sizeof(YK09_AirscrewCtrl),YK_ANSWER_SUCCESS);
	}





void Dowork_YK0A_PropellerNCtrl()
	{
	//ת���޷�
	if(YK0A_PropellerNCtrl.PropellerN_LimitSelect==0xAA)
		{
		if(YK0A_PropellerNCtrl.PropellerN_Limit<=600)
			{g_YC_Package.TJ.PropellerN_Limit=YK0A_PropellerNCtrl.PropellerN_Limit;}
		}
	if(YK0A_PropellerNCtrl.FrontPropelN_LimitSelect==0xAA)
		{
		if(YK0A_PropellerNCtrl.FrontPropelN_Limit<=3000)
			{g_YC_Package.TJ.FrontPropelN_Limit=YK0A_PropellerNCtrl.FrontPropelN_Limit;}
		}

	//ת�ٿ���
	for(iForAircrewCtrl=0;iForAircrewCtrl<=4;iForAircrewCtrl++)
		{
		if(TestByteBit((YK0A_PropellerNCtrl.AirscrewNCtrlSelect),iForAircrewCtrl)==0x01)
			{
			Airscrew_CtrlSend((iForAircrewCtrl+1),0x0B,(YK0A_PropellerNCtrl.AirscrewNCtrl[iForAircrewCtrl]));
			}
		}

	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK0A_PropellerNCtrl),sizeof(YK0A_PropellerNCtrl),YK_ANSWER_SUCCESS);
	}





DEF_UINT8	iForBalValCtrl;
DEF_UINT8	YKTransForEight[8];
void Dowork_YK0B_ValveCtrl()
	{
	for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
		{
		if(TestByteBit((YK0B_ValveCtrl.Ballonet_ValveCtrlSelect),iForBalValCtrl)==0x01)
			{
			if(((YK0B_ValveCtrl.Ballonet_ValveCtrl[iForBalValCtrl])>=0x01)&&((YK0B_ValveCtrl.Ballonet_ValveCtrl[iForBalValCtrl])<=0x09))
				{
				//���ſ��ؿ��� ����У�ش������������� 1+(20ms)+2+(20ms)+3
				Ballonet_CtrlSend((iForBalValCtrl+1),(YK0B_ValveCtrl.Ballonet_ValveCtrl[iForBalValCtrl]),(YK0B_ValveCtrl.Ballonet_ValveCtrlTime[iForBalValCtrl]));

				YKTransForEight[0]=iForBalValCtrl+1;	
				YKTransForEight[1]=YK0B_ValveCtrl.Ballonet_ValveCtrl[iForBalValCtrl];  
				YKTransForEight[2]=YK0B_ValveCtrl.Ballonet_ValveCtrlTime[iForBalValCtrl];
				CreateTimeDelayTask(0x0001,  20,  &(YKTransForEight[0]));
				CreateTimeDelayTask(0x0001,  40,  &(YKTransForEight[0]));
				}
			}
		}

	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK0B_ValveCtrl),sizeof(YK0B_ValveCtrl),YK_ANSWER_SUCCESS);
	}



void Dowork_YK0C_BallonetExploderControl()
	{
	if(g_YC_Package.TJ.FlightMode==0x4E)
		{
	
		//��������
		if(YK0C_BallonetExploderControl.BallonetExploderMode==0x01)
			{

			for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
				{
				if((YK0C_BallonetExploderControl.BallonetExploderCtrl[iForBalValCtrl]>=1)&&(YK0C_BallonetExploderControl.BallonetExploderCtrl[iForBalValCtrl]<=4))
					{
					//���屬�ƿ��� ����У�ش����� �򿪣��������� 1+(100ms)+2    ---------------------��ʱ1s�Զ��ر�-------------�رգ��������� 1+(100ms)+2
					Ballonet_CtrlSend((iForBalValCtrl+1),  (0x09+YK0C_BallonetExploderControl.BallonetExploderCtrl[iForBalValCtrl]),  0);
					YKTransForEight[0]=(iForBalValCtrl+1);
					YKTransForEight[1]=(0x09+YK0C_BallonetExploderControl.BallonetExploderCtrl[iForBalValCtrl]);
					CreateTimeDelayTask(0x0002,  100,  &(YKTransForEight[0]));

					YKTransForEight[0]=(iForBalValCtrl+1);
					YKTransForEight[1]=(0x15+YK0C_BallonetExploderControl.BallonetExploderCtrl[iForBalValCtrl]);
					CreateTimeDelayTask(0x0002,  1000,  &(YKTransForEight[0]));
					CreateTimeDelayTask(0x0002,  1100,  &(YKTransForEight[0]));
					}
				}
			}

		//1234һ�±���
		else if(YK0C_BallonetExploderControl.BallonetExploderMode==0x02)
			{
			//һ�±��� ��У�ش�������෢3�Σ�1+��1s��+��У��+2��+��1s��+��У��+3��
			for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
				{
				if(TestByteBit((YK0C_BallonetExploderControl.BallSameTimeExpCtrl), iForBalValCtrl)==0x01)
					{
					Ballonet_CtrlSend((iForBalValCtrl+1),  0x2C,  0);
					YKTransForEight[0]=(iForBalValCtrl+1);
					YKTransForEight[1]=0x2C;
					YKTransForEight[2]=2;
					CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
					}
				}
			}

		//ң�ػظ�ִ�гɹ�
		YKCX_Answer_State_Date((DEF_UINT8*)(&YK0C_BallonetExploderControl),sizeof(YK0C_BallonetExploderControl),YK_ANSWER_SUCCESS);

		}
	
	else
		{
		//ң�ػظ��������߱�
		YKCX_Answer_State_Date((DEF_UINT8*)(&YK0C_BallonetExploderControl),sizeof(YK0C_BallonetExploderControl),YK_ANSWER_ERR_LACK);
		}
	
	}






void Dowork_YK0D_ValveExplodeCtrl()
	{
	for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
		{
		//���ű��ƿ��� ����У�ش����� �򿪣��������� 1+(100ms)+2    ---------------------��ʱ1s�Զ��ر�-------------�رգ��������� 1+(100ms)+2
		if(TestByteBit((YK0D_ValveExplodeCtrl.ValveExplodeCtrl), iForBalValCtrl)==0x01)
			{
				Ballonet_CtrlSend((iForBalValCtrl+1),  0x12,  0);
				YKTransForEight[0]=(iForBalValCtrl+1);
				YKTransForEight[1]=0x12;
				CreateTimeDelayTask(0x0002,  100,  &(YKTransForEight[0]));

				YKTransForEight[0]=(iForBalValCtrl+1);
				YKTransForEight[1]=0x1E;
				CreateTimeDelayTask(0x0002,  1000,  &(YKTransForEight[0]));
				CreateTimeDelayTask(0x0002,  1100,  &(YKTransForEight[0]));
			}
		}

	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK0D_ValveExplodeCtrl),sizeof(YK0D_ValveExplodeCtrl),YK_ANSWER_SUCCESS);
	}




void Dowork_YK0E_BalnetColPreFire()
	{
	for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
		{
		//Ԥ��� ��У�ش�������෢3�Σ�1+��1s��+��У��+2��+��1s��+��У��+3��
		if(TestByteBit((YK0E_BalnetColPreFire.BalnetColPreFire), iForBalValCtrl)==0x01)
			{
			Ballonet_CtrlSend((iForBalValCtrl+1), 0x22, 0);
			YKTransForEight[0]=(iForBalValCtrl+1);
			YKTransForEight[1]=0x22;
			YKTransForEight[2]=2;
			CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
			}

		
		else
			{
			Ballonet_CtrlSend((iForBalValCtrl+1), 0x23, 0);
			YKTransForEight[0]=(iForBalValCtrl+1);
			YKTransForEight[1]=0x23;
			YKTransForEight[2]=2;
			CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
			}
		}

	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK0E_BalnetColPreFire),sizeof(YK0E_BalnetColPreFire),YK_ANSWER_SUCCESS);
	}




void Dowork_YK0F_BalnetColCtrl()
	{
	for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
		{
		//�������߿��� ��У�ش���: ��෢3�Σ�1+��1s��+��У��+2��+��1s��+��У��+3��
		if(TestByteBit((YK0F_BalnetColCtrl.BalnetColWorkCtrlEffect), iForBalValCtrl)==0x01)
			{
			if(YK0F_BalnetColCtrl.BalnetColWorkCtrl[iForBalValCtrl]==0x00)
				{
				Ballonet_CtrlSend((iForBalValCtrl+1), 0x2A, 0);
				YKTransForEight[0]=(iForBalValCtrl+1);
				YKTransForEight[1]=0x2A;
				YKTransForEight[2]=2;
				CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
				}
			else if(YK0F_BalnetColCtrl.BalnetColWorkCtrl[iForBalValCtrl]==0x01)
				{
				Ballonet_CtrlSend((iForBalValCtrl+1), 0x2B, 0);
				YKTransForEight[0]=(iForBalValCtrl+1);
				YKTransForEight[1]=0x2B;
				YKTransForEight[2]=2;
				CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
				}
			}
		}

	for(iForBalValCtrl=0;iForBalValCtrl<=3;iForBalValCtrl++)
		{
		//����ң���·� ��У�ش���: ��෢3�Σ�1+��1s��+��У��+2��+��1s��+��У��+3��
		if(TestByteBit((YK0F_BalnetColCtrl.BDYCTransCtrlEffect), iForBalValCtrl)==0x01)
			{
			if(YK0F_BalnetColCtrl.BDYCTransCtrl[iForBalValCtrl]==0x00)
				{
				Ballonet_CtrlSend((iForBalValCtrl+1), 0x3E, 0);
				YKTransForEight[0]=(iForBalValCtrl+1);
				YKTransForEight[1]=0x3E;
				YKTransForEight[2]=2;
				CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
				}
			else if(YK0F_BalnetColCtrl.BDYCTransCtrl[iForBalValCtrl]==0x01)
				{
				Ballonet_CtrlSend((iForBalValCtrl+1), 0x3F, 0);
				YKTransForEight[0]=(iForBalValCtrl+1);
				YKTransForEight[1]=0x3F;
				YKTransForEight[2]=2;
				CreateTimeDelayTask(0x0003,  1000,  &(YKTransForEight[0]));
				}
			}
		}

	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK0F_BalnetColCtrl),sizeof(YK0F_BalnetColCtrl),YK_ANSWER_SUCCESS);
	}








CanTxMsg	PowerCtrl_YKTrans;	//��Դ�豸ң��ָ����ݴ�
DEF_UINT8	i_ForPowerSelect=0;	//��Դ�豸ѡ�����

void Dowork_YK10_EnergySysCtrl()
{
	if(YK10_EnergySysCtrl.PowerCtrlSelect==0x00)
		{
	
	// DC-DC ���ؿ���
		if(YK10_EnergySysCtrl.DCDCCtrlEffect==0xAA)
			{
			memset(&PowerCtrl_YKTrans, 0, sizeof(PowerCtrl_YKTrans));
			
			PowerCtrl_YKTrans.StdId=0x7F;
			PowerCtrl_YKTrans.DLC=6;
			PowerCtrl_YKTrans.Data[0]=YK10_EnergySysCtrl.DCDCCtrlByte;
			PowerCtrl_YKTrans.Data[1]=0;
			bcopy(&(YK10_EnergySysCtrl.DCDCSetCur), &(PowerCtrl_YKTrans.Data[2]), 2);
			bcopy(&(YK10_EnergySysCtrl.DCDCSetVol), &(PowerCtrl_YKTrans.Data[4]), 2);
			//���ݷ��뷢�ͻ���
			Can1InTxFBuf(&PowerCtrl_YKTrans);
			}


	// DC-DC ��ʱ�ش�����
		for(i_ForPowerSelect=0;i_ForPowerSelect<3;i_ForPowerSelect++)
			{
			if(TestByteBit((YK10_EnergySysCtrl.DCDCTraCtEffect), i_ForPowerSelect)==0x01)
				{
				memset(&PowerCtrl_YKTrans, 0, sizeof(PowerCtrl_YKTrans));
				
				PowerCtrl_YKTrans.StdId=0x60;
				PowerCtrl_YKTrans.DLC=2;
				PowerCtrl_YKTrans.Data[0]=0x89+i_ForPowerSelect;
				PowerCtrl_YKTrans.Data[1]=TestByteBit((YK10_EnergySysCtrl.DCDCTraCtrl),i_ForPowerSelect);
				//���ݷ��뷢�ͻ���
				Can1InTxFBuf(&PowerCtrl_YKTrans);
				}
			}


	// ﮵�س��ڿ���
		if(YK10_EnergySysCtrl.BatteryInputCtEffect==0xAA)
			{
			if(YK10_EnergySysCtrl.BatteryInputCtrl<=0x01)
				{
				memset(&PowerCtrl_YKTrans, 0, sizeof(PowerCtrl_YKTrans));
				
				PowerCtrl_YKTrans.StdId=0x305;
				PowerCtrl_YKTrans.DLC=8;
				PowerCtrl_YKTrans.Data[0]=0xFF;
				PowerCtrl_YKTrans.Data[1]=0xFF;
				PowerCtrl_YKTrans.Data[2]=0x01;		//ID , �̶���1
				PowerCtrl_YKTrans.Data[3]=YK10_EnergySysCtrl.BatteryInputCtrl+1;	// �ر�0x01����0x02
				PowerCtrl_YKTrans.Data[4]=0x01;		//������0x01���ŵ����0x02
				PowerCtrl_YKTrans.Data[5]=0xFF;
				PowerCtrl_YKTrans.Data[6]=0xFF;
				PowerCtrl_YKTrans.Data[7]=0xFF;

				//���ݷ��뷢�ͻ���
				Can1InTxFBuf(&PowerCtrl_YKTrans);
				}

			}


	//﮵�طŵ�ڿ���
		if(YK10_EnergySysCtrl.BatteryOutputCtEffect==0xAA)
			{
			if(YK10_EnergySysCtrl.BatteryOutputCtrl<=0x01)
				{
				memset(&PowerCtrl_YKTrans, 0, sizeof(PowerCtrl_YKTrans));
				
				PowerCtrl_YKTrans.StdId=0x305;
				PowerCtrl_YKTrans.DLC=8;
				PowerCtrl_YKTrans.Data[0]=0xFF;
				PowerCtrl_YKTrans.Data[1]=0xFF;
				PowerCtrl_YKTrans.Data[2]=0x01;		//ID , �̶���1
				PowerCtrl_YKTrans.Data[3]=YK10_EnergySysCtrl.BatteryOutputCtrl+1;	// �ر�0x01����0x02
				PowerCtrl_YKTrans.Data[4]=0x02;		//������0x01���ŵ����0x02
				PowerCtrl_YKTrans.Data[5]=0xFF;
				PowerCtrl_YKTrans.Data[6]=0xFF;
				PowerCtrl_YKTrans.Data[7]=0xFF;

				//���ݷ��뷢�ͻ���
				Can1InTxFBuf(&PowerCtrl_YKTrans);
				}
			}

		//ң�ػظ�
		YKCX_Answer_State_Date((DEF_UINT8*)(&YK10_EnergySysCtrl),sizeof(YK10_EnergySysCtrl),YK_ANSWER_SUCCESS);
		}	
}




/*--------ʸ��װ�ýǶȿ���------*/
void Dowork_YK12_VectorAngelCtrl()
{
	
	Vector_Control(0x01,YK12_VectorAngelCtrl.VectorAngelCtrl);

	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK12_VectorAngelCtrl),sizeof(YK12_VectorAngelCtrl),YK_ANSWER_SUCCESS);

}



/*---------ʸ��װ�ò�������-----*/
void Dowork_YK13_VectorParamCtrl()
{
	if(YK13_VectorParamCtrl.Effect_VertorOnOff==0xAA)
		{
		if(YK13_VectorParamCtrl.VertorOnOff==0x01)
			{Vector_Control(0x04,0);}
		else if(YK13_VectorParamCtrl.VertorOnOff==0x02)
			{Vector_Control(0x02,0);}
		else if(YK13_VectorParamCtrl.VertorOnOff==0x03)
			{Vector_Control(0x03,0);}
		}


	if(YK13_VectorParamCtrl.Effect_VectorErroClear==0xAA)
		{
		if(YK13_VectorParamCtrl.VectorErroClear==0x01)
			{Vector_Control(0x05,0);}
		}


	if(YK13_VectorParamCtrl.Effect_VectorNCtrl==0xAA)
		{
		Vector_Control(0x06,(DEF_INT16)(YK13_VectorParamCtrl.VectorNCtrl));
		}


	//ң�ػظ�
	YKCX_Answer_State_Date((DEF_UINT8*)(&YK13_VectorParamCtrl),sizeof(YK13_VectorParamCtrl),YK_ANSWER_SUCCESS);

}



























































DEF_UINT8	AnsweTrans[Max_YKBtCount];	//ң�ز�ѯ�ظ��ݴ�
DEF_UINT8	AnsweTrans_NoHead[Max_YKBtCount];	//ң�ز�ѯ�ظ��ݴ�, ��ee ��cc ��N
/*---------------����ң�ػظ�����----------------*/
//����1----��ʼ��ַ(����EE CC N)��     2-----���ͳ���(��Checksum)��       3------ִ��״̬Ϊ��4�ֽڣ�
void YKCX_Answer_State_Date(DEF_UINT8 *ykcx_struct, DEF_UINT8 count, DEF_UINT8 ykcx_state)
{
	//��ͷ
	memset(AnsweTrans, 0, Max_YKBtCount);
	AnsweTrans[0]=0xEE;
	AnsweTrans[1]=0xCC;
	AnsweTrans[2]=count;

	//��ִ��״̬��У��
	bcopy(&(ykcx_struct[0]),&(AnsweTrans_NoHead[0]),count);
	AnsweTrans_NoHead[3]=ykcx_state;
	AnsweTrans_NoHead[count-1]=AddSum1((DEF_UINT8*)(&(AnsweTrans_NoHead[0])), (count-1) );

	//���뷢�ͻ��ζ���
	bcopy(&(AnsweTrans_NoHead[0]),&(AnsweTrans[3]),count);
	bcopy(&(AnsweTrans[0]),&(YK_AnsweStore[YK_Answe_Position_Put][0]),Max_YKBtCount);
	
	YK_Answe_Position_Put=(YK_Answe_Position_Put+1)%YK_AnStoreCount;
}







/* ------------UƵ�β��---��·����֡����------------*/
_SJZYC001_FastFrame	SJZYC001_FastFrame;	//ң����Ϣ֡��ԭ��֡
void	Task_Ulink_SendTestFram()
{
	//--------���Ͳ����·��Ϣ֡--------
	SJZYC001_FastFrame.m_SycCode1=0xEB;
	SJZYC001_FastFrame.m_SycCode2=0x90;
	SJZYC001_FastFrame.m_StationNum=0;
	SJZYC001_FastFrame.m_FrameFlag=0x81;
	SJZYC001_FastFrame.m_Count++;
	SJZYC001_FastFrame.m_BaricAlt1=g_YC_Package.HD01.BaricAlt;
	SJZYC001_FastFrame.m_INSLon=g_YC_Package.HD01.INSLon*10000000;
	SJZYC001_FastFrame.m_INSLat=g_YC_Package.HD01.INSLat*10000000;
	SJZYC001_FastFrame.m_InsAlt=g_YC_Package.HD01.INSAlt;
	SJZYC001_FastFrame.m_GPSAlt=g_YC_Package.TJ.GNSS_GPSAlt;
	SJZYC001_FastFrame.m_Pitch=g_YC_Package.HD01.Pitch;
	SJZYC001_FastFrame.m_Roll=g_YC_Package.HD01.Roll;
	SJZYC001_FastFrame.m_Heading=g_YC_Package.HD01.Yaw;
	SJZYC001_FastFrame.m_Heading=0x0000;
	SJZYC001_FastFrame.m_CheckSum=AddSum1((DEF_UINT8*)&(SJZYC001_FastFrame.m_StationNum),29);
	//д�뷢�ͻ���
	U4InTxBuf((DEF_UINT8*)&(SJZYC001_FastFrame.m_SycCode1),32);
}





/* ------------LƵ�β��---ң��ָ�����------------*/
void Task_LlinkCK_Reiceive()
{
	//��ȡң��ָ��
	//YK_Msg_Trans[]
if(U1RxFBufPo!=U1RxFBufPi)
	{	
	if(U1RxFBuf[U1RxFBufPo][U1_RxF_Len]<=Max_YKBtCount)
		{		
		bcopy(&(U1RxFBuf[U1RxFBufPo][0]),&(YK_Msg_Trans[0]),U1RxFBuf[U1RxFBufPo][U1_RxF_Len]);
		//ִ��ң��ָ��
		Only_YK_Operate();
		}
	U1RxFBufPo=(U1RxFBufPo+1)%U1_RxF_BufLen;
	}

}




DEF_UINT8	Checksum_ReserveCK_Receive=0;		//����У���
DEF_UINT8	Buffer_ReserveCK_Receive[32];		//ң��ָ����ݴ�
DEF_UINT8	ReserveCK_Receive_All[26*5];		//ң��ָ����ݴ�λ��,����ͷEE ��CC �����ݸ���
DEF_UINT8	N_For_ReserveCK_Receive=0;			//��֡��N
DEF_UINT8	ifor_ReserveCK_Receive=0;				//��֡���
DEF_UINT8	Count_ReserveCK_Receive=0;			//��֡����
/* ------------UƵ�β��---ң��ָ�����------------*/
void Task_UlinkCK_Reiceive()
 {
if(U4RxFBufPo!=U4RxFBufPi)
	{	
	bcopy(&(U4RxFBuf[U4RxFBufPo][0]),&(Buffer_ReserveCK_Receive[0]),32);
	U4RxFBufPo=(U4RxFBufPo+1)%U4_RxF_BufLen;

	Checksum_ReserveCK_Receive=AddSum1((DEF_UINT8*)&(Buffer_ReserveCK_Receive[2]),29);
	if((Buffer_ReserveCK_Receive[0]==0xEB)&&(Buffer_ReserveCK_Receive[1]==0x90)&&(Buffer_ReserveCK_Receive[31]==Checksum_ReserveCK_Receive))
		{
		N_For_ReserveCK_Receive=Buffer_ReserveCK_Receive[2];
		ifor_ReserveCK_Receive=Buffer_ReserveCK_Receive[3];
		
		if(ifor_ReserveCK_Receive==1)
			{Count_ReserveCK_Receive=0;}		//������0

		if(ifor_ReserveCK_Receive<=5)
			{
			bcopy(&(Buffer_ReserveCK_Receive[5]),&(ReserveCK_Receive_All[(ifor_ReserveCK_Receive-1)*26]),26);
			Count_ReserveCK_Receive++;
			}

		if((ifor_ReserveCK_Receive==N_For_ReserveCK_Receive)&&(Count_ReserveCK_Receive==N_For_ReserveCK_Receive))
			{
			if(ReserveCK_Receive_All[2]<=Max_YKBtCount)
				{
				//�յ����һ֡����������������ת��ң��/��ѯָ��ִ��
				bcopy(&(ReserveCK_Receive_All[0]),&(YK_Msg_Trans[0]),(ReserveCK_Receive_All[2]+3));
				//ִ��ң��ָ��
				Only_YK_Operate();
				}
			}

		}
	}

 }



/*------------�ɿ���ɼ���������ʹ�������------------*/
void UComFKSendCJ(DEF_UINT8 *BuffP, DEF_UINT8 SendCount)
{
if(g_YC_Package.HD01.FKCJChannel==0x00)
	{U3InTxBuf(BuffP,SendCount);}
else
	{UHInTxBuf(BuffP,SendCount);}

}


















