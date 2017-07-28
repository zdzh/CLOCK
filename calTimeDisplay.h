/***************************************************************************************
 *	FileName					:	calTimeDisplay.h
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
#ifndef __CALTIMEDISPLAY_H
#define __CALTIMEDISPLAY_H

/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include <reg52.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**************************************************************
*	Global Variable Declare Section
**************************************************************/


//����main.c�и�ֵ/calTimeDisplay.c�е���
extern uchar TimeArray[];	//�м�ת��ֵ
extern uchar i;	
extern long x, y;	
extern uchar pwmCount, pwmPeriod ;          //ռ�ձȼ�������ռ�ձȱ���

/**************************************************************
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: displayPageSetting
*	@description: ��ʾ���ý���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageSetting();

/**
*  @name:void displayTemp(int temp,bit tag)	 
*	@description: ��ʾ�¶�
 *	@param		:temp = �¶� x 10, tag=1������ʾ��������
 *	@return		: none
 *  @notice : none
 */
void displayTemp(int temp ,bit tag)	 ;
/**
*  @name: displayPageSetting
*	@description: ��ʾ��������ʱ�Ľ���
 *	@param		:none
 *	@return		: none
 *  @notice : none
 */
void displayPageClock();

#endif