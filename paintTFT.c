 /***************************************************************************************
 *	FileName					:	paintTFT.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:
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
#include <reg52.h>
#include "paintTFT.h"
#include "GUI.h"
#include "clock.h"

/**************************************************************
*	Macro Define Section
**************************************************************/

/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**************************************************************
*	Global Variable Declare Section
**************************************************************/


uchar code triangle[][48]=
{
/*--  ??x??=16x24  --*/
	//��ͷ
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0xC0,0x01,0xC0,
0x03,0xE0,0x07,0xF0,0x0F,0xF8,0x1F,0xFC,0x3F,0xFE,0x3F,0xFE,0x7F,0xFE,0x7F,0xFE,
0x7F,0xFE,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,	
/*--  ??x??=16x24  --*/
	//����ͷ
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x7F,0xFE,
0x7F,0xFE,0x7F,0xFE,0x3F,0xFE,0x3F,0xFE,0x1F,0xFC,0x0F,0xF8,0x07,0xF0,0x03,0xE0,
0x01,0xC0,0x01,0xC0,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
/**************************************************************
*	File Static Variable Define Section
**************************************************************/




/**************************************************************
*	Function Define Section
**************************************************************/
/**
*  @name:void TFT_paintSetTime(bit tag)
*	@description: ����ʱ�����
 *	@param		:tag = 1ʱ����ʱ�䡣=0ʱ��������
 *	@return		: none
 *  @notice : none
 *  @use : �ڴ�������ʾ����ʱ��Ļ�����ܣ����ý��棩
 */
 void TFT_paintSetTime(bit tag)
 {
	uchar stime[][2] = {0, '\0',0, '\0',0, '\0',0, '\0',0, '\0',0, '\0'};
	clockTime setTime;
	if(  tag == 1 )
	{
		setTime = time;
	GUI_WriteASCII(47, 24, "TIME", 0xFFE0, 0x0000);
	}
	else
	{
		setTime = timeclock;
	  GUI_WriteASCII(47, 24, "CLOCK", 0xFFE0, 0x0000);
		GUI_WriteASCII(127, 0, "YES", 0x001F, 0x0000);		
	}

	stime[0][0] = setTime.hour / 10 + '0';
	stime[1][0] = setTime.hour % 10 + '0';
	stime[2][0] = setTime.minute / 10 + '0';
	stime[3][0] = setTime.minute % 10 + '0';
	stime[4][0] = setTime.second / 10 + '0';
	stime[5][0] = setTime.second % 10 + '0';		
	/*��ʱ��д�����ý�����*/	
  GUI_Writetable(9, 60, triangle[0], 0x7fff, 0x0000);	
  GUI_Writetable(29, 60, triangle[0], 0x7fff, 0x0000);	
  GUI_Writetable(69, 60, triangle[0], 0x7fff, 0x0000);	
  GUI_Writetable(89, 60, triangle[0], 0x7fff, 0x0000);	
  GUI_Writetable(129, 60, triangle[0], 0x7fff, 0x0000);	
  GUI_Writetable(149, 60, triangle[0], 0x7fff, 0x0000);	
  GUI_Writetable(9, 160, triangle[1], 0x7fff, 0x0000);	
  GUI_Writetable(29, 160, triangle[1], 0x7fff, 0x0000);	
  GUI_Writetable(69, 160, triangle[1], 0x7fff, 0x0000);	
  GUI_Writetable(89, 160, triangle[1], 0x7fff, 0x0000);	
  GUI_Writetable(129, 160, triangle[1], 0x7fff, 0x0000);	
  GUI_Writetable(149, 160, triangle[1], 0x7fff, 0x0000);	
	
	GUI_WriteASCII(0, 0, "BACK", 0x001F, 0x0000);	  //����   ���Ͻ�	
  GUI_WriteASCII2(50, 94, ":", 0x7fff, 0x0000);
		GUI_WriteASCII2(106, 94, ":", 0x7fff, 0x0000);		
	  GUI_WriteASCII2(10, 100, stime[0], 0xF800, 0x0000);	 //h1				 
    GUI_WriteASCII2(30, 100, stime[1], 0xF800, 0x0000);	 //h0									 	
		GUI_WriteASCII2(70, 100, stime[2], 0x07e0, 0x0000);	 //m1					 
    GUI_WriteASCII2(90, 100, stime[3], 0x07e0, 0x0000);	 //m0								 	
		GUI_WriteASCII2(130, 100,stime[4], 0xffe0, 0x0000);	 //s1			 
    GUI_WriteASCII2(150, 100, stime[5], 0xffe0, 0x0000);	 //s0			
	
}	 



/**
*  @name:void paintTFT();
*	@description: �ڴ������ϻ�ͼ
 *	@param		:none
 *	@return		: none
 *  @notice : none
 *  @use : �ڴ�������ʾ����ʱ��Ļ�����ܣ����ý��棩
 */
void TFT_paintSetSur(uchar *s)		//���ý������ʾ
{
	TFT_ClearScreen(0x0000);
	GUI_WriteASCII(47, 24, s, 0xFFE0, 0x0000);	  //x, y	
  	//����
	GUI_Line(20, 50, 155, 50, 0xF800);  //x, y, x, y
	GUI_Line(20, 90, 155, 90, 0xF800);  //x, y, x, y
	GUI_Line(20, 130, 155, 130, 0xF800);  //x, y, x, y
	GUI_Line(20, 170, 155, 170, 0xF800);  //x, y, x, y
	GUI_Line(20, 210, 155, 210, 0xF800);  //x, y, x, y	
	//����
   	GUI_Line(65, 90, 65, 210, 0xF800);  //x, y, x, y
	GUI_Line(110, 50, 110, 210, 0xF800);  //x, y, x, y	
	//����	x, y		
   	GUI_WriteASCII(31, 94, "1", 0xF800, 0x0000);	 //1
	GUI_WriteASCII(81, 94, "2", 0xF800, 0x0000);	 //2
	GUI_WriteASCII(127, 94, "3", 0xF800, 0x0000);	 //3
	GUI_WriteASCII(31, 134, "4", 0xF800, 0x0000);	 //4
	GUI_WriteASCII(81, 134, "5", 0xF800, 0x0000);	 //5
	GUI_WriteASCII(127, 134, "6", 0xF800, 0x0000);	 //6
	GUI_WriteASCII(31, 174, "7", 0xF800, 0x0000);	 //7
	GUI_WriteASCII(81, 174, "8", 0xF800, 0x0000);	 //8
	GUI_WriteASCII(127, 174, "9", 0xF800, 0x0000);	 //9
    GUI_WriteASCII(127, 58, "0", 0xF800, 0x0000);	 //0	
	GUI_WriteASCII(0, 0, "BACK", 0x001F, 0x0000);	  //����   ���Ͻ�

}

/**
*  @name:void TFT_paintTimeSet();
*	@description: �������ʱ����ʾ
 *	@param		: bit tag �Ƿ���Ҫȫ��ˢ����ʾ��1Ϊˢ����ʾ
 *	@return		: none
 *  @notice : none
 *  @use : �õ�ʱ������λ������ʾ�ڴ��������м�
 */
void TFT_paintMainClock(bit tag)
{
	static clockTime lastTime;
	 uchar code table[] ={
0x38,0x00,0x6C,0x00,0xC6,0x00,0x82,0x00,0xC6,0x00,0x6C,0x00,0x38,0xFE,0x01,0xFE,
0x07,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
0x0E,0x00,0x0E,0x00,0x06,0x00,0x03,0xFE,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,
	 };       //���϶�	
  uchar color,k,j;	 
	uchar h1[]={0,'\0'}, h0[]={0,'\0'};
	uchar m1[]={0,'\0'}, m0[]={0,'\0'};
	uchar s1[]={0,'\0'}, s0[]={0,'\0'};	//���ʱ����
	if( tag == 1)         //��һ�ν���ʱ�ӽ��棬ˢ����������
	{								 	
	     GUI_WriteASCII(127, 0, "SET", 0x001F, 0x0000);	 //����   ���Ͻ�	
			 GUI_WriteASCII2(50, 94, ":", 0x7fff, 0x0000);
    	 GUI_WriteASCII2(106, 94, ":", 0x7fff, 0x0000);	
	 //���϶ȷ���
	 TFT_SetWindow(105,170,120, 193);
	  for (k=0; k<48; k++)
		{
			color = table[k];
			for (j=0; j<8; j++) 
			{
				if ((color&0x80) == 0x80)
				{
					TFT_WriteColor(0x7fff);
				} 						
				else
				{
					TFT_WriteColor(0x000);
				} 	
				color <<= 1;
			}
		}		
	}
	/*���ý������ʾʱ��*/
	h1[0]=time.hour/10+'0';
	h0[0]=time.hour%10+'0';
	m1[0]=time.minute/10+'0';
	m0[0]=time.minute%10+'0';
	s1[0]=time.second/10+'0';
	s0[0]=time.second%10+'0';

	/*��ʱ����ʾ�ڴ�������*/
	if( lastTime.hour != time.hour || tag == 1 )
	{
		if( (lastTime.hour / 10 != time.hour / 10) || (tag == 1) )
		{
		  GUI_WriteASCII2(10, 100, h1, 0xF800, 0x0000);	 //h1	
		}
     if( (lastTime.hour % 10 != time.hour % 10 ) || (tag == 1) )
		 {			 
    		GUI_WriteASCII2(30, 100, h0, 0xF800, 0x0000);	 //h0									 	
		 }
	 }
	if( (lastTime.minute != time.minute ) || (tag == 1) )
	{
		if( (lastTime.minute / 10 != time.minute / 10) || (tag == 1) )
		{
		 GUI_WriteASCII2(70, 100, m1, 0x07e0, 0x0000);	 //m1		
		}
     if( (lastTime.minute % 10 != time.minute % 10) || (tag == 1)  )
		 {			 
    		GUI_WriteASCII2(90, 100, m0, 0x07e0, 0x0000);	 //m0								 	
		 }
	 }
	if( (lastTime.second != time.second) || (tag == 1)  )
	{
		if( (lastTime.second / 10 != time.second / 10) || (tag == 1)  )
		{
		  	GUI_WriteASCII2(130, 100, s1, 0xffe0, 0x0000);	 //s1	
		}
     if( (lastTime.second % 10 != time.second % 10) || (tag == 1)  )
		 {			 
    		GUI_WriteASCII2(150, 100, s0, 0xffe0, 0x0000);	 //s0											 	
		 }		 
	 }	
	    lastTime = time;          //��¼��ǰʱ�������´ζԱ�
}

/**
*  @name:void TFT_paintTimeSet(clockTime setime)
*	@description: ��������ʱ�����ʾ
 *	@param		: ʱ����
 *	@return		: none
 *  @notice : none
 *  @use : �õ�ʱ������λ������ʾ�ڴ����������Ͻ�
 */
void TFT_paintTimeSet(clockTime setime)
{
	uchar h1[]={0,'\0'}, h0[]={0,'\0'};
	uchar m1[]={0,'\0'}, m0[]={0,'\0'};
	uchar s1[]={0,'\0'}, s0[]={0,'\0'};	//���ʱ����

	/*�õ����ý������ʾʱ��*/
	h1[0]=setime.hour/10+'0';
	h0[0]=setime.hour%10+'0';
	m1[0]=setime.minute/10+'0';
	m0[0]=setime.minute%10+'0';
	s1[0]=setime.second/10+'0';
	s0[0]=setime.second%10+'0';
	/*��ʱ��д�����ý�����ƫ��*/
	GUI_WriteASCII(39, 56, ":", 0xF800, 0x0000);
	GUI_WriteASCII(71, 56, ":", 0xF800, 0x0000);
	GUI_WriteASCII(17, 58, h1, 0xF800, 0x0000);	   //���12
	GUI_WriteASCII(29, 58, h0, 0xF800, 0x0000);
	GUI_WriteASCII(49, 58, m1, 0xF800, 0x0000);
	GUI_WriteASCII(61, 58, m0, 0xF800, 0x0000);
	GUI_WriteASCII(81, 58, s1, 0xF800, 0x0000);
	GUI_WriteASCII(93, 58, s0, 0xF800, 0x0000);
}