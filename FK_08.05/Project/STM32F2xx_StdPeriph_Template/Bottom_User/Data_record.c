


#include "K9WBG08U1M.h"
#include "main.h"





DEF_UINT8	iForYCSaveSelect=0;
DEF_UINT8	YC_Save_Trans[Max_YCBtCount+3];
/*------------�������ݴ洢���񣬿�֡��֡˳������洢-------------*/
void Task_PeriodDataSave()
{
	iForYCSaveSelect=(iForYCSaveSelect+1)%(YC_DATA_COUNT+YC_DATA_COUNTLow);

	if(iForYCSaveSelect<YC_DATA_COUNT)
		{/*---�洢��֡----*/

		P_ForYCPackge=(DEF_UINT8*)(&All_YCFast_Package);

		YC_Save_Trans[0]=0xEE;
		YC_Save_Trans[1]=0xCC;
		YC_Save_Trans[2]=g_YC_Date_Length[iForYCSaveSelect];
		bcopy(&(P_ForYCPackge[(YC_Date_StepBegain[iForYCSaveSelect])]),&(YC_Save_Trans[3]),YC_Save_Trans[2]);		
		}

	else
		{/*---�洢��֡----*/
		P_ForYCPackge=(DEF_UINT8*)(&All_YCLowPack);

		YC_Save_Trans[0]=0xEE;
		YC_Save_Trans[1]=0xCC;
		YC_Save_Trans[2]=g_YCLow_Date_Length[iForYCSaveSelect-YC_DATA_COUNT];
		bcopy(&(P_ForYCPackge[(YC_Date_StepBegain_Low[iForYCSaveSelect-YC_DATA_COUNT])]),&(YC_Save_Trans[3]),YC_Save_Trans[2]);		
		}
	YC_Save_Trans[(YC_Save_Trans[2]+2)]=AddSum1(&(YC_Save_Trans[3]),(YC_Save_Trans[2]-1));
	Date_Sore_GPSTime(&(YC_Save_Trans[0]),(YC_Save_Trans[2]+3));
}











DEF_UINT32	iForReadSaveData=0;	//��������֡����, 1Сʱ��Ŵ洢36000֡�������ݣ�ÿ40ms/֡�ٶȵ���1Сʱ���ݴ����Ҫ��Сʱ��
/*----��ȡ�Ѿ��洢�����ݣ���ʱ�Ӵ���6�����������������ڿ���Ϊ10ms������6�����ʿ���Ϊ115200bps----*/
void Task_PeriodDataReadOut()
{
	if(iForReadSaveData>0)
		{
		Download();
		U6InTxBuf(&(DownLoadData[0]), (RecordF_Len/2));
		U6InTxBuf(&(DownLoadData[(RecordF_Len/2)]), (RecordF_Len/2));
		
		iForReadSaveData=iForReadSaveData-1;
		}
}	





DEF_UINT8	Count_RecordData;		//���ݴ洢ѭ������
DEF_UINT16	SystemTime_Record;		//���ݴ洢��ϵͳʱ�䣬��λ1s
DEF_UINT32	GPSTime_Record;		//���ݴ洢��ϵͳʱ�䣬��λ0.1s
DEF_UINT8	ifor_Setzero_RecordData;

/*---------���ݴ洢��������ǰ��GPSʱ��:  1~2ʱ���ܣ�     3~4~5��ǰʱ�䵥λ0.1�룬���ֽ�����        6ѭ��������        7~8ϵͳʱ��(��λs)--------*/
/*---------�������: 1-���洢���ݵ�ַ��2-���ݸ���		---------------*/
void	Date_Sore_GPSTime(DEF_UINT8 *p, DEF_UINT16 Length)
{
/*-----------------------*/

if(g_YC_Package.HD01.CompuRecState==0x01)
	{
	if(Length>(RecordF_Len-10))
		{
		Length=RecordF_Len-10;
		}

	bcopy((DEF_UINT8*)&(g_YC_Package.HD01.INS_GPS_week), (DEF_UINT8*)&(RecordData[0]), 2);

	GPSTime_Record=g_YC_Package.HD01.INS_GPS_millisecond/100.0;
	bcopy((DEF_UINT8*)&(GPSTime_Record), (DEF_UINT8*)&(RecordData[2]), 3);
	RecordData[5]=Count_RecordData++;


	SystemTime_Record=(DEF_UINT16)(SystemTime/100);
	bcopy(&SystemTime_Record, &(RecordData[6]), 2);

	for(ifor_Setzero_RecordData=(Length+8);ifor_Setzero_RecordData<RecordF_Len;ifor_Setzero_RecordData++)
		{RecordData[ifor_Setzero_RecordData]=0xAA;}

	bcopy(p, &(RecordData[8]), Length);

	Record();
	
	}


}





U8 WriteData[NAND_PAGE_SIZE]={0};
U8 ReadData[NAND_PAGE_SIZE]={0};




//���� BLOCKɨ�蹦��
//NandFlash ����Block��¼��
 U8  NandErrByte[2*NandErrByte_LEN+2] = {0};      //0 ����  1 ������NandFlash1
 


 U16  NandErrCn1 = 0;               // ����Block������
 U16  NandErrCn2 = 0;               // ����Block������

/*K9WAG08U1M 8 zones of 2048 block */
/*K9WBG08U1M 8 zones of 2048 block */
 
//�������غ�����
//K9WBG08U1M ʵ��BLOCKsԼ16064~16384��
//8 zones*2048 Block per zone*64 pages per block*4096Bytes  page = 4G Bytes
// 2Ƭ K9WBG08U1M ����8GB
//��1s��¼1֡��ÿҳ��¼8֡����ɼ�¼ʱ��Ϊ194��

//K9WAG08U1M��K9WBG08U1M��ʵ�ʵ�ҳ��С��һ����K9WAG08U1MΪ2k��K9WBG08U1MΪ4k



int  Record(void)
{
   static U16 Offset=0;   //ҳ��ƫ���� 
   static NAND_ADDRESS tRecordAddr;   
   
   U16 TempByte=0;
   U16 TempBit=0;      

   U32 TempU32=0;
   static U32 LCurrent_RecordBlock =777777;    // ��Current_RecordBlock����
   U32 tCurrent_RecordBlock =0;
   static U8 NandNum = 2;
  

          if(Current_RecordBlock>= (2*NAND_MAX_ZONE*NAND_ZONE_SIZE))
          {
                //�����洢�ռ�
                return FALSE;     
          }
	   if((GetBit(Hardware_State1, 2) != 0)&&(Current_RecordBlock< (NAND_MAX_ZONE*NAND_ZONE_SIZE)))
	   {
	        //nandflash1 ���ϣ�ֱ�Ӵ�nandflash2��ʼ�洢
               Current_RecordBlock =  (NAND_MAX_ZONE*NAND_ZONE_SIZE); 
	   }
	   if((GetBit(Hardware_State1, 3) != 0)&&(Current_RecordBlock>= (NAND_MAX_ZONE*NAND_ZONE_SIZE)))
	   {
	        //nandflash2 �������Ѿ���¼��������ֱ���˳�
               return FALSE;  
	   }

          
		  
          if(Current_RecordBlock != LCurrent_RecordBlock)
          {
                 TempBit = Current_RecordBlock%8;
		   TempByte = Current_RecordBlock/8;
		   while(GetBit(NandErrByte[TempByte], TempBit) != 0)
		   {
                       Current_RecordBlock++;
			  if(Current_RecordBlock >= (2*NAND_MAX_ZONE*NAND_ZONE_SIZE))
			  {
                              return FALSE;     
			  }
			  else
			  {
	                       TempBit = Current_RecordBlock%8;
			         TempByte = Current_RecordBlock/8;	
			  }			  
		   }              
			
                 //ÿ�����濪ʼʱ����������״̬����
                 if(Current_RecordBlock>= (NAND_MAX_ZONE*NAND_ZONE_SIZE))
                 {                        
			   Select_NAND1;
			   tCurrent_RecordBlock = Current_RecordBlock -(NAND_MAX_ZONE*NAND_ZONE_SIZE);
			   NandNum = 3;			   
		   }
		   else
		   { 
		          Select_NAND0;
			   tCurrent_RecordBlock = Current_RecordBlock;
			   NandNum = 2;			  
		   }
		   
		   tRecordAddr.Zone=tCurrent_RecordBlock/NAND_ZONE_SIZE;
	          tRecordAddr.Block = tCurrent_RecordBlock%NAND_ZONE_SIZE;  
	          tRecordAddr.Page=0;		
		   TempU32 = NAND_EraseBlock(tRecordAddr); 
		   if(TempU32 != NAND_READY)
		   {
		          
		          SetBit(Hardware_State1, NandNum);     //����    //bit3  Nand Flash2
		          return FALSE;
		   }
		   
		  LCurrent_RecordBlock = Current_RecordBlock;
                 //�����¼����λ�ÿ�ʼ
		  Offset = 0;	
          }
	              
	   memcpy( &WriteData[Offset],RecordData, RecordF_Len); 
          Offset += RecordF_Len;	
				 
          if(Offset >= PAGE_USE_SIZE)
          {          
                 //����1ҳ                 
                TempU32 = NAND_WriteSmallPage(WriteData, &tRecordAddr, 1);
		   if((TempU32&0x000004FF) != 0x00000040)
		   {
		          //״̬������		  ��������ַ������       
                        SetBit(Hardware_State1, NandNum);     //����    //bit3  Nand Flash2	                        
	          }		   
		   if(NandNum == 2)  //nand1
		        Current_RecordBlock = tRecordAddr.Block + tRecordAddr.Zone*NAND_ZONE_SIZE;  	
		   else  //nand2
		   	Current_RecordBlock = (NAND_MAX_ZONE*NAND_ZONE_SIZE) + tRecordAddr.Block + tRecordAddr.Zone*NAND_ZONE_SIZE;  
		
		   Offset = 0;  		   
	   } 
     
     return TRUE;     
}

int Download(void)
{
   static U16 Offset=0;

   static U8 NewPageFlag=TRUE;


   U32 TempU32 =0;
   U16 TempByte=0;
   U16 TempBit=0;      

   static NAND_ADDRESS tDownAddr;   

   static U32 LCurrent_DownloadBlock = 777777;    // ��Current_DownloadBlock����
   U32 tCurrent_DownloadBlock =0;
   static U8 NandNum = 2;
  

          if(Current_DownloadBlock>= (2*NAND_MAX_ZONE*NAND_ZONE_SIZE))
          {
                //�����洢�ռ�
                return FALSE;     
          }
         if((GetBit(Hardware_State1, 2) != 0)&&(Current_DownloadBlock< (NAND_MAX_ZONE*NAND_ZONE_SIZE)))
	   {
	        //nandflash1 ���ϣ�ֱ�Ӵ�nandflash2��ʼ�洢
               Current_DownloadBlock =  (NAND_MAX_ZONE*NAND_ZONE_SIZE); 
	   }
	   if((GetBit(Hardware_State1, 3) != 0)&&(Current_DownloadBlock>= (NAND_MAX_ZONE*NAND_ZONE_SIZE)))
	   {
	        //nandflash2 �������Ѿ���¼��������ֱ���˳�
               return FALSE;  
	   }	   

	   if(Current_DownloadBlock != LCurrent_DownloadBlock)
          {
                 TempBit = Current_DownloadBlock%8;
		   TempByte = Current_DownloadBlock/8;
		   while(GetBit(NandErrByte[TempByte], TempBit) != 0)
		   {
                       Current_DownloadBlock++;
			  if(Current_DownloadBlock >= (2*NAND_MAX_ZONE*NAND_ZONE_SIZE))
			  {
                              return FALSE;     
			  }
			  else
			  {
	                       TempBit = Current_DownloadBlock%8;
			         TempByte = Current_DownloadBlock/8;	
			  }			  
		   }              
			
                 //ÿ�����濪ʼʱ����������״̬����
                 if(Current_DownloadBlock>= (NAND_MAX_ZONE*NAND_ZONE_SIZE))
                 {                        
			   Select_NAND1;
			   tCurrent_DownloadBlock = Current_DownloadBlock -(NAND_MAX_ZONE*NAND_ZONE_SIZE);
			   NandNum = 3;			   
		   }
		   else
		   { 
		          Select_NAND0;
			   tCurrent_DownloadBlock = Current_DownloadBlock;
			   NandNum = 2;			  
		   }
		   
		   tDownAddr.Zone=tCurrent_DownloadBlock/NAND_ZONE_SIZE;
	          tDownAddr.Block = tCurrent_DownloadBlock%NAND_ZONE_SIZE;  
	          tDownAddr.Page=0;
			  
		  LCurrent_DownloadBlock = Current_DownloadBlock;
                 //�����¼����λ�ÿ�ʼ
		  Offset = 0;		
		  NewPageFlag=TRUE;
          }

          if(NewPageFlag == TRUE)
          {
	          TempU32 = NAND_ReadSmallPage(ReadData, &tDownAddr, 1);   
	          if((TempU32&0x000004FF) != 0x00000040)
	          {
	                //״̬������  ��������ַ������
	                SetBit(Hardware_State1, NandNum);     //����    //bit3  Nand Flash2		   
	          }	
		   Offset = 0;
		   NewPageFlag=FALSE;
          }

           memcpy(DownLoadData, &ReadData[Offset],  RecordF_Len);  //ע�� ������	    
           Offset += RecordF_Len;	
			
	    if(Offset >= PAGE_USE_SIZE)
	    {
	      	 //��ҳ	         
		   Offset = 0;
		   NewPageFlag=TRUE;
		   
		   if(NandNum == 2)  //nand1
		        Current_DownloadBlock = tDownAddr.Block + tDownAddr.Zone*NAND_ZONE_SIZE;  	
		   else  //nand2
		   	Current_DownloadBlock = (NAND_MAX_ZONE*NAND_ZONE_SIZE) + tDownAddr.Block + tDownAddr.Zone*NAND_ZONE_SIZE; 
		   
	    }
			
       return TRUE;    
}


//Page Random Read : 25��s(Max.
//Page Program time : 200��s(Typ.)
// Block Erase Time : 1.5ms(Typ.
//ɨ�貽��
//����Block
//��ҳд��ָ������
//��ҳ��ȡ����д�����ݱȶԣ�
//ÿ�β������1��Block
//0.225*64 +1.5 = 15.9ms  

//

uint8 NandFlash_Scan(void) //NandFlash ɨ�裬���ֹ��ϵ�BLOCK
{
//U16 i=0;
//U16 j=0;
   U32 TempU32=0;
   U16 TempByte=0;
   U16 TempBit=0;
   char str[2] = {"%"};

   U8 ScanFlag = TRUE;

   static NAND_ADDRESS ScanAddr;
     
     TempByte = ScanAddr.Block + ScanAddr.Zone*NAND_ZONE_SIZE;         
     TempBit = TempByte%8;
     TempByte = TempByte/8;
     if(TempByte>=(NandErrByte_LEN))
	   TempByte = (NandErrByte_LEN-1);	 
    	
    if(GetBit(Hardware_State1, 2) == 0)
    {
             //��ʼ������    	 
          Select_NAND0;	   
          ResetBit(NandErrByte[TempByte], TempBit);  //Ĭ������
          TempU32 = NAND_EraseBlock(ScanAddr); 
	   if((TempU32&0x000004FF) != NAND_READY)
	   {   
                  //��ǹ���block                
                  SetBit(NandErrByte[TempByte], TempBit);
		    NandErrCn1++;
	   }	   
      }
    
     if(GetBit(Hardware_State1, 3) == 0)
     {
             //��ʼ������
            
          Select_NAND1;	 
	   ResetBit(NandErrByte[TempByte+NandErrByte_LEN], TempBit);  //Ĭ������
          TempU32 = NAND_EraseBlock(ScanAddr); 	
	   if((TempU32&0x000004FF) != NAND_READY)
	   {     
                  //��ǹ���block                
                  SetBit(NandErrByte[TempByte+NandErrByte_LEN], TempBit);
		    NandErrCn2++;
	   }
      }

	
     if((GetBit(Hardware_State1, 2) == 1)&&(GetBit(Hardware_State1, 3) == 1))
     {
           //bit2  Nand Flash1
	    //bit3  Nand Flash2     
	    //Nand Flash1��Nand Flash2������
           ScanFlag = FALSE;
     }

    if(GetBit(NandErrByte[TempByte], TempBit))
    {
        //��Block�й���
        USART1_Printf("Nand Flash1 Err BLock:%d, Sum:%d\n", TempByte*8+TempBit, NandErrCn1);   
    }
    if(GetBit(NandErrByte[TempByte+NandErrByte_LEN], TempBit))
    {
        //��Block�й���
        USART1_Printf("Nand Flash2 Err BLock:%d, Sum:%d\n", TempByte*8+TempBit, NandErrCn2);   
    }
    if(TempBit == 0)
    {
        //8��blocks�ش�һ�½���
        USART1_Printf("Scanned:%.2f%s\n", 100.0*((F32)(TempByte*8+TempBit)/(NAND_ZONE_SIZE*NAND_MAX_ZONE)),str);   
    }	

   //��ַ����
   ScanAddr.Block++;
   if(ScanAddr.Block >= NAND_ZONE_SIZE)
    {
            ScanAddr.Block = 0;
            ScanAddr.Zone++;

	      if(ScanAddr.Zone >= NAND_MAX_ZONE)
	      {
	             ScanFlag = FALSE;
	      }
    }

    if(ScanFlag == FALSE)
    {
           //�洢����block��¼��
           SaveNandErrByte();
	    USART1_Printf("NandFlash Scan End!\n");   
	    USART1_Printf("NandFlash1 Err BLocks Sum:%d\n", NandErrCn1);   
	    USART1_Printf("NandFlash2 Err BLocks Sum:%d\n", NandErrCn2);   
    }

    return(ScanFlag);

}

uint8 SaveNandErrByte( void )
{

      NandErrByte[2*NandErrByte_LEN] = 0x5A;
      NandErrByte[2*NandErrByte_LEN+1] = 0xA5;  
      SRAM_WriteBuffer((uint8_t*)NandErrByte, NandErrByte_ADDR, 2*NandErrByte_LEN+2);
      //SRAM_ReadBuffer((uint8_t*)NandErrByte, NandErrByte_ADDR, 2*NandErrByte_LEN);
      return TRUE;

}

uint8 ReadNandErrByte( void )
{
 U8 Chk[2] = {0};

      SRAM_ReadBuffer((uint8_t*)Chk, NandErrByte_ADDR+2*NandErrByte_LEN, 2); 
      if((Chk[0] == 0x5A)&&(Chk[1] == 0xA5))      
     {
           SRAM_ReadBuffer((uint8_t*)NandErrByte, NandErrByte_ADDR, 2*NandErrByte_LEN); 
	    return TRUE;
     }
     else  return FALSE;
}




























