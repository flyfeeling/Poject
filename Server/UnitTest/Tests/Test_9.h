#ifndef Test_9_h__
#define Test_9_h__
/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
	输入: 121
	输出: true
示例 2:
	输入: -121
	输出: false
	解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:
输入: 10
	输出: false
	解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:
	你能不将整数转为字符串来解决这个问题吗？
*/
#include "Solution.h"
class Test_9 : public Solution 
{
public:
#define INT32_MAX_T 214748364
#define INT32_MIN_T -214748364
	void Excute() 
	{
		int x = 1213;
		bool isP = isPalindrome(x);
	}
	bool isPalindrome(int x) 
	{
		if (x < 0)return false;
		int y = 0;
		int tmpx = x;
		while (tmpx != 0)
		{
			if (y > INT32_MAX_T || y < INT32_MIN_T)
			{
				return false;
			}
			y = y * 10 + tmpx % 10;
			tmpx /= 10;
			
		}
		return y == x;

	}
};
#endif // Test_9_h__
