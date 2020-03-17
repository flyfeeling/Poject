#ifndef Test_5_h__
#define Test_5_h__
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
示例 1：
	输入 : "babad"
	输出 : "bab"
	注意 : "aba" 也是一个有效答案。
示例 2：
	输入 : "cbbd"
	输出 : "bb"
*/
#include "Solution.h"
class Test_5 : public Solution 
{
public:
#define max(a,b) (((a) > (b)) ? (a) : (b))
	void Excute() 
	{

		string s = "babad";
		 string ss =longestPalindrome(s);
	}
	string longestPalindrome(string s) 
	{
		int size = s.size();
		if (size == 0 || size == 1) 
		{
			return s;
		}

		int start = 0;
		int end = 0;
		int maxLeng = 0;
		for (int i = 0; i < size; i++) 
		{
			int max1 = findMaxLength(s, i, i);
			int max2 = findMaxLength(s, i, i + 1);
			maxLeng = max(max(max1, max2), maxLeng);
			if (maxLeng > end - start + 1) 
			{
				start = i - (maxLeng - 1) / 2;
				end = i + maxLeng / 2;
			}
		}
		return s.substr(start, maxLeng);
	}

	int findMaxLength(string& s, int left, int right) 
	{
		int L = left;
		int R = right;
		while (L > -1 &&  R < s.size() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return (R - L-1);
	}
};

#endif // Test_5_h__ 
