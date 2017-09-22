/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/

#include "main.h"
#include "Configuration.h"


 U32 TimingDelay =0;  //ϵͳ��ʱ������

/*************************************************************************************
��������Delay1
�������������ӳ�ʱ�� (����ȷ��
���롡��nCount:�ƶ��ӳ�ʱ�䳤��	  0.1ms	  STM32ִ��һ��ָ���ԼΪ��ʮns
���������
���ء�����
*************************************************************************************/
void Delay(u32 nCount)
{
	int i;
	for(;nCount != 0;nCount--)
	{
		for(i=0;i<1200;i++)
		{
		
		
		}
	}	
}


//��ȷ��ʱms
void Delayms(u32 nTime)
{
     TimingDelay = nTime;

     while(TimingDelay != 0);
}

/****************************************************************\
�������ƣ�FIRCal
�������ܣ�FIR�ƶ�ƽ���˲�������

ʹ����򵥵��ƶ�ƽ���˲�����FIR�˲����и������Ȩֵϵ�����

indΪ��ǰ��������
xΪ���λ������׵�ַ
pΪ��������ַ
lenΪ�˲�������
\****************************************************************/
U32 FIRCal(U32 ind, U32 *x, U8 *p, U8 len)
{
U8  i;
U32 t;

    //��������
	*p  = (*p + 1) % len;
	x[*p] = ind;

	t = 0;

    for (i=0; i<len; i++)	
    {
	    t = t + x[i];    
	}
	
	t = t/len;
	    
	return t;
}

// 3�����Ƚϴ�С
U8 MINNum(U16 x0, U16 x1, U16 x2)
{
     if((x0<x1)&&(x0<x2))
	  return  0;
     else if((x1<x0)&&(x1<x2))
	  return  1; 
     else if((x2<x0)&&(x2<x1))
          return  2; 
     else  return 3;  	  	     
}

static const uint8 CTOHtable[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

uint8 CharToHex( uint8 c1, uint8 c2)
{
   	U8 i=0,r=0;
	while(CTOHtable[i]!=c1)
	{
	     i++;
	     if(i>=16)
		  {	                
			  return FALSE;  		
		  }		 
	}
	r=i*16;
	i=0;
	while(CTOHtable[i]!=c2)
	{
	     i++;
	     if(i>=16)
		  {	                
			  return FALSE;  		
		  }		 
	}
	r=r+i;
	return r;
}


	
void TmpCtrl(void)  //�¶ȿ���
 {
 S16 TempS16 = 0;
 static U8 Cn=0;

        //�¶Ȳ���
        TempS16 = Get_Tmp100(); //�¶Ȳ���

	
        if(TempS16 >-1000 )
        {
	        InnerTmp = (S8)TempS16;
		 ResetBit(Hardware_State2, 5);     //����  bit5 Tmp100                0���� 1����
		 Cn = 0;
        }
	 else 
	 {
	        Cn++;	 	 
	 }

	 if(Cn>20)
	 {
               InnerTmp = 0;
		 SetBit(Hardware_State2, 5);     //����  bit5 Tmp100                0���� 1����
	 }
	 
          
        //�¿�����    0:  �Զ��¿�  1: ���� 2:������
        if(TmpCtrl_CMD==0)
        {
               if (GetBit(Hardware_State2, 5) ==0)
               {
		          //����������
			 if(InnerTmp<Heat_StartT)
			 	 Set_TC_DO; //��������
			 else if(InnerTmp>=Heat_StopT)
			 	 Reset_TC_DO; //ֹͣ����
               }
		  else
		 {
		       //����������
	              Reset_TC_DO; //ֹͣ����
		 }		   
        }
        else if(TmpCtrl_CMD==1)
		Set_TC_DO; //��������
	 else if(TmpCtrl_CMD==2)
	 	Reset_TC_DO; //ֹͣ����
        

 }


void Save_ProData(void)  //�洢�ֳ���������
{
     Pro_Data.HeadByte1 = 0xA5;
     Pro_Data.HeadByte2 = 0x5A; 
     SRAM_WriteBuffer((uint8_t*)&Pro_Data, NVRAMProData_ADDR, sizeof(Pro_Datat));
     

}
void Read_ProData(void)  //��ȡ�ֳ���������
{
 Pro_Datat  tPro_Data;     
 
      SRAM_ReadBuffer((uint8_t*)&tPro_Data, NVRAMProData_ADDR, sizeof(Pro_Datat));
	  
      if((tPro_Data.HeadByte1 == 0xA5)&&(tPro_Data.HeadByte2 == 0x5A)&&(tPro_Data.CtrlByte == 1))
      	{            
               memcpy(&Pro_Data, &tPro_Data,  sizeof(Pro_Datat)); 	   


	}
       else
       {
              Pro_Data.HeadByte1 = 0;
		Pro_Data.HeadByte2 = 0;
		Pro_Data.CtrlByte = 0;
	}
	
	
}




