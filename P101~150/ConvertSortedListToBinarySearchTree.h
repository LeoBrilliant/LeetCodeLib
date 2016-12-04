/*
 * ConvertSortedListToBinarySearchTree.h
 *
 *  Created on: 2016年12月2日
 *      Author: user
 */

#ifndef P101_150_CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_
#define P101_150_CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_

#include "../Interface/BasicSolution.h"

class ConvertSortedListToBinarySearchTree: public BasicSolution {
public:
	ConvertSortedListToBinarySearchTree();
	virtual ~ConvertSortedListToBinarySearchTree();

	ListNode * GetMiddleOfList(ListNode * head)
	{
		ListNode * slow = head;
		ListNode * fast = head;
		ListNode * prevMiddle = NULL;
		while(fast)
		{
			fast = fast->next;
			if(fast && fast->next)
			{
				fast = fast->next;
				prevMiddle = slow;
				slow = slow->next;
			}
		}

		if(prevMiddle)
		{
			prevMiddle->next = NULL;
		}
		return slow;
	}

	TreeNode * CreateTree(ListNode * head)
	{
		TreeNode * root = NULL;

		if(head)
		{
			ListNode * middle = GetMiddleOfList(head);
			root = new TreeNode(middle->val);
			//ListNode * tmp = head;
			if(head != middle)
			{
				/*
				while(tmp)
				{
					if(tmp->next != middle)
					{
						tmp = tmp->next;
					}
					else
					{
						tmp->next = NULL;
					}
				}
				*/
				root->left = CreateTree(head);
			}
			root->right = CreateTree(middle->next);
		}

		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode * root = NULL;
		if(head)
		{
			root = CreateTree(head);
		}
		return root;
	}

	void TestSuite();
};

#endif /* P101_150_CONVERTSORTEDLISTTOBINARYSEARCHTREE_H_ */
