#include "FPara_Aspcfg.h"


const FPARA FPara_AspDefaultPara = 
{
		25000,						//����У׼ֵ
		25000,						//����У׼ֵ

		{{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},
		  {4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},
	       },	//��ѹУ׼ֵ

		{{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},
		},	//�¶�У׼ֵ
		
		{0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31},			//�������
		{0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30},		//����vin


		1,							//BOOLEAN	bCurrAutoCalibrate �Ƿ�ʹ�ܿ����Զ�У׼����      //1
		20,							//uint8		PreChargeVoltK;	Ԥ���ѹ�Ǻ϶ȣ�������ֵ����ΪԤ�����

		81400,						//TERMINALVOLT_MV	Ratedvolt; ���ѹ
		1274,						//QTYPE_01AH			QmaxSet;��������ֵ(0.1AH)(�����ٴ��趨)
		1274,						//QTYPE_01AH			QmaxRate;�������ֵ(0.1AH)(�)
		49,							//uint8				ParallelNum;��ز�����
		25,							//uint8 				CellNum;�ϱ�������
		
    {0xff,0xff,0xff,0x01},		//uint8		bCellReport[(CELLNUM_MAX+7)/8];		//�ϱ�������
	    	8,							//uint8		TempNum;�ϱ��¶���

		1,							//uint8 		Right;
		1,							//uint8 		Day;
		10,							//uint8 		Month;
		44,							//uint8 		Year;
		0,							//uint8 		BatType;

		{'L','S','H','0'},					//uint8		Vendor[VENDOR_LEN];	����ͺű���

		50,							//CELLVOLT_MV			BalanceDeltaV;	���������ѹ����ֵ
		3900,						//CELLVOLT_MV			BalanceStartV;	����������͵�ѹ��ֵ
		50,							//TEMPERATURE_1C		BalanceMaxTemp;	�������������¶�
		2000,						//uint16				BalanceVoltStableTime;	�����ѹ�ȴ��ȶ�ʱ��(��λ����)
		15,							//uint16				BalanceCtrlCycleTime;	�����������(��λ��)	


		7200,						//uint16				Normal_SOCOCV_StableTime;	��ͨ��̬�㿪·��ѹ�ȶ�ʱ��
		60,							//uint16				Charge_SOCOCV_StableTime;	��������̬���ȶ�ʱ��
		4192,						//uint16				Charge_SOCOCV_ValidVolt;	��Ϊ��������ֵ��ѹ
		
		2000,				//CURRENT_MA			LowCurVal;�͵����ж�����
		800,					//CURRENT_MA			ZeroCurVal;0�����ж�����
		4000,				//CURRENT_MA			ChargeCutOffCurVal;���ֹͣ��С����

							//��������
		4180,				//CELLVOLT_MV	CellHighVal;
		4200,				//CELLVOLT_MV	CellVeryHighVal;
		3650,				//CELLVOLT_MV	CellLowVal;       //3650   20141203
		3000,				//CELLVOLT_MV	CellVeryLowVal;   //3000   20141202

		39,					//TEMPERATURE_1C	ChargeTempHighVal;
		40,					//TEMPERATURE_1C	ChargeTempVeryHighVal;
		5,					//TEMPERATURE_1C	ChargeTempLowVal;
		0,					//TEMPERATURE_1C	ChargeTempVeryLowVal;
		55,					//TEMPERATURE_1C	DisChargeTempHighVal;
		60,					//TEMPERATURE_1C	DisChargeTempVeryHighVal;
		0,					//TEMPERATURE_1C	DisChargeTempLowVal;
		-20,					//TEMPERATURE_1C	DisChargeTempVeryLowVal;
		8,					//TEMPERATURE_1C	TempDiffVal;
		10,					//TEMPERATURE_1C	TempVeryDiffVal;
	
		250,					//SOCSOH		SOCLowVal (0.1%)
		5,					//SOCSOH		SOCVeryLowVal (0.1%)
		1000,				//SOCSOH		SOCHighVal (0.1%)
		1000,				//SOCSOH		SOCVeryHighVal (0.1%)

		3650,				//CELLVOLT_MV	CellDiff_VoltBoundary;��������ж������ѹ�ֽ�
		250,					//CELLVOLT_MV	CellDiffAlarm1Val_LowVolt;�͵�ѹʱ�������ֵһ���澯
		400,					//CELLVOLT_MV	CellDiffAlarm2Val_LowVolt;�͵�ѹʱ�������ֵ�����澯
		150,					//CELLVOLT_MV	CellDiffAlarm1Val_HighVolt;�ߵ�ѹʱ�������ֵһ���澯
		250,					//CELLVOLT_MV	CellDiffAlarm2Val_HighVolt;�ߵ�ѹʱ�������ֵ�����澯

		100,					//uint32		LeakLowVal;��Ե����1 (Kŷ)
		30,					//uint32		LeakVeryLowVal;	��Ե����2 (Kŷ)

		{{10,2},{50,10},{330,20}},				//����-�����������ȱ�(0.02, 0.1, 0.2AH)
			
		//��س�ŵ����Ʋ���
		1,					//uint8	BatLmtParaType;
		//uint8		BatLmtPara[BATLMTPARA_MAXLEN];	��ز���,��������Զ���

		{  
		    6,           //����(LSH0)
		    40,35,  90,0,       0,15,0,50,
		    40,35,  101,90,     0,10,0,30,
		    35,5,   90,0,       0,60,0,100,
		    35,5,   101,90,     0,30,0,60,
		    5,0,    90,0,       0,20,0,50,
		    5,0,    101,90,     0,10,0,20,
		    
		    5,          //�ŵ��
		    60,55,  101,0,      0,100,0,200,
		    55,0,   20,0,       0,100,0,200,
		    55,0,   101,20,     0,200,0x01,0x2C,        //200,300
		    0,-20,  30,0,       0,50,0,100,
		    0,-20,  101,30,     0,100,0,200,
		
		
		},
};
