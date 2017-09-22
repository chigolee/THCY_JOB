/*========================================================================================*
 * FILE:                     	B_Vector_Operate.c                   
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
 #include "B_Vector_Operate.h"


/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/
#define VectorSendGroupNO	5

DEF_UINT8 Vector_DataSend[VectorSendGroupNO][8];
DEF_UINT8 In_Vector_DataSend=0;
DEF_UINT8 Out_Vector_DataSend=0;


/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/




//矢量装置数据帧，无帧头无尾校验，注意矢量装置高字节在前，低字节在后。
struct 
{
DEF_INT16 	A1_VectorActualN;					/*矢量装置电机1-转速测量值*/
DEF_INT16 	A1_VectorAngle;						/*矢量装置角度值1-*/	
DEF_UINT16	A1_Reserve_2;						/*备用寄存器地址2*/
DEF_INT16	A1_VectorRadiatorTemp;				/*矢量装置电机1-驱动器温度*/ 

DEF_INT16 	A1_VectorMainwireVol;				/*矢量装置电机1-母线电压*/
DEF_INT16 	A1_VectorCurrent;					/*矢量装置电机1-电机电流*/

DEF_UINT16 	A1_VectorState;						/*矢量装置电机1-状态*/	
DEF_UINT16	A1_Reserve_7[3];					/*备用寄存器地址7~9*/	
}TransNoHead_Vector_Recieve;

DEF_UINT8	Vector_Data_Recieve[45];	//矢量装置接收全部数据
DEF_UINT16	Vector_CRC_Recieve=0;

 /*--------------矢量装置数据接收----------------*/
 void Task_Vector_Recieve()
 	{
 	int a=0;
	int b=0;
 	}







DEF_UINT8	Vector_Data_Require[8];
DEF_UINT16	Vector_CRC_Send=0;
/*-----矢量装置控制指令发送/数据请求任务----*/
 void Task_Vector_DataSend()
{
	if(Out_Vector_DataSend != In_Vector_DataSend)
		{
		//发送当前位置控制指令
		UGInTxBuf((U8*)&(Vector_DataSend[Out_Vector_DataSend][0]),8);
		Out_Vector_DataSend=(Out_Vector_DataSend+1)%VectorSendGroupNO;
		}
	
	else
		{
		//发送数据请求
		Vector_Data_Require[0]=UG_DH0;
		Vector_Data_Require[1]=UG_DH1_1;
		Vector_Data_Require[2]=0x00;
		Vector_Data_Require[3]=0x00;
		Vector_Data_Require[4]=0x00;
		Vector_Data_Require[5]=10;		
		Vector_CRC_Send=modbus_crc16((DEF_UINT8*)&(Vector_Data_Require[0]),6);
		bcopy((&Vector_CRC_Send),(&(Vector_Data_Require[6])),2);
		
		UGInTxBuf((U8*)&(Vector_Data_Require[0]),8);
		}
}











DEF_INT16	VectorCtrl_Trans[4];		//遥控数据暂存，注意高低位，矢量装置数据高位在前，CRC低位在前。
DEF_UINT16	VectorCtrlCRC=0;

//CtrlType，Param
// 0x01-角度			，角度值，单位°，有符号，精度0.1 。即Param=要控制角度*10   ；
// 0x02-启动			，0
// 0x03-回零			，0
// 0x04-停止			，0
// 0x05-清除故障	，0
// 0x06-转速控制	，转速值，单位r/min，有符号，精度0.1 。即Param=要控制转速*10   

 /*--------------矢量装置控制----------------*/
void Vector_Control(DEF_UINT8 CtrlType, DEF_INT16 Param)
 {
	VectorCtrl_Trans[0]=(0x0600+UG_DH0);		//低位在前21 , 06

	if(CtrlType==0x01)	//角度
		{
		VectorCtrl_Trans[1]=0x2200;		//寄存器地址0x0022
		if(Param>900)
			{VectorCtrl_Trans[2]=900;}
		else if(Param<-900)
			{VectorCtrl_Trans[2]=-900;}
		else
			{VectorCtrl_Trans[2]=Param;}
		g_YC_Package.TJ.VectorCtrlAngle=VectorCtrl_Trans[2];
		VectorCtrl_Trans[2]=ChangeWordByte((DEF_UINT16)(VectorCtrl_Trans[2]));	
		}

	else if(CtrlType==0x02)//启动
		{
		VectorCtrl_Trans[1]=0x1F00;		//寄存器地址0x1F00
		VectorCtrl_Trans[2]=0x0200;		//矢量高字节在前

		}

	else if(CtrlType==0x03)//回零
		{
		VectorCtrl_Trans[1]=0x1F00;		//寄存器地址0x1F00
		VectorCtrl_Trans[2]=0x0300;		//矢量高字节在前
		}

	else if(CtrlType==0x04)//停止
		{
		VectorCtrl_Trans[1]=0x1F00;		//寄存器地址0x1F00
		VectorCtrl_Trans[2]=0x0100;		//矢量高字节在前
		}

	else if(CtrlType==0x05)//清除故障
		{
		VectorCtrl_Trans[1]=0x2000;		//寄存器地址0x2000
		VectorCtrl_Trans[2]=0xffff;		//矢量高字节在前
		}

	else if(CtrlType==0x06)//转速控制
		{
		VectorCtrl_Trans[1]=0x2100;		//寄存器地址0x2100
		if((Param>50)||(Param<0))
			{VectorCtrl_Trans[2]=50;}
		else
			{VectorCtrl_Trans[2]=Param;}
		VectorCtrl_Trans[2]=ChangeWordByte((DEF_UINT16)(VectorCtrl_Trans[2]));	
		}

	VectorCtrl_Trans[3]=modbus_crc16((DEF_UINT8*)&(VectorCtrl_Trans[0]),6);

	//发送缓存
	bcopy((DEF_UINT8*)&(VectorCtrl_Trans[0]),(DEF_UINT8*)&(Vector_DataSend[In_Vector_DataSend][0]),8);
	In_Vector_DataSend=(In_Vector_DataSend+1)%VectorSendGroupNO;

 }





























