#ifndef Test_1_h__
#define Test_1_h__
/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
	如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
	您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 0 -> 8
	原因：342 + 465 = 807
*/
#include "Solution.h"
class Test_1 : public Solution
{
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
public:
	void Excute() 
	{
		ListNode l1(1);
		l1.next = new ListNode(8);
		//l1.next->next = new ListNode(3);

		ListNode l2(0);
		//l2.next = new ListNode(6);
		//l2.next->next = new ListNode(4);
		
		ListNode* l3 = addTwoNumbers(&l1, &l2);
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* rL = new ListNode(0);
		ListNode* tmp1 = l1;
		ListNode* tmp2 = l2;
		ListNode* tmp3 = rL;
		while (tmp1 != NULL || tmp2 != NULL)
		{
			if (tmp1->next != NULL || tmp2->next != NULL) 
			{
				if (!tmp1->next)
				{
					tmp1->next = new ListNode(0);
				}
				if (!tmp2->next)
				{
					tmp2->next = new ListNode(0);
				}
				tmp3->next = new ListNode(0);
			}
			tmp3->val += (tmp1->val + tmp2->val);
			if (tmp3->val > 9)
			{
				tmp3->val -=10;
				if (tmp3->next)
				{
					tmp3->next->val = 1;
				}
				else
				{
					tmp3->next = new ListNode(1);
				}
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			tmp3 = tmp3->next;
		}
		return rL;
	}
};
#endif // Test_1_h__
