/*========================================================================================*
 * FILE:                     	B_Alt_Height_Receive.c                   
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
 #include "B_Alt_Height_Receive.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
 _DEFSTRU_Alt_Recieve	Trans_Alt_Recieve;
 
/*------------------------------------------------------------------------------*
 *								������
void Modelname()
 *------------------------------------------------------------------------------*/
 

 /*---------��ѹ�߶ȱ����ݽ��մ���---------*/
void Task_Alt_Height_Recieve()	
{
	{
if(U9RxFBufPo!=U9RxFBufPi)
	{
	bcopy(&(U9RxFBuf[U9RxFBufPo][0]),&(Trans_Alt_Recieve),sizeof(Trans_Alt_Recieve));
	U9RxFBufPo=(U9RxFBufPo+1)%U9_RxF_BufLen;
	
	if(Trans_Alt_Recieve.AddSum==AddSum1((DEF_UINT8*)&(Trans_Alt_Recieve.Hp_Byte1),10))
		{
		DelaySecond_Healthy[0][5]=0;		//��ʱ������0 
		
		//��������
		g_YC_Package.HD01.BaricAlt=(DEF_INT32)(((DEF_FLOAT32)((Trans_Alt_Recieve.Hp_Byte1)<<16)+(DEF_FLOAT32)((Trans_Alt_Recieve.Hp_Byte2)<<8)+(DEF_FLOAT32)(Trans_Alt_Recieve.Hp_Byte3))/10.0-300.0);
		g_YC_Package.HD01.BaricAltPressure=(DEF_UINT16)((((DEF_FLOAT32)((Trans_Alt_Recieve.Hc_Byte1)<<16)+(DEF_FLOAT32)((Trans_Alt_Recieve.Hc_Byte2)<<8)+(DEF_FLOAT32)(Trans_Alt_Recieve.Hc_Byte3))/100.0-10.0)*100.0);
		g_YC_Package.HD01.BaricAltUpDownSpeed=(DEF_INT32)(((DEF_FLOAT32)((Trans_Alt_Recieve.Hv_Byte1)<<8)+(DEF_FLOAT32)(Trans_Alt_Recieve.Hv_Byte2))/10.0-100.0);
		g_YCLowPack.JC01.EnviTemp=(DEF_INT32)(((DEF_FLOAT32)((Trans_Alt_Recieve.Ts_Byte1)<<8)+(DEF_FLOAT32)(Trans_Alt_Recieve.Ts_Byte2))/10.0-70.0);

		}
	}
}
}





