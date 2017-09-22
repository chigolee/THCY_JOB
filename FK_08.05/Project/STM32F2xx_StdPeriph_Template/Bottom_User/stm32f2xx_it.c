/**
  ******************************************************************************
  * @file    Project/STM32F2xx_StdPeriph_Template/stm32f2xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
#include "stm32f2xx_it.h"
#include "main.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
 while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{

    static  U16 tc01 = 0;               //Timer0功能选定计数
    static  U8 tc011 = 0;               //Timer0功能选定计数
    static  U8 tc0111 = 0;               //Timer0功能选定计数

    static  U16 tc02 = 0;               //Timer0功能选定计数
        
   
   //系统延时用
    if(TimingDelay > 0)
       TimingDelay--;
        


	SystemTimems++;	//系统计时，单位1ms

	
    tc01 = (tc01+1)%10;  // 100Hz   
    
    tc02 = (tc02+1)%2;  // 500Hz   

    if(tc02 == 0)   
    {
            // 500Hz      
           Is_ExUsartSend = TRUE;  
    }
    
    if(tc01 == 1)   
    {   
           // 100Hz   
           Is_ADC = TRUE;	    
    } 
   else if(tc01 == 2)   
   {
          // 100Hz   
           if(rstdly>2)
               Is_FCS = TRUE;
   }   
   else if(tc01 == 9)   
   {
           //系统时钟单位10ms
           SystemTime++;
		   
	    tc011 = (tc011+1)%10;  // 10Hz   
           if(tc011 == 0)
	   {
	         // 10Hz  
	   	 Is_DIO  = TRUE;	
		 Is_WDG = TRUE;	
	   }	
	   if((tc011 == 1)||(tc011 == 6))
	   {
	        // 20Hz  
	   	 Is_CAN1Send  = TRUE;		  
	   }	  
	    if((tc011 == 2)||(tc011 == 7))
	   {
	        // 20Hz  
	   	 Is_CAN2Send  = TRUE;		  
	   }	  
	   else if(tc011 == 9)
	   { 	      

		 tc0111 = (tc0111+1)%10;  // 1Hz   
		 if(tc0111 == 0)
		   {				         
			  Is_TmpCtrl = TRUE;				  
		   }	
		   if(tc0111 == 2)
		   {	
			  IsTest = TRUE;				  
		   }	
		   else if(tc0111 == 8)
		   { 
		         
			  LED4TOG;
			  if(LED2_Flag ==0)
			  {
		               LED2OFF; 
			  }
			  else if(LED2_Flag ==1)
			  {
		               LED2ON; 
			  }
			  else 
			  {
		               LED2TOG; 
			  }
		   }		   
		   else if(tc0111 == 9)
		   { 
		         // 启动延时计数
		        if (rstdly > 0)
			 {
				 rstdly++;			   

				 if(rstdly > 200)
					rstdly = 200;	
			 }	  
		   }
		  
	   }

		   
   }

   
   

  
}

/******************************************************************************/
/*                 STM32F2xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f2xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
