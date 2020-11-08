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
  |--FileName    : BSP_USART.h                                              
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
#ifndef __BSP_USART_
#define	__BSP_USART_
/* =========================== Include&Define Begin =========================== */
#include "usart.h"

/*���ö���*/
#define DR16BufferNumber 22
#define DR16BufferTruthNumber 18
#define DR16BufferLastNumber 4
/* =========================== Include&Define End=========================== */

/* =========================== Extern Begin =========================== */
extern uint8_t DR16Buffer[DR16BufferNumber];
/* =========================== Extern End=========================== */

/* =========================== Structure Begin =========================== */

/* =========================== Structure End=========================== */

/* =========================== Function Begin =========================== */
void DR16_USART1_IT_Init(void);
/* =========================== Function End=========================== */
/*-----------------------------------file of end------------------------------*/





#endif
