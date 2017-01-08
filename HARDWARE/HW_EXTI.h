#ifndef __HW_EXTI_H
#define __HW_EXTI_H

//##########################��API��##########################
void HW_EXTI_Init(u8 int_portsource,u8 int_pinsource,u32 int_line,EXTITrigger_TypeDef trig); //��ʼ���ⲿ�ж�
void HW_EXTI_Enable(u8 int_channel,u8 preemption_priority,u8 sub_priority);	//ʹ���ж�
void HW_EXTI_Disable(u8 int_channel,u8 preemption_priority,u8 sub_priority);	//�����ж�


/*
///////////////////////����Ĵ棺����ͨ�ײ����ֲ��GRBL///////////////////////

	HW_GPIO_Init_In(LIMIT_GPIO_CLK,LIMIT_GPIO,X_LIMIT_GPIO_PIN);
	HW_GPIO_Write(LIMIT_GPIO,X_LIMIT_GPIO_PIN,1);	//�ߵ�ƽ
	HW_GPIO_Init_In(LIMIT_GPIO_CLK,LIMIT_GPIO,Y_LIMIT_GPIO_PIN);
	HW_GPIO_Write(LIMIT_GPIO,Y_LIMIT_GPIO_PIN,1);	//�ߵ�ƽ
	HW_GPIO_Init_In(LIMIT_GPIO_CLK,LIMIT_GPIO,Z_LIMIT_GPIO_PIN);
	HW_GPIO_Write(LIMIT_GPIO,Z_LIMIT_GPIO_PIN,1);	//�ߵ�ƽ

	HW_EXTI_Init(LIMIT_INT_PORTSOURCE,X_LIMIT_INT_PINSOURCE,X_LIMIT_INT_LINE,EXTI_Trigger_Falling);	//�͵�ƽ/�½��ش���
	HW_EXTI_Init(LIMIT_INT_PORTSOURCE,Y_LIMIT_INT_PINSOURCE,Y_LIMIT_INT_LINE,EXTI_Trigger_Falling);	//�͵�ƽ/�½��ش���
	HW_EXTI_Init(LIMIT_INT_PORTSOURCE,Z_LIMIT_INT_PINSOURCE,Z_LIMIT_INT_LINE,EXTI_Trigger_Falling);	//�͵�ƽ/�½��ش���

	HW_EXTI_Enable(LIMIT_INT_CHANNEL,2,3);	//ʹ���ж�

   	HW_EXTI_Disable(LIMIT_INT_CHANNEL,2,3);	//�����ж�

void EXTI9_5_IRQHandler(void)
{     
	//�жϴ���

	
	EXTI_ClearITPendingBit(RESET_INT_LINE|FEED_HOLD_INT_LINE|CYCLE_START_INT_LINE|SAFETY_DOOR_INT_LINE);  //����жϱ�־λ  
}

void EXTI15_10_IRQHandler(void)
{     
	if(0==HW_GPIO_Read(LIMIT_GPIO,X_LIMIT_GPIO_PIN))
	{

	}
	if(0==HW_GPIO_Read(LIMIT_GPIO,Y_LIMIT_GPIO_PIN))
	{

	}
	if(0==HW_GPIO_Read(LIMIT_GPIO,Z_LIMIT_GPIO_PIN))
	{

	}
	EXTI_ClearITPendingBit(X_LIMIT_INT_LINE|Y_LIMIT_INT_LINE|Z_LIMIT_INT_LINE);  //����жϱ�־λ
}





*/

#endif
