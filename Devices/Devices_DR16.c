/**
  |--------------------------------- Copyright --------------------------------|
  |                                                                            |
  |                      (C) Copyright 2019,口无 ,                             |
  |           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
  |                           All Rights Reserved                              |
  |                                                                            |
  |           By(GCU The wold of team | 华南理工大学广州学院机器人野狼队)      |
  |                    https://github.com/GCUWildwolfteam                      |
  |----------------------------------------------------------------------------|
  |--FileName    : Devices_DR16.c                                              
  |--Version     : v1.0                                                          
  |--Author      : 口无                                                     
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
/*内调用函数(不对外开放)*/
void DR16_ReInit(void);
void DR16_Process(uint8_t *pData);
void DR16_Handler(UART_HandleTypeDef *huart);
/* =========================== In_Function End=========================== */

/* =========================== Variable Begin =========================== */
/*遥控器结构体初始化*/
DR16_t DR16 = DR16_GroundInit;
/* =========================== Variable End=========================== */

/* =========================== Macor Begin =========================== */

/* =========================== Macor End=========================== */



/**
  * @Data    2019-02-19 15:46
  * @brief   DR16数据初始化
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
  * @brief   DR16遥控器解码函数
  * @param   uint8_t *pData
  * @retval  void
  */
void DR16_Process(uint8_t *pData)
{
    /*空值返回*/
	if(pData == NULL)
	{
		return;
	}

  /*遥控器*/
	DR16.Remote.Channel_0 = (pData[0] | (pData[1] << 8)) & 0x07FF;
	DR16.Remote.Channel_1 = ((pData[1] >> 3) | (pData[2] << 5)) & 0x07FF;
	DR16.Remote.Channel_2 = ((pData[2] >> 6) | (pData[3] << 2) | (pData[4] << 10)) & 0x07FF;
	DR16.Remote.Channel_3 = ((pData[4] >> 1) | (pData[5] << 7)) & 0x07FF;
  DR16.Remote.RowWheel = (pData[16] | (pData[17] << 8)) & 0x07FF;
	DR16.Remote.Switch_Left = ((pData[5] >> 4) & 0x000C) >> 2;
	DR16.Remote.Switch_Right = ((pData[5] >> 4) & 0x0003);
	
	/*鼠标*/
	DR16.Mouse.Mouse_X = (pData[6]) | (pData[7] << 8);
	DR16.Mouse.Mouse_Y = (pData[8]) | (pData[9] << 8);
	DR16.Mouse.Mouse_Z = (pData[10]) | (pData[11] << 8);
	DR16.Mouse.KeyLeftClick = pData[12];
	DR16.Mouse.KeyRightClick = pData[13];
	DR16.KeyBoard.key_code = (pData[14] | pData[15] <<8);

  /*通道数字调零*/
  DR16.Remote.Channel_0 -= 1024;
	DR16.Remote.Channel_1 -= 1024;
	DR16.Remote.Channel_2 -= 1024;
	DR16.Remote.Channel_3 -= 1024;
	DR16.Remote.RowWheel -=1024;
}




/**
  * @Data    2019-03-23 20:07
* @brief   获取对应hdma上面的发送后剩余字节数量
  * @param   uint8_t *pData
  * @retval  void
  */
uint16_t DMA_GET_COUNTER(DMA_Stream_TypeDef* __HAL_DMA_Get)
{
		return ((uint16_t)(__HAL_DMA_Get->NDTR));
}

/*一个是读取SR寄存器，一个是读取对应的CR控制寄存器*/
		/*正常情况下CR控制SR，我们入股要读取对应的标志位的话，既可以从CR读取也可以从SR读取*/
		/*__HAL_UART_GET_FLAG是获取SR寄存器里面的情况，也就是读取被CR控制器控制之后的对应状态*/
		/*__HAL_UART_GET_IT_SOURCE是直接读取控制寄存器里面的CRx标志位的情况*/
		/*这里的DMA_GET_COUNTER是获取还没发出去的字符数量，和之前的不同*/
		/*下面是两种情况的对比，请仔细阅读*/
/**
  * @Data    2019-03-23 20:07
  * @brief   DR16处理函数
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



