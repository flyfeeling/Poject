#ifndef Test_3_h__
#define Test_3_h__
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例:
	给定 nums = [2, 7, 11, 15], target = 9
	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]
*/
#include "Solution.h"
class Test_3 : public Solution
{
public:

	void Excute() 
	{
		vector<int> nums;
		nums.push_back(2);
		nums.push_back(7);
		nums.push_back(11);
		nums.push_back(15);
		std::vector<int> data = twoSum(nums, 9);
	}

	vector<int> twoSum(vector<int>& nums, int target) 
	{
		vector<int> rdata(2, -1);
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) 
		{
			int subnum = target - nums[i];
			if (map.count(subnum) > 0)
			{
				rdata[0] = i;
				rdata[1] = map[subnum];
			}
			map[nums[i]] = i;
		}
		return rdata;
	}
};
#endif // Test_3_h__
