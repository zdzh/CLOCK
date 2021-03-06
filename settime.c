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
 *	Abstract Description		:    设置时间
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
#include "clock.h"		//引用全局变量time
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
*	@description:  调整时间
*	@param		:n =0时修改小时，=1时修该分钟，=2时修改秒钟，num为修改前的值，
 *	@return		: 修改后的值
 *  @notice : none
 */
uchar  setTimeB(uchar n, uchar num, uint colo)
{
	char j = 0, m;
	bit tag = 0;
  TFT_ClearScreen(0x0000);		//清屏，消除屏幕之前显示内容的影响
  if( n == 0 )           //X	修改小时
	{
  	TFT_paintSetSur("HOUR");     
	}
  if( n == 1 )           //X	修改分钟
	{
  	TFT_paintSetSur("MINUTE");     
	}	
  if( n == 2 )           //X	修改秒钟
	{
  	TFT_paintSetSur("SECOND");     
	}		
	GUI_WriteASCIICh(49, 58 , num / 10 +'0', colo, 0x0000);   //显示需要设置的值1·
  GUI_WriteASCIICh(61, 58 , num % 10 +'0', colo, 0x0000);	
	while(1) 
   {
		if(TOUCH_XPT_ReadXY() == 1)		
		{
			//转化
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
		  //设置时间 
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
			else if((x<55)&&(y<24))	 //左上角
			{
        break;   //退出循环				
			}	
  		if( tag == 1 )      //判断是否需要更改
			{	
				tag = 0;
				j++;
        if( j == 1 )           //第一次修改
				{
					num = m;
				}
				if( j== 2)            //第二次修改
				{
					num = num * 10 + m;
				}
				if( j == 3)   // 重新修改
				{
					j =1;
					num = m;
				}
				if( n == 0 && num > 23 )
				{
					num = 23;          //小时最大不超过23
				}
				else if( num > 59 )
				{
					num = 59;      // 分钟和秒钟最大不超过53
				}
        GUI_WriteASCIICh(49, 58 , num / 10 +'0', colo, 0x0000);   //显示需要设置的值1·
        GUI_WriteASCIICh(61, 58 , num % 10 +'0', colo, 0x0000);	
        tag = 0;	
				Delay(40);
			}
		}	
	}
	  TFT_ClearScreen(0x0000);		//清屏� 
	 return num;
}


/**
*  @name: clockTime setTime(bit tag,clock setTime)
*	@description:  调整时间
*	@param		:setime 需要设置的时间
 *	@return		: 设置后的时间
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
			//转化
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
		  //选择设置时间 
			if( (y > 100)&&( y < 140 ) )
			{
        if( x<60 )	  //小时
				{
					num = setTimeB(0, set.hour, 0xf800);
					if( num < 24 )         //判断此次修改是否有效
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
				else if( x<115 )	  //分钟
				{
					num = setTimeB(1,set.minute, 0x7e0);			
					if( num < 60 )         //判断此次修改是否有效
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
				else	  //秒钟
				{
					num = setTimeB(2, set.second, 0xffe0);
					if( num < 60 )         //判断此次修改是否有效
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
	
			
      //按数字上方加一			
      else if( y < 90  && y > 55	 )
			{
				if( x < 30 )	  //小时十位
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
				else if( x<60 )	  //小时个位
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
				else if( x<85 )	  //分钟十位
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
				else if( x<115 )	  //分钟个位
				{
					if( set.minute % 10 == 9 )    //当分钟个位数不超过9
					{
						set.minute -= set.minute % 10;
					}
					else
					{
						set.minute += 1;
					}
					GUI_WriteASCII2Ch(90, 100, set.minute % 10 + '0', 0x07e0, 0x0000);	
				}				
				else if( x<147 )	  //秒钟十位
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
				else	  //秒钟个位
				{
					if( set.second % 10 == 9 )    //当分钟个位数不超过9
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

         // 按数字下方减一
      else if( y < 185 && y > 	155 )
			{
				if( x < 30 )	  //小时十位
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
				else if( x<60 )	  //小时个位
				{

					if( set.hour  == 20 )    //当小时十位数为二时，个位数不能超过三
					{
						set.hour = 23;
					}
					else if( set.hour % 10 == 0 )       //小时个位数从新从0开始
					{
                set.hour = (set.hour / 10) * 10 + 9 ;
					}
					else
					{
						set.hour -= 1 ;		
					}	
          GUI_WriteASCII2Ch(30, 100, set.hour % 10 + '0', 0xF800, 0x0000);					
				}			
				else if( x<85 )	  //分钟十位
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
				else if( x<120 )	  //分钟个位
				{

					if( set.minute % 10 == 0 )    //当分钟个位数不超过9
					{
						set.minute = (set.minute / 10) * 10 +  9;
					}
					else
					{
						set.minute -= 1;
					}
					GUI_WriteASCII2Ch(90, 100, set.minute % 10 + '0', 0x07e0, 0x0000);	
				}				
				else if( x<156 )	  //秒钟十位
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
				else	  //秒钟个位
				{
					if( set.second % 10 == 0 )    //当分钟个位数不超过9
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
			else if((x<55)&&(y<24))	 //左上角
			{
        break;   //退出循环				
			}
			else if((x>115)&&(y<24)&& (tag == 0))	 //左上角
			{
				clockTag = 1;      //开启闹钟
        break;   //退出循环				
			}
			Delay(20);
		}	
	}		
     TFT_ClearScreen(0x0000);		//清屏，消除屏幕之前显示内容的影响	
   return set;			
}	 

