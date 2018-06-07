/**
@brief : 문자열을 잘라주는 함수입니다.
@strOrigin : 자를 데이터
@strTok : 분기줄 데이터
@string : 반환형 , 배열로 인자전달
*/
#pragma once
#include "subFunc.h"
string* StringSplit(string strTarget, string strTok)
{
	int D_MAX_ARRAY_SIZE = 100;
	int     nCutPos;
	int     nIndex = 0;
	string* strResult = new string[D_MAX_ARRAY_SIZE];

	while ((nCutPos = strTarget.find_first_of(strTok)) != strTarget.npos)
	{
		if (nCutPos > 0)
		{
			strResult[nIndex++] = strTarget.substr(0, nCutPos);
		}
		strTarget = strTarget.substr(nCutPos + 1);
	}

	if (strTarget.length() > 0)
	{
		strResult[nIndex++] = strTarget.substr(0, nCutPos);
	}

	return strResult;
}