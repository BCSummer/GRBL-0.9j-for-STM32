#include "Hardware.h"

void HW_TIM_Init(void)		  
{	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3|RCC_APB1Periph_TIM4, ENABLE); //ʱ��ʹ��
	
	//��ʱ��TIM3��ʼ��:Driver Interrupt
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //ʹ��ָ����TIM3�ж�,��������ж�
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //��ռ���ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	//��ʱ��TIM4��ʼ��:Port Reset Interrupt
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //ʹ��ָ����TIM3�ж�,��������ж�
	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM4�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�1��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
}

void HW_Debounce_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;	 //�����ʼ������
	NVIC_InitTypeDef NVIC_InitStructure;  

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);

	TIM_TimeBaseStructure.TIM_Prescaler =123;    	     //Լ��ʱ30ms����ȥ�� 
	TIM_TimeBaseStructure.TIM_Period = 123; 				
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 	 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  	
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE); 	//TIM1����ж�����

	NVIC_InitStructure.NVIC_IRQChannel=TIM1_UP_IRQn;		//����TIM1������
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;		//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;			//�����ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;		  		//NVICʹ��
	NVIC_Init(&NVIC_InitStructure);						  		//�����жϷ����������ȼ�
}

//##############################��Driver Interrupt��##############################
void HW_TIM_DriverInterrupt_Enable(void)
{
	TIM_Cmd(TIM3,ENABLE);	
}

void HW_TIM_DriverInterrupt_Disable(void)
{
	TIM_Cmd(TIM3,DISABLE);	
}

void HW_TIM_DriverInterrupt_ValueConfig(u32 Prescaler,u32 Autoreload)
{
	TIM_PrescalerConfig(TIM3,(uint16_t)Prescaler,TIM_PSCReloadMode_Immediate);
	TIM_SetAutoreload(TIM3,(uint16_t)Autoreload);			
}


//##############################��Port Reset Interrupt��##############################
void HW_TIM_PortResetInterrupt_Enable(void)
{
	TIM_Cmd(TIM4,ENABLE);
}

void HW_TIM_PortResetInterrupt_Disable(void)
{
	TIM_Cmd(TIM4,DISABLE);
}

void HW_TIM_PortResetInterrupt_ValueConfig(u32 Prescaler,u32 Autoreload)
{
	TIM_PrescalerConfig(TIM4,(uint16_t)Prescaler,TIM_PSCReloadMode_Immediate);
	TIM_SetAutoreload(TIM4,(uint16_t)Autoreload);
}

//##############################��Debounce��##############################

void HW_Debounce_Enable(void)
{
	TIM_Cmd(TIM1, ENABLE); 
}	 				

void HW_Debounce_Disable(void)
{
	TIM_Cmd(TIM1, DISABLE); 
}	 



