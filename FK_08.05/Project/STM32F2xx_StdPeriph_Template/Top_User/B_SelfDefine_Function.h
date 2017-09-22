/*========================================================================================*
 * FILE:                     	SelfDefine_Function.h                   
 *========================================================================================*
 *
 * COPYRIGHT 2008-2015 BY 513 教研室
 *
 *========================================================================================*
 *
 * 名称:  
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
#ifndef M_SelfDefine_Function_H
#define M_SelfDefine_Function_H


/*------------------------------------------------------------------------------*
 *								头文件
#include "B_GlobalDefine.h"
 *------------------------------------------------------------------------------*/
 #include "B_GlobalDefine.h"

 /*------------------------------------------------------------------------------*
 *								宏定义
 #define Modelname   3.1415926
 *------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*
 *								结构体定义
 typedef struct  
{
	DEF_UINT16 m_Modelname;	
	
}Modelname;
 *------------------------------------------------------------------------------*/
 
/*------------------------------------------------------------------------------*
 *								变量定义
 extern DEF_UINT8 Modelname;	
 *------------------------------------------------------------------------------*/
 

 
/*------------------------------------------------------------------------------*
 *								函数声明
void Modelname();
 *------------------------------------------------------------------------------*/



/*-------------------------------校验函数----------------------------------*/

 
 /* 校验和----输出为单字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT8 AddSum1(DEF_UINT8 *start , DEF_UINT8 count);

/* 校验和----输出为双字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT16 AddSum2(DEF_UINT8 *start , DEF_UINT8 count);

/* CRC 校验----输出为双字节,输入为  (首个字节地址,字节个数)    */
DEF_UINT16 modbus_crc16(DEF_UINT8 *message,int crc_length);

unsigned long CRC32Value(int i);
unsigned long CalculateBlockCRC32(DEF_UINT8 *ucBuffer, DEF_UINT32 ulCount);     /* Data block */ /* Number of bytes in the data block */   









/*-------------------------------置位、验位函数----------------------------------*/


/* 置位----输出为单字节置位结果, 输入为( 要置位字节，置位位置0~7，置位值0~1 )    */
DEF_UINT8 SetByteBit(DEF_UINT8 Byte, DEF_UINT8 Position, DEF_UINT8 Value );

/* 验位----输出为单字节验位结果0x00，0x01, 输入为(要 验位字节，验位位置0~7 )    */
DEF_UINT8 TestByteBit(DEF_UINT8 Byte, DEF_UINT8 Position);

/* 调换双字节数据高低字节----输出为双字节，输入为( 要调换的双字节数据 )*/
DEF_UINT16 ChangeWordByte(DEF_UINT16 Word);

/* 调换四字节数据高低字节----输出为四字节，输入为( 要调换的四字节数据 )*/
DEF_UINT32 Change_4_Byte(DEF_UINT32 Byte_4);














#endif 









