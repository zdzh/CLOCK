#ifndef _GUI_H_
#define _GUI_H_

//---����ͷ�ļ�---//
//#include <reg52.H>
#include "lcd_driver.h"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//---��ʾͼƬ---//
//#define PICTURE_SHOW

//---��ʾ32*29�ĺ���---//
#define CHAR32_SHOW

//---��ʾ19x24�ĺ���---//
//#define CHAR14_SHOW

//---��ʾASCII���Ӧ���ַ�---//
#define USE_ASCII

//---����ȫ�ֱ���---//
void GUI_Dot(uint x, uint y, uint color);  //����

//void GUI_DrowSign(uint x, uint y, uint color);	//��ʮ��
//void GUI_Box(uint sx, uint sy, uchar ex, uint ey, uint color);   //������

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color);//������
//�����֣� x���ʼλ�ã�y���ʼλ�ã������׵�ַ������ɫ��������ɫ
void GUI_Write32CnChar(uint x, uint y, uchar *cn, uint wordColor, uint backColor);
//�����֣�x���ʼλ�ã�y���ʼλ�ã������׵�ַ������ɫ��������ɫ
	 
//void GUI_Write14CnChar(uint x,uint y,uchar *cn,uint wordColor,uint backColor);
//��ͼ��x���ʼλ�ã�y���ʼλ�ã�����	 
//void GUI_ShowPicture(uint x, uint y, uchar wide, uint high);

//���ַ���x���ʼλ�ã�y���ʼλ�ã��ַ��׵�ַ������ɫ��������ɫ
void GUI_WriteASCII(uint x, uint y, uchar *p, uint wordColor, uint backColor);

void GUI_WriteASCII2(uint x, uint y, uchar *p, uint wordColor, uint backColor);
void GUI_WriteASCII2Ch(uint x, uint y, uchar c, uint wordColor, uint backColor);
void GUI_WriteASCIICh(uint x, uint y, uchar c, uint wordColor, uint backColor);
void GUI_Writetable(uint x, uint y, uchar *c, uint wordColor, uint backColor);
#endif
