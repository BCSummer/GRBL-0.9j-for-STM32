
/* GRBL_stm32f10xϵ�е����������ļ�  */

#ifdef GRBL_PLATFORM
#error "cpu_map already defined: GRBL_PLATFORM=" GRBL_PLATFORM
#endif

// Define step pulse output pins. NOTE: All step bit pins must be on the same port.
//���岽������������š�ע�����еĲ����������ű��붨����ͬһ���˿��ϡ�
#define STEP_GPIO_CLK 				RCC_APB2Periph_GPIOB	//����ʱ��
#define	STEP_GPIO					GPIOB					//�˿�
#define	X_STEP_GPIO_PIN				GPIO_Pin_5				//����
#define	Y_STEP_GPIO_PIN				GPIO_Pin_6			   	//����
#define	Z_STEP_GPIO_PIN				GPIO_Pin_7				//����
//ԭƽ̨���䣬�ɲ����޸ġ�
#define X_STEP_BIT      			2  
#define Y_STEP_BIT      			3  
#define Z_STEP_BIT      			4  
#define STEP_MASK       			((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) 	



// Define step direction output pins. NOTE: All direction pins must be on the same port.
//���巽���ƽ������š�ע�����еķ������ű��붨����ͬһ���˿��ϡ�
#define DIRECTION_GPIO_CLK 				RCC_APB2Periph_GPIOB	//����ʱ��
#define	DIRECTION_GPIO					GPIOB					//�˿�
#define	X_DIRECTION_GPIO_PIN			GPIO_Pin_8				//����
#define	Y_DIRECTION_GPIO_PIN			GPIO_Pin_9			   	//����
#define	Z_DIRECTION_GPIO_PIN			GPIO_Pin_10				//����
//ԭƽ̨���䣬�ɲ����޸ġ�
#define X_DIRECTION_BIT   				5  
#define Y_DIRECTION_BIT   				6  
#define Z_DIRECTION_BIT   				7  
#define DIRECTION_MASK    				((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT))


// Define stepper driver enable/disable output pin.
//���岽�����������ʹ������
#define STEPPERS_DISABLE_GPIO_CLK		RCC_APB2Periph_GPIOB	//����ʱ��
#define STEPPERS_DISABLE_GPIO   		GPIOB					//�˿�
#define STEPPERS_DISABLE_GPIO_PIN		GPIO_Pin_11				//����
//ԭƽ̨���䣬�ɲ����޸ġ�
#define STEPPERS_DISABLE_BIT    		0  
#define STEPPERS_DISABLE_MASK   		(1<<STEPPERS_DISABLE_BIT)



// Define homing/hard limit switch input pins and limit interrupt vectors. 
//����ԭ��/Ӳ��λ�����������ź���λ�ж�����
//ע�⣺���е���λ���ű���ʹ��ͬһ���жϴ�������
#define LIMIT_GPIO_CLK 				RCC_APB2Periph_GPIOA	//����ʱ��
#define	LIMIT_GPIO					GPIOA					//�˿�
#define	X_LIMIT_GPIO_PIN			GPIO_Pin_11				//����
#define Y_LIMIT_GPIO_PIN			GPIO_Pin_12			   	//����
#define	Z_LIMIT_GPIO_PIN			GPIO_Pin_15				//����

#define LIMIT_INT_PORTSOURCE 		GPIO_PortSourceGPIOA 	//�ж�Դ�˿�
#define X_LIMIT_INT_PINSOURCE		GPIO_PinSource11	   	//�ж�Դ����
#define Y_LIMIT_INT_PINSOURCE		GPIO_PinSource12		//�ж�Դ����
#define Z_LIMIT_INT_PINSOURCE		GPIO_PinSource15		//�ж�Դ����
#define X_LIMIT_INT_LINE			EXTI_Line11				//�ж���
#define Y_LIMIT_INT_LINE			EXTI_Line12				//�ж���
#define Z_LIMIT_INT_LINE			EXTI_Line15				//�ж���

#define LIMIT_INT_CHANNEL			EXTI15_10_IRQn			//�ж�����ͨ��
//ע�⣺�жϴ��������ڴ������޸�

//ԭƽ̨���䣬�ɲ����޸ġ�
#define X_LIMIT_BIT      1  
#define Y_LIMIT_BIT      2 
#define Z_LIMIT_BIT    	 3 
#define LIMIT_MASK       ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits



// Define spindle enable and spindle direction output pins.
//��������ʹ���������
#define SPINDLE_ENABLE_GPIO_CLK			RCC_APB2Periph_GPIOA	//����ʱ��
#define SPINDLE_ENABLE_GPIO   			GPIOA					//�˿�
#define SPINDLE_ENABLE_GPIO_PIN			GPIO_Pin_1				//����
//�������᷽���������
#define SPINDLE_DIRECTION_GPIO_CLK		RCC_APB2Periph_GPIOA	//����ʱ��
#define SPINDLE_DIRECTION_GPIO   		GPIOA					//�˿�
#define SPINDLE_DIRECTION_GPIO_PIN		GPIO_Pin_2				//����

// Start of PWM & Stepper Enabled Spindle
//����PWM��������
#ifdef VARIABLE_SPINDLE 
  #define SPINDLE_PWM_GPIO_CLK		RCC_APB2Periph_GPIOA	//����ʱ��
  #define SPINDLE_PWM_GPIO   		GPIOA					//�˿�
  #define SPINDLE_PWM_GPIO_PIN		GPIO_Pin_0				//����
  
  #define PWM_MAX_VALUE       		65535.0					//PWM�������ֵ
//�Ķ�Դ�ļ�spindle_control.c��֪PWM���ֵΪ0xffff��65535��

  #define PWM_TIMER					TIM2					//PWM����ʱ��
  #define PWM_CLK 					RCC_APB1Periph_TIM2		//����ʱ��
  //ע�⣺OC1Init()��TIM_OC1PreloadConfig()���ض�ͨ���������ڴ������޸�

#endif // End of VARIABLE_SPINDLE

  
// Define flood and mist coolant enable output pins.
//��������ȴ������ȴʹ���������
#define COOLANT_FLOOD_GPIO_CLK		RCC_APB2Periph_GPIOB	//����ʱ��
#define COOLANT_FLOOD_GPIO   		GPIOB					//�˿�
#define COOLANT_FLOOD_GPIO_PIN		GPIO_Pin_3				//����

#ifdef ENABLE_M7 
// Mist coolant disabled by default. See config.h to enable/disable.
//����ȴĬ�Ϲرա��鿴config.h�ļ�����
  #define COOLANT_MIST_GPIO_CLK		RCC_APB2Periph_GPIOB	//����ʱ��
  #define COOLANT_MIST_GPIO   		GPIOB					//�˿�
  #define COOLANT_MIST_GPIO_PIN		GPIO_Pin_4				//����

#endif  


// Define user-control controls (cycle start, reset, feed hold) input pins.
//�����û����ƣ�ѭ����ʼ����λ���������֣���������
//ע�⣺���е���λ���ű���ʹ��ͬһ���жϴ�������
#define CONTROL_GPIO_CLK 				RCC_APB2Periph_GPIOA	//����ʱ��
#define	CONTROL_GPIO					GPIOA					//�˿�
#define	RESET_GPIO_PIN					GPIO_Pin_5				//����
#define FEED_HOLD_GPIO_PIN				GPIO_Pin_6			   	//����
#define	CYCLE_START_GPIO_PIN			GPIO_Pin_7				//����
#define	SAFETY_DOOR_GPIO_PIN			GPIO_Pin_8				//����

#define CONTROL_INT_PORTSOURCE 		GPIO_PortSourceGPIOA 	//�ж�Դ�˿�
#define RESET_INT_PINSOURCE			GPIO_PinSource5			//�ж�Դ���ţ���λ
#define FEED_HOLD_INT_PINSOURCE		GPIO_PinSource6			//�ж�Դ���ţ���������
#define CYCLE_START_INT_PINSOURCE	GPIO_PinSource7			//�ж�Դ���ţ�ѭ����ʼ
#define SAFETY_DOOR_INT_PINSOURCE	GPIO_PinSource8			//�ж�Դ���ţ�����ͣ��
#define RESET_INT_LINE				EXTI_Line5				//�ж��ߣ���λ
#define FEED_HOLD_INT_LINE			EXTI_Line6				//�ж��ߣ���������
#define CYCLE_START_INT_LINE		EXTI_Line7				//�ж��ߣ�ѭ����ʼ
#define SAFETY_DOOR_INT_LINE		EXTI_Line8				//�ж��ߣ�����ͣ��

#define CONTROL_INT_CHANNEL			EXTI9_5_IRQn			//�ж�����ͨ��
//ע�⣺�жϴ��������ڴ������޸�

//ԭƽ̨���䣬�ɲ����޸ġ�
#define RESET_BIT         0 
#define FEED_HOLD_BIT     1  
#define CYCLE_START_BIT   2  
#define SAFETY_DOOR_BIT   3  
#define CONTROL_MASK ((1<<RESET_BIT)|(1<<FEED_HOLD_BIT)|(1<<CYCLE_START_BIT)|(1<<SAFETY_DOOR_BIT))
#define CONTROL_INVERT_MASK CONTROL_MASK   



// Define probe switch input pin.
//����̽�⿪����������
#define PROBE_GPIO_CLK		RCC_APB2Periph_GPIOA	//����ʱ��
#define PROBE_GPIO   		GPIOA					//�˿�
#define PROBE_GPIO_PIN		GPIO_Pin_4				//����

















