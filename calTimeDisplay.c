/***************************************************************************************
 *	FileName					:	calTimeDisplay.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:  ��ʾ����
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/

#include "calTimeDisplay.h"
#include "touch.h"
#include "paintTFT.h"
#include "GUI.h"
#include "lcd_driver.h"
#include "clock.h"		//����ȫ�ֱ���time
#include"AD.H"
#include"gy521.h"
/**************************************************************
*	Macro Define Section
**************************************************************/

/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/
sbit PWM = P3^5; 
sbit deep = P3^6;            //������
/**************************************************************
*	Global Variable Declare Section
**************************************************************/


/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/


	
/**
*  @name:void displayPageSet()
*	@description: ��ʾ����ʱ�����
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetTime()
{
		/*���������ֵĻ�����ͼ*/		
		//TFT_paintSetSur("TIME");
	  TFT_paintSetTime(1);
	 
		/*��ʱ��д�����ý�����*/	 
	//	TFT_paintTimeSet(time);									 	
	
    time = setTimeA(1, time);        //����ʱ��
}

/**
*  @name:void displayPageSetClock()
*	@description: ��ʾ�������ӽ���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetClock()
{
		/*���������ֵĻ�����ͼ*/		
		//TFT_paintSetSur("CLOCK");
	//GUI_WriteASCII(99,0, "YES", 0x07E0, 0x0000);	
		/*��ʱ��д�����ý�����ƫ��*/	 
		//TFT_paintTimeSet(timeclock);					 	
	  //setClockTime();
			/*���������ֵĻ�����ͼ*/		
		//TFT_paintSetSur("TIME");
	  TFT_paintSetTime(0);
	 
		/*��ʱ��д�����ý�����*/	 
	//	TFT_paintTimeSet(time);									 	
	
    timeclock = setTimeA(0, timeclock);        //����ʱ��
}



/**
*  @name: displayPageSetting
*	@description: ��ʾ���ý���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetting()
{
	TFT_ClearScreen(0x0000);		//����		
	GUI_WriteASCII(0,0, "BACK", 0x001F, 0x0000);	
	GUI_WriteASCII(50,24, "SET", 0xFFE0, 0x0000);
	GUI_WriteASCII(50, 94, "TIME", 0x7ff, 0x0000);	
	GUI_WriteASCII(50, 134, "CLOCK", 0x7fff, 0x0000);	
	GUI_Line(20, 50, 155, 50, 0xF800);     //������
	GUI_Line(20, 130, 155, 130, 0xF800);  //x, y, x, y
	GUI_Line(20, 170, 155, 170, 0xF800);  //x, y, x, y
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			/*ת��*/
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
			if( y < 135 && y > 95)       //ѡ������ʱ��
			{
				TFT_ClearScreen(0x0000);		//����			
				displayPageSetTime();
				TFT_ClearScreen(0x0000);		//����
        break;   //�˳�ѭ��	
			}
			else if( y > 135 && y < 165)   // ѡ����������
			{
					TFT_ClearScreen(0x0000);		//����		
				displayPageSetClock();
			TFT_ClearScreen(0x0000);		//����
        break;   //�˳�ѭ��	
			}
			else if((x<55)&&(y<24))	 //���Ͻ�
			{
			TFT_ClearScreen(0x0000);		//����
        break;   //�˳�ѭ��				
			}
		}
	}		
}

/**
*  @name:void displayTemp(int temp,bit tag)	 
*	@description: ��ʾ�¶�
 *	@param		:temp = �¶� x 10, tag=1������ʾ��������
 *	@return		: none
 *  @notice : none
 */
void displayTemp(int temp ,bit tag)	 
{
   static int lastTemp = 0;
	 uchar stemp[][2]= { 0, '\0', 0, '\0',  0,  '\0'};
	 stemp[0][0] = temp / 100 + '0';     
	 stemp[1][0] = (temp % 100) / 10 + '0';
	 stemp[2][0] = temp % 10 + '0';
	 if( (lastTemp / 100 != temp / 100) || (tag == 1) )
	 {
     GUI_WriteASCII(60, 170, stemp[0], 0x7fff, 0x0000);	
	 }
	 if( ((lastTemp / 10) % 10 != (temp / 10) % 10) || (tag == 1) )
	 {
		 GUI_WriteASCII(70, 170, stemp[1], 0x7fff, 0x0000);	 
	 GUI_WriteASCII(80, 170, ".", 0x7fff, 0x0000);	 		 		 
   }
	 if((lastTemp != temp) || (tag == 1) )
	 {
		 
   GUI_WriteASCII(90, 170, stemp[2], 0x7fff, 0x0000);		

	 }
	 lastTemp = temp;            //��¼��ǰ�¶������´αȽ�
 }	 

 
/**
*  @name: displayPageSetting
*	@description: ��ʾ��������ʱ�Ľ���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageClock()
{
					 //��������
						TMOD = 0x10 | 0x01; // ����ʱ��1ģʽ1
	          TL1 = 0xcc; // 
	          TH1 = 0xcc;
	          ET1 = 1;
          	TR1 = 1;
           	pwmCount = 0;
	          pwmPeriod = PWM_MODE;
				TFT_ClearScreen(0x0000);		//����	
			GUI_WriteASCII(65, 100, "STOP", 0xffe0, 0x0000);	 //��ʾ�رհ�ť	
  	while( 1 )
		{
			TFT_paintTimeSet(time);          //���Ͻ���ʾʱ�䰴
       deep = ~deep;
 		  if(TOUCH_XPT_ReadXY() == 1 )		
	   	{
			/*ת��*/
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
     	if((x>65)&&(x<130)&&(y>97)&&(y<125))	  //����ر�
			{
				clockTag = 0;
				TR1 = 0;
				ET1 = 0;
				PWM = 0;
				TFT_ClearScreen(0x0000);		//����
				break;
			}
		}
		 else if( judge() == 1)            //�ζ��ر�
			{
				clockTag = 0;
				TR1 = 0;
				ET1 = 0;
				PWM = 0;
				TFT_ClearScreen(0x0000);		//����
				break;
	}	
	}
}

 