/**
  ******************************************************************************
  * @file    Project/STM32F2xx_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


CanRxMsg tRxMessage;
CanTxMsg tTxMessage;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
  
U8 Can1SendDiv=0;

int main(void)
{

  static U8 Cn =0;
 u32 TestData =0xA55AEB90;
  u32 TempU32 = 0;

  //硬件初始化
  InitDevice();
  
  //现场保护数据恢复
  Read_ProData();

  ReadNandErrByte();

  //参数初始化  
  USART1_Printf("Stratospheric Airship Control System V1.0.1!\n" );   // 发送数据   


/*------------用户数据初始化------*/
 {
//--现场保护数据恢复
	Pro_Data.CtrlByte=0x01;	//数据保护标志
	Current_RecordBlock=Pro_Data.Current_RecordBlock+1;
	g_YC_Package.HD01.CriticalBaricAlt=Pro_Data.CriticalBaricAlt;
	g_YC_Package.TJ.PropellerN_Limit=Pro_Data.PropellerN_Limit;
	g_YC_Package.TJ.FrontPropelN_Limit=Pro_Data.FrontPropelN_Limit;
	g_YC_Package.TJ.FlightMode=Pro_Data.FlightMode;
	g_YC_Package.HD01.CompuRecState=Pro_Data.CompuRecState;
	g_YC_Package.HD01.SafeCtrlMinite=Pro_Data.SafeCtrlMinite;
	g_YC_Package.TJ.AirscrewCtrlState=Pro_Data.AirscrewCtrlState;

	if((g_YC_Package.HD01.CriticalBaricAlt<0)||(g_YC_Package.HD01.CriticalBaricAlt>3000)){g_YC_Package.HD01.CriticalBaricAlt=50;}	//默认50
	if((g_YC_Package.TJ.PropellerN_Limit==0)||(g_YC_Package.TJ.PropellerN_Limit>=600)){g_YC_Package.TJ.PropellerN_Limit=600;}		//默认600
	if((g_YC_Package.TJ.FrontPropelN_Limit==0)||(g_YC_Package.TJ.FrontPropelN_Limit>=3000)){g_YC_Package.TJ.FrontPropelN_Limit=3000;}		//默认3000
	if(g_YC_Package.TJ.FlightMode==0){g_YC_Package.TJ.FlightMode=0x10;}		//默认升空模式

	if((g_YC_Package.HD01.SafeCtrlMinite<10)||(g_YC_Package.HD01.SafeCtrlMinite>120)){g_YC_Package.HD01.SafeCtrlMinite=30;}

//--用户数据初始化
	Ctrl_Para_Init();
}




  /* Add your application code here
     */

  LED1ON;
  LED2ON;
  LED3ON;
  LED4ON;

  rstdly = 1; //开始启动计数

  /* Infinite loop */
  while (1)
  {

	  if(Is_FCS == TRUE)
	  {
               //100Hz
               //添加用户程序
               FCS();
               Is_FCS = FALSE;
	  }
	  if(ProData_Flag == TRUE)
	  {
                Save_ProData(); //存储现场保护数据
	         ProData_Flag = FALSE;
	  }
         if(Is_ADC == TRUE)
         {
               // 100Hz   
              AD_Convert(); 
              Is_ADC = FALSE;
	  }
	   if(Is_DIO == TRUE)
         {
               // 10Hz   
              DIData = DI(); 
		DO(DOData);

		  //测试用             
		
              Is_DIO = FALSE;
	  }
	   if(Is_WDG == TRUE)
         {
               // 10Hz   
              //硬件看门狗
              WDI_TOG;		
              Is_WDG = FALSE;
	  }  
	  
	  
       //外部扩展串口数据接收处理    
       ExUsartIRQ();
	ExUsartRXD();
 	if(Is_ExUsartSend == TRUE)
	{
              //500Hz
               ExUsartTXD(); //外部串口数据发送
              Is_ExUsartSend = FALSE;
	}
	if(Is_CAN1Send == TRUE)   //20Hz
		{
		Can1SendDiv=(Can1SendDiv+1)%10;
		if(Can1SendDiv==0)
			{
	              // 2Hz
	               Can1OutTxFBuf(); ////CAN数据帧发送               	              
			}
		Is_CAN1Send = FALSE;
		}
	
	if(Is_CAN2Send == TRUE)   //20Hz
	{
	
              //5Hz           
               Can2OutTxFBuf(); ////CAN数据帧发送               
              
              //测试用
              if(IsSystemTest == TRUE)
              {
		       if(IsNandScanCMD  == TRUE)
			{
                              if(NandFlash_Scan())
                              {
                               
                              }
				  else  IsNandScanCMD = FALSE;
			 }
              }
			  
		Is_CAN2Send = FALSE;
		
	}
	
	if(Is_TmpCtrl == TRUE)
	{
              // 1s        
              TmpCtrl(); //温度控制         
              Is_TmpCtrl = FALSE;
	}
	
	

	

	 if (IsTest == TRUE)
	 { 			
	      // 1Hz	
	      // 测试用
	       if(IsSystemTest == TRUE)
	       {
	              //DO循环输出
                     Cn = (Cn+1)%16;
			if((Cn%2) == 0)
			{
                           DOData = 0x00;	
			}
			else
			{
                           DOData = (0x01<<(Cn/2));		
			}
			
			  
			
                      
			// Record();
                     // Download();
			//USART1_Printf("D0:%d, Dn:%d\n", DownLoadData[0],DownLoadData[RecordF_Len-1]);   // 发送数据
			//USART1_Printf("R:%d, D:%d\n", NandErrByte[0],Current_DownloadBlock); 

			 
			 
                      //串口切换操作
			 //USART_SW_U1;
			 //USART_SW_U2;

			 //加温测试

			 //硬件看门狗测试
			 
		     
	       }
              //USART1_Printf("ADC1:%d, ADC2:%d, ADC3:%d, ADC4:%d,Tmp:%d!\n", ADC_TestData[0] ,ADC_TestData[1],ADC_TestData[2] ,ADC_TestData[11] , Get_Tmp100()); 
		
	     
	      	
	      	//LED 闪烁
	      	LED3TOG;   
		IsTest = FALSE;				
	 } 

   
  
  }
}





/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
