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
  |--FileName    : Devices_DR16.h                                              
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
#ifndef __DEVICE_DR16_H
#define __DEVICE_DR16_H
/* =========================== Include&Define Begin =========================== */
#include "BSP_USART.h"
#include "stdbool.h"
#pragma anon_unions

/*�ṹ���ʼ��*/

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
/*ң�����ṹ��*/
typedef struct
{
		/*ң��������*/
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
		
		/*���Ա���*/
    struct
    {
        int16_t Mouse_X;
        int16_t Mouse_Y;
        int16_t Mouse_Z;
        uint8_t KeyLeftClick;
        uint8_t KeyRightClick;
    } Mouse;

		/*���̱���*/
    union
    {
        uint16_t key_code;
        struct 
				{
				/*��Ӧռ��λ���ַ�Ϊ1*/
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
		
	/*֡�ʿ��ƣ��ж��Ƿ����ߣ�*/
	uint16_t UpdateFrame;
	uint8_t OFFLINE_SET;
		
	/*ָ�뺯��*/
	void(*DR16_ReInit)(void);
	void(*DR16_Process)(uint8_t *pData);
	void(*DR16_Handler)(UART_HandleTypeDef *huart);
		
} DR16_t;
/* =========================== Structure End=========================== */


/* =========================== Extern Begin =========================== */
/*���⿪��API�ͽṹ��*/
extern DR16_t DR16;
/* =========================== Extern End=========================== */

/* =========================== Function Begin =========================== */
/* =========================== Function End=========================== */


	
#endif
