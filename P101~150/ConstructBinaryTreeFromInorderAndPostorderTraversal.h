/*
 * ConstructBinaryTreeFromInorderAndPostorderTraversal.h
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#ifndef P101_150_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H_
#define P101_150_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H_

#include "../Interface/BasicSolution.h"

class ConstructBinaryTreeFromInorderAndPostorderTraversal: public BasicSolution {
public:
	ConstructBinaryTreeFromInorderAndPostorderTraversal();
	virtual ~ConstructBinaryTreeFromInorderAndPostorderTraversal();

	TreeNode * Helper(vector<int>& inorder, int ib, int ie, vector<int>& postorder, int pb, int pe)
	{
    	TreeNode * root = NULL;

    	int n = pe - pb;
    	if(n)
    	{
    		//assert(preorder.size() == inorder.size());
    		int value = postorder[pe - 1];
    		root = new TreeNode(value);
    		int index = -1;
    		for(int i = ib; i < ie; ++i)
    		{
    			if(inorder[i] == value)
    				index = i;
    		}

    		int n = index - ib;
    		int pb1, pb2, pe1, pe2;
    		pb1 = pb;
    		pe1 = pb1 + n;

    		pb2 = pe1;
    		pe2 = pe - 1;

    		int ib1, ib2, ie1, ie2;
    		ib1 = ib;
    		ie1 = ib1 + n;

    		ib2 = ie1 + 1;
    		ie2 = ie;

    		if(pb1 <= pe1 && ib1 <= ie1)
    			root->left = Helper(inorder, ib1, ie1, postorder, pb1, pe1);
    		if(pb2 <= pe2 && ib2 <= ie2)
    		    root->right = Helper(inorder, ib2, ie2, postorder, pb2, pe2);
    	}
    	return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return Helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}

	void TestSuite();
};

#endif /* P101_150_CONSTRUCTBINARYTREEFROMINORDERANDPOSTORDERTRAVERSAL_H_ */
