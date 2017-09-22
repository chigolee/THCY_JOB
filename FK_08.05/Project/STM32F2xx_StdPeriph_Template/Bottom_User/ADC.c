#include "main.h"


/*
内部
ADC1        ADC3ConvertedValue[0]
ADC2        ADC3ConvertedValue[1]   
ADC3        ADC3ConvertedValue[2]        VCC3      比例尺VCC3 = (ADC3ConvertedValue[2]/4096)*33*(100/49.9)
ADC4        ADC3ConvertedValue[3]        VCC5      比例尺VCC5 = (ADC3ConvertedValue[3]/4096)*33*(100/49.9)

外部通过MAX306EU和ADC1扩展16路AIN,
其中前10路外接，后6路板上电压监控
AIN1          AinData[0]                比例尺AIN1 =  (AinData[10]/4096)*33*(2)
AIN2          AinData[1]                比例尺AIN2 =  (AinData[10]/4096)*33*(2)
AIN3          AinData[2]                比例尺AIN3 =  (AinData[10]/4096)*33*(2)
AIN4          AinData[3]                比例尺AIN4 =  (AinData[10]/4096)*33*(2)
AIN5          AinData[4]                比例尺AIN5 =  (AinData[10]/4096)*33*(2)
AIN6          AinData[5]                比例尺AIN6 =  (AinData[10]/4096)*33*(2)
AIN7          AinData[6]                比例尺AIN7 =  (AinData[10]/4096)*33*(2)
AIN8          AinData[7]                比例尺AIN8 =  (AinData[10]/4096)*33*(2)
AIN9          AinData[8]                比例尺AIN9 =  (AinData[10]/4096)*33*(2)
AIN10          AinData[9]              比例尺AIN10 =  (AinData[10]/4096)*33*(2)
AIN11          AinData[10]      OVCC3            比例尺OVCC3 =  (AinData[10]/4096)*33*(2)
AIN12          AinData[11]      OVCC5            比例尺OVCC5 =  (AinData[11]/4096)*33*(2)
AIN13          AinData[12]      OAGND            比例尺OAGND =  (AinData[12]/4096)*33*(2)
AIN14          AinData[13]                             比例尺AIN14 =  (AinData[13]/4096)*33*(2)
AIN15          AinData[14]      OAVCC12+      比例尺OAVCC12+  = (AinData[14]/4096)*33*(2*63.4/10.2)
AIN16          AinData[15]      MVCC              比例尺MVCC+  = (AinData[15]/4096)*33*(2*63.4/10.2)


*/
 // 100Hz   
void AD_Convert(void)
{

  static U8 Cn =0;
  F32 TempF32=0;

     Cn = (Cn+1)%17;  //17分频
     //5Hz
	
     if( Cn== 0 )
     {
         AinData[15]=  ADC3ConvertedValue[0]; 
         Select_Ain1; 	  
     }
    else if( Cn== 1 )
     {
         AinData[0] =  ADC3ConvertedValue[0]; 
         Select_Ain2; 
     }    
     else if( Cn== 2)
     {
         AinData[1] =  ADC3ConvertedValue[0]; 
         Select_Ain3; 
     }
     else if( Cn== 3 )
     {
         AinData[2] =  ADC3ConvertedValue[0]; 
         Select_Ain4; 
     }
     else if( Cn== 4 )
     {
         AinData[3] =  ADC3ConvertedValue[0]; 
         Select_Ain5; 
     }
     else if( Cn== 5 )
     {
         AinData[4] =  ADC3ConvertedValue[0]; 
         Select_Ain6; 
     }
     else if( Cn== 6 )
     {
         AinData[5] =  ADC3ConvertedValue[0]; 
         Select_Ain7; 
     }
     else if( Cn== 7 )
     {
         AinData[6] =  ADC3ConvertedValue[0]; 
         Select_Ain8; 
     }
     else if( Cn== 8 )
     {
         AinData[7] =  ADC3ConvertedValue[0]; 
         Select_Ain9; 
     }
     else if( Cn== 9)
     {
         AinData[8] =  ADC3ConvertedValue[0]; 
         Select_Ain10; 
     }
     else if( Cn== 10 )
     {
         AinData[9] =  ADC3ConvertedValue[0]; 
         Select_Ain11; 
     }
     else if( Cn== 11 )
     {
         AinData[10] =  ADC3ConvertedValue[0]; 
         Select_Ain12; 
     }
     else if( Cn== 12 )
     {
         AinData[11] =  ADC3ConvertedValue[0]; 
         Select_Ain13; 
     }
     else if( Cn== 13 )
     {
         AinData[12] =  ADC3ConvertedValue[0]; 
         Select_Ain14; 
     }
     else if( Cn== 14 )
     {
         AinData[13] =  ADC3ConvertedValue[0]; 
         Select_Ain15; 
     }
     else if( Cn== 15 )
     {
         AinData[14] =  ADC3ConvertedValue[0]; 
         Select_Ain16; 
     } 
     else if( Cn== 16)
     {
             TempF32 = ADC3ConvertedValue[2];			
             VCC3_Volt = (U16)((TempF32*33*2)/4096);
	      TempF32 = ADC3ConvertedValue[3];			
             VCC5_Volt = (U16)((TempF32*33*2)/4096);

	      TempF32 = AinData[10];		
             OVCC3_Volt = (U16)((TempF32*33*2)/4096);
	      TempF32 = AinData[11];		
             OVCC5_Volt = (U16)((TempF32*33*2)/4096);
	      TempF32 = AinData[12];		
             OAGND_Volt = (U16)((TempF32*33*2)/4096);

	      TempF32 = AinData[14];		
             OAVCC12_Volt = (U16)((TempF32*33*2*63.4/10.2)/4096);
	      TempF32 = AinData[15];		
             MVCC_Volt = (U16)((TempF32*33*2*63.4/10.2)/4096);

             //判断状态
             if((VCC3_Volt>35)||(VCC3_Volt<31))
             	{
                      SetBit(Hardware_State1,4);  //0正常 1故障
                      SetBit(Hardware_State1,0);  //0正常 1故障  bit0 ADC      0正常 1故障
             	}
             else  
             	{
			 ResetBit(Hardware_State1,4);  //0正常 1故障
			 ResetBit(Hardware_State1,0);  //0正常 1故障  bit0 ADC      0正常 1故障
             	}
             if((VCC5_Volt>52)||(VCC5_Volt<48))
                   SetBit(Hardware_State1,5);  //0正常 1故障
             else  ResetBit(Hardware_State1,5);  //0正常 1故障

	      if((OVCC3_Volt>35)||(OVCC3_Volt<31))
                   SetBit(Hardware_State1,6);  //0正常 1故障
             else  ResetBit(Hardware_State1,6);  //0正常 1故障
             if((OVCC5_Volt>52)||(OVCC5_Volt<48))
                   SetBit(Hardware_State1,7);  //0正常 1故障
             else  ResetBit(Hardware_State1,7);  //0正常 1故障		
               
		
     } 

     

	 
     

}


