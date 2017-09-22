/*************************************************************************\
\**************************AUV_Control    2011.04.20**************************/
/***************************AUV_Control System*****************************\
\****************************** Main_Control ********************************/


//函数声明

extern void Delay(u32 nCount);
extern void Delayms(u32 nTime);

extern U32 TimingDelay;  //系统延时计数器


extern U8 MINNum(U16 x0, U16 x1, U16 x2);


/****************************************************************\
函数名称：FIRCal
函数功能：FIR移动平滑滤波器计算

使用最简单的移动平滑滤波，即FIR滤波器中各个项的权值系数相等

ind为当前输入数据
x为环形缓冲区首地址
p为计数器地址
len为滤波器长度
\****************************************************************/
extern U32 FIRCal(U32 ind, U32 *x, U8 *p, U8 len);


//不同类型数据转换
#define    U8toU16(x, y) ((U16)(((U16)(y))<<8|((U16)(x))))
#define    U8toS16(x, y) ((S16)(((U16)(y))<<8|((U16)(x))))

#define    U8toU32(x1, x2,x3, x4)   ((U32)(((U32)(x4))<<24|((U32)(x3))<<16|((U32)(x2))<<8|((U16)(x1))))
#define    U8toS32(x1, x2,x3, x4)   ((S32)(((U32)(x4))<<24|((U32)(x3))<<16|((U32)(x2))<<8|((U16)(x1))))

#define    U16toU8(x)    (U8*)(&(x))
#define    S16toU8(x)    (U8*)(&(x))

//将x的第y位置1,  其余位不变;    
#define    SetBit(x, y)  x= (((U8)(x))|(0x01<<((U8)(y))))

//将x的第y位清0 ,  其余位不变; 
#define    ResetBit(x, y)  x= (((U8)(x))&(~(0x01<<((U8)(y)))))

//将x的第y位及前1位 置z,  其余位不变;    
#define    Set2Bit(x, y,z)  x= ((((U8)(x))&(~(0x03<<((U8)(y)))))|(((U8)(z))<<((U8)(y))))

//获取x的第y位是0还是1;    
#define    GetBit(x, y)  ((((U8)(x))>>((U8)(y)))&0x01)
//获取x的第y位及前1位    
//y取值0,1,2,3,4,5,6,7分别对应 01,12,23,34,45,56,67,7bit
#define    Get2Bit(x, y)  ((((U8)(x))>>((U8)(y)))&0x03)

extern uint8 CharToHex( uint8 c1, uint8 c2);


extern void TmpCtrl(void);  //温度控制

#define  NVRAMProData_ADDR  0  //现场保护数据存储起始地址
void Save_ProData(void);  //存储现场保护数据
void Read_ProData(void);  //读取现场保护数据


