/**
  ******************************************************************************
  * @file    app_main.h
  * @author  Roger
  * @version V0.0.0
  * @date    11-January-2017
  * @brief   This file contains all the functions prototypes for the main 
  *          application.
  ******************************************************************************
  * @attention
  * None.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_MAIN_H
#define __APP_MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "esp_common.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "uart.h"

#include "app_debug.h"



void app_main(void);


#endif /* __APP_MAIN_H */
/****************** (C) COPYRIGHT 2017 microeaux technology *******************/
/******************************** END OF FILE *********************************/

