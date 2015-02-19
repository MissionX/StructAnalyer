#include <stdio.h>
#include "Struct_AnalyzerCfg.h"

/**********************************************************
����Ϊ���ս��ͳ��������������Լ�������������ö�ٹ�������
**********************************************************/
typedef enum {
	FinalTypeEnumStart = 0,
	t_int8 = FinalTypeEnumStart,		t_uint8,
	t_int16,	t_uint16,
	t_int32,	t_uint32,
	Struct,		//�����ԱΪһ���ӽṹ�壬�����Ͳ��ܴ�FinalTypeStruct�л�ȡ
				//��Ҫ���ҵ�ǰToken�б�ȷ�����Ӧ�Ľṹ��(����)
	FinalTypeEnumEnd,
}FinalTypeEnum;

const char FinalTypeStruct[FinalTypeEnumEnd][FINALTYPE_CHAR_MAXLEN] = {
	"<signed char>",	"<unsigned char>",	//int8,uint8
	"<signed short>",	"<unsigned short>",	//int16,uint16
	"<signed long>",	"<unsigned long>",	//int32,uint32
};

/**********************************************************
����Ϊ���ս��ͳ�����Ŀ��ṹ����Ϣ�ṹ�壬�Լ�ÿ����Ա�ṹ��
***********************************************************/
//���ɵ�Ŀ��ṹ���Ա��Ϣ
typedef struct{
	FinalTypeEnum fteType;
	char szTitle[MEMBER_TITLE_MAXLEN];
}MEMBER_INFO;

//���ɵ�Ŀ��ṹ����Ϣ
typedef struct{
	int nMemberCnt;
	MEMBER_INFO Member_Info[MEMBER_COUNT_MAXNUM];
}DESTSTRUCT_INFO;


//��ӡĿ��ṹ����Ϣ������̨,�ɹ�����0
char Print_DestStructInfo(DESTSTRUCT_INFO *pDestStruct_Info)
{
	int i;
	char tmp[4];
	if(pDestStruct_Info->nMemberCnt >= MEMBER_TITLE_MAXLEN && NULL != pDestStruct_Info){
		return 1;
	}
	printf("\r\n%-10s%-20s%-20s","Member","Title","Type");
	for(i=0; i<pDestStruct_Info->nMemberCnt; i++){
		sprintf(tmp,"[%d]",i+1);
		if(tmp[3] != '\0'){
			return 2;	//��Ա��������99��buff���
		}
		printf("\r\n%-10s%-20s%-20s", tmp, \
			pDestStruct_Info->Member_Info[i].szTitle, \
			FinalTypeStruct[pDestStruct_Info->Member_Info[i].fteType]);
	}
	return 0;
}

//���Խṹ����Ϣ�������TestFor Print_DestStructInfo()
const DESTSTRUCT_INFO Test_DestStruct_Info[] = 
{
	6,
	{
		{t_uint8,  "member1_uint8"},  {t_int8, "member2_int8"},\
		{t_uint16, "member3_uint16"},{t_int16, "member4_int16"},\
		{t_uint32, "member5_uint32"},{t_int32, "member6_int32"}
	},
};

int main(int argc, char* argv[])
{
	LEX_ANALYZE_RESULT lex_analyze_token;
	LEX_STREAM_SCAN_ERROR lex_alanyze_rst;
	lex_analyze_init();
	lex_alanyze_rst = lex_analyze(&lex_analyze_token);
	while(lex_alanyze_rst != LEX_SCAN_END){
		printf("\r\nToken[%d]:\t%s",lex_analyze_token.nType,\
							lex_analyze_token.szString);
		lex_alanyze_rst = lex_analyze(&lex_analyze_token);
	}
//	Print_DestStructInfo((DESTSTRUCT_INFO *)Test_DestStruct_Info);
	getchar();
	return 0;
}