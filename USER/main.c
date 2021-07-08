#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sys.h"
#include "delay.h"

#include "usart.h"
#include "hc05.h" 	 
#include "usart3.h" 
#include "bcomponent.h"

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		// ����ϵͳ�ж����ȼ�����2
	delay_init(168);				// ��ʱ��ʼ�� 
	
	uart_init(9600);				// ��ʼ������
	BCOMPONENT_Init();				// ��ʼ���Զ�������
	
	while ( HC05_Init() ) 			// ��ʼ��HC05����ģ��
	{
		delay_ms(100);
		printf("������ʼ����...\r\n");
	}
	
	while(1)
	{
		// ����
		if( USART3_RX_STA & 0X8000 )
		{
			u8 len = USART3_RX_STA & 0X7FFF;
				
			// ��������ť - ����
			if ( USART3_RX_BUF[0] == '1' ) {
				FOCUS_O = 1;		// ������������ΪĬ�Ϸ���
				FOCUS_T = 0;		// ���������ʼת��
				u3_printf("Focus - reduce pressed !\r\n");
			}
				
			// ��������ť - ̧��
			if ( USART3_RX_BUF[0] == '2' ) {
				FOCUS_O = 1;		// ������������ΪĬ�Ϸ���
				FOCUS_T = 1;		// �������ֹͣת��
				u3_printf("Focus - reduce released !\r\n");
			}
					
			// ��������ť - ����
			if ( USART3_RX_BUF[0] == '3' ) {
				FOCUS_O = 0;		// ������������Ϊ�෴����
				FOCUS_T = 0;		// ���������ʼת��
				u3_printf("Focus - increase pressed !\r\n");
			}
				
			// ��������ť - ̧��
			if ( USART3_RX_BUF[0] == '4' ) {
				FOCUS_O = 1;		// ������������ΪĬ�Ϸ���
				FOCUS_T = 1;		// �������ֹͣת��
				u3_printf("Focus - increase released !\r\n");
			}
				
			// �䱶����ť - ����
			if ( USART3_RX_BUF[0] == '5' ) {
				ZOOM_O = 1;			// �䱶��������ΪĬ�Ϸ���
				ZOOM_T = 0;			// �䱶�����ʼת��
				u3_printf("Zoom - reduce pressed !\r\n");
			}
				
			// �䱶����ť - ̧��
			if ( USART3_RX_BUF[0] == '6' ) {
				ZOOM_O = 1;			// �䱶��������ΪĬ�Ϸ���
				ZOOM_T = 1;			// �䱶���ֹͣת��
				u3_printf("Zoom - reduce released !\r\n");
			}
					
			//  �䱶����ť - ����
			if ( USART3_RX_BUF[0] == '7' ) {
				ZOOM_O = 0;			// �䱶��������Ϊ�෴����
				ZOOM_T = 0;			// �䱶�����ʼת��
				u3_printf("Zoom - increase pressed !\r\n");
			}
				
			//  �䱶����ť - ̧��
			if ( USART3_RX_BUF[0] == '8' ) {
				ZOOM_O = 1;			// �䱶��������ΪĬ�Ϸ���
				ZOOM_T = 1;			// �䱶���ֹͣת��
				u3_printf("Zoom - increase released !\r\n");
			}

			// �Աȶ�
			if ( USART3_RX_BUF[0] == 'a' ) {
				// �ȸ�����λȷ��λ�ã���ת����һ��λ��
				u3_printf("Contrast !\r\n");
			}
				
			// ��׼
			if ( USART3_RX_BUF[0] == 'b' ) {
				// �����źŸ���λ�����򿪶�׼���
				u3_printf("Align !\r\n");
				printf("8");
			}
				
			// ����
			if ( USART3_RX_BUF[0] == 'c' ) {
				// �����źŸ���λ������������
				u3_printf("Measure !\r\n");
				printf("9");
			}
				
			/*
			USART3_RX_BUF[len] = 0;							// �ӽ�����
			printf("Bluetooth: %s\r\n", USART3_RX_BUF);		// �������ݵ���λ��
			*/
				
			USART3_RX_STA = 0;
		}
			
		// ����
		if ( USART_RX_STA & 0x8000 )
		{
			u8 len = USART_RX_STA & 0x3fff;	// �õ��˴ν��յ������ݳ���
				
			if ( USART_RX_BUF[0] == 'a' )
			{
				FOCUS_O = 1;		// ������������ΪĬ�Ϸ���
				FOCUS_T = 0;		// ���������ʼת��
				printf("Focus - reduce pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'b' )
			{
				FOCUS_O = 1;		// ������������ΪĬ�Ϸ���
				FOCUS_T = 1;		// �������ֹͣת��
				printf("Focus - reduce released !");
			}
				
			if ( USART_RX_BUF[0] == 'c' )
			{
				FOCUS_O = 0;		// ������������Ϊ�෴����
				FOCUS_T = 0;		// ���������ʼת��
				printf("Focus - increase pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'd' )
			{
				FOCUS_O = 1;		// ������������ΪĬ�Ϸ���
				FOCUS_T = 1;		// �������ֹͣת��
				printf("Focus - increase released !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == 'e' )
			{
				ZOOM_O = 1;			// �䱶��������ΪĬ�Ϸ���
				ZOOM_T = 0;			// �䱶�����ʼת��
				printf("Zoom - reduce pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'f' )
			{
				ZOOM_O = 1;			// �䱶��������ΪĬ�Ϸ���
				ZOOM_T = 1;			// �䱶���ֹͣת��
				printf("Zoom - reduce released !");
			}
				
			if ( USART_RX_BUF[0] == 'g' )
			{
				ZOOM_O = 0;			// �䱶��������Ϊ�෴����
				ZOOM_T = 0;			// �䱶�����ʼת��
				printf("Zoom - increase pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'h' )
			{
				ZOOM_O = 1;			// �䱶��������ΪĬ�Ϸ���
				ZOOM_T = 1;			// �䱶���ֹͣת��
				printf("Zoom - increase released !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == 'i' )
			{
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				printf("Bright - reduce pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'j' )
			{
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
				printf("Bright - reduce released !");
			}
				
			if ( USART_RX_BUF[0] == 'k' )
			{
				BRIGHT_O = 0;		// �����ȵ�������Ϊ�෴����
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				printf("Bright - increase pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'l' )
			{
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
				printf("Bright - increase released !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == 'm' )
			{
				CONTRAST_O = 1;		// �Աȶȵ�������ΪĬ�Ϸ���
				CONTRAST_T = 0;		// �Աȶȵ����ʼת��
				delay_ms(500);		// ת��ʱ��
				CONTRAST_T = 1;		// �Աȶȵ��ֹͣת��
					
				printf("Contrast - reduce !");
			}
				
			if ( USART_RX_BUF[0] == 'n' )
			{
				CONTRAST_O = 0;		// �Աȶȵ�������Ϊ�෴����
				CONTRAST_T = 0;		// �Աȶȵ����ʼת��
				delay_ms(500);		// ת��ʱ��
				CONTRAST_T = 1;		// �Աȶȵ��ֹͣת��
				CONTRAST_O = 1;		// �Աȶȵ�������ΪĬ�Ϸ���
					
				printf("Contrast - increase !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == '1' )
			{
				BRIGHT_O = 0;		// �����ȵ�������Ϊ�෴����
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				delay_ms(50);
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
					
				printf("Bright - increase 1 !");
			}
				
			if ( USART_RX_BUF[0] == '2' )
			{
				BRIGHT_O = 0;		// �����ȵ�������Ϊ�෴����
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				delay_ms(100);
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
					
				printf("Bright - increase 2 !");
			}
				
			if ( USART_RX_BUF[0] == '3' )
			{
				BRIGHT_O = 0;		// �����ȵ�������Ϊ�෴����
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				delay_ms(150);
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
					
				printf("Bright - increase 3 !");
			}
				
			if ( USART_RX_BUF[0] == '4' )
			{
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				delay_ms(50);
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
					
				printf("Bright - reduce 1 !");
			}
				
			if ( USART_RX_BUF[0] == '5' )
			{
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				delay_ms(100);
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
					
				printf("Bright - reduce 2 !");
			}
				
			if ( USART_RX_BUF[0] == '6' )
			{
				BRIGHT_O = 1;		// �����ȵ�������ΪĬ�Ϸ���
				BRIGHT_T = 0;		// �����ȵ����ʼת��
				delay_ms(150);
				BRIGHT_T = 1;		// �����ȵ��ֹͣת��
					
				printf("Bright - reduce 3 !");
			}
				
			/*
			printf("Com:  ");
			for ( u8 t = 0; t < len; ++t )
			{
				USART_SendData(USART1, USART_RX_BUF[t]);         			// �������ݵ���λ��
				while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);	// �ȴ����ͽ���
			}
			printf("\r\n");	// ���뻻��
			*/
				
			USART_RX_STA = 0;
		}

		delay_ms(10);
	}
}
