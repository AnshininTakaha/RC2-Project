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
  |--FileName    : Devices_RM3508.h                                               
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
#ifndef __DEVICES_RM3508_H
#define __DEVICES_RM3508_H
/* =========================== Include&Define Begin =========================== */
#include "Devices_Analysis.h"
#include "stm32f4xx_hal.h"
/* =========================== Include&Define End=========================== */

/* =========================== Structure Begin =========================== */
typedef struct
{
	/*���ص���ֵ���*/
	int16_t RealAngle;
	int16_t RealSpeed;
	int16_t RealCurrent;
	int16_t RealTempeture;
}RM3508_t;

/* =========================== Structure End=========================== */

/* =========================== Extern Begin =========================== */
extern RM3508_t RM3508;
/* =========================== Extern End=========================== */

/* =========================== Function Begin =========================== */
/*������ݽ���*/
void RM3508_Process(CAN_RxTypedef RxMessage);

/* =========================== Function End=========================== */






#endif
