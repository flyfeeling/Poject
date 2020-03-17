﻿#include "stdafx.h"
#include "CommonConvert.h"


INT32 CommonConvert::StringToInt(char* pStr)
{
	if(pStr == NULL)
	{
		return 0;
	}

	return atoi(pStr);
}

INT64 CommonConvert::StringToInt64(char* pStr)
{
	if(pStr == NULL)
	{
		return 0;
	}

	return atol(pStr);
}

INT64 CommonConvert::StringToInt64(const char* pStr)
{
	if(pStr == NULL)
	{
		return 0;
	}


#ifdef WIN32
	return _atoi64(pStr);
#else
	return atoll(pStr);
#endif
}

INT32 CommonConvert::StringToInt(const char* pStr)
{
	if(pStr == NULL)
	{
		return 0;
	}

	return atoi(pStr);
}

FLOAT  CommonConvert::StringToFloat(char* pStr)
{
	if(pStr == NULL)
	{
		return 0;
	}

	return (FLOAT)atof(pStr);
}

DOUBLE CommonConvert::StringToDouble(char* pStr)
{
	if (pStr == NULL)
	{
		return 0;
	}

	return strtod(pStr, NULL);
}

std::string CommonConvert::DoubleToString(DOUBLE dValue)
{
	CHAR szValue[64] = { 0 };

	snprintf(szValue, 64, "%f", dValue);

	return std::string(szValue);
}

FLOAT  CommonConvert::StringToFloat(const char* pStr)
{
	if(pStr == NULL)
	{
		return 0;
	}

	return (FLOAT)atof(pStr);
}

std::string CommonConvert::IntToString(INT32 nValue)
{
	CHAR szValue[64] = {0};

	snprintf(szValue, 64, "%d", nValue);

	return std::string(szValue);
}

std::string CommonConvert::IntToString(INT64 uValue)
{
	CHAR szValue[64] = { 0 };

	snprintf(szValue, 64, "%lld", uValue);

	return std::string(szValue);
}

std::string CommonConvert::IntToString(UINT32 nValue)
{
	CHAR szValue[64] = { 0 };

	snprintf(szValue, 64, "%d", nValue);

	return std::string(szValue);
}

std::string CommonConvert::IntToString(UINT64 uValue)
{
	CHAR szValue[64] = { 0 };

	snprintf(szValue, 64, "%lld", uValue);

	return std::string(szValue);
}

BOOL CommonConvert::StringToPos(char* pStr, FLOAT& x, FLOAT& y, FLOAT& z)
{
	if(pStr == NULL)
	{
		return FALSE;
	}

	char szTempBuf[256] = { 0 };
	strncpy(szTempBuf, pStr, strlen(pStr));

	char* pPos = strchr(szTempBuf, ',');
	if(pPos == NULL)
	{
		return FALSE;
	}
	*pPos = 0;
	x = CommonConvert::StringToFloat(szTempBuf + 1);

	char* pOldPos = pPos + 1;
	pPos = strchr(pPos + 1, ',');
	if(pPos == NULL)
	{
		return FALSE;
	}
	*pPos = 0;
	y = CommonConvert::StringToFloat(pOldPos);

	pOldPos = pPos + 1;
	pPos = strchr(pPos + 1, ')');
	if(pPos == NULL)
	{
		return FALSE;
	}
	*pPos = 0;
	z = CommonConvert::StringToFloat(pOldPos);

	return TRUE;
}

std::string CommonConvert::FloatToString(FLOAT fValue, INT32 nPrecision, BOOL bRound)
{
	CHAR szValue[64] = {0};

	if((bRound) && (nPrecision > 0) && (nPrecision < 6))
	{
		FLOAT fRoundValue = 5;

		for(int i = 0; i < nPrecision + 1; i++)
		{
			fRoundValue *= 0.1f;
		}

		fValue += fRoundValue;
	}

	snprintf(szValue, 64, "%f", fValue);

	CHAR* pChar = strchr(szValue, '.');
	if(pChar == NULL)
	{
		return std::string(szValue);
	}

	*(pChar + nPrecision + 1) = '\0';

	return std::string(szValue);
}

BOOL CommonConvert::SpliteString(std::string strSrc, std::string strDelim, std::vector<std::string>& vtStr)
{
	vtStr.clear();
	if (strDelim.empty())
	{
		vtStr.push_back(strSrc);
		return TRUE;
	}

	std::string::iterator subStart, subEnd;
	subStart = strSrc.begin();
	while (true)
	{
		subEnd = std::search(subStart, strSrc.end(), strDelim.begin(), strDelim.end());
		std::string temp(subStart, subEnd);
		if (!temp.empty())
		{
			vtStr.push_back(temp);
		}
		if (subEnd == strSrc.end())
		{
			break;
		}
		subStart = subEnd + strDelim.size();
	}

	return TRUE;
}

BOOL CommonConvert::ReplaceString(std::string& str, const std::string& pattern, const std::string& newpat)
{
	const size_t nsize = newpat.size();
	const size_t psize = pattern.size();

	for (size_t pos = str.find(pattern, 0); pos != std::string::npos; pos = str.find(pattern, pos + nsize))
	{
		str.replace(pos, psize, newpat);
	}

	return TRUE;
}

BOOL CommonConvert::SpliteString(std::string strSrc,  char cDelim, std::vector<std::string>& vtStr)
{
	vtStr.clear();

	std::string::size_type posStart, posEnd;
	posEnd = strSrc.find(cDelim);
	posStart = 0;
	while(std::string::npos != posEnd)
	{
		vtStr.push_back(strSrc.substr(posStart, posEnd - posStart));

		posStart = posEnd + 1;
		posEnd = strSrc.find(cDelim, posStart);
	}

	if(posStart != strSrc.length())
	{
		vtStr.push_back(strSrc.substr(posStart));
	}

	return TRUE;
}

std::wstring CommonConvert::Utf8_To_Unicode( std::string strSrc )
{
	wchar_t wBuff[102400] = {0};
#ifdef WIN32
	MultiByteToWideChar(CP_UTF8, 0, strSrc.c_str(), -1, wBuff, 102400);
	std::wstring strRet = wBuff;
	return strRet;
#else
#endif
}

std::string CommonConvert::Unicode_To_Uft8( std::wstring wstrValue )
{
	CHAR sBuff[102400] = {0};
#ifdef WIN32
	WideCharToMultiByte(CP_UTF8, 0, wstrValue.c_str(), -1, sBuff, 102400, NULL, NULL);
	std::string strRet = sBuff;
	return strRet;
#else
#endif
}

std::wstring CommonConvert::Ansi_To_Unicode( std::string strSrc )
{
	wchar_t wBuff[102400] = {0};
	CHAR sBuff[102400] = {0};
#ifdef WIN32
	MultiByteToWideChar(CP_ACP,  0, strSrc.c_str(), -1, wBuff, 102400);
	std::wstring strRet = wBuff;
	return strRet;
#else
#endif
}

std::string CommonConvert::Unicode_To_Ansi( std::wstring strValue )
{
	CHAR sBuff[102400] = {0};
#ifdef WIN32
	WideCharToMultiByte(CP_ACP, 0, strValue.c_str(), -1, sBuff, 102400, NULL, NULL);
	return std::string(sBuff);
#else

#endif
}

std::string CommonConvert::Utf8_To_Ansi( std::string strSrc )
{
	wchar_t wBuff[102400] = {0};
	CHAR sBuff[102400] = {0};
#ifdef WIN32
	MultiByteToWideChar(CP_UTF8, 0, strSrc.c_str(), -1, wBuff, 102400);
	WideCharToMultiByte(CP_ACP, 0, wBuff, -1, sBuff, 102400, NULL, NULL);
	std::string strRet = sBuff;
	return strRet;
#else
#endif
}

std::string CommonConvert::Ansi_To_Uft8( std::string strSrc )
{
	wchar_t wBuff[102400] = {0};
	CHAR sBuff[102400] = {0};
#ifdef WIN32
	MultiByteToWideChar(CP_ACP,  0, strSrc.c_str(), -1, wBuff, 102400);
	WideCharToMultiByte(CP_UTF8, 0, wBuff, -1, sBuff, 102400, NULL, NULL);
	std::string strRet = sBuff;
	return strRet;
#else
#endif
}

BOOL CommonConvert::IsTextUTF8(const char* str, UINT32 length)
{
	UINT32 i;
	UINT32 nBytes = 0;//UFT8可用1-6个字节编码,ASCII用一个字节
	UINT8 chr;
	BOOL bAllAscii = TRUE; //如果全部都是ASCII, 说明不是UTF-8
	for (i = 0; i < length; i++)
	{
		chr = *(str + i);
		if ((chr & 0x80) != 0) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
		{ bAllAscii = FALSE; }
		if (nBytes == 0) //如果不是ASCII码,应该是多字节符,计算字节数
		{
			if (chr >= 0x80)
			{
				if (chr >= 0xFC && chr <= 0xFD)
				{ nBytes = 6; }
				else if (chr >= 0xF8)
				{ nBytes = 5; }
				else if (chr >= 0xF0)
				{ nBytes = 4; }
				else if (chr >= 0xE0)
				{ nBytes = 3; }
				else if (chr >= 0xC0)
				{ nBytes = 2; }
				else
				{
					return FALSE;
				}
				nBytes--;
			}
		}
		else //多字节符的非首字节,应为 10xxxxxx
		{
			if ((chr & 0xC0) != 0x80)
			{
				return FALSE;
			}
			nBytes--;
		}
	}
	if (nBytes > 0) //违返规则
	{
		return FALSE;
	}
	if (bAllAscii) //如果全部都是ASCII, 说明不是UTF-8
	{
		return FALSE;
	}
	return TRUE;
}

UINT32 CommonConvert::VersionToInt( std::string& strVersion )
{
	char szBuf[255] = {0};
	strncpy(szBuf, strVersion.c_str(), 255);

	char* pPos = strchr(szBuf, '.');
	if(pPos == NULL)
	{
		return 0;
	}

	*pPos = 0;
	UINT32 nVersion1 = CommonConvert::StringToInt(szBuf);

	char* pOldPos = pPos + 1;
	pPos = strchr(pPos + 1, '.');
	if(pPos == NULL)
	{
		return 0;
	}
	*pPos = 0;
	UINT32 nVersion2 = CommonConvert::StringToInt(pOldPos);

	pOldPos = pPos + 1;
	UINT32 nVersion3 = CommonConvert::StringToInt(pOldPos);

	return nVersion1 * 1000000 + nVersion2 * 1000 + nVersion3;
}

INT32 CommonConvert::CountSymbol(char* pStr, char cSymbol )
{
	if(pStr == NULL)
	{
		return 0;
	}

	INT32 nCount = 0;

	char* pTemp = pStr;
	while(*pTemp != '\0')
	{
		if(*pTemp == cSymbol)
		{
			nCount += 1;
		}

		pTemp += 1;
	}

	return nCount;
}

BOOL CommonConvert::StringTrim(std::string& strValue)
{
	if(!strValue.empty())
	{
		strValue.erase(0, strValue.find_first_not_of((" \n\r\t")));
		strValue.erase(strValue.find_last_not_of((" \n\r\t")) + 1);
	}
	return TRUE;
}
