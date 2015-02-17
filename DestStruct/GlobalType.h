#ifndef 	__GLOBALTYPE_H_
#define __GLOBALTYPE_H_


#include "Hal_types.h"

#define QT_STATIC static

#define QT_CODE_SEG			CODE_SEG
#define QT_CODE_DEFAULT		DEFAULT_ROM

#define REPLACE_QTMCUMISC_SEG			DEFAULT_ROM
#define REPLACE_PROTDY_SEG				PAGED_ROM
#define REPLACE_RTC_SEG				PAGED_ROM
#define REPLACE_BMSSOC_SEG			PAGED_ROM
#define REPLACE_QMAX_CALIBRATE_SEG	PAGED_ROM
#define REPLACE_QMAX_DATA_SEG		PAGED_ROM
#define REPLACE_LEAK_SEG				PAGED_ROM
#define REPLACE_BMSDEBUG_SEG			PAGED_ROM
#define REPLACE_PROTDY_SEG				PAGED_ROM
#define REPLACE_BMSPROCESS_SEG		PAGED_ROM
#define REPLACE_EPARA_SEG				PAGED_ROM
#define REPLACE_BMSSAMPLE_SEG			PAGED_ROM
#define REPLACE_DATASTORE_SEG			PAGED_ROM
#define REPLACE_BALANCE_SEG			PAGED_ROM
#define REPLACE_TEMPCONVERT_SEG		PAGED_ROM
#define REPLACE_DATAOPERATOR_SEG		PAGED_ROM
#define REPLACE_VOLT_CALIBRATE_SEG	PAGED_ROM
#define REPLACE_BATCFGDATA_SEG		PAGED_ROM
#define REPLACE_REALTIMEDATASTORE_SEG	PAGED_ROM

////////////////////////////////////////////全局单位定义///////////////////////////////////////////////

/*以下部分定义的类型，如电流、端电压、单体电压、温度等整个项目中必须统一
使用此定义及单位。对外接口协议中如果定义不统一，在接收到数据或发送数据时
进行转换。
*/
typedef int32			CURRENTI_MAMS;			//电流积分，最多累积量2000AS
typedef int32			CURRENT_MA;				//电流 mA，充电为负
typedef 	uint16		CELLVOLT_MV;				//单体电压,0.001V
typedef uint16		SOCSOH;					//SOC,SOH,0.1%
typedef	uint32		TERMINALVOLT_MV;		//端电压,mv
typedef 	int8			TEMPERATURE_1C;			//温度，1℃	
typedef uint32		MILLISECOND;				//毫秒，相对单位
typedef uint16		MICROSECOND;			//微秒，相对单位 
typedef uint32		SECOND;					//秒，系统时间单位
typedef uint16		BATALARM;					//电池故障类型
typedef uint16		MVVOLT;					//毫伏电压
typedef int32			SVOLT_01MV;				//有符号mv电压
typedef uint32		VOLT_01MV;				//无符号0.1mv电压

typedef uint32		QTYPE_01AH;				//Q值0.1Ah
typedef uint32		QTYPE_001AH;				//Q值0.01Ah

typedef uint32		LEAKUNIT;					//绝缘阻值单位

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef uint16 		MCUADCODE;			//ad code type
typedef uint16		QTIOFILTERLEN_TYPE;		//
typedef uint8			QTIOINSAMPLINTV_TYPE;

typedef uint8			QT_SOFTTIMERMAX_TYPE;		//软件timer数量的类型

typedef uint16 		MCUADCODE;			//ad code type
typedef uint16 		MCUADCODE_SUM;		//ad code type 累加缓存类型
typedef uint32 		MCUADCODE_CALCULATE_TYPE;		//ad code type 计算中间值类型

typedef uint8			EPARA_UNIT;
typedef uint16		EPARA_ADDRTYPE;
typedef uint32      SPIPARA_ADDRTYPE;


typedef struct{
MICROSECOND		LowTime;
MICROSECOND		HighTime;
}QT_PWM_STATUS;

#define CAN_Id_Standard            	0  /*!< Standard Id */
#define CAN_Id_Extended            	1  /*!< Extended Id */

#define CAN_RTR_Data                0  /*!< Data frame  */
#define CAN_RTR_Remote              1  /*!< Remote frame */
typedef struct
{
  uint32 Id;  /*!< Specifies the extended identifier.
                        This parameter can be a value between 0 to 0x1FFFFFFF. */

  uint8 IDE;     /*!< Specifies the type of identifier for the message that 
                        will be transmitted. This parameter can be a value 
                        of @ref CAN_identifier_type */

  uint8 RTR;     /*!< Specifies the type of frame for the message that will 
                        be transmitted. This parameter can be a value of 
                        @ref CAN_remote_transmission_request */

  uint8 DLC;     /*!< Specifies the length of the frame that will be 
                        transmitted. This parameter can be a value between 
                        0 to 8 */

  uint8 Data[8]; /*!< Contains the data to be transmitted. It ranges from 0 
                        to 0xFF. */
} CanMsg;

//can 波特率
#define CAN_BAUDRATE_250K				1
#define CAN_BAUDRATE_500K				2
#define CAN_BAUDRATE_1M				3



//无参数无返回的函数指针定义
typedef void (*FUNC_VOID_VOID)(void);
typedef void(*FUNC_VOID_UINT8)(uint8);
//一个uint8参数无返回的函数指针定义
typedef void(*FUNC_VOID_UINT8CANMSGP)(uint8,CanMsg*);
typedef BOOLEAN (*FUNC_BOOL_UINT8)(uint8);
typedef BOOLEAN (*FUNC_BOOL_UINT8CANMSGP)(uint8, CanMsg*);
typedef BOOLEAN (*FUNC_BOOL_UINT8UINT8CANMSGP)(uint8, uint8, CanMsg*);
typedef void (*FUNC_VOID_UINT8CURMA)(uint8, CURRENT_MA);
typedef void(*FUNC_VOID_UINT8CURIMAMS)(uint8, CURRENTI_MAMS);
typedef void(*FUNC_VOID_UINT8CURMAPCURIMAMSP)(uint8, CURRENT_MA*,CURRENTI_MAMS*);
typedef VOLT_01MV	(*FUNC_VOLT01MV_UINT8VOLT01MV)(uint8, VOLT_01MV);

//////////////////////////////////////////////以下是电池相关数据结构定义////////////////////////////////////




//单个电池箱最大单体数
#define BMS_CELLNUM_MAX		25
//单个电池箱最大温度采样点数
#define BMS_TEMPNUM_MAX		4
//序列号最大长度
#define BMS_SERIALNUM_MAXLEN	16



//BMS详细信息
typedef struct{
	uint8					SerialNum[BMS_SERIALNUM_MAXLEN];			//序列号
	CELLVOLT_MV				CellVolt[BMS_CELLNUM_MAX];					//单体电压
	TEMPERATURE_1C			Temp[BMS_TEMPNUM_MAX];					//温度

}BMS_DETAILSINFO;



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif//__GLOBALTYPE_H_

