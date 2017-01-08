#ifndef __HW_GPIO_H
#define __HW_GPIO_H

//�˴����뽫ʵ��GPIO�Ĺ��ܿ��ƣ��������������ʼ�����������ŵ�ƽ�Ͷ�ȡ���ŵ�ƽ��

//##############################��API��##############################
void HW_GPIO_Init_Out(u32 gpio_clk,GPIO_TypeDef * gpio,u16 gpio_pin);	
void HW_GPIO_Init_In(u32 gpio_clk,GPIO_TypeDef * gpio,u16 gpio_pin);
void HW_GPIO_Write(GPIO_TypeDef * gpio,u16 gpio_pin,u8 val);
u8   HW_GPIO_Read(GPIO_TypeDef * gpio,u16 gpio_pin);




#endif
