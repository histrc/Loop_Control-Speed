
#include "main.h"
#include "tim.h"
#include "oled.h"
#include "gpio.h"
#include "encode.h"

#include "bsp_pid.h"
#include <stdio.h>
#include <math.h>

/*PID����*/
#define kp 650//100
#define ki 20//20
#define kd 0.03//20

short TargetSpeed=150;

/******************************
	���ܣ�ÿ500ms�ڶ�ʱ����ִ��һ�Σ�
				��ȡ����ٶ�SPEED
	����ֵ������ٶ�SPEED
	�βΣ���
*******************************/
short GetSpeed()
{
	
	short SPEED = 0;
//	static short last = 0;
	//SPEED = (short)((Read_Encoder()*100)/(4*32*30));
	return SPEED;
}


/******************************
	���ܣ�ÿ500ms�ڶ�ʱ����ִ��һ�Σ�
				����pwm����ֵ
	����ֵ������ٶ�SPEED
	�βΣ���
*******************************/
short PID_Cal(short Speed,short *error)
{
	short Error = TargetSpeed - Speed;
	static short Error_last = 0,Error_prev = 0;
	short pwm_add=0;
	if((Error<0.2f)&&(Error>-0.2f)){Error=0.0f;}
	*error = Error;
	pwm_add = kp*(Error - Error_last) + ki*Error + kd*(Error-2.0f*Error_last+Error_prev);
	
	Error_prev = Error_last;	  	    // �������ϴ����
	Error_last = Error;	              // �����ϴ�ƫ��
	
	
	return pwm_add;
}
/******************************
	���ܣ��жϵ������ת��
			�����������õ�PWM��ֵ
			д�뵥Ƭ����
	����ֵ����
	�βΣ���
*******************************/
void SetMotorVoltageAndDirection(int Pwm)
{
	/*if(Pwm<0)
	{
		Motor_1(GPIO_PIN_RESET);
		Motor_2(GPIO_PIN_SET);
	}
	else if(Pwm>0)
	{
		Motor_1(GPIO_PIN_SET);
		Motor_2(GPIO_PIN_RESET);
	}*/
	Pwm = abs(Pwm);
  TIM3->CCR2 = Pwm;
}


