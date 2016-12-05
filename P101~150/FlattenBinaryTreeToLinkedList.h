/*
 * FlattenBinaryTreeToLinkedList.h
 *
 *  Created on: 2016年12月5日
 *      Author: user
 */

#ifndef P101_150_FLATTENBINARYTREETOLINKEDLIST_H_
#define P101_150_FLATTENBINARYTREETOLINKEDLIST_H_

#include "../Interface/BasicSolution.h"

class FlattenBinaryTreeToLinkedList: public BasicSolution {
public:
	FlattenBinaryTreeToLinkedList();
	virtual ~FlattenBinaryTreeToLinkedList();

	void flatten(TreeNode* root) {
		if(!root)
			return;

		TreeNode * left = root->left;
		TreeNode * right = root->right;
		TreeNode * insert = root;
		if(left)
		{
			insert->left = NULL;
			flatten(left);
			insert->right = left;
			while(insert->right)
			{
				insert = insert->right;
			}
		}

		if(right)
		{
			flatten(right);
			insert->right = right;
		}
	}

	void TestSuite();

	void DumpRightNodes(TreeNode * root);
};

#endif /* P101_150_FLATTENBINARYTREETOLINKEDLIST_H_ */
