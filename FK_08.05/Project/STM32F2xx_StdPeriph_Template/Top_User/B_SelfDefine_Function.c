/*========================================================================================*
 * FILE:                     	SelfDefine_Function.c                   
 *========================================================================================*
 *
 * COPYRIGHT 2008-2015 BY 513 教研室
 *
 *========================================================================================*
 *
 * 名称:  一些功能性函数
 *
 * 描述: 	
 *			
 *
 *				
 *
 *----------------------------------------------------------------------------------------*
 *          
 * HISTORY:   
 *
 *   Date    By     Comments
 * --------  -----  ------------------------------------------------------------
 * 2015/03/26  聂春雨	Created.
 *========================================================================================*/ 

/*------------------------------------------------------------------------------*
 *								头文件
 #include "Modelname.h"
 *------------------------------------------------------------------------------*/
 #include "B_SelfDefine_Function.h"

 
/*------------------------------------------------------------------------------*
 *								变量定义
 DEF_UINT8 Modelname=0;	
 *------------------------------------------------------------------------------*/
 
 
/*------------------------------------------------------------------------------*
 *								任务函数
void Modelname()
 *------------------------------------------------------------------------------*/






/*-------------------------------校验函数----------------------------------*/


/* 校验和----输出为单字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT8 AddSum1(DEF_UINT8 *start , DEF_UINT8 count)
 	{
 	DEF_UINT8 addsum1=0;
	DEF_UINT8 ifor_addsum1=0;

	for(ifor_addsum1=0;ifor_addsum1<count;ifor_addsum1++)
		{
		addsum1=addsum1+start[ifor_addsum1];
		}

	return addsum1;
	
 	}


/* 校验和----输出为双字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT16 AddSum2(DEF_UINT8 *start , DEF_UINT8 count)
 	{
 	DEF_UINT16 addsum2=0;
	DEF_UINT8 ifor_addsum2=0;

	for(ifor_addsum2=0;ifor_addsum2<count;ifor_addsum2++)
		{
		addsum2=addsum2+start[ifor_addsum2];
		}

	return addsum2;
	
 	}



/* CRC 校验----输出为双字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT16 modbus_crc16(DEF_UINT8 *message,int crc_length)
{
	short crc_i,crc_j;
	unsigned short crc_reg=0xffff;
	for(crc_i=0;crc_i<crc_length;crc_i++)
	{
		crc_reg=crc_reg^*(message+crc_i);
		for(crc_j=0;crc_j<8;crc_j++)
		{
			if(crc_reg&0x0001)
			{
				crc_reg=crc_reg>>1;
				crc_reg=crc_reg&0x7FFF;
				crc_reg=crc_reg^0xA001;
			}
			else
			{
				crc_reg=crc_reg>>1;
				crc_reg=crc_reg&0x7FFF;
			}
		}
	}
	return crc_reg;
}




#define CRC32_POLYNOMIAL   0xEDB88320L

/* --------------------------------------------------------------------------
Calculate a CRC value to be used by CRC calculation functions. 
-------------------------------------------------------------------------- */
unsigned long CRC32Value(int i)
{
   int j;
   unsigned long ulCRC;
ulCRC = i;
   for ( j = 8 ; j > 0; j-- )
   {
      if ( ulCRC & 1 )
         ulCRC = ( ulCRC >> 1 ) ^ CRC32_POLYNOMIAL;
      else
         ulCRC >>= 1;
   }
   return ulCRC;
}
/* --------------------------------------------------------------------------
Calculates the CRC-32 of a block of data all at once
-------------------------------------------------------------------------- */
/* CRC 校验----输出为四字节,输入为  (首个字节地址,字节个数)    */

unsigned long CalculateBlockCRC32(DEF_UINT8 *ucBuffer, DEF_UINT32 ulCount)     /* Data block */ /* Number of bytes in the data block */   
{
   unsigned long ulTemp1;
   unsigned long ulTemp2;
   unsigned long ulCRC = 0;
while ( ulCount-- != 0 )
   {
      ulTemp1 = ( ulCRC >> 8 ) & 0x00FFFFFFL;
      ulTemp2 = CRC32Value( ((int) ulCRC ^ *ucBuffer++ ) & 0xff );
      ulCRC = ulTemp1 ^ ulTemp2;
   }
   return( ulCRC );
}











/*-------------------------------置位、验位函数----------------------------------*/




/* 置位----输出为单字节置位结果, 输入为( 要置位字节，置位位置0~7，置位值0~1 )    */
DEF_UINT8 SetByteBit(DEF_UINT8 Byte, DEF_UINT8 Position, DEF_UINT8 Value )
{
	DEF_UINT8 bit_1=0x01;

	bit_1=bit_1<<Position;	

	if(Value==0)
	{Byte=Byte&(~bit_1);		
	}

	if(Value==1)
	{Byte=Byte|bit_1;		
	}
	return Byte;
}



/* 验位----输出为单字节验位结果0x00，0x01, 输入为(要 验位字节，验位位置0~7 )    */
DEF_UINT8 TestByteBit(DEF_UINT8 Byte, DEF_UINT8 Position)
{
	DEF_UINT8 bit_1=0x01;

	bit_1=bit_1<<Position;	
	
	if((Byte&bit_1)!=0)
		{return 0x01;}
	else
		{return 0x00;}
	
}



/* 调换双字节数据高低字节----输出为双字节，输入为( 要调换的双字节数据 )*/
DEF_UINT16 ChangeWordByte(DEF_UINT16 Word)
{	
	DEF_UINT16 Byte=0;

	Byte=Word%256;

	Word=Word>>8;
	Word=Word&0x00FF;

	Word=Word+(Byte<<8);

	return Word;
}



/* 调换四字节数据高低字节----输出为四字节，输入为( 要调换的四字节数据 )*/
DEF_UINT32 Change_4_Byte(DEF_UINT32 Byte_4)
{	
	DEF_UINT8 Byte_Old[4];
	DEF_UINT8 Byte_New[4];

	bcopy(&Byte_4, &(Byte_Old[0]), 4);
	Byte_New[0]=Byte_Old[3];
	Byte_New[1]=Byte_Old[2];
	Byte_New[2]=Byte_Old[1];
	Byte_New[3]=Byte_Old[0];

	bcopy(&(Byte_New[0]), &Byte_4, 4);

	return Byte_4;
}
























 
