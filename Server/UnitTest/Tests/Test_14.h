#ifndef Test_14_h__
#define Test_14_h__
/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
	输入: ["flower","flow","flight"]
	输出: "fl"
示例 2:
	输入: ["dog","racecar","car"]
	输出: ""
	解释: 输入不存在公共前缀。
说明:
	所有输入只包含小写字母 a-z 。
*/
#include "Solution.h"
class Test_14 : public Solution
{
public:
	void Excute() 
	{
		std::vector<string> strs = { "flower","flow","flight" };
		string result = longestCommonPrefix(strs);
	}
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
	string longestCommonPrefix(vector<string>& strs) 
	{
		
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];

		int idx = strs[0].size();
		for (int i = 1; i < strs.size(); ++i) 
		{
			int size = min(idx, strs[i].size());
			for (int j = 0; j <= size; ++j) 
			{
				if (strs[0][j] != strs[i][j]) 
				{
					idx = j;
					if (idx == 0) 
					{
						return "";
					}
					break;
				}
			}
		}
		return strs[0].substr(0,idx);
	}
};
#endif // Test_14_h__
