/*
 * PopulatingNextRightPointersInEachNode.h
 *
 *  Created on: 2016年12月5日
 *      Author: user
 */

#ifndef P101_150_POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H_
#define P101_150_POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H_

#include "../Interface/BasicSolution.h"

class PopulatingNextRightPointersInEachNode: public BasicSolution {
public:
	PopulatingNextRightPointersInEachNode();
	virtual ~PopulatingNextRightPointersInEachNode();

	// Definition for binary tree with next pointer.
	struct TreeLinkNode {
		int val;
		TreeLinkNode *left, *right, *next;
		TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	};

	void connect(TreeLinkNode *root) {
		if(!root)
			return;

		TreeLinkNode * curr = root;
		TreeLinkNode * son = root->left;
		TreeLinkNode * sibling = root->next;

		while(curr)
		{
			if(curr->left)
			{
				curr->left->next = curr->right;

				if(sibling)
				{
					curr->right->next = sibling->left;
					curr = sibling;
					sibling = sibling->next;
				}
				else
				{
					curr = son;
					sibling = son->next;
					son = son->left;
				}
			}
			else
			{
				break;
			}
		}
	}

	void TestSuite();
};

#endif /* P101_150_POPULATINGNEXTRIGHTPOINTERSINEACHNODE_H_ */
