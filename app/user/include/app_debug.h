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
	uint8 size;																	// �ýṹ�峤��
	
	uint8 status:1;												// ���Դ��������־
	uint8 level	:2;																// ���Դ�������ȼ�
}app_debug_info_t;

void AppDebug_Init(UART_Port uart_no, uint32 baud_rate);


#endif
