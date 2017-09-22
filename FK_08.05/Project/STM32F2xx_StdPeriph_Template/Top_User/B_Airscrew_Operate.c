/*========================================================================================*
 * FILE:                     	B_Airscrew_Operate.c                   
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
 #include "B_Airscrew_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/
 

_DEFSTRU_AirscrewRecivePacage	TransforAirscrew;
//�ƽ�������ݽ���,����Ϊ(�����)    1��2��3��4��5��
void Task_Airscrew_Recieve(DEF_UINT8 Numb)
{
//�ṹ����������
	TransforAirscrew.Head1=0;TransforAirscrew.Head2=0;TransforAirscrew.Checksum=0;

//�ж϶��ĸ����������
	switch(Numb)
	{//���ݽ���ת��TransforAirscrew ,  ��ʱ������0
	case 1:	{if(UBRxFBufPo!=UBRxFBufPi){bcopy(&(UBRxFBuf[UBRxFBufPo][0]),&(TransforAirscrew),16);UBRxFBufPo=(UBRxFBufPo+1)%UB_RxF_BufLen;DelaySecond_Healthy[1][0]=0;} break;}
	case 2:	{if(UCRxFBufPo!=UCRxFBufPi){bcopy(&(UCRxFBuf[UCRxFBufPo][0]),&(TransforAirscrew),16);UCRxFBufPo=(UCRxFBufPo+1)%UC_RxF_BufLen;DelaySecond_Healthy[1][1]=0;} break;}
	case 3:	{if(UDRxFBufPo!=UDRxFBufPi){bcopy(&(UDRxFBuf[UDRxFBufPo][0]),&(TransforAirscrew),16);UDRxFBufPo=(UDRxFBufPo+1)%UD_RxF_BufLen;DelaySecond_Healthy[1][2]=0;} break;}
	case 4:	{if(UERxFBufPo!=UERxFBufPi){bcopy(&(UERxFBuf[UERxFBufPo][0]),&(TransforAirscrew),16);UERxFBufPo=(UERxFBufPo+1)%UE_RxF_BufLen;DelaySecond_Healthy[1][3]=0;} break;}
	case 5:	{if(UFRxFBufPo!=UFRxFBufPi){bcopy(&(UFRxFBuf[UFRxFBufPo][0]),&(TransforAirscrew),16);UFRxFBufPo=(UFRxFBufPo+1)%UF_RxF_BufLen;DelaySecond_Healthy[1][7]=0;} break;}

	default: break;	
			}	


//�ж���ͷ1��2��У���
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

/*   2-ָ��:   0x0B-�ٶȣ�0x0C-ֹͣ��0x0D-������    */
/*----------�ƽ����---ң��ָ���( 1-������(�ƽ�1~4,ǰ������5);     2-ָ��;     3-ת��r/min. )  -----------*/
void Airscrew_CtrlSend(DEF_UINT8 Numb,  DEF_UINT8 Comand, DEF_UINT16 Speed)
{
if(Numb<=5)
	{
//����ͷ����
	AirscrewCtrlSend.Head1=0x00;
	
	if(Comand==0x0B)		//ת�ٿ���
		{
		if(TestByteBit((g_YC_Package.TJ.AirscrewCtrlState), (Numb-1))==0x01)		//�ɿ�ת��
			{
			if(Numb<=4)
				{
				if(Speed>(g_YC_Package.TJ.PropellerN_Limit))
					{Speed=g_YC_Package.TJ.PropellerN_Limit;}	//�޷�
				}
			else
				if(Speed>(g_YC_Package.TJ.FrontPropelN_Limit))
					{Speed=g_YC_Package.TJ.FrontPropelN_Limit;}	//�޷�						
			g_YC_Package.TJ.AirscrewCtrlN[Numb-1]=Speed;		//��д���Ʒ���ֵ
			
			//��дָ��
			AirscrewCtrlSend.Head1=0xEB;
			AirscrewCtrlSend.Head2=0x90;
			AirscrewCtrlSend.Flag=0x0B;
			AirscrewCtrlSend.CtrlByte1=Speed&0x00FF;
			AirscrewCtrlSend.CtrlByte2=(Speed>>8)&0x00FF;
			AirscrewCtrlSend.Checksum=AddSum1((DEF_UINT8*)(&(AirscrewCtrlSend.Head1)),5);
			}
		}
	
	else if(Comand==0x0C)		//ֹͣ����
		{
		g_YC_Package.TJ.AirscrewCtrlState=SetByteBit((g_YC_Package.TJ.AirscrewCtrlState),(Numb-1),0);
		g_YC_Package.TJ.AirscrewCtrlN[Numb-1]=0;		//��д���Ʒ���ֵ
		//��дָ��
		AirscrewCtrlSend.Head1=0xEB;
		AirscrewCtrlSend.Head2=0x90;
		AirscrewCtrlSend.Flag=0x0C;
		AirscrewCtrlSend.CtrlByte1=0x0C;
		AirscrewCtrlSend.CtrlByte2=0x0C;
		AirscrewCtrlSend.Checksum=AddSum1((DEF_UINT8*)(&(AirscrewCtrlSend.Head1)),5);
		}

	else if(Comand==0x0D)		//��������
		{
		g_YC_Package.TJ.AirscrewCtrlState=SetByteBit((g_YC_Package.TJ.AirscrewCtrlState),(Numb-1),1);	//ֻ�������λ���������֡���
		}	
	

//�������
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





