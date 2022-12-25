
#pragma once
#include "./C++Header.h"



namespace util
{
	enum SplitType { Contain, Except };

	static vector<string> Split(string text, SplitType splitType, regex format = regex(R"()"))   // 정규식으로 문자열을 Split한다
	{
		sregex_token_iterator iter, end;
		if (splitType == Contain) iter = sregex_token_iterator(text.begin(), text.end(), format);
		else if (splitType == Except) iter = sregex_token_iterator(text.begin(), text.end(), format, -1);
		return vector<string>(iter, end);
	}
}