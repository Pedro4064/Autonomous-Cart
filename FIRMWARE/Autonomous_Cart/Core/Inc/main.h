/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g4xx_hal.h"

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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define LEFT_MOTOR_PWM_Pin GPIO_PIN_0
#define LEFT_MOTOR_PWM_GPIO_Port GPIOC
#define RIGHT_MOTOR_PWM_Pin GPIO_PIN_1
#define RIGHT_MOTOR_PWM_GPIO_Port GPIOC
#define IR1_AD_Pin GPIO_PIN_0
#define IR1_AD_GPIO_Port GPIOA
#define LPUART1_TX_Pin GPIO_PIN_2
#define LPUART1_TX_GPIO_Port GPIOA
#define LPUART1_RX_Pin GPIO_PIN_3
#define LPUART1_RX_GPIO_Port GPIOA
#define YELLOW_LED_Pin GPIO_PIN_5
#define YELLOW_LED_GPIO_Port GPIOA
#define IR2_AD_Pin GPIO_PIN_6
#define IR2_AD_GPIO_Port GPIOA
#define BATTERY_AD_Pin GPIO_PIN_7
#define BATTERY_AD_GPIO_Port GPIOA
#define IMU_SCL_Pin GPIO_PIN_4
#define IMU_SCL_GPIO_Port GPIOC
#define BT_ENTER_Pin GPIO_PIN_5
#define BT_ENTER_GPIO_Port GPIOC
#define ULTRASSONIC_TRIGGER_Pin GPIO_PIN_2
#define ULTRASSONIC_TRIGGER_GPIO_Port GPIOB
#define BLUETOOTH_RX_Pin GPIO_PIN_10
#define BLUETOOTH_RX_GPIO_Port GPIOB
#define BLUETOOTH_TX_Pin GPIO_PIN_11
#define BLUETOOTH_TX_GPIO_Port GPIOB
#define LEFT_MOTOR_DIR_IN1_Pin GPIO_PIN_12
#define LEFT_MOTOR_DIR_IN1_GPIO_Port GPIOB
#define IR3_AD_Pin GPIO_PIN_13
#define IR3_AD_GPIO_Port GPIOB
#define IR4_AD_Pin GPIO_PIN_15
#define IR4_AD_GPIO_Port GPIOB
#define ULTRASSONIC_ECO_Pin GPIO_PIN_6
#define ULTRASSONIC_ECO_GPIO_Port GPIOC
#define BT_DOWN_Pin GPIO_PIN_7
#define BT_DOWN_GPIO_Port GPIOC
#define BT_LEFT_Pin GPIO_PIN_8
#define BT_LEFT_GPIO_Port GPIOC
#define BT_RIGHT_Pin GPIO_PIN_9
#define BT_RIGHT_GPIO_Port GPIOC
#define IMU_SDA_Pin GPIO_PIN_8
#define IMU_SDA_GPIO_Port GPIOA
#define IR5_AD_Pin GPIO_PIN_9
#define IR5_AD_GPIO_Port GPIOA
#define RIGHT_MOTOR_DIR_IN4_Pin GPIO_PIN_10
#define RIGHT_MOTOR_DIR_IN4_GPIO_Port GPIOA
#define RED_LED_Pin GPIO_PIN_11
#define RED_LED_GPIO_Port GPIOA
#define GREEN_LED_Pin GPIO_PIN_12
#define GREEN_LED_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define BUZZER_PWM_Pin GPIO_PIN_15
#define BUZZER_PWM_GPIO_Port GPIOA
#define SW_FRONTAL_Pin GPIO_PIN_2
#define SW_FRONTAL_GPIO_Port GPIOD
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
#define LEFT_ENCODER_Pin GPIO_PIN_4
#define LEFT_ENCODER_GPIO_Port GPIOB
#define RIGHT_ENCODER_Pin GPIO_PIN_5
#define RIGHT_ENCODER_GPIO_Port GPIOB
#define BT_UP_Pin GPIO_PIN_6
#define BT_UP_GPIO_Port GPIOB
#define RIGHT_MOTOR_DIR_IN3_Pin GPIO_PIN_7
#define RIGHT_MOTOR_DIR_IN3_GPIO_Port GPIOB
#define BLUE_LED_Pin GPIO_PIN_8
#define BLUE_LED_GPIO_Port GPIOB
#define LEFT_MOTOR_DIR_IN2_Pin GPIO_PIN_9
#define LEFT_MOTOR_DIR_IN2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
