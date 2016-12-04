/*
 * PathSum.h
 *
 *  Created on: 2016年12月4日
 *      Author: LeoBrilliant
 */

#ifndef PATHSUM_H_
#define PATHSUM_H_

#include "../Interface/BasicSolution.h"

class PathSum: public BasicSolution {
public:
	PathSum();
	virtual ~PathSum();

	struct Node {
		int sum;
		TreeNode * curr;
		TreeNode * parent;
		Node(int x) : sum(x), curr(NULL), parent(NULL) {}
		Node(int x, TreeNode * curr, TreeNode * parent) : sum(x), curr(curr), parent(parent) {}
	};

	bool hasPathSum(TreeNode* root, int sum) {
		bool ret = false;
		list<Node*> buf;
		if(root)
		{
			buf.push_back(new Node(root->val, root, NULL));
			buf.push_back(NULL);
			while(!buf.empty())
			{
				Node * curr = buf.front();
				if(curr)
				{
					if(!curr->curr->left && !curr->curr->right && curr->sum == sum)
					{
						ret = true;
						break;
					}
					if(curr->curr->left)
					{
						buf.push_back(new Node(curr->sum + curr->curr->left->val, curr->curr->left, curr->curr));
					}
					if(curr->curr->right)
					{
						buf.push_back(new Node(curr->sum + curr->curr->right->val, curr->curr->right, curr->curr));
					}
				}
				else
				{
					if(buf.size() > 1)
						buf.push_back(NULL);
				}
				buf.pop_front();
			}
		}
		return ret;
	}

	void TestSuite();
};

#endif /* PATHSUM_H_ */
