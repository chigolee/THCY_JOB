
#include "main.h"

U8 DI(void)  //8¬∑DI≤…ºØ
{
U8 Result = 0;
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
       
      if((GPIOH->IDR & GPIO_Pin_6))
	    SetBit(Result, 0);
      else ResetBit(Result, 0);
	  
      if((GPIOH->IDR & GPIO_Pin_7))
	    SetBit(Result, 1);
      else ResetBit(Result, 1);

      if((GPIOH->IDR & GPIO_Pin_8))
	    SetBit(Result, 2);
      else ResetBit(Result, 2);

      if((GPIOH->IDR & GPIO_Pin_9))
	    SetBit(Result, 3);
      else ResetBit(Result, 3);

      if((GPIOH->IDR & GPIO_Pin_10))
	    SetBit(Result, 4);
      else ResetBit(Result, 4);

      if((GPIOH->IDR & GPIO_Pin_11))
	    SetBit(Result, 5);
      else ResetBit(Result, 5);

     if((GPIOH->IDR & GPIO_Pin_12))
	    SetBit(Result, 6);
      else ResetBit(Result, 6);

      if((GPIOB->IDR & GPIO_Pin_14))
	    SetBit(Result, 7);
      else ResetBit(Result, 7);  

	return Result;

}
void  DO(U8 CtrlData)  //8¬∑DOøÿ÷∆ ‰≥ˆ
{
 static U8 LCtrlData = 0;

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
      if(CtrlData != LCtrlData)
      	{
            Set_DO_LE;
	}
	else Reset_DO_LE;
	  
      if(GetBit(CtrlData,0))
	    GPIOB->BSRRL = GPIO_Pin_15; //÷√∏ﬂ
      else  GPIOB->BSRRH = GPIO_Pin_15; //÷√µÕ

      if(GetBit(CtrlData,1))
	    GPIOD->BSRRL = GPIO_Pin_8; //÷√∏ﬂ
      else  GPIOD->BSRRH = GPIO_Pin_8; //÷√µÕ

      if(GetBit(CtrlData,2))
	     GPIOD->BSRRL = GPIO_Pin_9; //÷√∏ﬂ
      else  GPIOD->BSRRH = GPIO_Pin_9; //÷√µÕ

      if(GetBit(CtrlData,3))
	     GPIOD->BSRRL = GPIO_Pin_10; //÷√∏ﬂ
      else  GPIOD->BSRRH = GPIO_Pin_10; //÷√µÕ

      if(GetBit(CtrlData,4))
	     GPIOD->BSRRL = GPIO_Pin_13; //÷√∏ﬂ
      else  GPIOD->BSRRH = GPIO_Pin_13; //÷√µÕ
  
      if(GetBit(CtrlData,5))
	     GPIOH->BSRRL = GPIO_Pin_13; //÷√∏ﬂ
      else  GPIOH->BSRRH = GPIO_Pin_13; //÷√µÕ

      if(GetBit(CtrlData,6))
	     GPIOH->BSRRL = GPIO_Pin_14; //÷√∏ﬂ
      else  GPIOH->BSRRH = GPIO_Pin_14; //÷√µÕ  
	  
      if(GetBit(CtrlData,7))
	     GPIOH->BSRRL = GPIO_Pin_15; //÷√∏ﬂ
      else  GPIOH->BSRRH = GPIO_Pin_15; //÷√µÕ
	
	LCtrlData = CtrlData;

}

 
