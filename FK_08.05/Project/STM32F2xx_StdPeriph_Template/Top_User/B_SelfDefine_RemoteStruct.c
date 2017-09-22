/*========================================================================================*
 * FILE:                     	SelfDefine_RemoteStruct.c                   
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

 #include "B_SelfDefine_RemoteStruct.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 DEF_UINT8 Modelname=0;	
 *------------------------------------------------------------------------------*/



/*----------快帧-----------*/
const DEF_UINT8 g_YC_Date_Length[YC_DATA_COUNT]				//遥测数据结构体长度
		=	{
			sizeof(_DEFSTRU_HD01YC),					//	0
			sizeof(_DEFSTRU_HD02YC),					//	1
			sizeof(_DEFSTRU_TJYC),					//	2
			sizeof(_DEFSTRU_NYYC),					//	3
			sizeof(_DEFSTRU_NTYC)					//	4
			};											//↑↑↑注意个数，不要达到定义YC_DATA_COUNT  ↑↑↑

_DEFSTRU_YC_All g_YC_Package;				/*      遥测数据集合包  */

const DEF_UINT8 g_YC_FRAMEFLAG[YC_DATA_COUNT]					//遥测数据帧标志
					={
						FRAMEFLAG_YC_HD01,
						FRAMEFLAG_YC_HD02,
						FRAMEFLAG_YC_TJ,
						FRAMEFLAG_YC_NY,
						FRAMEFLAG_YC_NT
					};




/*----------慢帧-----------*/

const DEF_UINT8 g_YCLow_Date_Length[YC_DATA_COUNTLow]				//遥测数据结构体长度
		=	{
			sizeof(_DEFSTRU_JC01YC),					//	0
			sizeof(_DEFSTRU_JC02YC),					//	1
			};											//↑↑↑注意个数，不要达到定义YC_DATA_COUNTLow  ↑↑↑

 _DEFSTRU_YC_Low g_YCLowPack;				/*      遥测数据集合包  */

const DEF_UINT8 g_YCLow_FRAMEFLAG[YC_DATA_COUNTLow]					//遥测数据帧标志
			={	FRAMEFLAG_YC_JC01,
				FRAMEFLAG_YC_JC02};





//遥控数据全局变量
_DEFSTRU_YK01_FlightMode						YK01_FlightMode;
_DEFSTRU_YK02_WeightAdjust_Lock				YK02_WeightAdjust_Lock;
_DEFSTRU_YK03_WeightAdjustCtrl				YK03_WeightAdjustCtrl;
_DEFSTRU_YK04_NavCtrl						YK04_NavCtrl;
_DEFSTRU_YK05_FK_ComputHeart				YK05_FK_ComputHeart;
_DEFSTRU_YK06_FK_ComputerReset				YK06_FK_ComputerReset;
_DEFSTRU_YK07_FK_ComuterCtrl					YK07_FK_ComuterCtrl;
_DEFSTRU_YK08_LandingParSet					YK08_LandingParSet;
_DEFSTRU_YK09_AirscrewCtrl					YK09_AirscrewCtrl;
_DEFSTRU_YK0A_PropellerNCtrl					YK0A_PropellerNCtrl;
_DEFSTRU_YK0B_ValveCtrl						YK0B_ValveCtrl;
_DEFSTRU_YK0C_BallonetExploderControl			YK0C_BallonetExploderControl;
_DEFSTRU_YK0D_ValveExplodeCtrl				YK0D_ValveExplodeCtrl;
_DEFSTRU_YK0E_BalnetColPreFire				YK0E_BalnetColPreFire;
_DEFSTRU_YK0F_BalnetColCtrl					YK0F_BalnetColCtrl;
_DEFSTRU_YK10_EnergySysCtrl					YK10_EnergySysCtrl;
_DEFSTRU_YK11_FlightCtrlDataTrans				YK11_FlightCtrlDataTrans;
_DEFSTRU_YK12_VectorAngelCtrl					YK12_VectorAngelCtrl;
_DEFSTRU_YK13_VectorParamCtrl				YK13_VectorParamCtrl;
_DEFSTRU_YK14_MovCameraAngel				YK14_MovCameraAngel;
_DEFSTRU_YK15_MovCaParamCtrl				YK15_MovCaParamCtrl;
_DEFSTRU_YK16_ImageSysCtrl					YK16_ImageSysCtrl;
_DEFSTRU_YK17_AnalogImageSwitchCtrl			YK17_AnalogImageSwitchCtrl;
_DEFSTRU_YK18_DigitalImageSwitchCtrl			YK18_DigitalImageSwitchCtrl;
					



 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/
 




