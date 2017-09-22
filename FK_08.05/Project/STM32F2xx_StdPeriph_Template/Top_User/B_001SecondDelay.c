/*========================================================================================*
 * FILE:                     	B_001SecondDelay.c                   
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
 #include "B_001SecondDelay.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/
 



_DEFSTRU_TaskDelayMsg TaskDelayMsg[DelayTaskMaxCount];
DEF_UINT8 iForCheck001Task=0;

DEF_UINT8 SignForTstDelTask=0;	//0-������1-������
DEF_UINT8 CountForTstDelTask=0; //��ǰ��ʱ�������
/*-----------------��ʱ0.01s  ִ�е�����-------------------------*/
void Task_B_001SecondDelay()
 {

 
 if(SignForTstDelTask!=0) //������
 	{
 	//�������������0
 	CountForTstDelTask=0;


	
	 for(iForCheck001Task=0;iForCheck001Task<DelayTaskMaxCount;iForCheck001Task++)
	 	{
	 	if(TaskDelayMsg[iForCheck001Task].Time>0)
	 		{
	 		CountForTstDelTask++;	//�������������1

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
				
				//�������ID
				TaskDelayMsg[iForCheck001Task].TaskID=0x0000;		
				}
			TaskDelayMsg[iForCheck001Task].Time--;	//ʱ������Լ�
	 		}
	 	}

	if(CountForTstDelTask==0)
		{SignForTstDelTask=0;}	 //�������´�������
		
 	} 

 }









DEF_UINT8 InPutDelayTask=0;
/*------------------������ʱִ������, ����:  1-������룬2-��ʱ(��λms)��3-�������(8���ֽ�����)---------------------*/
void CreateTimeDelayTask(DEF_UINT16 TaskID,  DEF_UINT16 Delayms,  DEF_UINT8 Group[])
{
TaskDelayMsg[InPutDelayTask].TaskID=TaskID;
TaskDelayMsg[InPutDelayTask].Time=(DEF_UINT16)(Delayms/10+1);	//  1msת0.01s����1ʱִ������

bcopy(&(Group[0]), &(TaskDelayMsg[InPutDelayTask].Data[0]), DelayDataCount);

InPutDelayTask=(InPutDelayTask+1)%DelayTaskMaxCount;

SignForTstDelTask=1;	//������
}





//-----��ʱ����ID =  0x0001
//	���ſ���, 0-�ɼ������:    1-ָ����룬2-���ſ���ʱ��
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


//-----��ʱ����ID =  0x0002
//	���嵥�����ƺͷ��ű�������:    0-�ɼ�����ţ�1-ָ�����
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
//-----��ʱ����ID =  0x0003
//	���ɼ���ָ��ش�(һ�±���/Ԥ���/��������/����ң���·�):    0-�ɼ�����ţ�1-�����ָ����룬2-������(1\2...)
void TimeDelayTask_ID0003()
{
if((TaskDelayMsg[iForCheck001Task].Data[0]>0)&&(TaskDelayMsg[iForCheck001Task].Data[0]<=4))
	{
	//�����3��
	if(TaskDelayMsg[iForCheck001Task].Data[2]>3)
		{TaskDelayMsg[iForCheck001Task].Data[2]=3;}

	//----���ָ��ش�-----
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
						{//�ٴη��ͣ�
						Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  0);

						if(TaskDelayMsg[iForCheck001Task].Data[2]>1)
							{
							TaskDelayMsg[iForCheck001Task].Data[2]=TaskDelayMsg[iForCheck001Task].Data[2]-1;
							bcopy(&(TaskDelayMsg[iForCheck001Task].Data[0]),&(SendEightForTimeDelay[0]),3);
							CreateTimeDelayTask(0x0003, 1000, &(SendEightForTimeDelay[0]));		//��ʱ1s�ٴ�ִ��					
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
						//�ٴη��ͣ�
						Ballonet_CtrlSend(TaskDelayMsg[iForCheck001Task].Data[0],  TaskDelayMsg[iForCheck001Task].Data[1],  0);

						if(TaskDelayMsg[iForCheck001Task].Data[2]>1)
							{
							TaskDelayMsg[iForCheck001Task].Data[2]=TaskDelayMsg[iForCheck001Task].Data[2]-1;
							bcopy(&(TaskDelayMsg[iForCheck001Task].Data[0]),&(SendEightForTimeDelay[0]),3);
							CreateTimeDelayTask(0x0003, 1000, &(SendEightForTimeDelay[0]));		//��ʱ1s�ٴ�ִ��	
							}
						}					
					break;
					}
		default:break;
		}
	}
}



//-----��ʱ����ID =  0x0004
//	����ɼ���ָ���(һ�±���/Ԥ���/��������/����ң���·�):   0-�ɼ�����ţ�1-ָ�����
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




//-----��ʱ����ID =  0x0005
//	:    0-��1-��2-
void TimeDelayTask_ID0005()
{



}








//-----��ʱ����ID =  0x0006
//	:    0-��1-��2-
void TimeDelayTask_ID0006()
{




}



//-----��ʱ����ID =  0x0007
//	:    0-��1-��2-
void TimeDelayTask_ID0007()
{




}


//-----��ʱ����ID =  0x0008
//	:    0-��1-��2-
void TimeDelayTask_ID0008()
{




}















