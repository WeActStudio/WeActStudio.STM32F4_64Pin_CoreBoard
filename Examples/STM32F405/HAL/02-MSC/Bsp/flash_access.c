#include "flash_access.h"

__IO const uint64_t uid_data __attribute__((section(".ARM.__at_0x8001000"))) = 0xFFFFFFFFFFFFFFFF;
uint8_t flashx_init(void)
{
  uint8_t result = 0;
  if (uid_data != *(uint64_t *)(UID_BASE))
  {
    if (uid_data == 0xFFFFFFFFFFFFFFFF)
    {
      HAL_FLASH_Unlock();
      HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, (uint32_t)(&uid_data), *(uint32_t *)(UID_BASE));
			HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, (uint32_t)(&uid_data) + 4, *(uint32_t *)(UID_BASE + 4));
      HAL_FLASH_Lock();
      HAL_NVIC_SystemReset();
    }
    else
    {
      FLASH_OBProgramInitTypeDef OptionsBytesStruct;
      HAL_FLASHEx_OBGetConfig(&OptionsBytesStruct);
      if (OptionsBytesStruct.RDPLevel != OB_RDP_LEVEL_1)
      {
				HAL_FLASH_OB_Unlock();
				HAL_FLASH_Unlock();
        OptionsBytesStruct.OptionType = OPTIONBYTE_RDP;
        OptionsBytesStruct.RDPLevel = OB_RDP_LEVEL_1;
        HAL_FLASHEx_OBProgram(&OptionsBytesStruct);
				if (HAL_FLASH_OB_Launch() != HAL_OK) {
            while (1) {
            }
				}
        HAL_FLASH_OB_Lock();
				HAL_FLASH_Lock();
      }
      while (1)
      {
      }
    }
    result++;
  }
  return result;
}