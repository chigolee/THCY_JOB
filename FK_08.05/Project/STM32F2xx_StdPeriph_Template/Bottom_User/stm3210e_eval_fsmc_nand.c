/**
  ******************************************************************************
  * @file    stm3210e_eval_fsmc_nand.c
  * @author  MCD Application Team
  * @version V4.3.0
  * @date    10/15/2010
  * @brief   This file provides a set of functions needed to drive the
  *          NAND512W3A2 memory mounted on STM3210E-EVAL board.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "Configuration.h"
#include "main.h"
/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM3210E_EVAL
  * @{
  */
  
/** @addtogroup STM3210E_EVAL_FSMC_NAND
  * @brief      This file provides a set of functions needed to drive the
  *             NAND512W3A2 memory mounted on STM3210E-EVAL board.
  * @{
  */ 

/** @defgroup STM3210E_EVAL_FSMC_NAND_Private_Types
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM3210E_EVAL_FSMC_NAND_Private_Defines
  * @{
  */ 
/** 
  * @brief  FSMC Bank 2 
  */


/**
  * @}
  */ 

/** @defgroup STM3210E_EVAL_FSMC_NAND_Private_Macros
  * @{
  */
#define ROW_ADDRESS (Address.Page + (Address.Block + (Address.Zone * NAND_ZONE_SIZE)) * NAND_BLOCK_SIZE)  

NAND_IDTypeDef NAND_ID;
uint32  Bank_NAND_ADDR  = Bank2_NAND_ADDR;

/**
  * @}
  */ 
  

/** @defgroup STM3210E_EVAL_FSMC_NAND_Private_Variables
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM3210E_EVAL_FSMC_NAND_Private_Function_Prototypes
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup STM3210E_EVAL_FSMC_NAND_Private_Functions
  * @{
  */ 


void nand_delay_ms(u32 ms)
{
	u16 i;
	for(;ms != 0;ms--)
	{
		for(i=0;i<20000;i++)
		{
			__nop();
		}
	}
}
/**
  * @brief  Configures the FSMC and GPIOs to interface with the NAND memory.
  *         This function must be called before any write/read operation on the 
  *         NAND.
  * @param  None
  * @retval None
  */
void NAND_Init(void)
{
  FSMC_NANDInitTypeDef FSMC_NANDInitStructure;
  FSMC_NAND_PCCARDTimingInitTypeDef  p;
  // FSMC端口已经在SRAM_Init中初始化完成

  /*-- FSMC Configuration ------------------------------------------------------*/
  p.FSMC_SetupTime = 0x0;
  p.FSMC_WaitSetupTime = 0x2;
  p.FSMC_HoldSetupTime = 0x1;
  p.FSMC_HiZSetupTime = 0x0;
  
  FSMC_NANDInitStructure.FSMC_Bank = FSMC_Bank2_NAND;
  FSMC_NANDInitStructure.FSMC_Waitfeature = FSMC_Waitfeature_Enable;
  FSMC_NANDInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
  FSMC_NANDInitStructure.FSMC_ECC = FSMC_ECC_Enable;
  FSMC_NANDInitStructure.FSMC_ECCPageSize = FSMC_ECCPageSize_4096Bytes;
  FSMC_NANDInitStructure.FSMC_TCLRSetupTime = 0x00;
  FSMC_NANDInitStructure.FSMC_TARSetupTime = 0x00;
  FSMC_NANDInitStructure.FSMC_CommonSpaceTimingStruct = &p;
  FSMC_NANDInitStructure.FSMC_AttributeSpaceTimingStruct = &p;

  FSMC_NANDInit(&FSMC_NANDInitStructure);

  /*!< FSMC NAND Bank Cmd Test */
  FSMC_NANDCmd(FSMC_Bank2_NAND, ENABLE);
  
  FSMC_NANDInitStructure.FSMC_Bank = FSMC_Bank3_NAND;
  FSMC_NANDInitStructure.FSMC_Waitfeature = FSMC_Waitfeature_Enable;
  FSMC_NANDInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b;
  FSMC_NANDInitStructure.FSMC_ECC = FSMC_ECC_Enable;
  FSMC_NANDInitStructure.FSMC_ECCPageSize = FSMC_ECCPageSize_4096Bytes;
  FSMC_NANDInitStructure.FSMC_TCLRSetupTime = 0x00;
  FSMC_NANDInitStructure.FSMC_TARSetupTime = 0x00;
  FSMC_NANDInitStructure.FSMC_CommonSpaceTimingStruct = &p;
  FSMC_NANDInitStructure.FSMC_AttributeSpaceTimingStruct = &p;

  FSMC_NANDInit(&FSMC_NANDInitStructure);

  /*!< FSMC NAND Bank Cmd Test */
  FSMC_NANDCmd(FSMC_Bank3_NAND, ENABLE);

  

  Select_NAND0;
  NAND_Reset();
  Select_NAND1;
  NAND_Reset();
 
  Delayms(10);
  Select_NAND0;
  NAND_Set8xTiming();//设置最快时序
  Select_NAND1;
  NAND_Set8xTiming();//设置最快时序
  
}

/**
  * @brief  Reads NAND memory's ID.
  * @param  NAND_ID: pointer to a NAND_IDTypeDef structure which will hold
  *         the Manufacturer and Device ID.  
  * @retval None
  */
void NAND_ReadID(NAND_IDTypeDef* NAND_ID)
{
  uint32_t data = 0;

  /*!< Send Command to the command area */
  *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = 0x90;
  *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00;
	 // wait
	// nand_delay_ms(1); 
   /*!< Sequence to read ID from NAND flash */
   data = *(__IO uint32_t *)(Bank_NAND_ADDR | DATA_AREA);

   NAND_ID->Maker_ID   = ADDR_1st_CYCLE (data);
   NAND_ID->Device_ID  = ADDR_2nd_CYCLE (data);
   NAND_ID->Third_ID   = ADDR_3rd_CYCLE (data);
   NAND_ID->Fourth_ID  = ADDR_4th_CYCLE (data);
   
}

/**
  * @brief  This routine is for writing one or several 512 Bytes Page size.
  * @param  pBuffer: pointer on the Buffer containing data to be written 
  * @param  Address: First page address
  * @param  NumPageToWrite: Number of page to write  
  * @retval New status of the NAND operation. This parameter can be:
  *              - NAND_TIMEOUT_ERROR: when the previous operation generate 
  *                a Timeout error
  *              - NAND_READY: when memory is ready for the next operation 
  *                And the new status of the increment address operation. It can be:
  *              - NAND_VALID_ADDRESS: When the new address is valid address
  *              - NAND_INVALID_ADDRESS: When the new address is invalid address  
  */
uint32_t NAND_WriteSmallPage(uint8_t *pBuffer, NAND_ADDRESS* pAddress, uint32_t NumPageToWrite)
{
  uint32_t index = 0x00, numpagewritten = 0x00, addressstatus = NAND_VALID_ADDRESS;
  uint32_t status = NAND_READY, size = 0x00;
  NAND_ADDRESS Address = *pAddress;

  while((NumPageToWrite != 0x00) && (addressstatus == NAND_VALID_ADDRESS) && (status == NAND_READY))
  {
    /*!< Page write command and address */
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_AREA_A;
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_WRITE0;

    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00;
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00;
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_1st_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_2nd_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_3rd_CYCLE(ROW_ADDRESS);

    /*!< Calculate the size */
    size = NAND_PAGE_SIZE + (NAND_PAGE_SIZE * numpagewritten);

    /*!< Write data */
    for(; index < size; index++)
    {
      *(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA) = pBuffer[index];
    }
    
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_WRITE_TRUE1;

    /*!< Check status for successful operation */
    status = NAND_GetStatus();
    
    //if(status == NAND_READY)
   // {
      numpagewritten++;

      NumPageToWrite--;
      /*!< Calculate Next small page Address */
      addressstatus = NAND_AddressIncrement(&Address);
    //}
  }
  *pAddress = Address;
  return (status | addressstatus);
}




void NAND_Set8xTiming() 
{
	*(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = 0xef;
	*(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x01; 
	*(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA) = 0x08;
	*(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA) = 0x00;
	*(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA) = 0x00;
	*(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA) = 0x00;
}

/**
  * @brief  This routine is for sequential read from one or several 512 Bytes Page size.
  * @param  pBuffer: pointer on the Buffer to fill
  * @param  Address: First page address
  * @param  NumPageToRead: Number of page to read  
  * @retval New status of the NAND operation. This parameter can be:
  *              - NAND_TIMEOUT_ERROR: when the previous operation generate 
  *                a Timeout error
  *              - NAND_READY: when memory is ready for the next operation 
  *                And the new status of the increment address operation. It can be:
  *              - NAND_VALID_ADDRESS: When the new address is valid address
  *              - NAND_INVALID_ADDRESS: When the new address is invalid address
  */
uint32_t NAND_ReadSmallPage(uint8_t *pBuffer, NAND_ADDRESS *pAddress, uint32_t NumPageToRead)
{
  uint32_t index = 0x00, numpageread = 0x00, addressstatus = NAND_VALID_ADDRESS;
  uint32_t status = NAND_READY, size = 0x00;
  NAND_ADDRESS Address = *pAddress;

   uint16_t timeout=5000;

  while((NumPageToRead != 0x0) && (addressstatus == NAND_VALID_ADDRESS))
  {
    /*!< Page Read command and page address */
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_AREA_A;
   
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00; 
		*(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00; 
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_1st_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_2nd_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_3rd_CYCLE(ROW_ADDRESS);
	
     *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = 0x30;
		
    //等待20us
    // The 4,224 bytes  of data within the selected page are transferred to the data registers in less than 20μs(tR).
     while((((GPIOD->IDR) & GPIO_Pin_6) == 0)&&(timeout != 0))
     {
           timeout --;
     }
    
    /*!< Calculate the size */
    size = NAND_PAGE_SIZE + (NAND_PAGE_SIZE * numpageread);
    
    /*!< Get Data into Buffer */    
    for(; index < size; index++)
    {
      pBuffer[index]= *(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA);
    }

    numpageread++;
    
    NumPageToRead--;

    /*!< Calculate page address */
    addressstatus = NAND_AddressIncrement(&Address);
  }

  if(timeout == 0x00)
  {
        status =  NAND_TIMEOUT_ERROR;
  }
  else
  {
        status = NAND_GetStatus();
  }  
  *pAddress = Address;
  return (status | addressstatus);
}

/**
  * @brief  This routine write the spare area information for the specified
  *         pages addresses.  
  * @param  pBuffer: pointer on the Buffer containing data to be written 
  * @param  Address: First page address
  * @param  NumSpareAreaTowrite: Number of Spare Area to write
  * @retval New status of the NAND operation. This parameter can be:
  *              - NAND_TIMEOUT_ERROR: when the previous operation generate 
  *                a Timeout error
  *              - NAND_READY: when memory is ready for the next operation 
  *                And the new status of the increment address operation. It can be:
  *              - NAND_VALID_ADDRESS: When the new address is valid address
  *              - NAND_INVALID_ADDRESS: When the new address is invalid address
  */
uint32_t NAND_WriteSpareArea(uint8_t *pBuffer, NAND_ADDRESS Address, uint32_t NumSpareAreaTowrite)
{
  uint32_t index = 0x00, numsparesreawritten = 0x00, addressstatus = NAND_VALID_ADDRESS;
  uint32_t status = NAND_READY, size = 0x00; 

  while((NumSpareAreaTowrite != 0x00) && (addressstatus == NAND_VALID_ADDRESS) && (status == NAND_READY))
  {
    /*!< Page write Spare area command and address */
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_AREA_C;
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_WRITE0;

    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00; 
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_1st_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_2nd_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_3rd_CYCLE(ROW_ADDRESS);

    /*!< Calculate the size */ 
    size = NAND_SPARE_AREA_SIZE + (NAND_SPARE_AREA_SIZE * numsparesreawritten);

    /*!< Write the data */ 
    for(; index < size; index++)
    {
      *(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA) = pBuffer[index];
    }
    
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_WRITE_TRUE1;

    /*!< Check status for successful operation */
    status = NAND_GetStatus();

    if(status == NAND_READY)
    {
      numsparesreawritten++;

      NumSpareAreaTowrite--;
    
      /*!< Calculate Next page Address */
      addressstatus = NAND_AddressIncrement(&Address);
    }
  }
  
  return (status | addressstatus);
}

/**
  * @brief  This routine read the spare area information from the specified
  *         pages addresses.  
  * @param  pBuffer: pointer on the Buffer to fill 
  * @param  Address: First page address
  * @param  NumSpareAreaToRead: Number of Spare Area to read
  * @retval New status of the NAND operation. This parameter can be:
  *              - NAND_TIMEOUT_ERROR: when the previous operation generate 
  *                a Timeout error
  *              - NAND_READY: when memory is ready for the next operation 
  *                And the new status of the increment address operation. It can be:
  *              - NAND_VALID_ADDRESS: When the new address is valid address
  *              - NAND_INVALID_ADDRESS: When the new address is invalid address
  */
uint32_t NAND_ReadSpareArea(uint8_t *pBuffer, NAND_ADDRESS Address, uint32_t NumSpareAreaToRead)
{
  uint32_t numsparearearead = 0x00, index = 0x00, addressstatus = NAND_VALID_ADDRESS;
  uint32_t status = NAND_READY, size = 0x00;

  while((NumSpareAreaToRead != 0x0) && (addressstatus == NAND_VALID_ADDRESS))
  {     
    /*!< Page Read command and page address */
    *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_AREA_C;

    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = 0x00; 
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_1st_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_2nd_CYCLE(ROW_ADDRESS);
    *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_3rd_CYCLE(ROW_ADDRESS);

    /*!< Data Read */
    size = NAND_SPARE_AREA_SIZE +  (NAND_SPARE_AREA_SIZE * numsparearearead);

    /*!< Get Data into Buffer */
    for ( ;index < size; index++)
    {
      pBuffer[index] = *(__IO uint8_t *)(Bank_NAND_ADDR | DATA_AREA);
    }
    
    numsparearearead++;
    
    NumSpareAreaToRead--;

    /*!< Calculate page address */
    addressstatus = NAND_AddressIncrement(&Address);
  }

  status = NAND_GetStatus();

  return (status | addressstatus);
}

/**
  * @brief  This routine erase complete block from NAND FLASH
  * @param  Address: Any address into block to be erased
  * @retval New status of the NAND operation. This parameter can be:
  *              - NAND_TIMEOUT_ERROR: when the previous operation generate 
  *                a Timeout error
  *              - NAND_READY: when memory is ready for the next operation 
  */
uint32_t NAND_EraseBlock(NAND_ADDRESS Address)
{
  *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_ERASE0;

  *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_1st_CYCLE(ROW_ADDRESS);
  *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_2nd_CYCLE(ROW_ADDRESS);
  *(__IO uint8_t *)(Bank_NAND_ADDR | ADDR_AREA) = ADDR_3rd_CYCLE(ROW_ADDRESS);

  *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_ERASE1; 

  return (NAND_GetStatus());
}

/**
  * @brief  This routine reset the NAND FLASH.
  * @param  None
  * @retval NAND_READY
  */
uint32_t NAND_Reset(void)
{
  *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_RESET;
  return (NAND_READY);
}

/**
  * @brief  Get the NAND operation status.
  * @param  None
  * @retval New status of the NAND operation. This parameter can be:
  *              - NAND_TIMEOUT_ERROR: when the previous operation generate
  *                a Timeout error
  *              - NAND_READY: when memory is ready for the next operation
  */
uint32_t NAND_GetStatus(void)
{
 uint32_t timeout = 300000, status = NAND_BUSY;

  //等待2ms
    // Block Erase Time  2ms
     while((((GPIOD->IDR) & GPIO_Pin_6) == 0)&&(timeout != 0))
     {
           timeout --;
     }

    if(timeout == 0x00)
   {
            status =  NAND_TIMEOUT_ERROR;
   }
   else
   {       
	   status = NAND_ReadStatus();    	  
   }


  /*!< Return the operation status */
  return (status);
}
  
/**
  * @brief  Reads the NAND memory status using the Read status command. 
  * @param  None
  * @retval The status of the NAND memory. This parameter can be:
  *              - NAND_BUSY: when memory is busy
  *              - NAND_READY: when memory is ready for the next operation
  *              - NAND_ERROR: when the previous operation gererates error
  */
uint32_t NAND_ReadStatus(void)
{
  uint32_t data = 0x00, status = NAND_BUSY;

  /*!< Read status operation ------------------------------------ */
  *(__IO uint8_t *)(Bank_NAND_ADDR | CMD_AREA) = NAND_CMD_STATUS;
  data = *(__IO uint8_t *)(Bank_NAND_ADDR);

  if((data & NAND_ERROR) == NAND_ERROR)
  {
    status = NAND_ERROR;
  } 
  else if((data & NAND_READY) == NAND_READY)
  {
    status = NAND_READY;
  }
  else
  {
    status = NAND_BUSY; 
  }
  
  return (status);
}

/**
  * @brief  Increment the NAND memory address. 
  * @param  Address: address to be incremented.
  * @retval The new status of the increment address operation. It can be:
  *              - NAND_VALID_ADDRESS: When the new address is valid address
  *              - NAND_INVALID_ADDRESS: When the new address is invalid address   
  */
uint32_t NAND_AddressIncrement(NAND_ADDRESS* Address)
{
  uint32_t status = NAND_VALID_ADDRESS;
 
  Address->Page++;

  if(Address->Page == NAND_BLOCK_SIZE)
  {
    Address->Page = 0;
    Address->Block++;
    
    if(Address->Block == NAND_ZONE_SIZE)
    {
      Address->Block = 0;
      Address->Zone++;

      if(Address->Zone == NAND_MAX_ZONE)
      {
        status = NAND_INVALID_ADDRESS;
      }
    }
  } 
  
  return (status);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */  

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
