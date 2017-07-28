/***************************************************************************************
 *	File Name				:		clock.h
 *	CopyRight				:
 *	ModuleName				:	
 *
 *	CPU						:
 *	RTOS					:
 *
 *	Create Data				:	
 *	Author/Corportation		:	
 *
 *	Abstract Description	:	this will be used for  lcd1602
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/ 

#ifndef __CLOCK_H
#define __CLOCK_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include<reg52.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uint
#define uint unsigned int
#endif

#ifndef uchar
#define uchar unsigned char 
#endif

#define PWM_MODE  70      //����ռ�ձ�ģʽ
/**************************************************************
*	Struct Define Section
**************************************************************/
typedef struct clockTime
{
	uchar hour;
	uchar minute;
	uchar second;
}clockTime;              //��¼ʱ��


/**************************************************************
*	Global Variable Declare Section
**************************************************************/
extern clockTime time, timeclock;          //��¼ʱ��
extern uchar clockTag;
/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/

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
void initTimer();

/**
*  @name: clockTime setTime(bit tag,clock setTime)
*	@description:  ����ʱ��
*	@param		:setime ��Ҫ���õ�ʱ��
 *	@return		: ���ú��ʱ��
 *  @notice : none
 */
clockTime setTimeA(bit tag,clockTime setTime);

#endif