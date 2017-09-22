/*========================================================================================*
 * FILE:                     	B_TimeSecondDelay.c                   
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
 #include "B_TimeSecondDelay.h"
 *------------------------------------------------------------------------------*/
 #include "B_TimeSecondDelay.h"
 #include "User_Data.h"

/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/


DEF_UINT8	DelayHealthyByte[4];		//超时状态字节存储bit     0-超时；  1-正常。 
DEF_UINT8	DelaySecond_Healthy[4][8];		//设备超时计时
/*----状态0 -----*/
// 0-L; 
// 1-U; 
// 2-U移动; 
// 3-采集计算机1路; 
// 4-采集计算机2路; 
// 5-气高;
// 6-中部北斗; 
// 7-前部北斗。

/*----状态1 -----*/
// 0-左前电机; 
// 1-左后电机; 
// 2-右前电机; 
// 3-右后电机; 
// 4-高压DC;
// 5-28V_DC;
// 6-29V_DC;
// 7-航向电机;


/*----状态2 -----*/
// 0-储能电池1; 
// 1-储能电池2; 
// 2-应急锂电池; 
// 3-矢量装置; 
// 4-囊采中主；
// 5-囊采中备；
// 6-囊采前主；
// 7-囊采前备。

/*----状态3 -----*/
// 0-主惯导; 
// 1-GNSS接收机; 


DEF_UINT8	g_GroupForSetDoSecond[8]={0};	//DO控制延时数组


/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/
 DEF_UINT8	CJComputerDelayTime=0;	//采集计算机超时时间，超过10s则自动切换通道，也可手动切换
 DEF_UINT8	TransForFKCJHeart[6];	//FK到CJ心跳帧


 DEF_UINT8	iForTestTimeSecond;		//循环监测用
 DEF_UINT8	iForByteTest;
 /*---------延时1s执行的任务---------*/
void Task_B_TimeSecondDelay()
{


/*-------现场数据保护-----*/
      	{
      	//更新Pro_Data
	Pro_Data.Current_RecordBlock=Current_RecordBlock;
	Pro_Data.CriticalBaricAlt=g_YC_Package.HD01.CriticalBaricAlt;
	Pro_Data.PropellerN_Limit=g_YC_Package.TJ.PropellerN_Limit;
	Pro_Data.FrontPropelN_Limit=g_YC_Package.TJ.FrontPropelN_Limit;
	Pro_Data.FlightMode=g_YC_Package.TJ.FlightMode;
	Pro_Data.CompuRecState=g_YC_Package.HD01.CompuRecState;
	Pro_Data.SafeCtrlMinite=g_YC_Package.HD01.SafeCtrlMinite;
	Pro_Data.AirscrewCtrlState=g_YC_Package.TJ.AirscrewCtrlState;
	
      //更新ProData_Flag	，现场保护数据更新 
	ProData_Flag = TRUE;	  
      }





/*-------------检查设备超时状态--------------*/
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


/*-----------FK到CJ 通信检测及心跳发送------------*/
	//通道检测
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
	//通道切换
if(CJComputerDelayTime>=10)			
	{
	if(g_YC_Package.HD01.FKCJChannel==0x00)
		{g_YC_Package.HD01.FKCJChannel=0x01;}
	else
		{g_YC_Package.HD01.FKCJChannel=0x00;}
	CJComputerDelayTime=0;
	}
	//心跳发送
TransForFKCJHeart[0]=U3_DH0;					TransForFKCJHeart[1]=U3_DH1;		TransForFKCJHeart[2]=3;
TransForFKCJHeart[3]=TransForFKCJHeart[3]+1;	TransForFKCJHeart[4]=0x50;
TransForFKCJHeart[5]=AddSum1((DEF_UINT8*)&(TransForFKCJHeart[3]), 2);
UComFKSendCJ((DEF_UINT8*)&(TransForFKCJHeart[0]),6);	





//-----------DO延时检测,  放在最后------------------
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
DEF_UINT8	SignForSafeHeight=0;	//高度状态，0-正常，1-异常
DEF_INT16	HeightSafeCtrl=20000;	//当前高度，安控使用
DEF_UINT16	TimeForFastEx=0; 		//快速放气计时，单位100ms

DEF_UINT16	CKDelayMaxTime=18000;		//单位0.1s
/*----------延时100ms执行的任务-----------*/
 void Task_B_Time100msDelay()
 	{
	//计算机状态
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
	

	

	//吊舱温度采集
	g_YCLowPack.JC01.CabinTemp[0]=(DEF_INT32)(((((DEF_FLOAT32)(AinData[0])*33.0*2.0)/4096.0)/10-1.7642)/0.0114+80);
	g_YCLowPack.JC01.CabinTemp[1]=(DEF_INT32)(((((DEF_FLOAT32)(AinData[1])*33.0*2.0)/4096.0)/10-1.7642)/0.0114+80);
	g_YCLowPack.JC01.CabinTemp[2]=(DEF_INT32)(((((DEF_FLOAT32)(AinData[2])*33.0*2.0)/4096.0)/10-1.7642)/0.0114+80);





	if((TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 0)==0x00)
		&&(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 1)==0x00)
		&&(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 2)==0x00))
		{TimeForCKDelay=TimeForCKDelay+1;}
	else
		{TimeForCKDelay=0;}


	if(g_YC_Package.TJ.FlightMode!=0x15)	//地面调试模式下不走安控流程
		{

	/*----延时安控，注意时间单位为0.1s   -------------------*/
		CKDelayMaxTime=g_YC_Package.HD01.SafeCtrlMinite*600;

		if(TimeForCKDelay>=CKDelayMaxTime)
			{
			
			if((TimeForCKDelay==CKDelayMaxTime)||(TimeForCKDelay==(CKDelayMaxTime+5)))
				{
				g_YC_Package.TJ.FlightMode=0x4E;
				//开阀门两次，间隔0.5s
				//开阀门，时间填20s
				Ballonet_CtrlSend(1,0x01,200);
				Ballonet_CtrlSend(2,0x01,200);
				Ballonet_CtrlSend(3,0x01,200);
				Ballonet_CtrlSend(4,0x01,200);			
				}

			
			else if(TimeForCKDelay==(CKDelayMaxTime+200))
				{
				//20s后，若超时/未开启成功，则快速放气
					if(	(((g_YC_Package.HD01.DelayReceiveState[2])&0xF0)<0xF0)	//采集器有超时
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[0]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[0]),7)==0x00))	//采集器1主，阀门均不到位
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[1]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[1]),7)==0x00))	//采集器1备，阀门均不到位
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[2]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[2]),7)==0x00))	//采集器2主，阀门均不到位
						||((TestByteBit((g_YC_Package.NT.Ballonet_ValveState[3]),6)==0x00)&&(TestByteBit((g_YC_Package.NT.Ballonet_ValveState[3]),7)==0x00))	//采集器2备，阀门均不到位
					)
						{
						Balloon_FastExploder();
						TimeForFastEx=FastExHeightTime;
						}
				}

			}



//-----降落模式下程序流程
		if(g_YC_Package.TJ.FlightMode==0x4E)
			{
			//-------------------高度检测及确定-------------------------------
			if(TestByteBit((g_YC_Package.HD01.DelayReceiveState[0]), 5)==0x01)
				{//气压高度表正常
				SignForSafeHeight=0;
				HeightSafeCtrl=g_YC_Package.HD01.BaricAlt;
				}		
			else if((TestByteBit((g_YC_Package.HD01.DelayReceiveState[3]), 1)==0x01)&&(g_YC_Package.TJ.GNSS_ReceiverState==0x00))
				{//GNSS高度正常
				SignForSafeHeight=0;
				HeightSafeCtrl=g_YC_Package.TJ.GNSS_GPSAlt;
				}
			else
				{//高度异常
				SignForSafeHeight=1;
				}

			//-----------------近地快速放气---------------------------	
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
   0s---预点火打开，发3次，间隔100ms；
   1s---中部、前部主一致爆破，1s检查回传并最多发3次；
   5s --中部、前部备一致爆破，1s检查回传并最多发3次；
   10s -预点火关闭，发3次，间隔100ms。
 -----*/


DEF_UINT8	OnceSignForFastExploder=0;	//快速放气标志位，快速放气只执行一次，0为可执行状态
DEF_UINT8	Second01TransForData[DelayDataCount];
DEF_UINT8	iForSecond01Val=0;
/*--------快速放气(调用前请检查飞行模式是否处于降落模式)-------*/
void Balloon_FastExploder()
{
//检查快速放气标志位
if(OnceSignForFastExploder==0)
	{
	//预点火打开
	for(iForSecond01Val=1;iForSecond01Val<=4;iForSecond01Val++)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x22;
		Ballonet_CtrlSend(iForSecond01Val, 0x22, 0);
		CreateTimeDelayTask(0x0004, 100, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0004, 200, &(Second01TransForData[0]));
		}
	/*----------*/
	//主囊采一致爆破
	for(iForSecond01Val=1; iForSecond01Val<=4; iForSecond01Val=iForSecond01Val+2)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x2C;
		Second01TransForData[2]=2;
		CreateTimeDelayTask(0x0004, 1000, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0003, 2000, &(Second01TransForData[0]));
		}


	//备囊采一致爆破
	for(iForSecond01Val=2; iForSecond01Val<=4; iForSecond01Val=iForSecond01Val+2)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x2C;
		Second01TransForData[2]=2;
		CreateTimeDelayTask(0x0004, 5000, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0003, 6000, &(Second01TransForData[0]));	
		}


	// 预点火关闭
	for(iForSecond01Val=1;iForSecond01Val<=4;iForSecond01Val++)
		{
		Second01TransForData[0]=iForSecond01Val;
		Second01TransForData[1]=0x23;
		CreateTimeDelayTask(0x0004, 10000, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0004, 10100, &(Second01TransForData[0]));
		CreateTimeDelayTask(0x0004, 10200, &(Second01TransForData[0]));
		}
	
	//快速放气标志位置为1
	OnceSignForFastExploder=1;
	}
	
}





