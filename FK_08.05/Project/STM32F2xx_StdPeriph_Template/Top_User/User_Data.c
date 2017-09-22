#include "main.h"
#include "B_GlobalDefine.h"

//状态数据 Bottom ---> Top
 U16 AinData[16]={0};  //16通道AD     AinData[0]-AIN1    AIN =  (AinData[]/4096)*33*(2) ，单位:0.1V
 U8 DIData =0; //8路DI   1bit对应1路  bit0-DI_D1

 U8 Hardware_State1 = 0;//硬件状态低字节
 U8 Hardware_State2 = 0;//硬件状态高字节

//Hardware_State1
//bit0 ADC      0正常 1故障
//bit1 NVRAM    0正常 1故障
//bit2 NandFlash1    0正常 1故障
//bit3 NandFlash2    0正常 1故障
//bit4 VCC3            0正常 1故障
//bit5 VCC5            0正常 1故障
//bit6 OVCC3          0正常 1故障
//bit7 OVCC5          0正常 1故障

//Hardware_State2
//bit0 CAN1      0正常 1故障
//bit1 CAN2     0正常 1故障
//bit2 MAX14830A    0正常 1故障
//bit3 MAX14830B    0正常 1故障
//bit4 MAX14830C         0正常 1故障
//bit5 Tmp100                0正常 1故障
//bit6 U1&U2 Switch       0:U1工作,U2备用     1:U2工作,U1备用
//bit7 备用串口状态   0正常 1故障

 S8 InnerTmp = 0;//内部温度   单位度


//控制数据Top  ---> Bottom
 U8 DOData = 0;//8路DO   1bit对应1路 bit0-DO_C1    

 U8 ComSW_CMD = 0;//串口切换命令    0:  自动切换  1: Usart1  2:Usart2
 U8 TmpCtrl_CMD = 0;//温控命令    0:  自动温控  1: 加温 2:不加温

//现场保护数据
Pro_Datat  Pro_Data;
U8 ProData_Flag = FALSE;//现场保护数据更新标志

U32 SystemTime = 0;  //系统计数器  单位10ms
U32 SystemTimems =0;  // //系统计数器  单位1ms
U8 LED2_Flag = 2;//LED2状态控制   0 灭 1 亮2闪亮
U8 Record_Flag = 0;//飞行数据记录/下载状态  0   不动作  1  记录  2下载 默认0   //数据记录 频率为1Hz

U8 IsSystemTest= FALSE;  //系统测试标志 默认FALSE,,,,TRUE





//20150619新增数据记录相关
//数据记录不超过10Hz
//数据下载不超过20Hz
U8 RecordData[RecordF_Len] = {0};  //数据记录数据帧
U8 DownLoadData[RecordF_Len] = {0};  //数据下载数据帧
U32 Current_RecordBlock = 0;  //当前正在记录的Block     0-32767
U32 Current_DownloadBlock = 0;  //当前正在下载的Block  0-32767
U8 IsNandScanCMD = FALSE; //扫描命令





//#define USART_SW_U1     GPIOF->BSRRH = GPIO_Pin_10;  ResetBit(Hardware_State2, 6)  //置低   UART_SW  选择RS422A_1输出
//#define USART_SW_U2     GPIOF->BSRRL = GPIO_Pin_10;  SetBit(Hardware_State2, 6)   //置高   UART_SW  选择RS422A_1输出



DEF_UINT8 SignForResetTest=0;
void FCS(void)//预留给飞行控制用的函数
{
      //输入
      //Pro_Data   第一次运行时用Pro_Data进行初始化
      //AinData[16]
      //DIData
      //Hardware_State1
      //Hardware_State2
      //InnerTmp
      //SystemTime
      //UxRxFBuf  //串口接收数据
      //CAnxRxFBuf  //CAN接收数据
if(SignForResetTest==1)
	{
	for(SignForResetTest=0;SignForResetTest<=9;SignForResetTest++)
		{g_CountTest[SignForResetTest]=0;}



//g_YC_Package.TJ.FlightMode=0;
//TimeForCKDelay=CKDelayMaxTime-50;
//OnceSignForFastExploder=0;

	
	SignForResetTest=0;	
	
	}



/*-------周期循环任务-------*/

	
	//设定周期任务,  注意同一频率的任务可以分数执行
	g_TimeCount=g_TimeCount++;


	if(g_TimeCount%1==0)
		{Task_INSMain_Recieve();Task_INSMain_Recieve();}		/*--惯导1	数据接收--*/

	if(g_TimeCount%2==0)	
		{Task_CJComputer_Receive();}	/*--采集计算机数据接收--*/

	if(g_TimeCount%2==0)				
		{Task_UlinkCK_Reiceive();}		/*--U频段--遥控指令接收--*/

	if(g_TimeCount%2==0)	
		{Task_CAN_Power_Recieve();}	/*--能源设备数据接收--*/

	if(g_TimeCount%3==0)				
		{Task_Airscrew_Recieve(1);		/*--推进电机1\2\3\4\前部风扇--数据接收--*/
		Task_Airscrew_Recieve(2);
		Task_Airscrew_Recieve(3);
		Task_Airscrew_Recieve(4);
		Task_Airscrew_Recieve(5);}

	if(g_TimeCount%5==0)				
		{Task_LlinkCK_Reiceive();}		/*--L频段--遥控指令接收--*/

	if(g_TimeCount%5==0)				
		{Task_GNSS_Recieve();}			/*--GNSS接收机，数据接收--*/

	if(g_TimeCount%5==0)				
		{Task_Ballonet_Operate(1);		/*--囊体采集1\2\3\4--数据接收--*/
		Task_Ballonet_Operate(2);
		Task_Ballonet_Operate(3);
		Task_Ballonet_Operate(4);}

	if(g_TimeCount%10==0)	
		{Task_YCYKBack_Send();	}		/*--遥测数据、遥控回复发送--*/
	
	 if(g_TimeCount%10==0)	
		{Task_Ulink_SendTestFram();}	/*--U频段测控链路测试帧发送--*/

	 if(g_TimeCount%10==0)	
		{Task_PeriodDataSave();}		/*--快慢帧周期存储--*/

	if(g_TimeCount%10==0)				
		{Task_Alt_Height_Recieve();}		/*--气压高度表数据接收--*/

	if(g_TimeCount%30==0)		
		{Task_Vector_DataSend();}		/*--矢量装置数据请求--*/
	if(g_TimeCount%5==2)		
		{Task_Vector_Recieve();}		/*--矢量装置数据接收--*/

	if(g_TimeCount%100==0)				
		{Task_CtrlLaw_Operate();}		/*--自动飞行控制--*/


	if(g_TimeCount%1==0)				
		{Task_B_001SecondDelay();}		/*--0.01秒延时任务--*/

	if(g_TimeCount%10==0)				
		{Task_B_Time100msDelay();}	/*--0.1秒延时任务--*/

	if(g_TimeCount%100==0)				
		{Task_B_TimeSecondDelay();}	/*--1秒延时任务--*/



      LED2_Flag =2;

      //飞行数据记录
      Record_Flag = 0;//飞行数据记录/下载状态  0   不动作  1  记录  2下载 默认0
}



