#ifndef Test_4_h__
#define Test_4_h__
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
	nums1 = [1, 3]
	nums2 = [2]
	则中位数是 2.0
示例 2:
	nums1 = [1, 2]
	nums2 = [3, 4]
	则中位数是 (2 + 3)/2 = 2.5
*/
#include "Solution.h"
class Test_4 : public Solution 
{
public:

	void Excute() 
	{
		vector<int> num1;
		num1.push_back(2);
		num1.push_back(3);
		num1.push_back(6);
		vector<int> num2;
		num2.push_back(1);
		num2.push_back(4);
		num2.push_back(5);
		num2.push_back(7);
		double num =  findMedianSortedArrays(num1,num2);
	}

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() > nums2.size())
		{
			return findMedianSortedArrays(nums2,nums1);
		}
		int n1size = nums1.size();
		int n2size = nums2.size();
		int LMax1, RMin1, LMax2, RMin2;
		int c1, c2;
		int i = 0;
		int size = 2 * n1size;
		while (i <= size)
		{
			c1 = (i + size) / 2;
			c2 = n2size + n1size - c1;
			LMax1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = c1 == 2 * n1size ? INT_MAX : nums1[c1 / 2];
			LMax2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = c2 == 2 * n2size ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2) 
			{
				size = c1-1;
			}
			else if (LMax2 > RMin1)
			{
				i = c1+1;
			}
			else 
			{
				break;
			}

		}
		
		return ( max(LMax1,LMax2)+min(RMin1,RMin2) ) / 2.0;
	}
};

#endif // Test_4_h__
