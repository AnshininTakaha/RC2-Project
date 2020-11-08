/**
  |--------------------------------- Copyright --------------------------------|
  |                                                                            |
  |                      (C) Copyright 2019,口无                               |
  |           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
  |                           All Rights Reserved                              |
  |                                                                            |
  |           By(GCU The wold of team | 华南理工大学广州学院机器人野狼队)      |
  |                    https://github.com/GCUWildwolfteam                      |
  |----------------------------------------------------------------------------|
  |--FileName    : Devices_Analysis.c                                                
  |--Version     : v1.0                                                            
  |--Author      : 口无                                                        
  |--Date        : 2019-03-27               
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
#include "Devices_Analysis.h"
#include "Devices_RM3508.h"
/* =========================== Include End=========================== */

/* =========================== In_Function Begin =========================== */

/* =========================== In_Function End=========================== */

/* =========================== Variable Begin =========================== */

/* =========================== Variable End=========================== */

/* =========================== Macor Begin =========================== */

/* =========================== Macor End=========================== */

/**
  * @Data    2019-02-19 15:46
  * @brief   CAN1回调解析函数
  * @param   void
  * @retval  void
  */
void Analysis_CAN1_Handler(CAN_HandleTypeDef *hcan)
{
		CAN_RxTypedef CAN_RxMessage;
		/*判断是否进入了中断*/
		if(__HAL_CAN_GET_IT_SOURCE(hcan,CAN_IT_RX_FIFO0_MSG_PENDING))
		{
			/*接收CAN的数据到对应解析结构体中*/
			HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,
													&CAN_RxMessage.CAN_RxHeader,
													CAN_RxMessage.CAN_RxMessage);
			/*对应的解析函数*/	
			CANx_Analysis(CAN_RxMessage);
			
			__HAL_CAN_CLEAR_FLAG(hcan,CAN_IT_RX_FIFO0_MSG_PENDING);
		}
}

/**
  * @Data    2019-02-19 15:46
  * @brief   CANx电机函数解析总函数
  * @param   void
  * @retval  void
  */

void CANx_Analysis(CAN_RxTypedef Input_RxMessage)
{
		/*识别对应的Rx接收ID为多少*/
		switch(Input_RxMessage.CAN_RxHeader.StdId)
		{
			case 0x202:
				RM3508_Process(Input_RxMessage);
				break;
			
			default:
				
				break;
			
		}
}