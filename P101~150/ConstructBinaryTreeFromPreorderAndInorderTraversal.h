/*
 * ConstructBinaryTreeFromPreorderAndInorderTraversal.h
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#ifndef P101_150_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_
#define P101_150_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_

#include "../Interface/BasicSolution.h"

class ConstructBinaryTreeFromPreorderAndInorderTraversal : public BasicSolution {
public:
	ConstructBinaryTreeFromPreorderAndInorderTraversal();
	virtual ~ConstructBinaryTreeFromPreorderAndInorderTraversal();

	// 算法思想没有问题，但是内存使用太多，MLE。
    TreeNode* AbuildTree(vector<int>& preorder, vector<int>& inorder) {
    	TreeNode * root = NULL;

    	int n = preorder.size();
    	if(n)
    	{
    		//assert(preorder.size() == inorder.size());
    		root = new TreeNode(preorder[0]);
    		int index = -1;
    		for(int i = 0; i < n; ++i)
    		{
    			if(inorder[i] == preorder[0])
    			{
    				index = i;
    				break;
    			}
    		}

    		vector<int>::iterator iterbegin, iterend;
    		iterbegin = iterend = preorder.begin();
    		advance(iterbegin, 1);
    		advance(iterend, index + 1);
    		vector<int> preorderleft(iterbegin, iterend);
    		iterbegin = iterend;
    		iterend = preorder.end();
    		vector<int> preorderright(iterbegin, iterend);

    		iterbegin = iterend = inorder.begin();
    		advance(iterend, index);
    		vector<int> inorderleft(iterbegin, iterend);
    		advance(iterend, 1);
    		iterbegin = iterend;
    		iterend = inorder.end();
    		vector<int> inorderright(iterbegin, iterend);

    		root->left = buildTree(preorderleft, inorderleft);
    		root->right = buildTree(preorderright, inorderright);
    	}
    	return root;
    }

    TreeNode* Helper(vector<int>& preorder, int pb, int pe, vector<int>& inorder, int ib, int ie)
    {
    	TreeNode * root = NULL;

    	int n = pe - pb;
    	if(n)
    	{
    		//assert(preorder.size() == inorder.size());
    		root = new TreeNode(preorder[pb]);
    		int index = -1;
    		for(int i = ib; i < ie; ++i)
    		{
    			if(inorder[i] == preorder[pb])
    				index = i;
    		}

    		int n = index - ib;
    		int pb1, pb2, pe1, pe2;
    		pb1 = pb + 1;
    		pe1 = pb + n + 1;

    		pb2 = pe1;
    		pe2 = pe;

    		int ib1, ib2, ie1, ie2;
    		ib1 = ib;
    		ie1 = ib1 + n;

    		ib2 = ie1 + 1;
    		ie2 = ie;

    		if(pb1 <= pe1 && ib1 <= ie1)
    			root->left = Helper(preorder, pb1, pe1, inorder, ib1, ie1);
    		if(pb2 <= pe2 && ib2 <= ie2)
    		    root->right = Helper(preorder, pb2, pe2, inorder, ib2, ie2);
    	}
    	return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	TreeNode * root = Helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());

       	return root;
    }

    void TestSuite();
};

#endif /* P101_150_CONSTRUCTBINARYTREEFROMPREORDERANDINORDERTRAVERSAL_H_ */
