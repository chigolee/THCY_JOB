#include "main.h"
#include "B_GlobalDefine.h"

//״̬���� Bottom ---> Top
 U16 AinData[16]={0};  //16ͨ��AD     AinData[0]-AIN1    AIN =  (AinData[]/4096)*33*(2) ����λ:0.1V
 U8 DIData =0; //8·DI   1bit��Ӧ1·  bit0-DI_D1

 U8 Hardware_State1 = 0;//Ӳ��״̬���ֽ�
 U8 Hardware_State2 = 0;//Ӳ��״̬���ֽ�

//Hardware_State1
//bit0 ADC      0���� 1����
//bit1 NVRAM    0���� 1����
//bit2 NandFlash1    0���� 1����
//bit3 NandFlash2    0���� 1����
//bit4 VCC3            0���� 1����
//bit5 VCC5            0���� 1����
//bit6 OVCC3          0���� 1����
//bit7 OVCC5          0���� 1����

//Hardware_State2
//bit0 CAN1      0���� 1����
//bit1 CAN2     0���� 1����
//bit2 MAX14830A    0���� 1����
//bit3 MAX14830B    0���� 1����
//bit4 MAX14830C         0���� 1����
//bit5 Tmp100                0���� 1����
//bit6 U1&U2 Switch       0:U1����,U2����     1:U2����,U1����
//bit7 ���ô���״̬   0���� 1����

 S8 InnerTmp = 0;//�ڲ��¶�   ��λ��


//��������Top  ---> Bottom
 U8 DOData = 0;//8·DO   1bit��Ӧ1· bit0-DO_C1    

 U8 ComSW_CMD = 0;//�����л�����    0:  �Զ��л�  1: Usart1  2:Usart2
 U8 TmpCtrl_CMD = 0;//�¿�����    0:  �Զ��¿�  1: ���� 2:������

//�ֳ���������
Pro_Datat  Pro_Data;
U8 ProData_Flag = FALSE;//�ֳ��������ݸ��±�־

U32 SystemTime = 0;  //ϵͳ������  ��λ10ms
U32 SystemTimems =0;  // //ϵͳ������  ��λ1ms
U8 LED2_Flag = 2;//LED2״̬����   0 �� 1 ��2����
U8 Record_Flag = 0;//�������ݼ�¼/����״̬  0   ������  1  ��¼  2���� Ĭ��0   //���ݼ�¼ Ƶ��Ϊ1Hz

U8 IsSystemTest= FALSE;  //ϵͳ���Ա�־ Ĭ��FALSE,,,,TRUE





//20150619�������ݼ�¼���
//���ݼ�¼������10Hz
//�������ز�����20Hz
U8 RecordData[RecordF_Len] = {0};  //���ݼ�¼����֡
U8 DownLoadData[RecordF_Len] = {0};  //������������֡
U32 Current_RecordBlock = 0;  //��ǰ���ڼ�¼��Block     0-32767
U32 Current_DownloadBlock = 0;  //��ǰ�������ص�Block  0-32767
U8 IsNandScanCMD = FALSE; //ɨ������





//#define USART_SW_U1     GPIOF->BSRRH = GPIO_Pin_10;  ResetBit(Hardware_State2, 6)  //�õ�   UART_SW  ѡ��RS422A_1���
//#define USART_SW_U2     GPIOF->BSRRL = GPIO_Pin_10;  SetBit(Hardware_State2, 6)   //�ø�   UART_SW  ѡ��RS422A_1���



DEF_UINT8 SignForResetTest=0;
void FCS(void)//Ԥ�������п����õĺ���
{
      //����
      //Pro_Data   ��һ������ʱ��Pro_Data���г�ʼ��
      //AinData[16]
      //DIData
      //Hardware_State1
      //Hardware_State2
      //InnerTmp
      //SystemTime
      //UxRxFBuf  //���ڽ�������
      //CAnxRxFBuf  //CAN��������
if(SignForResetTest==1)
	{
	for(SignForResetTest=0;SignForResetTest<=9;SignForResetTest++)
		{g_CountTest[SignForResetTest]=0;}



//g_YC_Package.TJ.FlightMode=0;
//TimeForCKDelay=CKDelayMaxTime-50;
//OnceSignForFastExploder=0;

	
	SignForResetTest=0;	
	
	}



/*-------����ѭ������-------*/

	
	//�趨��������,  ע��ͬһƵ�ʵ�������Է���ִ��
	g_TimeCount=g_TimeCount++;


	if(g_TimeCount%1==0)
		{Task_INSMain_Recieve();Task_INSMain_Recieve();}		/*--�ߵ�1	���ݽ���--*/

	if(g_TimeCount%2==0)	
		{Task_CJComputer_Receive();}	/*--�ɼ���������ݽ���--*/

	if(g_TimeCount%2==0)				
		{Task_UlinkCK_Reiceive();}		/*--UƵ��--ң��ָ�����--*/

	if(g_TimeCount%2==0)	
		{Task_CAN_Power_Recieve();}	/*--��Դ�豸���ݽ���--*/

	if(g_TimeCount%3==0)				
		{Task_Airscrew_Recieve(1);		/*--�ƽ����1\2\3\4\ǰ������--���ݽ���--*/
		Task_Airscrew_Recieve(2);
		Task_Airscrew_Recieve(3);
		Task_Airscrew_Recieve(4);
		Task_Airscrew_Recieve(5);}

	if(g_TimeCount%5==0)				
		{Task_LlinkCK_Reiceive();}		/*--LƵ��--ң��ָ�����--*/

	if(g_TimeCount%5==0)				
		{Task_GNSS_Recieve();}			/*--GNSS���ջ������ݽ���--*/

	if(g_TimeCount%5==0)				
		{Task_Ballonet_Operate(1);		/*--����ɼ�1\2\3\4--���ݽ���--*/
		Task_Ballonet_Operate(2);
		Task_Ballonet_Operate(3);
		Task_Ballonet_Operate(4);}

	if(g_TimeCount%10==0)	
		{Task_YCYKBack_Send();	}		/*--ң�����ݡ�ң�ػظ�����--*/
	
	 if(g_TimeCount%10==0)	
		{Task_Ulink_SendTestFram();}	/*--UƵ�β����·����֡����--*/

	 if(g_TimeCount%10==0)	
		{Task_PeriodDataSave();}		/*--����֡���ڴ洢--*/

	if(g_TimeCount%10==0)				
		{Task_Alt_Height_Recieve();}		/*--��ѹ�߶ȱ����ݽ���--*/

	if(g_TimeCount%30==0)		
		{Task_Vector_DataSend();}		/*--ʸ��װ����������--*/
	if(g_TimeCount%5==2)		
		{Task_Vector_Recieve();}		/*--ʸ��װ�����ݽ���--*/

	if(g_TimeCount%100==0)				
		{Task_CtrlLaw_Operate();}		/*--�Զ����п���--*/


	if(g_TimeCount%1==0)				
		{Task_B_001SecondDelay();}		/*--0.01����ʱ����--*/

	if(g_TimeCount%10==0)				
		{Task_B_Time100msDelay();}	/*--0.1����ʱ����--*/

	if(g_TimeCount%100==0)				
		{Task_B_TimeSecondDelay();}	/*--1����ʱ����--*/



      LED2_Flag =2;

      //�������ݼ�¼
      Record_Flag = 0;//�������ݼ�¼/����״̬  0   ������  1  ��¼  2���� Ĭ��0
}



