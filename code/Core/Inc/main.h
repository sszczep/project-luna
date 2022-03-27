/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define COL5_Pin GPIO_PIN_0
#define COL5_GPIO_Port GPIOA
#define COL4_Pin GPIO_PIN_1
#define COL4_GPIO_Port GPIOA
#define COL3_Pin GPIO_PIN_2
#define COL3_GPIO_Port GPIOA
#define COL2_Pin GPIO_PIN_3
#define COL2_GPIO_Port GPIOA
#define COL1_Pin GPIO_PIN_4
#define COL1_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define ROW1_Pin GPIO_PIN_6
#define ROW1_GPIO_Port GPIOA
#define ROW2_Pin GPIO_PIN_7
#define ROW2_GPIO_Port GPIOA
#define ROW3_Pin GPIO_PIN_0
#define ROW3_GPIO_Port GPIOB
#define ROW4_Pin GPIO_PIN_1
#define ROW4_GPIO_Port GPIOB
#define ROW5_Pin GPIO_PIN_10
#define ROW5_GPIO_Port GPIOB
#define ROW6_Pin GPIO_PIN_12
#define ROW6_GPIO_Port GPIOB
#define COL15_Pin GPIO_PIN_13
#define COL15_GPIO_Port GPIOB
#define COL14_Pin GPIO_PIN_14
#define COL14_GPIO_Port GPIOB
#define COL13_Pin GPIO_PIN_15
#define COL13_GPIO_Port GPIOB
#define COL12_Pin GPIO_PIN_8
#define COL12_GPIO_Port GPIOA
#define COL11_Pin GPIO_PIN_9
#define COL11_GPIO_Port GPIOA
#define COL10_Pin GPIO_PIN_10
#define COL10_GPIO_Port GPIOA
#define COL9_Pin GPIO_PIN_4
#define COL9_GPIO_Port GPIOB
#define COL8_Pin GPIO_PIN_5
#define COL8_GPIO_Port GPIOB
#define COL7_Pin GPIO_PIN_6
#define COL7_GPIO_Port GPIOB
#define COL6_Pin GPIO_PIN_7
#define COL6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
