#ifndef __BSP_PID_H
#define	__BSP_PID_H
#include "stm32f1xx.h"
#include <stdio.h>
#include <stdlib.h>

/*pid*/
typedef struct
{
  float target_val;     //目标值
	float actual_val;     //实际值
	float err;            //定义当前偏差值
	float err_next;       //定义下一个偏差值
	float err_last;       //定义最后一个偏差值
	float Kp, Ki, Kd;     //定义比例、积分、微分系数
}_pid;

short GetSpeed(void);
short PID_Cal(short Speed,short *error);
void SetMotorVoltageAndDirection(int Pwm);
#endif
