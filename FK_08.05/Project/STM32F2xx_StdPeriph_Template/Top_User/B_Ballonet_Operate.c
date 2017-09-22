/*========================================================================================*
 * FILE:                     	B_Ballonet_Operate.c                   
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
 #include "B_Ballonet_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/
 
DEF_UINT8	SignForBDReiceive=0xAA;		//0,1-��Ч��������Ч��
DEF_UINT8 	ByteCoForNTCJ=0;
DEF_UINT8	Ballonet_Data_Recieve[120];	//����ɼ�����ȫ������
DEF_UINT8	XorSumFromBD=0;

DEF_UINT8	CountForComa=0;	//����������
DEF_UINT8	iForReadBDByte;		//�����������ֽڼ���
DEF_UINT8	StringPosComa[MaxTransComaCount];		//����λ�ü�¼
DEF_UINT8	BDAsclTransState=1;
DEF_FLOAT32	BDTransFloat=0;

_DEFSTRU_BallColRecivePacage	BallColReciPacage;
DEF_UINT8	iForBallColTempra=0;
DEF_UINT16	Y_ForBallColPressure=0;
DEF_UINT16	A_ForBallColPressure=0;






/*----------����ɼ����ݽ��գ�����Ϊ�ɼ�����1~4  -----------*/
void Task_Ballonet_Operate(DEF_UINT8 Collector_NO)
{
}







/*--- 1~4 ��Ӧ:  1����1�ӣ�2����2��---*/
//  0x01-������(��)��
//  0x02-�ط���(��)��
//  0x03-������(��λ1)��
//  0x04-�ط���(��λ1)��
//  0x05-�ط���(��λ��)��
//  0x06-�ط���(��λ2)��
//  0x07-������(�޵�λ)��
//  0x08-�ط���(�޵�λ)��
//  0x09-ֹͣ��

//  0x0A-1·��𿪣�	0x16-1·���أ�
//  0x0B-2·��𿪣�	0x17-2·���أ�
//  0x0C-3·��𿪣�	0x18-3·���أ�
//  0x0D-4·��𿪣�	0x19-4·���أ�
//  0x0E-5·��𿪣�	0x1A-5·���أ�
//  0x0F-6·��𿪣�	0x1B-6·���أ�
//  0x10-7·��𿪣�	0x1C-7·���أ�
//  0x11-8·��𿪣�	0x1D-8·���أ�
//  0x12-�����и�1����0x1E-�����и�1�أ�

//  0x22-Ԥ��𿪣�		0x23-Ԥ���أ�
//  0x2A-������			0x2B-���ߣ�
//  0x2C-���屬��1234��
//  0x3E-ң�ⶨʱ�·�ֹͣ��  0x3F-ң�ⶨʱ�·�������

_DEFSTRU_BallCoCtrlSend	BallCoCtrlSend;
DEF_UINT8	Ballonet_CtrlTime;
/*----------����ɼ�ң��ָ���( 1-�ɼ�����(1~4);     2-ָ��;     3-����ʱ��0.1s  . )  -----------*/
void Ballonet_CtrlSend(DEF_UINT8 Collector_NO,  DEF_UINT8 Comand, DEF_UINT8 Time)
{
BallCoCtrlSend.head[0]=0xCC;
BallCoCtrlSend.head[1]=0xEE;
BallCoCtrlSend.StaticByte=0x11;

BallCoCtrlSend.Command[0]=Comand;
BallCoCtrlSend.Command[1]=Comand;
BallCoCtrlSend.Command[2]=Comand;

//���ſ���ʱ��������1.0~20.0s   ��
if(Comand<0x0A)
	{
	if(Time<10)
		{Ballonet_CtrlTime=10;}
	else if(Time>200)
		{Ballonet_CtrlTime=200;}
	else
		{Ballonet_CtrlTime=Time;}
	}
else
	{Ballonet_CtrlTime=Time;}

BallCoCtrlSend.ValveCtrlTime[0]=Ballonet_CtrlTime;
BallCoCtrlSend.ValveCtrlTime[1]=Ballonet_CtrlTime;

BallCoCtrlSend.CommandVert[0]=~Comand;
BallCoCtrlSend.CommandVert[1]=~Comand;
BallCoCtrlSend.CommandVert[2]=~Comand;

BallCoCtrlSend.Checksum=AddSum1((DEF_UINT8*)&(BallCoCtrlSend.StaticByte),11);

BallCoCtrlSend.end[0]=0x55;
BallCoCtrlSend.end[1]=0xAA;

switch(Collector_NO)
	{
	case 1:	{{U5InTxBuf((U8*)&(BallCoCtrlSend),16);}break;}
	case 2:	{{U6InTxBuf((U8*)&(BallCoCtrlSend),16);}break;}
	case 3:	{{U7InTxBuf((U8*)&(BallCoCtrlSend),16);}break;}
	case 4:	{{U8InTxBuf((U8*)&(BallCoCtrlSend),16);}break;}

	default: break;			
	}

}









 /*��� У���----���Ϊ���ֽ�,����Ϊ  (�׸��ֽڵ�ַ,�ֽڸ���)    */
DEF_UINT8 XorSum1(DEF_UINT8 *start , DEF_UINT8 count)
 	{
 	DEF_UINT8 xorsum1=start[0];
	DEF_UINT8 ifor_xorsum1=0;

	for(ifor_xorsum1=1;ifor_xorsum1<count;ifor_xorsum1++)
		{
		xorsum1=xorsum1^(start[ifor_xorsum1]);
		}

	return xorsum1;
	
 	}




/*---------��ASCLL��ת��Ϊ������, ת����ȷ�򷵻ظ�������ͬʱ״̬��Ϊ0��    ���������󣬷���ֵΪ-1��״̬����Ϊ1------------*/
/*------������壺1-Ascll������ָ�룬2-ת��״̬�ֽ�ָ��---------------*/
DEF_FLOAT32	TransAscllToFloat(DEF_UINT8* Ascll, DEF_UINT8*TansState)
{
DEF_UINT8	i_Byte;
DEF_FLOAT32	Number=0;
DEF_FLOAT32	Sign=1;
DEF_UINT8	DotPos=0xFF;	//С����λ��
DEF_UINT8	ComaPos=0xFF;	//����λ��
TansState[0]=1;	//����ת��״̬Ĭ����Ϊ1


//�鿴��һ���ַ��Ƿ�Ϊ������
if(Ascll[0]==0x2B)
	{
	Sign=1;
	Ascll=(DEF_UINT8*)&(Ascll[1]);
	}
else if(Ascll[0]==0x2D)
	{
	Sign=-1;
	Ascll=(DEF_UINT8*)&(Ascll[1]);
	}

//�Ϸ��Լ���С����λ�ü��
for(i_Byte=0;i_Byte<MaxTransAscllCount;i_Byte++)
	{
	if((Ascll[i_Byte]>0x2F)&&(Ascll[i_Byte]<0x3A))	//
		{
		continue;
		}
	else if(Ascll[i_Byte]==0x2E)
		{
		if(DotPos==0xFF)	
			{DotPos=i_Byte;}
		else		//�����˵ڶ���С���㣬����
			{TansState[0]=1;	return -1;}	
		}
	else if(Ascll[i_Byte]==0x2C)	//���ֶ��ţ�����
		{
		ComaPos=i_Byte;
		break;
		}
	else		//��������Ҳ����С���㣬����
		{TansState[0]=1;	return -1;}		
	}

if(ComaPos==0)	//��һ������Ϊ���ţ�����0
	{TansState[0]=0;  return 0;}	//����ת��״̬��Ϊ����
else if(ComaPos==0xFF)	//û���ֶ��ţ���������
	{TansState[0]=1;	return -1;}


//�����ַ�ת��
Number=0;

//��С����
if(DotPos==0xFF)
	{
	for(i_Byte=0;i_Byte<ComaPos;i_Byte++)
		{Number=Number+(Ascll[i_Byte]-0x30)*pow(10,(ComaPos-i_Byte-1));}
	}
else
	{
	//��С����
	for(i_Byte=0;i_Byte<DotPos;i_Byte++)
		{Number=Number+(Ascll[i_Byte]-0x30)*pow(10,(DotPos-i_Byte-1));}
	for(i_Byte=DotPos+1;i_Byte<ComaPos;i_Byte++)
		{Number=Number+(Ascll[i_Byte]-0x30)*pow(10,(DotPos-i_Byte));}
	}

Number=Number*Sign;

TansState[0]=0;		//����ת��״̬��Ϊ����
return Number;
}



