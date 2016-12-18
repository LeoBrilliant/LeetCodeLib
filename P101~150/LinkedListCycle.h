/*
 * LinkedListCycle.h
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_LINKEDLISTCYCLE_H_
#define P101_150_LINKEDLISTCYCLE_H_

#include "../Interface/BasicSolution.h"

class LinkedListCycle: public BasicSolution {
public:
	LinkedListCycle();
	virtual ~LinkedListCycle();

	bool hasCycle(ListNode *head) {
		bool ret = false;

		if(head)
		{
			ListNode * fast = head;
			ListNode * slow = head;

			while(fast)
			{
				fast = fast->next;
				if(fast && fast->next)
				{
					fast = fast->next;
					slow = slow->next;

					if(fast && fast == slow)
					{
						ret = true;
						break;
					}
				}
			}
		}
		return ret;
    }

    ListNode *detectCycle(ListNode *head) {
    	ListNode * ret = NULL;

		if(head)
		{
			ListNode * fast = head;
			ListNode * slow = head;
			ListNode * common = NULL;
			int lh, lc;
			lh = lc = 0;

			while(fast)
			{
				fast = fast->next;
				if(fast && fast->next)
				{
					fast = fast->next;
					slow = slow->next;

					if(fast && fast == slow)
					{
						common = fast;
						break;
					}
				}
			}

			if(common)
			{
				slow = common;
				while(slow->next != common)
				{
					slow = slow->next;
					lc++;
				}
				lc++;

				slow = head;
				while(slow->next != common)
				{
					slow = slow->next;
					lh++;
				}
				lh++;

				slow = head;
				while(lh > lc)
				{
					slow = slow->next;
					lh--;
				}
				fast = common;
				while(lc > lh)
				{
					fast = fast->next;
					lc--;
				}

				while(slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				ret = slow;
			}
		}
        return ret;
    }

	void TestSuite();
};

#endif /* P101_150_LINKEDLISTCYCLE_H_ */
