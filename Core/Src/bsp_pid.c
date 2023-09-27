
#include "main.h"
#include "tim.h"
#include "oled.h"
#include "gpio.h"
#include "encode.h"

#include "bsp_pid.h"
#include <stdio.h>
#include <math.h>

/*PID参数*/
#define kp 650//100
#define ki 20//20
#define kd 0.03//20

short TargetSpeed=150;

/******************************
	功能：每500ms在定时器中执行一次，
				获取电机速度SPEED
	返回值：电机速度SPEED
	形参：无
*******************************/
short GetSpeed()
{
	
	short SPEED = 0;
//	static short last = 0;
	//SPEED = (short)((Read_Encoder()*100)/(4*32*30));
	return SPEED;
}


/******************************
	功能：每500ms在定时器中执行一次，
				计算pwm返回值
	返回值：电机速度SPEED
	形参：无
*******************************/
short PID_Cal(short Speed,short *error)
{
	short Error = TargetSpeed - Speed;
	static short Error_last = 0,Error_prev = 0;
	short pwm_add=0;
	if((Error<0.2f)&&(Error>-0.2f)){Error=0.0f;}
	*error = Error;
	pwm_add = kp*(Error - Error_last) + ki*Error + kd*(Error-2.0f*Error_last+Error_prev);
	
	Error_prev = Error_last;	  	    // 保存上上次误差
	Error_last = Error;	              // 保存上次偏差
	
	
	return pwm_add;
}
/******************************
	功能：判断电机正反转，
			并将计算所得的PWM数值
			写入单片机中
	返回值：无
	形参：无
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


