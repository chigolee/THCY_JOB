#include "main.h"

u8 Is_WDG= FALSE; //看门狗标志
u8 Is_DIO= FALSE; //DIO标示
U8 Is_ADC = FALSE;  //ADC转换标志
U8 Is_ExUsartSend = FALSE;  //外部扩展串口发送
U8 Is_CAN1Send = FALSE;  //CAN数据帧发送标志
U8 Is_CAN2Send = FALSE;  //CAN数据帧发送标志
U8 Is_TmpCtrl = FALSE;  //温度控制标志

U8 Is_FCS= FALSE;  //飞行控制标志
u8 IsTest = FALSE; ////测试标示
U32 rstdly =0;                //启动延时计数
u8 TestData1; ////测试数据
u8 TestData2; ////测试数据
u8 TestData3; ////测试数据
u8 TestData4; ////测试数据
u8 TestData5; ////测试数据
u8 TestData6; ////测试数据



U16 VCC3_Volt = 0;   //内部3.3V电压
U16 VCC5_Volt = 0;   //内部5V电压
U16 OAGND_Volt = 0; //外部模拟地V电压
U16 OVCC3_Volt = 0; //外部3.3V电压
U16 OVCC5_Volt = 0; //外部5V电压
U16 MVCC_Volt = 0;  //供电电源电压
U16 OAVCC12_Volt = 0; //外部模拟12V电源电压


