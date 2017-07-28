/***************************************************************************************
 *	FileName					:	gy521.c
 *	CopyRight					: 
 *	ModuleName					:	 
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	 yezhihuo
 *
 *	Abstract Description		:	���ᴫ����
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
#include"gy521.h"
#include"i2c.h"
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
*	File Static Variable Define Section
**************************************************************/

/**************************************************************
*	Function Define Section
**************************************************************/
/**
 *  @name:void initMPU()
 *	@description : ��ʼ��MPU6050
 *	@param			��none
 *	@return		�� none
 *  @notice   �� none
 */
void initMPU()
{
	initI2C();                    //��ʼ��I2C
	writeAdd(PWR_MGMT_1, 0X00);     //�����豸
	writeAdd(SMP_DIV, 0X07);        //���ò����ʣ�125HZ
	writeAdd(CONFIG, 0x06);           //��ͨ�˲�Ƶ�ʣ�5HZ
	writeAdd(GYO_CONF, 0x18);        //�������Լ켰������Χ�����Լ죬2000deg/S
	writeAdd(ACC_CONF, 0X01);           //���ټ��Լ졢������Χ����ͨ�˲�Ƶ�ʣ����Լ죬2G,5HZ
}

/**
 *  @name:int GetData(uchar REG_Address)
 *	@description : ���ָ������
 *	@param			��reg_Address ָ����ַ
 *	@return		�� �������
 *  @notice   �� none
 */
int GetData(uchar REG_Address)
{
	char H,L;
	int temp;
	H=readAdd(REG_Address);    //��ø�λ����
	L=readAdd(REG_Address+1);     //��õ�λ����
	temp = (H<<8)+L;            //�������
	return temp / 64;             //ת��Ϊʮλ��
}



	

/**
*  @name  :void judge()
*	@description : �жϻζ�����Ҫ��
*	@param	: none
*	@return	:1 ȷ��Ϊ�𶯣� 0 ������
*  @notice : none
 */
uchar  judge()
{
	int acc[2][3],gyr[2][3];
	uchar i, j, num = 0;
  if( (GetData(ACC_Y_H) == 0 )&& (GetData(ACC_Z_H) == 0) && 	(GetData(GYRO_X_H) == 0) )
	{
       if( 	(GetData(GYRO_Y_H )== 0) && 	(GetData(GYRO_Z_H) == 0) ) 
			 {
               			initMPU();	//�ж���·�������⣬���³�ʼ��MPU6050
			 }			
	}	
	acc[0][0] = GetData(ACC_X_H);
	acc[0][1] = GetData(ACC_Y_H);
	acc[0][2] = GetData(ACC_Z_H);
	gyr[0][0] = GetData(GYRO_X_H);
	gyr[0][1] = GetData(GYRO_Y_H);
	gyr[0][2] = GetData(GYRO_Z_H);
	for( j = 0; j < 3; j++ )          //�ظ���3�β鿴�Ƿ�ȷ��Ϊ�ƶ�
	{
			acc[1][0] = acc[0][0];
			acc[1][1] = acc[0][1];
			acc[1][2] = acc[0][2];
			gyr[1][0] = gyr[0][0];
			gyr[1][1] = gyr[0][1];
			gyr[1][2] = gyr[0][2];			
			acc[0][0] = GetData(ACC_X_H);
			acc[0][1] = GetData(ACC_Y_H);
			acc[0][2] = GetData(ACC_Z_H);
			gyr[0][0] = GetData(GYRO_X_H);
			gyr[0][1] = GetData(GYRO_Y_H);
			gyr[0][2] = GetData(GYRO_Z_H);
			for( i = 0; i < 3; i++ )
			{
				if( acc[0][i] - acc[1][i] > 200 || acc[1][i] - acc[0][i] > 200 )         //�Ƚ�ǰ�����νǶ�
				{
					num++;
					break;
				}
			}
  }
			if( num < 3 )
			{
				return 0;                  //�ж�Ϊ�����ƶ�
			}	
			else
			{
				return 1;
			}
}


/**************************************************************
*	Function Define Section
**************************************************************/


  	