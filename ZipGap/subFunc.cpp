/**
@brief : ���ڿ��� �߶��ִ� �Լ��Դϴ�.
@strOrigin : �ڸ� ������
@strTok : �б��� ������
@string : ��ȯ�� , �迭�� ��������
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