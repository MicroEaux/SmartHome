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
	gpAppDebugInfo = malloc(sizeof(app_debug_info_t));							// ���� gpAppDebugInfo �ڴ�ռ�
	memset(gpAppDebugInfo, 0, sizeof(app_debug_info_t));						// ��� gpAppDebugInfo �ڴ�ռ�

	gpAppDebugInfo->size = sizeof(app_debug_info_t);							// ��¼ gpAppDebugInfo �ڴ�ռ䳤��
	gpAppDebugInfo->status = APP_DEBUG_STATUS_ENABLE;							// ������־���
	gpAppDebugInfo->level = APP_DEBUG_LEVEL_ALL;								// �����������
	
	AppDebug_relocatePrintf(uart_no, baud_rate);								// �ض��� printf ����
}

void AppDebug_Exit(void)
{
	free(gpAppDebugInfo);
}


