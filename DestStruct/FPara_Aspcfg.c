#include "FPara_Aspcfg.h"


const FPARA FPara_AspDefaultPara = 
{
		25000,						//电流校准值
		25000,						//电流校准值

		{{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},
		  {4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},
	       },	//电压校准值

		{{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},{4096,0},
		},	//温度校准值
		
		{0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31,0x31},			//电池箱编号
		{0x31,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30},		//车辆vin


		1,							//BOOLEAN	bCurrAutoCalibrate 是否使能开机自动校准电流      //1
		20,							//uint8		PreChargeVoltK;	预充电压吻合度，超过此值才认为预充结束

		81400,						//TERMINALVOLT_MV	Ratedvolt; 额定电压
		1274,						//QTYPE_01AH			QmaxSet;电量设置值(0.1AH)(出厂再次设定)
		1274,						//QTYPE_01AH			QmaxRate;电量标称值(0.1AH)(额定)
		49,							//uint8				ParallelNum;电池并联数
		25,							//uint8 				CellNum;上报单体数
		
    {0xff,0xff,0xff,0x01},		//uint8		bCellReport[(CELLNUM_MAX+7)/8];		//上报单体数
	    	8,							//uint8		TempNum;上报温度数

		1,							//uint8 		Right;
		1,							//uint8 		Day;
		10,							//uint8 		Month;
		44,							//uint8 		Year;
		0,							//uint8 		BatType;

		{'L','S','H','0'},					//uint8		Vendor[VENDOR_LEN];	电池型号编码

		50,							//CELLVOLT_MV			BalanceDeltaV;	启动均衡电压差异值
		3900,						//CELLVOLT_MV			BalanceStartV;	启动均衡最低电压阈值
		50,							//TEMPERATURE_1C		BalanceMaxTemp;	均衡板允许最高温度
		2000,						//uint16				BalanceVoltStableTime;	均衡电压等待稳定时间(单位毫秒)
		15,							//uint16				BalanceCtrlCycleTime;	均衡控制周期(单位秒)	


		7200,						//uint16				Normal_SOCOCV_StableTime;	普通稳态点开路电压稳定时间
		60,							//uint16				Charge_SOCOCV_StableTime;	充满电稳态点稳定时间
		4192,						//uint16				Charge_SOCOCV_ValidVolt;	认为充满电阈值电压
		
		2000,				//CURRENT_MA			LowCurVal;低电流判定条件
		800,					//CURRENT_MA			ZeroCurVal;0电流判定条件
		4000,				//CURRENT_MA			ChargeCutOffCurVal;充电停止最小电流

							//报警参数
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

		3650,				//CELLVOLT_MV	CellDiff_VoltBoundary;单体差异判定单体电压分界
		250,					//CELLVOLT_MV	CellDiffAlarm1Val_LowVolt;低电压时单体差异值一级告警
		400,					//CELLVOLT_MV	CellDiffAlarm2Val_LowVolt;低电压时单体差异值二级告警
		150,					//CELLVOLT_MV	CellDiffAlarm1Val_HighVolt;高电压时单体差异值一级告警
		250,					//CELLVOLT_MV	CellDiffAlarm2Val_HighVolt;高电压时单体差异值二级告警

		100,					//uint32		LeakLowVal;绝缘报警1 (K欧)
		30,					//uint32		LeakVeryLowVal;	绝缘报警2 (K欧)

		{{10,2},{50,10},{330,20}},				//电流-电量保存粒度表(0.02, 0.1, 0.2AH)
			
		//电池充放电限制参数
		1,					//uint8	BatLmtParaType;
		//uint8		BatLmtPara[BATLMTPARA_MAXLEN];	电池参数,各个电池自定义

		{  
		    6,           //充电表(LSH0)
		    40,35,  90,0,       0,15,0,50,
		    40,35,  101,90,     0,10,0,30,
		    35,5,   90,0,       0,60,0,100,
		    35,5,   101,90,     0,30,0,60,
		    5,0,    90,0,       0,20,0,50,
		    5,0,    101,90,     0,10,0,20,
		    
		    5,          //放电表
		    60,55,  101,0,      0,100,0,200,
		    55,0,   20,0,       0,100,0,200,
		    55,0,   101,20,     0,200,0x01,0x2C,        //200,300
		    0,-20,  30,0,       0,50,0,100,
		    0,-20,  101,30,     0,100,0,200,
		
		
		},
};
