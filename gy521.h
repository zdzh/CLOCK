/***************************************************************************************
 *	File Name				:		gy521.h
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
#ifndef __GY521_H
#define __GY521_H


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

#define  SMP_DIV   0X19      //���ݲ�����
#define  CONFIG    0X1A       //��ͨ�˲�Ƶ��
#define  GYO_CONF  0X1B      //�������Լ켰������Χ
#define  ACC_CONF  0X1C      //���ټ��Լ졢������Χ����ͨƵ��    
#define  ACC_X_H   0X3B      //X����ٶȸ�λ
#define  ACC_X_L   0X3C      //X����ٶȵ�λ
#define  ACC_Y_H   0X3D      //y����ٶȸ�λ
#define  ACC_Y_L   0X3E
#define  ACC_Z_H   0X3F
#define  ACC_Z_L   0X40
#define  TEMP_H    0X41     
#define  TEMP_L    0X42
#define  GYRO_X_H  0X43      //x����ٶ�
#define  GYRO_X_L  0X44       //X����ٶ�
#define  GYRO_Y_H  0X45       //Y����ٶ�
#define  GYRO_Y_L  0X46
#define  GYRO_Z_H  0X47
#define  GYRO_Z_L  0X48
#define  PWR_MGMT_1  0X6B       //��Դ����
#define  WHO_AM_I    0X75      //I2C��ַ
#define  SLAVEADDR   0XD0    //IICд��ʱ�ĵ�ַ�ֽ�����+1λ��ȡ
/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/
/**
 *  @name:int GetData(uchar REG_Address)
 *	@description : ���ָ������
 *	@param			��reg_Address ָ����ַ
 *	@return		�� �������
 *  @notice   �� none
 */
int GetData(uchar REG_Address);
/**
 *  @name:void initMPU()
 *	@description : ��ʼ��MPU6050
 *	@param			��none
 *	@return		�� none
 *  @notice   �� none
 */
void initMPU();

/**
*  @name  :void judge()
*	@description : �жϻζ�����Ҫ��
*	@param	: none
*	@return	:none
*  @notice : none
 */
uchar judge();
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif