﻿#ifndef Test_10_h__
#define Test_10_h__
/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
说明:
	s 可能为空，且只包含从 a-z 的小写字母。
	p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:
	输入:
	s = "aa"
	p = "a"
	输出: false
	解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:
	输入:
	s = "aa"
	p = "a*"
	输出: true
	解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3:
	输入:
	s = "ab"
	p = ".*"
	输出: true
	解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:
	输入:
	s = "aab"
	p = "c*a*b"
	输出: true
	解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:
	输入:
	s = "mississippi"
	p = "mis*is*p*"
	输出: false

*/
#include "Solution.h"
class Test_10 : public Solution 
{
public:
	void Excute() 
	{
		string s = "abbbcd";
		string p = "abb*cde";
		bool flag = isMatch(s, p);
	}
	bool isMatch(string s, string p) 
	{
		int size1 = s.size();
		int size2 = p.size();
		if (p.size() && p[0] == '*')
			return false;
		vector<vector<bool>>flag(size1 + 1, vector<bool>(size2 + 1, false));
		flag[0][0] = true;
		int i = 1, j = 1;
		for (i = 1; i <= size2; ++i) 
		{
			if (p[i - 1] == '*') 
			{
				flag[0][i] = flag[0][i - 1] || flag[0][i - 2];
			}
		}
		for (i = 1; i <= size1; ++i) 
		{
			for (j = 1; j <= size2; ++j) 
			{
				if (p[j - 1] == s[i - 1] || p[j - 1] == '.') 
				{
					flag[i][j] = flag[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') 
				{
					if (s[i - 1] == p[j - 2] || p[j - 2] == '.') 
					{
						flag[i][j] = flag[i][j - 2] || flag[i][j - 1] || flag[i - 1][j];
					}
					else 
					{
						flag[i][j] = flag[i][j - 2];
					}

				}
				else 
				{
					flag[i][j] = false;
				}
			}
		}
		return flag[size1][size2];
	}

	


	bool isMatch2(string s, string p) 
	{
		if (p.empty()) return s.empty();
		if (p.length() > 1 && p[1] == '*')
			return isMatch2(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch2(s.substr(1), p));
		else 
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch2(s.substr(1), p.substr(1));
	}

	
};
#endif // Test_10_h__
