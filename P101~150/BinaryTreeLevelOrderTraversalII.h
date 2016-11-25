/*
 * BinaryTreeLevelOrderTraversalII.h
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#ifndef P101_150_BINARYTREELEVELORDERTRAVERSALII_H_
#define P101_150_BINARYTREELEVELORDERTRAVERSALII_H_

#include "../Interface/BasicSolution.h"

class BinaryTreeLevelOrderTraversalII: public BasicSolution {
public:
	BinaryTreeLevelOrderTraversalII();
	virtual ~BinaryTreeLevelOrderTraversalII();

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> ret;

    	if(root)
    	{
    		list<TreeNode*> buf;
    		buf.push_back(root);
    		buf.push_back(NULL);
    		vector<int> level;
    		vector<vector<int>> tmp;
    		while(!buf.empty())
    		{
    			TreeNode * curr = buf.front();
    			if(curr)
    			{
    				level.push_back(curr->val);
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
    				tmp.push_back(level);
    				level.clear();
    				if(buf.size() > 1)
    					buf.push_back(NULL);
    			}
    			buf.pop_front();
    		}

    		for(int i = tmp.size() - 1; i >= 0; --i)
    		{
    			ret.push_back(tmp[i]);
    		}

    	}
    	return ret;
	}

	void TestSuite();
};

#endif /* P101_150_BINARYTREELEVELORDERTRAVERSALII_H_ */
