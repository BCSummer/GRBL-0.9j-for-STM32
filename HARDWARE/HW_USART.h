#ifndef __HW_USART_H
#define __HW_USART_H

//�˴����뽫ʵ�ִ��ڳ�ʼ����

//##############################��API��##############################
void HW_USART_Init(u32 bound);		//���ڳ�ʼ����bound�������ʣ�

/*
///////////////////////����Ĵ棺����ͨ�ײ����ֲ��GRBL///////////////////////

USART_ITConfig(USART1,USART_IT_TXE, ENABLE);//���������жϲ����̽��뷢�ͼĴ������ж�

void USART1_IRQHandler(void)		
{
	u8 data;
	if(USART_GetFlagStatus(USART1 , USART_IT_RXNE)!=RESET)		//���ռĴ����ǿ��ж�
	{
		data=USART_ReceiveData(USART1);		//��ȡ�ַ�
		USART_SendData(USART1, data);		//�����ַ�
	}
	if (USART_GetITStatus(USART1, USART_IT_TXE)!=RESET) 		//���ͼĴ������ж�
	{
		USART_SendData(USART1, 'a');						//�����ַ�
		USART_ITConfig(USART1, USART_IT_TXE, DISABLE);		//���ܷ����ж�
	}
}


*/
#endif
