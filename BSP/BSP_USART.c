/**
  |--------------------------------- Copyright --------------------------------|
  |                                                                            |
  |                      (C) Copyright 2019,���� ,                             |
  |           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
  |                           All Rights Reserved                              |
  |                                                                            |
  |           By(GCU The wold of team | ��������ѧ����ѧԺ������Ұ�Ƕ�)      |
  |                    https://github.com/GCUWildwolfteam                      |
  |----------------------------------------------------------------------------|
  |--FileName    : BAP_USART.c	
  |--Version     : v1.0                                                          
  |--Author      : ����                                                     
  |--Date        : 2019-03-23             
  |--Libsupports : 
  |--Description :                                                     
  |--FunctionList                                                     
  |-------1. ....                                                     
  |          <version>:                                                     
  |     <modify staff>:                                                       
  |             <data>:                                                       
  |      <description>:                                                        
  |-------2. ...                                                       
  |-----------------------------declaration of end-----------------------------|
 **/
/* =========================== Include Begin =========================== */
#include "BSP_USART.h"
/* =========================== Include End=========================== */

/* =========================== In_Function Begin =========================== */

/*�ڵ��ú���*/
static int USART1_Receive_DMA_NO_IT(UART_HandleTypeDef* huart, uint8_t* pData, uint32_t Size);
/* =========================== In_Function End=========================== */

/* =========================== Variable Begin =========================== */
/*�궨�����*/
uint8_t DR16Buffer[DR16BufferNumber];
/* =========================== Variable End=========================== */

/* =========================== Macor Begin =========================== */

/* =========================== Macor End=========================== */

/**
  * @Data    2019-02-19 15:46
  * @brief   DR16�жϳ�ʼ��
  * @param   void
  * @retval  void
  */
void DR16_USART1_IT_Init(void)
{
	/*��ձ�־λȻ��ʹ��USART���ж�*/
	__HAL_UART_CLEAR_IDLEFLAG(&huart1);
	__HAL_UART_ENABLE(&huart1);
	__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);
	/*����DMA���䣨���ǲ�����DMA�жϣ�*/
	USART1_Receive_DMA_NO_IT(&huart1,DR16Buffer,DR16BufferNumber);
}

/**
  * @Data    2019-02-19 15:46
  * @brief   USART1_DMA�������ض���
  * @param   void
  * @retval  void
  */
static int USART1_Receive_DMA_NO_IT(UART_HandleTypeDef* huart, uint8_t* pData, uint32_t Size)
{

		/*��⵱ǰhuart״̬*/
		if(huart->RxState == HAL_UART_STATE_READY)
		{
			/*����ĵ�ַ��������������Ļ�*/
			if((pData == NULL) || (Size == 0))
			{
					return HAL_ERROR;
			}
			
			/*huart�����Ӧ��Rx�����ض���*/
			huart->pRxBuffPtr = pData;
			huart->RxXferSize = Size;
			huart->ErrorCode = HAL_UART_ERROR_NONE;
			
			/*����huart1�ϵ�RX_DMA*/
			HAL_DMA_Start(huart->hdmarx,(uint32_t)&huart->Instance->DR,(uint32_t)pData,Size);
			
			/*ֻ������ӦDMA�����Rx���ܣ�����ǿ���Tx�Ļ�����USART_CR3_DMAT��*/
			SET_BIT(huart->Instance->CR3, USART_CR3_DMAR);
			
			
		}
		else
		{
			return HAL_BUSY;
		}
}


/*-----------------------------------file of end------------------------------*/
