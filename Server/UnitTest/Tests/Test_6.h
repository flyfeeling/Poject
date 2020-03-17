#ifndef Test_6_h__
#define Test_6_h__
/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
	L   C   I   R
	E T O E S I I G
	E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
	示例 1:
		输入: s = "LEETCODEISHIRING", numRows = 3
		输出: "LCIRETOESIIGEDHN"
	示例 2:
		输入: s = "LEETCODEISHIRING", numRows = 4
		输出: "LDREOEIIECIHNTSG"
		解释:
			L     D     R
			E   O E   I I
			E C   I H   N
			T     S     G
*/
#include "Solution.h"

class Test_6 : public Solution
{
public:
	void Excute() 
	{
		int a = std::ceil(float(3) / float(2));
		char *vis = new char[2];
		memset(vis, 2, 2 * sizeof(char));
		
		string s = "LEETCODEISHIRING";
		int nowRows = 4;
		convert(s, nowRows);
	}
	

	
	string convert(string s, int numRows) 
	{
		if (numRows < 2 || s.size() < numRows) return s;
		string str="";
		int size = s.size();
		int circle_count = 2 * numRows - 2;
		int circle_size = std::ceil(float(s.size()) / float(circle_count));
		for (int j = 0; j < numRows; j++)
		{
			for (int i = 0; i < circle_size; i++)
			{ 
				if (j == 0 || j == numRows - 1) 
				{
					if (i*circle_count + j < size) 
					{
						str += s[i*circle_count + j];
					}
				}
				else
				{
					if (i*circle_count + j < size)
					{
						str += s[i*circle_count + j];
					}
					if (i*circle_count + circle_count - j < size)
					{
						str += s[i*circle_count + circle_count - j];
					}
				}
			}
		}
		return str;
	}
};
//int nowIndex = j + circle_count * i;
//if (nowIndex > (s.size() - 1))
//{
//	break;
//}
//if (j == 0 || j > z_col || i < numRows)
//{
//	str += s[nowIndex];
//}
//else
//{
//	str += s[circle_count * i + numRows + circle_count - j - 2];
//
//}
#endif // Test_6_h__
