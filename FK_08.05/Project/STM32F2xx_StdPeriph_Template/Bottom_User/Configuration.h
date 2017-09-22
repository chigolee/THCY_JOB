/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/

//系统配置文件，一般所有文件均须引用

//这一段无需改动

#ifndef _TYPE_DEF
#define _TYPE_DEF
typedef unsigned char  uint8;                   /* 无符号8位整型变量         */
typedef signed   char  int8;                    /* 有符号8位整型变量         */
typedef unsigned short uint16;                  /* 无符号16位整型变量        */
typedef signed   short int16;                   /* 有符号16位整型变量        */
typedef unsigned int   uint32;                  /* 无符号32位整型变量        */
typedef signed   int   int32;                   /* 有符号32位整型变量        */
typedef float          fp32;                     /* 单精度浮点数（32位长度）  */
typedef double       fp64;                    /* 双精度浮点数（64位长度）  */



typedef uint8  U8;
typedef uint16 U16;
typedef uint32 U32;
typedef int8   S8;
typedef int16  S16;
typedef int32  S32; 
typedef fp32   F32;
typedef fp64   F64;

typedef double V4[4];
typedef double V3[3];

#endif // _TYPE_DEF


#define FALSE  0
#define TRUE    1 

#ifndef _Configuration_H
#define _Configuration_H

extern void GPIO_Configuration(void);
extern void UART_Configuration(void);
extern void CAN_Configuration(void);

extern void ADC_Configuration(void);



extern void InitDevice(void);	

/*
LED
SLED1   PB0
SLED2   PB1
SLED3   PE11
SLED4   PE12
*/
#define LED1ON  GPIOB->BSRRH = GPIO_Pin_0    //置低
#define LED2ON  GPIOB->BSRRH = GPIO_Pin_1    //置低
#define LED3ON  GPIOE->BSRRH = GPIO_Pin_11  //置低
#define LED4ON  GPIOE->BSRRH = GPIO_Pin_12  //置低

#define LED1OFF  GPIOB->BSRRL = GPIO_Pin_0   //置高
#define LED2OFF  GPIOB->BSRRL = GPIO_Pin_1   //置高
#define LED3OFF  GPIOE->BSRRL = GPIO_Pin_11  //置高
#define LED4OFF  GPIOE->BSRRL = GPIO_Pin_12  //置高

#define LED1TOG  GPIOB->ODR ^= GPIO_Pin_0    //置反
#define LED2TOG  GPIOB->ODR ^= GPIO_Pin_1    //置反
#define LED3TOG  GPIOE->ODR ^= GPIO_Pin_11   //置反
#define LED4TOG  GPIOE->ODR ^= GPIO_Pin_12   //置反

 /*
ADC Channel Select
IOA0     PH5
IOA1     PH4
IOA2     PH3
IOA3     PH2
*/
#define Select_Ain1		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //0000   
#define Select_Ain2		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //0001      
#define Select_Ain3		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //0010      
#define Select_Ain4		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //0011   
#define Select_Ain5		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //0100    
#define Select_Ain6		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //0101   
#define Select_Ain7		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //0110 
#define Select_Ain8		GPIOH->BSRRH = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //0111
#define Select_Ain9		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //1000  
#define Select_Ain10		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //1001
#define Select_Ain11		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //1010  
#define Select_Ain12		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRH = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //1011
#define Select_Ain13		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //1100
#define Select_Ain14		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRH = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //1101
#define Select_Ain15		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRH = GPIO_Pin_5   //1110
#define Select_Ain16		GPIOH->BSRRL = GPIO_Pin_2; GPIOH->BSRRL = GPIO_Pin_3; GPIOH->BSRRL = GPIO_Pin_4; GPIOH->BSRRL = GPIO_Pin_5   //1111

/*
 TC_DO  PA0
 DO_LE   PA1
 UART_SW   PF10
 WDI  PF9
*/
//UART_SW   PF10 
#define USART_SW_U1     GPIOF->BSRRH = GPIO_Pin_10;  ResetBit(Hardware_State2, 6)  //置低   UART_SW  选择RS422A_1输出
#define USART_SW_U2     GPIOF->BSRRL = GPIO_Pin_10;  SetBit(Hardware_State2, 6)   //置高   UART_SW  选择RS422A_1输出

//WDI  PF9
#define WDI_TOG		       GPIOF->ODR ^= GPIO_Pin_9   //置反      // WDI  PF9                   喂狗信号输出     
//#define ResetWDI		GPIOF->BSRRH = GPIO_Pin_9      // WDI  PF9                   喂狗信号输出     

// DO_LE   PA1
#define Set_DO_LE		GPIOA->BSRRL = GPIO_Pin_1     // DO_LE   PA1                  DO输出直通  
#define Reset_DO_LE		GPIOA->BSRRH = GPIO_Pin_1      // DO_LE   PA1                 DO输出锁存    

// TC_DO  PA0
#define Set_TC_DO		GPIOA->BSRRL = GPIO_Pin_0     // TC_DO  PA0                  加温     
#define Reset_TC_DO		GPIOA->BSRRH = GPIO_Pin_0      // TC_DO  PA0                 不加温 


#define ADC3_DR_ADDRESS    ((uint32_t)0x4001224C)
extern U16 ADC3ConvertedValue[4];


#endif /* _Configuration_H */
