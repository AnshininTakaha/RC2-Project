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
  |--FileName    : BSP_CAN.c                                              
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
#include "BSP_CAN.h"
/* =========================== Include End=========================== */

/* =========================== In_Function Begin =========================== */
/* =========================== In_Function End=========================== */

/* =========================== Variable Begin =========================== */
CAN_FilterTypeDef CAN1_Filter;
/* =========================== Variable End=========================== */

/* =========================== Macor Begin =========================== */
/* =========================== Macor End=========================== */

/**
  * @Data   2019-01-07
  * @brief   CAN1_Filter初始化
  * @param   进入参数
  * @retval  返回参数
  */
void CAN1_FILTER_Init(CAN_FilterTypeDef CAN1_Filter)
{	
	CAN1_Filter.FilterIdHigh = 0x0000;
	CAN1_Filter.FilterIdLow = 0x0000;
	CAN1_Filter.FilterMaskIdHigh = 0x0000;
	CAN1_Filter.FilterMaskIdLow = 0x0000;
	CAN1_Filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	CAN1_Filter.FilterBank = 0;
	CAN1_Filter.SlaveStartFilterBank = 0;
	CAN1_Filter.FilterMode = CAN_FILTERMODE_IDMASK;
	CAN1_Filter.FilterScale = CAN_FILTERSCALE_32BIT;
	CAN1_Filter.FilterActivation = CAN_FILTER_ENABLE;
	HAL_CAN_ConfigFilter(&hcan1,&CAN1_Filter);
}
/**
  * @Data   2019-01-07
  * @brief   RM电机CAN中断启用
  * @param   进入参数
  * @retval  返回参数
  */
void RM_MOTOR_CAN1_IT_Init(void)
{
	/*使能滤波器*/
	CAN1_FILTER_Init(CAN1_Filter);
	/*启用CAN*/
	HAL_CAN_Start(&hcan1);
	/*使能CAN的IT中断*/
	__HAL_CAN_ENABLE_IT(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING);
	
}


/*-----------------------------------file of end------------------------------*/