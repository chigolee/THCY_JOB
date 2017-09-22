/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/

#include "main.h"
#include "Configuration.h"


 U32 TimingDelay =0;  //系统延时计数器

/*************************************************************************************
函数名：Delay1
描述　：插入延迟时间 (不精确）
输入　：nCount:制定延迟时间长度	  0.1ms	  STM32执行一条指令大约为几十ns
输出　：无
返回　：无
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


//精确延时ms
void Delayms(u32 nTime)
{
     TimingDelay = nTime;

     while(TimingDelay != 0);
}

/****************************************************************\
函数名称：FIRCal
函数功能：FIR移动平滑滤波器计算

使用最简单的移动平滑滤波，即FIR滤波器中各个项的权值系数相等

ind为当前输入数据
x为环形缓冲区首地址
p为计数器地址
len为滤波器长度
\****************************************************************/
U32 FIRCal(U32 ind, U32 *x, U8 *p, U8 len)
{
U8  i;
U32 t;

    //更新数据
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

// 3个数比较大小
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


	
void TmpCtrl(void)  //温度控制
 {
 S16 TempS16 = 0;
 static U8 Cn=0;

        //温度测量
        TempS16 = Get_Tmp100(); //温度测量

	
        if(TempS16 >-1000 )
        {
	        InnerTmp = (S8)TempS16;
		 ResetBit(Hardware_State2, 5);     //正常  bit5 Tmp100                0正常 1故障
		 Cn = 0;
        }
	 else 
	 {
	        Cn++;	 	 
	 }

	 if(Cn>20)
	 {
               InnerTmp = 0;
		 SetBit(Hardware_State2, 5);     //故障  bit5 Tmp100                0正常 1故障
	 }
	 
          
        //温控命令    0:  自动温控  1: 加温 2:不加温
        if(TmpCtrl_CMD==0)
        {
               if (GetBit(Hardware_State2, 5) ==0)
               {
		          //传感器正常
			 if(InnerTmp<Heat_StartT)
			 	 Set_TC_DO; //启动加温
			 else if(InnerTmp>=Heat_StopT)
			 	 Reset_TC_DO; //停止加温
               }
		  else
		 {
		       //传感器故障
	              Reset_TC_DO; //停止加温
		 }		   
        }
        else if(TmpCtrl_CMD==1)
		Set_TC_DO; //启动加温
	 else if(TmpCtrl_CMD==2)
	 	Reset_TC_DO; //停止加温
        

 }


void Save_ProData(void)  //存储现场保护数据
{
     Pro_Data.HeadByte1 = 0xA5;
     Pro_Data.HeadByte2 = 0x5A; 
     SRAM_WriteBuffer((uint8_t*)&Pro_Data, NVRAMProData_ADDR, sizeof(Pro_Datat));
     

}
void Read_ProData(void)  //读取现场保护数据
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




