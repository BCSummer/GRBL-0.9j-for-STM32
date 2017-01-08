#ifndef __HW_TIM_H
#define __HW_TIM_H




/*
///////////////////////����Ĵ棺����ͨ�ײ����ֲ��GRBL///////////////////////

	HW_TIM_Init();				//��ʱ����ʼ������ʱ��NVIC��ʼ��������̽���һ���жϣ�
	HW_TIM_DriverInterrupt_ValueConfig(8000,9000);		//���ö�ʱ����װֵ
	HW_TIM_DriverInterrupt_Enable(); 					//������ʱ��
	HW_TIM_PortResetInterrupt_ValueConfig(4500,9000); 	//���ö�ʱ����װֵ
	HW_TIM_PortResetInterrupt_Enable();  				//������ʱ��

	HW_Debounce_Init();		//ȥ����ʱ��
	HW_Debounce_Enable();	//ʹ��ȥ����ʱ��
	HW_Debounce_Disable();	//����ȥ����ʱ��


//��ʱ��1�жϷ������
void TIM1_UP_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM1,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM1,TIM_FLAG_Update);
		//.....����

	}
}

//��ʱ��3�жϷ������
void TIM3_IRQHandler(void)   //TIM3�ж�
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIM3�����жϱ�־ 
		//.....����

	}
}

//��ʱ��4�жϷ������
void TIM4_IRQHandler(void)   //TIM4�ж�
{
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  //���TIM4�����жϷ������
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //���TIM4�����жϱ�־ 
		//.....����

	}
}




*/
//##############################��API��##############################
void HW_TIM_Init(void);				//��ʱ����ʼ����Ҫ������stepper.c�е�st_init()
//Driver Interrupt
void HW_TIM_DriverInterrupt_Enable(void); 		//������ʱ��
void HW_TIM_DriverInterrupt_Disable(void);		//�رն�ʱ��
void HW_TIM_DriverInterrupt_ValueConfig(u32 Prescaler,u32 Autoreload);		//���ö�ʱ����װֵ
//Port Reset Interrupt
void HW_TIM_PortResetInterrupt_Enable(void);  	//������ʱ��
void HW_TIM_PortResetInterrupt_Disable(void);	//�رն�ʱ��
void HW_TIM_PortResetInterrupt_ValueConfig(u32 Prescaler,u32 Autoreload); 	//���ö�ʱ����װֵ
//Debounce
void HW_Debounce_Init(void);		//ȥ����ʱ��
void HW_Debounce_Enable(void);		//ʹ��ȥ����ʱ��
void HW_Debounce_Disable(void);		//����ȥ����ʱ��



















#endif
