
/*
�ڲ�
ADC1        ADC3ConvertedValue[0]
ADC2        ADC3ConvertedValue[1]   
ADC3        ADC3ConvertedValue[2]        VCC3      ������VCC3 = (ADC3ConvertedValue[2]/4096)*33*(100/49.9)
ADC4        ADC3ConvertedValue[3]        VCC5      ������VCC5 = (ADC3ConvertedValue[3]/4096)*33*(100/49.9)

�ⲿͨ��MAX306EU��ADC1��չ16·AIN,
����ǰ10·��ӣ���6·���ϵ�ѹ���
AIN1          AinData[0]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN2          AinData[1]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN3          AinData[2]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN4          AinData[3]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN5          AinData[4]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN6          AinData[5]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN7          AinData[6]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN8          AinData[7]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN9          AinData[8]                ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN10          AinData[9]              ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN11          AinData[10]      OVCC3           ������VCC3 =  (AinData[10]/4096)*33*(2)
AIN12          AinData[11]      OVCC5            ������VCC3 =  (AinData[11]/4096)*33*(2)
AIN13          AinData[12]      OAGND            ������VCC3 =  (AinData[12]/4096)*33*(2)
AIN14          AinData[13]                            ������VCC3 =  (AinData[13]/4096)*33*(2)
AIN15          AinData[14]      OAVCC12+     ������OAVCC12+  = (AinData[14]/4096)*33*(2*63.4/10.2)
AIN16          AinData[15]      MVCC             ������OAVCC12+  = (AinData[15]/4096)*33*(2*63.4/10.2)


*/
extern void AD_Convert(void);





