/*========================================================================================*
 * FILE:                     	B_001SecondDelay.c                   
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
 #include "B_001SecondDelay.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/
 



_DEFSTRU_TaskDelayMsg TaskDelayMsg[DelayTaskMaxCount];
DEF_UINT8 iForCheck001Task=0;

DEF_UINT8 SignForTstDelTask=0;	//0-无任务，1-有任务
DEF_UINT8 CountForTstDelTask=0; //当前延时任务计数
/*-----------------延时0.01s  执行的任务-------------------------*/
void Task_B_001SecondDelay()
 {

 
 if(SignForTstDelTask!=0) //有任务
 	{
 	//任务个数计数置0
 	CountForTstDelTask=0;


	
	 for(iForCheck001Task=0;iForCheck001Task<DelayTaskMaxCount;iForCheck001Task++)
	 	{
	 	if(TaskDelayMsg[iForCheck001Task].Time>0)
	 		{
	 		CountForTstDelTask++;	//任务个数计数加1

			if(TaskDelayMsg[iForCheck001Task].Time==1)
				{
				switch(TaskDelayMsg[iForCheck001Task].TaskID)
					{
						case   0x0001:{TimeDelayTask_ID0001();break;}
						case   0x0002:{TimeDelayTask_ID0002();break;}
						case   0x0003:{TimeDelayTask_ID0003();break;}
						case   0x0004:{TimeDelayTask_ID0004();break;}
						case   0x0005:{TimeDelayTask_ID0005();break;}
						case   0x0006:{TimeDelayTask_ID0006();break;}
						case   0x0007:{TimeDelayTask_ID0007();break;}
						case   0x0008:{TimeDelayTask_ID0008();break;}

						default:break;
					}
				
				//清空任务ID
				TaskDelayMsg[iForCheck001Task].TaskID=0x0000;		
				}
			TaskDelayMsg[iForCheck001Task].Time--;	//时间计数自减
	 		}
	 	}

	if(CountForTstDelTask==0)
		{SignForTstDelTask=0;}	 //无任务，下次无需检测
		
 	} 

 }









DEF_UINT8 InPutDelayTask=0;
/*------------------创建延时执行任务, 输入:  1-任务代码，2-延时(单位ms)，3-任务参数(8个字节数组)---------------------*/
void CreateTimeDelayTask(DEF_UINT16 TaskID,  DEF_UINT16 Delayms,  DEF_UINT8 Group[])
{
TaskDelayMsg[InPutDelayTask].TaskID=TaskID;
TaskDelayMsg[InPutDelayTask].Time=(DEF_UINT16)(Delayms/10+1);	//  1ms转0.01s，到1时执行任务。

bcopy(&(Group[0]), &(TaskDelayMsg[InPutDelayTask].Data[0]), DelayDataCount);

InPutDelayTask=(InPutDelayTask+1)%DelayTaskMaxCount;

SignForTstDelTask=1;	//任务标记
}





//-----延时任务，ID =  0x0001
//	阀门开关, 0-采集器编号:    1-指令代码，2-阀门控制时间
void TimeDelayTask_ID0001()
{
if((TaskDelayMsg[iForCheck001Task].Data[0]>0)&&(TaskDelayMsg[iForCheck001Task].Data[0]<=4))
	{
	if((TaskDelayMsg[iForCheck001Task].Data[1]>=0x01)&&(TaskDelayMsg[iForCheck001Task].Data[1]<=0x09))
		{
		Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  TaskDelayMsg[iForCheck001Task].Data[2]);
		}
	}
}


//-----延时任务，ID =  0x0002
//	囊体单独爆破和阀门爆破任务:    0-采集器编号，1-指令代码
void TimeDelayTask_ID0002()
{
if((TaskDelayMsg[iForCheck001Task].Data[0]>0)&&(TaskDelayMsg[iForCheck001Task].Data[0]<=4))
	{
	if(((TaskDelayMsg[iForCheck001Task].Data[1]>=0x0A)&&(TaskDelayMsg[iForCheck001Task].Data[1]<=0x12))
		||((TaskDelayMsg[iForCheck001Task].Data[1]>=0x16)&&(TaskDelayMsg[iForCheck001Task].Data[1]<=0x1E)))
		{
		Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  0);
		}
	}
}




DEF_UINT8	SendEightForTimeDelay[DelayDataCount];
//-----延时任务，ID =  0x0003
//	检查采集器指令回传(一致爆破/预点火/工作休眠/北斗遥测下发):    0-采集器编号，1-待检查指令代码，2-检查次数(1\2...)
void TimeDelayTask_ID0003()
{
if((TaskDelayMsg[iForCheck001Task].Data[0]>0)&&(TaskDelayMsg[iForCheck001Task].Data[0]<=4))
	{
	//最多检查3次
	if(TaskDelayMsg[iForCheck001Task].Data[2]>3)
		{TaskDelayMsg[iForCheck001Task].Data[2]=3;}

	//----检查指令回传-----
	switch(TaskDelayMsg[iForCheck001Task].Data[1])
		{
		case 0x22:
		case 0x23:
		case 0x2A:
		case 0x2B:
		case 0x3E:
		case 0x3F:
					{
					if(g_YC_Package.NT.CommandTransBack[(TaskDelayMsg[iForCheck001Task].Data[0]-1)]!=TaskDelayMsg[iForCheck001Task].Data[1])
						{//再次发送，
						Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  0);

						if(TaskDelayMsg[iForCheck001Task].Data[2]>1)
							{
							TaskDelayMsg[iForCheck001Task].Data[2]=TaskDelayMsg[iForCheck001Task].Data[2]-1;
							bcopy(&(TaskDelayMsg[iForCheck001Task].Data[0]),&(SendEightForTimeDelay[0]),3);
							CreateTimeDelayTask(0x0003, 1000, &(SendEightForTimeDelay[0]));		//延时1s再次执行					
							}
						}
					break;
					}
			
		case 0x2C:	{
					if((g_YC_Package.NT.CommandTransBack[(TaskDelayMsg[iForCheck001Task].Data[0]-1)]!=0x2C)
						&&(g_YC_Package.NT.CommandTransBack[(TaskDelayMsg[iForCheck001Task].Data[0]-1)]!=0x2E)
						&&(g_YC_Package.NT.CommandTransBack[(TaskDelayMsg[iForCheck001Task].Data[0]-1)]!=0x30)
						&&(g_YC_Package.NT.CommandTransBack[(TaskDelayMsg[iForCheck001Task].Data[0]-1)]!=0x31))
						{
						//再次发送，
						Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  0);

						if(TaskDelayMsg[iForCheck001Task].Data[2]>1)
							{
							TaskDelayMsg[iForCheck001Task].Data[2]=TaskDelayMsg[iForCheck001Task].Data[2]-1;
							bcopy(&(TaskDelayMsg[iForCheck001Task].Data[0]),&(SendEightForTimeDelay[0]),3);
							CreateTimeDelayTask(0x0003, 1000, &(SendEightForTimeDelay[0]));		//延时1s再次执行	
							}
						}					
					break;
					}
		default:break;
		}
	}
}



//-----延时任务，ID =  0x0004
//	囊体采集器指令发送(一致爆破/预点火/工作休眠/北斗遥测下发):   0-采集器编号，1-指令代码
void TimeDelayTask_ID0004()
{
if((TaskDelayMsg[iForCheck001Task].Data[0]>0)&&(TaskDelayMsg[iForCheck001Task].Data[0]<=4))
	{
	if((TaskDelayMsg[iForCheck001Task].Data[1]==0x22)
	||(TaskDelayMsg[iForCheck001Task].Data[1]==0x23)
	||(TaskDelayMsg[iForCheck001Task].Data[1]==0x2A)
	||(TaskDelayMsg[iForCheck001Task].Data[1]==0x2B)
	||(TaskDelayMsg[iForCheck001Task].Data[1]==0x2C)
	||(TaskDelayMsg[iForCheck001Task].Data[1]==0x3E)
	||(TaskDelayMsg[iForCheck001Task].Data[1]==0x3F))		
		{
		Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  0);
		}
	}
}




//-----延时任务，ID =  0x0005
//	:    0-，1-，2-
void TimeDelayTask_ID0005()
{



}








//-----延时任务，ID =  0x0006
//	:    0-，1-，2-
void TimeDelayTask_ID0006()
{




}



//-----延时任务，ID =  0x0007
//	:    0-，1-，2-
void TimeDelayTask_ID0007()
{




}


//-----延时任务，ID =  0x0008
//	:    0-，1-，2-
void TimeDelayTask_ID0008()
{




}















