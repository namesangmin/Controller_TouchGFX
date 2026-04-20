/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define VSYNC_FREQ_Pin GPIO_PIN_2
#define VSYNC_FREQ_GPIO_Port GPIOE
#define RENDER_TIME_Pin GPIO_PIN_3
#define RENDER_TIME_GPIO_Port GPIOE
#define FRAME_RATE_Pin GPIO_PIN_4
#define FRAME_RATE_GPIO_Port GPIOE
#define MCU_ACTIVE_Pin GPIO_PIN_5
#define MCU_ACTIVE_GPIO_Port GPIOE
#define LED_BLUE_Pin GPIO_PIN_6
#define LED_BLUE_GPIO_Port GPIOE
#define LED_1_Pin GPIO_PIN_13
#define LED_1_GPIO_Port GPIOC
#define LED_2_Pin GPIO_PIN_14
#define LED_2_GPIO_Port GPIOC
#define LED_3_Pin GPIO_PIN_15
#define LED_3_GPIO_Port GPIOC
#define ADC_1_Pin GPIO_PIN_1
#define ADC_1_GPIO_Port GPIOC
#define ADC_2_Pin GPIO_PIN_3
#define ADC_2_GPIO_Port GPIOC
#define ADC_3_Pin GPIO_PIN_5
#define ADC_3_GPIO_Port GPIOA
#define JOY_X_Pin GPIO_PIN_7
#define JOY_X_GPIO_Port GPIOA
#define JOY_Y_Pin GPIO_PIN_4
#define JOY_Y_GPIO_Port GPIOC
#define JOY_BUTTON_Pin GPIO_PIN_5
#define JOY_BUTTON_GPIO_Port GPIOC
#define JOY_BUTTON_EXTI_IRQn EXTI9_5_IRQn
#define MODE_BUTTON_Pin GPIO_PIN_11
#define MODE_BUTTON_GPIO_Port GPIOC
#define MODE_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define SEG_DP_Pin GPIO_PIN_12
#define SEG_DP_GPIO_Port GPIOC
#define SEG_G_Pin GPIO_PIN_2
#define SEG_G_GPIO_Port GPIOD
#define SEG_F_Pin GPIO_PIN_4
#define SEG_F_GPIO_Port GPIOD
#define SEG_E_Pin GPIO_PIN_5
#define SEG_E_GPIO_Port GPIOD
#define SEG_D_Pin GPIO_PIN_6
#define SEG_D_GPIO_Port GPIOD
#define SEG_C_Pin GPIO_PIN_7
#define SEG_C_GPIO_Port GPIOD
#define SEG_B_Pin GPIO_PIN_9
#define SEG_B_GPIO_Port GPIOG
#define SEG_A_Pin GPIO_PIN_13
#define SEG_A_GPIO_Port GPIOG
#define COM4_Pin GPIO_PIN_14
#define COM4_GPIO_Port GPIOG
#define COM3_Pin GPIO_PIN_3
#define COM3_GPIO_Port GPIOB
#define COM2_Pin GPIO_PIN_4
#define COM2_GPIO_Port GPIOB
#define COM1_Pin GPIO_PIN_7
#define COM1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define MAX_ADC 5
#define NOISE_FILTTER 150
#define MAX_ADC_X 3
#define JOY_STICK_ADC 2
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
