/*
 * SumRootToLeafNumbers.h
 *
 *  Created on: 2016年12月18日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_SUMROOTTOLEAFNUMBERS_H_
#define P101_150_SUMROOTTOLEAFNUMBERS_H_

#include "../Interface/BasicSolution.h"

class SumRootToLeafNumbers: public BasicSolution {
public:
	SumRootToLeafNumbers();
	virtual ~SumRootToLeafNumbers();

	struct Node {
		int sum;
		TreeNode * curr;
		TreeNode * parent;
		Node(int x) : sum(x), curr(NULL), parent(NULL) {}
		Node(int x, TreeNode * curr, TreeNode * parent) : sum(x), curr(curr), parent(parent) {}
	};

    int sumNumbers(TreeNode* root) {
		int ret = 0;
		if(root)
		{
			list<Node*> buf;
			vector<int> nums;
			buf.push_back(new Node(root->val, root, NULL));
			buf.push_back(NULL);
			while(!buf.empty())
			{
				Node * curr = buf.front();
				if(curr)
				{
					if(!curr->curr->left && !curr->curr->right)
					{
						nums.push_back(curr->sum);
					}
					if(curr->curr->left)
					{
						buf.push_back(new Node(curr->sum * 10 + curr->curr->left->val, curr->curr->left, curr->curr));
					}
					if(curr->curr->right)
					{
						buf.push_back(new Node(curr->sum  * 10 + curr->curr->right->val, curr->curr->right, curr->curr));
					}
				}
				else
				{
					if(buf.size() > 1)
						buf.push_back(NULL);
				}
				buf.pop_front();
			}

			for(auto i : nums)
				ret += i;
		}
		return ret;
	}

    void TestSuite();
};

#endif /* P101_150_SUMROOTTOLEAFNUMBERS_H_ */
