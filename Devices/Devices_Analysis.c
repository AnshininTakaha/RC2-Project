/**
  |--------------------------------- Copyright --------------------------------|
  |                                                                            |
  |                      (C) Copyright 2019,����                               |
  |           1 Xuefu Rd, Huadu Qu, Guangzhou Shi, Guangdong Sheng, China      |
  |                           All Rights Reserved                              |
  |                                                                            |
  |           By(GCU The wold of team | ��������ѧ����ѧԺ������Ұ�Ƕ�)      |
  |                    https://github.com/GCUWildwolfteam                      |
  |----------------------------------------------------------------------------|
  |--FileName    : Devices_Analysis.c                                                
  |--Version     : v1.0                                                            
  |--Author      : ����                                                        
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
  * @brief   CAN1�ص���������
  * @param   void
  * @retval  void
  */
void Analysis_CAN1_Handler(CAN_HandleTypeDef *hcan)
{
		CAN_RxTypedef CAN_RxMessage;
		/*�ж��Ƿ�������ж�*/
		if(__HAL_CAN_GET_IT_SOURCE(hcan,CAN_IT_RX_FIFO0_MSG_PENDING))
		{
			/*����CAN�����ݵ���Ӧ�����ṹ����*/
			HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,
													&CAN_RxMessage.CAN_RxHeader,
													CAN_RxMessage.CAN_RxMessage);
			/*��Ӧ�Ľ�������*/	
			CANx_Analysis(CAN_RxMessage);
			
			__HAL_CAN_CLEAR_FLAG(hcan,CAN_IT_RX_FIFO0_MSG_PENDING);
		}
}

/**
  * @Data    2019-02-19 15:46
  * @brief   CANx������������ܺ���
  * @param   void
  * @retval  void
  */

void CANx_Analysis(CAN_RxTypedef Input_RxMessage)
{
		/*ʶ���Ӧ��Rx����IDΪ����*/
		switch(Input_RxMessage.CAN_RxHeader.StdId)
		{
			case 0x202:
				RM3508_Process(Input_RxMessage);
				break;
			
			default:
				
				break;
			
		}
}