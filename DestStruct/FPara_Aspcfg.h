#ifndef __PARA_ASPCFG_H_
#define __PARA_ASPCFG_H_

#include "GlobalType.h"



//����FPARA�������ַ
#define FPARA_PAGEA_PHYADDR		0x11800	//ʵ�ʵ�ַ��0x10000
#define FPARA_PAGEB_PHYADDR		0x11C00	//ʵ�ʵ�ַ��0x10200
#define FPARA_PAGE_SIZE				512

#define 	VIN_CODE_LEN			17
#define 	VENDOR_LEN				4
#define	PRODUCTCODE_LEN		16

#define	BATLMTPARA_MAXLEN	160

#define CURR_IDMAX				2
#define CELLNUM_MAX			26
#define TEMPNUM_MAX			10

//��ѹУ׼
#pragma pack(1)
typedef struct
{
	uint16 	K;
	int8	B;
}AFE680XCALIBRATE;
#pragma pack()

//����- �����������ȱ����ݸ���
#define SOC_CURRENT_Q_SAVEUNIT_TABLENUM		3	// 3��
//���� - �����������ȱ����ݽṹ
#pragma pack(1)
typedef struct{
	uint16	Current;		//��λ����
	uint8	QSave_UnitMultiple;	//��λ0.01AH
}BMSSOC_CURRENT_Q_SAVEUINT;
#pragma pack()

typedef struct
{
VOLT_01MV		CurrCalibrateVal[CURR_IDMAX];			//����У׼ֵ
AFE680XCALIBRATE	CellCalibrateVal[CELLNUM_MAX];		//��ѹУ׼ֵ
AFE680XCALIBRATE	TempCalibrateVal[TEMPNUM_MAX];		//�¶�У׼ֵ
uint8			ProductCode[PRODUCTCODE_LEN];			//BMS���
uint8 			Vin_Code[VIN_CODE_LEN];					//����vin

//////////////////////////////���¿�ͨ��FPara�����޸�/////////////////////////////////////////////////////
BOOLEAN				bCurrAutoCalibrate;
uint8				PreChargeVoltK;						//Ԥ���ѹ�Ǻ϶ȣ�������ֵ����ΪԤ�����
TERMINALVOLT_MV	Ratedvolt;							//���ѹ
QTYPE_01AH			QmaxSet;							//��������ֵ(0.1AH)(�����ٴ��趨)
QTYPE_01AH			QmaxRate;							//�������ֵ(0.1AH)(�)
uint8				ParallelNum;						//��ز�����
uint8 				CellNum;							//�ϱ�������
uint8				bCellReport[(CELLNUM_MAX+7)/8];		//�ϱ�������
uint8				TempNum;							//�ϱ��¶���
uint8 				Right;
uint8 				Day;
uint8 				Month;
uint8 				Year;
uint8 				BatType;
uint8				Vendor[VENDOR_LEN];							//����ͺű���

CELLVOLT_MV			BalanceDeltaV;								//���������ѹ����ֵ 
CELLVOLT_MV			BalanceStartV;								//����������͵�ѹ��ֵ
TEMPERATURE_1C		BalanceMaxTemp;							//�������������¶�
uint16				BalanceVoltStableTime;						//�����ѹ�ȴ��ȶ�ʱ��(��λ����)
uint16				BalanceCtrlCycleTime;						//�����������(��λ��)

uint16				Normal_SOCOCV_StableTime;					//��ͨ��̬�㿪·��ѹ�ȶ�ʱ��
uint16				Charge_SOCOCV_StableTime;					//��������̬���ȶ�ʱ��
uint16				Charge_SOCOCV_ValidVolt;					//��Ϊ��������̬����Ч��ֵ��ѹ

CURRENT_MA			LowCurVal;									//�͵����ж�����
CURRENT_MA			ZeroCurVal;									//0�����ж�����
CURRENT_MA			ChargeCutOffCurVal;							//���ֹͣ��С����

//��������
CELLVOLT_MV			CellHighVal;
CELLVOLT_MV			CellVeryHighVal;
CELLVOLT_MV			CellLowVal;
CELLVOLT_MV			CellVeryLowVal;

TEMPERATURE_1C		ChargeTempHighVal;
TEMPERATURE_1C		ChargeTempVeryHighVal;
TEMPERATURE_1C		ChargeTempLowVal;
TEMPERATURE_1C		ChargeTempVeryLowVal;

TEMPERATURE_1C		DisChargeTempHighVal;
TEMPERATURE_1C		DisChargeTempVeryHighVal;
TEMPERATURE_1C		DisChargeTempLowVal;
TEMPERATURE_1C		DisChargeTempVeryLowVal;

TEMPERATURE_1C	TempDiffVal;
TEMPERATURE_1C	TempVeryDiffVal;

SOCSOH			SOCLowVal;
SOCSOH			SOCVeryLowVal;
SOCSOH			SOCHighVal;
SOCSOH			SOCVeryHighVal;

CELLVOLT_MV		CellDiff_VoltBoundary;						//��������ж������ѹ�ֽ�
CELLVOLT_MV		CellDiffAlarm1Val_LowVolt;					//�͵�ѹʱ�������ֵһ���澯
CELLVOLT_MV		CellDiffAlarm2Val_LowVolt;					//�͵�ѹʱ�������ֵ�����澯
CELLVOLT_MV		CellDiffAlarm1Val_HighVolt;					//�ߵ�ѹʱ�������ֵ
CELLVOLT_MV		CellDiffAlarm2Val_HighVolt;

uint32		LeakLowVal;										//��Ե����1 (Kŷ)
uint32		LeakVeryLowVal;									//��Ե����2 (Kŷ)

BMSSOC_CURRENT_Q_SAVEUINT BmsSoc_Current_Q_SaveUnitTable[SOC_CURRENT_Q_SAVEUNIT_TABLENUM];	//����-�����������ȱ�

//��س�ŵ����Ʋ���
uint8		BatLmtParaType;
uint8		BatLmtPara[BATLMTPARA_MAXLEN];					//��ز���,��������Զ���

}FPARA;
extern const FPARA* IR_FPara;
extern const FPARA FPara_AspDefaultPara;


#define FPara_ProductID						(*((const uint32 *)0x100))
#define FPara_HardVer						(*((const uint16 *)0x104))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�����ӿ�
#define FPara_CurrCalibrateVal				(IR_FPara->CurrCalibrateVal)
#define FPara_CellCalibrateVal				(IR_FPara->CellCalibrateVal)
#define FPARA_bCurrAutoCalibrate				(IR_FPara->bCurrAutoCalibrate)
#define FPara_CellNum						(IR_FPara->CellNum)
#define FPara_TempNum						(IR_FPara->TempNum)
#define FPara_bCellReport					(IR_FPara->bCellReport)
#define FPARA_LowCurVal						(IR_FPara->LowCurVal)
#define FPARA_ZeroCurVal					(IR_FPara->ZeroCurVal)
#define FPARA_CellDiff_VoltBoundary			(IR_FPara->CellDiff_VoltBoundary)
#define FPARA_CellDiffAlarm2Val_HighVolt		(IR_FPara->CellDiffAlarm2Val_HighVolt)
#define FPARA_CellDiffAlarm1Val_HighVolt		(IR_FPara->CellDiffAlarm1Val_HighVolt)
#define FPARA_CellDiffAlarm2Val_LowVolt		(IR_FPara->CellDiffAlarm2Val_LowVolt)
#define FPARA_CellDiffAlarm1Val_LowVolt		(IR_FPara->CellDiffAlarm1Val_LowVolt)
#define FPARA_ChargeTempVeryHighVal		(IR_FPara->ChargeTempVeryHighVal)
#define FPARA_ChargeTempHighVal			(IR_FPara->ChargeTempHighVal)
#define FPARA_ChargeTempVeryLowVal		(IR_FPara->ChargeTempVeryLowVal)
#define FPARA_ChargeTempLowVal			(IR_FPara->ChargeTempLowVal)
#define FPARA_DisChargeTempVeryHighVal		(IR_FPara->DisChargeTempVeryHighVal)
#define FPARA_DisChargeTempHighVal			(IR_FPara->DisChargeTempHighVal)
#define FPARA_DisChargeTempVeryLowVal		(IR_FPara->DisChargeTempVeryLowVal)
#define FPARA_DisChargeTempLowVal			(IR_FPara->DisChargeTempLowVal)
#define FPARA_TempVeryDiffVal				(IR_FPara->TempVeryDiffVal)
#define FPARA_TempDiffVal					(IR_FPara->TempDiffVal)

#define FPARA_CellVeryHighVal				(IR_FPara->CellVeryHighVal)
#define FPARA_CellHighVal					(IR_FPara->CellHighVal)
#define FPARA_CellVeryLowVal				(IR_FPara->CellVeryLowVal)
#define FPARA_CellLowVal						(IR_FPara->CellLowVal)

#define FPARA_SOCVeryLowVal				(IR_FPara->SOCVeryLowVal)
#define FPARA_SOCLowVal					(IR_FPara->SOCLowVal)
#define FPARA_SOCVeryHighVal				(IR_FPara->SOCVeryHighVal)
#define FPARA_SOCHighVal					(IR_FPara->SOCHighVal)

#define FPARA_LeakVeryLowVal				(IR_FPara->LeakVeryLowVal)
#define FPARA_LeakLowVal					(IR_FPara->LeakLowVal)

#define FPARA_BatLmtParaType				(IR_FPara->BatLmtParaType)
#define FPARA_pBatLmtPara					(IR_FPara->BatLmtPara)

#define 	FPARA_ProductCode					(IR_FPara->ProductCode)
#define 	FPARA_VinCode						(IR_FPara->Vin_Code)
#define 	FPARA_PreChargeVoltK				(IR_FPara->PreChargeVoltK)

#define 	FPARA_RatedVolt					(IR_FPara->Ratedvolt)
#define 	FPARA_QMaxRate					(IR_FPara->QmaxRate)
#define 	FPARA_QMaxSet						(IR_FPara->QmaxSet)
#define 	FPARA_ParallelNum				(IR_FPara->ParallelNum)
#define 	FPARA_Vendor						(IR_FPara->Vendor)

#define	FPARA_BalanceDeltaV				(IR_FPara->BalanceDeltaV)
#define	FPARA_BalanceStartV				(IR_FPara->BalanceStartV)
#define	FPARA_BalanceMaxTemp				(IR_FPara->BalanceMaxTemp)
#define	FPARA_BalanceVoltStableTime		(IR_FPara->BalanceVoltStableTime)
#define	FPARA_BalanceCtrlCycleTime			(IR_FPara->BalanceCtrlCycleTime)

#define	FPARA_SocStableTime				(IR_FPara->Normal_SOCOCV_StableTime)
#define	FPARA_Charge_SOCOCV_ValidVolt		(IR_FPara->Charge_SOCOCV_ValidVolt)
#define	FPARA_Charge_SOCOCV_StableTime	(IR_FPara->Charge_SOCOCV_StableTime)

#define	FPARA_IQ_Save_Unit_Table	(IR_FPara->BmsSoc_Current_Q_SaveUnitTable)

#define	FPARA_ChargeCutOffCurrVal			(IR_FPara->ChargeCutOffCurVal)

#define   FPARA_Right							(IR_FPara->Right)
#define   FPARA_Day							(IR_FPara->Day)
#define   FPARA_Month						(IR_FPara->Month)
#define   FPARA_Year							(IR_FPara->Year)
#define   FPARA_BatType						(IR_FPara->BatType)

//�ɽ����������õĵ�ַ
#define FPARA_BATCHCONFIG_ADDR			((uint16)(&(IR_FPara->bCurrAutoCalibrate))-(uint16)(IR_FPara))

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//д��ӿ�
#define FParaSet_QmaxSet(Val)					(FPara_SetData(&(Val), (uint16)(&(IR_FPara->QmaxSet))-(uint16)(IR_FPara), sizeof(IR_FPara->QmaxSet)))
#define FParaSet_CurrCalibrateVal(CurrID,Val)		(FPara_SetData(&(Val), (uint16)(&(IR_FPara->CurrCalibrateVal[CurrID]))-(uint16)(IR_FPara), sizeof(IR_FPara->CurrCalibrateVal[CurrID])))
#define FParaSet_CellCalibrateVal(CellID,Val)		(FPara_SetData(&(Val), (uint16)(&(IR_FPara->CellCalibrateVal[CellID]))-(uint16)(IR_FPara), sizeof(IR_FPara->CellCalibrateVal[CellID])))
#define FParaSet_TempCalibrateVal(TempID,Val)	(FPara_SetData(&(Val), (uint16)(&(IR_FPara->TempCalibrateVal[TempID]))-(uint16)(IR_FPara), sizeof(IR_FPara->TempCalibrateVal[TempID])))
#define FParaSet_ProductCode(pVal,Offset, Len)	(FPara_SetData(pVal, (uint16)(&(IR_FPara->ProductCode[Offset]))-(uint16)(IR_FPara),Len))
#define FParaSet_VinCode(pVal,Offset,Len)			(FPara_SetData(pVal, (uint16)(&(IR_FPara->Vin_Code[Offset]))-(uint16)(IR_FPara),Len))
#endif//__PARA_ASPCFG_H_	

