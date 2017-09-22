#include "main.h"
#include "Configuration.h"

CanRxMsg RxMessage;
CanTxMsg TxMessage;

CanTxMsg  Can1TxFBuf[Can1_TxF_BufLen];          //�巢�ͻ�����
 U8  Can1TxFBufPi = 0;                                       //�巢�ͻ���������ָ��
 U8  Can1TxFBufPo = 0;                                      //�巢�ͻ��������ָ��

 CanRxMsg  Can1RxFBuf[Can1_RxF_BufLen];         //����ջ�����
 U8  Can1RxFBufPi = 0;                                       //����ջ���������ָ��
 U8  Can1RxFBufPo = 0;                                       //����ջ���������ָ��

 CanTxMsg  Can2TxFBuf[Can2_TxF_BufLen];          //�巢�ͻ�����
 U8  Can2TxFBufPi = 0;                                       //�巢�ͻ���������ָ��
 U8  Can2TxFBufPo = 0;                                      //�巢�ͻ��������ָ��

 CanRxMsg  Can2RxFBuf[Can2_RxF_BufLen];         //����ջ�����
 U8  Can2RxFBufPi = 0;                                       //����ջ���������ָ��
 U8  Can2RxFBufPo = 0;                                       //����ջ���������ָ��



//U8	CAN_count_Select[5]={0,0,0,0,0};

void CAN1_RX0_IRQHandler(void)
{  

      if(CAN_GetITStatus(CAN1, CAN_IT_FMP0) != RESET)
	{
              while(CAN_MessagePending(CAN1, CAN_FIFO0))//����fifo�Ƿ�������(����3��)
		{
			CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);	
		       if(IsSystemTest == TRUE)
		      {
		           //ϵͳ����
		           TxMessage.StdId = RxMessage.StdId;
			    TxMessage.ExtId = RxMessage.ExtId;
			    TxMessage.RTR = RxMessage.RTR;
			    TxMessage.IDE = RxMessage.IDE;
			    TxMessage.DLC = RxMessage.DLC;//����֡����			   
			    memcpy(&(TxMessage.Data[0]), &(RxMessage.Data[0]),  8); 
                         CAN_Transmit(CAN1, &TxMessage);//can���� 		
		      }
			else
			{
			//ѡ��Ƶ
			switch(RxMessage.StdId)
				{				
//				case 0x316:{CAN_count_Select[0]=(CAN_count_Select[0]+1)%5; if(CAN_count_Select[0]==0){memcpy(&(Can1RxFBuf[Can1RxFBufPi]), &RxMessage, sizeof(CanRxMsg));Can1RxFBufPi=(Can1RxFBufPi+1)%Can1_RxF_BufLen;}	break;}

				default:{memcpy(&(Can1RxFBuf[Can1RxFBufPi]), &RxMessage, sizeof(CanRxMsg));	Can1RxFBufPi=(Can1RxFBufPi+1)%Can1_RxF_BufLen;	break;}

				}
	
			}
						
		}		
	       CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);		
	}
}

void CAN2_RX0_IRQHandler(void)
{
       //CAN_Transmit(CAN2, &TxMessage);//can���� 		
       if(CAN_GetITStatus(CAN2, CAN_IT_FMP0) != RESET)
	{
            	
              while(CAN_MessagePending(CAN2, CAN_FIFO0))//����fifo�Ƿ�������(����3��)
		{
			CAN_Receive(CAN2, CAN_FIFO0, &RxMessage);	

		      if(IsSystemTest == TRUE)
		      {
		           //ϵͳ����
		           TxMessage.StdId = RxMessage.StdId;
			    TxMessage.ExtId = RxMessage.ExtId;
			    TxMessage.RTR = RxMessage.RTR;
			    TxMessage.IDE = RxMessage.IDE;
			    TxMessage.DLC = RxMessage.DLC;//����֡����			   
			    memcpy(&(TxMessage.Data[0]), &(RxMessage.Data[0]),  8); 
                         CAN_Transmit(CAN2, &TxMessage);//can���� 		
		      }
		      else
		      {
                           memcpy(&(Can2RxFBuf[Can2RxFBufPi]), &RxMessage, sizeof(CanRxMsg));  //ע�� ������    
                            Can2RxFBufPi=(Can2RxFBufPi+1)%Can2_RxF_BufLen;  //ָ����λ
			}		
							
		}		
	       CAN_ClearITPendingBit(CAN2, CAN_IT_FMP0);		
	}
}


void Can1InTxFBuf(CanTxMsg* p)     //��������CAN֡ѹ�뻺����
{
       memcpy(&(Can1TxFBuf[Can1TxFBufPi]), p, sizeof(CanTxMsg));  //ע�� ������    
       Can1TxFBufPi=(Can1TxFBufPi+1)%Can1_TxF_BufLen;  //ָ����λ
}

void Can1OutTxFBuf(void)
{

      if(Can1TxFBufPo != Can1TxFBufPi) //Э���建��������
	{	    	 
		CAN_Transmit(CAN1, &(Can1TxFBuf[Can1TxFBufPo]));//can���� 		
		Can1TxFBufPo=(Can1TxFBufPo+1)%Can1_TxF_BufLen;  //ָ����λ  	
	}
}	

void Can2InTxFBuf(CanTxMsg* p)     //��������CAN֡ѹ�뻺����
{
       memcpy(&(Can2TxFBuf[Can2TxFBufPi]), p, sizeof(CanTxMsg));  //ע�� ������    
       Can2TxFBufPi=(Can2TxFBufPi+1)%Can2_TxF_BufLen;  //ָ����λ
}

void Can2OutTxFBuf(void)
{

      if(Can2TxFBufPo != Can2TxFBufPi) //Э���建��������
	{	    	 
		CAN_Transmit(CAN2, &(Can2TxFBuf[Can2TxFBufPo]));//can���� 		
		Can2TxFBufPo=(Can2TxFBufPo+1)%Can2_TxF_BufLen;  //ָ����λ  	
	}
}	



