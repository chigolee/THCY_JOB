/*========================================================================================*
 * FILE:                     	B_Ballonet_Operate.c                   
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
 #include "B_Ballonet_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/
 
DEF_UINT8	SignForBDReiceive=0xAA;		//0,1-有效，其余无效。
DEF_UINT8 	ByteCoForNTCJ=0;
DEF_UINT8	Ballonet_Data_Recieve[120];	//囊体采集接收全部数据
DEF_UINT8	XorSumFromBD=0;

DEF_UINT8	CountForComa=0;	//读到逗号数
DEF_UINT8	iForReadBDByte;		//读北斗数据字节计数
DEF_UINT8	StringPosComa[MaxTransComaCount];		//逗号位置记录
DEF_UINT8	BDAsclTransState=1;
DEF_FLOAT32	BDTransFloat=0;

_DEFSTRU_BallColRecivePacage	BallColReciPacage;
DEF_UINT8	iForBallColTempra=0;
DEF_UINT16	Y_ForBallColPressure=0;
DEF_UINT16	A_ForBallColPressure=0;






/*----------囊体采集数据接收，输入为采集器号1~4  -----------*/
void Task_Ballonet_Operate(DEF_UINT8 Collector_NO)
 {
//接收缓存清零
SignForBDReiceive=0x55;
ByteCoForNTCJ=0;
Ballonet_Data_Recieve[0]=0;
Ballonet_Data_Recieve[1]=0;

//根据采集器编号，到相应缓存中读取数据Ballonet_Data_Recieve[]
switch(Collector_NO)
	{
	case 1:	{if(U5RxFBufPo!=U5RxFBufPi){SignForBDReiceive=0;ByteCoForNTCJ=U5RxFBuf[U5RxFBufPo][U5_RxF_Len];if(ByteCoForNTCJ>U5_RxF_Len){ByteCoForNTCJ=U5_RxF_Len;}bcopy(&(U5RxFBuf[U5RxFBufPo][0]),&(Ballonet_Data_Recieve[0]),ByteCoForNTCJ);U5RxFBufPo=(U5RxFBufPo+1)%U5_RxF_BufLen;}break;}
	case 2:	{if(U6RxFBufPo!=U6RxFBufPi){SignForBDReiceive=0x55;ByteCoForNTCJ=U6RxFBuf[U6RxFBufPo][U6_RxF_Len];if(ByteCoForNTCJ>U6_RxF_Len){ByteCoForNTCJ=U6_RxF_Len;}bcopy(&(U6RxFBuf[U6RxFBufPo][0]),&(Ballonet_Data_Recieve[0]),ByteCoForNTCJ);U6RxFBufPo=(U6RxFBufPo+1)%U6_RxF_BufLen;}break;}
	case 3:	{if(U7RxFBufPo!=U7RxFBufPi){SignForBDReiceive=1;ByteCoForNTCJ=U7RxFBuf[U7RxFBufPo][U7_RxF_Len];if(ByteCoForNTCJ>U7_RxF_Len){ByteCoForNTCJ=U7_RxF_Len;}bcopy(&(U7RxFBuf[U7RxFBufPo][0]),&(Ballonet_Data_Recieve[0]),ByteCoForNTCJ);U7RxFBufPo=(U7RxFBufPo+1)%U7_RxF_BufLen;}break;}
	case 4:	{if(U8RxFBufPo!=U8RxFBufPi){SignForBDReiceive=0x55;ByteCoForNTCJ=U8RxFBuf[U8RxFBufPo][U8_RxF_Len];if(ByteCoForNTCJ>U8_RxF_Len){ByteCoForNTCJ=U8_RxF_Len;}bcopy(&(U8RxFBuf[U8RxFBufPo][0]),&(Ballonet_Data_Recieve[0]),ByteCoForNTCJ);U8RxFBufPo=(U8RxFBufPo+1)%U8_RxF_BufLen;}break;}

	default: break;			
	}

// 1-北斗数据
if((Ballonet_Data_Recieve[0]==U_5678_BDStart)&&(SignForBDReiceive<=1))
	{
	//校验
	XorSumFromBD=0;
	if(Ballonet_Data_Recieve[ByteCoForNTCJ-4]<0x3A)	//数字
		{XorSumFromBD=XorSumFromBD+(Ballonet_Data_Recieve[ByteCoForNTCJ-4]-0x30)*0x10;}
	else //字母
		{XorSumFromBD=XorSumFromBD+(Ballonet_Data_Recieve[ByteCoForNTCJ-4]-0x37)*0x10;}

	if(Ballonet_Data_Recieve[ByteCoForNTCJ-3]<0x3A)	//数字
		{XorSumFromBD=XorSumFromBD+Ballonet_Data_Recieve[ByteCoForNTCJ-3]-0x30;}
	else //字母
		{XorSumFromBD=XorSumFromBD+Ballonet_Data_Recieve[ByteCoForNTCJ-3]-0x37;}

	if(XorSumFromBD==XorSum1(&(Ballonet_Data_Recieve[1]),(ByteCoForNTCJ-6)))
		{		
		CountForComa=0;		//读到逗号数置零
		for(iForReadBDByte=0;iForReadBDByte<ByteCoForNTCJ;iForReadBDByte++)
			{
			if(Ballonet_Data_Recieve[iForReadBDByte]==0x2C)
				{
				StringPosComa[CountForComa]=iForReadBDByte;
				CountForComa++;				
				if(CountForComa>=MaxTransComaCount){break;}
				}		
			}

		if(CountForComa==MaxTransComaCount)
			{
			DelaySecond_Healthy[0][6+SignForBDReiceive]=0;		//北斗超时计数置零
			//处理并存入遥测帧
			BDTransFloat=TransAscllToFloat((DEF_UINT8*)&(Ballonet_Data_Recieve[(StringPosComa[6]+1)]), &BDAsclTransState);
			if(BDAsclTransState==0){g_YC_Package.NT.BD_SatelitNum[SignForBDReiceive]=(DEF_INT32)(BDTransFloat);}

			BDTransFloat=TransAscllToFloat((DEF_UINT8*)&(Ballonet_Data_Recieve[(StringPosComa[8]+1)]), &BDAsclTransState);
			if(BDAsclTransState==0){g_YC_Package.NT.BD_Alt[SignForBDReiceive]=(DEF_INT32)(BDTransFloat);}

			BDTransFloat=TransAscllToFloat((DEF_UINT8*)&(Ballonet_Data_Recieve[(StringPosComa[3]+4)]), &BDAsclTransState);
			if(BDAsclTransState==0){g_YC_Package.NT.BD_Lon[SignForBDReiceive]=(Ballonet_Data_Recieve[(StringPosComa[3])+1]-0x30)*100+(Ballonet_Data_Recieve[(StringPosComa[3])+2]-0x30)*10+(Ballonet_Data_Recieve[(StringPosComa[3])+3]-0x30)+(BDTransFloat)/60;}

			BDTransFloat=TransAscllToFloat((DEF_UINT8*)&(Ballonet_Data_Recieve[(StringPosComa[1]+3)]), &BDAsclTransState);
			if(BDAsclTransState==0){g_YC_Package.NT.BD_Lat[SignForBDReiceive]=(Ballonet_Data_Recieve[(StringPosComa[1])+1]-0x30)*10+(Ballonet_Data_Recieve[(StringPosComa[1])+2]-0x30)+(BDTransFloat)/60;}

			BDTransFloat=TransAscllToFloat((DEF_UINT8*)&(Ballonet_Data_Recieve[(StringPosComa[5]+1)]), &BDAsclTransState);
			if(BDAsclTransState==0){g_YC_Package.NT.BD_state[SignForBDReiceive]=(DEF_INT32)(BDTransFloat);}

			}
		}
	}

// 2-采集器数据
else if((Ballonet_Data_Recieve[0]==U_5678_DH0)&&(Ballonet_Data_Recieve[1]==U_5678_DH1))
	{
	//校验
	if(	((Collector_NO==1)&&(Ballonet_Data_Recieve[2]%2==0))||
		((Collector_NO==2)&&(Ballonet_Data_Recieve[2]%2==1))||
		((Collector_NO==3)&&(Ballonet_Data_Recieve[2]%2==0))||
		((Collector_NO==4)&&(Ballonet_Data_Recieve[2]%2==1)))
		{
		bcopy(&(Ballonet_Data_Recieve[0]),(DEF_UINT8*)&BallColReciPacage,sizeof(BallColReciPacage));
		if(BallColReciPacage.XorChecksum==XorSum1((DEF_UINT8*)&(BallColReciPacage.FrameHead1),41))
			{
			DelaySecond_Healthy[2][3+Collector_NO]=0;	//超时计数置0

	//处理-高低字节转换，高4位置0
			BallColReciPacage.BoardTem=ChangeWordByte((DEF_UINT16)(BallColReciPacage.BoardTem))&0x0FFF;
			
			BallColReciPacage.Pressure=ChangeWordByte((DEF_UINT16)(BallColReciPacage.Pressure))&0x0FFF;
			Y_ForBallColPressure=(((DEF_UINT16)BallColReciPacage.Parameter_1)<<8)|(((DEF_UINT16)BallColReciPacage.Parameter_2));
			Y_ForBallColPressure=Y_ForBallColPressure&0x0FFF;
			A_ForBallColPressure=1224-(((DEF_UINT8)BallColReciPacage.Parameter_1)>>4);
			
			BallColReciPacage.Vol28V=ChangeWordByte((DEF_UINT16)(BallColReciPacage.Vol28V))&0x0FFF;
			BallColReciPacage.Vol16V=ChangeWordByte((DEF_UINT16)(BallColReciPacage.Vol16V))&0x0FFF;
			BallColReciPacage.ValveCurrent=ChangeWordByte((DEF_UINT16)(BallColReciPacage.ValveCurrent))&0x0FFF;
			BallColReciPacage.W100Temp=ChangeWordByte((DEF_UINT16)(BallColReciPacage.W100Temp))&0x0FFF;
			BallColReciPacage.W50Temp=ChangeWordByte((DEF_UINT16)(BallColReciPacage.W50Temp))&0x0FFF;
			
			for(iForBallColTempra=0;iForBallColTempra<=5;iForBallColTempra++)
				{BallColReciPacage.Temp[iForBallColTempra]=ChangeWordByte((DEF_UINT16)(BallColReciPacage.Temp[iForBallColTempra]))&0x0FFF;}			

			BallColReciPacage.angle=ChangeWordByte((DEF_UINT16)(BallColReciPacage.angle))&0x0FFF;
			
	//转存
			g_YC_Package.NT.CommandTransBack[Collector_NO-1]=BallColReciPacage.CommandReturn;
			g_YCLowPack.JC01.BalnetColBoardTemp[Collector_NO-1]=(DEF_INT32)((BallColReciPacage.BoardTem-1616.0)/5.3248+27.0);
			g_YC_Package.NT.Ballonet_PressureGap[Collector_NO-1]=(DEF_INT32)abs(((2000.0/(Y_ForBallColPressure-A_ForBallColPressure))*(BallColReciPacage.Pressure-A_ForBallColPressure)));			
			g_YC_Package.NT.BalnetPowerVol[Collector_NO-1]=(DEF_INT32)(((BallColReciPacage.Vol28V*1.0-625.0)/66.0+10.0)*5.0);
			g_YC_Package.NT.BalnetBatteryVol[Collector_NO-1]=(DEF_INT32)(((BallColReciPacage.Vol16V*1.0-625.0)/66.0+10.0)*5.0);
			g_YC_Package.NT.Ballonet_ValveCur[Collector_NO-1]=(DEF_INT32)((BallColReciPacage.ValveCurrent*0.0021)*10.0);
			
			for(iForBallColTempra=0;iForBallColTempra<=5;iForBallColTempra++)
				{g_YCLowPack.JC01.Ballonet_Temp[Collector_NO-1][iForBallColTempra]=(DEF_INT32)((50.0/(BallColReciPacage.W100Temp-BallColReciPacage.W50Temp)*(BallColReciPacage.Temp[5-iForBallColTempra]-BallColReciPacage.W100Temp)/0.39)*10);}

			g_YC_Package.NT.ValvePowderState[Collector_NO-1]=BallColReciPacage.State_2;
			g_YC_Package.NT.Ballonet_ValveAngle[Collector_NO-1]=(DEF_INT32)((360.0/4096.0)*BallColReciPacage.angle);
			g_YC_Package.NT.Ballonet_ValveState[Collector_NO-1]=BallColReciPacage.ValveState;
			g_YC_Package.NT.BallonetExploderState[Collector_NO-1]=BallColReciPacage.FirePointState;
			g_YC_Package.NT.BallonetFireState[Collector_NO-1]=BallColReciPacage.FireCtlState;
			g_YC_Package.NT.BallonetWorkState[Collector_NO-1]=BallColReciPacage.State_1;

			}
		}
	}

 }







/*--- 1~4 对应:  1主，1从，2主，2从---*/
//  0x01-开阀门(或)；
//  0x02-关阀门(或)；
//  0x03-开阀门(到位1)；
//  0x04-关阀门(到位1)；
//  0x05-关阀门(到位与)；
//  0x06-关阀门(到位2)；
//  0x07-开阀门(无到位)；
//  0x08-关阀门(无到位)；
//  0x09-停止；

//  0x0A-1路点火开；	0x16-1路点火关；
//  0x0B-2路点火开；	0x17-2路点火关；
//  0x0C-3路点火开；	0x18-3路点火关；
//  0x0D-4路点火开；	0x19-4路点火关；
//  0x0E-5路点火开；	0x1A-5路点火关；
//  0x0F-6路点火开；	0x1B-6路点火关；
//  0x10-7路点火开；	0x1C-7路点火关；
//  0x11-8路点火开；	0x1D-8路点火关；
//  0x12-阀门切割1开；0x1E-阀门切割1关；

//  0x22-预点火开；		0x23-预点火关；
//  0x2A-工作；			0x2B-休眠；
//  0x2C-囊体爆破1234；
//  0x3E-遥测定时下发停止；  0x3F-遥测定时下发启动。

_DEFSTRU_BallCoCtrlSend	BallCoCtrlSend;
DEF_UINT8	Ballonet_CtrlTime;
/*----------囊体采集遥控指令发送( 1-采集器号(1~4);     2-指令;     3-阀门时间0.1s  . )  -----------*/
void Ballonet_CtrlSend(DEF_UINT8 Collector_NO,  DEF_UINT8 Comand, DEF_UINT8 Time)
{
BallCoCtrlSend.head[0]=0xCC;
BallCoCtrlSend.head[1]=0xEE;
BallCoCtrlSend.StaticByte=0x11;

BallCoCtrlSend.Command[0]=Comand;
BallCoCtrlSend.Command[1]=Comand;
BallCoCtrlSend.Command[2]=Comand;

//阀门控制时间限制在1.0~20.0s   。
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









 /*异或 校验和----输出为单字节,输入为  (首个字节地址,字节个数)    */
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




/*---------将ASCLL码转换为浮点数, 转换正确则返回浮点数，同时状态置为0；    如数据有误，返回值为-1，状态将置为1------------*/
/*------输入参叔：1-Ascll码数组指针，2-转换状态字节指针---------------*/
DEF_FLOAT32	TransAscllToFloat(DEF_UINT8* Ascll, DEF_UINT8*TansState)
{
DEF_UINT8	i_Byte;
DEF_FLOAT32	Number=0;
DEF_FLOAT32	Sign=1;
DEF_UINT8	DotPos=0xFF;	//小数点位置
DEF_UINT8	ComaPos=0xFF;	//逗号位置
TansState[0]=1;	//数据转换状态默认置为1


//查看第一个字符是否为正负号
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

//合法性检查和小数点位置检查
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
		else		//发现了第二个小数点，错误
			{TansState[0]=1;	return -1;}	
		}
	else if(Ascll[i_Byte]==0x2C)	//发现逗号，结束
		{
		ComaPos=i_Byte;
		break;
		}
	else		//不是数字也不是小数点，错误
		{TansState[0]=1;	return -1;}		
	}

if(ComaPos==0)	//第一个数即为逗号，返回0
	{TansState[0]=0;  return 0;}	//数据转换状态置为正常
else if(ComaPos==0xFF)	//没发现逗号，超长错误
	{TansState[0]=1;	return -1;}


//进行字符转数
Number=0;

//无小数点
if(DotPos==0xFF)
	{
	for(i_Byte=0;i_Byte<ComaPos;i_Byte++)
		{Number=Number+(Ascll[i_Byte]-0x30)*pow(10,(ComaPos-i_Byte-1));}
	}
else
	{
	//有小数点
	for(i_Byte=0;i_Byte<DotPos;i_Byte++)
		{Number=Number+(Ascll[i_Byte]-0x30)*pow(10,(DotPos-i_Byte-1));}
	for(i_Byte=DotPos+1;i_Byte<ComaPos;i_Byte++)
		{Number=Number+(Ascll[i_Byte]-0x30)*pow(10,(DotPos-i_Byte));}
	}

Number=Number*Sign;

TansState[0]=0;		//数据转换状态置为正常
return Number;
}



