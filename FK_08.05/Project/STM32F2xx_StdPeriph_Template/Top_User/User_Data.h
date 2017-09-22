#ifndef M_User_Data_H
#define M_User_Data_H

//状态数据 Bottom ---> Top
extern U16 AinData[16];  //16通道AD     AinData[0]-AIN1
extern U8 DIData; //8路DI   1bit对应1路  bit0-DI_D1

extern U8 Hardware_State1;//硬件状态低字节
extern U8 Hardware_State2;//硬件状态高字节

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


extern S8 InnerTmp;//内部温度   单位度


//控制数据Top  ---> Bottom
extern U8 DOData;//8路DO   1bit对应1路 bit0-DO_C1    

extern U8 ComSW_CMD;//串口切换命令    0:  自动切换  1: Usart1  2:Usart2
extern U8 TmpCtrl_CMD;//温控命令    0:  自动温控  1: 加温 2:不加温




//20150619新增数据记录相关
//数据记录不超过10Hz
//数据下载不超过20Hz

#define RecordF_Len  140	//数据记录数据帧长度
extern U8 RecordData[RecordF_Len];  //数据记录数据帧
extern U8 DownLoadData[RecordF_Len];  //数据下载数据帧
extern U32 Current_RecordBlock;  //当前正在记录的Block
extern U32 Current_DownloadBlock;  //当前正在下载的Block
extern U8 IsNandScanCMD; //扫描命令




//现场保护数据
typedef __packed struct _ProData
      {

		U8     HeadByte1;          // 字头1    用于判断数据读写是否正常 
              U8     HeadByte2;          // 字头2    用于判断数据读写是否正常 
              
              U8     CtrlByte;          // 控制字              
              //bit0   是否保护现场  0不保护   1保护  
              //地面测试阶段可以不保护，空中状态要保护
              //bit1-bit7   备用
              U32 SystemTime;  //系统计数器  单位10ms
	       
		/******* 其它数据待添加，注意添加顺序最好不要乱改********/             
		U32	Current_RecordBlock;	//当前存储位置
		
		S16	CriticalBaricAlt;			/*临界气压高度*/
		U16	PropellerN_Limit;		/*自主控制推进转速限幅*/ 

		U16	FrontPropelN_Limit;		/*航向电机转速限幅*/ 			
		U8	FlightMode;				/*飞行模式*/
		U8	CompuRecState;			/*计算机记录情况*/
		
		U8 	SafeCtrlMinite;			/*安控时间,单位min*/
		U8	AirscrewCtrlState;		/*电机启停状态bit0~ bit3：左前电机~右后电机； bit4：航向电机。状态：0-停止；1-启动。*/
	  
	}Pro_Datat;

extern Pro_Datat  Pro_Data;

//飞行记录数据

extern U8 ProData_Flag;//现场保护数据更新标志


extern U32 SystemTime;  //系统计数器  单位10ms
extern U32 SystemTimems;  // //系统计数器  单位1ms

extern U8 LED2_Flag;//LED2状态控制   0 灭 1 亮2闪亮

extern U8 Record_Flag;//飞行数据记录/下载状态  0   不动作  1  记录  2下载 默认0

extern U8 IsSystemTest;  //系统测试标志

#define Heat_StartT    -25   //加温温度门限 单位度
#define Heat_StopT    0   //停止加温温度门限 单位度

extern void FCS(void);//预留给飞行控制用的函数





#endif 

