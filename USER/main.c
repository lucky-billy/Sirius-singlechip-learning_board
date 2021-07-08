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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		// 设置系统中断优先级分组2
	delay_init(168);				// 延时初始化 
	
	uart_init(9600);				// 初始化串口
	BCOMPONENT_Init();				// 初始化自定义引脚
	
	while ( HC05_Init() ) 			// 初始化HC05蓝牙模块
	{
		delay_ms(100);
		printf("蓝牙初始化中...\r\n");
	}
	
	while(1)
	{
		// 蓝牙
		if( USART3_RX_STA & 0X8000 )
		{
			u8 len = USART3_RX_STA & 0X7FFF;
				
			// 调焦左旋钮 - 按下
			if ( USART3_RX_BUF[0] == '1' ) {
				FOCUS_O = 1;		// 调焦电机方向变为默认方向
				FOCUS_T = 0;		// 调焦电机开始转动
				u3_printf("Focus - reduce pressed !\r\n");
			}
				
			// 调焦左旋钮 - 抬起
			if ( USART3_RX_BUF[0] == '2' ) {
				FOCUS_O = 1;		// 调焦电机方向变为默认方向
				FOCUS_T = 1;		// 调焦电机停止转动
				u3_printf("Focus - reduce released !\r\n");
			}
					
			// 调焦右旋钮 - 按下
			if ( USART3_RX_BUF[0] == '3' ) {
				FOCUS_O = 0;		// 调焦电机方向变为相反方向
				FOCUS_T = 0;		// 调焦电机开始转动
				u3_printf("Focus - increase pressed !\r\n");
			}
				
			// 调焦右旋钮 - 抬起
			if ( USART3_RX_BUF[0] == '4' ) {
				FOCUS_O = 1;		// 调焦电机方向变为默认方向
				FOCUS_T = 1;		// 调焦电机停止转动
				u3_printf("Focus - increase released !\r\n");
			}
				
			// 变倍左旋钮 - 按下
			if ( USART3_RX_BUF[0] == '5' ) {
				ZOOM_O = 1;			// 变倍电机方向变为默认方向
				ZOOM_T = 0;			// 变倍电机开始转动
				u3_printf("Zoom - reduce pressed !\r\n");
			}
				
			// 变倍左旋钮 - 抬起
			if ( USART3_RX_BUF[0] == '6' ) {
				ZOOM_O = 1;			// 变倍电机方向变为默认方向
				ZOOM_T = 1;			// 变倍电机停止转动
				u3_printf("Zoom - reduce released !\r\n");
			}
					
			//  变倍右旋钮 - 按下
			if ( USART3_RX_BUF[0] == '7' ) {
				ZOOM_O = 0;			// 变倍电机方向变为相反方向
				ZOOM_T = 0;			// 变倍电机开始转动
				u3_printf("Zoom - increase pressed !\r\n");
			}
				
			//  变倍右旋钮 - 抬起
			if ( USART3_RX_BUF[0] == '8' ) {
				ZOOM_O = 1;			// 变倍电机方向变为默认方向
				ZOOM_T = 1;			// 变倍电机停止转动
				u3_printf("Zoom - increase released !\r\n");
			}

			// 对比度
			if ( USART3_RX_BUF[0] == 'a' ) {
				// 先根据限位确定位置，再转到另一个位置
				u3_printf("Contrast !\r\n");
			}
				
			// 对准
			if ( USART3_RX_BUF[0] == 'b' ) {
				// 发送信号给上位机，打开对准相机
				u3_printf("Align !\r\n");
				printf("8");
			}
				
			// 测量
			if ( USART3_RX_BUF[0] == 'c' ) {
				// 发送信号给上位机，启动测量
				u3_printf("Measure !\r\n");
				printf("9");
			}
				
			/*
			USART3_RX_BUF[len] = 0;							// 加结束符
			printf("Bluetooth: %s\r\n", USART3_RX_BUF);		// 发送数据到上位机
			*/
				
			USART3_RX_STA = 0;
		}
			
		// 串口
		if ( USART_RX_STA & 0x8000 )
		{
			u8 len = USART_RX_STA & 0x3fff;	// 得到此次接收到的数据长度
				
			if ( USART_RX_BUF[0] == 'a' )
			{
				FOCUS_O = 1;		// 调焦电机方向变为默认方向
				FOCUS_T = 0;		// 调焦电机开始转动
				printf("Focus - reduce pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'b' )
			{
				FOCUS_O = 1;		// 调焦电机方向变为默认方向
				FOCUS_T = 1;		// 调焦电机停止转动
				printf("Focus - reduce released !");
			}
				
			if ( USART_RX_BUF[0] == 'c' )
			{
				FOCUS_O = 0;		// 调焦电机方向变为相反方向
				FOCUS_T = 0;		// 调焦电机开始转动
				printf("Focus - increase pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'd' )
			{
				FOCUS_O = 1;		// 调焦电机方向变为默认方向
				FOCUS_T = 1;		// 调焦电机停止转动
				printf("Focus - increase released !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == 'e' )
			{
				ZOOM_O = 1;			// 变倍电机方向变为默认方向
				ZOOM_T = 0;			// 变倍电机开始转动
				printf("Zoom - reduce pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'f' )
			{
				ZOOM_O = 1;			// 变倍电机方向变为默认方向
				ZOOM_T = 1;			// 变倍电机停止转动
				printf("Zoom - reduce released !");
			}
				
			if ( USART_RX_BUF[0] == 'g' )
			{
				ZOOM_O = 0;			// 变倍电机方向变为相反方向
				ZOOM_T = 0;			// 变倍电机开始转动
				printf("Zoom - increase pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'h' )
			{
				ZOOM_O = 1;			// 变倍电机方向变为默认方向
				ZOOM_T = 1;			// 变倍电机停止转动
				printf("Zoom - increase released !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == 'i' )
			{
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				printf("Bright - reduce pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'j' )
			{
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
				BRIGHT_T = 1;		// 明亮度电机停止转动
				printf("Bright - reduce released !");
			}
				
			if ( USART_RX_BUF[0] == 'k' )
			{
				BRIGHT_O = 0;		// 明亮度电机方向变为相反方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				printf("Bright - increase pressed !");
			}
				
			if ( USART_RX_BUF[0] == 'l' )
			{
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
				BRIGHT_T = 1;		// 明亮度电机停止转动
				printf("Bright - increase released !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == 'm' )
			{
				CONTRAST_O = 1;		// 对比度电机方向变为默认方向
				CONTRAST_T = 0;		// 对比度电机开始转动
				delay_ms(500);		// 转动时长
				CONTRAST_T = 1;		// 对比度电机停止转动
					
				printf("Contrast - reduce !");
			}
				
			if ( USART_RX_BUF[0] == 'n' )
			{
				CONTRAST_O = 0;		// 对比度电机方向变为相反方向
				CONTRAST_T = 0;		// 对比度电机开始转动
				delay_ms(500);		// 转动时长
				CONTRAST_T = 1;		// 对比度电机停止转动
				CONTRAST_O = 1;		// 对比度电机方向变为默认方向
					
				printf("Contrast - increase !");
			}
				
			//------------------------------------------------------------------------------
				
			if ( USART_RX_BUF[0] == '1' )
			{
				BRIGHT_O = 0;		// 明亮度电机方向变为相反方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				delay_ms(50);
				BRIGHT_T = 1;		// 明亮度电机停止转动
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
					
				printf("Bright - increase 1 !");
			}
				
			if ( USART_RX_BUF[0] == '2' )
			{
				BRIGHT_O = 0;		// 明亮度电机方向变为相反方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				delay_ms(100);
				BRIGHT_T = 1;		// 明亮度电机停止转动
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
					
				printf("Bright - increase 2 !");
			}
				
			if ( USART_RX_BUF[0] == '3' )
			{
				BRIGHT_O = 0;		// 明亮度电机方向变为相反方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				delay_ms(150);
				BRIGHT_T = 1;		// 明亮度电机停止转动
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
					
				printf("Bright - increase 3 !");
			}
				
			if ( USART_RX_BUF[0] == '4' )
			{
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				delay_ms(50);
				BRIGHT_T = 1;		// 明亮度电机停止转动
					
				printf("Bright - reduce 1 !");
			}
				
			if ( USART_RX_BUF[0] == '5' )
			{
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				delay_ms(100);
				BRIGHT_T = 1;		// 明亮度电机停止转动
					
				printf("Bright - reduce 2 !");
			}
				
			if ( USART_RX_BUF[0] == '6' )
			{
				BRIGHT_O = 1;		// 明亮度电机方向变为默认方向
				BRIGHT_T = 0;		// 明亮度电机开始转动
				delay_ms(150);
				BRIGHT_T = 1;		// 明亮度电机停止转动
					
				printf("Bright - reduce 3 !");
			}
				
			/*
			printf("Com:  ");
			for ( u8 t = 0; t < len; ++t )
			{
				USART_SendData(USART1, USART_RX_BUF[t]);         			// 发送数据到上位机
				while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);	// 等待发送结束
			}
			printf("\r\n");	// 插入换行
			*/
				
			USART_RX_STA = 0;
		}

		delay_ms(10);
	}
}
