#include "bcomponent.h"

void BCOMPONENT_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF | RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			// ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// �������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		// 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// ����
	GPIO_Init(GPIOF, &GPIO_InitStructure);					// ��ʼ��GPIO
	GPIO_SetBits(GPIOF, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_11);
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			// ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// �������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		// 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// ����
	GPIO_Init(GPIOG, &GPIO_InitStructure);					// ��ʼ��GPIO
	GPIO_SetBits(GPIOG, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_10);
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			// ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// �������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		// 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// ����
	GPIO_Init(GPIOD, &GPIO_InitStructure);					// ��ʼ��GPIO
	GPIO_SetBits(GPIOD, GPIO_Pin_5 | GPIO_Pin_11);
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;			// ��ͨ���ģʽ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			// �������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;		// 100MHz
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			// ����
	GPIO_Init(GPIOE, &GPIO_InitStructure);					// ��ʼ��GPIO
	GPIO_SetBits(GPIOE, GPIO_Pin_11);
}