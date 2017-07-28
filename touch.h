#ifndef __TOUCH_H
#define __TOUCH_H

//---����ͷ�ļ�---//
#include<reg52.h>
#include<intrins.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//---������������---//
//12λ�ĵ�ѹֵ
typedef struct 
{
	uint x;
	uint y;
} XPT_XY;

extern XPT_XY xpt_xy;

//---����оƬ�����ֽ�---//
#define XPT_CMD_X	0xD0    //��ȡX�������
#define XPT_CMD_Y	0x90	//��ȡY�������

//---����ʹ�õ�IO��---//
sbit TOUCH_DOUT = P2^0;	  //���
sbit TOUCH_CLK  = P2^1;	  //ʱ��
sbit TOUCH_DIN  = P2^2;	  //����
sbit TOUCH_CS   = P2^3;	  //Ƭѡ
sbit TOUCH_PEN  = P2^4;	  //��ⴥ������Ӧ�ź�

//---����ȫ�ֺ���---//
void TOUCH_SPI_Start(void);	  //��ʼ
void TOUCH_SPI_Write(uchar dat); //д
uint TOUCH_SPI_Read(void);	 //��

uint TOUCH_XPT_ReadData(uchar cmd);	 //����ѹ����
//��x,yֵ�����Ǵ洢�ڷ���ֵ�����ֵ�洢����0��1
//x,y��ֵ�洢��ȫ�ֱ������棬��������Ϊuint��
uchar TOUCH_XPT_ReadXY(void);		 



#endif
