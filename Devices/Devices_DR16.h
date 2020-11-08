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
  |--FileName    : Devices_DR16.h                                              
  |--Version     : v1.0                                                          
  |--Author      : 口无                                                     
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
#ifndef __DEVICE_DR16_H
#define __DEVICE_DR16_H
/* =========================== Include&Define Begin =========================== */
#include "BSP_USART.h"
#include "stdbool.h"
#pragma anon_unions

/*结构体初始化*/

#define DR16_GroundInit \
{ \
{0,0,0,0,0,0,0}, \
{0,0,0,0,0}, \
{0}, \
0, \
0, \
&DR16_ReInit, \
&DR16_Process, \
&DR16_Handler, \
} \
/* =========================== Include&Define End=========================== */


/* =========================== Structure Begin =========================== */
/*遥控器结构体*/
typedef struct
{
		/*遥控器变量*/
    struct 
		{
        int16_t Channel_0;//Right_X_Stick
        int16_t Channel_1;//Right_Y_Stick
        int16_t Channel_2;//Left_X_Stick
        int16_t Channel_3;//Left_Y_Stick
        int16_t RowWheel;//RowWheel
        uint8_t Switch_Left;
        uint8_t Switch_Right;
    } Remote;
		
		/*电脑变量*/
    struct
    {
        int16_t Mouse_X;
        int16_t Mouse_Y;
        int16_t Mouse_Z;
        uint8_t KeyLeftClick;
        uint8_t KeyRightClick;
    } Mouse;

		/*键盘变量*/
    union
    {
        uint16_t key_code;
        struct 
				{
				/*对应占用位置字符为1*/
            bool press_W:1;
            bool press_S:1;
            bool press_A:1;
            bool press_D:1;
						bool press_Shift:1;
            bool press_Ctrl:1;
            bool press_Q:1;
            bool press_E:1;
            bool press_R:1;
            bool press_F:1;
            bool press_G:1;
            bool press_Z:1;
            bool press_X:1;
            bool press_C:1;
            bool press_V:1;
            bool press_B:1;
           
        };
    } KeyBoard;
		
	/*帧率控制（判断是否离线）*/
	uint16_t UpdateFrame;
	uint8_t OFFLINE_SET;
		
	/*指针函数*/
	void(*DR16_ReInit)(void);
	void(*DR16_Process)(uint8_t *pData);
	void(*DR16_Handler)(UART_HandleTypeDef *huart);
		
} DR16_t;
/* =========================== Structure End=========================== */


/* =========================== Extern Begin =========================== */
/*对外开放API和结构体*/
extern DR16_t DR16;
/* =========================== Extern End=========================== */

/* =========================== Function Begin =========================== */
/* =========================== Function End=========================== */


	
#endif
