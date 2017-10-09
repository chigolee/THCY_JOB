/*========================================================================================*
 * FILE:                     	B_INSMain_Operate.c                   
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
 #include "B_INSMain_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/

 
 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/

DEF_UINT8		Trans_INSMain_Recieve[248];		//惯导接收数据暂存
DEF_UINT16		INSMain_Store_Uint16;			//转换用
DEF_UINT32		INSMain_Store_Uint32[2];		//转换用
DEF_FLOAT32		INSMain_Store_Float32[9];		//转换用
DEF_DOUBLE64	INSMain_Store_Double64[9];		//转换用

DEF_UINT8		INSMain_CRC_ByteCount;			//CRC校验字节数
DEF_UINT32		INSMain_CRC_Uint32;				//CRC校验

/*--------惯导数据接收任务---------*/
void Task_INSMain_Recieve()
{
//接收数据，Trans_INSMain_Recieve[120]
if(U2RxFBufPo!=U2RxFBufPi)
	{
	bcopy(&(U2RxFBuf[U2RxFBufPo][0]),&(Trans_INSMain_Recieve[0]),(U2RxFBuf[U2RxFBufPo][U2_RxF_Len]%(U2_RxF_Len+1)));
	U2RxFBufPo=(U2RxFBufPo+1)%U2_RxF_BufLen;

//得到CRC校验
	INSMain_CRC_ByteCount=0;
	INSMain_CRC_Uint32=0;		//校验和字节计数清零

	if((Trans_INSMain_Recieve[0]==0xAA)&&(Trans_INSMain_Recieve[1]==0x44))
		{
			
		if(Trans_INSMain_Recieve[2]==0x13)
			{INSMain_CRC_ByteCount=Trans_INSMain_Recieve[3]+12;}
		else if(Trans_INSMain_Recieve[2]==0x12)
			{bcopy(&(Trans_INSMain_Recieve[8]),&INSMain_Store_Uint16,2);
			INSMain_CRC_ByteCount=INSMain_Store_Uint16+28;}
			
		INSMain_CRC_Uint32=CalculateBlockCRC32((DEF_UINT8*)&(Trans_INSMain_Recieve[0]),(DEF_UINT32)(INSMain_CRC_ByteCount));
		bcopy(&(Trans_INSMain_Recieve[INSMain_CRC_ByteCount]),&(INSMain_Store_Uint32[0]),4);
		}

		

		
//数据处理Trans_INSMain_Recieve[]
	bcopy(&(Trans_INSMain_Recieve[4]),&(INSMain_Store_Uint16),2);

	if(INSMain_CRC_Uint32==INSMain_Store_Uint32[0])
		{
		DelaySecond_Healthy[3][0]=0;		//超时计数置0		
		switch(INSMain_Store_Uint16)
			{
			case 813:
					{
						bcopy(&(Trans_INSMain_Recieve[6]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[8]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);

						bcopy(&(Trans_INSMain_Recieve[24]),&(INSMain_Store_Double64[0]),48);
						g_YC_Package.HD01.PitchSpeed = (DEF_INT16)(INSMain_Store_Double64[0]*125*1000);
						g_YC_Package.HD01.RollSpeed = (DEF_INT16)(INSMain_Store_Double64[1]*125*1000);
						g_YC_Package.HD01.YawSpeed = (DEF_INT16)(INSMain_Store_Double64[2]*125*1000);
						g_YC_Package.HD01.AX = (DEF_INT16)(INSMain_Store_Double64[3]*125*100);
						g_YC_Package.HD01.AY = (DEF_INT16)(INSMain_Store_Double64[4]*125*100);
						g_YC_Package.HD01.AZ = (DEF_INT16)(INSMain_Store_Double64[5]*125*100);

						break;
					}
			case 508:
					{
						bcopy(&(Trans_INSMain_Recieve[6]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[8]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);

						bcopy(&(Trans_INSMain_Recieve[24]),&(INSMain_Store_Double64[0]),72);
						g_YC_Package.HD01.INSLat = (DEF_FLOAT32)(INSMain_Store_Double64[0]*PI/180);
						g_YC_Package.HD01.INSLon= (DEF_FLOAT32)(INSMain_Store_Double64[1]*PI/180);
						g_YC_Package.HD01.INSAlt= (DEF_INT16)(INSMain_Store_Double64[2]);
						g_YC_Package.HD01.North_V=(DEF_INT16)(INSMain_Store_Double64[3]*100);
						g_YC_Package.HD01.East_V=(DEF_INT16)(INSMain_Store_Double64[4]*100);
						g_YC_Package.HD01.Up_V=(DEF_INT16)(INSMain_Store_Double64[5]*100);
						g_YC_Package.HD01.Roll=(DEF_INT16)(INSMain_Store_Double64[6]*PI/180*10000);
						g_YC_Package.HD01.Pitch=(DEF_INT16)(INSMain_Store_Double64[7]*PI/180*10000);
						g_YC_Package.HD01.Yaw=(DEF_UINT16)(INSMain_Store_Double64[8]*PI/180*10000);
						g_YC_Package.HD01.INS_State=Trans_INSMain_Recieve[96];
						
						break;
					}
			

			case 971:
					{
						bcopy(&(Trans_INSMain_Recieve[14]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[16]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);
			
						g_YC_Package.HD01.INS_SiteSolveState=(((Trans_INSMain_Recieve[22])&(0x08))/0x04)+(g_YC_Package.HD01.INS_SiteSolveState)&0xFD; 
						g_YC_Package.HD01.ReserAlignType = Trans_INSMain_Recieve[32];
						bcopy(&(Trans_INSMain_Recieve[36]),&(INSMain_Store_Float32[0]),12);
						g_YC_Package.HD01.BaseLineLength = (DEF_UINT16)(INSMain_Store_Float32[0]*10);
						g_YC_Package.HD01.Double_Antenna_Heading = (DEF_UINT16)(INSMain_Store_Float32[1]*PI/180*10000);
						g_YC_Package.HD01.Double_Antenna_Pitch = (DEF_INT16)(INSMain_Store_Float32[2]*PI/180*10000);
			
						g_YC_Package.HD01.Double_TrackingNumber = Trans_INSMain_Recieve[64];
						g_YC_Package.HD01.Double_SatelliteSolveNumber = Trans_INSMain_Recieve[65];
									
						break;
					}




			case 1429:
					{
						bcopy(&(Trans_INSMain_Recieve[14]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[16]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);
						
						g_YC_Package.HD01.INS_SiteSolveState=(((Trans_INSMain_Recieve[22])&(0x08))/0x08)+(g_YC_Package.HD01.INS_SiteSolveState)&0xFE;	
						g_YC_Package.HD01.PrimaAlignType = Trans_INSMain_Recieve[32];
						bcopy(&(Trans_INSMain_Recieve[36]),&(INSMain_Store_Double64[0]),24);
						g_YC_Package.HD01.GPSLat = (DEF_FLOAT32)(INSMain_Store_Double64[0]*PI/180);
						g_YC_Package.HD01.GPSLon = (DEF_FLOAT32)(INSMain_Store_Double64[1]*PI/180);
						g_YC_Package.HD01.GPSAlt = (DEF_INT16)(INSMain_Store_Double64[2]);

						g_YC_Package.HD01.SatelTrackNumber = Trans_INSMain_Recieve[92];
						g_YC_Package.HD01.SatelSolveNumber = Trans_INSMain_Recieve[93];
						
						break;
					}
			
			case 1430:
					{
						bcopy(&(Trans_INSMain_Recieve[14]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[16]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);

						bcopy(&(Trans_INSMain_Recieve[52]),&(INSMain_Store_Double64[0]),8);
						g_YC_Package.HD01.FlightPathAngle=(DEF_UINT16)(INSMain_Store_Double64[0]*PI*10000/180);
						
						break;
					}
			case 320:
					{
						bcopy(&(Trans_INSMain_Recieve[6]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[8]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);
						
						bcopy(&(Trans_INSMain_Recieve[24]),&(INSMain_Store_Double64[0]),8);	
						INSMain_Store_Float32[0]=(DEF_FLOAT32)(sqrt(INSMain_Store_Double64[0]));
						if(INSMain_Store_Float32[0]>0xFF){g_YCLowPack.JC01.Lat_Deviation=0xFF;}else{g_YCLowPack.JC01.Lat_Deviation=(DEF_UINT8)INSMain_Store_Float32[0];}		
												
						bcopy(&(Trans_INSMain_Recieve[56]),&(INSMain_Store_Double64[1]),8);						
						INSMain_Store_Float32[1]=(DEF_FLOAT32)(sqrt(INSMain_Store_Double64[1]));
						if(INSMain_Store_Float32[1]>0xFF){g_YCLowPack.JC01.Lon_Deviation=0xFF;}else {g_YCLowPack.JC01.Lon_Deviation=(DEF_UINT8)INSMain_Store_Float32[1];}
						
						bcopy(&(Trans_INSMain_Recieve[88]),&(INSMain_Store_Double64[2]),16);						
						INSMain_Store_Float32[2]=(DEF_FLOAT32)(sqrt(INSMain_Store_Double64[2]));
						if(INSMain_Store_Float32[2]>0xFF){g_YCLowPack.JC01.InsAlt_Deviation=0xFF;}else {g_YCLowPack.JC01.InsAlt_Deviation=(DEF_UINT8)INSMain_Store_Float32[2];}						
						INSMain_Store_Float32[3]=(DEF_FLOAT32)((sqrt(INSMain_Store_Double64[3]))*10);
						if(INSMain_Store_Float32[3]>0xFF){g_YCLowPack.JC01.Pitch_Deviation=0xFF;}else {g_YCLowPack.JC01.Pitch_Deviation=(DEF_UINT8)INSMain_Store_Float32[3];}
						
						bcopy(&(Trans_INSMain_Recieve[128]),&(INSMain_Store_Double64[4]),8);						
						INSMain_Store_Float32[4]=(DEF_FLOAT32)((sqrt(INSMain_Store_Double64[4]))*10);
						if(INSMain_Store_Float32[4]>0xFF){g_YCLowPack.JC01.Roll_Deviation=0xFF;}else {g_YCLowPack.JC01.Roll_Deviation=(DEF_UINT8)INSMain_Store_Float32[4];}
						
						bcopy(&(Trans_INSMain_Recieve[160]),&(INSMain_Store_Double64[5]),16);						
						INSMain_Store_Float32[5]=(DEF_FLOAT32)((sqrt(INSMain_Store_Double64[5]))*10);
						if(INSMain_Store_Float32[5]>0xFF){g_YCLowPack.JC01.Yaw_Deviation=0xFF;}else {g_YCLowPack.JC01.Yaw_Deviation=(DEF_UINT8)INSMain_Store_Float32[5];}
						INSMain_Store_Float32[6]=(DEF_FLOAT32)((sqrt(INSMain_Store_Double64[6]))*10);
						if(INSMain_Store_Float32[6]>0xFF){g_YCLowPack.JC01.East_V_Deviation=0xFF;}else {g_YCLowPack.JC01.East_V_Deviation=(DEF_UINT8)INSMain_Store_Float32[6];}
						
						bcopy(&(Trans_INSMain_Recieve[200]),&(INSMain_Store_Double64[7]),8);						
						INSMain_Store_Float32[7]=(DEF_FLOAT32)((sqrt(INSMain_Store_Double64[7]))*10);
						if(INSMain_Store_Float32[7]>0xFF){g_YCLowPack.JC01.North_V_Deviation=0xFF;}else {g_YCLowPack.JC01.North_V_Deviation=(DEF_UINT8)INSMain_Store_Float32[7];}
						
						bcopy(&(Trans_INSMain_Recieve[232]),&(INSMain_Store_Double64[8]),8);						
						INSMain_Store_Float32[8]=(DEF_FLOAT32)((sqrt(INSMain_Store_Double64[8]))*10);
						if(INSMain_Store_Float32[8]>0xFF){g_YCLowPack.JC01.Up_V_Deviation=0xFF;}else {g_YCLowPack.JC01.Up_V_Deviation=(DEF_UINT8)INSMain_Store_Float32[8];}
												
						break;
					}
			case 963:
					{
						bcopy(&(Trans_INSMain_Recieve[14]),&(g_YC_Package.HD01.INS_GPS_week),2);
						bcopy(&(Trans_INSMain_Recieve[16]),&(g_YC_Package.HD01.INS_GPS_millisecond),4);

						bcopy(&(Trans_INSMain_Recieve[32]),&(INSMain_Store_Float32[0]),4);
						g_YCLowPack.JC01.INSTemp=(DEF_UINT8)(INSMain_Store_Float32[0]+80);
						g_YCLowPack.JC01.INSTempMeasreState=((g_YCLowPack.JC01.INSTempMeasreState)&(0xF0))+(Trans_INSMain_Recieve[36])&0x0F;
						g_YCLowPack.JC01.INSTempMeasreState=((g_YCLowPack.JC01.INSTempMeasreState)&(0x0F))+(((Trans_INSMain_Recieve[37])&0x01)*0x10);
						
						break;
					}

			default: break;	
			
			}
		}


	}
}










DEF_UINT8		Trans_GNSS_Recieve[120];		//GNSS接收数据暂存
DEF_UINT8		GNSS_CRC_ByteCount;			//CRC校验字节数
DEF_UINT32		GNSS_CRC_Uint32;				//CRC校验
DEF_UINT16		GNSS_Store_Uint16;			//转换用
DEF_DOUBLE64	GNSS_Store_Double64[3];		//转换用
DEF_FLOAT32		GNSS_Store_Float32[3];		//转换用
DEF_UINT32		GNSS_Store_Uint32[2];			//转换用
/*--------GNSS接收机，数据接收任务---------*/
void Task_GNSS_Recieve()
{
//接收数据，Trans_GNSS_Recieve[120]
if(UARxFBufPo!=UARxFBufPi)
	{
	
	bcopy(&(UARxFBuf[UARxFBufPo][0]),&(Trans_GNSS_Recieve[0]),(UARxFBuf[UARxFBufPo][UA_RxF_Len]%(UA_RxF_Len+1)));
	UARxFBufPo=(UARxFBufPo+1)%UA_RxF_BufLen;

//得到CRC校验
	GNSS_CRC_ByteCount=0;
	GNSS_CRC_Uint32=0;		//校验和字节计数清零

	if((Trans_GNSS_Recieve[0]==0xAA)&&(Trans_GNSS_Recieve[1]==0x44))
		{
		bcopy(&(Trans_GNSS_Recieve[8]),&GNSS_Store_Uint16,2);
		GNSS_CRC_ByteCount=GNSS_Store_Uint16+28;

		if(GNSS_CRC_ByteCount<=(UA_RxF_Len-4))
			{
			GNSS_CRC_Uint32=CalculateBlockCRC32((DEF_UINT8*)&(Trans_GNSS_Recieve[0]),(DEF_UINT32)(GNSS_CRC_ByteCount));
			bcopy(&(Trans_GNSS_Recieve[GNSS_CRC_ByteCount]),&(GNSS_Store_Uint32[0]),4);

			//数据处理Trans_GNSS_Recieve[]
			bcopy(&(Trans_GNSS_Recieve[4]),&(GNSS_Store_Uint16),2);

			if(GNSS_CRC_Uint32==GNSS_Store_Uint32[0])
				{
				DelaySecond_Healthy[3][1]=0;		//超时计数置0		

				switch(GNSS_Store_Uint16)
					{
					//副帧1
					case 42:		{

								bcopy(&(Trans_GNSS_Recieve[14]),&(g_YC_Package.TJ.GNSS_GPS_week),2);
								bcopy(&(Trans_GNSS_Recieve[16]),&(g_YC_Package.TJ.GNSS_GPS_millisecond),4);
								
								g_YC_Package.TJ.GNSS_ReceiverState=((Trans_GNSS_Recieve[22])&(0x08))/0x08;
								g_YC_Package.TJ.GNNS_AlignType=Trans_GNSS_Recieve[32];
								bcopy(&(Trans_GNSS_Recieve[36]),&(GNSS_Store_Double64[0]),24);
								g_YC_Package.TJ.GNSS_GPSLat=(DEF_FLOAT32)(GNSS_Store_Double64[0]);
								g_YC_Package.TJ.GNSS_GPSLon=(DEF_FLOAT32)(GNSS_Store_Double64[1]);
								g_YC_Package.TJ.GNSS_GPSAlt=(DEF_INT16)(GNSS_Store_Double64[2]);

								bcopy(&(Trans_GNSS_Recieve[68]),&(GNSS_Store_Float32[0]),12);
								if(GNSS_Store_Float32[0]<0xFF){g_YCLowPack.JC01.GNSS_Lat_Deviation=(DEF_UINT8)(GNSS_Store_Float32[0]);}else{g_YCLowPack.JC01.GNSS_Lat_Deviation=0xFF;}
								if(GNSS_Store_Float32[1]<0xFF){g_YCLowPack.JC01.GNSS_Lon_Deviation=(DEF_UINT8)(GNSS_Store_Float32[1]);}else{g_YCLowPack.JC01.GNSS_Lon_Deviation=0xFF;}
								if(GNSS_Store_Float32[2]<0xFF){g_YCLowPack.JC01.GNSS_InsAlt_Deviation=(DEF_UINT8)(GNSS_Store_Float32[2]);}else{g_YCLowPack.JC01.GNSS_InsAlt_Deviation=0xFF;}
						
								g_YC_Package.TJ.GNSS_SatelTrackNumber=Trans_GNSS_Recieve[92];
								g_YC_Package.TJ.GNSS_SatelSolveNumber=Trans_GNSS_Recieve[93];

								break;}
					//副帧2---正常
					case 963:		
								{

								bcopy(&(Trans_GNSS_Recieve[14]),&(g_YC_Package.TJ.GNSS_GPS_week),2);
								bcopy(&(Trans_GNSS_Recieve[16]),&(g_YC_Package.TJ.GNSS_GPS_millisecond),4);

								bcopy(&(Trans_GNSS_Recieve[32]),&(GNSS_Store_Float32[0]),4);
								g_YCLowPack.JC01.GNSS_CompuTempra=GNSS_Store_Float32[0]+80;
								g_YCLowPack.JC01.GNSS_TempMeaState=((g_YCLowPack.JC01.GNSS_TempMeaState)&(0xF0))+(Trans_GNSS_Recieve[36])&0x0F;
								g_YCLowPack.JC01.GNSS_TempMeaState=((g_YCLowPack.JC01.GNSS_TempMeaState)&(0x0F))+(((Trans_GNSS_Recieve[37])&0x01)*0x10);
								break;}						

					default: break;
					}

				}

			}


		


		//副帧2---超长
		if((GNSS_Store_Uint16==963)&&(GNSS_CRC_ByteCount>=36))
			{
			bcopy(&(Trans_GNSS_Recieve[14]),&(g_YC_Package.TJ.GNSS_GPS_week),2);
			bcopy(&(Trans_GNSS_Recieve[16]),&(g_YC_Package.TJ.GNSS_GPS_millisecond),4);

			bcopy(&(Trans_GNSS_Recieve[32]),&(GNSS_Store_Float32[0]),4);
			g_YCLowPack.JC01.GNSS_CompuTempra=GNSS_Store_Float32[0]+80;
			g_YCLowPack.JC01.GNSS_TempMeaState=((g_YCLowPack.JC01.GNSS_TempMeaState)&(0xF0))+(Trans_GNSS_Recieve[36])&0x0F;
			g_YCLowPack.JC01.GNSS_TempMeaState=((g_YCLowPack.JC01.GNSS_TempMeaState)&(0x0F))+(((Trans_GNSS_Recieve[37])&0x01)*0x10);
			}


		}


		
	}

<<<<<<< HEAD
=======
		
>>>>>>> NCY
}










