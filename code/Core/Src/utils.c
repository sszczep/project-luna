#include "main.h"

// https://michaeltien8901.github.io/2020/05/30/Jump-to-Internal-Bootloader-STM32F4.html
void BOOTLOADER_Jump(void) {
  void (*SysMemBootJump)(void);

  volatile uint32_t addr = 0x1FFF0000;


  HAL_RCC_DeInit();
  HAL_DeInit();

  SysTick->CTRL = 0;
  SysTick->LOAD = 0;
  SysTick->VAL = 0;

  __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH();

  SysMemBootJump = (void (*)(void)) (*((uint32_t *)(addr + 4)));

  __set_MSP(*(uint32_t *)addr);

  SysMemBootJump();
}
