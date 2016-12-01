/*
 * BalancedBinaryTree.h
 *
 *  Created on: 2016年11月30日
 *      Author: user
 */

#ifndef P101_150_BALANCEDBINARYTREE_H_
#define P101_150_BALANCEDBINARYTREE_H_

#include "../Interface/BasicSolution.h"

class BalancedBinaryTree: public BasicSolution {
public:
	BalancedBinaryTree();
	virtual ~BalancedBinaryTree();

	int ATreeBalance(TreeNode * root)
	{
		int ret = 0;
		if(!root)
		{
			ret = 0;
		}
		else if(!root->left && !root->right)
		{
			ret = 1;
		}
		else if(!root->left && root->right)
		{
			int rightHeight = TreeBalance(root->right);
			if(rightHeight == 0 || rightHeight == 1)
			{
				ret = rightHeight + 1;
			}
			else
			{
				ret = -1;
			}
		}
		else if(root->left && !root->right)
		{
			int leftHeight = TreeBalance(root->left);
			if(leftHeight == 0 || leftHeight == 1)
			{
				ret = leftHeight + 1;
			}
			else
			{
				ret = -1;
			}
		}
		else if(root->left && root->right)
		{
			int leftHeight = TreeBalance(root->left);
			int rightHeight = TreeBalance(root->right);
			if(leftHeight != -1 && rightHeight != -1 && abs(leftHeight - rightHeight) <= 1)
			{
				ret = max(leftHeight, rightHeight) + 1;
			}
			else
			{
				ret = -1;
			}
		}

		return ret;
	}

	int TreeBalance(TreeNode * root)
	{
		int ret = 0;
		if(!root)
		{
			ret = 0;
		}

		else
		{
			int leftHeight = TreeBalance(root->left);
			if(leftHeight != -1)
			{
				int rightHeight = TreeBalance(root->right);
				if(rightHeight != -1 && abs(leftHeight - rightHeight) <= 1)
					ret = max(leftHeight, rightHeight) + 1;
				else
					ret = -1;
			}
			else
			{
				ret = -1;
			}
		}

		return ret;
	}

    bool isBalanced(TreeNode* root) {
    	int ret = TreeBalance(root);
    	return ret != -1;
    }

    void TestSuite();
};

#endif /* P101_150_BALANCEDBINARYTREE_H_ */
