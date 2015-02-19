#include "lexical_analyzer.h"
#include "lexical_analyzerCfg.h"
#include <stdio.h>
#include <string.h>

/**********************************************************
以下为默认词素表
**********************************************************/
#define LEX_SZDEFTOKEN_OTHER_START	9	//其他保留字类型词素开始
#define LEX_SZDEFTOKEN_OTHER_OFFSET	20	//其他保留字类型词素偏移量
#define LEX_CHDEFTOKEN_START		14	//字符词素开始
#define LEX_CHDEFTOKEN_OFFSET		40	//字符词素偏移量
const char lex_DefszTokenTab[][SINGLE_TOKEN_MAXLEN]={
	"unsignedchar",	"signedchar",	"char",
	"unsignedint",	"signedint",	"int",
	"unsignedlong",	"signedlong",	"long",	//1

	"include",	//20
	"define",	//21
	"typedef",	//22
	"struct",	//23
	"enum",		//24

	"#",		//40
	"{",		//41
	"}",		//42
	"[",		//43
	"]",		//44
	";",		//45
	":",		//46
	"\"",		//47
	"<",		//48
	">",		//49
	".",		//50
};

//词法分析预扫描数据流操作方法(取出或者回退)
typedef enum{
	POP = 0,
	PUSH,
}LEX_STREAM_PREOP;

typedef enum{
	LEX_GETSTREAM_SUCCESS = 0,
	LEX_GETSTREAM_END,
	LEX_GETSTREAM_FAIL,
}LEX_GETSTREAM_ERROR;

//扫描数据流结构体声明
typedef struct{
	int pScan;
	int cntLen;
	char szStream[LEX_INPUT_STREAM_MAXLEN];	//stream里不应出现 ‘\n’ 和 ‘\’连接字符
}LEX_SCAN_STREAM;

//词法分析预扫描函数
static LEX_STREAM_SCAN_ERROR lex_pre_scaner(char *p_szDest, LEX_STREAM_PREOP lex_preop);
//默认词素查找函数
static int Lex_FindTokenTab(char *pSrc, char ch);

//扫描数据流结构体
LEX_SCAN_STREAM lex_scan_stream;

char Token[LEX_SCAN_PRESCAN_TOKEN_MAX][SINGLE_TOKEN_MAXLEN];	//一次分析总共要读取的词素个数
char dstToken[SINGLE_TOKEN_MAXLEN*LEX_SCAN_PRESCAN_TOKEN_MAX];

LEX_GETSTREAM_ERROR GetStream(void)
{
	const char teststream[] = "#include <stdio.h>     char unsigned char int \tint int ";
	printf("\r\nInputStream: %s",teststream);
	//初始化指针
	lex_scan_stream.pScan = 0;
	//按行读取文件,对读取的数据进行预处理
	
	//对全局stream进行赋值
	memcpy(lex_scan_stream.szStream, teststream, sizeof(teststream));
	//保存读取的字符数
	lex_scan_stream.cntLen = sizeof(teststream);

	return LEX_GETSTREAM_SUCCESS;
}

void lex_analyze_init(void)
{
	//读入数据流
	GetStream();
}
//词法分析函数
LEX_STREAM_SCAN_ERROR lex_analyze(LEX_ANALYZE_RESULT *pTokenGet)
{
	int i,j,offsetToken,cntTokenNum;
	LEX_STREAM_SCAN_ERROR lex_str_scan_error;
	
	cntTokenNum = 0;
	for(i=0; i<LEX_SCAN_PRESCAN_TOKEN_MAX; i++){
		lex_str_scan_error = lex_pre_scaner(Token[i], POP);
		if(lex_str_scan_error == LEX_SCAN_END){
			break;
		}else if(lex_str_scan_error == LEX_SCAN_OVERFLOW){
			return LEX_SCAN_OVERFLOW;
		}
		cntTokenNum++;
	}
	if(cntTokenNum == 0){
		return LEX_SCAN_END;
	}
	for(i=0; i<cntTokenNum; i++){
		memset(dstToken, 0, sizeof(dstToken));
		for(j=0; j<cntTokenNum-i; j++){
			strcat(dstToken, Token[j]);
		}
		offsetToken = Lex_FindTokenTab(dstToken,0);
		if(offsetToken != 0){
			pTokenGet->nType = offsetToken;
			strcpy(pTokenGet->szString, dstToken);
			return LEX_SCAN_SUCCESS;
		}else if(cntTokenNum-i-1 == 0){		//第一个token不必回退
			pTokenGet->nType = offsetToken = 0;	
			strcpy(pTokenGet->szString, dstToken);
		}else{
			lex_pre_scaner(Token[cntTokenNum-i-1], PUSH);
		}
	}
	return LEX_SCAN_FAIL;
 }

//词法分析预扫描函数
static LEX_STREAM_SCAN_ERROR lex_pre_scaner(char *p_szDest, LEX_STREAM_PREOP lex_preop)
{
	int m = 0;
	char ch;
	//若为取出Token操作，清空buff
	if(POP == lex_preop){
		memset(p_szDest, '\0', SINGLE_TOKEN_MAXLEN);
	}else{
		lex_scan_stream.pScan -= strlen(p_szDest);
		while(lex_scan_stream.pScan > 0 && \
				(lex_scan_stream.szStream[lex_scan_stream.pScan-1] == ' ' || \
				lex_scan_stream.szStream[lex_scan_stream.pScan-1] == '\t')){
			lex_scan_stream.pScan--;
		}
		return LEX_SCAN_SUCCESS;
	}
	
	if(lex_scan_stream.pScan >= lex_scan_stream.cntLen){
			return LEX_SCAN_END;			//处理完全部的数据流
	}
		
	//跳过空格和Tab
    do{
		ch=lex_scan_stream.szStream[lex_scan_stream.pScan++];
	}while((ch==' ' || ch=='\t') && lex_scan_stream.pScan<lex_scan_stream.cntLen);

	if(ch == ' ' || ch == '\t' || ch == '\0'){		//对应上述三种情况
		return LEX_SCAN_END;			//处理完全部的数据流
	}
	p_szDest[m++]=ch;
	//处理字母或'_'打头的词素
    if((ch<='z' && ch>='a')||(ch<='Z' && ch>='A')|| ch=='_'){ 
      	while(Lex_FindTokenTab(NULL, ch) == 0 && ch!=' ' && ch!='\t' &&\
				m<SINGLE_TOKEN_MAXLEN && lex_scan_stream.pScan<lex_scan_stream.cntLen){
			ch=lex_scan_stream.szStream[lex_scan_stream.pScan++];
			p_szDest[m++]=ch;
		};
		lex_scan_stream.pScan--;
		m--;

		if(m >= SINGLE_TOKEN_MAXLEN){
			return LEX_SCAN_OVERFLOW;	//单个词素长度超界
		}
		p_szDest[m] = '\0';
		return LEX_SCAN_SUCCESS;
	
	}else{
		p_szDest[m] = '\0';
		return LEX_SCAN_SUCCESS;
	}
}


static int Lex_FindTokenTab(char *pSrc, char ch)
{
	int i;
	if(NULL == pSrc){
		for(i=LEX_CHDEFTOKEN_START; i<sizeof(lex_DefszTokenTab)/sizeof(lex_DefszTokenTab[0]); i++){
			if(ch == lex_DefszTokenTab[i][0]){
				return (i-LEX_CHDEFTOKEN_START+LEX_CHDEFTOKEN_OFFSET);
			}
		}
		return 0;	//未找到默认字符token

	}else {
		for(i=0; i<sizeof(lex_DefszTokenTab)/sizeof(lex_DefszTokenTab[0]); i++){
			if(strcmp(pSrc, lex_DefszTokenTab[i]) == 0){
				if(i < LEX_SZDEFTOKEN_OTHER_START){
					return 1;
				}else if(i < LEX_CHDEFTOKEN_START){
					return (i-LEX_SZDEFTOKEN_OTHER_START+LEX_SZDEFTOKEN_OTHER_OFFSET);
				}else{
					return (i-LEX_CHDEFTOKEN_START+LEX_CHDEFTOKEN_OFFSET);
				}
			}
		}
		return 0;
	}
}