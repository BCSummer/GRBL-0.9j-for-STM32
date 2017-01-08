#ifndef __HARDWARE_H
#define __HARDWARE_H


#include "stm32f10x.h"

//#####################����׼�⡿#####################
#include <string.h>	

//#####################���ײ㡿#####################
#include "delay.h"		//��ʱ
#include "HW_GPIO.h"	//GPIO
#include "HW_USART.h"	//����
#include "HW_TIM.h"		//��ʱ��
#include "HW_EXTI.h"	//�ⲿ�ж�
#include "HW_PWM.h"		//PWM
#include "HW_EEPROM.h"	//STM32��Flash��EEPROM


//#####################��������#####################
#define STM32_FLASH_WREN 		1              	//ʹ��FLASHд��(0����ʹ��; 1��ʹ��)
#define STM32_FLASH_SIZE 		64 	 			//��ѡSTM32��FLASH������С(��λΪK)

#define STM32_EEPROM_ADDR_START	0x0800FC00		//��ΪEEPROM����ʼ��ַ����ַ������ż����
#define STM32_EEPROM_ADDR_MAX	0x400			//EEPROM����(��λB)

//#####################���꡿#####################
#define cli()      __set_PRIMASK(1)   			//���жϹر�
#define sei()      __set_PRIMASK(0) 			//���жϿ���


#endif
