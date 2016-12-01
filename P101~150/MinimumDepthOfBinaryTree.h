/*
 * MinimumDepthOfBinaryTree.h
 *
 *  Created on: 2016年11月30日
 *      Author: user
 */

#ifndef P101_150_MINIMUMDEPTHOFBINARYTREE_H_
#define P101_150_MINIMUMDEPTHOFBINARYTREE_H_

#include "../Interface/BasicSolution.h"

class MinimumDepthOfBinaryTree: public BasicSolution {
public:
	MinimumDepthOfBinaryTree();
	virtual ~MinimumDepthOfBinaryTree();

	int minDepth(TreeNode* root) {
		if(!root)
			return 0;
		else
		{
			int leftDepth = 0;
			int rightDepth = 0;
			int ret = 0;
			if(root->left)
				leftDepth = minDepth(root->left);

			if(root->right)
				rightDepth = minDepth(root->right);

			if(leftDepth == 0 && rightDepth == 0)
			{
				ret = 1;
			}
			else if(leftDepth == 0 && rightDepth != 0)
			{
				ret = rightDepth + 1;
			}
			else if(leftDepth != 0 && rightDepth == 0)
			{
				ret = leftDepth + 1;
			}
			else
			{
				ret = min(leftDepth, rightDepth) + 1;
			}
			return ret;
		}
	}

	void TestSuite();
};

#endif /* P101_150_MINIMUMDEPTHOFBINARYTREE_H_ */
