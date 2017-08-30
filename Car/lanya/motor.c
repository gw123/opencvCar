#include "motor.h"
#include "interface.h"
#include "stm32f10x.h"

//GPIO���ú���
void MotorGPIO_Configuration(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_F_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_Init(FRONT_LEFT_F_GPIO, &GPIO_InitStructure);    
	
	GPIO_InitStructure.GPIO_Pin = FRONT_LEFT_B_PIN;	
	GPIO_Init(FRONT_LEFT_B_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_F_PIN;	
	GPIO_Init(FRONT_RIGHT_F_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = FRONT_RIGHT_B_PIN;	
	GPIO_Init(FRONT_RIGHT_B_GPIO, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_LEFT_F_PIN;	
	GPIO_Init(BEHIND_LEFT_F_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_LEFT_B_PIN;	
	GPIO_Init(BEHIND_LEFT_B_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_RIGHT_F_PIN;	
	GPIO_Init(BEHIND_RIGHT_F_GPIO, &GPIO_InitStructure);  
	
	GPIO_InitStructure.GPIO_Pin = BEHIND_RIGHT_B_PIN;	
	GPIO_Init(BEHIND_RIGHT_B_GPIO, &GPIO_InitStructure);  
	
}

//    ֵ    ����     �ٶ�      
//    1    ǰ��      SPEED_DUTY
//    2    ����ǰ��  SPEED_DUTY+10
//    3    ����ǰ��  SPEED_DUTY-10

//    4    ����      SPEED_DUTY
//    5    ���ٺ���  SPEED_DUTY-10

#define V_FRONT    1
#define V_FRONT1   2
#define V_FRONT2   3
#define V_BACK     4
#define V_BACK1    5

//����ռ�ձ��������ת��
void CarMove(void)
{   
  //��ǰ��
	if(front_left_speed_duty==V_FRONT)//��ǰ
	{
		if(speed_count < SPEED_DUTY)
		{
			FRONT_LEFT_GO;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else if(front_left_speed_duty==V_FRONT1)
	{
		if(speed_count < SPEED_DUTY+10)
		{
			FRONT_LEFT_GO;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else if(front_left_speed_duty==V_FRONT2)
	{
		if(speed_count < SPEED_DUTY-10)
		{
			FRONT_LEFT_GO;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else if(front_left_speed_duty==V_BACK)//���
	{
		if(speed_count < SPEED_DUTY)
		{
			FRONT_LEFT_BACK;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else if(front_left_speed_duty==V_BACK1)//���
	{
		if(speed_count < SPEED_DUTY-10)
		{
			FRONT_LEFT_BACK;
		}else
		{
			FRONT_LEFT_STOP;
		}
	}
	else                //ֹͣ
	{
		FRONT_LEFT_STOP;
	}
	
	
	//��ǰ��
	if(front_right_speed_duty==V_FRONT)//��ǰ
	{
		if(speed_count < SPEED_DUTY)
		{
			FRONT_RIGHT_GO;
		}else
		{
			FRONT_RIGHT_STOP;
		}
	}
	else if(front_right_speed_duty==V_FRONT1)
	{
		if(speed_count < SPEED_DUTY+10)
		{
			FRONT_RIGHT_GO;
		}else
		{
			FRONT_RIGHT_STOP;
		}
	}
	else if(front_right_speed_duty==V_FRONT2)
	{
		if(speed_count < SPEED_DUTY-10)
		{
			FRONT_RIGHT_GO;
		}else
		{
			FRONT_RIGHT_STOP;
		}
	}
	else if(front_right_speed_duty==V_BACK)//���
	{
		if(speed_count < SPEED_DUTY)
		{
			FRONT_RIGHT_BACK;
		}else
		{
			FRONT_RIGHT_STOP;
		}
	}
	else if(front_right_speed_duty==V_BACK1)//���
	{
		if(speed_count < SPEED_DUTY-10)
		{
			FRONT_RIGHT_BACK;
		}else
		{
			FRONT_RIGHT_STOP;
		}
	}
	else                //ֹͣ
	{
		FRONT_RIGHT_STOP;
	}
	
	
	 //�����
	if(behind_left_speed_duty==V_FRONT)//��ǰ
	{
		if(speed_count < SPEED_DUTY)
		{
			BEHIND_LEFT_GO;
		}else
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty==V_FRONT1)
	{
		if(speed_count < SPEED_DUTY+10)
		{
			BEHIND_LEFT_GO;
		}else
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty==V_FRONT2)
	{
		if(speed_count < SPEED_DUTY-10)
		{
			BEHIND_LEFT_GO;
		}else
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty==V_BACK)//���
	{
		if(speed_count < SPEED_DUTY)
		{
			BEHIND_LEFT_BACK;
		}else
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty==V_BACK1)//���
	{
		if(speed_count < SPEED_DUTY-10)
		{
			BEHIND_LEFT_BACK;
		}else
		{
			BEHIND_LEFT_STOP;
		}
	}
	else                //ֹͣ
	{
		BEHIND_LEFT_STOP;
	}
	
	
	//�Һ���
	if(behind_right_speed_duty==V_FRONT)//��ǰ
	{
		if(speed_count < SPEED_DUTY)
		{
			BEHIND_RIGHT_GO;
		}else
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else if(behind_right_speed_duty==V_FRONT1)
	{
		if(speed_count < SPEED_DUTY+10)
		{
			BEHIND_RIGHT_GO;
		}else
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else if(behind_right_speed_duty==V_FRONT2)
	{
		if(speed_count < SPEED_DUTY-10)
		{
			BEHIND_RIGHT_GO;
		}else
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else if(behind_right_speed_duty==V_BACK)//���
	{
		if(speed_count < SPEED_DUTY)
		{
		 BEHIND_RIGHT_BACK;
		}else
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else if(behind_right_speed_duty==V_BACK1)//���
	{
		if(speed_count < SPEED_DUTY-10)
		{
			BEHIND_RIGHT_BACK;
		}else
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else                //ֹͣ
	{
	 BEHIND_RIGHT_STOP;	
	}
	
	/*
	//�����
	if(behind_left_speed_duty > 0)//��ǰ
	{
		if(speed_count < behind_left_speed_duty)
		{
			BEHIND_LEFT_GO;
		}	else                //ֹͣ
		{
			BEHIND_LEFT_STOP;
		}
	}
	else if(behind_left_speed_duty < 0)//���
	{
		if(speed_count < (-1)*behind_left_speed_duty)
		{
			BEHIND_LEFT_BACK;
		}	else                //ֹͣ
		{
			BEHIND_LEFT_STOP;
		}
	}
	else                //ֹͣ
	{
		BEHIND_LEFT_STOP;
	}
	
		//�Һ���
	if(behind_right_speed_duty > 0)//��ǰ
	{
		if(speed_count < behind_right_speed_duty)
		{
			BEHIND_RIGHT_GO;
		}	else                //ֹͣ
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else if(behind_right_speed_duty < 0)//���
	{
		if(speed_count < (-1)*behind_right_speed_duty)
		{
			BEHIND_RIGHT_BACK;
		}	else                //ֹͣ
		{
			BEHIND_RIGHT_STOP;
		}
	}
	else                //ֹͣ
	{
		BEHIND_RIGHT_STOP;
	}
	
	*/
}


void CarGo(void)
{
	front_left_speed_duty=V_FRONT;
	front_right_speed_duty=V_FRONT;
	behind_left_speed_duty=V_FRONT;
	behind_right_speed_duty=V_FRONT;
}

//����
void CarBack(void)
{
	front_left_speed_duty=V_BACK;
	front_right_speed_duty=V_BACK;
	behind_left_speed_duty=V_BACK;
	behind_right_speed_duty=V_BACK;
}

//����
void CarLeft(void)
{
	front_left_speed_duty=V_BACK1;
	front_right_speed_duty=V_FRONT;
	behind_left_speed_duty=V_BACK1;
	behind_right_speed_duty=V_FRONT1;//���Ӻ���������
}

//����
void CarRight(void)
{
	front_left_speed_duty=V_FRONT;
	front_right_speed_duty=V_BACK1;
	behind_left_speed_duty=V_FRONT1;//���Ӻ���������
	behind_right_speed_duty=V_BACK1;
}

//ֹͣ
void CarStop(void)
{
	front_left_speed_duty=0;
	front_right_speed_duty=0;
	behind_left_speed_duty=0;
	behind_right_speed_duty=0;
}

void MotorInit(void)
{
	MotorGPIO_Configuration();
	CarStop();
}

