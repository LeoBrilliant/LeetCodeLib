/*
 * PathSumII.h
 *
 *  Created on: 2016年12月4日
 *      Author: LeoBrilliant
 */

#ifndef PATHSUMII_H_
#define PATHSUMII_H_

#include "../Interface/BasicSolution.h"

class PathSumII: public BasicSolution {
public:
	PathSumII();
	virtual ~PathSumII();

	struct Node {
		int sum;
		TreeNode * curr;
		Node * parent;
		Node(int x) : sum(x), curr(NULL), parent(NULL) {}
		Node(int x, TreeNode * curr, Node * parent) : sum(x), curr(curr), parent(parent) {}
	};

	vector<vector<int>> PathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
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
						stack<int> tmp;
						vector<int> vi;
						Node * n = curr;
						while(n)
						{
							tmp.push(n->curr->val);
							n = n->parent;
						}

						while(tmp.size())
						{
							vi.push_back(tmp.top());
							tmp.pop();
						}

						ret.push_back(vi);
					}
					if(curr->curr->left)
					{
						buf.push_back(new Node(curr->sum + curr->curr->left->val, curr->curr->left, curr));
					}
					if(curr->curr->right)
					{
						buf.push_back(new Node(curr->sum + curr->curr->right->val, curr->curr->right, curr));
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

#endif /* PATHSUMII_H_ */
