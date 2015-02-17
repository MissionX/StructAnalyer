#ifndef __LEXICAL_ANALYZERCFG_H__
#define __LEXICAL_ANALYZERCFG_H__

#define SINGLE_TOKEN_MAXLEN			20	//单个语素最大支持长度
#define LEX_SCAN_PRESCAN_TOKEN_MAX	1	//词法分析器最多支持预扫描的词素个数
#define LEX_INPUT_STREAM_MAXLEN		200	//词法分析器一次性输入字符串流最大长度

/***************************************************
词法分析器最终返回的词素Type定义(待补充)

数据类型	1
include		2
define		3
typedef		4
struct		5
enum		6
#			7
{			8
}			9
;			10
**********************************************************/
typedef struct{
	int nType;
	char szString;
}LEX_ANALYZE_RESULT;


/**********************************************************
以下为默认词素表枚举关联
**********************************************************
typedef enum{
	lex_DefTypeEnumStart = 0,
	lex_t_uchar = lex_DefTypeEnumStart,	lex_t_schar,	lex_char,
	lex_t_uint,		lex_t_sint,		lex_t_int,
	lex_t_ulong,	lex_t_slong,	lex_t_long,
	lex_DefTypeEnumEnd,
};
*/

extern const char *lex_DefTokenTab[SINGLE_TOKEN_MAXLEN];








#endif