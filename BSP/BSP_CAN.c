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
  |--FileName    : BSP_CAN.c                                              
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
  * @brief   CAN1_Filter��ʼ��
  * @param   �������
  * @retval  ���ز���
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
  * @brief   RM���CAN�ж�����
  * @param   �������
  * @retval  ���ز���
  */
void RM_MOTOR_CAN1_IT_Init(void)
{
	/*ʹ���˲���*/
	CAN1_FILTER_Init(CAN1_Filter);
	/*����CAN*/
	HAL_CAN_Start(&hcan1);
	/*ʹ��CAN��IT�ж�*/
	__HAL_CAN_ENABLE_IT(&hcan1,CAN_IT_RX_FIFO0_MSG_PENDING);
	
}


/*-----------------------------------file of end------------------------------*/