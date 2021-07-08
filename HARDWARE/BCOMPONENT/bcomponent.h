#ifndef __BCOMPONENT_H
#define __BCOMPONENT_H
#include "sys.h"

#define FOCUS_T PFout(1)			// ����ת��
#define FOCUS_O PFout(2)			// ��������

#define ZOOM_T PFout(3)				// �䱶ת��
#define ZOOM_O PFout(4)				// �䱶����
#define ZOOM_ML PGout(0)			// �䱶����λ
#define ZOOM_MR PGout(1)			// �䱶����λ

#define BRIGHT_T PGout(10)			// ������ת��
#define BRIGHT_O PFout(0)			// �����ȷ���
#define BRIGHT_ML PGout(2)			// ����������λ
#define BRIGHT_MR PGout(3)			// ����������λ

#define CONTRAST_T PDout(5)			// �Աȶ�ת��
#define CONTRAST_O PFout(11)		// �Աȶȷ���
#define CONTRAST_ML PGout(4)		// �Աȶ�����λ
#define CONTRAST_MR PGout(5)		// �Աȶ�����λ

#define ALIGN PDout(11)				// ��׼
#define MEASURE PEout(11)			// ����

void BCOMPONENT_Init(void);			// ��ʼ��

#endif
