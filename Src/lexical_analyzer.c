#include "lexical_analyzer.h"
#include "lexical_analyzerCfg.h"
#include <stdio.h>
#include <string.h>

//词法分析预扫描数据流操作方法(取出或者回退)
typedef enum{
	POP = 0,
	PUSH,
}LEX_STREAM_PREOP;
//词法分析预扫描错误定义
typedef enum{
	LEX_PRESCAN_SUCCESS = 0,
	LEX_PRESCAN_END,
	LEX_PRESCAN_OVERFLOW,
	LEX_PRESCAN_FAIL,
}LEX_STREAM_PRESCAN_ERROR;

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
static LEX_STREAM_PRESCAN_ERROR lex_pre_scaner(LEX_SCAN_STREAM *pLexScanStream, char *p_szDest, LEX_STREAM_PREOP lex_preop);

//扫描数据流结构体
LEX_SCAN_STREAM lex_scan_stream;

char Token[LEX_SCAN_PRESCAN_TOKEN_MAX+1][SINGLE_TOKEN_MAXLEN+1];	//一次分析总共要读取的词素个数

LEX_GETSTREAM_ERROR GetStream(void)
{
	//初始化指针
	lex_scan_stream.pScan = 0;
	//按行读取文件,对读取的数据进行预处理
	
	//对全局stream进行赋值
	memcpy(lex_scan_stream.szStream,"fuck i define typedef int uinddddddddddddddsigned ",sizeof("fuck i define typedef int uinsigned +"));
	//保存读取的字符数
	lex_scan_stream.cntLen = sizeof("fuck i define typedef int uinddddddddddddddsigned ");

	return LEX_GETSTREAM_SUCCESS;
}

void main(void)
{
	LEX_STREAM_PRESCAN_ERROR lex_strpre_scan_error;
	//读入数据流
	GetStream();
	do{
			lex_strpre_scan_error = lex_pre_scaner(&lex_scan_stream, Token[0], POP);
			switch(lex_strpre_scan_error)
	 		{
				case LEX_PRESCAN_END:
					printf("\r\n输入流解析完毕");
					break;

				case LEX_PRESCAN_SUCCESS:
					printf("\r\n词素：%s",Token[0]);
					break;

				case LEX_PRESCAN_OVERFLOW:
					printf("\r\n单个词素长度超界限");
					break;

				default:
					printf("\r\n预扫描返回异常");
					break;
	  		}
    	}while(LEX_PRESCAN_END != lex_strpre_scan_error);
    getchar();
 }

//词法分析预扫描函数
static LEX_STREAM_PRESCAN_ERROR lex_pre_scaner(
	LEX_SCAN_STREAM *pLexScanStream, char *p_szDest, LEX_STREAM_PREOP lex_preop)
{
	int m = 0;
	char ch;
	//若为取出Token操作，清空buff
	if(POP == lex_preop){
		memset(p_szDest, '\0', SINGLE_TOKEN_MAXLEN);
	}
	
	if(pLexScanStream->pScan >= pLexScanStream->cntLen){
			return LEX_PRESCAN_END;			//处理完全部的数据流
	}
		
	//跳过空格和Tab
    do{
		ch=pLexScanStream->szStream[pLexScanStream->pScan++];
	}while((ch==' ' || ch=='\t') && pLexScanStream->pScan<pLexScanStream->cntLen);

	if(ch == ' ' || ch == '\t' || ch == '\0'){
		return LEX_PRESCAN_END;			//处理完全部的数据流
	}
	p_szDest[m++]=ch;
	//处理字母或'_'打头的词素
    if((ch<='z' && ch>='a')||(ch<='Z' && ch>='A')|| ch=='_'){ 
      	while(ch!=' ' && ch!='\t' && m<SINGLE_TOKEN_MAXLEN && pLexScanStream->pScan<pLexScanStream->cntLen){
			ch=pLexScanStream->szStream[pLexScanStream->pScan++];
			p_szDest[m++]=ch;
		};

		if(m >= SINGLE_TOKEN_MAXLEN){
			return LEX_PRESCAN_OVERFLOW;	//单个词素长度超界
		}
		p_szDest[m] = '\0';
		return LEX_PRESCAN_SUCCESS;
     }
	return LEX_PRESCAN_FAIL;
}