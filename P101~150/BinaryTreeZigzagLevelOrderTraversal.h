/*
 * BinaryTreeZigzagLevelOrderTraversal.h
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#ifndef P101_150_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_
#define P101_150_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_

#include "../Interface/BasicSolution.h"

class BinaryTreeZigzagLevelOrderTraversal: public BasicSolution {
public:
	BinaryTreeZigzagLevelOrderTraversal();
	virtual ~BinaryTreeZigzagLevelOrderTraversal();

	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> ret;

    	if(root)
    	{
    		list<TreeNode*> buf;
    		buf.push_back(root);
    		buf.push_back(NULL);
    		vector<int> level;
    		bool WalkRight = true;
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
    				if(WalkRight)
    				{
    					ret.push_back(level);
    					WalkRight = false;
    				}
    				else
    				{
    					vector<int> tmp;
    					for(int i = level.size() - 1; i >= 0; --i)
    					{
    						tmp.push_back(level[i]);
    					}
    					ret.push_back(tmp);
    					WalkRight = true;
    				}
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

#endif /* P101_150_BINARYTREEZIGZAGLEVELORDERTRAVERSAL_H_ */
