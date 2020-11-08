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
  |--FileName    : Devices_DR16.c                                              
  |--Version     : v1.0                                                          
  |--Author      : ����                                                     
  |--Date        : 2019-01-07             
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
#include "Devices_DR16.h"
/* =========================== Include End=========================== */

/* =========================== In_Function Begin =========================== */
/*�ڵ��ú���(�����⿪��)*/
void DR16_ReInit(void);
void DR16_Process(uint8_t *pData);
void DR16_Handler(UART_HandleTypeDef *huart);
/* =========================== In_Function End=========================== */

/* =========================== Variable Begin =========================== */
/*ң�����ṹ���ʼ��*/
DR16_t DR16 = DR16_GroundInit;
/* =========================== Variable End=========================== */

/* =========================== Macor Begin =========================== */

/* =========================== Macor End=========================== */



/**
  * @Data    2019-02-19 15:46
  * @brief   DR16���ݳ�ʼ��
  * @param   void
  * @retval  void
  */
void DR16_ReInit(void)
{
	DR16.Remote.Channel_0 = 0;
	DR16.Remote.Channel_1 = 0;
	DR16.Remote.Channel_2 = 0;
	DR16.Remote.Channel_3 = 0;
	DR16.Remote.RowWheel = 0;
	DR16.Remote.Switch_Left = 0;
	DR16.Remote.Switch_Right = 0;
	DR16.Mouse.Mouse_X = 0;
	DR16.Mouse.Mouse_Y = 0;
	DR16.Mouse.Mouse_Z = 0;
	DR16.Mouse.KeyLeftClick = 0;
	DR16.Mouse.KeyRightClick = 0;
	DR16.KeyBoard.key_code = 0;
	DR16.UpdateFrame = 0;
	DR16.OFFLINE_SET = 0;

}


/**
  * @Data    2019-03-23 20:07
  * @brief   DR16ң�������뺯��
  * @param   uint8_t *pData
  * @retval  void
  */
void DR16_Process(uint8_t *pData)
{
    /*��ֵ����*/
	if(pData == NULL)
	{
		return;
	}

  /*ң����*/
	DR16.Remote.Channel_0 = (pData[0] | (pData[1] << 8)) & 0x07FF;
	DR16.Remote.Channel_1 = ((pData[1] >> 3) | (pData[2] << 5)) & 0x07FF;
	DR16.Remote.Channel_2 = ((pData[2] >> 6) | (pData[3] << 2) | (pData[4] << 10)) & 0x07FF;
	DR16.Remote.Channel_3 = ((pData[4] >> 1) | (pData[5] << 7)) & 0x07FF;
  DR16.Remote.RowWheel = (pData[16] | (pData[17] << 8)) & 0x07FF;
	DR16.Remote.Switch_Left = ((pData[5] >> 4) & 0x000C) >> 2;
	DR16.Remote.Switch_Right = ((pData[5] >> 4) & 0x0003);
	
	/*���*/
	DR16.Mouse.Mouse_X = (pData[6]) | (pData[7] << 8);
	DR16.Mouse.Mouse_Y = (pData[8]) | (pData[9] << 8);
	DR16.Mouse.Mouse_Z = (pData[10]) | (pData[11] << 8);
	DR16.Mouse.KeyLeftClick = pData[12];
	DR16.Mouse.KeyRightClick = pData[13];
	DR16.KeyBoard.key_code = (pData[14] | pData[15] <<8);

  /*ͨ�����ֵ���*/
  DR16.Remote.Channel_0 -= 1024;
	DR16.Remote.Channel_1 -= 1024;
	DR16.Remote.Channel_2 -= 1024;
	DR16.Remote.Channel_3 -= 1024;
	DR16.Remote.RowWheel -=1024;
}




/**
  * @Data    2019-03-23 20:07
* @brief   ��ȡ��Ӧhdma����ķ��ͺ�ʣ���ֽ�����
  * @param   uint8_t *pData
  * @retval  void
  */
uint16_t DMA_GET_COUNTER(DMA_Stream_TypeDef* __HAL_DMA_Get)
{
		return ((uint16_t)(__HAL_DMA_Get->NDTR));
}

/*һ���Ƕ�ȡSR�Ĵ�����һ���Ƕ�ȡ��Ӧ��CR���ƼĴ���*/
		/*���������CR����SR���������Ҫ��ȡ��Ӧ�ı�־λ�Ļ����ȿ��Դ�CR��ȡҲ���Դ�SR��ȡ*/
		/*__HAL_UART_GET_FLAG�ǻ�ȡSR�Ĵ�������������Ҳ���Ƕ�ȡ��CR����������֮��Ķ�Ӧ״̬*/
		/*__HAL_UART_GET_IT_SOURCE��ֱ�Ӷ�ȡ���ƼĴ��������CRx��־λ�����*/
		/*�����DMA_GET_COUNTER�ǻ�ȡ��û����ȥ���ַ���������֮ǰ�Ĳ�ͬ*/
		/*��������������ĶԱȣ�����ϸ�Ķ�*/
/**
  * @Data    2019-03-23 20:07
  * @brief   DR16������
  * @param   uint8_t *pData
  * @retval  void
  */
void DR16_Handler(UART_HandleTypeDef *huart)
{
		
		if(__HAL_UART_GET_FLAG(huart, UART_FLAG_IDLE) &&
			 __HAL_UART_GET_IT_SOURCE(huart,UART_IT_IDLE))
		{
			__HAL_UART_CLEAR_IDLEFLAG(huart);
			__HAL_DMA_DISABLE(huart->hdmarx);
			
			//if(DR16BufferNumber - DMA_GET_COUNTER(huart->hdmarx->Instance) == DR16BufferTruthNumber)
			if(__HAL_DMA_GET_COUNTER(huart->hdmarx) == DR16BufferLastNumber)
			{
					DR16.DR16_Process(DR16Buffer);
			}
			
			__HAL_DMA_SET_COUNTER(huart->hdmarx,DR16BufferNumber);
			__HAL_DMA_ENABLE(huart->hdmarx);
		}
}



