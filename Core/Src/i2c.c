/**
  ******************************************************************************
  * File Name          : I2C.c
  * Description        : This file provides code for the configuration
  *                      of the I2C instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

I2C_HandleTypeDef hi2c3;
DMA_HandleTypeDef hdma_i2c3_rx;
I2C_HandleTypeDef hfmpi2c1;
DMA_HandleTypeDef hdma_fmpi2c1_rx;


/* I2C3 init function */
void MX_I2C3_Init(void)
{

  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }

}

void MX_FMPI2C1_Init(void)
{

  hfmpi2c1.Instance = FMPI2C1;
  hfmpi2c1.Init.ClockSpeed = 100000;
  hfmpi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hfmpi2c1.Init.OwnAddress1 = 0;
  hfmpi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hfmpi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hfmpi2c1.Init.OwnAddress2 = 0;
  hfmpi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hfmpi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hfmpi2c1) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==I2C3)
  {
  /* USER CODE BEGIN I2C3_MspInit 0 */

  /* USER CODE END I2C3_MspInit 0 */
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C3 GPIO Configuration    
    PA8     ------> I2C3_SCL
    PB4     ------> I2C3_SDA 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C3;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* I2C3 clock enable */
    __HAL_RCC_I2C3_CLK_ENABLE();
  
    /* I2C3 DMA Init */
    /* I2C3_RX Init */
    hdma_i2c3_rx.Instance = DMA1_Stream2;
    hdma_i2c3_rx.Init.Channel = DMA_CHANNEL_3;
    hdma_i2c3_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_i2c3_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_i2c3_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_i2c3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_i2c3_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_i2c3_rx.Init.Mode = DMA_NORMAL;
    hdma_i2c3_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_i2c3_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_i2c3_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(i2cHandle,hdmarx,hdma_i2c3_rx);

  /* USER CODE BEGIN I2C3_MspInit 1 */

  /* USER CODE END I2C3_MspInit 1 */
  }
}

void HAL_FMPI2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==FMPI2C1)
  {
  /* USER CODE BEGIN I2C3_MspInit 0 */

  /* USER CODE END I2C3_MspInit 0 */

    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**FMPI2C1 GPIO Configuration
    PC6     ------> FMPI2C1_SCL
    PC7     ------> FMPI2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_FMPI2C1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_FMPI2C1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    /* FMPI2C1 clock enable */
    __HAL_RCC_FMPI2C1_IS_CLK_ENABLED();

    /* FMPI2C1 DMA Init */
    /* FMPI2C1_RX Init */
    hdma_fmpi2c1_rx.Instance = DMA1_Stream2;
    hdma_fmpi2c1_rx.Init.Channel = DMA_CHANNEL_3;
    hdma_fmpi2c1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_fmpi2c1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_fmpi2c1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_fmpi2c1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_fmpi2c1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_fmpi2c1_rx.Init.Mode = DMA_NORMAL;
    hdma_fmpi2c1_rx.Init.Priority = DMA_PRIORITY_LOW;
    hdma_fmpi2c1_rx.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
    if (HAL_DMA_Init(&hdma_fmpi2c1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(i2cHandle,hdmarx,hdma_fmpi2c1_rx);

  /* USER CODE BEGIN FMPI2C1_MspInit 1 */

  /* USER CODE END FMPI2C1_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C3)
  {
  /* USER CODE BEGIN I2C3_MspDeInit 0 */

  /* USER CODE END I2C3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C3_CLK_DISABLE();
  
    /**I2C3 GPIO Configuration    
    PA8     ------> I2C3_SCL
    PB4     ------> I2C3_SDA 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_8);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);

    /* I2C3 DMA DeInit */
    HAL_DMA_DeInit(i2cHandle->hdmarx);
  /* USER CODE BEGIN I2C3_MspDeInit 1 */

  /* USER CODE END I2C3_MspDeInit 1 */
  }
} 

void HAL_FMPI2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==FMPI2C1)
  {
  /* USER CODE BEGIN FMPI2C1_MspDeInit 0 */

  /* USER CODE END FMPI2C1_MspDeInit 0 */
    /* Peripheral clock disable */
	  __HAL_RCC_FMPI2C1_IS_CLK_DISABLE();

    /**FMPI2C1 GPIO Configuration
    PC6     ------> FMPI2C1_SCL
    PC7     ------> FMPI2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_7);

    /* FMPI2C1 DMA DeInit */
    HAL_DMA_DeInit(i2cHandle->hdmarx);
  /* USER CODE BEGIN FMPI2C1_MspDeInit 1 */

  /* USER CODE END FMPI2C1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/