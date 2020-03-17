#ifndef Test_16_h__
#define Test_16_h__
/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
#include "Solution.h"
class Test_16 : public Solution 
{
public:

	void Excute()
	{
		vector<int> nums = {0 ,1,1,1 };
		int target = 1;
		int result = threeSumClosest(nums,target);
	}

	int threeSumClosest(vector<int>& nums, int target)
	{
		std::sort(nums.begin(), nums.end());
		
		int result = nums[0]+nums[1]+nums[2];
		if (nums.empty() || nums.size() < 3)
			return result;
		
		for (int i = 0; i < nums.size(); ++i) 
		{
			int l = i+1, r = nums.size() - 1,sum;
			while (l < r)
			{
				sum = nums[i] + nums[l] + nums[r];
				if (target == sum) return sum;
				if (abs(target - sum) < abs( target - result)) 
				{
					result = sum;
				}
				if (sum > target) 
				{
					r--;
				}
				else
				{
					l++;
				}
				
			}
		}
		return result;
	}
};
#endif // Test_16_h__
