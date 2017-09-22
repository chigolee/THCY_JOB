/*========================================================================================*
 * FILE:                     	B_TimeSecondDelay.c                   
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
 #include "B_TimeSecondDelay.h"
 *------------------------------------------------------------------------------*/
 #include "B_TimeSecondDelay.h"
 #include "User_Data.h"

/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/


DEF_UINT8	DelayHealthyByte[4];		//��ʱ״̬�ֽڴ洢bit     0-��ʱ��  1-������ 
DEF_UINT8	DelaySecond_Healthy[4][8];		//�豸��ʱ��ʱ
/*----״̬0 -----*/
// 0-L; 
// 1-U; 
// 2-U�ƶ�; 
// 3-�ɼ������1·; 
// 4-�ɼ������2·; 
// 5-����;
// 6-�в�����; 
// 7-ǰ��������

/*----״̬1 -----*/
// 0-��ǰ���; 
// 1-�����; 
// 2-��ǰ���; 
// 3-�Һ���; 
// 4-��ѹDC;
// 5-28V_DC;
// 6-29V_DC;
// 7-������;


/*----״̬2 -----*/
// 0-���ܵ��1; 
// 1-���ܵ��2; 
// 2-Ӧ��﮵��; 
// 3-ʸ��װ��; 
// 4-�Ҳ�������
// 5-�Ҳ��б���
// 6-�Ҳ�ǰ����
// 7-�Ҳ�ǰ����

/*----״̬3 -----*/
// 0-���ߵ�; 
// 1-GNSS���ջ�; 


DEF_UINT8	g_GroupForSetDoSecond[8]={0};	//DO������ʱ����


/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/
 DEF_UINT8	CJComputerDelayTime=0;	//�ɼ��������ʱʱ�䣬����10s���Զ��л�ͨ����Ҳ���ֶ��л�
 DEF_UINT8	TransForFKCJHeart[6];	//FK��CJ����֡


 DEF_UINT8	iForTestTimeSecond;		//ѭ�������
 DEF_UINT8	iForByteTest;
 /*---------��ʱ1sִ�е�����---------*/
void Task_B_TimeSecondDelay()
{


/*-------�ֳ����ݱ���-----*/
      	{
      	//����Pro_Data
	Pro_Data.Current_RecordBlock=Current_RecordBlock;
	Pro_Data.CriticalBaricAlt=g_YC_Package.HD01.CriticalBaricAlt;
	Pro_Data.PropellerN_Limit=g_YC_Package.TJ.PropellerN_Limit;
	Pro_Data.FrontPropelN_Limit=g_YC_Package.TJ.FrontPropelN_Limit;
	Pro_Data.FlightMode=g_YC_Package.TJ.FlightMode;
	Pro_Data.CompuRecState=g_YC_Package.HD01.CompuRecState;
	Pro_Data.SafeCtrlMinite=g_YC_Package.HD01.SafeCtrlMinite;
	Pro_Data.AirscrewCtrlState=g_YC_Package.TJ.AirscrewCtrlState;
	
      //����ProData_Flag	���ֳ��������ݸ��� 
	ProData_Flag = TRUE;	  
      }





/*-------------����豸��ʱ״̬--------------*/
	for(iForByteTest=0;iForByteTest<=3;iForByteTest++)
		{
		for(iForTestTimeSecond=0;iForTestTimeSecond<=7;iForTestTimeSecond++)
			{
			if(DelaySecond_Healthy[iForByteTest][iForTestTimeSecond]<10)
				{
				DelayHealthyByte[iForByteTest]=SetByteBit(DelayHealthyByte[iForByteTest],iForTestTimeSecond,1);
				DelaySecond_Healthy[iForByteTest][iForTestTimeSecond]++;
				}
			else
				{DelayHealthyByte[iForByteTest]=SetByteBit(DelayHealthyByte[iForByteTest],iForTestTimeSecond,0);}			
			}		
		}


/*-----------FK��CJ ͨ�ż�⼰��������------------*/
	//ͨ�����
if(g_YC_Package.HD01.FKCJChannel==0x00)	
	{	
		if(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 3)==0x00)
			{CJComputerDelayTime=CJComputerDelayTime+1;}	
		else 
			{CJComputerDelayTime=0;}
	}
else
	{	
		if(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 4)==0x00)
			{CJComputerDelayTime=CJComputerDelayTime+1;}	
		else
			{CJComputerDelayTime=0;}
	}
	//ͨ���л�
if(CJComputerDelayTime>=10)			
	{
	if(g_YC_Package.HD01.FKCJChannel==0x00)
		{g_YC_Package.HD01.FKCJChannel=0x01;}
	else
		{g_YC_Package.HD01.FKCJChannel=0x00;}
	CJComputerDelayTime=0;
	}
	//��������
TransForFKCJHeart[0]=U3_DH0;					TransForFKCJHeart[1]=U3_DH1;		TransForFKCJHeart[2]=3;
TransForFKCJHeart[3]=TransForFKCJHeart[3]+1;	TransForFKCJHeart[4]=0x50;
TransForFKCJHeart[5]=AddSum1((DEF_UINT8*)&(TransForFKCJHeart[3]), 2);
UComFKSendCJ((DEF_UINT8*)&(TransForFKCJHeart[0]),6);	





//-----------DO��ʱ���,  �������------------------
	for(iForTestTimeSecond=0;iForTestTimeSecond<=7;iForTestTimeSecond++)
		{
		if(g_GroupForSetDoSecond[iForTestTimeSecond]>0)
			{
			DOData=SetByteBit(DOData,iForTestTimeSecond,1);
			g_GroupForSetDoSecond[iForTestTimeSecond]=g_GroupForSetDoSecond[iForTestTimeSecond]-1;
			}
		else
			{DOData=SetByteBit(DOData,iForTestTimeSecond,0);}
		}

 }








DEF_UINT32	TimeForCKDelay=0;
DEF_UINT8	SignForSafeHeight=0;	//�߶�״̬��0-������1-�쳣
DEF_INT16	HeightSafeCtrl=20000;	//��ǰ�߶ȣ�����ʹ��
DEF_UINT16	TimeForFastEx=0; 		//���ٷ�����ʱ����λ100ms

DEF_UINT16	CKDelayMaxTime=18000;		//��λ0.1s
/*----------��ʱ100msִ�е�����-----------*/
 void Task_B_Time100msDelay()
 	{
	//�����״̬
	g_YC_Package.HD01.CompuState[0]=Hardware_State1;
	g_YC_Package.HD01.CompuState[1]=Hardware_State2;
	g_YCLowPack.JC01.CompuTempra=InnerTmp;
	g_YC_Package.HD01.TempraCtrl=TmpCtrl_CMD;
	g_YC_Package.HD01.WeightAdjustState=DOData;

	g_YC_Package.HD01.DelayReceiveState[0]=DelayHealthyByte[0];
	g_YC_Package.HD01.DelayReceiveState[1]=DelayHealthyByte[1];
	g_YC_Package.HD01.DelayReceiveState[2]=DelayHealthyByte[2];
	g_YC_Package.HD01.DelayReceiveState[3]=DelayHealthyByte[3];

	g_YC_Package.HD01.CompuRecBlock=Current_RecordBlock;
	g_YC_Package.HD01.CompuSysTime=SystemTime;
	if(TimeForCKDelay<600000){g_YC_Package.HD01.CKBreakTime=TimeForCKDelay*0.1;}   else{g_YC_Package.HD01.CKBreakTime=60000;}
	

	

	//�����¶Ȳɼ�
	g_YCLowPack.JC01.CabinTemp[0]=(DEF_INT32)(((((DEF_FLOAT32)(AinData[0])*33.0*2.0)/4096.0)/10-1.7642)/0.0114+80);
	g_YCLowPack.JC01.CabinTemp[1]=(DEF_INT32)(((((DEF_FLOAT32)(AinData[1])*33.0*2.0)/4096.0)/10-1.7642)/0.0114+80);
	g_YCLowPack.JC01.CabinTemp[2]=(DEF_INT32)(((((DEF_FLOAT32)(AinData[2])*33.0*2.0)/4096.0)/10-1.7642)/0.0114+80);





	if((TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 0)==0x00)
		&&(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 1)==0x00)
		&&(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 2)==0x00))
		{TimeForCKDelay=TimeForCKDelay+1;}
	else
		{TimeForCKDelay=0;}


	if(g_YC_Package.TJ.FlightMode!=0x15)	//�������ģʽ�²��߰�������
		{

	/*----��ʱ���أ�ע��ʱ�䵥λΪ0.1s   -------------------*/
		CKDelayMaxTime=g_YC_Package.HD01.SafeCtrlMinite*600;

		if(TimeForCKDelay>=CKDelayMaxTime)
			{
			
			if((TimeForCKDelay==CKDelayMaxTime)||(TimeForCKDelay==(CKDelayMaxTime+5)))
				{
				g_YC_Package.TJ.FlightMode=0x4E;
				//���������Σ����0.5s
				//�����ţ�ʱ����20s
				Ballonet_CtrlSend(1,0x01,200);
				Ballonet_CtrlSend(2,0x01,200);
				Ballonet_CtrlSend(3,0x01,200);
				Ballonet_CtrlSend(4,0x01,200);			
				}

			
			else if(TimeForCKDelay==(CKDelayMaxTime+200))
				{
				//20s������ʱ/δ�����ɹ�������ٷ���
					if(	(((g_YC_Package.HD01.DelayReceiveState[2])&0xF0)<0xF0)	//�ɼ����г�ʱ
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[0]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[0]),7)==0x00))	//�ɼ���1�������ž�����λ
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[1]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[1]),7)==0x00))	//�ɼ���1�������ž�����λ
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[2]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[2]),7)==0x00))	//�ɼ���2�������ž�����λ
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[3]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[3]),7)==0x00))	//�ɼ���2�������ž�����λ
					)
						{
						Balloon_FastExploder();
						TimeForFastEx=FastExHeightTime;
						}
				}

			}



//-----����ģʽ�³�������
		if(g_YC_Package.TJ.FlightMode==0x4E)
			{
			//-------------------�߶ȼ�⼰ȷ��-------------------------------
			if(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 5)==0x01)
				{//��ѹ�߶ȱ�����
				SignForSafeHeight=0;
				HeightSafeCtrl=g_YC_Package.HD01.BaricAlt;
				}		
			else if((TestByteBit((g_YC_Package.HD01.DelayReceiveState[3]), 1)==0x01)&&(g_YC_Package.TJ.GNSS_ReceiverState==0x00))
				{//GNSS�߶�����
				SignForSafeHeight=0;
				HeightSafeCtrl=g_YC_Package.TJ.GNSS_GPSAlt;
				}
			else
				{//�߶��쳣
				SignForSafeHeight=1;
				}

			//-----------------���ؿ��ٷ���---------------------------	
			if(TimeForFastEx<FastExHeightTime)
				{				
				if((SignForSafeHeight==1)||(HeightSafeCtrl<g_YC_Package.HD01.CriticalBaricAlt))	
					{
					TimeForFastEx=TimeForFastEx+1;
					if(TimeForFastEx==FastExHeightTime)
						{Balloon_FastExploder();}
					}
				else
					{TimeForFastEx=0;}
				}				
	
			}

		}

 	}














/*-----
   0s---Ԥ���򿪣���3�Σ����100ms��
   1s---�в���ǰ����һ�±��ƣ�1s���ش�����෢3�Σ�
   5s --�в���ǰ����һ�±��ƣ�1s���ش�����෢3�Σ�
   10s -Ԥ���رգ���3�Σ����100ms��
 -----*/


DEF_UINT8	OnceSignForFastExploder=0;	//���ٷ�����־λ�����ٷ���ִֻ��һ�Σ�0Ϊ��ִ��״̬
DEF_UINT8	Second01TransForData[DelayDataCount];
DEF_UINT8	iForSecond01Val=0;
/*--------���ٷ���(����ǰ�������ģʽ�Ƿ��ڽ���ģʽ)-------*/
void Balloon_FastExploder()
{
//�����ٷ�����־λ
if(OnceSignForFastExploder==0)
	{
	//Ԥ����
	for(iForSecond01Val=1;iForSecond01Val<=4;iForSecond01Val++)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x22;
		Ballonet_CtrlSend(iForSecond01Val, 0x22, 0);
		CreateTimeDelayTask(0x0004, 100, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0004, 200, &(Second01TransForData[0]));
		}
	/*----------*/
	//���Ҳ�һ�±���
	for(iForSecond01Val=1; iForSecond01Val<=4; iForSecond01Val=iForSecond01Val+2)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x2C;
		Second01TransForData[2]=2;
		CreateTimeDelayTask(0x0004, 1000, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0003, 2000, &(Second01TransForData[0]));
		}


	//���Ҳ�һ�±���
	for(iForSecond01Val=2; iForSecond01Val<=4; iForSecond01Val=iForSecond01Val+2)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x2C;
		Second01TransForData[2]=2;
		CreateTimeDelayTask(0x0004, 5000, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0003, 6000, &(Second01TransForData[0]));	
		}


	// Ԥ���ر�
	for(iForSecond01Val=1;iForSecond01Val<=4;iForSecond01Val++)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x23;
		CreateTimeDelayTask(0x0004, 10000, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0004, 10100, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0004, 10200, &(Second01TransForData[0]));
		}
	
	//���ٷ�����־λ��Ϊ1
	OnceSignForFastExploder=1;
	}
	
}





