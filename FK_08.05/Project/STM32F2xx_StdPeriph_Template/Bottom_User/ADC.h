
/*
内部
ADC1        ADC3ConvertedValue[0]
ADC2        ADC3ConvertedValue[1]   
ADC3        ADC3ConvertedValue[2]        VCC3      比例尺VCC3 = (ADC3ConvertedValue[2]/4096)*33*(100/49.9)
ADC4        ADC3ConvertedValue[3]        VCC5      比例尺VCC5 = (ADC3ConvertedValue[3]/4096)*33*(100/49.9)

外部通过MAX306EU和ADC1扩展16路AIN,
其中前10路外接，后6路板上电压监控
AIN1          AinData[0]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN2          AinData[1]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN3          AinData[2]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN4          AinData[3]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN5          AinData[4]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN6          AinData[5]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN7          AinData[6]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN8          AinData[7]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN9          AinData[8]                比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN10          AinData[9]              比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN11          AinData[10]      OVCC3           比例尺VCC3 =  (AinData[10]/4096)*33*(2)
AIN12          AinData[11]      OVCC5            比例尺VCC3 =  (AinData[11]/4096)*33*(2)
AIN13          AinData[12]      OAGND            比例尺VCC3 =  (AinData[12]/4096)*33*(2)
AIN14          AinData[13]                            比例尺VCC3 =  (AinData[13]/4096)*33*(2)
AIN15          AinData[14]      OAVCC12+     比例尺OAVCC12+  = (AinData[14]/4096)*33*(2*63.4/10.2)
AIN16          AinData[15]      MVCC             比例尺OAVCC12+  = (AinData[15]/4096)*33*(2*63.4/10.2)


*/
extern void AD_Convert(void);





