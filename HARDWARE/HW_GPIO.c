#include "Hardware.h"

//�˴����뽫ʵ��GPIO�Ĺ��ܿ��ƣ�������ʼ�����������ŵ�ƽ�Ͷ�ȡ���ŵ�ƽ��
void HW_GPIO_Init_Out(u32 gpio_clk,GPIO_TypeDef * gpio,u16 gpio_pin)			
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(gpio_clk,ENABLE);	 			//ʹ�ܶ˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = gpio_pin;						//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 	//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 	//IO���ٶ�Ϊ50MHz
	GPIO_Init(gpio, &GPIO_InitStructure);					//�����趨������ʼ��
}

void HW_GPIO_Init_In(u32 gpio_clk,GPIO_TypeDef * gpio,u16 gpio_pin)			
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(gpio_clk,ENABLE);	 			//ʹ�ܶ˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = gpio_pin;						//�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 		//��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 	//IO���ٶ�Ϊ50MHz
	GPIO_Init(gpio, &GPIO_InitStructure);					//�����趨������ʼ��
}

void HW_GPIO_Write(GPIO_TypeDef * gpio,u16 gpio_pin,u8 val)
{
	if(val==0) GPIO_ResetBits(gpio,gpio_pin);				//��������͵�ƽ
	else GPIO_SetBits(gpio,gpio_pin);						//��������ߵ�ƽ
}

u8 HW_GPIO_Read(GPIO_TypeDef * gpio,u16 gpio_pin)
{
	return GPIO_ReadInputDataBit(gpio,gpio_pin);			//�������ŵ�ƽ
}



