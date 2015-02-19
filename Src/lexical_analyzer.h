#ifndef __LEXICAL_ANALYZER_H__
#define __LEXICAL_ANALYZER_H__

#include "lexical_analyzerCfg.h"

//�ʷ�����ɨ�������
typedef enum{
	LEX_SCAN_SUCCESS = 0,
	LEX_SCAN_END,
	LEX_SCAN_OVERFLOW,
	LEX_SCAN_FAIL,
}LEX_STREAM_SCAN_ERROR;

void lex_analyze_init(void);
LEX_STREAM_SCAN_ERROR lex_analyze(LEX_ANALYZE_RESULT *pTokenGet);

#endif