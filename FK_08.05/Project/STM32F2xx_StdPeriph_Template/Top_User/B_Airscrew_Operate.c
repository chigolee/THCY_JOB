/*========================================================================================*
 * FILE:                     	B_Airscrew_Operate.c                   
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
 #include "B_Airscrew_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/
 

_DEFSTRU_AirscrewRecivePacage	TransforAirscrew;
//推进电机数据接收,输入为(电机号)    1、2、3、4、5。
void Task_Airscrew_Recieve(DEF_UINT8 Numb)
{
//结构体数据清零
	TransforAirscrew.Head1=0;TransforAirscrew.Head2=0;TransforAirscrew.Checksum=0;

//判断读哪个电机的数据
	switch(Numb)
	{//数据接收转存TransforAirscrew ,  超时计数置0
	case 1:	{if(UBRxFBufPo!=UBRxFBufPi){bcopy(&(UBRxFBuf[UBRxFBufPo][0]),&(TransforAirscrew),16);UBRxFBufPo=(UBRxFBufPo+1)%UB_RxF_BufLen;DelaySecond_Healthy[1][0]=0;} break;}
	case 2:	{if(UCRxFBufPo!=UCRxFBufPi){bcopy(&(UCRxFBuf[UCRxFBufPo][0]),&(TransforAirscrew),16);UCRxFBufPo=(UCRxFBufPo+1)%UC_RxF_BufLen;DelaySecond_Healthy[1][1]=0;} break;}
	case 3:	{if(UDRxFBufPo!=UDRxFBufPi){bcopy(&(UDRxFBuf[UDRxFBufPo][0]),&(TransforAirscrew),16);UDRxFBufPo=(UDRxFBufPo+1)%UD_RxF_BufLen;DelaySecond_Healthy[1][2]=0;} break;}
	case 4:	{if(UERxFBufPo!=UERxFBufPi){bcopy(&(UERxFBuf[UERxFBufPo][0]),&(TransforAirscrew),16);UERxFBufPo=(UERxFBufPo+1)%UE_RxF_BufLen;DelaySecond_Healthy[1][3]=0;} break;}
	case 5:	{if(UFRxFBufPo!=UFRxFBufPi){bcopy(&(UFRxFBuf[UFRxFBufPo][0]),&(TransforAirscrew),16);UFRxFBufPo=(UFRxFBufPo+1)%UF_RxF_BufLen;DelaySecond_Healthy[1][7]=0;} break;}

	default: break;	
			}	


//判断字头1、2、校验和
	if((TransforAirscrew.Head1==0xEB)&&(TransforAirscrew.Head2==0x90)&&(TransforAirscrew.Checksum==(AddSum1(((DEF_UINT8*)(&TransforAirscrew)),15))))
		{
		g_YC_Package.TJ.AirscrewState[Numb-1]=TransforAirscrew.AirscrewState;
		g_YC_Package.TJ.AirscrewCurrent[Numb-1]=TransforAirscrew.AirscrewCurrent;
		g_YC_Package.TJ.AirscrewMainwireVol[Numb-1]=TransforAirscrew.AirscrewMainwireVol;
		g_YC_Package.TJ.AirscrewRadiatorDutyRatio[Numb-1]=TransforAirscrew.AirscrewRadiatorDutyRatio;
		g_YC_Package.TJ.AirscrewActualN[Numb-1]=(TransforAirscrew.AirscrewActualN_High)*256+(TransforAirscrew.AirscrewActualN_Low);		

		if(Numb<5)
			{
			g_YCLowPack.JC01.AirscrewCrustTemp[Numb-1]=TransforAirscrew.AirscrewCrustTemp;
			g_YCLowPack.JC01.AirscrewRadiatorTemp[Numb-1][0]=TransforAirscrew.AirscrewRadiatorTemp[0];
			g_YCLowPack.JC01.AirscrewRadiatorTemp[Numb-1][1]=TransforAirscrew.AirscrewRadiatorTemp[1];		
			}
		
		else
			{
			g_YCLowPack.JC01.VecAirscrewCrustTemp=TransforAirscrew.AirscrewRadiatorTemp[1];
			g_YCLowPack.JC01.VecAirscrewRadiatorTemp=TransforAirscrew.AirscrewRadiatorTemp[0];
			}

		}

}






_DEFSTRU_AirscrewCtrlSend	AirscrewCtrlSend;

/*   2-指令:   0x0B-速度，0x0C-停止，0x0D-启动。    */
/*----------推进电机---遥控指令发送( 1-电机编号(推进1~4,前部风扇5);     2-指令;     3-转速r/min. )  -----------*/
void Airscrew_CtrlSend(DEF_UINT8 Numb,  DEF_UINT8 Comand, DEF_UINT16 Speed)
{
if(Numb<=5)
	{
//数据头清零
	AirscrewCtrlSend.Head1=0x00;
	
	if(Comand==0x0B)		//转速控制
		{
		if(TestByteBit((g_YC_Package.TJ.AirscrewCtrlState), (Numb-1))==0x01)		//可控转速
			{
			if(Numb<=4)
				{
				if(Speed>(g_YC_Package.TJ.PropellerN_Limit))
					{Speed=g_YC_Package.TJ.PropellerN_Limit;}	//限幅
				}
			else
				if(Speed>(g_YC_Package.TJ.FrontPropelN_Limit))
					{Speed=g_YC_Package.TJ.FrontPropelN_Limit;}	//限幅						
			g_YC_Package.TJ.AirscrewCtrlN[Numb-1]=Speed;		//填写控制反馈值
			
			//填写指令
			AirscrewCtrlSend.Head1=0xEB;
			AirscrewCtrlSend.Head2=0x90;
			AirscrewCtrlSend.Flag=0x0B;
			AirscrewCtrlSend.CtrlByte1=Speed&0x00FF;
			AirscrewCtrlSend.CtrlByte2=(Speed>>8)&0x00FF;
			AirscrewCtrlSend.Checksum=AddSum1((DEF_UINT8*)(&(AirscrewCtrlSend.Head1)),5);
			}
		}
	
	else if(Comand==0x0C)		//停止控制
		{
		g_YC_Package.TJ.AirscrewCtrlState=SetByteBit((g_YC_Package.TJ.AirscrewCtrlState),(Numb-1),0);
		g_YC_Package.TJ.AirscrewCtrlN[Numb-1]=0;		//填写控制反馈值
		//填写指令
		AirscrewCtrlSend.Head1=0xEB;
		AirscrewCtrlSend.Head2=0x90;
		AirscrewCtrlSend.Flag=0x0C;
		AirscrewCtrlSend.CtrlByte1=0x0C;
		AirscrewCtrlSend.CtrlByte2=0x0C;
		AirscrewCtrlSend.Checksum=AddSum1((DEF_UINT8*)(&(AirscrewCtrlSend.Head1)),5);
		}

	else if(Comand==0x0D)		//启动控制
		{
		g_YC_Package.TJ.AirscrewCtrlState=SetByteBit((g_YC_Package.TJ.AirscrewCtrlState),(Numb-1),1);	//只填软控制位，不填控制帧输出
		}	
	

//控制输出
	if(AirscrewCtrlSend.Head1==0xEB)
		{
		switch(Numb)
			{
			case 1:	{{UBInTxBuf((U8*)&AirscrewCtrlSend,6);}break;}
			case 2:	{{UCInTxBuf((U8*)&AirscrewCtrlSend,6);}break;}
			case 3:	{{UDInTxBuf((U8*)&AirscrewCtrlSend,6);}break;}
			case 4:	{{UEInTxBuf((U8*)&AirscrewCtrlSend,6);}break;}
			case 5:	{{UFInTxBuf((U8*)&AirscrewCtrlSend,6);}break;}

			default: break;			
			}		
		}
	
	}
}





