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
  |--FileName    : Devices_RM3508.c                                                
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
#include "Devices_RM3508.h"

/* =========================== Include End=========================== */

/* =========================== In_Function Begin =========================== */
RM3508_t RM3508;
/* =========================== In_Function End=========================== */

/* =========================== Variable Begin =========================== */

/* =========================== Variable End=========================== */

/* =========================== Macor Begin =========================== */

/* =========================== Macor End=========================== */
/**
  * @Data    2019-02-19 15:46
  * @brief   RM3508电机数据解析
  * @param   void
  * @retval  void
  */
void RM3508_Process(CAN_RxTypedef RxMessage)
{
		RM3508.RealAngle = (RxMessage.CAN_RxMessage[0]<<8|RxMessage.CAN_RxMessage[1]);
    RM3508.RealSpeed = (RxMessage.CAN_RxMessage[2]<<8|RxMessage.CAN_RxMessage[3]);
    RM3508.RealCurrent = (RxMessage.CAN_RxMessage[4]<<8|RxMessage.CAN_RxMessage[5]);
    RM3508.RealTempeture = (RxMessage.CAN_RxMessage[6]);
}