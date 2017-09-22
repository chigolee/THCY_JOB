/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/
//#ifndef M_Modelname_H
//#define M_Modelname_H
//#endif 




#ifndef M_Data_record_H
#define M_Data_record_H



#include "B_GlobalDefine.h"


extern U8 WriteData[NAND_PAGE_SIZE];
extern U8 ReadData[NAND_PAGE_SIZE];


extern int Record(void);  //飞行数据记录
extern int Download(void); //飞行数据下载



#define  PAGE_MAX_Frame_SIZE  8   //单页存储帧数
#define  PAGE_USE_SIZE  (PAGE_MAX_Frame_SIZE*RecordF_Len)   //单页实用空间  8*450 = 3600


//K9WBG08U1M 实际BLOCKs约16064~16384，最大可以记录约1600个剖面
//K9WAG08U1M 实际BLOCKs约16064~16384，最大可以记录800个剖面



 //增加 BLOCK扫描功能
extern uint8 NandFlash_Scan(void); //NandFlash 扫描，发现故障的BLOCK
//2048*8 = 16384;
#define   NandErrByte_LEN     2048  //故障字长度  
//NandFlash 故障Block记录字
extern U8  NandErrByte[2*NandErrByte_LEN+2];    //0 正常  1 不正常      NandFlash1



extern U16  NandErrCn1;               // 故障Block计数器     NandFlash1
extern U16  NandErrCn2;               // 故障Block计数器     NandFlash2


extern uint8 SaveNandErrByte( void );
extern uint8 ReadNandErrByte( void );

#define NandErrByte_ADDR     27000   //NandFlash 故障Block记录字 存储地址

/*K9WAG08U1M 8 zones of 2048 block */
/*K9WBG08U1M 8 zones of 2048 block */









void Task_PeriodDataSave();
void Task_PeriodDataReadOut();


void	Date_Sore_GPSTime(DEF_UINT8 *p, DEF_UINT16 Length);








#endif 




