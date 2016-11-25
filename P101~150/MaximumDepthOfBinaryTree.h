/*
 * MaximumDepthOfBinaryTree.h
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#ifndef P101_150_MAXIMUMDEPTHOFBINARYTREE_H_
#define P101_150_MAXIMUMDEPTHOFBINARYTREE_H_

#include "../Interface/BasicSolution.h"

class MaximumDepthOfBinaryTree: public BasicSolution {
public:
	MaximumDepthOfBinaryTree();
	virtual ~MaximumDepthOfBinaryTree();
    int AmaxDepth(TreeNode* root) {
    	if(!root)
    		return 0;
    	//else if(!root->left && !root->right)
    	//	return 1;
    	else
    	{
    		return max(AmaxDepth(root->left), AmaxDepth(root->right)) + 1;
    	}
    }

    int maxDepth(TreeNode* root) {
    	int Depth = 0;
    	if(root)
    	{
    		list<TreeNode*> buf;
    		buf.push_back(root);
    		buf.push_back(NULL);
    		while(!buf.empty())
    		{
    			TreeNode * curr = buf.front();
    			if(curr)
    			{
					if(curr->left)
					{
						buf.push_back(curr->left);
					}
					if(curr->right)
					{
						buf.push_back(curr->right);
					}
    			}
    			else
    			{
    				Depth++;
    				if(buf.size() > 1)
    					buf.push_back(NULL);
    			}
    			buf.pop_front();
    		}
    	}
    	return Depth;
    }

    void TestSuite();
};

#endif /* P101_150_MAXIMUMDEPTHOFBINARYTREE_H_ */
