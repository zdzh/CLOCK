      /***************************************************************************************
 *	FileName					:	clock.c
 *	CopyRight					:
 *	ModuleName				:
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	2017.7.22
 *	Author/Corportation			:	yezhihuo
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
#include"clock.h"
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
uchar sb = 0;                     //ÿ����20�μ�¼1s
uchar clockTag = 0;                //0Ϊ�رգ�1Ϊ������2Ϊ������
clockTime time, timeclock;

sbit PWM = P3^5;                           //���ź����
uchar pwmCount, pwmPeriod ;          //ռ�ձȼ�������ռ�ձȱ���
uint num;
/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: void timeFun() 
*	@description: �жϷ������⹦�ܼĴ������ã���ʱ��0��ʼ����
 *	@param		:none
 *	@return		: none
 *  @notice : 12MHZ
 */
void initTimer()
{
	TMOD=0x01;		  //ģʽ1
	TH0 = (65536 - 45874) / 256;
	TL0 = (65536 - 45874) % 256;   //0.05s
	ET0=1;		 //����ʱ��
	TR0=1;		 //����ʱ���ж�
	EA=1;		 //�����ж�
}

/**
*  @name: void timeFun() 
*	@description: ʱ�Ӽ�ʱ
 *	@param		:none
 *	@return		: none
 *  @notice : ʹ�ö�ʱ��0�����������ڼ�ʼ������
 */
void timeFun() interrupt 1
{
	TH0 = (65536 - 45870) / 256;
	TL0 = (65536 - 45870) % 256;   //0.05s
	if(sb >= 20 )             //20��Ϊ1s
	{
		sb = 0;
		if( time.second < 59 )				 //60��
		{
			time.second++;
		}
		else
		{
			time.second = 0;                    
			if( time.minute <59 )			//60����
			{
				time.minute++;
			}
			else
			{
				time.minute = 0;
				if( time.hour <23 )           ///1Сʱ
				{
		    	                                                                                                                                                                                                                                                                                                                                                                                                                                                        		time.hour++;
				}
				else
				{
					time.hour = 0;
				}
			}
		}			
			if( clockTag == 1 )           //�ж�����
			{
				 if(time.hour == timeclock.hour && time.minute == timeclock.minute && time.second == timeclock.second)
				 {  
					 clockTag = 2;     
				 }
			 }		
	}
	else
	{
	 sb++;
	}
}

/**
*  @name:void pwmInit();
*	@description: ��ʼ��pwm��������
 *	@param		:none
 *	@return		: none
 *  @notice : ʹ�ö�ʱ��1
 */
void pwm() interrupt 3
{
	TH1 = 0XCC;
	TL1 = 0XCC;
	pwmCount++;
	num++;	
	if( num > 60000 )
	{	 
  num = 0;
	}
	if( num % 1000 == 0 )         //���¼���
	{
		pwmPeriod += 10;
	}
	if( pwmCount == 100 )
	{
		pwmCount = 0;
	}
	if( pwmPeriod > 100 )
	{
		pwmPeriod = PWM_MODE;
	}
	if( pwmCount < pwmPeriod )    //�������
	{
		PWM = 1;
	}
	else
	{
		PWM = 0;
	}
}

