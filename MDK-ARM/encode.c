#include "encode.h"
#include "tim.h"
/**************************************************************************
�������ܣ���λʱ���ȡ����������
��ڲ�������ʱ��
����  ֵ���ٶ�ֵ
**************************************************************************/
int Read_Encoder(void)//��ȡ��������ֵ
{
  int Encoder_TIM;
	
	Encoder_TIM=(short)ENCODE_TIMX->CNT; 
	ENCODE_TIMX ->CNT=0;
	/*Encoder_TIM=(short)(__HAL_TIM_GET_COUNTER(&htim2));
	__HAL_TIM_SET_COUNTER(&htim2,0);*/
  return Encoder_TIM;
}
