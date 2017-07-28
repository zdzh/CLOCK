#include <reg52.h>
#include "gui.h"
#include "touch.h"
#include "calTimeDisplay.h"
#include "clock.h"
#include "AD.H"
#include "paintTFT.h"
#include "gy521.h"
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

uchar TimeArray[]={0, 0, 0, 0, 0, 0};
uchar i=0;
long x=0, y=0;	


void main()
{
	bit backTag = 1;           //���������淵���������־
  P3 = 0x00;
  initMPU();
	TFT_Init();				//��ʼ����������ʾ
  TFT_ClearScreen(0x0000);		//������������Ļ֮ǰ��ʾ���ݵ�Ӱ��
	initTimer();		 //��ʼ����ʱ��0��ʱ�ӣ	
	tempchange();   //��ʼ���¶�   
	while(1)
	{
	   if( clockTag == 2 )       //��������
		 {
			 displayPageClock();
			 backTag = 1;
		 }
    TFT_paintMainClock(backTag);           // ��ʾʱ��
			tempchange();   
			displayTemp(getTemp(),backTag);           // ��ʾ�¶�	
				 backTag = 0;			 

 
	    if(TOUCH_XPT_ReadXY() == 1)	
			{
				x=xpt_xy.x;
				x=(x-304)*175/3422;
				y=xpt_xy.y;
				y=(y-256)*219/3440;			
				if(x>174)
				{
					x=174;
				}
				if(y>218)
				{
					y=218;
				}		
				if( (x>115)&&(y<24) )	
				{					
    				 displayPageSetting();    //�������ý���
					   TFT_ClearScreen(0x0000);		//����	
					   backTag = 1;
				}
			}
	}

}

		