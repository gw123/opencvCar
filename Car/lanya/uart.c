#include "uart.h"
#include "interface.h"

//UART function
//UART3 TxD GPIOB10   RxD GPIOB11
void USART3Conf(u32 baudRate)
{
	NVIC_InitTypeDef 	NVIC_InitStruct;//����һ�������жϵĽṹ��	
	USART_InitTypeDef USART_InitSturct;//���崮��1�ĳ�ʼ���ṹ��
	GPIO_InitTypeDef GPIO_InitStruct;//���崮�ڶ�Ӧ�ܽŵĽṹ��

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3 , ENABLE);//�򿪴��ڹܽ�ʱ��
	//USART3_Tx_Pin Configure 
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;//�������
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;//��������ٶ�50MHz
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;//���츴�����
	GPIO_Init(GPIOB , &GPIO_InitStruct);//����ʼ���õĽṹ��װ��Ĵ���

//USART3_Rx_Pin Configure
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;//GPIOģʽ��������
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;//��������
  GPIO_Init(GPIOB, &GPIO_InitStruct);//����ʼ���õĽṹ��װ��Ĵ���

//USART3 Configure	
	USART_InitSturct.USART_BaudRate = baudRate;//������9600
	USART_InitSturct.USART_WordLength = USART_WordLength_8b;//���ݿ��8λ
	USART_InitSturct.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitSturct.USART_Parity = USART_Parity_No;//����żУ��
	USART_InitSturct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitSturct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//ʹ�ܷ��������
	USART_Init(USART3 , &USART_InitSturct);//����ʼ���õĽṹ��װ��Ĵ���	
	//USART1_INT Configure
	USART_ITConfig(USART3 , USART_IT_RXNE , ENABLE);//ʹ�ܽ����ж�
//	USART_ITConfig(USART3 , USART_IT_TXE , ENABLE);
	USART_Cmd(USART3 , ENABLE);//�򿪴���
	USART_ClearFlag(USART3 , USART_FLAG_TC);//�����һ�����ݷ���ʧ�ܵ�����
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;//�򿪸��ж�
	NVIC_Init(&NVIC_InitStruct);
	
}

void PutChar(u8 Data)
{
	USART_SendData(USART3 , Data);
	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);//�ȴ��������
}
void PutStr(char *str)//����һ���ַ���
{
	while(*str != '\0')
	{
		USART_SendData(USART3 , *str++);
		while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);//�ȴ��������
	}
}

void PutNChar(u8 *buf , u16 size)
{
  u8 i;
	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET); //��ֹ��һ�ֽڶ�ʧ
	for(i=0;i<size;i++)
	{
		 USART_SendData(USART3 , buf[i]);
		 while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);//�ȴ��������
	}
}



