/***************************************************************************************
 *	FileName					:	main.c
 *	CopyRight					:
 *	ModuleName				:
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	2017.47.10
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
#ifndef  _CLOCK_H
#define _CLOCK_H

/**************************************************************
*	Include File Section
**************************************************************/
#include<reg52.h>
#include<intrins.h>
/**************************************************************
*	Macro Define Section  
**************************************************************/
#define uint unsigned int
#define uchar unsigned char 
extern uchar  write;



/**************************************************************
*	Struct Define Section
**************************************************************/
typedef struct clock
{
	uchar hour;
	uchar minute;
	uchar second;
}clock;


/**************************************************************
*	Prototype Declare Section  ????
**************************************************************/


/**************************************************************
*	Global Variable Declare Section????
**************************************************************/
extern uchar sb, ld;
extern clock time;
extern uchar code table[16];


/**
 *  @name        :void delay()
 *	@description : ΢����ʱ����
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void delay();

/*  @name        : void init()
 *	@description : ���߳�ʼ��
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
void initI2C();

/*  @name        : uchar readAdd()
 *	@description :
 *	@param		 : none
 *	@return		 : none
 *  @notice      : None
 */
uchar readAdd(uchar address);

/*  @name        : void writeAdd(uchar adress, uchar date)
 *	@description : ��ӻ���������
 *	@param		 : address �ӻ�
 *	@return		 : none
 *  @notice      : None
 */
void writeAdd(uchar address, uchar date);

 /*  @name        :void delayms()
 *	@description : ms��ʱ����
 *	@param		 : uint i ��ʱims
 *	@return		 : none
 *  @notice      : None
 */
void delayms(uint i);




#endif