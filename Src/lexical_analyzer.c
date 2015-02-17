#include "lexical_analyzer.h"
#include "lexical_analyzerCfg.h"
#include <stdio.h>
#include <string.h>

/**********************************************************
����ΪĬ�ϴ��ر�
**********************************************************/
#define LEX_CHDEFTOKEN_OFFSET	40	//�ַ��������Ͷ���ƫ����
const char lex_DefchTokenTab[] = {
	'#',		//40
	'{',		//41
	'}',		//42
	'[',		//43
	']',		//44
	';',		//45
};
#define LEX_SZDEFTOKEN_TYPE_NUM		9	//�������ʹ�����Ŀ
#define LEX_SZDEFTOKEN_OTHER_OFFSET	20	//�������ʹ���ƫ��
const char lex_DefszTokenTab[][SINGLE_TOKEN_MAXLEN]={
	"unsigned char",	"signed char",	"char",
	"unsgined int",		"signed int",	"int",
	"unsigned long",	"signed long",	"long",	//1

	"include",	//20
	"define",	//21
	"typedef",	//22
	"struct",	//23
	"enum",		//24

};

//�ʷ�����Ԥɨ����������������(ȡ�����߻���)
typedef enum{
	POP = 0,
	PUSH,
}LEX_STREAM_PREOP;
//�ʷ�����Ԥɨ�������
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

//ɨ���������ṹ������
typedef struct{
	int pScan;
	int cntLen;
	char szStream[LEX_INPUT_STREAM_MAXLEN];	//stream�ﲻӦ���� ��\n�� �� ��\�������ַ�
}LEX_SCAN_STREAM;

//�ʷ�����Ԥɨ�躯��
static LEX_STREAM_PRESCAN_ERROR lex_pre_scaner(LEX_SCAN_STREAM *pLexScanStream, char *p_szDest, LEX_STREAM_PREOP lex_preop);

//ɨ���������ṹ��
LEX_SCAN_STREAM lex_scan_stream;

char Token[LEX_SCAN_PRESCAN_TOKEN_MAX+1][SINGLE_TOKEN_MAXLEN+1];	//һ�η����ܹ�Ҫ��ȡ�Ĵ��ظ���

LEX_GETSTREAM_ERROR GetStream(void)
{
	const char teststream[] = "int char[] _fuck";
	//��ʼ��ָ��
	lex_scan_stream.pScan = 0;
	//���ж�ȡ�ļ�,�Զ�ȡ�����ݽ���Ԥ����
	
	//��ȫ��stream���и�ֵ
	memcpy(lex_scan_stream.szStream, teststream, sizeof(teststream));
	//�����ȡ���ַ���
	lex_scan_stream.cntLen = sizeof(teststream);

	return LEX_GETSTREAM_SUCCESS;
}

void main(void)
{
	LEX_STREAM_PRESCAN_ERROR lex_strpre_scan_error;
	//����������
	GetStream();
	do{
			lex_strpre_scan_error = lex_pre_scaner(&lex_scan_stream, Token[0], POP);
			switch(lex_strpre_scan_error)
	 		{
				case LEX_PRESCAN_END:
					printf("\r\n�������������");
					break;

				case LEX_PRESCAN_SUCCESS:
					printf("\r\n���أ�%s",Token[0]);
					break;

				case LEX_PRESCAN_OVERFLOW:
					printf("\r\n�������س��ȳ�����");
					break;

				default:
					printf("\r\nԤɨ�践���쳣");
					break;
	  		}
    	}while(LEX_PRESCAN_END != lex_strpre_scan_error);
    getchar();
 }

//�ʷ�����Ԥɨ�躯��
static LEX_STREAM_PRESCAN_ERROR lex_pre_scaner(
	LEX_SCAN_STREAM *pLexScanStream, char *p_szDest, LEX_STREAM_PREOP lex_preop)
{
	int m = 0;
	char ch;
	//��Ϊȡ��Token���������buff
	if(POP == lex_preop){
		memset(p_szDest, '\0', SINGLE_TOKEN_MAXLEN);
	}
	
	if(pLexScanStream->pScan >= pLexScanStream->cntLen){
			return LEX_PRESCAN_END;			//������ȫ����������
	}
		
	//�����ո��Tab
    do{
		ch=pLexScanStream->szStream[pLexScanStream->pScan++];
	}while((ch==' ' || ch=='\t') && pLexScanStream->pScan<pLexScanStream->cntLen);

	if(ch == ' ' || ch == '\t' || ch == '\0'){		//��Ӧ�����������
		return LEX_PRESCAN_END;			//������ȫ����������
	}
	p_szDest[m++]=ch;
	//������ĸ��'_'��ͷ�Ĵ���
    if((ch<='z' && ch>='a')||(ch<='Z' && ch>='A')|| ch=='_'){ 
      	while(Lex_FindTokenTab(&ch,1) == 0 && ch!=' ' && ch!='\t' &&\
				m<SINGLE_TOKEN_MAXLEN && pLexScanStream->pScan<pLexScanStream->cntLen){
			ch=pLexScanStream->szStream[pLexScanStream->pScan++];
			p_szDest[m++]=ch;
		};
		pLexScanStream->pScan--;
		m--;

		if(m >= SINGLE_TOKEN_MAXLEN){
			return LEX_PRESCAN_OVERFLOW;	//�������س��ȳ���
		}
		p_szDest[m] = '\0';
		return LEX_PRESCAN_SUCCESS;
     }
	return LEX_PRESCAN_FAIL;
}


static int Lex_FindTokenTab(char *pSrc, int nLen)
{
	int i;
	if(nLen == 0){
		return 0;

	}else if(nLen > SINGLE_TOKEN_MAXLEN){
		return 0;

	}else if(1 == nLen){
		for(i=0; i<sizeof(lex_DefchTokenTab); i++){
			if(*pSrc == lex_DefchTokenTab[i]){
				return (i+LEX_CHDEFTOKEN_OFFSET);
			}
		}
		return 0;	//δ�ҵ�Ĭ���ַ�token

	}else {
		for(i=0; i<sizeof(lex_DefszTokenTab)/sizeof(lex_DefszTokenTab[0]); i++){
			if(memcmp(pSrc, lex_DefszTokenTab[i], nLen) == 0){
				return i;
			}
		}
		return 0;
	}
}