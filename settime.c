/***************************************************************************************
 *	FileName					:	settime.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 caiyinmao
 *
 *	Abstract Description		:    ����ʱ��
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
#include<reg52.h>
#include "clock.h"		//����ȫ�ֱ���time
#include "calTimeDisplay.h"
#include "touch.h"
#include "paintTFT.h"
#include "GUI.h"
#include "lcd_driver.h"

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

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: void setTimeb
*	@description:  ����ʱ��
*	@param		:n =0ʱ�޸�Сʱ��=1ʱ�޸÷��ӣ�=2ʱ�޸����ӣ�numΪ�޸�ǰ��ֵ��
 *	@return		: �޸ĺ��ֵ
 *  @notice : none
 */
uchar  setTimeB(uchar n, uchar num, uint colo)
{
	char j = 0, m;
	bit tag = 0;
  TFT_ClearScreen(0x0000);		//������������Ļ֮ǰ��ʾ���ݵ�Ӱ��
  if( n == 0 )           //X	�޸�Сʱ
	{
  	TFT_paintSetSur("HOUR");     
	}
  if( n == 1 )           //X	�޸ķ���
	{
  	TFT_paintSetSur("MINUTE");     
	}	
  if( n == 2 )           //X	�޸�����
	{
  	TFT_paintSetSur("SECOND");     
	}		
	GUI_WriteASCIICh(49, 58 , num / 10 +'0', colo, 0x0000);   //��ʾ��Ҫ���õ�ֵ1��
  GUI_WriteASCIICh(61, 58 , num % 10 +'0', colo, 0x0000);	
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			//ת��
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
		  //����ʱ�� 
			if((x>115)&&(y>45)&&(y<85))	  //0
			{
				m = 0;
				tag = 1;
			}
			else if((x<60)&&(y>95)&&(y<135))	  //1
			{
				m = 1;
				tag = 1;				
			}
			else if((x>70)&&(x<105)&&(y>95)&&(y<135)) //2
			{
				m = 2;
				tag = 1;	
			}
			else if((x>115)&&(y>95)&&(y<135))  //3
			{
				m = 3;
				tag = 1;	
			}
			else if((x<60)&&(y>145)&&(y<165))	  //4
			{
				m = 4;
				tag = 1;	
			}
			else if((x>70)&&(x<105)&&(y>145)&&(y<165)) //5
			{
				m = 5;
				tag = 1;	
			}
			else if((x>115)&&(y>145)&&(y<165)) //6
			{
				m = 6;
				tag = 1;	
			}
			else if((x<60)&&(y>175)&(y<205))	  //7
			{
				m  = 7;
				tag = 1;	
			}
			else if((x>70)&&(x<105)&&(y>175)&&(y<205)) //8
			{
				m = 8;
				tag = 1;	
			}
			else if((x>115)&&(y>175)&&(y<205)) //9
			{
				m = 9;
				tag = 1;	
			}																															
			else if((x<55)&&(y<24))	 //���Ͻ�
			{
        break;   //�˳�ѭ��				
			}	
  		if( tag == 1 )      //�ж��Ƿ���Ҫ����
			{	
				tag = 0;
				j++;
        if( j == 1 )           //��һ���޸�
				{
					num = m;
				}
				if( j== 2)            //�ڶ����޸�
				{
					num = num * 10 + m;
				}
				if( j == 3)   // �����޸�
				{
					j =1;
					num = m;
				}
				if( n == 0 && num > 23 )
				{
					num = 23;          //Сʱ��󲻳���23
				}
				else if( num > 59 )
				{
					num = 59;      // ���Ӻ�������󲻳���53
				}
        GUI_WriteASCIICh(49, 58 , num / 10 +'0', colo, 0x0000);   //��ʾ��Ҫ���õ�ֵ1��
        GUI_WriteASCIICh(61, 58 , num % 10 +'0', colo, 0x0000);	
        tag = 0;	
				Delay(40);
			}
		}	
	}
	  TFT_ClearScreen(0x0000);		//����� 
	 return num;
}


/**
*  @name: clockTime setTime(bit tag,clock setTime)
*	@description:  ����ʱ��
*	@param		:setime ��Ҫ���õ�ʱ��
 *	@return		: ���ú��ʱ��
 *  @notice : none
 */
clockTime setTimeA(bit tag,clockTime setTime)
{
	uchar num;
  clockTime set;
	set = setTime;
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			//ת��
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
		  //ѡ������ʱ�� 
			if( (y > 100)&&( y < 140 ) )
			{
        if( x<60 )	  //Сʱ
				{
					num = setTimeB(0, set.hour, 0xf800);
					if( num < 24 )         //�жϴ˴��޸��Ƿ���Ч
					{
						set.hour = num;
					}
					if( tag == 1 )
					{
						time = set;
					}
					else
					{
						timeclock =set;
					}
					TFT_paintSetTime(tag);					
				}					
				else if( x<115 )	  //����
				{
					num = setTimeB(1,set.minute, 0x7e0);			
					if( num < 60 )         //�жϴ˴��޸��Ƿ���Ч
					{
						set.minute = num;
					}
					if( tag == 1 )
					{
						time = set;
					}
					else
					{
						timeclock =set;
					}					
					TFT_paintSetTime(tag);							
				}								
				else	  //����
				{
					num = setTimeB(2, set.second, 0xffe0);
					if( num < 60 )         //�жϴ˴��޸��Ƿ���Ч
					{
						set.second = num;
					}
					if( tag == 1 )
					{
						time = set;
					}
					else
					{
						timeclock =set;
					}					
					TFT_paintSetTime(tag);					
				}
			}
	
			
      //�������Ϸ���һ			
      else if( y < 90  && y > 55	 )
			{
				if( x < 30 )	  //Сʱʮλ
				{
					if( set.hour > 13 && set.hour < 20 )
					{
						set.hour %= 10;
					}
					else if( set.hour > 19 )
					{
						set.hour = set.hour % 10;
					}
					else
					{
						set.hour += 10;
					}
					 GUI_WriteASCII2Ch(9, 100, set.hour / 10 + '0', 0xF800, 0x0000);	
				}
				else if( x<60 )	  //Сʱ��λ
				{
          if( set.hour == 23 )
					{
						set.hour = 20;
					}
					else
					{
						set.hour++;
					}
          GUI_WriteASCII2Ch(30, 100, set.hour % 10 + '0', 0xF800, 0x0000);					
				}			
				else if( x<85 )	  //����ʮλ
				{
            if( set.minute > 49 )
						{
							set.minute %= 10;
						}
						else
						{
							set.minute += 10;
						}
          	GUI_WriteASCII2Ch(69, 100, set.minute / 10 + '0', 0x07e0, 0x0000);				
				}		
				else if( x<115 )	  //���Ӹ�λ
				{
					if( set.minute % 10 == 9 )    //�����Ӹ�λ��������9
					{
						set.minute -= set.minute % 10;
					}
					else
					{
						set.minute += 1;
					}
					GUI_WriteASCII2Ch(90, 100, set.minute % 10 + '0', 0x07e0, 0x0000);	
				}				
				else if( x<147 )	  //����ʮλ
				{
            if( set.second > 49 )
						{
							set.second %= 10;
						}
						else
						{
							set.second += 10;
						}
					GUI_WriteASCII2Ch(129, 100, set.second / 10 + '0', 0xffe0, 0x0000);	
				}				
				else	  //���Ӹ�λ
				{
					if( set.second % 10 == 9 )    //�����Ӹ�λ��������9
					{
						set.second -= set.second % 10;
					}
					else
					{
						set.second += 1;
					}
					GUI_WriteASCII2Ch(150, 100, set.second % 10 + '0', 0xffe0, 0x0000);
				}	
			}

         // �������·���һ
      else if( y < 185 && y > 	155 )
			{
				if( x < 30 )	  //Сʱʮλ
				{
					if( set.hour < 4)
					{						
						 set.hour = set.hour + 2 * 10;
					}
					else if( set.hour < 10 )
					{
						set.hour = set.hour + 10;
					}
					else
					{
						set.hour -= 10;
					}
					 GUI_WriteASCII2Ch(9, 100, set.hour / 10 + '0', 0xF800, 0x0000);
			 }
				else if( x<60 )	  //Сʱ��λ
				{

					if( set.hour  == 20 )    //��Сʱʮλ��Ϊ��ʱ����λ�����ܳ�����
					{
						set.hour = 23;
					}
					else if( set.hour % 10 == 0 )       //Сʱ��λ�����´�0��ʼ
					{
                set.hour = (set.hour / 10) * 10 + 9 ;
					}
					else
					{
						set.hour -= 1 ;		
					}	
          GUI_WriteASCII2Ch(30, 100, set.hour % 10 + '0', 0xF800, 0x0000);					
				}			
				else if( x<85 )	  //����ʮλ
				{
					if( set.minute < 10 )
					{
						set.minute = set.minute % 10 + 5 * 10;
					}
          else
					{
             set.minute -= 10;
					}						
          	GUI_WriteASCII2Ch(70, 100, set.minute / 10 + '0', 0x07e0, 0x0000);				
				}		
				else if( x<120 )	  //���Ӹ�λ
				{

					if( set.minute % 10 == 0 )    //�����Ӹ�λ��������9
					{
						set.minute = (set.minute / 10) * 10 +  9;
					}
					else
					{
						set.minute -= 1;
					}
					GUI_WriteASCII2Ch(90, 100, set.minute % 10 + '0', 0x07e0, 0x0000);	
				}				
				else if( x<156 )	  //����ʮλ
				{
					if( set.second < 10 )
					{
						set.second = set.second % 10 + 5 * 10;
					}
          else
					{
             set.second -= 10;
					}			
					GUI_WriteASCII2Ch(130, 100, set.second / 10 + '0', 0xffe0, 0x0000);	
				}				
				else	  //���Ӹ�λ
				{
					if( set.second % 10 == 0 )    //�����Ӹ�λ��������9
					{
						set.second = (set.second / 10) * 10 +  9;
					}
					else
					{
						set.second -= 1;
					}
					GUI_WriteASCII2Ch(150, 100, set.second % 10 + '0', 0xffe0, 0x0000);
				}				
			}	
			else if((x<55)&&(y<24))	 //���Ͻ�
			{
        break;   //�˳�ѭ��				
			}
			else if((x>115)&&(y<24)&& (tag == 0))	 //���Ͻ�
			{
				clockTag = 1;      //��������
        break;   //�˳�ѭ��				
			}
			Delay(20);
		}	
	}		
     TFT_ClearScreen(0x0000);		//������������Ļ֮ǰ��ʾ���ݵ�Ӱ��	
   return set;			
}	 

