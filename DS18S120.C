/***************************************************************************************
 *	FileName					:	
 *	CopyRight					:
 *	ModuleName					:	
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	
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
#include"AD.H"

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
sbit ds = P3^7;

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: void delayMs(uint i)
*	@description: 延时函数
 *	@param： i 延时时间	
 *	@return		：none
 *  @notice ：none
 */
 void delayMs(uint i)
 {
	 uchar j;
	 while( i > 0 )
	 {
		 for( j = 0; j < 110; j++ )
		 {
			 ;
		 }
		 i--;
	 }
 }

/**
	*  @name: void dsreset()
	*	@description: DS180B20复位，初始化函数
	*	@param:	none
	*	@return:		none
	*  @notice: none
 */
void dsreset()
{
	uint i;
	ds = 0;
	i = 103;
	while ( i > 0 )
	{
		i--;             //延时
	}
	ds = 1;
	i = 4;
	while( i > 0) 
	{
		i--;
	}
}
 
/**
*  @name: bit tempReadBit()
*	@description: 读一位数据
 *	@param			
 *	@return		：读取的数据
 *  @notice
 */
bit tempReadBit()
{
	uint i;
	bit dat;
	ds = 0;
	i++;
	ds = 1;
	i++; i++;
	dat = ds;
	i = 8;
	while( i > 0 )
	{
		i--;
	}
	return dat;
}


	
	/**
*  @name: uchar tempRead()
 *	@description：读一个字节数据
 *	@param			
 *	@return		：读取的数据
 *  @notice
 */
 uchar tempRead()
{
	uchar i, j, dat;
	dat = 0;
	for( i = 0; i < 8; i++ )
	{
		j = tempReadBit();
		dat = (dat >> 1) | (j << 7);               //将读取的数据存入一个字节
	} 
	return dat;
}
	
 
 /**
 *  @name：void tempWrite(uchar dat)
 *	@description： 向ds18b20写一个字节数据
 *	@param			：需要写入的数据
 *	@return		
 *  @notice
 */
void tempWrite(uchar dat)
{
	uint i;
	uchar j;
	bit test;
	for( j = 0; j < 8; j++ )
	{
		test = dat & 0x01;
		dat >>= 1;
		if( test == 1 )           //写1
		{
			ds = 0;
			i++; i++;
			ds = 1;
			i = 8;
			while( i > 0 )
			{
				i--;
			}
		}
		else             //写0
		{
			ds = 0;
			i = 8;
			while( i > 0 )
			{
				i--;
			}
			ds = 1;
			i++; i++;
		}
	}
}

 
 /**
*  @name:float getTemp()
*	@description: 读取温度
 *	@param	： none 		
*	@return		: 读取到的温度 * 10
*  @notice   :none
 */
uint getTemp()
{
	uchar a, b;
	float ftemp;
  uint	temp;
	dsreset();
	delayMs(1);
  tempWrite(0xcc);
	tempWrite(0xbe);
	a = tempRead();          //读低8位
	b = tempRead();          //读高8位 
	temp = b;
	temp <<= 8;
	temp = temp | a;         //合并为一个字
	ftemp = temp * 0.0625;          //温度在寄存器中为12位，分辨率为0.0625
  temp = ftemp * 10 + 0.5;           //�+0.05为四舍五入,*10 表示支取一位小数
	return temp;
}

 /**
*  @name:void tempchang()
*	@description: 开始获取温度并转换
*	@param			:none
*	@return		:none
*  @notice : none
 */
void tempchange()
{
	dsreset();
	delayMs(1);
	tempWrite(0xcc);    //写跳过读rom指令
	tempWrite(0x44);     //写温度转换指令
}
