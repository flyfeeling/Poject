#ifndef Test_19_h__
#define Test_19_h__
/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：
	输入：1->2->4, 1->3->4
	输出：1->1->2->3->4->4
*/
#include "Solution.h"

 
 
class Test_19 : public Solution 
{
public:
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	void Excute() 
	{
		ListNode* l1 = new ListNode(1);
		l1->next = new ListNode(2);
		l1->next->next = new ListNode(4);

		ListNode* l2 = new ListNode(1);
		l2->next = new ListNode(3);
		l2->next->next = new ListNode(4);


		ListNode* result = mergeTwoLists(l1, l2);
	} 

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;


		ListNode head(INT_MIN);
		head.next = l1;
		l1 = &head;
		ListNode* tmp1;
		ListNode* tmp2;
		while (l2 != nullptr)
		{
			tmp1 = l1->next;
			tmp2 = l2->next;
			if (tmp1 == nullptr)
			{
				l1->next = l2;
				break;
			}
			if(l2->val <= tmp1->val)
			{
				l2->next = l1->next;
				l1->next = l2;
				l2 = tmp2;
			}
			l1 = l1->next;
		}
		return head.next;
	}

};
#endif // Test_19_h__
