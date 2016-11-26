/*
 * IntersectionOfTwoLinkedLists.h
 *
 *  Created on: 2016年11月26日
 *      Author: user
 */

#ifndef P101_150_INTERSECTIONOFTWOLINKEDLISTS_H_
#define P101_150_INTERSECTIONOFTWOLINKEDLISTS_H_

#include "../Interface/BasicSolution.h"

class IntersectionOfTwoLinkedLists: public BasicSolution {
public:
	IntersectionOfTwoLinkedLists();
	virtual ~IntersectionOfTwoLinkedLists();

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode * ret = NULL;

		if(headA && headB)
		{
			int lenA, lenB;
			lenA = lenB = 1;
			ListNode * lastA, *lastB;
			lastA = headA;
			lastB = headB;

			while(lastA->next)
			{
				lenA++;
				lastA = lastA->next;
			}

			while(lastB->next)
			{
				lenB++;
				lastB = lastB->next;
			}

			if(lastA == lastB)
			{
				ListNode * cmpA , * cmpB;
				if(lenA >= lenB)
				{
					cmpA = headA;
					cmpB = headB;
				}
				else
				{
					cmpA = headB;
					cmpB = headA;
				}

				int n = abs(lenA - lenB);

				while(n > 0)
				{
					n --;
					cmpA = cmpA->next;
				}

				while(cmpA != cmpB)
				{
					cmpA = cmpA->next;
					cmpB = cmpB->next;
				}

				ret = cmpA;
			}
		}
		return ret;
	}

	void TestSuite();
};

#endif /* P101_150_INTERSECTIONOFTWOLINKEDLISTS_H_ */
