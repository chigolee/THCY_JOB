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

  //Ӳ����ʼ��
  InitDevice();
  
  //�ֳ��������ݻָ�
  Read_ProData();

  ReadNandErrByte();

  //������ʼ��  
  USART1_Printf("Stratospheric Airship Control System V1.0.1!\n" );   // ��������   


/*------------�û����ݳ�ʼ��------*/
 {
//--�ֳ��������ݻָ�
	Pro_Data.CtrlByte=0x01;	//���ݱ�����־
	Current_RecordBlock=Pro_Data.Current_RecordBlock+1;
	g_YC_Package.HD01.CriticalBaricAlt=Pro_Data.CriticalBaricAlt;
	g_YC_Package.TJ.PropellerN_Limit=Pro_Data.PropellerN_Limit;
	g_YC_Package.TJ.FrontPropelN_Limit=Pro_Data.FrontPropelN_Limit;
	g_YC_Package.TJ.FlightMode=Pro_Data.FlightMode;
	g_YC_Package.HD01.CompuRecState=Pro_Data.CompuRecState;
	g_YC_Package.HD01.SafeCtrlMinite=Pro_Data.SafeCtrlMinite;
	g_YC_Package.TJ.AirscrewCtrlState=Pro_Data.AirscrewCtrlState;

	if((g_YC_Package.HD01.CriticalBaricAlt<0)||(g_YC_Package.HD01.CriticalBaricAlt>3000)){g_YC_Package.HD01.CriticalBaricAlt=50;}	//Ĭ��50
	if((g_YC_Package.TJ.PropellerN_Limit==0)||(g_YC_Package.TJ.PropellerN_Limit>=600)){g_YC_Package.TJ.PropellerN_Limit=600;}		//Ĭ��600
	if((g_YC_Package.TJ.FrontPropelN_Limit==0)||(g_YC_Package.TJ.FrontPropelN_Limit>=3000)){g_YC_Package.TJ.FrontPropelN_Limit=3000;}		//Ĭ��3000
	if(g_YC_Package.TJ.FlightMode==0){g_YC_Package.TJ.FlightMode=0x10;}		//Ĭ������ģʽ

	if((g_YC_Package.HD01.SafeCtrlMinite<10)||(g_YC_Package.HD01.SafeCtrlMinite>120)){g_YC_Package.HD01.SafeCtrlMinite=30;}

//--�û����ݳ�ʼ��
	Ctrl_Para_Init();
}




  /* Add your application code here
     */

  LED1ON;
  LED2ON;
  LED3ON;
  LED4ON;

  rstdly = 1; //��ʼ��������

  /* Infinite loop */
  while (1)
  {

	  if(Is_FCS == TRUE)
	  {
               //100Hz
               //����û�����
               FCS();
               Is_FCS = FALSE;
	  }
	  if(ProData_Flag == TRUE)
	  {
                Save_ProData(); //�洢�ֳ���������
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

		  //������             
		
              Is_DIO = FALSE;
	  }
	   if(Is_WDG == TRUE)
         {
               // 10Hz   
              //Ӳ�����Ź�
              WDI_TOG;		
              Is_WDG = FALSE;
	  }  
	  
	  
       //�ⲿ��չ�������ݽ��մ���    
       ExUsartIRQ();
	ExUsartRXD();
 	if(Is_ExUsartSend == TRUE)
	{
              //500Hz
               ExUsartTXD(); //�ⲿ�������ݷ���
              Is_ExUsartSend = FALSE;
	}
	if(Is_CAN1Send == TRUE)   //20Hz
		{
		Can1SendDiv=(Can1SendDiv+1)%10;
		if(Can1SendDiv==0)
			{
	              // 2Hz
	               Can1OutTxFBuf(); ////CAN����֡����               	              
			}
		Is_CAN1Send = FALSE;
		}
	
	if(Is_CAN2Send == TRUE)   //20Hz
	{
	
              //5Hz           
               Can2OutTxFBuf(); ////CAN����֡����               
              
              //������
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
              TmpCtrl(); //�¶ȿ���         
              Is_TmpCtrl = FALSE;
	}
	
	

	

	 if (IsTest == TRUE)
	 { 			
	      // 1Hz	
	      // ������
	       if(IsSystemTest == TRUE)
	       {
	              //DOѭ�����
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
			//USART1_Printf("D0:%d, Dn:%d\n", DownLoadData[0],DownLoadData[RecordF_Len-1]);   // ��������
			//USART1_Printf("R:%d, D:%d\n", NandErrByte[0],Current_DownloadBlock); 

			 
			 
                      //�����л�����
			 //USART_SW_U1;
			 //USART_SW_U2;

			 //���²���

			 //Ӳ�����Ź�����
			 
		     
	       }
              //USART1_Printf("ADC1:%d, ADC2:%d, ADC3:%d, ADC4:%d,Tmp:%d!\n", ADC_TestData[0] ,ADC_TestData[1],ADC_TestData[2] ,ADC_TestData[11] , Get_Tmp100()); 
		
	     
	      	
	      	//LED ��˸
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
