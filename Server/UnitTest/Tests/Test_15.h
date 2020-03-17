#ifndef Test_15_h__
#define Test_15_h__
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
	满足要求的三元组集合为：
	[
	  [-1, 0, 1],
	  [-1, -1, 2]
	]
*/
#include "Solution.h"
class Test_15 : public Solution 
{
public:
	void Excute() 
	{
		//vector<int> nums = { -4 , -1,-1, 0,1, 2,  };
		//vector<int> nums = { 0,0,0 ,0,0,0};
		vector<int> nums = {-4,1,0,3 ,3};
		vector<vector<int>> result = threeSum(nums);
	}

	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		std::sort(nums.begin(), nums.end());
		if (nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0)
			return {};
		vector<vector<int>> result;
		for (int i = 0; i < nums.size(); ++i) 
		{
			int fix = nums[i];
			if (fix > 0)
				break;
			if (i > 0 && fix == nums[i - 1])
				continue;
			int l = i + 1, r = nums.size() - 1;
			while (l < r)
			{
				if (fix + nums[l] + nums[r] < 0) 
				{ 
					++l; 
				}
				else if (fix + nums[l] + nums[r] > 0) 
				{
					--r;
				}
				else
				{
					result.push_back({ fix, nums[l],nums[r] });
					++l; --r; 
					while (l < r && nums[l] == nums[l - 1])
						++l;
					while (l < r && nums[r] == nums[r + 1])
						--r;
				}
			}
		}
		return result;
	}
};
#endif // Test_15_h__
