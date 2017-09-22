//串口接收帧结构配置
/******************************************

1--L频段测控设备
    	波特率：115200 bps
    	字符格式：1位起始位，8位数据位（无校验），1位停止位。
    	内容	EE	CC	N      ...................................	累加和

2---惯导
	 “惯导→飞控计算机” 的串口参数如下：
	RS-422接口，波特率115200bps，
	1bit开始位，8bit数据位，1bit停止位，无校验。
	对于多字节数据，低字节在前，高字节在后。
	数据格式分两种:  
	格式一
	内容	AA	44	13	(有效字节长度N)，总长=N+16
	格式二
	内容	AA	44	12	(有效字节长度N)，总长=N+32



3--采集计算机1	  通道
	波特率：115200 bps
    	字符格式：1位起始位，8位数据位（无校验），1位停止位。
    	内容	EE	CC	N      ...................................	累加和

4--U频段测控设备
	波特率：38400 bps
	字符格式：1位起始位，8位数据位（无校验），1位停止位。
	名称	帧头	数据
	字节序号	1	2	3	4	…	31	32
	内容	EB	90					字节3~31累加和

5-6-7-8---囊体采集器1主
	波特率：19200bps
	字符格式：1位起始位，8位数据位（无校验），1位停止位。
	内容	EE	CC	...............55	AA  , 总长44字节

	ASCLL码格式

9--气压高度表
	波特率:  19200 bps
	字符格式:  1位起始位，8位数据位（无校验），1位停止位。
	字节序号:      1       2      3    .......       11       12
	内容:			AA     ...     ...    .......      ....       校验和


A-- GNSS接收机
	RS-422接口，波特率9600bps，1bit开始位，8bit数据位，1bit停止位，无校验。对于多字节数据，低字节在前，高字节在后。



B-C-D-E-F-----推进电机1\2\3\4\前部风扇
    “推进电机→飞控计算机”的串口参数如下：
    波特率：19200 bps
    字符格式：1位起始位，8位数据位（无校验），1位停止位。
    字节序号	1	2	3	……	15	16
    内容	EB	90				字节1~15累加和


G--矢量装置
    “矢量装置电机→飞控计算机” 的串口参数如下：
    波特率：38400 bps
    起始位	数据位	校验位	停止位
    1	8	偶	1
    数据格式分两种，分别定义如下。
   格式一：
   名称	帧头	数据长度	数据（2N个）	字节1~(2N+3)的CRC校验
   字节序号	1	2	3	1+3	2+3	…	2N+3	2N+4	2N+5
   内容	01	03	N					低字节	高字节

   格式二：
   名称	帧头	数据（4个）	字节1~6的CRC校验
   字节序号	1	2	3	4	5	6	7	8
   内容	01	06					低字节	高字节



H--采集计算机1	  通道
	波特率：115200 bps
    	字符格式：1位起始位，8位数据位（无校验），1位停止位。
    	内容	EE	CC	N      ...................................	累加和



*******************************************/

#define  U1_DH0			0xEE	//桢头0  数据
#define  U1_DH1			0xCC	//桢头1   数据
#define  U1_Len_Plus		3		 //帧长附加值 

#define  U2_DH0_1		0xAA	//帧头0 数据
#define  U2_DH0_2		0x44	//帧头1 数据
#define  U2_D1_H1		0x13	//桢1-头1   数据
#define  U2_D2_H1		0x12	//桢2-头1   数据
#define  U2_LengPosi_1	3		//帧1长度字节位置
#define  U2_LengPosi_2	8		//帧2长度字节位置
#define  U2_Len_Plus_1	16		//帧1长附加值 
#define  U2_Len_Plus_2	32		//帧2长附加值 


#define  U3_DH0			0xEE	//桢头0  数据
#define  U3_DH1			0xCC	//桢头1   数据
#define  U3_Len_Plus		3		 //帧长附加值 


#define  U4_DH0			0xEB      //桢头0  数据
#define  U4_DH1			0x90      //桢头1   数据
#define  U4_Length		32           //0可定义帧长  其它固定帧长


#define  U_5678_DH0		0xEE	//桢头0  数据
#define  U_5678_DH1		0xCC	//桢头1   数据
#define  U_5678_Length	44		//0可定义帧长  其它固定帧长
#define  U_5678_BDStart	0x24	//北斗数据帧帧头
#define  U_5678_BDEnd	0x0A	//北斗数据帧帧尾


#define  U9_DH0			0xAA	//桢头0  数据
#define  U9_DH1			0x55	//桢头1  数据
#define  U9_Length		13		//0可定义帧长  其它固定帧长

#define  UA_DH0_1		0xAA	//帧头0 数据
#define  UA_DH0_2		0x44	//帧头1 数据
#define  UA_D1_H1		0x13	//桢1-长度 数据
#define  UA_D2_H1		0x12	//桢2-长度 数据
#define  UA_LengPosi_1	3		//帧1长度字节位置
#define  UA_LengPosi_2	8		//帧2长度字节位置
#define  UA_Len_Plus_1	16		//帧1长附加值 
#define  UA_Len_Plus_2	32		//帧2长附加值 

#define  U_BCDEF_DH0        0xEB	//桢头0  数据
#define  U_BCDEF_DH1        0x90	//桢头1   数据
#define  U_BCDEF_Length	16		//0可定义帧长  其它固定帧长



#define  UG_DH0			0x24      //桢头0  数据
#define  UG_DH1_1		0x03      //桢头1   数据
#define  UG_DH1_2		0x06     //桢头1   数据
#define  UG_Len_1_Addr	2      	//帧长数据地址, 第3个字节
#define  UG_Len_2		8           //0可定义帧长  其它固定帧长


#define  UH_DH0			0xEE	//桢头0  数据
#define  UH_DH1			0xCC	//桢头1   数据
#define  UH_Len_Plus		3		 //帧长附加值 




//串口波特率设置
#define U1_BaudRate     115200
#define U2_BaudRate     115200
#define U3_BaudRate     115200
#define U4_BaudRate     38400
#define U5_BaudRate     19200
#define U6_BaudRate     19200

//扩展串口波特率设置 
#define U7_BaudRate		MAX14830_BR_19200
#define U8_BaudRate		MAX14830_BR_19200
#define U9_BaudRate		MAX14830_BR_19200
#define UA_BaudRate		MAX14830_BR_9600
#define UB_BaudRate		MAX14830_BR_19200
#define UC_BaudRate		MAX14830_BR_19200
#define UD_BaudRate		MAX14830_BR_19200
#define UE_BaudRate		MAX14830_BR_19200
#define UF_BaudRate		MAX14830_BR_19200
#define UG_BaudRate		MAX14830_BR_38400
#define UH_BaudRate		MAX14830_BR_115200
#define UI_BaudRate		MAX14830_BR_9600





