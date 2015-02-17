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

////////////////////////////////////////////ȫ�ֵ�λ����///////////////////////////////////////////////

/*���²��ֶ�������ͣ���������˵�ѹ�������ѹ���¶ȵ�������Ŀ�б���ͳһ
ʹ�ô˶��弰��λ������ӿ�Э����������岻ͳһ���ڽ��յ����ݻ�������ʱ
����ת����
*/
typedef int32			CURRENTI_MAMS;			//�������֣�����ۻ���2000AS
typedef int32			CURRENT_MA;				//���� mA�����Ϊ��
typedef 	uint16		CELLVOLT_MV;				//�����ѹ,0.001V
typedef uint16		SOCSOH;					//SOC,SOH,0.1%
typedef	uint32		TERMINALVOLT_MV;		//�˵�ѹ,mv
typedef 	int8			TEMPERATURE_1C;			//�¶ȣ�1��	
typedef uint32		MILLISECOND;				//���룬��Ե�λ
typedef uint16		MICROSECOND;			//΢�룬��Ե�λ 
typedef uint32		SECOND;					//�룬ϵͳʱ�䵥λ
typedef uint16		BATALARM;					//��ع�������
typedef uint16		MVVOLT;					//������ѹ
typedef int32			SVOLT_01MV;				//�з���mv��ѹ
typedef uint32		VOLT_01MV;				//�޷���0.1mv��ѹ

typedef uint32		QTYPE_01AH;				//Qֵ0.1Ah
typedef uint32		QTYPE_001AH;				//Qֵ0.01Ah

typedef uint32		LEAKUNIT;					//��Ե��ֵ��λ

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef uint16 		MCUADCODE;			//ad code type
typedef uint16		QTIOFILTERLEN_TYPE;		//
typedef uint8			QTIOINSAMPLINTV_TYPE;

typedef uint8			QT_SOFTTIMERMAX_TYPE;		//���timer����������

typedef uint16 		MCUADCODE;			//ad code type
typedef uint16 		MCUADCODE_SUM;		//ad code type �ۼӻ�������
typedef uint32 		MCUADCODE_CALCULATE_TYPE;		//ad code type �����м�ֵ����

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

//can ������
#define CAN_BAUDRATE_250K				1
#define CAN_BAUDRATE_500K				2
#define CAN_BAUDRATE_1M				3



//�޲����޷��صĺ���ָ�붨��
typedef void (*FUNC_VOID_VOID)(void);
typedef void(*FUNC_VOID_UINT8)(uint8);
//һ��uint8�����޷��صĺ���ָ�붨��
typedef void(*FUNC_VOID_UINT8CANMSGP)(uint8,CanMsg*);
typedef BOOLEAN (*FUNC_BOOL_UINT8)(uint8);
typedef BOOLEAN (*FUNC_BOOL_UINT8CANMSGP)(uint8, CanMsg*);
typedef BOOLEAN (*FUNC_BOOL_UINT8UINT8CANMSGP)(uint8, uint8, CanMsg*);
typedef void (*FUNC_VOID_UINT8CURMA)(uint8, CURRENT_MA);
typedef void(*FUNC_VOID_UINT8CURIMAMS)(uint8, CURRENTI_MAMS);
typedef void(*FUNC_VOID_UINT8CURMAPCURIMAMSP)(uint8, CURRENT_MA*,CURRENTI_MAMS*);
typedef VOLT_01MV	(*FUNC_VOLT01MV_UINT8VOLT01MV)(uint8, VOLT_01MV);

//////////////////////////////////////////////�����ǵ��������ݽṹ����////////////////////////////////////




//����������������
#define BMS_CELLNUM_MAX		25
//�������������¶Ȳ�������
#define BMS_TEMPNUM_MAX		4
//���к���󳤶�
#define BMS_SERIALNUM_MAXLEN	16



//BMS��ϸ��Ϣ
typedef struct{
	uint8					SerialNum[BMS_SERIALNUM_MAXLEN];			//���к�
	CELLVOLT_MV				CellVolt[BMS_CELLNUM_MAX];					//�����ѹ
	TEMPERATURE_1C			Temp[BMS_TEMPNUM_MAX];					//�¶�

}BMS_DETAILSINFO;



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif//__GLOBALTYPE_H_

