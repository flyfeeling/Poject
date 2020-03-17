#ifndef Test_7_h__
#define Test_7_h__
/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
	示例 1:
		输入: 123
		输出: 321
 	示例 2:
		输入: -123
		输出: -321
	示例 3:
		输入: 120
		输出: 21
		注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

*/
#include "Solution.h"
class Test_7 : public Solution 
{
public:
//#define INT32_MAX 2147483647
//#define INT32_MIN -2147483648
#define INT32_MAX_T 214748364
#define INT32_MIN_T -214748364
	void Excute() 
	{
		int x = 1463847412;
		int y =reverse(x);
	}

	int reverse(int x)
	{
		int y = 0;
		while (x != 0)
		{
			int chu = x % 10;
			x /= 10;
		
			if (y > INT32_MAX_T || (y == INT32_MAX_T && chu > 7))
			{
				return 0;
			}
			if (y < INT32_MIN_T || (y == INT32_MIN_T && chu < -8))
			{
				return 0;
			}
			y = y*10+ chu;
		}
		return y;
	}
};

#endif // Test_7_h__
