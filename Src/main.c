#include <stdio.h>
#include "Struct_AnalyzerCfg.h"

/**********************************************************
以下为最终解释出来的数据类型以及最终数据类型枚举关联定义
**********************************************************/
typedef enum {
	FinalTypeEnumStart = 0,
	t_int8 = FinalTypeEnumStart,		t_uint8,
	t_int16,	t_uint16,
	t_int32,	t_uint32,
	Struct,		//如果成员为一个子结构体，其类型不能从FinalTypeStruct中获取
				//需要查找当前Token列表，确定其对应的结构体(待定)
	FinalTypeEnumEnd,
}FinalTypeEnum;

const char FinalTypeStruct[FinalTypeEnumEnd][FINALTYPE_CHAR_MAXLEN] = {
	"<signed char>",	"<unsigned char>",	//int8,uint8
	"<signed short>",	"<unsigned short>",	//int16,uint16
	"<signed long>",	"<unsigned long>",	//int32,uint32
};

/**********************************************************
以下为最终解释出来的目标结构体信息结构体，以及每个成员结构体
***********************************************************/
//生成的目标结构体成员信息
typedef struct{
	FinalTypeEnum fteType;
	char szTitle[MEMBER_TITLE_MAXLEN];
}MEMBER_INFO;

//生成的目标结构体信息
typedef struct{
	int nMemberCnt;
	MEMBER_INFO Member_Info[MEMBER_COUNT_MAXNUM];
}DESTSTRUCT_INFO;


//打印目标结构体信息到控制台,成功返回0
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
			return 2;	//成员个数超过99，buff溢出
		}
		printf("\r\n%-10s%-20s%-20s", tmp, \
			pDestStruct_Info->Member_Info[i].szTitle, \
			FinalTypeStruct[pDestStruct_Info->Member_Info[i].fteType]);
	}
	return 0;
}

//测试结构体信息输出数据TestFor Print_DestStructInfo()
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