#ifndef __LEXICAL_ANALYZERCFG_H__
#define __LEXICAL_ANALYZERCFG_H__

#define SINGLE_TOKEN_MAXLEN			20	//�����������֧�ֳ���
#define LEX_SCAN_PRESCAN_TOKEN_MAX	2	//�ʷ����������֧��Ԥɨ��Ĵ��ظ���
#define LEX_INPUT_STREAM_MAXLEN		200	//�ʷ�������һ���������ַ�������󳤶�


/***************************************************
�ʷ����������շ��صĴ���Type����(������)

��������	1
include		20
define		21
typedef		22
struct		23
enum		24
#			40
{			41
}			42
[			43
]			44
;			45
**********************************************************/
typedef struct{
	int nType;
	char szString[SINGLE_TOKEN_MAXLEN];
}LEX_ANALYZE_RESULT;


/**********************************************************
����ΪĬ�ϴ��ر�ö�ٹ���
**********************************************************
typedef enum{
	lex_DefTypeEnumStart = 0,
	lex_t_uchar = lex_DefTypeEnumStart,	lex_t_schar,	lex_char,
	lex_t_uint,		lex_t_sint,		lex_t_int,
	lex_t_ulong,	lex_t_slong,	lex_t_long,
	lex_DefTypeEnumEnd,
};
*/








#endif