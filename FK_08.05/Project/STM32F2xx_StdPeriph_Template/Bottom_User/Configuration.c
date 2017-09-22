/*************************************************************************\
\**************************Glider_Control    2012.06.24**************************/
/***************************Glider_Control System*****************************\
\****************************** Main_Control ********************************/

#include "main.h"

 U16 ADC3ConvertedValue[4] = {0};
	  
void InitDevice(void)
{

RCC_ClocksTypeDef RCC_Clocks;	


  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f2xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f2xx.c file
     */  

    /* SysTick end of count event each 10ms */
    RCC_GetClocksFreq(&RCC_Clocks);
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);	   // 1ms

    GPIO_Configuration();
    UART_Configuration();    
    CAN_Configuration();
    ADC_Configuration();
    

   
    if(initMax14830A())
         ResetBit(Hardware_State2,2);  //0正常 1故障
    else SetBit(Hardware_State2,2);  //0正常 1故障

    if(initMax14830B())
         ResetBit(Hardware_State2,3);  //0正常 1故障
    else SetBit(Hardware_State2,3);  //0正常 1故障

    if(initMax14830C())
         ResetBit(Hardware_State2,4);  //0正常 1故障
    else SetBit(Hardware_State2,4);  //0正常 1故障
	
    if(SRAM_Init())
         ResetBit(Hardware_State1,1);  //0正常 1故障
    else SetBit(Hardware_State1,1);  //0正常 1故障    


/*------------调试注释掉-------------*/
	
    NAND_Init();
    
    Select_NAND0;
    NAND_ReadID(&NAND_ID);
    if(NAND_ID.Maker_ID == MakerID)
    ResetBit(Hardware_State1, 2);     //正常   //bit2  Nand Flash1
     else SetBit(Hardware_State1, 2);     //故障    //bit2  Nand Flash1
	
    Select_NAND1;    
    NAND_ReadID(&NAND_ID);
    if(NAND_ID.Maker_ID == MakerID)
    ResetBit(Hardware_State1, 3);     //正常   //bit3  Nand Flash2
    else SetBit(Hardware_State1, 3);     //故障    //bit3  Nand Flash2





    
    Tmp100_Init();   

}

//GPIO初始化
void GPIO_Configuration(void)
{
GPIO_InitTypeDef  GPIO_InitStructure;

      /*
       LED
       SLED1   PB0
       SLED2   PB1
       SLED3   PE11
       SLED4   PE12
       
        ADC Channel Select
       IOA0     PH5
       IOA1     PH4
       IOA2     PH3
       IOA3     PH2

       Digital Input
       IOB1     PH6
       IOB2     PH7
       IOB3     PH8
       IOB4     PH9
       IOB5     PH10
       IOB6     PH11
       IOB7     PH12
       IOB8     PB14

       Digital Output
       IOC1     PB15
       IOC2     PD8
       IOC3     PD9
       IOC4     PD10
       IOC5     PD13
       IOC6     PH13
       IOC7     PH14
       IOC8     PH15
       

       TC_DO  PA0
       DO_LE   PA1
       UART_SW   PF10
       WDI  PF9


       MAX_RST1   PA4
       MAX_IRQ1   PC4
       MAX_CS1    PC5

       MAX_RST2  PE13
       MAX_IRQ2  PE14
       MAX_CS2    PE15

       MAX_RST3  PF6
       MAX_IRQ3  PF7
       MAX_CS3   PF8
      */

      /*
        LED
       SLED1   PB0
       SLED2   PB1
       SLED3   PE11
       SLED4   PE12
       */
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
	
        //LED
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_12;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	  GPIO_Init(GPIOE, &GPIO_InitStructure);

	  LED1ON;
	  LED2OFF;
	  LED3ON;
	  LED4OFF;

       /*
	ADC Channel Select
       IOA0     PH5
       IOA1     PH4
       IOA2     PH3
       IOA3     PH2
       */
         GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOH, &GPIO_InitStructure);
	  Select_Ain1;
	  
	/*
	Digital Input
       IOB1     PH6
       IOB2     PH7
       IOB3     PH8
       IOB4     PH9
       IOB5     PH10
       IOB6     PH11
       IOB7     PH12
       IOB8     PB14
       */
         GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	  
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOH, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	  
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);

       /*
	  Digital Output
       IOC1     PB15
       IOC2     PD8
       IOC3     PD9
       IOC4     PD10
       IOC5     PD13
       IOC6     PH13
       IOC7     PH14
       IOC8     PH15
    */
         GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);

         GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_13;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOH, &GPIO_InitStructure);

	   //初始化置低
	   
	  GPIOB->BSRRH = GPIO_Pin_15;   //置低
	  GPIOD->BSRRH = GPIO_Pin_8;   //置低
	  GPIOD->BSRRH = GPIO_Pin_9;   //置低
	  GPIOD->BSRRH = GPIO_Pin_10;   //置低
	  GPIOD->BSRRH = GPIO_Pin_13;   //置低
	  GPIOH->BSRRH = GPIO_Pin_13;   //置低
	  GPIOH->BSRRH = GPIO_Pin_14;   //置低
	  GPIOH->BSRRH = GPIO_Pin_15;   //置低
        /*
	  GPIOB->BSRRH = GPIO_Pin_15;   //置低
	  GPIOD->BSRRH = GPIO_Pin_8;   //置低
	  GPIOD->BSRRH = GPIO_Pin_9;   //置低
	  GPIOD->BSRRH = GPIO_Pin_10;   //置低
	  GPIOD->BSRRL = GPIO_Pin_13;   //置高
	  GPIOH->BSRRL = GPIO_Pin_13;   //置高
	  GPIOH->BSRRL = GPIO_Pin_14;   //置高
	  GPIOH->BSRRL = GPIO_Pin_15;   //置高
	   */
	  /*
         TC_DO  PA0
         DO_LE   PA1
         UART_SW   PF10
         WDI  PF9
	  */
         GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOF, &GPIO_InitStructure);

	  //初始化置低
	  Reset_TC_DO;   //置低	  	  
	  USART_SW_U1;  //置低   UART_SW  选择RS422A_1输出
	  
	  Set_DO_LE;//置高
	  Delayms(2);
	  Reset_DO_LE;//置低
	

	

	  /*
	  MAX_RST1   PA4
         MAX_IRQ1   PC4
         MAX_CS1    PC5

         MAX_RST2  PE13
         MAX_IRQ2  PE14
         MAX_CS2    PE15

         MAX_RST3  PF6
         MAX_IRQ3  PF7
         MAX_CS3   PF8
	 */
         GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOE, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_8;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	  GPIO_Init(GPIOF, &GPIO_InitStructure);

         //初始化置高  //无效
	  GPIOA->BSRRL = GPIO_Pin_4;
	  GPIOC->BSRRL = GPIO_Pin_5;
	  GPIOE->BSRRL = GPIO_Pin_13;
	  GPIOE->BSRRL = GPIO_Pin_15;
	  GPIOF->BSRRL = GPIO_Pin_6;
	  GPIOF->BSRRL = GPIO_Pin_8;	  

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	  
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	  
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init(GPIOE, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	  
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_Init(GPIOF, &GPIO_InitStructure);	  

	  

}

void UART_Configuration(void)
{
	// TX1 PA9   RX1 PA10
	// TX2 PA2   RX2 PA3
	// TX3 PB10 RX3 PB11
	// TX4 PC10 RX4 PC11
	// TX5 PC12 RX5 PD2
	// TX6 PC6   RX6 PC7
	/*************UART1***************/
       USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	  /* Enable the USART OverSampling by 8 */
	  // USART_OverSampling8Cmd(USART1, ENABLE); 
		/* USARTx configured as follow:
	        - BaudRate = 115200 baud  
	        - Word Length = 8 Bits
	        - One Stop Bit
	        - No parity
	        - Hardware flow control disabled (RTS and CTS signals)
	        - Receive and transmit enabled
	  */	  

         // TX1 PA9   RX1 PA10
	  /* Enable GPIO clock */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	  /* Enable UART clock */
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	  /* Connect PA9 to USART1_Tx*/
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	  /* Connect PA10 to USART1_Rx*/
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	  
	  /* Configure USART Tx as alternate function  */
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
         GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
		 
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	  
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  /* Configure USART Rx as alternate function  */	  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);	  

         if(IsSystemTest == TRUE)
         {
                USART_InitStructure.USART_BaudRate = 115200;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  else
	  {
	         USART_InitStructure.USART_BaudRate = U1_BaudRate;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
        
	  /* USART configuration */
	  USART_Init(USART1, &USART_InitStructure);
	    
	  /* Enable USART */
	  USART_Cmd(USART1, ENABLE);

	  //STM_EVAL_COMInit(COM1, &USART_InitStructure);
		
	  /*************UART2***************/	
	   // TX2 PA2   RX2 PA3	
	  /* Enable GPIO clock */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	  /* Enable UART clock */
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	  /* Connect PA2 to USART2_Tx*/
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);

	  /* Connect PA3 to USART2_Rx*/
	  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

	  
	  /* Configure USART Tx as alternate function  */
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	  
	  GPIO_Init(GPIOA, &GPIO_InitStructure);

	  /* Configure USART Rx as alternate function  */	  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	  GPIO_Init(GPIOA, &GPIO_InitStructure);	  

         if(IsSystemTest == TRUE)
         {
                USART_InitStructure.USART_BaudRate = 115200;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  else
	  {
	         USART_InitStructure.USART_BaudRate = U2_BaudRate;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  /* USART configuration */
	  USART_Init(USART2, &USART_InitStructure);
	    
	  /* Enable USART */
	  USART_Cmd(USART2, ENABLE);

	  
	  /*************UART3***************/
	  // TX3 PB10 RX3 PB11	
	  /* Enable GPIO clock */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	  /* Enable UART clock */
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

	  /* Connect PB10 to USART3_Tx*/
	  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);

	  /* Connect PB11 to USART3_Rx*/
	  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);

	  /* Configure USART Tx as alternate function  */
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	  
	  GPIO_Init(GPIOB, &GPIO_InitStructure);

	  /* Configure USART Rx as alternate function  */	  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	  GPIO_Init(GPIOB, &GPIO_InitStructure);

         if(IsSystemTest == TRUE)
         {
                USART_InitStructure.USART_BaudRate = 115200;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  else
	  {
	         USART_InitStructure.USART_BaudRate = U3_BaudRate;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  /* USART configuration */
	  USART_Init(USART3, &USART_InitStructure);
	    
	  /* Enable USART */
	  USART_Cmd(USART3, ENABLE);
		
	  /*************UART4***************/
	  // TX4 PC10 RX4 PC11	
	  /* Enable GPIO clock */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	  /* Enable UART clock */
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);

	  /* Connect PC10 to USART4_Tx*/
	  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_UART4);

	  /* Connect PC11 to USART4_Rx*/
	  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_UART4);

	  /* Configure USART Tx as alternate function  */
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	  
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

	  /* Configure USART Rx as alternate function  */	  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

         if(IsSystemTest == TRUE)
         {
                USART_InitStructure.USART_BaudRate = 115200;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  else
	  {
	         USART_InitStructure.USART_BaudRate = U4_BaudRate;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  /* USART configuration */
	  USART_Init(UART4, &USART_InitStructure);
	    
	  /* Enable USART */
	  USART_Cmd(UART4, ENABLE);
		
	  /*************UART5***************/
	  // TX5 PC12 RX5 PD2
	
	  /* Enable GPIO clock */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOD, ENABLE);

	  /* Enable UART clock */
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);

	  /* Connect PC12 to USART5_Tx*/
	  GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_UART5);

	  /* Connect PD2 to USART5_Rx*/
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource2, GPIO_AF_UART5);

	  /* Configure USART Tx as alternate function  */
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	  
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

	  /* Configure USART Rx as alternate function  */	 
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

         if(IsSystemTest == TRUE)
         {
                USART_InitStructure.USART_BaudRate = 115200;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  else
	  {
	         USART_InitStructure.USART_BaudRate = U5_BaudRate;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  /* USART configuration */
	  USART_Init(UART5, &USART_InitStructure);
	    
	  /* Enable USART */
	  USART_Cmd(UART5, ENABLE);
		
	  /*************UART6***************/
	  // TX6 PC6  RX6 PC7
	  /* Enable GPIO clock */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	  /* Enable UART clock */
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);

	  /* Connect PC6 to USART6_Tx*/
	  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);

	  /* Connect PC7 to USART6_Rx*/
	  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);

	  /* Configure USART Tx as alternate function  */
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	  
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

	  /* Configure USART Rx as alternate function  */	  
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);

         if(IsSystemTest == TRUE)
         {
                USART_InitStructure.USART_BaudRate = 115200;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  else
	  {
	         USART_InitStructure.USART_BaudRate = U6_BaudRate;
		  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
		  USART_InitStructure.USART_StopBits = USART_StopBits_1;
		  USART_InitStructure.USART_Parity = USART_Parity_No;
		  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	  }
	  /* USART configuration */
	  USART_Init(USART6, &USART_InitStructure);
	    
	  /* Enable USART */
	  USART_Cmd(USART6, ENABLE);

	  //配置用1位表示优先级
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				 //选择第1组优先级

		
		/* NVIC configuration */
	  /* Configure the Priority Group to 2 bits */
	  // NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	  /* Enable the USARTx Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
	  /* Enable the USARTx Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
	  /* Enable the USARTx Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
	  /* Enable the USARTx Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
	  /* Enable the USARTx Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
	  /* Enable the USARTx Interrupt */
	  NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;
	  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
	USART_ITConfig(UART5, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	
}

 

void CAN_Configuration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	CAN_InitTypeDef        CAN_InitStructure;
       CAN_FilterInitTypeDef  CAN_FilterInitStructure;

	CanRxMsg RxMessage;
       CanTxMsg TxMessage;


  //CAN1
  /* CAN GPIOs configuration **************************************************/

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 

  /* Connect CAN pins to AF9 */
  //CANRX1   PA11     CANTX1   PA12
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_CAN1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_CAN1); 
  
  /* Configure CAN RX and TX pins */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* CAN configuration ********************************************************/  
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
  
  /* CAN register init */
  CAN_DeInit(CAN1);
  CAN_StructInit(&CAN_InitStructure);

  /* CAN cell init */
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE;
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_LoopBack;
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    
  //BaudRate = APB1 / (( BS1 + BS2 + 1) * Prescaler)  = 30M/((6+8+1)*8) = 250k
  CAN_InitStructure.CAN_BS1 = CAN_BS1_6tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
  CAN_InitStructure.CAN_Prescaler = 8;
  CAN_Init(CAN1, &CAN_InitStructure);

  /* CAN filter init */
// #ifdef  USE_CAN1
  CAN_FilterInitStructure.CAN_FilterNumber = 0;
// #else /* USE_CAN2 */
  //CAN_FilterInitStructure.CAN_FilterNumber = 1;
// #endif  /* USE_CAN1 */
  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(CAN1, &CAN_FilterInitStructure);

  //回绕测试
  TxMessage.StdId = 0x321;//设置标准标识符
  TxMessage.ExtId = 0x01;//设置扩展标识符
  TxMessage.RTR = CAN_RTR_DATA;//设置将要传送帧数据的类型
  TxMessage.IDE = CAN_ID_STD;//设置将要传送的消息的标识符类型
  TxMessage.DLC = 1;//设置帧长度
  TxMessage.Data[0] = 0x9F;//设置测试数据
  CAN_Transmit(CAN1, &TxMessage);//can发送 
  
  Delayms(10);  
  RxMessage.Data[0] =0;
  CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);	  
  if(TxMessage.Data[0] ==RxMessage.Data[0])
      ResetBit(Hardware_State2,0);  //0正常 1故障
  else SetBit(Hardware_State2,0);  //0正常 1故障  

  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  CAN_Init(CAN1, &CAN_InitStructure);     
 
   
  /* Enable FIFO 0 message pending Interrupt */
  CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
  /* Enable CAN1 RX0 interrupt IRQ channel */
  NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);


  //CAN2
/* CAN GPIOs configuration **************************************************/
  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 

  /* Connect CAN pins to AF9 */
  //CANRX2   PB12     CANTX2   PB13
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource12, GPIO_AF_CAN2);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource13, GPIO_AF_CAN2); 
  
  /* Configure CAN RX and TX pins */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* CAN configuration ********************************************************/  
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);
  
  /* CAN register init */
  CAN_DeInit(CAN2);
  CAN_StructInit(&CAN_InitStructure);

  /* CAN cell init */
  CAN_InitStructure.CAN_TTCM = DISABLE;
  CAN_InitStructure.CAN_ABOM = DISABLE;
  CAN_InitStructure.CAN_AWUM = DISABLE;
  CAN_InitStructure.CAN_NART = DISABLE;
  CAN_InitStructure.CAN_RFLM = DISABLE;
  CAN_InitStructure.CAN_TXFP = DISABLE;
  CAN_InitStructure.CAN_Mode = CAN_Mode_LoopBack;
  CAN_InitStructure.CAN_SJW = CAN_SJW_1tq;
    
  //BaudRate = APB1 / (( BS1 + BS2 + 1) * Prescaler)  = 30M/((6+8+1)*8) = 250k
  CAN_InitStructure.CAN_BS1 = CAN_BS1_6tq;
  CAN_InitStructure.CAN_BS2 = CAN_BS2_8tq;
  CAN_InitStructure.CAN_Prescaler = 8;
  CAN_Init(CAN2, &CAN_InitStructure);

  /* CAN filter init */
  // #ifdef  USE_CAN1
  //   CAN_FilterInitStructure.CAN_FilterNumber = 0;
  // #else /* USE_CAN2 */
  CAN_FilterInitStructure.CAN_FilterNumber = 14;
  // #endif  /* USE_CAN1 */
  CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;
  CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
  CAN_FilterInitStructure.CAN_FilterIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdHigh = 0x0000;
  CAN_FilterInitStructure.CAN_FilterMaskIdLow = 0x0000;
  CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_FIFO0;
  CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
  CAN_FilterInit(CAN2, &CAN_FilterInitStructure);

  //回绕测试
  TxMessage.StdId = 0x321;//设置标准标识符
  TxMessage.ExtId = 0x01;//设置扩展标识符
  TxMessage.RTR = CAN_RTR_DATA;//设置将要传送帧数据的类型
  TxMessage.IDE = CAN_ID_STD;//设置将要传送的消息的标识符类型
  TxMessage.DLC = 1;//设置帧长度
  TxMessage.Data[0] = 0x9F;//设置测试数据
  CAN_Transmit(CAN2, &TxMessage);//can发送 
  
  Delayms(10);  
  RxMessage.Data[0] =0;
  CAN_Receive(CAN2, CAN_FIFO0, &RxMessage);	  
  if(TxMessage.Data[0] ==RxMessage.Data[0])
      ResetBit(Hardware_State2,1);  //0正常 1故障
  else SetBit(Hardware_State2,1);  //0正常 1故障  

  CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;
  CAN_Init(CAN2, &CAN_InitStructure);     
   
  /* Enable FIFO 0 message pending Interrupt */
  CAN_ITConfig(CAN2, CAN_IT_FMP0, ENABLE);
  /* Enable CAN1 RX0 interrupt IRQ channel */
  NVIC_InitStructure.NVIC_IRQChannel = CAN2_RX0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  
}

 void ADC_Configuration(void)
 {
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  DMA_InitTypeDef       DMA_InitStructure;
  GPIO_InitTypeDef      GPIO_InitStructure;
  
//ADC1  PC0  ADC123_10
//ADC2  PC1  ADC123_11
//ADC3  PC2  ADC123_12
//ADC4  PC3  ADC123_13

/* Enable ADC3, DMA2 and GPIO clocks ****************************************/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOC, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);

  /* DMA2 Stream0 channel2 configuration **************************************/
  DMA_InitStructure.DMA_Channel = DMA_Channel_2;  
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC3_DR_ADDRESS;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADC3ConvertedValue;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = 4;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_Init(DMA2_Stream0, &DMA_InitStructure);
  DMA_Cmd(DMA2_Stream0, ENABLE);

  /* Configure ADC3 Channel10/11/12/13 pin as analog input ******************************/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  

  /* ADC Common Init **********************************************************/
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
  ADC_CommonInit(&ADC_CommonInitStructure);

  /* ADC3 Init ****************************************************************/
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;
  ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 4;
  ADC_Init(ADC3, &ADC_InitStructure);

  /* ADC3 regular channel7 configuration *************************************/
  ADC_RegularChannelConfig(ADC3, ADC_Channel_10, 1, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC3, ADC_Channel_11, 2, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC3, ADC_Channel_12, 3, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC3, ADC_Channel_13, 4, ADC_SampleTime_3Cycles);

  /* Enable DMA request after last transfer (Single-ADC mode) */
  ADC_DMARequestAfterLastTransferCmd(ADC3, ENABLE);

  /* Enable ADC3 DMA */
  ADC_DMACmd(ADC3, ENABLE);

  /* Enable ADC3 */
  ADC_Cmd(ADC3, ENABLE);

 /* Start ADC3 Software Conversion */ 
  ADC_SoftwareStartConv(ADC3);

 }




