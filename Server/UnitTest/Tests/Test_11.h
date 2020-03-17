#ifndef Test_11_h__
#define Test_11_h__
/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

*/
#include "Solution.h"
class Test_11 : public Solution 
{
public:
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
	void Excute() 
	{
		int h[9] = { 1,8,6,2,5,4,8,3,7 };
		std::vector<int> height(h, h + 9);
		int r = maxArea(height);
	}

	int maxArea(vector<int>& height) 
	{
		int i = 0,j = height.size() - 1;
		int result = 0;
		while (i<j)
		{
			result = max(result, min(height[j], height[i]) * (j - i));
			height[i] > height[j]? --j: ++i;
		}
		return result;
	}
	
	int maxArea2(vector<int>& height) 
	{
		int size = height.size();
		int i=0, j= 0;
		int result = 0;
		for (i = 0; i < size-1; ++i)
		{
			for (j = i+1; j < size; ++j)
			{
				result = max(result,min(height[j], height[i]) * (j - i));
			}
		}
		return result;
	}
};

#endif // Test_11_h__
