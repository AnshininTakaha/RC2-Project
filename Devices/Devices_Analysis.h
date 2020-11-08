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
  |--FileName    : Devices_Analysis.h                                                
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
#ifndef __DEVICES_ANALYSIS
#define __DEVICES_ANALYSIS
/* =========================== Include&Define Begin =========================== */
#include "BSP_CAN.h"
/* =========================== Include&Define End=========================== */

/* =========================== Extern Begin =========================== */
/* =========================== Extern End=========================== */

/* =========================== Structure Begin =========================== */
typedef struct
{
		uint8_t CAN_RxMessage[8];
		CAN_RxHeaderTypeDef CAN_RxHeader;	
}CAN_RxTypedef;
/* =========================== Structure End=========================== */

/* =========================== Function Begin =========================== */
/*Analysis_CAN1中断回调函数*/
void Analysis_CAN1_Handler(CAN_HandleTypeDef *hcan);

/*电机函数解析*/
void CANx_Analysis(CAN_RxTypedef Input_RxMessage);
/* =========================== Function End=========================== */
#endif
/*-----------------------------------file of end------------------------------*/
