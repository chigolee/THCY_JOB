/*------------------------------------------------------------------------------*
 *								头文件
 #include "Modelname.h"
 *------------------------------------------------------------------------------*/
 #include "B_CtrlLaw_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 
DEF_UINT8	Modelname=DEF_FALSE;	
 *------------------------------------------------------------------------------*/





_DEFSTRU_CtrlLaw01_FlightPathInput			CtrlLaw01_FlightPathInput;
_DEFSTRU_CtrlLaw02_CruiseCirclePara			CtrlLaw02_CruiseCirclePara;
_DEFSTRU_CtrlLaw03_StayModePara				CtrlLaw03_StayModePara;
_DEFSTRU_CtrlLaw04_TrajPlanPara				CtrlLaw04_TrajPlanPara;
_DEFSTRU_CtrlLaw05_CruiseDirection			CtrlLaw05_CruiseDirection;
_DEFSTRU_CtrlLaw06_GesturePara				CtrlLaw06_GesturePara;
_DEFSTRU_CtrlLaw07_CtrlAllocatePara			CtrlLaw07_CtrlAllocatePara;
_DEFSTRU_CtrlLaw08_SpeedPara				CtrlLaw08_SpeedPara;
_DEFSTRU_CtrlLaw09_WindSpDirection			CtrlLaw09_WindSpDirection;
_DEFSTRU_CtrlLaw0A_EngineState				CtrlLaw0A_EngineState;
_DEFSTRU_CtrlLaw0B_RemoteCtrl				CtrlLaw0B_RemoteCtrl;
_DEFSTRU_CtrlLaw0C_NavEKFPara				CtrlLaw0C_NavEKFPara;

_DEFSTRU_CtrlLaw0D_FlightCtroInfor			CtrlLaw0D_FlightCtroInfor;
_DEFSTRU_CtrlLaw0E_AttitudeDataOrigin		CtrlLaw0E_AttitudeDataOrigin;
_DEFSTRU_CtrlLaw0F_AttitudeDataDealed		CtrlLaw0F_AttitudeDataDealed;

_DEFSTRU_CtrlLaw0G_SemSimFKtoMAT			CtrlLaw0G_SemSimFKtoMAT;
_DEFSTRU_CtrlLaw0H_SemSimMATtoFK			CtrlLaw0H_SemSimMATtoFK;
_DEFSTRU_CtrlLaw0I_Matlab_Recieve1          CtrlLaw0I_Matlab_Recieve1;          

	

					
//查询数据全局变量				
_DEFSTRU_CX_FlightCtrlData					CX_FlightCtrlData;

_DEFSTRU_CXHF01_FlightCtrlData				CXHF01_FlightCtrlData;
_DEFSTRU_CXHF02_FlightCtrlData				CXHF02_FlightCtrlData;
_DEFSTRU_CXHF03_FlightCtrlData				CXHF03_FlightCtrlData;
_DEFSTRU_CXHF04_FlightCtrlData				CXHF04_FlightCtrlData;

//仿真用结构体
 _DEFSTRU_Matlab_Recieve					Trans_Matlab_Recieve;



/*---------------- 系统 全局变量，导航及控制用-----------------*/
//注意：所有角度数据单位为0.1度
//所有角速度数据单位为0.01度/秒

DEF_UINT8 CHENTIAN = 0;


//当前使用参数
//aim 
  DEF_INT16			CtrlSys_acou =0;				    //目标航线角
  DEF_INT16			CtrlSys_tay =0;						//目标偏航角 
  DEF_INT16			CtrlSys_ayy =0;				      	//通过当前点和目标点的相对位置计算出的目标航向角
//current
  DEF_INT32			CtrlSys_cLon  =0;                   //当前经度
  DEF_INT32			CtrlSys_cLat =0;					//当前纬度
  DEF_INT16			CtrlSys_cHei =0;					//当前高度
  DEF_INT16			CtrlSys_cSpe =0;					//当前速度   0.1m/s

//current differential 
  DEF_INT16			CtrlSys_cdHei =0;                   //当前升降速率
  DEF_INT16			CtrlSys_cdLerror =0;				//当前侧偏距 变化率

  DEF_DOUBLE64		CtrlSys_dphi = 0;
  DEF_DOUBLE64		CtrlSys_dtheta = 0;
  DEF_DOUBLE64		CtrlSys_dpsi = 0;
  
//准备更新参数
//CtrlSys_temp aim        --自主飞行用
  DEF_INT32			CtrlSys_taLon1 =0;                   //目标经度  
  DEF_INT32			CtrlSys_taLat1 =0;					 //目标纬度
  DEF_INT16			CtrlSys_taHei1 =0;					 //目标高度
  DEF_INT16			CtrlSys_tacou1 =0;				     //目标航线角
  DEF_UINT8			CtrlSys_isSafeMode = 0;				 //是否为安全飞行模式

  DEF_INT16			CtrlSys_cp =0;                       //当前俯仰角
  DEF_INT16			CtrlSys_cr =0;						 //当前滚转角
  DEF_UINT16		CtrlSys_cy =0;						 //当前偏航角(融合)

//CtrlSys_temp current 
  DEF_INT32			CtrlSys_tcLon =0;                     //当前经度(计算)
  DEF_INT32			CtrlSys_tcLat =0;					  //当前纬度(计算)
  DEF_INT16			CtrlSys_tcHei =0;					  //当前高度(计算)
  DEF_INT16			CtrlSys_tcSpe =0;					  //当前速度(计算)
  DEF_INT16			CtrlSys_tcLerror =0;				  //当前侧偏距 (计算)


//CtrlSys_temp current differential 
//distance
  DEF_INT32			CtrlSys_adist =0;    				  //当前点到目标航点距离,以10米为单位.
  DEF_FLOAT32		CtrlSys_tadistf =0;   				  //当前点到目标航点距离,以米为单位.

  DEF_FLOAT32		CtrlSys_LTLK = 1;
  
  DEF_DOUBLE64		CtrlSys_Thro= 0;
  DEF_DOUBLE64		CtrlSys_Thro_LeftFront = 0;
  DEF_DOUBLE64		CtrlSys_Thro_LeftBack = 0;
  DEF_DOUBLE64		CtrlSys_Thro_RightFront = 0;
  DEF_DOUBLE64		CtrlSys_Thro_RightBack= 0;
  DEF_DOUBLE64 		CtrlSys_Thro_LeftFront_Current = 0;
  DEF_DOUBLE64		CtrlSys_Thro_LeftBack_Current = 0;
  DEF_DOUBLE64		CtrlSys_Thro_RightFront_Current = 0;
  DEF_DOUBLE64		CtrlSys_Thro_RightBack_Current= 0;
  
  DEF_DOUBLE64		CtrlSys_Thro_FrontFan_Basic= 0;
  DEF_DOUBLE64		CtrlSys_Thro_FrontFan= 0; 

  
  DEF_DOUBLE64		CtrlSys_temp_sy = 0;
  DEF_DOUBLE64		CtrlSys_sy = 0;
  DEF_DOUBLE64		CtrlSys_VectorAngle= 0;
  DEF_DOUBLE64		CtrlSys_VectorAngle_Last = 0;  
  DEF_DOUBLE64		CtrlSys_VectorAngle_Current = 0;

//Initial function key parameter 
  extern DEF_UINT8	CtrlSys_Ini_State = 1;					//控制律初始化标志

  DEF_DOUBLE64 		Low_filter[2]={0,0};
  DEF_DOUBLE64 		Filter_va=0.01;

 
//-----------------载入缓冲用数组----------------------


  DEF_UINT16 CtrlSys_cHy =0;					  //当前机头方位角(融合)
  DEF_UINT16 CtrlSys_cGy =0;					  //当前航迹角(融合) 

 

//-----------------控制中间变量----------------------


 //DEF_DOUBLE CtrlSys_temp = 0;	

DEF_INT32	CtrlSys_error_yaw = 0;
DEF_INT32	CtrlSys_error_dyaw = 0;
DEF_INT32	CtrlSys_error_yaw_last = 0;

DEF_UINT8  CtrlSys_CWn =CtrlSys_HoverWay;    	 //当前航线编号
DEF_UINT8  CtrlSys_CPn =1;    					//当前航点编号

_DEFSTRU_CtrlLaw01_FlightPathInput  PathPoint[3];  //航点
_DEFSTRU_CtrlLaw01_FlightPathInput  PathPointSet[3];  //航点设置用
_DEFSTRU_CtrlLaw01_FlightPathInput  PathpointDown;  //航点下载用


DEF_INT16 CtrlSys_cdp =0;                                 //当前俯仰角速度 0.01度/秒
DEF_INT16 CtrlSys_cdr =0;				         //当前滚转角速度 0.01度/秒
DEF_INT16 CtrlSys_cdy =0;	                              //当前偏航角速度 0.01度/秒

//积分中间变量
DEF_DOUBLE64 CtrlSys_ei1_y = 0;
DEF_DOUBLE64 CtrlSys_ei2_y = 0;






/*============================================================================*
* 函数名：				Dowork_YK11_FlightCtrlDataTrans
*============================================================================*
*
* 功能：飞控相关遥控数据处理
*
* 描述: 
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/


//航线注入变量
_DEFSTRU_CtrlLaw01_FlightPathInput	FlightPath_Package[5][20];		//航线遥控指令存储
DEF_UINT8	FlightPath_PointCount[5];							//各条航线航点计数

void Dowork_YK11_FlightCtrlDataTrans()
{
	if ( YK11_FlightCtrlDataTrans.CommandCode== CtrlLaw_FlightPathInput )
		{
			bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw01_FlightPathInput),sizeof(CtrlLaw01_FlightPathInput));
			if ((CtrlLaw01_FlightPathInput.PathNO<=5)&&(CtrlLaw01_FlightPathInput.PointCount<=20)&&((CtrlLaw01_FlightPathInput.PointNO<=(CtrlLaw01_FlightPathInput.PointCount))))
				{
					FlightPath_PointCount[(CtrlLaw01_FlightPathInput.PathNO-1)]=CtrlLaw01_FlightPathInput.PointCount;	
					bcopy(&CtrlLaw01_FlightPathInput,&(FlightPath_Package[(CtrlLaw01_FlightPathInput.PathNO-1)][(CtrlLaw01_FlightPathInput.PointNO-1)]),sizeof(CtrlLaw01_FlightPathInput));

					//遥控回复成功
					YKCX_Answer_State_Date((DEF_UINT8*)(&CtrlLaw01_FlightPathInput),sizeof(CtrlLaw01_FlightPathInput),YK_ANSWER_SUCCESS);
				}
			else
				{
					//遥控回复条件不具备无法执行
					YKCX_Answer_State_Date((DEF_UINT8*)(&CtrlLaw01_FlightPathInput),sizeof(CtrlLaw01_FlightPathInput),YK_ANSWER_ERR_LACK);		
				}
		}
	else
		{
			switch (YK11_FlightCtrlDataTrans.CommandCode )
				{
					case	CtrlLaw_CruiseCirclePara:
								{
									bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw02_CruiseCirclePara),sizeof(CtrlLaw02_CruiseCirclePara));
									YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw02_CruiseCirclePara),YK_ANSWER_SUCCESS);
									break;
								}
					
					case	CtrlLaw_StayModePara:
								{
									bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw03_StayModePara),sizeof(CtrlLaw03_StayModePara));
									YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw03_StayModePara),YK_ANSWER_SUCCESS);
									break;
								}
					case	CtrlLaw_TrajPlanPara:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw04_TrajPlanPara),sizeof(CtrlLaw04_TrajPlanPara));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw04_TrajPlanPara),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_CruiseDirection:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw05_CruiseDirection),sizeof(CtrlLaw05_CruiseDirection));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw05_CruiseDirection),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_GesturePara:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw06_GesturePara),sizeof(CtrlLaw06_GesturePara));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw06_GesturePara),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_CtrlAllocatePara:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw07_CtrlAllocatePara),sizeof(CtrlLaw07_CtrlAllocatePara));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw07_CtrlAllocatePara),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_SpeedPara:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw08_SpeedPara),sizeof(CtrlLaw08_SpeedPara));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw08_SpeedPara),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_WindSpDirection:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw09_WindSpDirection),sizeof(CtrlLaw09_WindSpDirection));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw09_WindSpDirection),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_EngineState:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw0A_EngineState),sizeof(CtrlLaw0A_EngineState));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw0A_EngineState),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_RemoteCtrl:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw0B_RemoteCtrl),sizeof(CtrlLaw0B_RemoteCtrl));
								//YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw0B_RemoteCtrl),YK_ANSWER_SUCCESS);
								break;
							}
					case	CtrlLaw_NavEKFPara:
							{
								bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw0C_NavEKFPara),sizeof(CtrlLaw0C_NavEKFPara));
								YKCX_Answer_State_Date((DEF_UINT8*)(&YK11_FlightCtrlDataTrans),sizeof(CtrlLaw0C_NavEKFPara),YK_ANSWER_SUCCESS);
								break;
							}
					default: break;	
				}
			
		}
}


 
/*============================================================================*
* 函数名：				Dowork_CX_FlightCtrlData
*============================================================================*
*
* 功能：飞控相关查询指令处理
*
* 描述: 
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/

DEF_UINT8	i_ForCXFlightPath;		//航点信息计数
DEF_UINT8	Count_FlightPath;		//航点个数
DEF_UINT8	LineNO_FlightPath;		//航线编号

void Dowork_CX_FlightCtrlData()
{


 	//航线数据查询指令
	if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX01_FlightCtrl01)
		{
			Count_FlightPath = FlightPath_PointCount[CX_FlightCtrlData.Reserved_5[0]-1];
			//前4 个字节
			bcopy(&(CX_FlightCtrlData),&(CXHF01_FlightCtrlData),4);
			if((CX_FlightCtrlData.Reserved_5[0]<=5)&&(CX_FlightCtrlData.Reserved_5[1]<=20)&&(Count_FlightPath>0))
				{
					LineNO_FlightPath = CX_FlightCtrlData.Reserved_5[0];

					for(i_ForCXFlightPath=0;i_ForCXFlightPath<Count_FlightPath;i_ForCXFlightPath++)
						{
							//组帧
							bcopy(&(FlightPath_Package[LineNO_FlightPath-1][i_ForCXFlightPath].PathNO),&(CXHF01_FlightCtrlData.PathNO),(sizeof(CXHF01_FlightCtrlData)-4));
							
							//遥控回复形式下传
							YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF01_FlightCtrlData),sizeof(CXHF01_FlightCtrlData),CX_ANSWER_SUCCESS);
						}	
				}
			else
				{
					//遥控回复查询失败
					YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF01_FlightCtrlData),sizeof(CXHF01_FlightCtrlData),CX_ANSWER_ERR_LACK);
				}
		}
	
	
	//控制参数查询指令
	else if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX02_FlightCtrl02 )
		{
			//组帧
			//飞控参数查询第1 帧
			bcopy(&(CX_FlightCtrlData),&(CXHF02_FlightCtrlData),4);
			CXHF02_FlightCtrlData.CommandCode = MSGDATA_CX02_FlightCtrl02;
			
			bcopy(&(CtrlLaw02_CruiseCirclePara.CruiseCircleLong),&(CXHF02_FlightCtrlData.CruiseCircleLong),12);
			bcopy(&(CtrlLaw03_StayModePara.HomeLong),&(CXHF02_FlightCtrlData.HomeLong),16);
			bcopy(&(CtrlLaw04_TrajPlanPara.Para_kcpt),&(CXHF02_FlightCtrlData.Para_kcpt),28);
			bcopy(&(CtrlLaw05_CruiseDirection.CruiseDirection),&(CXHF02_FlightCtrlData.CruiseDirection),4);
			bcopy(&(CtrlLaw06_GesturePara.Para_kypt),&(CXHF02_FlightCtrlData.Para_kypt),28);
			//遥控回复形式下传
			//飞控参数查询第1 帧
			YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF02_FlightCtrlData),sizeof(CXHF02_FlightCtrlData),CX_ANSWER_SUCCESS);
		}

	else if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX03_FlightCtrl03 )
		{
			//组帧
			//飞控参数查询第2 帧
			bcopy(&(CX_FlightCtrlData),&(CXHF03_FlightCtrlData),4);
			CXHF03_FlightCtrlData.CommandCode = MSGDATA_CX03_FlightCtrl03;
			
			bcopy(&(CtrlLaw07_CtrlAllocatePara.CAPara1),&(CXHF03_FlightCtrlData.CAPara1),24);
			bcopy(&(CtrlLaw08_SpeedPara.Para_kvp),&(CXHF03_FlightCtrlData.Para_kvp),14);
			bcopy(&(CtrlLaw09_WindSpDirection.WindSet_H_Angle),&(CXHF03_FlightCtrlData.WindSet_H_Angle),8);
			bcopy(&(CtrlLaw0A_EngineState.Propeller1),&(CXHF03_FlightCtrlData.Propeller1),7);


			//遥控回复形式下传
			//飞控参数查询第2 帧
			YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF03_FlightCtrlData),sizeof(CXHF03_FlightCtrlData),CX_ANSWER_SUCCESS);
		}
	
	else if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX04_FlightCtrl04 )
		{
			//组帧
			//飞控参数查询第3帧
			bcopy(&(CX_FlightCtrlData),&(CXHF04_FlightCtrlData),4);
			CXHF04_FlightCtrlData.CommandCode = MSGDATA_CX04_FlightCtrl04;
			
			bcopy(&(CtrlLaw0C_NavEKFPara.PitchAngleQ),&(CXHF04_FlightCtrlData.PitchAngleQ),sizeof(CtrlLaw0C_NavEKFPara));
			

			//遥控回复形式下传
			//飞控参数查询第3帧
			YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF04_FlightCtrlData),sizeof(CXHF04_FlightCtrlData),CX_ANSWER_SUCCESS);
		}

}



/*============================================================================*
* 函数名：							CtrlInfor_Update
*============================================================================*
*
* 功能：控制律所用数据更新
*
* 描述: 根据具体需求，决定使用惯导类型，决定是否需要滤波
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
 void CtrlInfor_Update(void)
	{
		//判断飞行模式是否改变
		if(CtrlLaw0D_FlightCtroInfor.FlightMode != g_YC_Package.TJ.FlightMode)
			{CtrlLaw0D_FlightCtroInfor.FlightMode = g_YC_Package.TJ.FlightMode;
			CtrlLaw_ini();}

		

		//位置和速度采用惯导输出参数
		if( All_YCFast_Package.TJ.FK_UseINS != 0x01 )	//主惯导
			{
			CtrlLaw0D_FlightCtroInfor.Height = g_YC_Package.HD01.INSAlt;
			CtrlLaw0D_FlightCtroInfor.FlightLong = g_YC_Package.HD01.INSLon * 1e7;
			CtrlLaw0D_FlightCtroInfor.FlightLat = g_YC_Package.HD01.INSLat * 1e7;				
			CtrlLaw0D_FlightCtroInfor.EastVelo = g_YC_Package.HD01.East_V;
			CtrlLaw0D_FlightCtroInfor.NorthVelo = g_YC_Package.HD01.North_V;
			CtrlLaw0D_FlightCtroInfor.VertiVelo = g_YC_Package.HD01.Up_V;
			
			CtrlLaw0D_FlightCtroInfor.PitchAngle = g_YC_Package.HD01.Pitch;
			CtrlLaw0D_FlightCtroInfor.RollAngle = g_YC_Package.HD01.Roll;
			CtrlLaw0D_FlightCtroInfor.HeadAngle = g_YC_Package.HD01.Yaw;
			CtrlLaw0D_FlightCtroInfor.XAngleRate = g_YC_Package.HD01.RollSpeed;
			CtrlLaw0D_FlightCtroInfor.YAngleRate = g_YC_Package.HD01.PitchSpeed;
			CtrlLaw0D_FlightCtroInfor.ZAngleRate = g_YC_Package.HD01.YawSpeed;		
			
			}
		else 	//备惯导
			{			
			CtrlLaw0D_FlightCtroInfor.Height = All_YCFast_Package.HD02.InsAlt;
			CtrlLaw0D_FlightCtroInfor.FlightLong = All_YCFast_Package.HD02.InsLon * 1e7;
			CtrlLaw0D_FlightCtroInfor.FlightLat = All_YCFast_Package.HD02.InsLat * 1e7;				
			CtrlLaw0D_FlightCtroInfor.EastVelo = All_YCFast_Package.HD02.East_V;
			CtrlLaw0D_FlightCtroInfor.NorthVelo = All_YCFast_Package.HD02.North_V;
			CtrlLaw0D_FlightCtroInfor.VertiVelo = All_YCFast_Package.HD02.Up_V;

			CtrlLaw0D_FlightCtroInfor.PitchAngle = All_YCFast_Package.HD02.Pitch;
			CtrlLaw0D_FlightCtroInfor.RollAngle = All_YCFast_Package.HD02.Roll;
			CtrlLaw0D_FlightCtroInfor.HeadAngle = All_YCFast_Package.HD02.Yaw;
			CtrlLaw0D_FlightCtroInfor.XAngleRate = All_YCFast_Package.HD02.RollSpeed;
			CtrlLaw0D_FlightCtroInfor.YAngleRate = All_YCFast_Package.HD02.PitchSpeed;
			CtrlLaw0D_FlightCtroInfor.ZAngleRate = All_YCFast_Package.HD02.YawSpeed;				
			}

		//执行机构状态
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftFront = g_YC_Package.TJ.AirscrewActualN[0];
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftBack = g_YC_Package.TJ.AirscrewActualN[1];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightFront = g_YC_Package.TJ.AirscrewActualN[2];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightBack = g_YC_Package.TJ.AirscrewActualN[3];
		CtrlLaw0D_FlightCtroInfor.Propeller_Front = g_YC_Package.TJ.AirscrewActualN[4];
		CtrlLaw0D_FlightCtroInfor.VectorAngle=g_YC_Package.TJ.VectorAngle;
	}	


/*============================================================================*
* 函数名：							SemSim_Update
*============================================================================*
*
* 功能：仿真用数据更新
*
* 描述: 使用Matlab传入飞行数据作为实际飞行数据
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/

 void SemSim_Update(void)
	{
		//判断飞行模式是否改变
		if(CtrlLaw0D_FlightCtroInfor.FlightMode != g_YC_Package.TJ.FlightMode)
			{CtrlLaw0D_FlightCtroInfor.FlightMode = g_YC_Package.TJ.FlightMode;
			CtrlLaw_ini();}
		
		CtrlLaw0D_FlightCtroInfor.FlightMode = g_YC_Package.TJ.FlightMode;

		CtrlLaw0D_FlightCtroInfor.Height = CtrlLaw0H_SemSimMATtoFK.FlightAlt;			
		CtrlLaw0D_FlightCtroInfor.FlightLong = CtrlLaw0H_SemSimMATtoFK.FlightLong;
		CtrlLaw0D_FlightCtroInfor.FlightLat = CtrlLaw0H_SemSimMATtoFK.FlightLat;			
		CtrlLaw0D_FlightCtroInfor.EastVelo = CtrlLaw0H_SemSimMATtoFK.EastVelo* 100;
		CtrlLaw0D_FlightCtroInfor.NorthVelo = CtrlLaw0H_SemSimMATtoFK.NorthVelo* 100;
		CtrlLaw0D_FlightCtroInfor.VertiVelo = CtrlLaw0H_SemSimMATtoFK.VertiVelo* 100;		

		CtrlLaw0D_FlightCtroInfor.PitchAngle = CtrlLaw0H_SemSimMATtoFK.PitchAngle* 10000;
		CtrlLaw0D_FlightCtroInfor.RollAngle = CtrlLaw0H_SemSimMATtoFK.RollAngle* 10000;
		CtrlLaw0D_FlightCtroInfor.HeadAngle = CtrlLaw0H_SemSimMATtoFK.HeadAngle * 10000;
		CtrlLaw0D_FlightCtroInfor.XAngleRate = CtrlLaw0H_SemSimMATtoFK.XAngleRate* 1000;
		CtrlLaw0D_FlightCtroInfor.YAngleRate = CtrlLaw0H_SemSimMATtoFK.YAngleRate* 1000;
		CtrlLaw0D_FlightCtroInfor.ZAngleRate = CtrlLaw0H_SemSimMATtoFK.ZAngleRate* 1000;
			
		//执行机构状态
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftFront = g_YC_Package.TJ.AirscrewActualN[0];
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftBack = g_YC_Package.TJ.AirscrewActualN[1];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightFront = g_YC_Package.TJ.AirscrewActualN[2];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightBack = g_YC_Package.TJ.AirscrewActualN[3];
		CtrlLaw0D_FlightCtroInfor.Propeller_Front = g_YC_Package.TJ.AirscrewActualN[4];
		CtrlLaw0D_FlightCtroInfor.VectorAngle=g_YC_Package.TJ.VectorAngle;	

	}	


/*============================================================================*
* 函数名：							CtrlInfor_EKF
*============================================================================*
*
* 功能：控制律所用数据滤波
*
* 描述: 每隔0.08s调用一次
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
DEF_FLOAT32		CtrlSys_dt = 0.08;
DEF_FLOAT32		PPitch[4] = { 100*10000, 0, 0, 100*1000 };
DEF_FLOAT32    	PYaw[4] = { 100*10000, 0, 0, 100*1000 };
DEF_FLOAT32   	PRoll[4] = { 100*10000, 0, 0, 100*1000 };
DEF_FLOAT32		QPitchAngle = 1*10000;  			//俯仰角状态协方差
DEF_FLOAT32		QPitchAngleRate = 1*1000; 		//俯仰角速度状态协方差
DEF_FLOAT32		RPitchAngle =100*10000; 			//俯仰角输出协方差
DEF_FLOAT32		RPitchAngleRate = 100*1000; 		//俯仰角速度输出协方差
DEF_FLOAT32		QYawAngle = 1*10000;				//偏航角状态协方差
DEF_FLOAT32		QYawAngleRate = 1*1000;			//偏航角速度状态协方差
DEF_FLOAT32		RYawAngle = 100*10000;			//偏航角输出协方差
DEF_FLOAT32		RYawAngleRate = 100*1000;		//偏航角速度输出协方差
DEF_FLOAT32		QRollAngle = 1*10000;				//滚转角状态协方差
DEF_FLOAT32		QRollAngleRate = 1*1000;			//滚转角速度输出协方差
DEF_FLOAT32		RRollAngle = 100*10000;			//滚转角输出协方差
DEF_FLOAT32		RRollAngleRate = 100*1000;		//滚转角速度输出协方差	 

DEF_FLOAT32		EKF_Gain[4] = {0,0,0,0};


void CtrlInfor_EKF(void)
{
     DEF_FLOAT32 a, b, c, d, m, n, p, q;
     //滤波参数更新
	 QPitchAngle = CtrlLaw0C_NavEKFPara.PitchAngleQ;
	 QPitchAngleRate = CtrlLaw0C_NavEKFPara.PitchAngleRateQ;
	 RPitchAngle = CtrlLaw0C_NavEKFPara.PitchAngleR;
	 RPitchAngleRate = CtrlLaw0C_NavEKFPara.PitchAngleRateR;

	 QYawAngle = CtrlLaw0C_NavEKFPara.YawAngleQ;
	 QYawAngleRate = CtrlLaw0C_NavEKFPara.YawAngleRateQ;
	 RYawAngle = CtrlLaw0C_NavEKFPara.YawAngleR;
	 RYawAngleRate = CtrlLaw0C_NavEKFPara.YawAngleRateR;

	 QRollAngle = CtrlLaw0C_NavEKFPara.RollAngleQ;
	 QRollAngleRate = CtrlLaw0C_NavEKFPara.RollAngleRateQ;
	 RRollAngle = CtrlLaw0C_NavEKFPara.RollAngleR;
	 RRollAngleRate = CtrlLaw0C_NavEKFPara.RollAngleRateR;

	 //原始数据更新
	 if( YK04_NavCtrl.FK_UseINS == 0x11 )
		{
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngle 		= g_YC_Package.HD01.Pitch;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngle 		= g_YC_Package.HD01.Roll;
		 CtrlLaw0E_AttitudeDataOrigin.HeadAngle 		= g_YC_Package.HD01.Yaw;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngleRate 	= g_YC_Package.HD01.RollSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate 	= g_YC_Package.HD01.PitchSpeed;
		 CtrlLaw0D_FlightCtroInfor.ZAngleRate 			= g_YC_Package.HD01.PitchSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchDA 			= g_YC_Package.HD01.Double_Antenna_Pitch;          //双天线俯仰
		 CtrlLaw0E_AttitudeDataOrigin.YawDA 			= g_YC_Package.HD01.Double_Antenna_Heading;        //双天线航向
	 	}
	 else if( YK04_NavCtrl.FK_UseINS == 0x22 )
	 	{
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngle 		= g_YC_Package.HD02.Pitch;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngle 		= g_YC_Package.HD02.Roll;
		 CtrlLaw0E_AttitudeDataOrigin.HeadAngle 		= g_YC_Package.HD02.Yaw;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngleRate 	= g_YC_Package.HD02.RollSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate 	= g_YC_Package.HD02.PitchSpeed;
		 CtrlLaw0D_FlightCtroInfor.ZAngleRate 			= g_YC_Package.HD02.PitchSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchDA 			= g_YC_Package.HD02.Double_Antenna_Pitch;          //双天线俯仰
		 CtrlLaw0E_AttitudeDataOrigin.YawDA 			= g_YC_Package.HD02.Double_Antenna_Heading;        //双天线航向
	 	}
	 
	 /* 俯仰角滤波 */
	 //Project the state ahead
	 CtrlLaw0F_AttitudeDataDealed.PitchAngle += CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate*CtrlSys_dt;
	 //Project the error covariance ahead
	 PPitch[0] += QPitchAngle;
	 PPitch[3] += QPitchAngleRate;
	 //Compute the Kalman gain
	 a = PPitch[0] + RPitchAngle;
	 b = PPitch[1];
	 c = PPitch[2];
	 d = PPitch[3] + RPitchAngleRate;
	 m = d / (a*d - b*c);
	 n = -b / (a*d - b*c);
	 p = -c / (a*d - b*c);
	 q = a / (a*d - b*c);
	 EKF_Gain[0] = m*PPitch[0] + p*PPitch[1];
	 EKF_Gain[1] = n*PPitch[0] + q*PPitch[1];
	 EKF_Gain[2] = m*PPitch[2] + p*PPitch[3];
	 EKF_Gain[3] = n*PPitch[2] + q*PPitch[3];
	 //Update estimate with measurement
	 a = EKF_Gain[0]*(CtrlLaw0E_AttitudeDataOrigin.PitchDA - CtrlLaw0F_AttitudeDataDealed.PitchAngle) + EKF_Gain[1] * (CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate - CtrlLaw0F_AttitudeDataDealed.PitchAngleRate);
	 b = EKF_Gain[2] * (CtrlLaw0E_AttitudeDataOrigin.PitchDA - CtrlLaw0F_AttitudeDataDealed.PitchAngle) + EKF_Gain[3] * (CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate - CtrlLaw0F_AttitudeDataDealed.PitchAngleRate);
	 CtrlLaw0F_AttitudeDataDealed.PitchAngle += a;
	 CtrlLaw0F_AttitudeDataDealed.PitchAngleRate += b;
	 //Update error covariance
	 a = (1 - EKF_Gain[0])*PPitch[0] - EKF_Gain[1] * PPitch[2];
	 b = (1 - EKF_Gain[0])*PPitch[1] - EKF_Gain[1] * PPitch[3];
	 c = (1 - EKF_Gain[3])*PPitch[2] - EKF_Gain[2] * PPitch[0];
	 d = (1 - EKF_Gain[3])*PPitch[3] - EKF_Gain[2] * PPitch[1];
	 PPitch[0] = a;
	 PPitch[1] = b;
	 PPitch[2] = c;
	 PPitch[3] = d;

	 /* 偏航角滤波 */
	 //Project the state ahead
	 CtrlLaw0F_AttitudeDataDealed.HeadAngle += CtrlLaw0E_AttitudeDataOrigin.YawAngleRate*CtrlSys_dt;
	 //Project the error covariance ahead
	 PYaw[0] += QYawAngle;
	 PYaw[3] += QYawAngleRate;
	 //Compute the Kalman gain
	 a = PYaw[0] + RYawAngle;
	 b = PYaw[1];
	 c = PYaw[2];
	 d = PYaw[3] + RYawAngleRate;
	 m = d / (a*d - b*c);
	 n = -b / (a*d - b*c);
	 p = -c / (a*d - b*c);
	 q = a / (a*d - b*c);
	 EKF_Gain[0] = m*PYaw[0] + p*PYaw[1];
	 EKF_Gain[1] = n*PYaw[0] + q*PYaw[1];
	 EKF_Gain[2] = m*PYaw[2] + p*PYaw[3];
	 EKF_Gain[3] = n*PYaw[2] + q*PYaw[3];
	 //Update estimate with measurement
	 a = EKF_Gain[0]*(CtrlLaw0E_AttitudeDataOrigin.YawDA - CtrlLaw0F_AttitudeDataDealed.HeadAngle) + EKF_Gain[1] * (CtrlLaw0E_AttitudeDataOrigin.YawAngleRate - CtrlLaw0F_AttitudeDataDealed.YawAngleRate);
	 b = EKF_Gain[2] * (CtrlLaw0E_AttitudeDataOrigin.YawDA - CtrlLaw0F_AttitudeDataDealed.HeadAngle) + EKF_Gain[3] * (CtrlLaw0E_AttitudeDataOrigin.YawAngleRate - CtrlLaw0F_AttitudeDataDealed.YawAngleRate);
	 CtrlLaw0F_AttitudeDataDealed.HeadAngle += a;
	 CtrlLaw0F_AttitudeDataDealed.YawAngleRate += b;
	 //Update error covariance
	 a = (1 - EKF_Gain[0])*PYaw[0] - EKF_Gain[1] * PYaw[2];
	 b = (1 - EKF_Gain[0])*PYaw[1] - EKF_Gain[1] * PYaw[3];
	 c = (1 - EKF_Gain[3])*PYaw[2] - EKF_Gain[2] * PYaw[0];
	 d = (1 - EKF_Gain[3])*PYaw[3] - EKF_Gain[2] * PYaw[1];
	 PYaw[0] = a;
	 PYaw[1] = b;
	 PYaw[2] = c;
	 PYaw[3] = d;



	  /* 滚转角滤波 */
	 //Project the state ahead
	 CtrlLaw0F_AttitudeDataDealed.RollAngle += CtrlLaw0E_AttitudeDataOrigin.RollAngleRate*CtrlSys_dt;
	 //Project the error covariance ahead
	 PRoll[0] += QRollAngle;
	 PRoll[3] += QRollAngleRate;
	 //Compute the Kalman gain
	 a = PRoll[0] + RRollAngle;
	 b = PRoll[1];
	 c = PRoll[2];
	 d = PRoll[3] + RRollAngleRate;
	 m = d / (a*d - b*c);
	 n = -b / (a*d - b*c);
	 p = -c / (a*d - b*c);
	 q = a / (a*d - b*c);
	 EKF_Gain[0] = m*PRoll[0] + p*PRoll[1];
	 EKF_Gain[1] = n*PRoll[0] + q*PRoll[1];
	 EKF_Gain[2] = m*PRoll[2] + p*PRoll[3];
	 EKF_Gain[3] = n*PRoll[2] + q*PRoll[3];
	 //Update estimate with measurement
	 a = EKF_Gain[0]*(CtrlLaw0E_AttitudeDataOrigin.RollAngle - CtrlLaw0F_AttitudeDataDealed.RollAngle) + EKF_Gain[1] * (CtrlLaw0E_AttitudeDataOrigin.RollAngleRate - CtrlLaw0F_AttitudeDataDealed.RollAngleRate);
	 b = EKF_Gain[2] * (CtrlLaw0E_AttitudeDataOrigin.RollAngle - CtrlLaw0F_AttitudeDataDealed.RollAngle) + EKF_Gain[3] * (CtrlLaw0E_AttitudeDataOrigin.RollAngleRate - CtrlLaw0F_AttitudeDataDealed.RollAngleRate);
	 CtrlLaw0F_AttitudeDataDealed.RollAngle += a;
	 CtrlLaw0F_AttitudeDataDealed.RollAngleRate += b;
	 //Update error covariance
	 a = (1 - EKF_Gain[0])*PRoll[0] - EKF_Gain[1] * PRoll[2];
	 b = (1 - EKF_Gain[0])*PRoll[1] - EKF_Gain[1] * PRoll[3];
	 c = (1 - EKF_Gain[3])*PRoll[2] - EKF_Gain[2] * PRoll[0];
	 d = (1 - EKF_Gain[3])*PRoll[3] - EKF_Gain[2] * PRoll[1];
	 PRoll[0] = a;
	 PRoll[1] = b;
	 PRoll[2] = c;
	 PRoll[3] = d;	

}







	
/*============================================================================*
* 函数名：							Ctrl_Para_Init
*============================================================================*
*
* 功能：飞控参数初始化
*
* 描述:    飞控数据初始化
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
void Ctrl_Para_Init(void)
  	{
		
		//飞行模式初始化
		CtrlLaw0D_FlightCtroInfor.FlightMode = g_YC_Package.TJ.FlightMode;

		//驻留区域初始化
		CtrlLaw03_StayModePara.HomeLat = 7727057;
		CtrlLaw03_StayModePara.HomeLong = 20217942;
		CtrlLaw03_StayModePara.BufferAreaDist = 0;
		CtrlLaw03_StayModePara.HomeHeight = 20000;
		CtrlLaw03_StayModePara.CoreAreaDist = 5000;
		CtrlLaw03_StayModePara.TotalAreaDist = 5000;
		

		//内环参数初始化
		CtrlLaw06_GesturePara.Para_kypt = 1;
		CtrlLaw06_GesturePara.Para_kyp1= 1.8;
		CtrlLaw06_GesturePara.Para_kyp2= 2;
		CtrlLaw06_GesturePara.Para_kyi = 360;
		CtrlLaw06_GesturePara.Para_kyd = 15;
		CtrlLaw06_GesturePara.Para_kyth = 0;
		CtrlLaw06_GesturePara.Para_kylimit= 900;
		
		CtrlLaw05_CruiseDirection.CruiseDirection = 0.52;
		
	
		//外环参数初始化
		CtrlLaw04_TrajPlanPara.Para_kcpt = 1;
		CtrlLaw04_TrajPlanPara.Para_kcp1 = 0.06;
		CtrlLaw04_TrajPlanPara.Para_kcp2 = 0.06;
		CtrlLaw04_TrajPlanPara.Para_kci = 0;
		CtrlLaw04_TrajPlanPara.Para_kcd = 0;
		CtrlLaw04_TrajPlanPara.Para_kcth = 0;
		CtrlLaw04_TrajPlanPara.Para_kclimit = 900;

		//风场设置
		CtrlLaw09_WindSpDirection.WindSet_H_Angle = 0;
		CtrlLaw09_WindSpDirection.WindSpSet_H = 0;
		CtrlLaw09_WindSpDirection.WindSpSet_V = 0;

		//巡航圆参数初始化
		CtrlLaw02_CruiseCirclePara.CruiseCircleRadius = 8000;
		CtrlLaw02_CruiseCirclePara.PreTurningLen = 100;
	
		//控制分配参数初始化
		CtrlLaw07_CtrlAllocatePara.CAPara1 = 0.67;
		CtrlLaw07_CtrlAllocatePara.CAPara2 = 0;
		CtrlLaw07_CtrlAllocatePara.CAPara3 = 1;
		CtrlLaw07_CtrlAllocatePara.CAPara4 = 6000;
		CtrlLaw07_CtrlAllocatePara.CAPara5 = 0;
		CtrlLaw07_CtrlAllocatePara.CAPara6 = 0;

		//执行机构状态初始化
		CtrlLaw0A_EngineState.Propeller1= 0;
		CtrlLaw0A_EngineState.Propeller2 = 0;
		CtrlLaw0A_EngineState.Propeller3 = 0;
		CtrlLaw0A_EngineState.Propeller4 = 0;
		CtrlLaw0A_EngineState.Propeller_Front= 0;	


		//滤波参数更新
		QPitchAngle = 10000;  			//俯仰角状态协方差
		QPitchAngleRate = 1000; 			//俯仰角速度状态协方差
		RPitchAngle =1000000; 			//俯仰角输出协方差
		RPitchAngleRate = 100000; 		//俯仰角速度输出协方差
		QYawAngle = 10000;				//偏航角状态协方差
		QYawAngleRate = 1000;			//偏航角速度状态协方差
		RYawAngle = 1000000;			//偏航角输出协方差
		RYawAngleRate = 100000;			//偏航角速度输出协方差
		QRollAngle = 10000;				//滚转角状态协方差
		QRollAngleRate = 1000;			//滚转角速度输出协方差
		RRollAngle = 1000000;			//滚转角输出协方差
		RRollAngleRate = 100000;			//滚转角速度输出协方差	 
		
  	}



/*============================================================================*
* 函数名：							CopyWP
*============================================================================*
*
* 功能：航点复制函数
*
* 描述:    将航点P2中数据复制到P1中
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/

//航点复制P2-->P1
DEF_UINT8 CopyWP(_DEFSTRU_CtrlLaw01_FlightPathInput*P1, _DEFSTRU_CtrlLaw01_FlightPathInput*P2)
{


	    (*P1).PathNO = (*P2).PathNO;
	    (*P1).PointCount = (*P2).PointCount;
	    (*P1).PointNO = (*P2).PointNO;
	    (*P1).PointTask = (*P2).PointTask;
	    (*P1).PointLong = (*P2).PointLong;
	    (*P1).PointLat = (*P2).PointLat;	
	    (*P1).PreTurningLen = (*P2).PreTurningLen;
	    (*P1).PathChange = (*P2).PathChange;	     
	    (*P1).PathRestart = (*P2).PathRestart;
         
		
	   return TRUE;  
}

/*============================================================================*
* 函数名：							ReadWP
*============================================================================*
*
* 功能：航点读取函数
*
* 描述:    读取下一个航点
*
* 注意：可能待修改!!!!!!!!
*
* 参数：	Wn: 航线编号
			Pn:  航点编号
			P :  目标位置
*
* RETURENS：
*
*============================================================================*/

_DEFSTRU_CtrlLaw01_FlightPathInput	Trans_PathPoint;	

DEF_UINT8 ReadWP(DEF_UINT8 Wn, DEF_UINT8 Pn, _DEFSTRU_CtrlLaw01_FlightPathInput *P)
{
	  DEF_UINT16 Page=0;
	  DEF_UINT16 Offset=0;
	  DEF_UINT8  CtrlSys_Result=TRUE;

	/*
	 if ( Pn == PathPoint[CtrlSys_LastPoint].PointCount)
	 	{
		 	Wn = Wn+1;
		 	Pn = 1;
	 	}
	 else 
	 	{
		 	Wn = Wn;
		 	Pn = Pn + 1;
	 	}

	*/

	 
	  //一般航线
	  if((Wn>=1)&&(Wn<=MaxPathNum)&&(Pn<=MaxPointNum)&&(Pn>=1))
	   {

		bcopy(&((FlightPath_Package[Wn-1][Pn-1])),&(Trans_PathPoint),sizeof(Trans_PathPoint));
			
	        
	         CtrlSys_Result &= CopyWP(P,&(Trans_PathPoint));   		  
		  		  
		  //if((Pn >=  (*P).PointCount)||( (*P).PointCount > MaxPointNum)||( ((*P).PathNO&0x0F) != Wn)||((*P).PointNO != (Pn+1)))
		  	//CtrlSys_Result = FALSE;	
	   }
	   else CtrlSys_Result = FALSE;

	   return CtrlSys_Result;   
}






/*============================================================================*
* 函数名：							Navigation
*============================================================================*
*
* 功能：水平面导航函数
*
* 描述:    根据当前状态计算当前航点到目标航点的航向角、距离与侧偏距
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
  DEF_INT32 CtrlSys_aLon =0;                             //目标经度
  DEF_INT32 CtrlSys_aLat =0;				 //目标纬度



DEF_UINT8 Navigation(void)
	{ 
		DEF_FLOAT32  CtrlSys_temp=0; 		   
		  
	    //更新数据   
	    CtrlSys_aLon = CtrlSys_taLon1;
		CtrlSys_aLat = CtrlSys_taLat1;	     
		CtrlSys_acou = CtrlSys_tacou1;
		
	    CtrlSys_cLon = CtrlSys_tcLon;
		CtrlSys_cLat = CtrlSys_tcLat;  
			  
	    // 计算当前航点到目标航点的航向角
	    CtrlSys_ayy=Cal_Point(CtrlSys_cLon, CtrlSys_cLat,CtrlSys_aLon, CtrlSys_aLat,&CtrlSys_tadistf);
	      
	    //当前点到当前目标点的距离
	    CtrlSys_adist = (DEF_INT32)CtrlSys_tadistf/10.0;  
	    if(CtrlSys_adist >60000)
			CtrlSys_adist = 60000;
		
	    //当前点到当前航线的侧偏距
	    CtrlSys_tcLerror = Cal_LineError( CtrlSys_ayy,  CtrlSys_acou, CtrlSys_tadistf);      

			
	    return TRUE;
	}



/*============================================================================*
* 函数名：							SwitchWP
*============================================================================*
*
* 功能：航点切换函数
*
* 描述:    根据当前距离与提前转弯量的关系，确认切换方式
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/


DEF_UINT8 SwitchWP(void)
{
   DEF_FLOAT32  CtrlSys_SwitchWP_temp=0;   
   
   DEF_UINT8   CtrlSys_Result=TRUE;  
   static DEF_FLOAT32 CtrlSys_LastLineDist = 0;
      
   // 按提前量过线切换航点（默认）      
   //计算距离
   CtrlSys_SwitchWP_temp =  Cal_LineDist( CtrlSys_ayy,  CtrlSys_acou, CtrlSys_tadistf);
  
   if(CtrlSys_SwitchWP_temp>(DEF_FLOAT32)(PathPoint[CtrlSys_CurrentPoint].PreTurningLen))			//未达到提前转弯距离，则不进行切换
   
           return  FALSE;
   
   else																					//达到提前转弯距离，进行切换
   	{
		   if(PathPoint[CtrlSys_CurrentPoint].PathChange == FALSE)			
		   { 
		    	    //正常切换
			   CopyWP(&PathPoint[CtrlSys_LastPoint],&PathPoint[CtrlSys_CurrentPoint]); 	   
					
			   //读取下一个航点	   
			   
			   CtrlSys_CPn++;
		             
			   if(CtrlSys_CPn>PathPoint[CtrlSys_CurrentPoint].PointCount)				//此航点为该航线最后一个航点
			     {
		               if(PathPoint[CtrlSys_CurrentPoint].PathRestart != FALSE)  				//循环航线
				 {
				 	CtrlSys_CPn = 1;
					
				 }		 
				 else
				 {
				      /*------------------------转到安全模式------------------------*/
					  //在当前位置做区域驻留
					CtrlSys_isSafeMode = TRUE;
					CopyWP(&PathPoint[CtrlSys_TempPoint],&PathPoint[CtrlSys_CurrentPoint]); //当前航点存入临时寄存器
					
				 }	
			      }	   


			   else															//非最后一个航点
			      {CtrlSys_CPn = CtrlSys_CPn;}

			  
			   if(CtrlSys_CWn< CtrlSys_HoverWay)							  //普通用户航线(直线飞行)
			   {
			          CtrlSys_Result &= ReadWP(PathPoint[CtrlSys_LastPoint].PathNO, CtrlSys_CPn, &PathPoint[CtrlSys_CurrentPoint]);
		                 if(CtrlSys_Result == TRUE)
				    {		 	 
					    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
					    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
					   	              
					    CtrlSys_tacou1 = Cal_Point(PathPoint[CtrlSys_LastPoint].PointLong, PathPoint[CtrlSys_LastPoint].PointLat, PathPoint[CtrlSys_CurrentPoint].PointLong, PathPoint[CtrlSys_CurrentPoint].PointLat, &CtrlSys_LastLineDist);   
						  
				    }
				    else
				    {
					   CtrlSys_isSafeMode= TRUE; //如果航点不正确 则切到安全模式
					   CtrlSys_CPn = 1;	
					   CopyWP(&PathPoint[CtrlSys_TempPoint],&PathPoint[CtrlSys_LastPoint]); //当前航点存入临时寄存器
				    }

			   }


			   
		          if(CtrlSys_CWn==CtrlSys_HoverWay) //盘旋航线
			   {	

				    PathPoint[CtrlSys_CurrentPoint].PointCount = 8;
				    //PathPoint[CtrlSys_TempPoint] 作为盘旋航线的参考点
		    	     	    //然后将当前航点变换成绝对航点
		    	     	    //整个圆周分成8个点,    

				
				            
			           if(CtrlSys_LTLK != 0)
		                      {  PathPoint[CtrlSys_CurrentPoint].PointLong = PathPoint[CtrlSys_LastPoint].PointLong + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*cos(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0)/CtrlSys_LTLK;}
				    else 
					  PathPoint[CtrlSys_CurrentPoint].PointLong =0;
					
				    PathPoint[CtrlSys_CurrentPoint].PointLat =  PathPoint[CtrlSys_LastPoint].PointLat + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*sin(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0); 

				    PathPoint[CtrlSys_CurrentPoint].PointNO = CtrlSys_CPn;
				    PathPoint[CtrlSys_CurrentPoint].PathChange = 0x00;  //不支持制式切换
					    
				    PathPoint[CtrlSys_CurrentPoint].PathRestart =TRUE; //循环   //盘旋航线自动循环
				    PathPoint[CtrlSys_CurrentPoint].PreTurningLen =CtrlLaw02_CruiseCirclePara.PreTurningLen; //提前转弯量	    

				    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
				    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
	              
				    CtrlSys_tacou1 = Cal_Point(PathPoint[CtrlSys_LastPoint].PointLong, PathPoint[CtrlSys_LastPoint].PointLat, PathPoint[CtrlSys_CurrentPoint].PointLong, PathPoint[CtrlSys_CurrentPoint].PointLat, &CtrlSys_LastLineDist);   
			
				    
			   }
		   	
			         
		    }
		  
		   else 							 //切换到安全模式
		   {
		       //默认切换到安全模式
		   	   //切换到安全模式
			    
			    CtrlSys_isSafeMode = TRUE;
				
		   	    CopyWP(&PathPoint[CtrlSys_LastPoint],&PathPoint[CtrlSys_CurrentPoint]); 
			    CopyWP(&PathPoint[CtrlSys_TempPoint],&PathPoint[CtrlSys_CurrentPoint]);  //当前航点存入临时寄存器	

		             	   
		    }    
		   
   	
   		return TRUE; 
   	}
}




/*============================================================================*
* 函数名：							WPInit
*============================================================================*
*
* 功能：航点初始化函数
*
* 描述:    初始化航点，先将航点读入到PathPoint[CtrlSys_LastPoint]，如果航点正常再拷贝到PathPoint[CtrlSys_CurrentPoint]
*		     防止读入不正常又将PathPoint[CtrlSys_CurrentPoint]中的当前航点冲掉的问题
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
DEF_UINT8 WPInit(DEF_UINT8 Wn, DEF_UINT8 Pn)
	{
	   DEF_UINT8  CtrlSys_Result=TRUE;

	   //先将航点读入到PathPoint[CtrlSys_LastPoint]，如果航点正常再拷贝到PathPoint[CtrlSys_CurrentPoint]
	   //防止读入不正常又将PathPoint[CtrlSys_CurrentPoint]中的当前航点冲掉的问题
	   if(Wn < CtrlSys_HoverWay)
		   {
		         CtrlSys_Result &= ReadWP(Wn, Pn, &PathPoint[CtrlSys_LastPoint]);
				
			  if(CtrlSys_Result == TRUE)
			   {
			       //航点读入正常
				    CtrlSys_CWn = Wn;  
				    CtrlSys_CPn = Pn;   		
				  
				    CopyWP(&PathPoint[CtrlSys_CurrentPoint],&PathPoint[CtrlSys_LastPoint]); 
				     //将目标经纬度高度导引到当前航点上
				    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
				    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
			    }
		   }
	   if(Wn >= CtrlSys_HoverWay)    //盘旋航线   
		   {
		            //切换到盘旋航线
			    CtrlSys_CWn = CtrlSys_HoverWay;

			    if((CtrlSys_cHy>=0)&&(CtrlSys_cHy<450))
			    {
		                  CtrlSys_CPn = 4;
			    }
			    else if((CtrlSys_cHy>=450)&&(CtrlSys_cHy<900))
			    {
		                  CtrlSys_CPn = 3;
			    }
			    else if((CtrlSys_cHy>=900)&&(CtrlSys_cHy<1350))
			    {
		                  CtrlSys_CPn = 2;
			    }
			    else if((CtrlSys_cHy>=1350)&&(CtrlSys_cHy<1800))
			    {
		                  CtrlSys_CPn = 1;
			    }
			    else if((CtrlSys_cHy>=1800)&&(CtrlSys_cHy<2250))
			    {
		                  CtrlSys_CPn = 8;
			    }
			    else if((CtrlSys_cHy>=2250)&&(CtrlSys_cHy<2700))
			    {
		                  CtrlSys_CPn = 7;
			    }
			    else if((CtrlSys_cHy>=2700)&&(CtrlSys_cHy<3150))
			    {
		                  CtrlSys_CPn = 6;
			    }
			    else
			    {
		                  CtrlSys_CPn = 5;
			    }		

	            //盘旋航线时，PathPoint[CtrlSys_TempPoint]作为盘旋航线的参考点
	            //初始化时如果恰好为盘旋航线，则以当前点为参考点
	            //所以将当前点的经度、纬度存入PathPoint[CtrlSys_TempPoint]
	            PathPoint[CtrlSys_TempPoint].PointLong =  CtrlSys_tcLon;
			    PathPoint[CtrlSys_TempPoint].PointLat  =  CtrlSys_tcLat;


			    //然后将当前航点变换成绝对航点
			    PathPoint[CtrlSys_CurrentPoint].PointCount = 8;

			    if(CtrlSys_LTLK!= 0)
		            PathPoint[CtrlSys_CurrentPoint].PointLong = PathPoint[CtrlSys_TempPoint].PointLong + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*cos(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0)/CtrlSys_LTLK;
			    else 
					PathPoint[CtrlSys_CurrentPoint].PointLong = 0;
			    	PathPoint[CtrlSys_CurrentPoint].PointLat =  PathPoint[CtrlSys_TempPoint].PointLat + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*sin(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0); 
			
			   
			   
			    PathPoint[CtrlSys_CurrentPoint].PathChange = 0x00;  //不支持制式航线嵌套	
			       
			    PathPoint[CtrlSys_CurrentPoint].PathRestart = 0x10; //循环   //盘旋航线自动循环
			    PathPoint[CtrlSys_CurrentPoint].PreTurningLen = CtrlLaw02_CruiseCirclePara.PreTurningLen; //提前转弯	    	    

			    //将目标经纬度高度导引到当前航点上
			    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
			    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
			
	  	 }

  
    return CtrlSys_Result;   
}





/*============================================================================*
* 函数名：							NavInit
*============================================================================*
*
* 功能：导航数据初始化函数
*
* 描述:    初始化导航数据，求解目标航线角
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/


  DEF_INT32 CtrlSys_taLon2 =0;                                   //目标经度  
  DEF_INT32 CtrlSys_taLat2 =0;					  //目标纬度
  DEF_INT16 CtrlSys_taHei2 =0;					  //目标高度
  DEF_INT16 CtrlSys_tacou2 =0;				         //目标航线角


 DEF_UINT8 NavInit(DEF_UINT8 ID)
 {
   DEF_FLOAT32  CtrlSys_temp=0;   
          if(ID == 1)
          {
                  //导航数据初始化——用GPS数据
	         CtrlSys_tacou1 = Cal_Point(CtrlSys_tcLon, CtrlSys_tcLat, CtrlSys_taLon1, CtrlSys_taLat1, &CtrlSys_temp); 				 
		  	 
		  return TRUE;   
          }
	   else if (ID == 2)
	   {	        
	   	  CtrlSys_tacou2 = Cal_Point(CtrlSys_tcLon, CtrlSys_tcLat, CtrlSys_taLon2, CtrlSys_taLat2, &CtrlSys_temp); 
		     
		  return TRUE;   
	   }	
    return FALSE;   
}




/*============================================================================*
* 函数名：							Cal_Point
*============================================================================*
*
* 功能：计算两点间角度和距离函数
*
* 描述:    计算两点间角度和距离
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/

DEF_INT16 Cal_Point(DEF_INT32 P1Lo, DEF_INT32 P1La, DEF_INT32 P2Lo, DEF_INT32 P2La, DEF_FLOAT32 *plen)
{
	  double temp_n=0,temp_e=0;
	  DEF_FLOAT32 angle=0;
	  DEF_INT16 cou=0;

	  
	  temp_n= P2La - P1La;

	  CtrlSys_LTLK=cos((double)P1La/10000000.0);
	  
	  temp_e=(P2Lo - P1Lo)*CtrlSys_LTLK;
	  
	  *plen = (DEF_FLOAT32)sqrt(temp_n*temp_n+temp_e*temp_e);  
	  
	  //计算航向角
	  angle=0;
	  
	  if((*plen) > 0)
		  {
			angle = acos(temp_n/(*plen));  //与N轴的夹角
		    if(temp_e>=0)
		   	{
			    angle =angle *572.96f;  //57.296*10   单位0.1度
			}
		    else
			{
			    angle = 3600-angle *572.96f;  //57.296*10 单位0.1度
			}
		  }
	  
	  if (angle >= 3600)
		  {
		    angle=angle - 3600;
		  }
	  
	  else if (angle < 0)
		  {
		    angle=angle + 3600;
		  }
	  
	  cou=(DEF_INT16)angle;
	  
	  // 限制cou 在0到359内
	  if(cou<0)
	  	cou=0;
	  
	  else if(cou>3599)
	  	cou=3599; 
	  
	  *plen = (*plen)*(CtrlSys_MtMk/1000.0);//距离单位转换为米
	  
	  return cou;	 
}



/*============================================================================*
* 函数名：							Cal_LineError
*============================================================================*
*
* 功能：计算当前位置距离航线的侧偏距
*
* 描述:   计算 侧偏距	destcou 为当前点到目标航点的航向角  linecou为当前航段的航向角，
		    plen为当前点到目标点的距离
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/

DEF_FLOAT32  Cal_LineError(DEF_INT16 destcou,DEF_INT16 linecou, DEF_FLOAT32 plen)
	{
		   
		   DEF_FLOAT32 lerror;  //侧偏距
		   DEF_INT16 CtrlSys_temp;  //临时变量
		  

		   CtrlSys_temp = destcou-linecou;
		   
		   if(CtrlSys_temp > 1800)
			   {
			       CtrlSys_temp =-(3600-CtrlSys_temp);
			   }
		   if(CtrlSys_temp<-1800)
			   {
			       CtrlSys_temp=3600+CtrlSys_temp;
			   }
		   
		   lerror = (DEF_FLOAT32)(plen*sin(((DEF_FLOAT32)CtrlSys_temp/572.96f)));// 计算侧偏距   
		   
		   return lerror;
	}



/*============================================================================*
* 函数名：							Cal_LineDist
*============================================================================*
*
* 功能：计算当前点沿航线方向到目标点的距离
*
* 描述:  	destcou 当前偏航角，linecou航线角，plen两点间距离

* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
DEF_FLOAT32  Cal_LineDist(DEF_INT16 destcou,DEF_INT16 linecou, DEF_FLOAT32 plen)
{
  
   DEF_FLOAT32 LDistance;  //侧偏距
   DEF_INT16 CtrlSys_temp;  //临时变量
  

   CtrlSys_temp = destcou-linecou;
   
   if(CtrlSys_temp > 1800)
	   {
	       CtrlSys_temp =-(3600-CtrlSys_temp);
	   }
   if(CtrlSys_temp<-1800)
	   {
	       CtrlSys_temp=3600+CtrlSys_temp;
	   }
   
   LDistance = (DEF_FLOAT32)(plen*cos(((DEF_FLOAT32)CtrlSys_temp/572.96f)));// 计算侧偏距   
   
   return LDistance;
}






/*============================================================================*
* 函数名：			Line_Guidance_Law
*============================================================================*
*
* 功能：平面制导律计算
*
* 描述: 平面制导律控制计算，生成期望  偏航角
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
void Line_Guidance_Law(void)
{

	Navigation();
	OutLoop_Track();
	SwitchWP();
}



/*============================================================================*
* 函数名：			Circle_Guidance_Law
*============================================================================*
*
* 功能：平面制导律计算
*
* 描述: 平面制导律控制计算，生成期望  偏航角
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
void Circle_Guidance_Law(void)
{
	Navigation();
	OutLoop_Track();
	SwitchWP();
}






/*============================================================================*
* 函数名：			CtrlLaw_ini
*============================================================================*
*
* 功能：控制律初始化函数,每次飞行模式改变时，调用一次
*
* 描述: 切换控制模式时需执行该函数1次
*
* 注意：
*
* 参数：	
*
* RETURENS：
*
*============================================================================*/
void CtrlLaw_ini(void)
{
	switch(CtrlLaw0D_FlightCtroInfor.FlightMode)
		{
	
		//航点飞行
		case FlightModel_GoPoint_1:
				{
					CHENTIAN =10;
			
			        //读取第一个航点
				bcopy(&((FlightPath_Package[0][0]).PathNO),&(Trans_PathPoint.PathNO),sizeof(Trans_PathPoint)-4);
							   
				CopyWP(&PathPoint[CtrlSys_CurrentPoint],&(Trans_PathPoint));
				
	                 	CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
		           	CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 1;
				CtrlSys_CPn = 1;

				break;
			}
		case FlightModel_GoPoint_2:
				{
			
			        //读取第一个航点
				bcopy(&((FlightPath_Package[1][0]).PathNO),&(Trans_PathPoint.PathNO),sizeof(Trans_PathPoint));
							   
				CopyWP(&PathPoint[CtrlSys_CurrentPoint],&(Trans_PathPoint));
				
	                 	CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
		           	CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 2;
				CtrlSys_CPn = 1;

				break;
			}
		case FlightModel_GoPoint_3:
				{
			
			        //读取第一个航点
				bcopy(&((FlightPath_Package[2][0]).PathNO),&(Trans_PathPoint.PathNO),sizeof(Trans_PathPoint));
							   
				CopyWP(&PathPoint[CtrlSys_CurrentPoint],&(Trans_PathPoint));
				
	                 	CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
		           	CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 3;
				CtrlSys_CPn = 1;

				break;
			}
		case FlightModel_GoPoint_4:
				{
			
			        //读取第一个航点
				bcopy(&((FlightPath_Package[3][0]).PathNO),&(Trans_PathPoint.PathNO),sizeof(Trans_PathPoint));
							   
				CopyWP(&PathPoint[CtrlSys_CurrentPoint],&(Trans_PathPoint));
				
	                 	CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
		           	CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 4;
				CtrlSys_CPn = 1;

				break;
			}
		case FlightModel_GoPoint_5:				
			{
			
			        //读取第一个航点
				bcopy(&((FlightPath_Package[4][0]).PathNO),&(Trans_PathPoint.PathNO),sizeof(Trans_PathPoint));
							   
				CopyWP(&PathPoint[CtrlSys_CurrentPoint],&(Trans_PathPoint));
				
	                 	CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
		           	CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 5;
				CtrlSys_CPn = 1;

				break;
			}	

		
		//盘旋航线
		case 0x50:
			{
		  		 //盘旋航线时，PathPoint[CtrlSys_TempPoint]作为盘旋航线的参考点
	                       //初始化时如果恰好为盘旋航线，则以当盘旋点为参考点
	                       //所以将盘旋点的经度、纬度、高度存入PathPoint[CtrlSys_TempPoint]
			       PathPoint[CtrlSys_TempPoint].PointLong = CtrlSys_tcLon;
			       PathPoint[CtrlSys_TempPoint].PointLat = CtrlSys_tcLat;	   
			
				   
				if((CtrlSys_cHy>=0)&&(CtrlSys_cHy<450))
				    {
			                  CtrlSys_CPn = 3;
				    }
				    else if((CtrlSys_cHy>=450)&&(CtrlSys_cHy<900))
				    {
			                  CtrlSys_CPn = 2;
				    }
				    else if((CtrlSys_cHy>=900)&&(CtrlSys_cHy<1350))
				    {
			                  CtrlSys_CPn = 1;
				    }
				    else if((CtrlSys_cHy>=1350)&&(CtrlSys_cHy<1800))
				    {
			                  CtrlSys_CPn = 8;
				    }
				    else if((CtrlSys_cHy>=1800)&&(CtrlSys_cHy<2250))
				    {
			                  CtrlSys_CPn = 7;
				    }
				    else if((CtrlSys_cHy>=2250)&&(CtrlSys_cHy<2700))
				    {
			                  CtrlSys_CPn = 6;
				    }
				    else if((CtrlSys_cHy>=2700)&&(CtrlSys_cHy<3150))
				    {
			                  CtrlSys_CPn = 5;
				    }
				    else
				    {
			                  CtrlSys_CPn = 4;
				    }		
		                     
			 	//然后将当前航点变换成绝对航点
			     	 if(CtrlSys_LTLK!= 0)
					PathPoint[CtrlSys_CurrentPoint].PointLong = PathPoint[CtrlSys_TempPoint].PointLong + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*cos(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0)/CtrlSys_LTLK;
			        else 
					PathPoint[CtrlSys_CurrentPoint].PointLong =0;

				PathPoint[CtrlSys_CurrentPoint].PointLat =  PathPoint[CtrlSys_TempPoint].PointLat + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*sin(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0); 
			         
				PathPoint[CtrlSys_CurrentPoint].PointCount = 8;
				PathPoint[CtrlSys_CurrentPoint].PointNO = CtrlSys_CPn;
				CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
			       CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 6;
				
			
			      break;
			}

				  
	
		default: break;	

		}


	
	
	NavInit(1);	
		

	//期望偏航角归零
	CtrlSys_tay = 0;

	//控制状态量清零
	CtrlSys_error_yaw = 0;

	CtrlSys_ei2_y = 0;
	CtrlSys_ei1_y = 0;            //误差积分
	CtrlSys_isSafeMode = FALSE;
		
	
}



/*============================================================================*
* 函数名：			OutLoop_Track
*============================================================================*
*
* 功能：  航向外环控制律  
*
* 描述:    	利用侧偏距求解目标航向角
*
*
*============================================================================*/
DEF_INT16 CtrlSys_aly = 0;				      		  //通过侧偏距计算出的目标航向角
DEF_INT16 CtrlSys_cLerror = 0;				         //当前侧偏距 




void OutLoop_Track(void)
{
	//侧偏距---> 目标航向角   10Hz
	//侧偏距---> 目标航向角   10Hz		
	DEF_INT32 error = 0, CtrlSys_OutLoop_Track_temp_1 = 0, CtrlSys_OutLoop_Track_temp_2 = 0;     
	
	//载入缓冲数据
    CtrlSys_cLerror = CtrlSys_tcLerror;	
    CtrlSys_cSpe = CtrlSys_tcSpe;   //0.1m/s

	//计算航向角与侧偏距偏差
	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_cGy - CtrlSys_acou;	
	
	if( CtrlSys_OutLoop_Track_temp_1 > 1800 )
	   {
	     CtrlSys_OutLoop_Track_temp_1 = -( 3600 - CtrlSys_OutLoop_Track_temp_1 );
	   }
	
	else if( CtrlSys_OutLoop_Track_temp_1 < -1800 )
	   {
	     CtrlSys_OutLoop_Track_temp_1 = 3600 + CtrlSys_OutLoop_Track_temp_1;
	   }

	if(abs(CtrlSys_OutLoop_Track_temp_1) < 900)   
	   {
		  //侧偏距微分  0.1m/s
		   CtrlSys_cdLerror = (DEF_FLOAT32)(CtrlSys_cSpe*sin(((DEF_FLOAT32)CtrlSys_OutLoop_Track_temp_1/572.96f)));// 计算侧偏距微分量 
				
          //求解误差
		   error = CtrlSys_cLerror; 
			
		  //如果没有超过门限值，则目标航向角为0
		   if (error < CtrlLaw04_TrajPlanPara.Para_kcth && error > -CtrlLaw04_TrajPlanPara.Para_kcth)
		   		{					         
					CtrlSys_aly = 0;
					CtrlSys_OutLoop_Track_temp_1 = CtrlSys_aly; //侧偏距导航   
		       		CtrlSys_ei1_y = 0;
					CtrlSys_tay = CtrlSys_OutLoop_Track_temp_1; 			
		    	}
		   else
		   		{
					//计算比例的值
					if( error > CtrlSys_kcth || error < -CtrlSys_kcth )
						{
							//如果在第二段内
							if( error > 0 )
								CtrlSys_OutLoop_Track_temp_1 = CtrlLaw04_TrajPlanPara.Para_kcp1 * CtrlSys_kcth + CtrlLaw04_TrajPlanPara.Para_kcp2 * ( error - CtrlSys_kcth );	
							else
								CtrlSys_OutLoop_Track_temp_1 = -CtrlLaw04_TrajPlanPara.Para_kcp1 * CtrlSys_kcth + CtrlLaw04_TrajPlanPara.Para_kcp2 * ( error + CtrlSys_kcth );	
						}
					else
						{
							//如果在第一段内
							CtrlSys_OutLoop_Track_temp_1 = CtrlLaw04_TrajPlanPara.Para_kcp1 * error;
						}
			
					//计算微分的值  CtrlSys_cdLerror  0.1m/s
			      	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 - CtrlSys_cdLerror * CtrlLaw04_TrajPlanPara.Para_kcd / 10.0;
				
					//计算积分的值
					if ( error < CtrlSys_icth && error > -CtrlSys_icth )
						{
							//计算误差的积分
							CtrlSys_ei1_y= CtrlSys_ei1_y + error; 
							if(CtrlSys_ei1_y>100000)
								CtrlSys_ei1_y =100000;
							else if(CtrlSys_ei1_y<-100000)
								CtrlSys_ei1_y = -100000;
							CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 + CtrlSys_ei1_y * CtrlLaw04_TrajPlanPara.Para_kci / 100000.0;		  
						}
					else
						{
							//超出积分开启的范围，积分无效，并设置误差的积分为0
							CtrlSys_ei1_y = 0;
						}
				
			      	//总比例控制
			     	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 * CtrlLaw04_TrajPlanPara.Para_kcpt*10.0;   //放大10倍，是因为计算时角度值单位为 0.1度

	              	//输出限位			                  
					if ( CtrlSys_OutLoop_Track_temp_1 > CtrlLaw04_TrajPlanPara.Para_kclimit )
						CtrlSys_OutLoop_Track_temp_1 = CtrlLaw04_TrajPlanPara.Para_kclimit;
				    else if ( CtrlSys_OutLoop_Track_temp_1 < -CtrlLaw04_TrajPlanPara.Para_kclimit )
						CtrlSys_OutLoop_Track_temp_1 = -CtrlLaw04_TrajPlanPara.Para_kclimit;							

		   		
			   } 
	   	}
	   	
	else  
		{
	       //如果当前值与目标相差过大，则aly = CtrlSys_acou;   
	       //防止目标航向在转弯过程中发生方向性变化
	       CtrlSys_OutLoop_Track_temp_1 = 0;
		   
		}
				   
	//输出
	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 + CtrlSys_acou;  	

	if(CtrlSys_OutLoop_Track_temp_1 < 0)
		CtrlSys_OutLoop_Track_temp_1 += 3600;
	else if(CtrlSys_OutLoop_Track_temp_1 >= 3600)
		CtrlSys_OutLoop_Track_temp_1 -= 3600;
	
	// 输出限制在0到359内
	if (CtrlSys_OutLoop_Track_temp_1 > 3599)
		CtrlSys_OutLoop_Track_temp_1 = 3599;
	else if (CtrlSys_OutLoop_Track_temp_1 < 0)
		CtrlSys_OutLoop_Track_temp_1 = 0;   
	
					 
	CtrlSys_aly = CtrlSys_OutLoop_Track_temp_1;		
	CtrlSys_tay = CtrlSys_aly;

}
 


/*============================================================================*
* 函数名：			Yaw_Track
*============================================================================*
*
* 功能：跟踪期望偏航角
*
* 描述:    
*
*
*============================================================================*/

  
  DEF_DOUBLE64 CtrlSys_cdy1 = 0;
  DEF_DOUBLE64 CtrlSys_d1=0;
  DEF_DOUBLE64 CtrlSys_d = 0;
  
void Yaw_Track(void)
{
	/*--------------------------跟踪期望偏航角--------------------------*/

			CtrlSys_temp_sy = 0; 
			CtrlSys_error_yaw = 0;
			//偏航角误差
			if (CtrlSys_tay<0)
				CtrlSys_tay = CtrlSys_tay + 3600;
			else if (CtrlSys_tay>3600)
				CtrlSys_tay = CtrlSys_tay-3600;
			
			CtrlSys_error_yaw = CtrlSys_tay - CtrlSys_cy;		
			CtrlSys_error_dyaw = CtrlSys_error_yaw -CtrlSys_error_yaw_last;
			
			//如果没有超过门限值，则方向舵角为0			
			if ( CtrlSys_error_yaw < CtrlLaw06_GesturePara.Para_kyth * 10.0 && CtrlSys_error_yaw > -CtrlLaw06_GesturePara.Para_kyth*10.0 )
				{
					CtrlSys_temp_sy =0;								 		       
			        CtrlSys_ei2_y= 0;	
				
					//输出限位
					if ( CtrlSys_temp_sy > CtrlLaw06_GesturePara.Para_kylimit )
						CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kylimit;
					else if ( CtrlSys_temp_sy < -CtrlLaw06_GesturePara.Para_kylimit )
						CtrlSys_temp_sy = -CtrlLaw06_GesturePara.Para_kylimit;
					//输出
					CtrlSys_sy = CtrlSys_temp_sy;
			 	}
			else
				{			
					if ( CtrlSys_error_yaw > 1800 )
						{
							//ay 在cy 的左侧e为负,例ay=3300,CtrlSys_cy=300 			 
							CtrlSys_error_yaw = -(3600 - CtrlSys_error_yaw);     
						}
					else if (CtrlSys_error_yaw < -1800 )
						{
							//ay在cy的右侧e为正,例ay =300,CtrlSys_cy=3300
							CtrlSys_error_yaw = 3600 + CtrlSys_error_yaw;         
						}

				//当偏差太大时，右转逻辑
				//if (CtrlSys_error_yaw > 1500 || CtrlSys_error_yaw < -1500)
			   		// CtrlSys_error_yaw = 1500;
				  
				//计算比例的值
				if( CtrlSys_error_yaw > CtrlSys_kyth || CtrlSys_error_yaw < -CtrlSys_kyth )
					{
						//如果在第二段内
						if(CtrlSys_error_yaw > 0)
							CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kyp1 * CtrlSys_kyth + CtrlLaw06_GesturePara.Para_kyp2 * ( CtrlSys_error_yaw - CtrlSys_kyth );	
						else
							CtrlSys_temp_sy = -CtrlLaw06_GesturePara.Para_kyp1 * CtrlSys_kyth + CtrlLaw06_GesturePara.Para_kyp2 * ( CtrlSys_error_yaw + CtrlSys_kyth );	
					}
				else
					{
						//如果在第一段内
						CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kyp1 * CtrlSys_error_yaw;
					}
				

				//计算积分的值
				if (CtrlSys_error_yaw < CtrlSys_iyth && CtrlSys_error_yaw > -CtrlSys_iyth)
					{
						//计算误差的积分
						CtrlSys_ei2_y = CtrlSys_ei2_y + CtrlSys_error_yaw/10.0; 

						if(CtrlSys_ei2_y>1000)

							CtrlSys_ei2_y =1000;

						else if(CtrlSys_ei2_y<-1000)

							CtrlSys_ei2_y = -1000;

						CtrlSys_temp_sy = CtrlSys_temp_sy + CtrlSys_ei2_y * CtrlLaw06_GesturePara.Para_kyi / 1000.0;
					}
				else
					{
					        //超出积分开启的范围，积分无效，并设置误差的积分为0
					         CtrlSys_ei2_y = 0;
					} 
				
					

				//计算微分的值
				CtrlSys_cdy =  CtrlSys_error_yaw_last - CtrlSys_error_yaw;
				
				CtrlSys_temp_sy = CtrlSys_temp_sy - CtrlSys_cdy * CtrlLaw06_GesturePara.Para_kyd;

				//CtrlSys_d = CtrlSys_cdy*CtrlLaw06_GesturePara.Para_kyd/10.0;
				//CtrlSys_temp_sy = CtrlSys_temp_sy - ((1.0-CtrlLaw06_GesturePara.Para_kyth)*CtrlSys_d + CtrlLaw06_GesturePara.Para_kyth*CtrlSys_d1);
				//CtrlSys_d1 = CtrlSys_d; 										

				//总比例控制
				CtrlSys_temp_sy = CtrlSys_temp_sy * CtrlLaw06_GesturePara.Para_kypt;

				//输出限位
				if ( CtrlSys_temp_sy > CtrlLaw06_GesturePara.Para_kylimit )
					CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kylimit;
				else if ( CtrlSys_temp_sy < -CtrlLaw06_GesturePara.Para_kylimit )
					CtrlSys_temp_sy = -CtrlLaw06_GesturePara.Para_kylimit;
				//输出
				//CtrlSys_sy = CtrlSys_temp_sy;

				

			/*-----------------输出滤波-----------------------*/
			Filter_va =  CtrlLaw07_CtrlAllocatePara.CAPara5;
		    Low_filter[1]=CtrlSys_temp_sy;//存放本次采样值
			CtrlSys_temp_sy=(1-Filter_va)*Low_filter[1]+Filter_va*Low_filter[0];   //计算本次滤波值
			CtrlSys_sy = CtrlSys_temp_sy;
			Low_filter[0]=CtrlSys_sy;    //保存上次滤波值

			}	
			
	CtrlSys_error_yaw_last = CtrlSys_error_yaw;
}

/*============================================================================*
* 函数名：			Brennschluss
*============================================================================*
*
* 功能：执行器保持熄火
*
* 描述:    升空、下降模式保持熄火状态
*
*
*============================================================================*/
void Brennschluss(void)
	{
		CtrlSys_Thro_LeftFront = 0;			//左前螺旋桨转速
		CtrlSys_Thro_LeftBack = 0;			//左后螺旋桨转速
		CtrlSys_Thro_RightFront = 0;			//右前螺旋桨转速
		CtrlSys_Thro_RightBack =  0;			//右后螺旋桨转速
		CtrlSys_Thro_FrontFan = 0;			//前部风扇转速
		CtrlSys_VectorAngle= 0;				//矢量装置转角	

	}



/*============================================================================*
* 函数名：			Wind_Resist
*============================================================================*
*
* 功能：抗风飞行
*
* 描述:    偏航角跟踪风向
*
*
*============================================================================*/
void Wind_Resist(void)
	{
		//设定期望偏航角为抗风场值，即为当前风向角+ pi
		DEF_UINT32 temp_CruiseDerection = 0;
		temp_CruiseDerection = CtrlLaw09_WindSpDirection.WindSet_H_Angle * 10000.0 + CtrlSys_PI * 10000.0;
		if (temp_CruiseDerection > 62800)
			{
				CtrlSys_tay = (temp_CruiseDerection - 62800)*0.18/CtrlSys_PI;	//单位为0.1度
				
			}

		else
			{
				CtrlSys_tay = temp_CruiseDerection*0.18/CtrlSys_PI;	//单位为0.1度
			}
		//跟踪期望偏航角
		Yaw_Track();
	}





/*============================================================================*
* 函数名：			Line_Path_Track
*============================================================================*
*
* 功能：航点飞行
*
* 描述:    根据航点飞行
*
*
*============================================================================*/
void Line_Path_Track(void)
{
	Line_Guidance_Law();
	Yaw_Track();
}




/*============================================================================*
* 函数名：			Circle_Path_Track
*============================================================================*
*
* 功能：盘旋飞行
*
* 描述:   绕定点定半径飞行
*
*
*============================================================================*/
void Circle_Path_Track()
{
	Circle_Guidance_Law();
	
	Yaw_Track();
}





/*============================================================================*
* 函数名：			Remote_Control
*============================================================================*
*
* 功能： 遥控飞行
*
* 描述:   由地面站发送遥控信号进行控制
*
*
*============================================================================*/



void Remote_Control(void)
{
	if (CtrlLaw0B_RemoteCtrl.CtrlMode== FlightModel_RCCtrl_Fault)				/*故障模式*/					/*正常工作模式*/
		{
		CtrlSys_Thro_LeftFront=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*左1螺旋桨*/
		CtrlSys_Thro_LeftBack=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*左2螺旋桨*/
		CtrlSys_Thro_RightFront=CtrlLaw0B_RemoteCtrl.Propeller_Right/10.0;		/*右1螺旋桨*/
		CtrlSys_Thro_RightBack=CtrlLaw0B_RemoteCtrl.Propeller_Right/10.0;		/*右2螺旋桨*/	
		switch (CtrlLaw0B_RemoteCtrl.Propeller_Front)
			{
				case RC_Tail_Plus:
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_Max-CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Fan_Max;}								/*前螺旋桨转速*/
					else {CtrlSys_Thro_FrontFan_Basic = CtrlSys_Thro_FrontFan_Basic+CtrlSys_Fan_change;}		
					break;
				case RC_Tail_Minus:																				
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Thro_FrontFan_Basic-CtrlSys_Fan_change;}					/*前螺旋桨转速*/
					else {CtrlSys_Thro_FrontFan_Basic = 0;}			
					break;
				default :				
					break;
			}
		switch (CtrlLaw0B_RemoteCtrl.VectorReset)
			{
				case RC_Vector_Reset:
					CtrlSys_VectorAngle=0;								/*前矢量角*/
					break;
				default:
					CtrlSys_VectorAngle=CtrlLaw0B_RemoteCtrl.VertorAngle;/*前矢量角*/
					break;
			}
		}
		
	else if (CtrlLaw0B_RemoteCtrl.CtrlMode== FlightModel_RCCtrl_Mix)							/*组合调姿模式*/
		{
			switch (CtrlLaw0B_RemoteCtrl.VectorReset)
			{
				case RC_Vector_Reset:											/*开启归零*/
					CtrlSys_VectorAngle=0;									/*前矢量角*/
					break;
				default:														/*不归零*/
					CtrlSys_VectorAngle=CtrlLaw0B_RemoteCtrl.VertorAngle;
					break;
			}
			switch (CtrlLaw0B_RemoteCtrl.Propeller_Front)
			{
				case RC_Tail_Plus:
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_Max-CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Fan_Max;}	
					else {CtrlSys_Thro_FrontFan_Basic = CtrlSys_Thro_FrontFan_Basic+CtrlSys_Fan_change;}							
					break;
				case RC_Tail_Minus:												
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Thro_FrontFan_Basic-CtrlSys_Fan_change;}			/*前螺旋桨转速*/
					else {CtrlSys_Thro_FrontFan_Basic = 0;}								
					break;
				default:																							/*不控*/					
					break;
			}

			
		CtrlSys_Thro=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0 + (CtrlLaw07_CtrlAllocatePara.CAPara1* CtrlSys_VectorAngle);		/*左1螺旋桨*/
		if (CtrlSys_Thro>CtrlSys_Pro_Max){CtrlSys_Thro_LeftFront = CtrlSys_Pro_Max;}
		else if(CtrlSys_Thro<0){CtrlSys_Thro_LeftFront = 0;}
		else {CtrlSys_Thro_LeftFront = CtrlSys_Thro;	}	
		CtrlSys_Thro_LeftBack=CtrlSys_Thro_LeftFront;										/*左2螺旋桨*/
		
		CtrlSys_Thro=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0 - (CtrlLaw07_CtrlAllocatePara.CAPara1 * CtrlSys_VectorAngle);		/*右1螺旋桨*/
		if (CtrlSys_Thro<0){CtrlSys_Thro_RightFront = 0;}	
		else if (CtrlSys_Thro >CtrlSys_Pro_Max){CtrlSys_Thro_RightFront = CtrlSys_Pro_Max;}	
		else {CtrlSys_Thro_RightFront = CtrlSys_Thro;	}
		CtrlSys_Thro_RightBack=CtrlSys_Thro_RightFront;									/*右2螺旋桨*/	
		}

	
	else 																
		{
		
			CtrlSys_Thro_LeftFront=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*左1螺旋桨*/
			CtrlSys_Thro_LeftBack=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;				/*左2螺旋桨*/
			CtrlSys_Thro_RightFront=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*右1螺旋桨*/
			CtrlSys_Thro_RightBack=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*右2螺旋桨*/
		
			switch (CtrlLaw0B_RemoteCtrl.Propeller_Front)
				{				
					case RC_Tail_Plus:													/*前部螺旋桨加速*/
						if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_Max-CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Fan_Max;}	/*前螺旋桨转速*/
						else {CtrlSys_Thro_FrontFan_Basic = CtrlSys_Thro_FrontFan_Basic+CtrlSys_Fan_change;}								
						break;
						
					case RC_Tail_Minus:																				/*前部螺旋桨减速*/
						if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Thro_FrontFan_Basic-CtrlSys_Fan_change;}			/*前螺旋桨转速*/
						else {CtrlSys_Thro_FrontFan_Basic = 0;}			
						break;
						
					default:													/*不控*/
						break;
				}
			
			switch (CtrlLaw0B_RemoteCtrl.VectorReset)
				{
					
					case RC_Vector_Reset:										/*开启归零*/
						CtrlSys_VectorAngle=0;								/*矢量角归零*/
						break;
						
					default:													/*不归零*/
						CtrlSys_VectorAngle=CtrlLaw0B_RemoteCtrl.VertorAngle;
						break;
				}



		
		}

		CtrlSys_Thro_FrontFan = CtrlSys_Thro_FrontFan_Basic * CtrlLaw07_CtrlAllocatePara.CAPara3 * sin(fabs(CtrlSys_VectorAngle*PI/1800.0));



}






/*============================================================================*
* 函数名：			Constant_Speed
*============================================================================*
*
* 功能： 定航向飞行
*
* 描述:     跟踪固定航向角飞行
*
*
*============================================================================*/

void Constant_headangle(void)
{
	CtrlSys_tay = CtrlLaw05_CruiseDirection.CruiseDirection*1800.0/CtrlSys_PI;	//单位为0.1度
	Yaw_Track();
}

/*============================================================================*
* 函数名：			Reside_Mode
*============================================================================*
*
* 功能： 区域驻留模式，在固定区域内驻留
*
* 描述:     根据设定区域驻留，在核心区域时进行抗风飞行(此时可切换任意模式)
*
*
*============================================================================*/

DEF_INT16 CtrlSys_aHoy =0;					  //通过当前点和原点的相对位置计算出的目标航向角
DEF_FLOAT32  CtrlSys_tHomeDistf =0;   				 //当前点到原点距离,以米为单位.(计算)

DEF_INT32  CtrlSys_HomeLon =0;                                    //原点经度  
DEF_INT32  CtrlSys_HomeLat =0;					  //原点纬度
DEF_UINT16  CtrlSys_HomeDist =0; 					  // 距离原点距离，单位10m
DEF_UINT16  CtrlSys_TotalDist =0; 					  // 自主飞行时，安全区域距离边界缓冲距离，单位10m(即总空域)
DEF_UINT16  CtrlSys_BufferDist =0;					  // 自主飞行时，安全区域距离边界缓冲距离，单位10m
DEF_UINT16  CtrlSys_CoreDist =0; 					  // 自主飞行时，核心区域边界距离原点距离，单位10m


void Reside_Mode(void)
{

	// 计算当前航点到原点的航向角
      CtrlSys_aHoy=Cal_Point(CtrlSys_tcLon, CtrlSys_tcLat,CtrlSys_HomeLon, CtrlSys_HomeLat,&CtrlSys_tHomeDistf);      
	  
      //当前点到原点的距离(单位10m)
      CtrlSys_HomeDist= (DEF_INT32)CtrlSys_tHomeDistf/10.0;  

	if( CtrlSys_HomeDist < CtrlSys_CoreDist )		//飞艇在核心区域内
		{
			Wind_Resist();
		}
	else{
	  	//设定原点为目标航点					    
	       CtrlSys_taLon1 = CtrlSys_HomeLon;
		CtrlSys_taLat1 = CtrlSys_HomeLat;	     
		CtrlSys_tacou1 = CtrlSys_aHoy;
		Navigation();
		OutLoop_Track();
		Yaw_Track();
				
		}
}




/*============================================================================*
* 函数名：			Control_Law
*============================================================================*
*
* 功能：自动飞行控制
*
* 描述:    切换控制模式，并完成当前模式下控制输入解算
*
*
*============================================================================*/

 
  DEF_UINT8   CtrlSys_Flight_Mode = CtrlSys_RC;           		  //飞行模式，默认为遥控模式
  DEF_UINT8   CtrlSys_Flight_State = CtrlSys_NORMAL;             //飞行状态，默认为正常


  DEF_INT32 CtrlSys_tcdp = 0;                   		   //俯仰角速度
  DEF_INT32 CtrlSys_tcdr = 0;					   //滚转角速度
  DEF_INT32 CtrlSys_tcdy = 0;				 	   //航向角速度
  
  DEF_INT16 CtrlSys_cfv = 0;   				 //当前前飞速度   0.1m/s
  DEF_INT16 CtrlSys_csv = 0; 					 //当前侧飞速度 0.1m/s  
  DEF_INT16 CtrlSys_chv = 0; 					 // 垂直速度分量0.1m/s

  DEF_DOUBLE64 CtrlSys_tcdp1 = 0;
  DEF_DOUBLE64 CtrlSys_tcdr1 = 0;
  DEF_DOUBLE64 CtrlSys_tcdy1 = 0;

  DEF_FLOAT32 CtrlSys_TempF32 = 0;

  DEF_FLOAT32 CtrlSys_T_angle = 0;
  
  DEF_DOUBLE64 CtrlSys_saturation = 200;

  DEF_UINT8	CtrlSys_CtrlAllloMode = 0x01;				//控制分配模式,初始化为模式1
 

 void Task_CtrlLaw_Operate()
 {



	/*----------1-飞控数据更新----------*/
		CtrlInfor_Update();		//实际飞行
	//SemSim_Update();		//仿真用

	/*----------2-判断飞行模式并进行相应飞行控制----------*/

		/* ----------------------2.1载入缓冲数据---------------------------*/
			//载入当前位置信息(经度、纬度、高度)			
			CtrlSys_tcLon = CtrlLaw0D_FlightCtroInfor.FlightLong;		//当前经度(计算用)，单位10-7 rad
			CtrlSys_tcLat= CtrlLaw0D_FlightCtroInfor.FlightLat;		//当前纬度(计算用)，单位10-7 rad	
			CtrlSys_tcHei = CtrlLaw0D_FlightCtroInfor.Height; 					//单位m
			
			//将当前航点存入临时寄存器
			PathPoint[CtrlSys_TempPoint].PointLong = CtrlSys_tcLon;
			PathPoint[CtrlSys_TempPoint].PointLat = CtrlSys_tcLat;
				
			//载入当前姿态角
			CtrlSys_cp = CtrlLaw0D_FlightCtroInfor.PitchAngle*0.18/CtrlSys_PI;	//单位为0.1度
			CtrlSys_cr = CtrlLaw0D_FlightCtroInfor.RollAngle*0.18/CtrlSys_PI;		//单位为0.1度
			CtrlSys_cy = CtrlLaw0D_FlightCtroInfor.HeadAngle*0.18/CtrlSys_PI;	//当前航迹向,单位为0.1度
			CtrlSys_cHy = CtrlSys_cy;
			CtrlSys_cGy = CtrlSys_cy;
			
			//载入当前速度
			CtrlSys_tcSpe = sqrt((CtrlLaw0D_FlightCtroInfor.EastVelo * CtrlLaw0D_FlightCtroInfor.EastVelo)+(CtrlLaw0D_FlightCtroInfor.NorthVelo* CtrlLaw0D_FlightCtroInfor.NorthVelo)+(CtrlLaw0D_FlightCtroInfor.VertiVelo* CtrlLaw0D_FlightCtroInfor.VertiVelo) )/10.0;   //当前地速0.1m/s(计算)
			CtrlSys_cSpe = CtrlSys_tcSpe;
			
			//载入当前角速度
			CtrlSys_tcdy = CtrlLaw0D_FlightCtroInfor.ZAngleRate*180.0/CtrlSys_PI; 
			CtrlSys_tcdp = CtrlLaw0D_FlightCtroInfor.YAngleRate*180.0/CtrlSys_PI;
			CtrlSys_tcdr = CtrlLaw0D_FlightCtroInfor.XAngleRate*180.0/CtrlSys_PI;	
			
			CtrlSys_cdy = CtrlSys_tcdy/10.0;					//当前偏航角速度,单位为0.01度/s
			CtrlSys_cdp = CtrlSys_tcdp/10.0;					//当前俯仰角速度,单位为0.01度/s
			CtrlSys_cdr =  CtrlSys_tcdr/10.0;					//当前滚转角速度,单位为0.01度/s
			/*			
			//滤波得到偏航角微分值
			CtrlSys_tcdy = (CtrlSys_tcdy + CtrlSys_tcdy1)/2.0;	//平均值滤波
			CtrlSys_tcdp = (CtrlSys_tcdp + CtrlSys_tcdp1)/2.0;	//平均值滤波
			CtrlSys_tcdr = (CtrlSys_tcdr + CtrlSys_tcdr1)/2.0;	//平均值滤波
			
			
			CtrlSys_tcdy1 = CtrlSys_tcdy;
			CtrlSys_tcdp1 = CtrlSys_tcdp;
			CtrlSys_tcdr1 = CtrlSys_tcdr;			
			
			



			//当前滚转微分 单位为0.1度/秒
			CtrlSys_dphi = CtrlSys_cdr + (CtrlSys_cdy*cos(CtrlSys_cr/10.0/180.0*CtrlSys_PI) + CtrlSys_cdp*sin(CtrlSys_cr/10.0/180.0*CtrlSys_PI))*tan(CtrlSys_cp/10.0/180.0*CtrlSys_PI);
	
			//当前俯仰微分 单位为0.1度/秒
			CtrlSys_dtheta = CtrlSys_cdp*cos(CtrlSys_cr/10.0/180.0*CtrlSys_PI)  - CtrlSys_cdy*sin(CtrlSys_cr/10.0/180.0*CtrlSys_PI);
			
			//当前航向微分 单位为0.1度/秒
			CtrlSys_dpsi = 1.0/cos((CtrlSys_cp/10.0)/180.0*CtrlSys_PI)*(CtrlSys_cdy*cos((CtrlSys_cr/10.0)/180.0*CtrlSys_PI) + CtrlSys_cdp*sin(CtrlSys_cr/10.0/180.0*CtrlSys_PI));
			*/
			
			//载入当前矢量角位置
			CtrlSys_VectorAngle_Current= CtrlLaw0D_FlightCtroInfor.VectorAngle;		
			//载入当前主推螺旋桨转速
			CtrlSys_Thro_LeftFront_Current = CtrlLaw0D_FlightCtroInfor.Propeller_LeftFront;
			CtrlSys_Thro_LeftBack_Current = CtrlLaw0D_FlightCtroInfor.Propeller_LeftBack;
			CtrlSys_Thro_RightFront_Current = CtrlLaw0D_FlightCtroInfor.Propeller_RightFront;
			CtrlSys_Thro_RightBack_Current = CtrlLaw0D_FlightCtroInfor.Propeller_RightBack;

			//计算当前速度
			CtrlSys_TempF32 = CtrlLaw0D_FlightCtroInfor.NorthVelo * cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f)+CtrlLaw0D_FlightCtroInfor.EastVelo * sin((DEF_FLOAT32)CtrlSys_cy/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f)-CtrlLaw0D_FlightCtroInfor.VertiVelo * sin((DEF_FLOAT32)CtrlSys_cp/572.96f);
			CtrlSys_cfv = CtrlSys_TempF32/10.0;   //当前前飞速度   0.1m/s
	
			CtrlSys_TempF32 = CtrlLaw0D_FlightCtroInfor.NorthVelo * (cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*sin((DEF_FLOAT32)CtrlSys_cr/572.96f) - cos((DEF_FLOAT32)CtrlSys_cr/572.96f)*sin((DEF_FLOAT32)CtrlSys_cy/572.96f))+CtrlLaw0D_FlightCtroInfor.EastVelo *( sin((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*sin((DEF_FLOAT32)CtrlSys_cr/572.96f)+cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*cos((DEF_FLOAT32)CtrlSys_cr/572.96f))+CtrlLaw0D_FlightCtroInfor.VertiVelo *( sin((DEF_FLOAT32)CtrlSys_cr/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f));
		    	CtrlSys_csv = CtrlSys_TempF32/10.0;   //当前侧飞速度 0.1m/s  
		    	
			CtrlSys_TempF32 = CtrlLaw0D_FlightCtroInfor.NorthVelo * (cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*cos((DEF_FLOAT32)CtrlSys_cr/572.96f) + sin((DEF_FLOAT32)CtrlSys_cr/572.96f)*sin((DEF_FLOAT32)CtrlSys_cy/572.96f)- sin((DEF_FLOAT32)CtrlSys_cr/572.96f)*cos((DEF_FLOAT32)CtrlSys_cy/572.96f))+CtrlLaw0D_FlightCtroInfor.EastVelo *( cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*cos((DEF_FLOAT32)CtrlSys_cr/572.96f))+CtrlLaw0D_FlightCtroInfor.VertiVelo *( cos((DEF_FLOAT32)CtrlSys_cr/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f));
			CtrlSys_chv = CtrlSys_TempF32/10.0;  // 垂直速度分量0.1m/s

			//载入驻留区域圆心信息			
			CtrlSys_HomeLon =CtrlLaw03_StayModePara.HomeLong;                              //原点经度  
		 	CtrlSys_HomeLat =CtrlLaw03_StayModePara.HomeLat;					  //原点纬度
			CtrlSys_TotalDist = CtrlLaw03_StayModePara.TotalAreaDist/10;				  //自主飞行时，总区域边界距离原点距离，单位10m
			CtrlSys_BufferDist =CtrlLaw03_StayModePara.BufferAreaDist/10; 			  // 自主飞行时，安全区域距离边界缓冲距离，单位10m
		 	CtrlSys_CoreDist = CtrlLaw03_StayModePara.CoreAreaDist/10;				 // 自主飞行时，核心区域边界距离原点距离，单位10m

			//载入飞行模式
			if( CtrlLaw0D_FlightCtroInfor.FlightMode >= 0x30&& CtrlLaw0D_FlightCtroInfor.FlightMode <=0x38)
				{
					CtrlSys_Flight_Mode = CtrlSys_AUTO;
					CtrlSys_Flight_State = CtrlSys_NORMAL;				
				}
			
			else if( CtrlLaw0D_FlightCtroInfor.FlightMode >= 0x20&& CtrlLaw0D_FlightCtroInfor.FlightMode <=0x22)
				{
					CtrlSys_Flight_Mode = CtrlSys_RC;
					CtrlSys_Flight_State = CtrlSys_NORMAL;
				}
			
			else 
				{
					CtrlSys_Flight_Mode = CtrlSys_TakeOff;
					CtrlSys_Flight_State = CtrlSys_NORMAL;
				}
			
	
		/* ----------------------2.2 控制律解算---------------------------*/
			//判断飞行模式
			if( CtrlSys_Flight_Mode ==CtrlSys_AUTO )	//自主模式
				{
					/*-----------------------根据飞行模式计算矢量偏角-------------------------*/
					switch (CtrlLaw0D_FlightCtroInfor.FlightMode)
						{							
							case 	FlightModel_SetDirection :				// 定航向飞行，定偏航角飞行
								Constant_headangle();		break;
								
							case 	FlightModel_Stay :						//抗风飞行，根据估计风场设定期望偏航角，并跟踪此偏航角
								Wind_Resist();			break;
								
							case	 FlightModel_GoPoint_1: 				//控制飞艇按航点巡航飞行，到最后一个航点时切换为区域驻留或圆巡航。
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_2 :				//控制飞艇按航点巡航飞行，到最后一个航点时切换为区域驻留或圆巡航。
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_3 :				//控制飞艇按航点巡航飞行，到最后一个航点时切换为区域驻留或圆巡航。
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_4 :				//控制飞艇按航点巡航飞行，到最后一个航点时切换为区域驻留或圆巡航。
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_5 :				//控制飞艇按航点巡航飞行，到最后一个航点时切换为区域驻留或圆巡航。
								Line_Path_Track();		break;
								
							case	 FlightModel_FlyRound :					//控制飞艇按定点盘旋，到最后一个航点时切换为区域驻留或圆巡航。
								Circle_Path_Track();	break;
									
							case	 FlightModel_Stay_Area :				//区域驻留飞行，判断飞艇位置位于指定空域内，即为抗风飞行，否则进入回家模式
								Reside_Mode();			break;
								
							default:					
								break;					
						  }

					/*-----------------------------安全模式处理----------------------------*/

					  if(CtrlSys_isSafeMode == TRUE)
					 	  {
							  CtrlSys_Flight_State = CtrlSys_UNNORMAL;
							  //抗风飞行
							  Wind_Resist();							
						   }

				     /*-----------------------计算螺旋桨转速-----------------------*/
				
					//根据控制模式，计算各螺旋桨转速
					//左侧螺旋桨
					CtrlSys_Thro_LeftFront = (1-CtrlLaw0A_EngineState.Propeller1) * (YK0A_PropellerNCtrl.AirscrewNCtrl[0] + CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);
					CtrlSys_Thro_LeftBack = (1-CtrlLaw0A_EngineState.Propeller2) * ( YK0A_PropellerNCtrl.AirscrewNCtrl[1]  + CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);
					
					//右侧螺旋桨
					CtrlSys_Thro_RightFront = (1-CtrlLaw0A_EngineState.Propeller3) * ( YK0A_PropellerNCtrl.AirscrewNCtrl[2]  -  CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);
					CtrlSys_Thro_RightBack = (1-CtrlLaw0A_EngineState.Propeller4) * ( YK0A_PropellerNCtrl.AirscrewNCtrl[3]  - CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);

					//前部螺旋桨
					CtrlSys_Thro_FrontFan_Basic = (1-CtrlLaw0A_EngineState.Propeller_Front) * YK0A_PropellerNCtrl.AirscrewNCtrl[4];
					CtrlSys_Thro_FrontFan = CtrlSys_Thro_FrontFan_Basic * CtrlLaw07_CtrlAllocatePara.CAPara3 * sin(fabs(CtrlSys_temp_sy*PI/1800.0));

										
					 /*-----------------------计算矢量偏角-----------------------*/
					//根据控制模式，计算矢量偏角
					CtrlSys_VectorAngle = CtrlSys_temp_sy;
				 	

		
					//前部矢量角速度限幅
					/*
					if ((CtrlSys_VectorAngle - CtrlSys_VectorAngle_Current) > CtrlLaw07_CtrlAllocatePara.CAPara2)
						CtrlSys_VectorAngle = CtrlSys_VectorAngle_Current + CtrlLaw07_CtrlAllocatePara.CAPara2;
					else if ((CtrlSys_VectorAngle -CtrlSys_VectorAngle_Current ) < -CtrlLaw07_CtrlAllocatePara.CAPara2)
						CtrlSys_VectorAngle = CtrlSys_VectorAngle_Current - CtrlLaw07_CtrlAllocatePara.CAPara2;
*/
					
					//矢量角位置限幅
					//前部矢量角限幅
					if (CtrlSys_VectorAngle> CtrlSys_Vect_Limit)
							CtrlSys_VectorAngle = CtrlSys_Vect_Limit;
					else if (CtrlSys_VectorAngle < -CtrlSys_Vect_Limit)
							CtrlSys_VectorAngle = -CtrlSys_Vect_Limit;
					
					/*-----------输出控制螺旋桨转速、矢量装置角度----------*/		
					//控制输出,主推螺旋桨
					//螺旋桨加减速限幅
				
					CtrlSys_Thro_LeftFront = GetLimitValue(CtrlSys_Thro_LeftFront, CtrlSys_Thro_LeftFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
					CtrlSys_Thro_LeftBack = GetLimitValue(CtrlSys_Thro_LeftBack, CtrlSys_Thro_LeftBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
					CtrlSys_Thro_RightFront = GetLimitValue(CtrlSys_Thro_RightFront, CtrlSys_Thro_RightFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
					CtrlSys_Thro_RightBack = GetLimitValue(CtrlSys_Thro_RightBack, CtrlSys_Thro_RightBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);


					//螺旋桨转速限幅
					if(CtrlSys_Thro_LeftFront<CtrlSys_Pro_Min) CtrlSys_Thro_LeftFront = CtrlSys_Pro_Min;
					else CtrlSys_Thro_LeftFront = CtrlSys_Thro_LeftFront;
					if(CtrlSys_Thro_LeftBack<CtrlSys_Pro_Min) CtrlSys_Thro_LeftBack = CtrlSys_Pro_Min;
					else CtrlSys_Thro_LeftBack = CtrlSys_Thro_LeftBack;
					if(CtrlSys_Thro_RightFront<CtrlSys_Pro_Min) CtrlSys_Thro_RightFront = CtrlSys_Pro_Min;
					else CtrlSys_Thro_RightFront = CtrlSys_Thro_RightFront;
					if(CtrlSys_Thro_RightBack<CtrlSys_Pro_Min) CtrlSys_Thro_RightBack = CtrlSys_Pro_Min;
					else CtrlSys_Thro_RightBack = CtrlSys_Thro_RightBack;
					if(CtrlSys_Thro_FrontFan<CtrlSys_Fan_Min) CtrlSys_Thro_FrontFan = CtrlSys_Fan_Min;
					else CtrlSys_Thro_FrontFan = CtrlSys_Thro_FrontFan;


					Airscrew_CtrlSend(1,0x0B,CtrlSys_Thro_LeftFront);
					Airscrew_CtrlSend(2,0x0B,CtrlSys_Thro_LeftBack);
					Airscrew_CtrlSend(3,0x0B,CtrlSys_Thro_RightFront);
					Airscrew_CtrlSend(4,0x0B,CtrlSys_Thro_RightBack);
					Airscrew_CtrlSend(5,0x0B,CtrlSys_Thro_FrontFan);

					//控制输出,矢量装置转角
					Vector_Control(0x01,CtrlSys_VectorAngle);	//角度控制
					Vector_Control(0x02,0);		//启动控制			
					  
				}  
			
			
			else if( CtrlSys_Flight_Mode ==CtrlSys_RC )		//遥控模式处理
			{
				Remote_Control();	
				/*-----------输出控制螺旋桨转速、矢量装置角度----------*/		
				//控制输出,主推螺旋桨
				//螺旋桨加减速限幅
				
				CtrlSys_Thro_LeftFront = GetLimitValue(CtrlSys_Thro_LeftFront, CtrlSys_Thro_LeftFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
				CtrlSys_Thro_LeftBack = GetLimitValue(CtrlSys_Thro_LeftBack, CtrlSys_Thro_LeftBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
				CtrlSys_Thro_RightFront = GetLimitValue(CtrlSys_Thro_RightFront, CtrlSys_Thro_RightFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
				CtrlSys_Thro_RightBack = GetLimitValue(CtrlSys_Thro_RightBack, CtrlSys_Thro_RightBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);



				//螺旋桨转速限幅
				if(CtrlSys_Thro_LeftFront<CtrlSys_Pro_Min) CtrlSys_Thro_LeftFront = CtrlSys_Pro_Min;
				else CtrlSys_Thro_LeftFront = CtrlSys_Thro_LeftFront;
				if(CtrlSys_Thro_LeftBack<CtrlSys_Pro_Min) CtrlSys_Thro_LeftBack = CtrlSys_Pro_Min;
				else CtrlSys_Thro_LeftBack = CtrlSys_Thro_LeftBack;
				if(CtrlSys_Thro_RightFront<CtrlSys_Pro_Min) CtrlSys_Thro_RightFront = CtrlSys_Pro_Min;
				else CtrlSys_Thro_RightFront = CtrlSys_Thro_RightFront;
				if(CtrlSys_Thro_RightBack<CtrlSys_Pro_Min) CtrlSys_Thro_RightBack = CtrlSys_Pro_Min;
				else CtrlSys_Thro_RightBack = CtrlSys_Thro_RightBack;
				if(CtrlSys_Thro_FrontFan<CtrlSys_Fan_Min) CtrlSys_Thro_FrontFan = CtrlSys_Fan_Min;
				else CtrlSys_Thro_FrontFan = CtrlSys_Thro_FrontFan;


				Airscrew_CtrlSend(1,0x0B,CtrlSys_Thro_LeftFront);
				Airscrew_CtrlSend(2,0x0B,CtrlSys_Thro_LeftBack);
				Airscrew_CtrlSend(3,0x0B,CtrlSys_Thro_RightFront);
				Airscrew_CtrlSend(4,0x0B,CtrlSys_Thro_RightBack);
				Airscrew_CtrlSend(5,0x0B,CtrlSys_Thro_FrontFan);

				//控制输出,矢量装置转角
				Vector_Control(0x01,CtrlSys_VectorAngle);	//角度控制
				Vector_Control(0x02,0);		//启动控制			
			}	
			

		

}

  

 /*--------------------------仿真所用函数---------------------------*/
 
 /*---------Matlab 数据接收处理---------*/
void Task_Mat2FK_Recieve()	
{
if(U9RxFBufPo!=U9RxFBufPi)
	{
	bcopy(&(U9RxFBuf[U9RxFBufPo][0]),&(Trans_Matlab_Recieve),sizeof(Trans_Matlab_Recieve));
	U9RxFBufPo=(U9RxFBufPo+1)%U9_RxF_BufLen;
	
	if(Trans_Matlab_Recieve.CheckSum==AddSum1((DEF_UINT8*)&(Trans_Matlab_Recieve.FrameHead_1),55))
		{
		DelaySecond_Healthy[0][5]=0;		//超时计数置0 
		
		//处理数据

		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.FlightLong), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.FlightLat), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.FlightAlt), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.EastVelo), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.NorthVelo), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.VertiVelo), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.PitchAngle), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.RollAngle), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.HeadAngle), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.XAngleRate), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.YAngleRate), 4);
		ChangeHighLowBytes((DEF_UINT8*)&(Trans_Matlab_Recieve.ZAngleRate), 4);
		
		bcopy(&(Trans_Matlab_Recieve),&(CtrlLaw0H_SemSimMATtoFK),sizeof(CtrlLaw0H_SemSimMATtoFK));

		
	
		}
	}
}





void Task_FK2Mat_Send()
{

	//组建发送至Matlab的数据帧	
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_1 = 0xAA;
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_2 = 0x55;
	CtrlLaw0G_SemSimFKtoMAT.FrameLength = 18;
	CtrlLaw0G_SemSimFKtoMAT.CircleCount = CtrlLaw0H_SemSimMATtoFK.CircleCount + 1;

/*	
	//没有执行机构数据回传
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate1 = CtrlSys_Thro_LeftFront;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate2 = CtrlSys_Thro_LeftBack;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate3 = CtrlSys_Thro_RightFront;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate4 = CtrlSys_Thro_RightBack;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate_Front = CtrlSys_Thro_FrontFan;
	CtrlLaw0G_SemSimFKtoMAT.VectorAngle = CtrlSys_VectorAngle;

*/
	

	//采用执行机构数据回传
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate1 = g_YC_Package.TJ.AirscrewActualN[0];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate2 = g_YC_Package.TJ.AirscrewActualN[1];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate3 = g_YC_Package.TJ.AirscrewActualN[2];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate4 = g_YC_Package.TJ.AirscrewActualN[3];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate_Front = g_YC_Package.TJ.AirscrewActualN[4];
	CtrlLaw0G_SemSimFKtoMAT.VectorAngle=g_YC_Package.TJ.VectorAngle;		//转变为真实值，角度

	
	CtrlLaw0G_SemSimFKtoMAT.Reserved_17 = 0;		//备用
	CtrlLaw0G_SemSimFKtoMAT.CheckSum = AddSum1((DEF_UINT8*)(&(CtrlLaw0G_SemSimFKtoMAT)), (sizeof(CtrlLaw0G_SemSimFKtoMAT)-1) );		
	
	U9InTxBuf((U8*)&(CtrlLaw0G_SemSimFKtoMAT),18);

}



void Task_FK2Mat_Filter_Send()
{

	//组建发送至Matlab的数据帧	
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_1 = 0xAA;
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_2 = 0x55;
	CtrlLaw0G_SemSimFKtoMAT.FrameLength = 56;
	CtrlLaw0G_SemSimFKtoMAT.CircleCount = CtrlLaw0H_SemSimMATtoFK.CircleCount + 1;

	
	//没有执行机构数据回传
	CtrlLaw0I_Matlab_Recieve1.MatPitchAngleOrigin  = (float)CtrlLaw0E_AttitudeDataOrigin.PitchAngle;
	CtrlLaw0I_Matlab_Recieve1.MatRollAngleOrigin  = (float)CtrlLaw0E_AttitudeDataOrigin.RollAngle;
	CtrlLaw0I_Matlab_Recieve1.MatYawAngleOrigin  = (float)CtrlLaw0E_AttitudeDataOrigin.HeadAngle;
	CtrlLaw0I_Matlab_Recieve1.MatPitchAngleRateOrigin  = (float)CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate;   
	CtrlLaw0I_Matlab_Recieve1.MatYawAngleRateOrigin  = (float)CtrlLaw0E_AttitudeDataOrigin.YawAngleRate;   
	CtrlLaw0I_Matlab_Recieve1.MatRollAngleRateOrigin  = (float)CtrlLaw0E_AttitudeDataOrigin.RollAngleRate;    

	CtrlLaw0I_Matlab_Recieve1.MatPitchAngleDealed  = (float)CtrlLaw0F_AttitudeDataDealed.PitchAngle;
	CtrlLaw0I_Matlab_Recieve1.MatRollAngleDealed  = (float)CtrlLaw0F_AttitudeDataDealed.RollAngle;
	CtrlLaw0I_Matlab_Recieve1.MatYawAngleDealed  = (float)CtrlLaw0F_AttitudeDataDealed.HeadAngle;
	CtrlLaw0I_Matlab_Recieve1.MatPitchAngleRateDealed  = (float)CtrlLaw0F_AttitudeDataDealed.PitchAngleRate;   
	CtrlLaw0I_Matlab_Recieve1.MatYawAngleRateDealed  = (float)CtrlLaw0F_AttitudeDataDealed.YawAngleRate;   
	CtrlLaw0I_Matlab_Recieve1.MatRollAngleRateDealed  = (float)CtrlLaw0F_AttitudeDataDealed.RollAngleRate;  

	CtrlLaw0I_Matlab_Recieve1.Reserved_53[0]= 53;		//备用
	CtrlLaw0I_Matlab_Recieve1.Reserved_53[1]= 54;		//备用
	CtrlLaw0I_Matlab_Recieve1.Reserved_53[2]= 55;		//备用
	
	CtrlLaw0I_Matlab_Recieve1.CheckSum = AddSum1((DEF_UINT8*)(&(CtrlLaw0I_Matlab_Recieve1)), (sizeof(CtrlLaw0I_Matlab_Recieve1)-1) );		
	
	U9InTxBuf((U8*)&(CtrlLaw0I_Matlab_Recieve1),56);

}







/*-------调换内存地址中的字节顺序-------*/
/*-------输入:  1-起始位置； 2-字节个数(1~8, 不超过8)-------*/
DEF_UINT8 ChangeHighLowBytes(DEF_UINT8 *p, DEF_UINT8 Count)
{
	DEF_UINT8	iForCount;
	DEF_UINT8	TransForBytes[8];

	if(Count<=8)
		{
		bcopy((DEF_UINT8*)&(p[0]),&(TransForBytes[0]),Count);

		for(iForCount=0;iForCount<Count;iForCount++)
			{p[iForCount]=TransForBytes[Count-iForCount-1];}

		return 0;
		}
	
	else
		{return 1;}
}



		
		
/*----获得限幅后控制量:   1-控制值，2-当前值，3-限幅---*/
DEF_DOUBLE64 GetLimitValue(DEF_DOUBLE64 CtrlValue, DEF_DOUBLE64 CurrentValue, DEF_FLOAT32 LimitValue)
{
	if(LimitValue>0)
		{
		if(abs(CtrlValue-CurrentValue)>LimitValue)
			{
			if (CtrlValue>CurrentValue)
				{CtrlValue = CurrentValue + LimitValue;}
			  else
			  	{CtrlValue= CurrentValue - LimitValue;}
			}
		}
	return CtrlValue; 
}







