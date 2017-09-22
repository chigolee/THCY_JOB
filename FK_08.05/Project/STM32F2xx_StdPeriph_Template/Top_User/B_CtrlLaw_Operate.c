/*------------------------------------------------------------------------------*
 *								ͷ�ļ�
 #include "Modelname.h"
 *------------------------------------------------------------------------------*/
 #include "B_CtrlLaw_Operate.h"

 
/*------------------------------------------------------------------------------*
 *								��������
 
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

	

					
//��ѯ����ȫ�ֱ���				
_DEFSTRU_CX_FlightCtrlData					CX_FlightCtrlData;

_DEFSTRU_CXHF01_FlightCtrlData				CXHF01_FlightCtrlData;
_DEFSTRU_CXHF02_FlightCtrlData				CXHF02_FlightCtrlData;
_DEFSTRU_CXHF03_FlightCtrlData				CXHF03_FlightCtrlData;
_DEFSTRU_CXHF04_FlightCtrlData				CXHF04_FlightCtrlData;

//�����ýṹ��
 _DEFSTRU_Matlab_Recieve					Trans_Matlab_Recieve;



/*---------------- ϵͳ ȫ�ֱ�����������������-----------------*/
//ע�⣺���нǶ����ݵ�λΪ0.1��
//���н��ٶ����ݵ�λΪ0.01��/��

DEF_UINT8 CHENTIAN = 0;


//��ǰʹ�ò���
//aim 
  DEF_INT16			CtrlSys_acou =0;				    //Ŀ�꺽�߽�
  DEF_INT16			CtrlSys_tay =0;						//Ŀ��ƫ���� 
  DEF_INT16			CtrlSys_ayy =0;				      	//ͨ����ǰ���Ŀ�������λ�ü������Ŀ�꺽���
//current
  DEF_INT32			CtrlSys_cLon  =0;                   //��ǰ����
  DEF_INT32			CtrlSys_cLat =0;					//��ǰγ��
  DEF_INT16			CtrlSys_cHei =0;					//��ǰ�߶�
  DEF_INT16			CtrlSys_cSpe =0;					//��ǰ�ٶ�   0.1m/s

//current differential 
  DEF_INT16			CtrlSys_cdHei =0;                   //��ǰ��������
  DEF_INT16			CtrlSys_cdLerror =0;				//��ǰ��ƫ�� �仯��

  DEF_DOUBLE64		CtrlSys_dphi = 0;
  DEF_DOUBLE64		CtrlSys_dtheta = 0;
  DEF_DOUBLE64		CtrlSys_dpsi = 0;
  
//׼�����²���
//CtrlSys_temp aim        --����������
  DEF_INT32			CtrlSys_taLon1 =0;                   //Ŀ�꾭��  
  DEF_INT32			CtrlSys_taLat1 =0;					 //Ŀ��γ��
  DEF_INT16			CtrlSys_taHei1 =0;					 //Ŀ��߶�
  DEF_INT16			CtrlSys_tacou1 =0;				     //Ŀ�꺽�߽�
  DEF_UINT8			CtrlSys_isSafeMode = 0;				 //�Ƿ�Ϊ��ȫ����ģʽ

  DEF_INT16			CtrlSys_cp =0;                       //��ǰ������
  DEF_INT16			CtrlSys_cr =0;						 //��ǰ��ת��
  DEF_UINT16		CtrlSys_cy =0;						 //��ǰƫ����(�ں�)

//CtrlSys_temp current 
  DEF_INT32			CtrlSys_tcLon =0;                     //��ǰ����(����)
  DEF_INT32			CtrlSys_tcLat =0;					  //��ǰγ��(����)
  DEF_INT16			CtrlSys_tcHei =0;					  //��ǰ�߶�(����)
  DEF_INT16			CtrlSys_tcSpe =0;					  //��ǰ�ٶ�(����)
  DEF_INT16			CtrlSys_tcLerror =0;				  //��ǰ��ƫ�� (����)


//CtrlSys_temp current differential 
//distance
  DEF_INT32			CtrlSys_adist =0;    				  //��ǰ�㵽Ŀ�꺽�����,��10��Ϊ��λ.
  DEF_FLOAT32		CtrlSys_tadistf =0;   				  //��ǰ�㵽Ŀ�꺽�����,����Ϊ��λ.

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
  extern DEF_UINT8	CtrlSys_Ini_State = 1;					//�����ɳ�ʼ����־

  DEF_DOUBLE64 		Low_filter[2]={0,0};
  DEF_DOUBLE64 		Filter_va=0.01;

 
//-----------------���뻺��������----------------------


  DEF_UINT16 CtrlSys_cHy =0;					  //��ǰ��ͷ��λ��(�ں�)
  DEF_UINT16 CtrlSys_cGy =0;					  //��ǰ������(�ں�) 

 

//-----------------�����м����----------------------


 //DEF_DOUBLE CtrlSys_temp = 0;	

DEF_INT32	CtrlSys_error_yaw = 0;
DEF_INT32	CtrlSys_error_dyaw = 0;
DEF_INT32	CtrlSys_error_yaw_last = 0;

DEF_UINT8  CtrlSys_CWn =CtrlSys_HoverWay;    	 //��ǰ���߱��
DEF_UINT8  CtrlSys_CPn =1;    					//��ǰ������

_DEFSTRU_CtrlLaw01_FlightPathInput  PathPoint[3];  //����
_DEFSTRU_CtrlLaw01_FlightPathInput  PathPointSet[3];  //����������
_DEFSTRU_CtrlLaw01_FlightPathInput  PathpointDown;  //����������


DEF_INT16 CtrlSys_cdp =0;                                 //��ǰ�������ٶ� 0.01��/��
DEF_INT16 CtrlSys_cdr =0;				         //��ǰ��ת���ٶ� 0.01��/��
DEF_INT16 CtrlSys_cdy =0;	                              //��ǰƫ�����ٶ� 0.01��/��

//�����м����
DEF_DOUBLE64 CtrlSys_ei1_y = 0;
DEF_DOUBLE64 CtrlSys_ei2_y = 0;






/*============================================================================*
* ��������				Dowork_YK11_FlightCtrlDataTrans
*============================================================================*
*
* ���ܣ��ɿ����ң�����ݴ���
*
* ����: 
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/


//����ע�����
_DEFSTRU_CtrlLaw01_FlightPathInput	FlightPath_Package[5][20];		//����ң��ָ��洢
DEF_UINT8	FlightPath_PointCount[5];							//�������ߺ������

void Dowork_YK11_FlightCtrlDataTrans()
{
	if ( YK11_FlightCtrlDataTrans.CommandCode== CtrlLaw_FlightPathInput )
		{
			bcopy(&(YK11_FlightCtrlDataTrans),&(CtrlLaw01_FlightPathInput),sizeof(CtrlLaw01_FlightPathInput));
			if ((CtrlLaw01_FlightPathInput.PathNO<=5)&&(CtrlLaw01_FlightPathInput.PointCount<=20)&&((CtrlLaw01_FlightPathInput.PointNO<=(CtrlLaw01_FlightPathInput.PointCount))))
				{
					FlightPath_PointCount[(CtrlLaw01_FlightPathInput.PathNO-1)]=CtrlLaw01_FlightPathInput.PointCount;	
					bcopy(&CtrlLaw01_FlightPathInput,&(FlightPath_Package[(CtrlLaw01_FlightPathInput.PathNO-1)][(CtrlLaw01_FlightPathInput.PointNO-1)]),sizeof(CtrlLaw01_FlightPathInput));

					//ң�ػظ��ɹ�
					YKCX_Answer_State_Date((DEF_UINT8*)(&CtrlLaw01_FlightPathInput),sizeof(CtrlLaw01_FlightPathInput),YK_ANSWER_SUCCESS);
				}
			else
				{
					//ң�ػظ��������߱��޷�ִ��
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
* ��������				Dowork_CX_FlightCtrlData
*============================================================================*
*
* ���ܣ��ɿ���ز�ѯָ���
*
* ����: 
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/

DEF_UINT8	i_ForCXFlightPath;		//������Ϣ����
DEF_UINT8	Count_FlightPath;		//�������
DEF_UINT8	LineNO_FlightPath;		//���߱��

void Dowork_CX_FlightCtrlData()
{


 	//�������ݲ�ѯָ��
	if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX01_FlightCtrl01)
		{
			Count_FlightPath = FlightPath_PointCount[CX_FlightCtrlData.Reserved_5[0]-1];
			//ǰ4 ���ֽ�
			bcopy(&(CX_FlightCtrlData),&(CXHF01_FlightCtrlData),4);
			if((CX_FlightCtrlData.Reserved_5[0]<=5)&&(CX_FlightCtrlData.Reserved_5[1]<=20)&&(Count_FlightPath>0))
				{
					LineNO_FlightPath = CX_FlightCtrlData.Reserved_5[0];

					for(i_ForCXFlightPath=0;i_ForCXFlightPath<Count_FlightPath;i_ForCXFlightPath++)
						{
							//��֡
							bcopy(&(FlightPath_Package[LineNO_FlightPath-1][i_ForCXFlightPath].PathNO),&(CXHF01_FlightCtrlData.PathNO),(sizeof(CXHF01_FlightCtrlData)-4));
							
							//ң�ػظ���ʽ�´�
							YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF01_FlightCtrlData),sizeof(CXHF01_FlightCtrlData),CX_ANSWER_SUCCESS);
						}	
				}
			else
				{
					//ң�ػظ���ѯʧ��
					YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF01_FlightCtrlData),sizeof(CXHF01_FlightCtrlData),CX_ANSWER_ERR_LACK);
				}
		}
	
	
	//���Ʋ�����ѯָ��
	else if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX02_FlightCtrl02 )
		{
			//��֡
			//�ɿز�����ѯ��1 ֡
			bcopy(&(CX_FlightCtrlData),&(CXHF02_FlightCtrlData),4);
			CXHF02_FlightCtrlData.CommandCode = MSGDATA_CX02_FlightCtrl02;
			
			bcopy(&(CtrlLaw02_CruiseCirclePara.CruiseCircleLong),&(CXHF02_FlightCtrlData.CruiseCircleLong),12);
			bcopy(&(CtrlLaw03_StayModePara.HomeLong),&(CXHF02_FlightCtrlData.HomeLong),16);
			bcopy(&(CtrlLaw04_TrajPlanPara.Para_kcpt),&(CXHF02_FlightCtrlData.Para_kcpt),28);
			bcopy(&(CtrlLaw05_CruiseDirection.CruiseDirection),&(CXHF02_FlightCtrlData.CruiseDirection),4);
			bcopy(&(CtrlLaw06_GesturePara.Para_kypt),&(CXHF02_FlightCtrlData.Para_kypt),28);
			//ң�ػظ���ʽ�´�
			//�ɿز�����ѯ��1 ֡
			YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF02_FlightCtrlData),sizeof(CXHF02_FlightCtrlData),CX_ANSWER_SUCCESS);
		}

	else if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX03_FlightCtrl03 )
		{
			//��֡
			//�ɿز�����ѯ��2 ֡
			bcopy(&(CX_FlightCtrlData),&(CXHF03_FlightCtrlData),4);
			CXHF03_FlightCtrlData.CommandCode = MSGDATA_CX03_FlightCtrl03;
			
			bcopy(&(CtrlLaw07_CtrlAllocatePara.CAPara1),&(CXHF03_FlightCtrlData.CAPara1),24);
			bcopy(&(CtrlLaw08_SpeedPara.Para_kvp),&(CXHF03_FlightCtrlData.Para_kvp),14);
			bcopy(&(CtrlLaw09_WindSpDirection.WindSet_H_Angle),&(CXHF03_FlightCtrlData.WindSet_H_Angle),8);
			bcopy(&(CtrlLaw0A_EngineState.Propeller1),&(CXHF03_FlightCtrlData.Propeller1),7);


			//ң�ػظ���ʽ�´�
			//�ɿز�����ѯ��2 ֡
			YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF03_FlightCtrlData),sizeof(CXHF03_FlightCtrlData),CX_ANSWER_SUCCESS);
		}
	
	else if ( CX_FlightCtrlData.CommandCode == MSGDATA_CX04_FlightCtrl04 )
		{
			//��֡
			//�ɿز�����ѯ��3֡
			bcopy(&(CX_FlightCtrlData),&(CXHF04_FlightCtrlData),4);
			CXHF04_FlightCtrlData.CommandCode = MSGDATA_CX04_FlightCtrl04;
			
			bcopy(&(CtrlLaw0C_NavEKFPara.PitchAngleQ),&(CXHF04_FlightCtrlData.PitchAngleQ),sizeof(CtrlLaw0C_NavEKFPara));
			

			//ң�ػظ���ʽ�´�
			//�ɿز�����ѯ��3֡
			YKCX_Answer_State_Date((DEF_UINT8*)(&CXHF04_FlightCtrlData),sizeof(CXHF04_FlightCtrlData),CX_ANSWER_SUCCESS);
		}

}



/*============================================================================*
* ��������							CtrlInfor_Update
*============================================================================*
*
* ���ܣ��������������ݸ���
*
* ����: ���ݾ������󣬾���ʹ�ùߵ����ͣ������Ƿ���Ҫ�˲�
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
 void CtrlInfor_Update(void)
	{
		//�жϷ���ģʽ�Ƿ�ı�
		if(CtrlLaw0D_FlightCtroInfor.FlightMode != g_YC_Package.TJ.FlightMode)
			{CtrlLaw0D_FlightCtroInfor.FlightMode = g_YC_Package.TJ.FlightMode;
			CtrlLaw_ini();}

		

		//λ�ú��ٶȲ��ùߵ��������
		if( All_YCFast_Package.TJ.FK_UseINS != 0x01 )	//���ߵ�
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
		else 	//���ߵ�
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

		//ִ�л���״̬
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftFront = g_YC_Package.TJ.AirscrewActualN[0];
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftBack = g_YC_Package.TJ.AirscrewActualN[1];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightFront = g_YC_Package.TJ.AirscrewActualN[2];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightBack = g_YC_Package.TJ.AirscrewActualN[3];
		CtrlLaw0D_FlightCtroInfor.Propeller_Front = g_YC_Package.TJ.AirscrewActualN[4];
		CtrlLaw0D_FlightCtroInfor.VectorAngle=g_YC_Package.TJ.VectorAngle;
	}	


/*============================================================================*
* ��������							SemSim_Update
*============================================================================*
*
* ���ܣ����������ݸ���
*
* ����: ʹ��Matlab�������������Ϊʵ�ʷ�������
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/

 void SemSim_Update(void)
	{
		//�жϷ���ģʽ�Ƿ�ı�
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
			
		//ִ�л���״̬
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftFront = g_YC_Package.TJ.AirscrewActualN[0];
		CtrlLaw0D_FlightCtroInfor.Propeller_LeftBack = g_YC_Package.TJ.AirscrewActualN[1];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightFront = g_YC_Package.TJ.AirscrewActualN[2];
		CtrlLaw0D_FlightCtroInfor.Propeller_RightBack = g_YC_Package.TJ.AirscrewActualN[3];
		CtrlLaw0D_FlightCtroInfor.Propeller_Front = g_YC_Package.TJ.AirscrewActualN[4];
		CtrlLaw0D_FlightCtroInfor.VectorAngle=g_YC_Package.TJ.VectorAngle;	

	}	


/*============================================================================*
* ��������							CtrlInfor_EKF
*============================================================================*
*
* ���ܣ����������������˲�
*
* ����: ÿ��0.08s����һ��
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
DEF_FLOAT32		CtrlSys_dt = 0.08;
DEF_FLOAT32		PPitch[4] = { 100*10000, 0, 0, 100*1000 };
DEF_FLOAT32    	PYaw[4] = { 100*10000, 0, 0, 100*1000 };
DEF_FLOAT32   	PRoll[4] = { 100*10000, 0, 0, 100*1000 };
DEF_FLOAT32		QPitchAngle = 1*10000;  			//������״̬Э����
DEF_FLOAT32		QPitchAngleRate = 1*1000; 		//�������ٶ�״̬Э����
DEF_FLOAT32		RPitchAngle =100*10000; 			//���������Э����
DEF_FLOAT32		RPitchAngleRate = 100*1000; 		//�������ٶ����Э����
DEF_FLOAT32		QYawAngle = 1*10000;				//ƫ����״̬Э����
DEF_FLOAT32		QYawAngleRate = 1*1000;			//ƫ�����ٶ�״̬Э����
DEF_FLOAT32		RYawAngle = 100*10000;			//ƫ�������Э����
DEF_FLOAT32		RYawAngleRate = 100*1000;		//ƫ�����ٶ����Э����
DEF_FLOAT32		QRollAngle = 1*10000;				//��ת��״̬Э����
DEF_FLOAT32		QRollAngleRate = 1*1000;			//��ת���ٶ����Э����
DEF_FLOAT32		RRollAngle = 100*10000;			//��ת�����Э����
DEF_FLOAT32		RRollAngleRate = 100*1000;		//��ת���ٶ����Э����	 

DEF_FLOAT32		EKF_Gain[4] = {0,0,0,0};


void CtrlInfor_EKF(void)
{
     DEF_FLOAT32 a, b, c, d, m, n, p, q;
     //�˲���������
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

	 //ԭʼ���ݸ���
	 if( YK04_NavCtrl.FK_UseINS == 0x11 )
		{
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngle 		= g_YC_Package.HD01.Pitch;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngle 		= g_YC_Package.HD01.Roll;
		 CtrlLaw0E_AttitudeDataOrigin.HeadAngle 		= g_YC_Package.HD01.Yaw;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngleRate 	= g_YC_Package.HD01.RollSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate 	= g_YC_Package.HD01.PitchSpeed;
		 CtrlLaw0D_FlightCtroInfor.ZAngleRate 			= g_YC_Package.HD01.PitchSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchDA 			= g_YC_Package.HD01.Double_Antenna_Pitch;          //˫���߸���
		 CtrlLaw0E_AttitudeDataOrigin.YawDA 			= g_YC_Package.HD01.Double_Antenna_Heading;        //˫���ߺ���
	 	}
	 else if( YK04_NavCtrl.FK_UseINS == 0x22 )
	 	{
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngle 		= g_YC_Package.HD02.Pitch;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngle 		= g_YC_Package.HD02.Roll;
		 CtrlLaw0E_AttitudeDataOrigin.HeadAngle 		= g_YC_Package.HD02.Yaw;
		 CtrlLaw0E_AttitudeDataOrigin.RollAngleRate 	= g_YC_Package.HD02.RollSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchAngleRate 	= g_YC_Package.HD02.PitchSpeed;
		 CtrlLaw0D_FlightCtroInfor.ZAngleRate 			= g_YC_Package.HD02.PitchSpeed;
		 CtrlLaw0E_AttitudeDataOrigin.PitchDA 			= g_YC_Package.HD02.Double_Antenna_Pitch;          //˫���߸���
		 CtrlLaw0E_AttitudeDataOrigin.YawDA 			= g_YC_Package.HD02.Double_Antenna_Heading;        //˫���ߺ���
	 	}
	 
	 /* �������˲� */
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

	 /* ƫ�����˲� */
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



	  /* ��ת���˲� */
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
* ��������							Ctrl_Para_Init
*============================================================================*
*
* ���ܣ��ɿز�����ʼ��
*
* ����:    �ɿ����ݳ�ʼ��
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
void Ctrl_Para_Init(void)
  	{
		
		//����ģʽ��ʼ��
		CtrlLaw0D_FlightCtroInfor.FlightMode = g_YC_Package.TJ.FlightMode;

		//פ�������ʼ��
		CtrlLaw03_StayModePara.HomeLat = 7727057;
		CtrlLaw03_StayModePara.HomeLong = 20217942;
		CtrlLaw03_StayModePara.BufferAreaDist = 0;
		CtrlLaw03_StayModePara.HomeHeight = 20000;
		CtrlLaw03_StayModePara.CoreAreaDist = 5000;
		CtrlLaw03_StayModePara.TotalAreaDist = 5000;
		

		//�ڻ�������ʼ��
		CtrlLaw06_GesturePara.Para_kypt = 1;
		CtrlLaw06_GesturePara.Para_kyp1= 1.8;
		CtrlLaw06_GesturePara.Para_kyp2= 2;
		CtrlLaw06_GesturePara.Para_kyi = 360;
		CtrlLaw06_GesturePara.Para_kyd = 15;
		CtrlLaw06_GesturePara.Para_kyth = 0;
		CtrlLaw06_GesturePara.Para_kylimit= 900;
		
		CtrlLaw05_CruiseDirection.CruiseDirection = 0.52;
		
	
		//�⻷������ʼ��
		CtrlLaw04_TrajPlanPara.Para_kcpt = 1;
		CtrlLaw04_TrajPlanPara.Para_kcp1 = 0.06;
		CtrlLaw04_TrajPlanPara.Para_kcp2 = 0.06;
		CtrlLaw04_TrajPlanPara.Para_kci = 0;
		CtrlLaw04_TrajPlanPara.Para_kcd = 0;
		CtrlLaw04_TrajPlanPara.Para_kcth = 0;
		CtrlLaw04_TrajPlanPara.Para_kclimit = 900;

		//�糡����
		CtrlLaw09_WindSpDirection.WindSet_H_Angle = 0;
		CtrlLaw09_WindSpDirection.WindSpSet_H = 0;
		CtrlLaw09_WindSpDirection.WindSpSet_V = 0;

		//Ѳ��Բ������ʼ��
		CtrlLaw02_CruiseCirclePara.CruiseCircleRadius = 8000;
		CtrlLaw02_CruiseCirclePara.PreTurningLen = 100;
	
		//���Ʒ��������ʼ��
		CtrlLaw07_CtrlAllocatePara.CAPara1 = 0.67;
		CtrlLaw07_CtrlAllocatePara.CAPara2 = 0;
		CtrlLaw07_CtrlAllocatePara.CAPara3 = 1;
		CtrlLaw07_CtrlAllocatePara.CAPara4 = 6000;
		CtrlLaw07_CtrlAllocatePara.CAPara5 = 0;
		CtrlLaw07_CtrlAllocatePara.CAPara6 = 0;

		//ִ�л���״̬��ʼ��
		CtrlLaw0A_EngineState.Propeller1= 0;
		CtrlLaw0A_EngineState.Propeller2 = 0;
		CtrlLaw0A_EngineState.Propeller3 = 0;
		CtrlLaw0A_EngineState.Propeller4 = 0;
		CtrlLaw0A_EngineState.Propeller_Front= 0;	


		//�˲���������
		QPitchAngle = 10000;  			//������״̬Э����
		QPitchAngleRate = 1000; 			//�������ٶ�״̬Э����
		RPitchAngle =1000000; 			//���������Э����
		RPitchAngleRate = 100000; 		//�������ٶ����Э����
		QYawAngle = 10000;				//ƫ����״̬Э����
		QYawAngleRate = 1000;			//ƫ�����ٶ�״̬Э����
		RYawAngle = 1000000;			//ƫ�������Э����
		RYawAngleRate = 100000;			//ƫ�����ٶ����Э����
		QRollAngle = 10000;				//��ת��״̬Э����
		QRollAngleRate = 1000;			//��ת���ٶ����Э����
		RRollAngle = 1000000;			//��ת�����Э����
		RRollAngleRate = 100000;			//��ת���ٶ����Э����	 
		
  	}



/*============================================================================*
* ��������							CopyWP
*============================================================================*
*
* ���ܣ����㸴�ƺ���
*
* ����:    ������P2�����ݸ��Ƶ�P1��
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/

//���㸴��P2-->P1
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
* ��������							ReadWP
*============================================================================*
*
* ���ܣ������ȡ����
*
* ����:    ��ȡ��һ������
*
* ע�⣺���ܴ��޸�!!!!!!!!
*
* ������	Wn: ���߱��
			Pn:  ������
			P :  Ŀ��λ��
*
* RETURENS��
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

	 
	  //һ�㺽��
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
* ��������							Navigation
*============================================================================*
*
* ���ܣ�ˮƽ�浼������
*
* ����:    ���ݵ�ǰ״̬���㵱ǰ���㵽Ŀ�꺽��ĺ���ǡ��������ƫ��
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
  DEF_INT32 CtrlSys_aLon =0;                             //Ŀ�꾭��
  DEF_INT32 CtrlSys_aLat =0;				 //Ŀ��γ��



DEF_UINT8 Navigation(void)
	{ 
		DEF_FLOAT32  CtrlSys_temp=0; 		   
		  
	    //��������   
	    CtrlSys_aLon = CtrlSys_taLon1;
		CtrlSys_aLat = CtrlSys_taLat1;	     
		CtrlSys_acou = CtrlSys_tacou1;
		
	    CtrlSys_cLon = CtrlSys_tcLon;
		CtrlSys_cLat = CtrlSys_tcLat;  
			  
	    // ���㵱ǰ���㵽Ŀ�꺽��ĺ����
	    CtrlSys_ayy=Cal_Point(CtrlSys_cLon, CtrlSys_cLat,CtrlSys_aLon, CtrlSys_aLat,&CtrlSys_tadistf);
	      
	    //��ǰ�㵽��ǰĿ���ľ���
	    CtrlSys_adist = (DEF_INT32)CtrlSys_tadistf/10.0;  
	    if(CtrlSys_adist >60000)
			CtrlSys_adist = 60000;
		
	    //��ǰ�㵽��ǰ���ߵĲ�ƫ��
	    CtrlSys_tcLerror = Cal_LineError( CtrlSys_ayy,  CtrlSys_acou, CtrlSys_tadistf);      

			
	    return TRUE;
	}



/*============================================================================*
* ��������							SwitchWP
*============================================================================*
*
* ���ܣ������л�����
*
* ����:    ���ݵ�ǰ��������ǰת�����Ĺ�ϵ��ȷ���л���ʽ
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/


DEF_UINT8 SwitchWP(void)
{
   DEF_FLOAT32  CtrlSys_SwitchWP_temp=0;   
   
   DEF_UINT8   CtrlSys_Result=TRUE;  
   static DEF_FLOAT32 CtrlSys_LastLineDist = 0;
      
   // ����ǰ�������л����㣨Ĭ�ϣ�      
   //�������
   CtrlSys_SwitchWP_temp =  Cal_LineDist( CtrlSys_ayy,  CtrlSys_acou, CtrlSys_tadistf);
  
   if(CtrlSys_SwitchWP_temp>(DEF_FLOAT32)(PathPoint[CtrlSys_CurrentPoint].PreTurningLen))			//δ�ﵽ��ǰת����룬�򲻽����л�
   
           return  FALSE;
   
   else																					//�ﵽ��ǰת����룬�����л�
   	{
		   if(PathPoint[CtrlSys_CurrentPoint].PathChange == FALSE)			
		   { 
		    	    //�����л�
			   CopyWP(&PathPoint[CtrlSys_LastPoint],&PathPoint[CtrlSys_CurrentPoint]); 	   
					
			   //��ȡ��һ������	   
			   
			   CtrlSys_CPn++;
		             
			   if(CtrlSys_CPn>PathPoint[CtrlSys_CurrentPoint].PointCount)				//�˺���Ϊ�ú������һ������
			     {
		               if(PathPoint[CtrlSys_CurrentPoint].PathRestart != FALSE)  				//ѭ������
				 {
				 	CtrlSys_CPn = 1;
					
				 }		 
				 else
				 {
				      /*------------------------ת����ȫģʽ------------------------*/
					  //�ڵ�ǰλ��������פ��
					CtrlSys_isSafeMode = TRUE;
					CopyWP(&PathPoint[CtrlSys_TempPoint],&PathPoint[CtrlSys_CurrentPoint]); //��ǰ���������ʱ�Ĵ���
					
				 }	
			      }	   


			   else															//�����һ������
			      {CtrlSys_CPn = CtrlSys_CPn;}

			  
			   if(CtrlSys_CWn< CtrlSys_HoverWay)							  //��ͨ�û�����(ֱ�߷���)
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
					   CtrlSys_isSafeMode= TRUE; //������㲻��ȷ ���е���ȫģʽ
					   CtrlSys_CPn = 1;	
					   CopyWP(&PathPoint[CtrlSys_TempPoint],&PathPoint[CtrlSys_LastPoint]); //��ǰ���������ʱ�Ĵ���
				    }

			   }


			   
		          if(CtrlSys_CWn==CtrlSys_HoverWay) //��������
			   {	

				    PathPoint[CtrlSys_CurrentPoint].PointCount = 8;
				    //PathPoint[CtrlSys_TempPoint] ��Ϊ�������ߵĲο���
		    	     	    //Ȼ�󽫵�ǰ����任�ɾ��Ժ���
		    	     	    //����Բ�ֳܷ�8����,    

				
				            
			           if(CtrlSys_LTLK != 0)
		                      {  PathPoint[CtrlSys_CurrentPoint].PointLong = PathPoint[CtrlSys_LastPoint].PointLong + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*cos(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0)/CtrlSys_LTLK;}
				    else 
					  PathPoint[CtrlSys_CurrentPoint].PointLong =0;
					
				    PathPoint[CtrlSys_CurrentPoint].PointLat =  PathPoint[CtrlSys_LastPoint].PointLat + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*sin(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0); 

				    PathPoint[CtrlSys_CurrentPoint].PointNO = CtrlSys_CPn;
				    PathPoint[CtrlSys_CurrentPoint].PathChange = 0x00;  //��֧����ʽ�л�
					    
				    PathPoint[CtrlSys_CurrentPoint].PathRestart =TRUE; //ѭ��   //���������Զ�ѭ��
				    PathPoint[CtrlSys_CurrentPoint].PreTurningLen =CtrlLaw02_CruiseCirclePara.PreTurningLen; //��ǰת����	    

				    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
				    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
	              
				    CtrlSys_tacou1 = Cal_Point(PathPoint[CtrlSys_LastPoint].PointLong, PathPoint[CtrlSys_LastPoint].PointLat, PathPoint[CtrlSys_CurrentPoint].PointLong, PathPoint[CtrlSys_CurrentPoint].PointLat, &CtrlSys_LastLineDist);   
			
				    
			   }
		   	
			         
		    }
		  
		   else 							 //�л�����ȫģʽ
		   {
		       //Ĭ���л�����ȫģʽ
		   	   //�л�����ȫģʽ
			    
			    CtrlSys_isSafeMode = TRUE;
				
		   	    CopyWP(&PathPoint[CtrlSys_LastPoint],&PathPoint[CtrlSys_CurrentPoint]); 
			    CopyWP(&PathPoint[CtrlSys_TempPoint],&PathPoint[CtrlSys_CurrentPoint]);  //��ǰ���������ʱ�Ĵ���	

		             	   
		    }    
		   
   	
   		return TRUE; 
   	}
}




/*============================================================================*
* ��������							WPInit
*============================================================================*
*
* ���ܣ������ʼ������
*
* ����:    ��ʼ�����㣬�Ƚ�������뵽PathPoint[CtrlSys_LastPoint]��������������ٿ�����PathPoint[CtrlSys_CurrentPoint]
*		     ��ֹ���벻�����ֽ�PathPoint[CtrlSys_CurrentPoint]�еĵ�ǰ������������
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
DEF_UINT8 WPInit(DEF_UINT8 Wn, DEF_UINT8 Pn)
	{
	   DEF_UINT8  CtrlSys_Result=TRUE;

	   //�Ƚ�������뵽PathPoint[CtrlSys_LastPoint]��������������ٿ�����PathPoint[CtrlSys_CurrentPoint]
	   //��ֹ���벻�����ֽ�PathPoint[CtrlSys_CurrentPoint]�еĵ�ǰ������������
	   if(Wn < CtrlSys_HoverWay)
		   {
		         CtrlSys_Result &= ReadWP(Wn, Pn, &PathPoint[CtrlSys_LastPoint]);
				
			  if(CtrlSys_Result == TRUE)
			   {
			       //�����������
				    CtrlSys_CWn = Wn;  
				    CtrlSys_CPn = Pn;   		
				  
				    CopyWP(&PathPoint[CtrlSys_CurrentPoint],&PathPoint[CtrlSys_LastPoint]); 
				     //��Ŀ�꾭γ�ȸ߶ȵ�������ǰ������
				    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
				    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
			    }
		   }
	   if(Wn >= CtrlSys_HoverWay)    //��������   
		   {
		            //�л�����������
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

	            //��������ʱ��PathPoint[CtrlSys_TempPoint]��Ϊ�������ߵĲο���
	            //��ʼ��ʱ���ǡ��Ϊ�������ߣ����Ե�ǰ��Ϊ�ο���
	            //���Խ���ǰ��ľ��ȡ�γ�ȴ���PathPoint[CtrlSys_TempPoint]
	            PathPoint[CtrlSys_TempPoint].PointLong =  CtrlSys_tcLon;
			    PathPoint[CtrlSys_TempPoint].PointLat  =  CtrlSys_tcLat;


			    //Ȼ�󽫵�ǰ����任�ɾ��Ժ���
			    PathPoint[CtrlSys_CurrentPoint].PointCount = 8;

			    if(CtrlSys_LTLK!= 0)
		            PathPoint[CtrlSys_CurrentPoint].PointLong = PathPoint[CtrlSys_TempPoint].PointLong + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*cos(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0)/CtrlSys_LTLK;
			    else 
					PathPoint[CtrlSys_CurrentPoint].PointLong = 0;
			    	PathPoint[CtrlSys_CurrentPoint].PointLat =  PathPoint[CtrlSys_TempPoint].PointLat + CtrlLaw02_CruiseCirclePara.CruiseCircleRadius*sin(6.2831852*(DEF_FLOAT32)(CtrlSys_CPn-1)/8.0)/(CtrlSys_MtMk/1000.0); 
			
			   
			   
			    PathPoint[CtrlSys_CurrentPoint].PathChange = 0x00;  //��֧����ʽ����Ƕ��	
			       
			    PathPoint[CtrlSys_CurrentPoint].PathRestart = 0x10; //ѭ��   //���������Զ�ѭ��
			    PathPoint[CtrlSys_CurrentPoint].PreTurningLen = CtrlLaw02_CruiseCirclePara.PreTurningLen; //��ǰת��	    	    

			    //��Ŀ�꾭γ�ȸ߶ȵ�������ǰ������
			    CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
			    CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 
			
	  	 }

  
    return CtrlSys_Result;   
}





/*============================================================================*
* ��������							NavInit
*============================================================================*
*
* ���ܣ��������ݳ�ʼ������
*
* ����:    ��ʼ���������ݣ����Ŀ�꺽�߽�
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/


  DEF_INT32 CtrlSys_taLon2 =0;                                   //Ŀ�꾭��  
  DEF_INT32 CtrlSys_taLat2 =0;					  //Ŀ��γ��
  DEF_INT16 CtrlSys_taHei2 =0;					  //Ŀ��߶�
  DEF_INT16 CtrlSys_tacou2 =0;				         //Ŀ�꺽�߽�


 DEF_UINT8 NavInit(DEF_UINT8 ID)
 {
   DEF_FLOAT32  CtrlSys_temp=0;   
          if(ID == 1)
          {
                  //�������ݳ�ʼ��������GPS����
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
* ��������							Cal_Point
*============================================================================*
*
* ���ܣ����������ǶȺ;��뺯��
*
* ����:    ���������ǶȺ;���
*
* ע�⣺
*
* ������	
*
* RETURENS��
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
	  
	  //���㺽���
	  angle=0;
	  
	  if((*plen) > 0)
		  {
			angle = acos(temp_n/(*plen));  //��N��ļн�
		    if(temp_e>=0)
		   	{
			    angle =angle *572.96f;  //57.296*10   ��λ0.1��
			}
		    else
			{
			    angle = 3600-angle *572.96f;  //57.296*10 ��λ0.1��
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
	  
	  // ����cou ��0��359��
	  if(cou<0)
	  	cou=0;
	  
	  else if(cou>3599)
	  	cou=3599; 
	  
	  *plen = (*plen)*(CtrlSys_MtMk/1000.0);//���뵥λת��Ϊ��
	  
	  return cou;	 
}



/*============================================================================*
* ��������							Cal_LineError
*============================================================================*
*
* ���ܣ����㵱ǰλ�þ��뺽�ߵĲ�ƫ��
*
* ����:   ���� ��ƫ��	destcou Ϊ��ǰ�㵽Ŀ�꺽��ĺ����  linecouΪ��ǰ���εĺ���ǣ�
		    plenΪ��ǰ�㵽Ŀ���ľ���
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/

DEF_FLOAT32  Cal_LineError(DEF_INT16 destcou,DEF_INT16 linecou, DEF_FLOAT32 plen)
	{
		   
		   DEF_FLOAT32 lerror;  //��ƫ��
		   DEF_INT16 CtrlSys_temp;  //��ʱ����
		  

		   CtrlSys_temp = destcou-linecou;
		   
		   if(CtrlSys_temp > 1800)
			   {
			       CtrlSys_temp =-(3600-CtrlSys_temp);
			   }
		   if(CtrlSys_temp<-1800)
			   {
			       CtrlSys_temp=3600+CtrlSys_temp;
			   }
		   
		   lerror = (DEF_FLOAT32)(plen*sin(((DEF_FLOAT32)CtrlSys_temp/572.96f)));// �����ƫ��   
		   
		   return lerror;
	}



/*============================================================================*
* ��������							Cal_LineDist
*============================================================================*
*
* ���ܣ����㵱ǰ���غ��߷���Ŀ���ľ���
*
* ����:  	destcou ��ǰƫ���ǣ�linecou���߽ǣ�plen��������

* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
DEF_FLOAT32  Cal_LineDist(DEF_INT16 destcou,DEF_INT16 linecou, DEF_FLOAT32 plen)
{
  
   DEF_FLOAT32 LDistance;  //��ƫ��
   DEF_INT16 CtrlSys_temp;  //��ʱ����
  

   CtrlSys_temp = destcou-linecou;
   
   if(CtrlSys_temp > 1800)
	   {
	       CtrlSys_temp =-(3600-CtrlSys_temp);
	   }
   if(CtrlSys_temp<-1800)
	   {
	       CtrlSys_temp=3600+CtrlSys_temp;
	   }
   
   LDistance = (DEF_FLOAT32)(plen*cos(((DEF_FLOAT32)CtrlSys_temp/572.96f)));// �����ƫ��   
   
   return LDistance;
}






/*============================================================================*
* ��������			Line_Guidance_Law
*============================================================================*
*
* ���ܣ�ƽ���Ƶ��ɼ���
*
* ����: ƽ���Ƶ��ɿ��Ƽ��㣬��������  ƫ����
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
void Line_Guidance_Law(void)
{

	Navigation();
	OutLoop_Track();
	SwitchWP();
}



/*============================================================================*
* ��������			Circle_Guidance_Law
*============================================================================*
*
* ���ܣ�ƽ���Ƶ��ɼ���
*
* ����: ƽ���Ƶ��ɿ��Ƽ��㣬��������  ƫ����
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
void Circle_Guidance_Law(void)
{
	Navigation();
	OutLoop_Track();
	SwitchWP();
}






/*============================================================================*
* ��������			CtrlLaw_ini
*============================================================================*
*
* ���ܣ������ɳ�ʼ������,ÿ�η���ģʽ�ı�ʱ������һ��
*
* ����: �л�����ģʽʱ��ִ�иú���1��
*
* ע�⣺
*
* ������	
*
* RETURENS��
*
*============================================================================*/
void CtrlLaw_ini(void)
{
	switch(CtrlLaw0D_FlightCtroInfor.FlightMode)
		{
	
		//�������
		case FlightModel_GoPoint_1:
				{
					CHENTIAN =10;
			
			        //��ȡ��һ������
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
			
			        //��ȡ��һ������
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
			
			        //��ȡ��һ������
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
			
			        //��ȡ��һ������
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
			
			        //��ȡ��һ������
				bcopy(&((FlightPath_Package[4][0]).PathNO),&(Trans_PathPoint.PathNO),sizeof(Trans_PathPoint));
							   
				CopyWP(&PathPoint[CtrlSys_CurrentPoint],&(Trans_PathPoint));
				
	                 	CtrlSys_taLon1 = PathPoint[CtrlSys_CurrentPoint].PointLong;
		           	CtrlSys_taLat1 = PathPoint[CtrlSys_CurrentPoint].PointLat; 

				CtrlSys_CWn = 5;
				CtrlSys_CPn = 1;

				break;
			}	

		
		//��������
		case 0x50:
			{
		  		 //��������ʱ��PathPoint[CtrlSys_TempPoint]��Ϊ�������ߵĲο���
	                       //��ʼ��ʱ���ǡ��Ϊ�������ߣ����Ե�������Ϊ�ο���
	                       //���Խ�������ľ��ȡ�γ�ȡ��߶ȴ���PathPoint[CtrlSys_TempPoint]
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
		                     
			 	//Ȼ�󽫵�ǰ����任�ɾ��Ժ���
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
		

	//����ƫ���ǹ���
	CtrlSys_tay = 0;

	//����״̬������
	CtrlSys_error_yaw = 0;

	CtrlSys_ei2_y = 0;
	CtrlSys_ei1_y = 0;            //������
	CtrlSys_isSafeMode = FALSE;
		
	
}



/*============================================================================*
* ��������			OutLoop_Track
*============================================================================*
*
* ���ܣ�  �����⻷������  
*
* ����:    	���ò�ƫ�����Ŀ�꺽���
*
*
*============================================================================*/
DEF_INT16 CtrlSys_aly = 0;				      		  //ͨ����ƫ��������Ŀ�꺽���
DEF_INT16 CtrlSys_cLerror = 0;				         //��ǰ��ƫ�� 




void OutLoop_Track(void)
{
	//��ƫ��---> Ŀ�꺽���   10Hz
	//��ƫ��---> Ŀ�꺽���   10Hz		
	DEF_INT32 error = 0, CtrlSys_OutLoop_Track_temp_1 = 0, CtrlSys_OutLoop_Track_temp_2 = 0;     
	
	//���뻺������
    CtrlSys_cLerror = CtrlSys_tcLerror;	
    CtrlSys_cSpe = CtrlSys_tcSpe;   //0.1m/s

	//���㺽������ƫ��ƫ��
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
		  //��ƫ��΢��  0.1m/s
		   CtrlSys_cdLerror = (DEF_FLOAT32)(CtrlSys_cSpe*sin(((DEF_FLOAT32)CtrlSys_OutLoop_Track_temp_1/572.96f)));// �����ƫ��΢���� 
				
          //������
		   error = CtrlSys_cLerror; 
			
		  //���û�г�������ֵ����Ŀ�꺽���Ϊ0
		   if (error < CtrlLaw04_TrajPlanPara.Para_kcth && error > -CtrlLaw04_TrajPlanPara.Para_kcth)
		   		{					         
					CtrlSys_aly = 0;
					CtrlSys_OutLoop_Track_temp_1 = CtrlSys_aly; //��ƫ�ർ��   
		       		CtrlSys_ei1_y = 0;
					CtrlSys_tay = CtrlSys_OutLoop_Track_temp_1; 			
		    	}
		   else
		   		{
					//���������ֵ
					if( error > CtrlSys_kcth || error < -CtrlSys_kcth )
						{
							//����ڵڶ�����
							if( error > 0 )
								CtrlSys_OutLoop_Track_temp_1 = CtrlLaw04_TrajPlanPara.Para_kcp1 * CtrlSys_kcth + CtrlLaw04_TrajPlanPara.Para_kcp2 * ( error - CtrlSys_kcth );	
							else
								CtrlSys_OutLoop_Track_temp_1 = -CtrlLaw04_TrajPlanPara.Para_kcp1 * CtrlSys_kcth + CtrlLaw04_TrajPlanPara.Para_kcp2 * ( error + CtrlSys_kcth );	
						}
					else
						{
							//����ڵ�һ����
							CtrlSys_OutLoop_Track_temp_1 = CtrlLaw04_TrajPlanPara.Para_kcp1 * error;
						}
			
					//����΢�ֵ�ֵ  CtrlSys_cdLerror  0.1m/s
			      	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 - CtrlSys_cdLerror * CtrlLaw04_TrajPlanPara.Para_kcd / 10.0;
				
					//������ֵ�ֵ
					if ( error < CtrlSys_icth && error > -CtrlSys_icth )
						{
							//�������Ļ���
							CtrlSys_ei1_y= CtrlSys_ei1_y + error; 
							if(CtrlSys_ei1_y>100000)
								CtrlSys_ei1_y =100000;
							else if(CtrlSys_ei1_y<-100000)
								CtrlSys_ei1_y = -100000;
							CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 + CtrlSys_ei1_y * CtrlLaw04_TrajPlanPara.Para_kci / 100000.0;		  
						}
					else
						{
							//�������ֿ����ķ�Χ��������Ч�����������Ļ���Ϊ0
							CtrlSys_ei1_y = 0;
						}
				
			      	//�ܱ�������
			     	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 * CtrlLaw04_TrajPlanPara.Para_kcpt*10.0;   //�Ŵ�10��������Ϊ����ʱ�Ƕ�ֵ��λΪ 0.1��

	              	//�����λ			                  
					if ( CtrlSys_OutLoop_Track_temp_1 > CtrlLaw04_TrajPlanPara.Para_kclimit )
						CtrlSys_OutLoop_Track_temp_1 = CtrlLaw04_TrajPlanPara.Para_kclimit;
				    else if ( CtrlSys_OutLoop_Track_temp_1 < -CtrlLaw04_TrajPlanPara.Para_kclimit )
						CtrlSys_OutLoop_Track_temp_1 = -CtrlLaw04_TrajPlanPara.Para_kclimit;							

		   		
			   } 
	   	}
	   	
	else  
		{
	       //�����ǰֵ��Ŀ����������aly = CtrlSys_acou;   
	       //��ֹĿ�꺽����ת������з��������Ա仯
	       CtrlSys_OutLoop_Track_temp_1 = 0;
		   
		}
				   
	//���
	CtrlSys_OutLoop_Track_temp_1 = CtrlSys_OutLoop_Track_temp_1 + CtrlSys_acou;  	

	if(CtrlSys_OutLoop_Track_temp_1 < 0)
		CtrlSys_OutLoop_Track_temp_1 += 3600;
	else if(CtrlSys_OutLoop_Track_temp_1 >= 3600)
		CtrlSys_OutLoop_Track_temp_1 -= 3600;
	
	// ���������0��359��
	if (CtrlSys_OutLoop_Track_temp_1 > 3599)
		CtrlSys_OutLoop_Track_temp_1 = 3599;
	else if (CtrlSys_OutLoop_Track_temp_1 < 0)
		CtrlSys_OutLoop_Track_temp_1 = 0;   
	
					 
	CtrlSys_aly = CtrlSys_OutLoop_Track_temp_1;		
	CtrlSys_tay = CtrlSys_aly;

}
 


/*============================================================================*
* ��������			Yaw_Track
*============================================================================*
*
* ���ܣ���������ƫ����
*
* ����:    
*
*
*============================================================================*/

  
  DEF_DOUBLE64 CtrlSys_cdy1 = 0;
  DEF_DOUBLE64 CtrlSys_d1=0;
  DEF_DOUBLE64 CtrlSys_d = 0;
  
void Yaw_Track(void)
{
	/*--------------------------��������ƫ����--------------------------*/

			CtrlSys_temp_sy = 0; 
			CtrlSys_error_yaw = 0;
			//ƫ�������
			if (CtrlSys_tay<0)
				CtrlSys_tay = CtrlSys_tay + 3600;
			else if (CtrlSys_tay>3600)
				CtrlSys_tay = CtrlSys_tay-3600;
			
			CtrlSys_error_yaw = CtrlSys_tay - CtrlSys_cy;		
			CtrlSys_error_dyaw = CtrlSys_error_yaw -CtrlSys_error_yaw_last;
			
			//���û�г�������ֵ��������Ϊ0			
			if ( CtrlSys_error_yaw < CtrlLaw06_GesturePara.Para_kyth * 10.0 && CtrlSys_error_yaw > -CtrlLaw06_GesturePara.Para_kyth*10.0 )
				{
					CtrlSys_temp_sy =0;								 		       
			        CtrlSys_ei2_y= 0;	
				
					//�����λ
					if ( CtrlSys_temp_sy > CtrlLaw06_GesturePara.Para_kylimit )
						CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kylimit;
					else if ( CtrlSys_temp_sy < -CtrlLaw06_GesturePara.Para_kylimit )
						CtrlSys_temp_sy = -CtrlLaw06_GesturePara.Para_kylimit;
					//���
					CtrlSys_sy = CtrlSys_temp_sy;
			 	}
			else
				{			
					if ( CtrlSys_error_yaw > 1800 )
						{
							//ay ��cy �����eΪ��,��ay=3300,CtrlSys_cy=300 			 
							CtrlSys_error_yaw = -(3600 - CtrlSys_error_yaw);     
						}
					else if (CtrlSys_error_yaw < -1800 )
						{
							//ay��cy���Ҳ�eΪ��,��ay =300,CtrlSys_cy=3300
							CtrlSys_error_yaw = 3600 + CtrlSys_error_yaw;         
						}

				//��ƫ��̫��ʱ����ת�߼�
				//if (CtrlSys_error_yaw > 1500 || CtrlSys_error_yaw < -1500)
			   		// CtrlSys_error_yaw = 1500;
				  
				//���������ֵ
				if( CtrlSys_error_yaw > CtrlSys_kyth || CtrlSys_error_yaw < -CtrlSys_kyth )
					{
						//����ڵڶ�����
						if(CtrlSys_error_yaw > 0)
							CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kyp1 * CtrlSys_kyth + CtrlLaw06_GesturePara.Para_kyp2 * ( CtrlSys_error_yaw - CtrlSys_kyth );	
						else
							CtrlSys_temp_sy = -CtrlLaw06_GesturePara.Para_kyp1 * CtrlSys_kyth + CtrlLaw06_GesturePara.Para_kyp2 * ( CtrlSys_error_yaw + CtrlSys_kyth );	
					}
				else
					{
						//����ڵ�һ����
						CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kyp1 * CtrlSys_error_yaw;
					}
				

				//������ֵ�ֵ
				if (CtrlSys_error_yaw < CtrlSys_iyth && CtrlSys_error_yaw > -CtrlSys_iyth)
					{
						//�������Ļ���
						CtrlSys_ei2_y = CtrlSys_ei2_y + CtrlSys_error_yaw/10.0; 

						if(CtrlSys_ei2_y>1000)

							CtrlSys_ei2_y =1000;

						else if(CtrlSys_ei2_y<-1000)

							CtrlSys_ei2_y = -1000;

						CtrlSys_temp_sy = CtrlSys_temp_sy + CtrlSys_ei2_y * CtrlLaw06_GesturePara.Para_kyi / 1000.0;
					}
				else
					{
					        //�������ֿ����ķ�Χ��������Ч�����������Ļ���Ϊ0
					         CtrlSys_ei2_y = 0;
					} 
				
					

				//����΢�ֵ�ֵ
				CtrlSys_cdy =  CtrlSys_error_yaw_last - CtrlSys_error_yaw;
				
				CtrlSys_temp_sy = CtrlSys_temp_sy - CtrlSys_cdy * CtrlLaw06_GesturePara.Para_kyd;

				//CtrlSys_d = CtrlSys_cdy*CtrlLaw06_GesturePara.Para_kyd/10.0;
				//CtrlSys_temp_sy = CtrlSys_temp_sy - ((1.0-CtrlLaw06_GesturePara.Para_kyth)*CtrlSys_d + CtrlLaw06_GesturePara.Para_kyth*CtrlSys_d1);
				//CtrlSys_d1 = CtrlSys_d; 										

				//�ܱ�������
				CtrlSys_temp_sy = CtrlSys_temp_sy * CtrlLaw06_GesturePara.Para_kypt;

				//�����λ
				if ( CtrlSys_temp_sy > CtrlLaw06_GesturePara.Para_kylimit )
					CtrlSys_temp_sy = CtrlLaw06_GesturePara.Para_kylimit;
				else if ( CtrlSys_temp_sy < -CtrlLaw06_GesturePara.Para_kylimit )
					CtrlSys_temp_sy = -CtrlLaw06_GesturePara.Para_kylimit;
				//���
				//CtrlSys_sy = CtrlSys_temp_sy;

				

			/*-----------------����˲�-----------------------*/
			Filter_va =  CtrlLaw07_CtrlAllocatePara.CAPara5;
		    Low_filter[1]=CtrlSys_temp_sy;//��ű��β���ֵ
			CtrlSys_temp_sy=(1-Filter_va)*Low_filter[1]+Filter_va*Low_filter[0];   //���㱾���˲�ֵ
			CtrlSys_sy = CtrlSys_temp_sy;
			Low_filter[0]=CtrlSys_sy;    //�����ϴ��˲�ֵ

			}	
			
	CtrlSys_error_yaw_last = CtrlSys_error_yaw;
}

/*============================================================================*
* ��������			Brennschluss
*============================================================================*
*
* ���ܣ�ִ��������Ϩ��
*
* ����:    ���ա��½�ģʽ����Ϩ��״̬
*
*
*============================================================================*/
void Brennschluss(void)
	{
		CtrlSys_Thro_LeftFront = 0;			//��ǰ������ת��
		CtrlSys_Thro_LeftBack = 0;			//���������ת��
		CtrlSys_Thro_RightFront = 0;			//��ǰ������ת��
		CtrlSys_Thro_RightBack =  0;			//�Һ�������ת��
		CtrlSys_Thro_FrontFan = 0;			//ǰ������ת��
		CtrlSys_VectorAngle= 0;				//ʸ��װ��ת��	

	}



/*============================================================================*
* ��������			Wind_Resist
*============================================================================*
*
* ���ܣ��������
*
* ����:    ƫ���Ǹ��ٷ���
*
*
*============================================================================*/
void Wind_Resist(void)
	{
		//�趨����ƫ����Ϊ���糡ֵ����Ϊ��ǰ�����+ pi
		DEF_UINT32 temp_CruiseDerection = 0;
		temp_CruiseDerection = CtrlLaw09_WindSpDirection.WindSet_H_Angle * 10000.0 + CtrlSys_PI * 10000.0;
		if (temp_CruiseDerection > 62800)
			{
				CtrlSys_tay = (temp_CruiseDerection - 62800)*0.18/CtrlSys_PI;	//��λΪ0.1��
				
			}

		else
			{
				CtrlSys_tay = temp_CruiseDerection*0.18/CtrlSys_PI;	//��λΪ0.1��
			}
		//��������ƫ����
		Yaw_Track();
	}





/*============================================================================*
* ��������			Line_Path_Track
*============================================================================*
*
* ���ܣ��������
*
* ����:    ���ݺ������
*
*
*============================================================================*/
void Line_Path_Track(void)
{
	Line_Guidance_Law();
	Yaw_Track();
}




/*============================================================================*
* ��������			Circle_Path_Track
*============================================================================*
*
* ���ܣ���������
*
* ����:   �ƶ��㶨�뾶����
*
*
*============================================================================*/
void Circle_Path_Track()
{
	Circle_Guidance_Law();
	
	Yaw_Track();
}





/*============================================================================*
* ��������			Remote_Control
*============================================================================*
*
* ���ܣ� ң�ط���
*
* ����:   �ɵ���վ����ң���źŽ��п���
*
*
*============================================================================*/



void Remote_Control(void)
{
	if (CtrlLaw0B_RemoteCtrl.CtrlMode== FlightModel_RCCtrl_Fault)				/*����ģʽ*/					/*��������ģʽ*/
		{
		CtrlSys_Thro_LeftFront=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*��1������*/
		CtrlSys_Thro_LeftBack=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*��2������*/
		CtrlSys_Thro_RightFront=CtrlLaw0B_RemoteCtrl.Propeller_Right/10.0;		/*��1������*/
		CtrlSys_Thro_RightBack=CtrlLaw0B_RemoteCtrl.Propeller_Right/10.0;		/*��2������*/	
		switch (CtrlLaw0B_RemoteCtrl.Propeller_Front)
			{
				case RC_Tail_Plus:
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_Max-CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Fan_Max;}								/*ǰ������ת��*/
					else {CtrlSys_Thro_FrontFan_Basic = CtrlSys_Thro_FrontFan_Basic+CtrlSys_Fan_change;}		
					break;
				case RC_Tail_Minus:																				
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Thro_FrontFan_Basic-CtrlSys_Fan_change;}					/*ǰ������ת��*/
					else {CtrlSys_Thro_FrontFan_Basic = 0;}			
					break;
				default :				
					break;
			}
		switch (CtrlLaw0B_RemoteCtrl.VectorReset)
			{
				case RC_Vector_Reset:
					CtrlSys_VectorAngle=0;								/*ǰʸ����*/
					break;
				default:
					CtrlSys_VectorAngle=CtrlLaw0B_RemoteCtrl.VertorAngle;/*ǰʸ����*/
					break;
			}
		}
		
	else if (CtrlLaw0B_RemoteCtrl.CtrlMode== FlightModel_RCCtrl_Mix)							/*��ϵ���ģʽ*/
		{
			switch (CtrlLaw0B_RemoteCtrl.VectorReset)
			{
				case RC_Vector_Reset:											/*��������*/
					CtrlSys_VectorAngle=0;									/*ǰʸ����*/
					break;
				default:														/*������*/
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
					if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Thro_FrontFan_Basic-CtrlSys_Fan_change;}			/*ǰ������ת��*/
					else {CtrlSys_Thro_FrontFan_Basic = 0;}								
					break;
				default:																							/*����*/					
					break;
			}

			
		CtrlSys_Thro=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0 + (CtrlLaw07_CtrlAllocatePara.CAPara1* CtrlSys_VectorAngle);		/*��1������*/
		if (CtrlSys_Thro>CtrlSys_Pro_Max){CtrlSys_Thro_LeftFront = CtrlSys_Pro_Max;}
		else if(CtrlSys_Thro<0){CtrlSys_Thro_LeftFront = 0;}
		else {CtrlSys_Thro_LeftFront = CtrlSys_Thro;	}	
		CtrlSys_Thro_LeftBack=CtrlSys_Thro_LeftFront;										/*��2������*/
		
		CtrlSys_Thro=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0 - (CtrlLaw07_CtrlAllocatePara.CAPara1 * CtrlSys_VectorAngle);		/*��1������*/
		if (CtrlSys_Thro<0){CtrlSys_Thro_RightFront = 0;}	
		else if (CtrlSys_Thro >CtrlSys_Pro_Max){CtrlSys_Thro_RightFront = CtrlSys_Pro_Max;}	
		else {CtrlSys_Thro_RightFront = CtrlSys_Thro;	}
		CtrlSys_Thro_RightBack=CtrlSys_Thro_RightFront;									/*��2������*/	
		}

	
	else 																
		{
		
			CtrlSys_Thro_LeftFront=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*��1������*/
			CtrlSys_Thro_LeftBack=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;				/*��2������*/
			CtrlSys_Thro_RightFront=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*��1������*/
			CtrlSys_Thro_RightBack=CtrlLaw0B_RemoteCtrl.Propeller_Left/10.0;			/*��2������*/
		
			switch (CtrlLaw0B_RemoteCtrl.Propeller_Front)
				{				
					case RC_Tail_Plus:													/*ǰ������������*/
						if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_Max-CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Fan_Max;}	/*ǰ������ת��*/
						else {CtrlSys_Thro_FrontFan_Basic = CtrlSys_Thro_FrontFan_Basic+CtrlSys_Fan_change;}								
						break;
						
					case RC_Tail_Minus:																				/*ǰ������������*/
						if (CtrlSys_Thro_FrontFan_Basic>CtrlSys_Fan_change)	{CtrlSys_Thro_FrontFan_Basic=CtrlSys_Thro_FrontFan_Basic-CtrlSys_Fan_change;}			/*ǰ������ת��*/
						else {CtrlSys_Thro_FrontFan_Basic = 0;}			
						break;
						
					default:													/*����*/
						break;
				}
			
			switch (CtrlLaw0B_RemoteCtrl.VectorReset)
				{
					
					case RC_Vector_Reset:										/*��������*/
						CtrlSys_VectorAngle=0;								/*ʸ���ǹ���*/
						break;
						
					default:													/*������*/
						CtrlSys_VectorAngle=CtrlLaw0B_RemoteCtrl.VertorAngle;
						break;
				}



		
		}

		CtrlSys_Thro_FrontFan = CtrlSys_Thro_FrontFan_Basic * CtrlLaw07_CtrlAllocatePara.CAPara3 * sin(fabs(CtrlSys_VectorAngle*PI/1800.0));



}






/*============================================================================*
* ��������			Constant_Speed
*============================================================================*
*
* ���ܣ� ���������
*
* ����:     ���ٹ̶�����Ƿ���
*
*
*============================================================================*/

void Constant_headangle(void)
{
	CtrlSys_tay = CtrlLaw05_CruiseDirection.CruiseDirection*1800.0/CtrlSys_PI;	//��λΪ0.1��
	Yaw_Track();
}

/*============================================================================*
* ��������			Reside_Mode
*============================================================================*
*
* ���ܣ� ����פ��ģʽ���ڹ̶�������פ��
*
* ����:     �����趨����פ�����ں�������ʱ���п������(��ʱ���л�����ģʽ)
*
*
*============================================================================*/

DEF_INT16 CtrlSys_aHoy =0;					  //ͨ����ǰ���ԭ������λ�ü������Ŀ�꺽���
DEF_FLOAT32  CtrlSys_tHomeDistf =0;   				 //��ǰ�㵽ԭ�����,����Ϊ��λ.(����)

DEF_INT32  CtrlSys_HomeLon =0;                                    //ԭ�㾭��  
DEF_INT32  CtrlSys_HomeLat =0;					  //ԭ��γ��
DEF_UINT16  CtrlSys_HomeDist =0; 					  // ����ԭ����룬��λ10m
DEF_UINT16  CtrlSys_TotalDist =0; 					  // ��������ʱ����ȫ�������߽绺����룬��λ10m(���ܿ���)
DEF_UINT16  CtrlSys_BufferDist =0;					  // ��������ʱ����ȫ�������߽绺����룬��λ10m
DEF_UINT16  CtrlSys_CoreDist =0; 					  // ��������ʱ����������߽����ԭ����룬��λ10m


void Reside_Mode(void)
{

	// ���㵱ǰ���㵽ԭ��ĺ����
      CtrlSys_aHoy=Cal_Point(CtrlSys_tcLon, CtrlSys_tcLat,CtrlSys_HomeLon, CtrlSys_HomeLat,&CtrlSys_tHomeDistf);      
	  
      //��ǰ�㵽ԭ��ľ���(��λ10m)
      CtrlSys_HomeDist= (DEF_INT32)CtrlSys_tHomeDistf/10.0;  

	if( CtrlSys_HomeDist < CtrlSys_CoreDist )		//��ͧ�ں���������
		{
			Wind_Resist();
		}
	else{
	  	//�趨ԭ��ΪĿ�꺽��					    
	       CtrlSys_taLon1 = CtrlSys_HomeLon;
		CtrlSys_taLat1 = CtrlSys_HomeLat;	     
		CtrlSys_tacou1 = CtrlSys_aHoy;
		Navigation();
		OutLoop_Track();
		Yaw_Track();
				
		}
}




/*============================================================================*
* ��������			Control_Law
*============================================================================*
*
* ���ܣ��Զ����п���
*
* ����:    �л�����ģʽ������ɵ�ǰģʽ�¿����������
*
*
*============================================================================*/

 
  DEF_UINT8   CtrlSys_Flight_Mode = CtrlSys_RC;           		  //����ģʽ��Ĭ��Ϊң��ģʽ
  DEF_UINT8   CtrlSys_Flight_State = CtrlSys_NORMAL;             //����״̬��Ĭ��Ϊ����


  DEF_INT32 CtrlSys_tcdp = 0;                   		   //�������ٶ�
  DEF_INT32 CtrlSys_tcdr = 0;					   //��ת���ٶ�
  DEF_INT32 CtrlSys_tcdy = 0;				 	   //������ٶ�
  
  DEF_INT16 CtrlSys_cfv = 0;   				 //��ǰǰ���ٶ�   0.1m/s
  DEF_INT16 CtrlSys_csv = 0; 					 //��ǰ����ٶ� 0.1m/s  
  DEF_INT16 CtrlSys_chv = 0; 					 // ��ֱ�ٶȷ���0.1m/s

  DEF_DOUBLE64 CtrlSys_tcdp1 = 0;
  DEF_DOUBLE64 CtrlSys_tcdr1 = 0;
  DEF_DOUBLE64 CtrlSys_tcdy1 = 0;

  DEF_FLOAT32 CtrlSys_TempF32 = 0;

  DEF_FLOAT32 CtrlSys_T_angle = 0;
  
  DEF_DOUBLE64 CtrlSys_saturation = 200;

  DEF_UINT8	CtrlSys_CtrlAllloMode = 0x01;				//���Ʒ���ģʽ,��ʼ��Ϊģʽ1
 

 void Task_CtrlLaw_Operate()
 {



	/*----------1-�ɿ����ݸ���----------*/
		CtrlInfor_Update();		//ʵ�ʷ���
	//SemSim_Update();		//������

	/*----------2-�жϷ���ģʽ��������Ӧ���п���----------*/

		/* ----------------------2.1���뻺������---------------------------*/
			//���뵱ǰλ����Ϣ(���ȡ�γ�ȡ��߶�)			
			CtrlSys_tcLon = CtrlLaw0D_FlightCtroInfor.FlightLong;		//��ǰ����(������)����λ10-7 rad
			CtrlSys_tcLat= CtrlLaw0D_FlightCtroInfor.FlightLat;		//��ǰγ��(������)����λ10-7 rad	
			CtrlSys_tcHei = CtrlLaw0D_FlightCtroInfor.Height; 					//��λm
			
			//����ǰ���������ʱ�Ĵ���
			PathPoint[CtrlSys_TempPoint].PointLong = CtrlSys_tcLon;
			PathPoint[CtrlSys_TempPoint].PointLat = CtrlSys_tcLat;
				
			//���뵱ǰ��̬��
			CtrlSys_cp = CtrlLaw0D_FlightCtroInfor.PitchAngle*0.18/CtrlSys_PI;	//��λΪ0.1��
			CtrlSys_cr = CtrlLaw0D_FlightCtroInfor.RollAngle*0.18/CtrlSys_PI;		//��λΪ0.1��
			CtrlSys_cy = CtrlLaw0D_FlightCtroInfor.HeadAngle*0.18/CtrlSys_PI;	//��ǰ������,��λΪ0.1��
			CtrlSys_cHy = CtrlSys_cy;
			CtrlSys_cGy = CtrlSys_cy;
			
			//���뵱ǰ�ٶ�
			CtrlSys_tcSpe = sqrt((CtrlLaw0D_FlightCtroInfor.EastVelo * CtrlLaw0D_FlightCtroInfor.EastVelo)+(CtrlLaw0D_FlightCtroInfor.NorthVelo* CtrlLaw0D_FlightCtroInfor.NorthVelo)+(CtrlLaw0D_FlightCtroInfor.VertiVelo* CtrlLaw0D_FlightCtroInfor.VertiVelo) )/10.0;   //��ǰ����0.1m/s(����)
			CtrlSys_cSpe = CtrlSys_tcSpe;
			
			//���뵱ǰ���ٶ�
			CtrlSys_tcdy = CtrlLaw0D_FlightCtroInfor.ZAngleRate*180.0/CtrlSys_PI; 
			CtrlSys_tcdp = CtrlLaw0D_FlightCtroInfor.YAngleRate*180.0/CtrlSys_PI;
			CtrlSys_tcdr = CtrlLaw0D_FlightCtroInfor.XAngleRate*180.0/CtrlSys_PI;	
			
			CtrlSys_cdy = CtrlSys_tcdy/10.0;					//��ǰƫ�����ٶ�,��λΪ0.01��/s
			CtrlSys_cdp = CtrlSys_tcdp/10.0;					//��ǰ�������ٶ�,��λΪ0.01��/s
			CtrlSys_cdr =  CtrlSys_tcdr/10.0;					//��ǰ��ת���ٶ�,��λΪ0.01��/s
			/*			
			//�˲��õ�ƫ����΢��ֵ
			CtrlSys_tcdy = (CtrlSys_tcdy + CtrlSys_tcdy1)/2.0;	//ƽ��ֵ�˲�
			CtrlSys_tcdp = (CtrlSys_tcdp + CtrlSys_tcdp1)/2.0;	//ƽ��ֵ�˲�
			CtrlSys_tcdr = (CtrlSys_tcdr + CtrlSys_tcdr1)/2.0;	//ƽ��ֵ�˲�
			
			
			CtrlSys_tcdy1 = CtrlSys_tcdy;
			CtrlSys_tcdp1 = CtrlSys_tcdp;
			CtrlSys_tcdr1 = CtrlSys_tcdr;			
			
			



			//��ǰ��ת΢�� ��λΪ0.1��/��
			CtrlSys_dphi = CtrlSys_cdr + (CtrlSys_cdy*cos(CtrlSys_cr/10.0/180.0*CtrlSys_PI) + CtrlSys_cdp*sin(CtrlSys_cr/10.0/180.0*CtrlSys_PI))*tan(CtrlSys_cp/10.0/180.0*CtrlSys_PI);
	
			//��ǰ����΢�� ��λΪ0.1��/��
			CtrlSys_dtheta = CtrlSys_cdp*cos(CtrlSys_cr/10.0/180.0*CtrlSys_PI)  - CtrlSys_cdy*sin(CtrlSys_cr/10.0/180.0*CtrlSys_PI);
			
			//��ǰ����΢�� ��λΪ0.1��/��
			CtrlSys_dpsi = 1.0/cos((CtrlSys_cp/10.0)/180.0*CtrlSys_PI)*(CtrlSys_cdy*cos((CtrlSys_cr/10.0)/180.0*CtrlSys_PI) + CtrlSys_cdp*sin(CtrlSys_cr/10.0/180.0*CtrlSys_PI));
			*/
			
			//���뵱ǰʸ����λ��
			CtrlSys_VectorAngle_Current= CtrlLaw0D_FlightCtroInfor.VectorAngle;		
			//���뵱ǰ����������ת��
			CtrlSys_Thro_LeftFront_Current = CtrlLaw0D_FlightCtroInfor.Propeller_LeftFront;
			CtrlSys_Thro_LeftBack_Current = CtrlLaw0D_FlightCtroInfor.Propeller_LeftBack;
			CtrlSys_Thro_RightFront_Current = CtrlLaw0D_FlightCtroInfor.Propeller_RightFront;
			CtrlSys_Thro_RightBack_Current = CtrlLaw0D_FlightCtroInfor.Propeller_RightBack;

			//���㵱ǰ�ٶ�
			CtrlSys_TempF32 = CtrlLaw0D_FlightCtroInfor.NorthVelo * cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f)+CtrlLaw0D_FlightCtroInfor.EastVelo * sin((DEF_FLOAT32)CtrlSys_cy/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f)-CtrlLaw0D_FlightCtroInfor.VertiVelo * sin((DEF_FLOAT32)CtrlSys_cp/572.96f);
			CtrlSys_cfv = CtrlSys_TempF32/10.0;   //��ǰǰ���ٶ�   0.1m/s
	
			CtrlSys_TempF32 = CtrlLaw0D_FlightCtroInfor.NorthVelo * (cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*sin((DEF_FLOAT32)CtrlSys_cr/572.96f) - cos((DEF_FLOAT32)CtrlSys_cr/572.96f)*sin((DEF_FLOAT32)CtrlSys_cy/572.96f))+CtrlLaw0D_FlightCtroInfor.EastVelo *( sin((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*sin((DEF_FLOAT32)CtrlSys_cr/572.96f)+cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*cos((DEF_FLOAT32)CtrlSys_cr/572.96f))+CtrlLaw0D_FlightCtroInfor.VertiVelo *( sin((DEF_FLOAT32)CtrlSys_cr/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f));
		    	CtrlSys_csv = CtrlSys_TempF32/10.0;   //��ǰ����ٶ� 0.1m/s  
		    	
			CtrlSys_TempF32 = CtrlLaw0D_FlightCtroInfor.NorthVelo * (cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*cos((DEF_FLOAT32)CtrlSys_cr/572.96f) + sin((DEF_FLOAT32)CtrlSys_cr/572.96f)*sin((DEF_FLOAT32)CtrlSys_cy/572.96f)- sin((DEF_FLOAT32)CtrlSys_cr/572.96f)*cos((DEF_FLOAT32)CtrlSys_cy/572.96f))+CtrlLaw0D_FlightCtroInfor.EastVelo *( cos((DEF_FLOAT32)CtrlSys_cy/572.96f)*sin((DEF_FLOAT32)CtrlSys_cp/572.96f)*cos((DEF_FLOAT32)CtrlSys_cr/572.96f))+CtrlLaw0D_FlightCtroInfor.VertiVelo *( cos((DEF_FLOAT32)CtrlSys_cr/572.96f)*cos((DEF_FLOAT32)CtrlSys_cp/572.96f));
			CtrlSys_chv = CtrlSys_TempF32/10.0;  // ��ֱ�ٶȷ���0.1m/s

			//����פ������Բ����Ϣ			
			CtrlSys_HomeLon =CtrlLaw03_StayModePara.HomeLong;                              //ԭ�㾭��  
		 	CtrlSys_HomeLat =CtrlLaw03_StayModePara.HomeLat;					  //ԭ��γ��
			CtrlSys_TotalDist = CtrlLaw03_StayModePara.TotalAreaDist/10;				  //��������ʱ��������߽����ԭ����룬��λ10m
			CtrlSys_BufferDist =CtrlLaw03_StayModePara.BufferAreaDist/10; 			  // ��������ʱ����ȫ�������߽绺����룬��λ10m
		 	CtrlSys_CoreDist = CtrlLaw03_StayModePara.CoreAreaDist/10;				 // ��������ʱ����������߽����ԭ����룬��λ10m

			//�������ģʽ
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
			
	
		/* ----------------------2.2 �����ɽ���---------------------------*/
			//�жϷ���ģʽ
			if( CtrlSys_Flight_Mode ==CtrlSys_AUTO )	//����ģʽ
				{
					/*-----------------------���ݷ���ģʽ����ʸ��ƫ��-------------------------*/
					switch (CtrlLaw0D_FlightCtroInfor.FlightMode)
						{							
							case 	FlightModel_SetDirection :				// ��������У���ƫ���Ƿ���
								Constant_headangle();		break;
								
							case 	FlightModel_Stay :						//������У����ݹ��Ʒ糡�趨����ƫ���ǣ������ٴ�ƫ����
								Wind_Resist();			break;
								
							case	 FlightModel_GoPoint_1: 				//���Ʒ�ͧ������Ѳ�����У������һ������ʱ�л�Ϊ����פ����ԲѲ����
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_2 :				//���Ʒ�ͧ������Ѳ�����У������һ������ʱ�л�Ϊ����פ����ԲѲ����
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_3 :				//���Ʒ�ͧ������Ѳ�����У������һ������ʱ�л�Ϊ����פ����ԲѲ����
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_4 :				//���Ʒ�ͧ������Ѳ�����У������һ������ʱ�л�Ϊ����פ����ԲѲ����
								Line_Path_Track();		break;

							case	 FlightModel_GoPoint_5 :				//���Ʒ�ͧ������Ѳ�����У������һ������ʱ�л�Ϊ����פ����ԲѲ����
								Line_Path_Track();		break;
								
							case	 FlightModel_FlyRound :					//���Ʒ�ͧ�����������������һ������ʱ�л�Ϊ����פ����ԲѲ����
								Circle_Path_Track();	break;
									
							case	 FlightModel_Stay_Area :				//����פ�����У��жϷ�ͧλ��λ��ָ�������ڣ���Ϊ������У��������ؼ�ģʽ
								Reside_Mode();			break;
								
							default:					
								break;					
						  }

					/*-----------------------------��ȫģʽ����----------------------------*/

					  if(CtrlSys_isSafeMode == TRUE)
					 	  {
							  CtrlSys_Flight_State = CtrlSys_UNNORMAL;
							  //�������
							  Wind_Resist();							
						   }

				     /*-----------------------����������ת��-----------------------*/
				
					//���ݿ���ģʽ�������������ת��
					//���������
					CtrlSys_Thro_LeftFront = (1-CtrlLaw0A_EngineState.Propeller1) * (YK0A_PropellerNCtrl.AirscrewNCtrl[0] + CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);
					CtrlSys_Thro_LeftBack = (1-CtrlLaw0A_EngineState.Propeller2) * ( YK0A_PropellerNCtrl.AirscrewNCtrl[1]  + CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);
					
					//�Ҳ�������
					CtrlSys_Thro_RightFront = (1-CtrlLaw0A_EngineState.Propeller3) * ( YK0A_PropellerNCtrl.AirscrewNCtrl[2]  -  CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);
					CtrlSys_Thro_RightBack = (1-CtrlLaw0A_EngineState.Propeller4) * ( YK0A_PropellerNCtrl.AirscrewNCtrl[3]  - CtrlLaw07_CtrlAllocatePara.CAPara1*CtrlSys_temp_sy);

					//ǰ��������
					CtrlSys_Thro_FrontFan_Basic = (1-CtrlLaw0A_EngineState.Propeller_Front) * YK0A_PropellerNCtrl.AirscrewNCtrl[4];
					CtrlSys_Thro_FrontFan = CtrlSys_Thro_FrontFan_Basic * CtrlLaw07_CtrlAllocatePara.CAPara3 * sin(fabs(CtrlSys_temp_sy*PI/1800.0));

										
					 /*-----------------------����ʸ��ƫ��-----------------------*/
					//���ݿ���ģʽ������ʸ��ƫ��
					CtrlSys_VectorAngle = CtrlSys_temp_sy;
				 	

		
					//ǰ��ʸ�����ٶ��޷�
					/*
					if ((CtrlSys_VectorAngle - CtrlSys_VectorAngle_Current) > CtrlLaw07_CtrlAllocatePara.CAPara2)
						CtrlSys_VectorAngle = CtrlSys_VectorAngle_Current + CtrlLaw07_CtrlAllocatePara.CAPara2;
					else if ((CtrlSys_VectorAngle -CtrlSys_VectorAngle_Current ) < -CtrlLaw07_CtrlAllocatePara.CAPara2)
						CtrlSys_VectorAngle = CtrlSys_VectorAngle_Current - CtrlLaw07_CtrlAllocatePara.CAPara2;
*/
					
					//ʸ����λ���޷�
					//ǰ��ʸ�����޷�
					if (CtrlSys_VectorAngle> CtrlSys_Vect_Limit)
							CtrlSys_VectorAngle = CtrlSys_Vect_Limit;
					else if (CtrlSys_VectorAngle < -CtrlSys_Vect_Limit)
							CtrlSys_VectorAngle = -CtrlSys_Vect_Limit;
					
					/*-----------�������������ת�١�ʸ��װ�ýǶ�----------*/		
					//�������,����������
					//�������Ӽ����޷�
				
					CtrlSys_Thro_LeftFront = GetLimitValue(CtrlSys_Thro_LeftFront, CtrlSys_Thro_LeftFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
					CtrlSys_Thro_LeftBack = GetLimitValue(CtrlSys_Thro_LeftBack, CtrlSys_Thro_LeftBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
					CtrlSys_Thro_RightFront = GetLimitValue(CtrlSys_Thro_RightFront, CtrlSys_Thro_RightFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
					CtrlSys_Thro_RightBack = GetLimitValue(CtrlSys_Thro_RightBack, CtrlSys_Thro_RightBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);


					//������ת���޷�
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

					//�������,ʸ��װ��ת��
					Vector_Control(0x01,CtrlSys_VectorAngle);	//�Ƕȿ���
					Vector_Control(0x02,0);		//��������			
					  
				}  
			
			
			else if( CtrlSys_Flight_Mode ==CtrlSys_RC )		//ң��ģʽ����
			{
				Remote_Control();	
				/*-----------�������������ת�١�ʸ��װ�ýǶ�----------*/		
				//�������,����������
				//�������Ӽ����޷�
				
				CtrlSys_Thro_LeftFront = GetLimitValue(CtrlSys_Thro_LeftFront, CtrlSys_Thro_LeftFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
				CtrlSys_Thro_LeftBack = GetLimitValue(CtrlSys_Thro_LeftBack, CtrlSys_Thro_LeftBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
				CtrlSys_Thro_RightFront = GetLimitValue(CtrlSys_Thro_RightFront, CtrlSys_Thro_RightFront_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);
				CtrlSys_Thro_RightBack = GetLimitValue(CtrlSys_Thro_RightBack, CtrlSys_Thro_RightBack_Current, CtrlLaw07_CtrlAllocatePara.CAPara4);



				//������ת���޷�
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

				//�������,ʸ��װ��ת��
				Vector_Control(0x01,CtrlSys_VectorAngle);	//�Ƕȿ���
				Vector_Control(0x02,0);		//��������			
			}	
			

		

}

  

 /*--------------------------�������ú���---------------------------*/
 
 /*---------Matlab ���ݽ��մ���---------*/
void Task_Mat2FK_Recieve()	
{
if(U9RxFBufPo!=U9RxFBufPi)
	{
	bcopy(&(U9RxFBuf[U9RxFBufPo][0]),&(Trans_Matlab_Recieve),sizeof(Trans_Matlab_Recieve));
	U9RxFBufPo=(U9RxFBufPo+1)%U9_RxF_BufLen;
	
	if(Trans_Matlab_Recieve.CheckSum==AddSum1((DEF_UINT8*)&(Trans_Matlab_Recieve.FrameHead_1),55))
		{
		DelaySecond_Healthy[0][5]=0;		//��ʱ������0 
		
		//��������

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

	//�齨������Matlab������֡	
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_1 = 0xAA;
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_2 = 0x55;
	CtrlLaw0G_SemSimFKtoMAT.FrameLength = 18;
	CtrlLaw0G_SemSimFKtoMAT.CircleCount = CtrlLaw0H_SemSimMATtoFK.CircleCount + 1;

/*	
	//û��ִ�л������ݻش�
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate1 = CtrlSys_Thro_LeftFront;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate2 = CtrlSys_Thro_LeftBack;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate3 = CtrlSys_Thro_RightFront;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate4 = CtrlSys_Thro_RightBack;
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate_Front = CtrlSys_Thro_FrontFan;
	CtrlLaw0G_SemSimFKtoMAT.VectorAngle = CtrlSys_VectorAngle;

*/
	

	//����ִ�л������ݻش�
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate1 = g_YC_Package.TJ.AirscrewActualN[0];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate2 = g_YC_Package.TJ.AirscrewActualN[1];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate3 = g_YC_Package.TJ.AirscrewActualN[2];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate4 = g_YC_Package.TJ.AirscrewActualN[3];
	CtrlLaw0G_SemSimFKtoMAT.PropellerRate_Front = g_YC_Package.TJ.AirscrewActualN[4];
	CtrlLaw0G_SemSimFKtoMAT.VectorAngle=g_YC_Package.TJ.VectorAngle;		//ת��Ϊ��ʵֵ���Ƕ�

	
	CtrlLaw0G_SemSimFKtoMAT.Reserved_17 = 0;		//����
	CtrlLaw0G_SemSimFKtoMAT.CheckSum = AddSum1((DEF_UINT8*)(&(CtrlLaw0G_SemSimFKtoMAT)), (sizeof(CtrlLaw0G_SemSimFKtoMAT)-1) );		
	
	U9InTxBuf((U8*)&(CtrlLaw0G_SemSimFKtoMAT),18);

}



void Task_FK2Mat_Filter_Send()
{

	//�齨������Matlab������֡	
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_1 = 0xAA;
	CtrlLaw0G_SemSimFKtoMAT.FrameHead_2 = 0x55;
	CtrlLaw0G_SemSimFKtoMAT.FrameLength = 56;
	CtrlLaw0G_SemSimFKtoMAT.CircleCount = CtrlLaw0H_SemSimMATtoFK.CircleCount + 1;

	
	//û��ִ�л������ݻش�
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

	CtrlLaw0I_Matlab_Recieve1.Reserved_53[0]= 53;		//����
	CtrlLaw0I_Matlab_Recieve1.Reserved_53[1]= 54;		//����
	CtrlLaw0I_Matlab_Recieve1.Reserved_53[2]= 55;		//����
	
	CtrlLaw0I_Matlab_Recieve1.CheckSum = AddSum1((DEF_UINT8*)(&(CtrlLaw0I_Matlab_Recieve1)), (sizeof(CtrlLaw0I_Matlab_Recieve1)-1) );		
	
	U9InTxBuf((U8*)&(CtrlLaw0I_Matlab_Recieve1),56);

}







/*-------�����ڴ��ַ�е��ֽ�˳��-------*/
/*-------����:  1-��ʼλ�ã� 2-�ֽڸ���(1~8, ������8)-------*/
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



		
		
/*----����޷��������:   1-����ֵ��2-��ǰֵ��3-�޷�---*/
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







