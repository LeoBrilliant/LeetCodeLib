/*
 * BinaryTreeLevelOrderTraversal.h
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#ifndef P101_150_BINARYTREELEVELORDERTRAVERSAL_H_
#define P101_150_BINARYTREELEVELORDERTRAVERSAL_H_

//#include "../Common.h"
#include "../Interface/BasicSolution.h"

class BinaryTreeLevelOrderTraversal: public BasicSolution {
public:
	BinaryTreeLevelOrderTraversal();
	virtual ~BinaryTreeLevelOrderTraversal();

    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> ret;

    	if(root)
    	{
    		list<TreeNode*> buf;
    		buf.push_back(root);
    		buf.push_back(NULL);
    		vector<int> level;
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
    				ret.push_back(level);
    				level.clear();
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

#endif /* P101_150_BINARYTREELEVELORDERTRAVERSAL_H_ */
