#ifndef __BSP_PID_H
#define	__BSP_PID_H
#include "stm32f1xx.h"
#include <stdio.h>
#include <stdlib.h>

/*pid*/
typedef struct
{
  float target_val;     //Ŀ��ֵ
	float actual_val;     //ʵ��ֵ
	float err;            //���嵱ǰƫ��ֵ
	float err_next;       //������һ��ƫ��ֵ
	float err_last;       //�������һ��ƫ��ֵ
	float Kp, Ki, Kd;     //������������֡�΢��ϵ��
}_pid;

short GetSpeed(void);
short PID_Cal(short Speed,short *error);
void SetMotorVoltageAndDirection(int Pwm);
#endif
