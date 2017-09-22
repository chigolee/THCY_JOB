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


extern int Record(void);  //�������ݼ�¼
extern int Download(void); //������������



#define  PAGE_MAX_Frame_SIZE  8   //��ҳ�洢֡��
#define  PAGE_USE_SIZE  (PAGE_MAX_Frame_SIZE*RecordF_Len)   //��ҳʵ�ÿռ�  8*450 = 3600


//K9WBG08U1M ʵ��BLOCKsԼ16064~16384�������Լ�¼Լ1600������
//K9WAG08U1M ʵ��BLOCKsԼ16064~16384�������Լ�¼800������



 //���� BLOCKɨ�蹦��
extern uint8 NandFlash_Scan(void); //NandFlash ɨ�裬���ֹ��ϵ�BLOCK
//2048*8 = 16384;
#define   NandErrByte_LEN     2048  //�����ֳ���  
//NandFlash ����Block��¼��
extern U8  NandErrByte[2*NandErrByte_LEN+2];    //0 ����  1 ������      NandFlash1



extern U16  NandErrCn1;               // ����Block������     NandFlash1
extern U16  NandErrCn2;               // ����Block������     NandFlash2


extern uint8 SaveNandErrByte( void );
extern uint8 ReadNandErrByte( void );

#define NandErrByte_ADDR     27000   //NandFlash ����Block��¼�� �洢��ַ

/*K9WAG08U1M 8 zones of 2048 block */
/*K9WBG08U1M 8 zones of 2048 block */









void Task_PeriodDataSave();
void Task_PeriodDataReadOut();


void	Date_Sore_GPSTime(DEF_UINT8 *p, DEF_UINT16 Length);








#endif 




