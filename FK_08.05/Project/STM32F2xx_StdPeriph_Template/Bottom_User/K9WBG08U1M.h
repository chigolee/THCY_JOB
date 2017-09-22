
//K9WBG08U1M����ض���
// 4GByte Nand Flash Memory
// 1 Page = (4K + 128)Bytes
// 1 Block = (4K + 128)B x 64 Pages = (256K + 8K) Bytes
// 1 Device = (4K+128)B x 64Pages x 16384 Blocks = 4224 MBytes
//ʵ��BLOCKsԼ16064~16384

//K9WAG08U1M-����ض���
// 2GByte Nand Flash Memory
// 1 Page = (2K + 128)Bytes
// 1 Block = (2K + 128)B x 64 Pages = (128K + 8K) Bytes
// 1 Device = (2K+128)B x 64Pages x 16384 Blocks = 2112 MBytes
//ʵ��BLOCKsԼ16064~16384

//K9WAG08U1M��K9WBG08U1M��ʵ�ʵ�ҳ��С��һ����K9WAG08U1MΪ2k��K9WBG08U1MΪ4k

/** 
  * @brief  FSMC NAND memory parameters  
  */  
//#define K9WAG08U1M       //2G flash
//#define K9WBG08U1M       //4G flash

//#define NAND_PAGE_SIZE             ((uint16_t)0x1000) /* 4096 bytes per page w/o Spare Area */   //K9WAG08U1M��K9WBG08U1M��д����ͳһ
//#define NAND_BLOCK_SIZE            ((uint16_t)0x0040) /* 64 pages per block */
//#define NAND_ZONE_SIZE             ((uint16_t)0x0800) /* 2048 Block per zone */
//#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x00E0) /* last 224 bytes as spare area */

// ע�⣺NAND���һ��BLOCK���������ã���ʹ��
#define NAND_PAGE_SIZE             ((uint16_t)0x1000) /* 4096 bytes per page w/o Spare Area */
#define NAND_BLOCK_SIZE            ((uint16_t)0x0040) /* 256x4096 bytes pages per block */
#define NAND_ZONE_SIZE             ((uint16_t)0x0800) /* 2048 Block per zone */
#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x00E0) /* last 128 bytes as spare area */
#define NAND_MAX_ZONE              ((uint16_t)0x0008) /* 8 zones of 2048 block */

#define MakerID  0xEC  //Maker Code

#define K9WAG08U1M_DeviceID  0xD3  //Device Code
#define K9WBG08U1M_DeviceID  0xD5  //Device Code

//#ifdef K9WAG08U1M
//#define NAND_PAGE_SIZE             ((uint16_t)0x1000) /* 2048 bytes per page w/o Spare Area */
//#define NAND_BLOCK_SIZE            ((uint16_t)0x0040) /* 64 pages per block */
//#define NAND_ZONE_SIZE             ((uint16_t)0x0800) /* 2048 Block per zone */
//#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x00E0) /* last 224 bytes as spare area */
//#define NAND_MAX_ZONE              ((uint16_t)0x0004) /* 8 zones of 2048 block */

//#define MakerID  0xEC  //Maker Code
//#define DeviceID  0xD3  //Device Code
//#define ThirdID  0x51  // 3rd Cycle
//#define FourthID  0x95  // 4rd Cycle

//#elif defined K9WBG08U1M
//#define NAND_PAGE_SIZE             ((uint16_t)0x1000) /* 4096 bytes per page w/o Spare Area */
//#define NAND_BLOCK_SIZE            ((uint16_t)0x0040) /* 64 pages per block */
//#define NAND_ZONE_SIZE             ((uint16_t)0x0800) /* 2048 Block per zone */
//#define NAND_SPARE_AREA_SIZE       ((uint16_t)0x00E0) /* last 224 bytes as spare area */
//#define NAND_MAX_ZONE              ((uint16_t)0x0008) /* 8 zones of 2048 block */

//#define MakerID  0xEC  //Maker Code
//#define DeviceID  0xD5  //Device Code
//#define ThirdID  0x51  // 3rd Cycle
//#define FourthID  0xA6  // 4rd Cycle

//#endif 





