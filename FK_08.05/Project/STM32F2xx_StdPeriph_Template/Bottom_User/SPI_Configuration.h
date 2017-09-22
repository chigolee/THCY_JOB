/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/



#ifndef _SPI_Configuration_H
#define _SPI_Configuration_H



void SPI1_Configuration(void);
u8 SPI1_SendByte(u8);
void SPI2_Configuration(void);
u8 SPI2_SendByte(u8);
void SPI3_Configuration(void);
u8 SPI3_SendByte(u8 byte); //16bit

#endif /* __SPI2_Configuration_H */
