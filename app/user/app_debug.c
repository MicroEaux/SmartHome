#include "app_debug.h"

app_debug_info_t *gpAppDebugInfo;

void AppDebug_relocatePrintf(UART_Port uart_no, uint32 baud_rate)
{
	UART_WaitTxFifoEmpty(uart_no);

	UART_ConfigTypeDef uart_config;
	uart_config.baud_rate	= baud_rate;
	uart_config.data_bits	= UART_WordLength_8b;
    uart_config.parity		= USART_Parity_None;
    uart_config.stop_bits	= USART_StopBits_1;
    uart_config.flow_ctrl	= USART_HardwareFlowControl_None;
	uart_config.UART_RxFlowThresh = 0;
    uart_config.UART_InverseMask = UART_None_Inverse;
    UART_ParamConfig(uart_no, &uart_config);
	UART_SetPrintPort(uart_no);
}

void AppDebug_Init(UART_Port uart_no, uint32 baud_rate)
{
	gpAppDebugInfo = malloc(sizeof(app_debug_info_t));							// 申请 gpAppDebugInfo 内存空间
	memset(gpAppDebugInfo, 0, sizeof(app_debug_info_t));						// 清空 gpAppDebugInfo 内存空间

	gpAppDebugInfo->size = sizeof(app_debug_info_t);							// 记录 gpAppDebugInfo 内存空间长度
	gpAppDebugInfo->status = APP_DEBUG_STATUS_ENABLE;							// 开启日志输出
	gpAppDebugInfo->level = APP_DEBUG_LEVEL_ALL;								// 开启所有输出
	
	AppDebug_relocatePrintf(uart_no, baud_rate);								// 重定向 printf 串口
}

void AppDebug_Exit(void)
{
	free(gpAppDebugInfo);
}


