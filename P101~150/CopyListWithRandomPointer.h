/*
 * CopyListWithRandomPointer.h
 *
 *  Created on: 2016年12月16日
 *      Author: user
 */

#ifndef P101_150_COPYLISTWITHRANDOMPOINTER_H_
#define P101_150_COPYLISTWITHRANDOMPOINTER_H_

#include "../Interface/BasicSolution.h"

	//Definition for singly-linked list with a random pointer.
	struct RandomListNode {
		int label;
		RandomListNode *next, *random;
		RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	};

class CopyListWithRandomPointer: public BasicSolution {
public:
	CopyListWithRandomPointer();
	virtual ~CopyListWithRandomPointer();

    RandomListNode *copyRandomList(RandomListNode *head) {
    	RandomListNode * ret = NULL;

    	if(head)
    	{
    		map<RandomListNode*, RandomListNode*> book;
    		RandomListNode * curr = head;
    		RandomListNode * cpy = NULL;
    		RandomListNode * next = NULL;
    		RandomListNode * rp = NULL;
    		RandomListNode * rcpy = NULL;
    		RandomListNode * last = NULL;
    		while(curr)
    		{
    			next = curr->next;
    			rp = curr->random;
    			if(book.find(curr) == book.end())
    			{
    				cpy = new RandomListNode(curr->label);
    				book[curr] = cpy;
    			}
    			else
    			{
    				cpy = book[curr];
    			}

    			if(rp){
					if(book.find(rp) == book.end())
					{
						rcpy = new RandomListNode(rp->label);
						book[rp] = rcpy;
					}
					else
					{
						rcpy = book[rp];
					}
					cpy->random = rcpy;
    			}

    			if(ret == NULL)
    			{
    				ret = cpy;
    			}

    			if(last == NULL)
    			{
    				last = cpy;
    			}
    			else
    			{
    				last->next = cpy;
    				last = cpy;
    			}

    			curr = next;
    		}
    	}
    	return ret;
    }

    RandomListNode * GenRandomListNodeFromVector(vector<int> & nums);

    void DumpRandomListNode(RandomListNode * head);

    int IsEqualRandomListNode(RandomListNode * l1, RandomListNode * l2);

    void SetRandomPointerByIndex(RandomListNode * head, vector<int> & index);

    void TestSuite();
};

#endif /* P101_150_COPYLISTWITHRANDOMPOINTER_H_ */
