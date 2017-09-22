
#include "main.h"
#include "Configuration.h"



 
void Tmp100_Init(void) //��ʼ��
{
 GPIO_InitTypeDef GPIO_InitStructure;
 I2C_InitTypeDef I2C_InitStructure;
  
  /* Enable IOE_I2C and IOE_I2C_GPIO_PORT & Alternate Function clocks */
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C3, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC , ENABLE);
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  /* Reset IOE_I2C IP */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C3, ENABLE);
  
  /* Release reset signal of IOE_I2C IP */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C3, DISABLE);
  
  /* IOE_I2C SCL and SDA pins configuration */

  //PA8  SCL3
  //PC9  SDA3
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_I2C3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_I2C3); 

  /* IOE_I2C configuration */
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
  I2C_InitStructure.I2C_OwnAddress1 = 0x00;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_ClockSpeed = 100000;  


  /* sEE_I2C Peripheral Enable */
   I2C_Cmd(I2C3, ENABLE);

   I2C_Init(I2C3, &I2C_InitStructure);

   I2C_AcknowledgeConfig(I2C3, ENABLE);

 

}

#define TIMEOUT_MAX    300 /*<! The value of the maximal timeout for I2C waiting loops */

uint32_t IOE_TimeOut = TIMEOUT_MAX; /*<! Value of Timeout when I2C communication fails */

U8 SignForI2C=0;
S16 Get_Tmp100(void)  //��ȡ�¶�
{
static S16 TempS16 =0;

static U8 Cn=0;
     
   
     if(Cn ==0)
     {
            IOE_TimeOut = TIMEOUT_MAX;
	      /*����1�ֽ�1Ӧ��ģʽ*/
	     I2C_AcknowledgeConfig(I2C3, ENABLE);

	      /* ������ʼλ */
	     I2C_GenerateSTART(I2C3, ENABLE);
     }
     else if(Cn ==1)
     {    
	 
	      I2C_Send7bitAddress(I2C3, Tmp100_DeviceAddr, I2C_Direction_Transmitter); 
     	
     } 
     else if(Cn ==2)
     {
    
              I2C_SendData(I2C3, Tmp100_RegisterAddr);
     }
   
     else if(Cn ==3)
     {
  
		/*��ʼλ*/
	      I2C_GenerateSTART(I2C3, ENABLE);
     }
     else if(Cn ==4)
     {
	
             I2C_Send7bitAddress(I2C3, Tmp100_DeviceAddr, I2C_Direction_Receiver);
	    
     }
     else if(Cn ==5)
     {

	SignForI2C=0;
	    /* ��Temperature Register*/	    
	    while(!I2C_CheckEvent(I2C3, I2C_EVENT_MASTER_BYTE_RECEIVED)) /* EV7 */
	    {
	            IOE_TimeOut--;
	            if (IOE_TimeOut == 0)
	            	{
	            	SignForI2C=1;
			I2C_AcknowledgeConfig(I2C3, DISABLE); //���һλ��Ҫ�ر�Ӧ���
	    		I2C_GenerateSTOP(I2C3, ENABLE);   //����ֹͣλ 
	    		break;
	            	}
	     }
		if(SignForI2C==0)
			{
	    		TempS16 = I2C_ReceiveData(I2C3);	  	
			I2C_AcknowledgeConfig(I2C3, DISABLE); //���һλ��Ҫ�ر�Ӧ���
	    		I2C_GenerateSTOP(I2C3, ENABLE);   //����ֹͣλ 
			}
		
     }

     if(IOE_TimeOut == 0)
   	    TempS16 = -2000; //�����־

     Cn = (Cn+1)%6;  
   
     return TempS16;

}




