#include "encode.h"
/**************************************************************************
函数功能：单位时间读取编码器计数
入口参数：定时器
返回  值：速度值
**************************************************************************/
int Read_Encoder(void)//读取计数器的值
{
  int Encoder_TIM;
	
	Encoder_TIM=(short)ENCODE_TIMX->CNT; ENCODE_TIMX ->CNT=0;

  return Encoder_TIM;
}
