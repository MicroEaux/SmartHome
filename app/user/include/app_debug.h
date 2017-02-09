#ifndef __APP_DEBUG_H
#define __APP_DEBUG_H

#include "app_main.h"

enum app_debug_status
{
	APP_DEBUG_STATUS_DISABLE = 0,
	APP_DEBUG_STATUS_ENABLE
};

enum app_debug_level
{
	APP_DEBUG_LEVEL_ALL 	= 0,
	APP_DEBUG_LEVEL_INFO	= 1,
	APP_DEBUG_LEVEL_ERROR	= 2,
};


typedef struct app_debug_info
{
	uint8 size;																	// 该结构体长度
	
	uint8 status:1;												// 调试串口输出标志
	uint8 level	:2;																// 调试串口输出等级
}app_debug_info_t;

void AppDebug_Init(UART_Port uart_no, uint32 baud_rate);


#endif
