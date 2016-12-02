/*
 * ConvertSortedArrayToBinarySearchTree.h
 *
 *  Created on: 2016年12月2日
 *      Author: user
 */

#ifndef P101_150_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_
#define P101_150_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_

#include "../Interface/BasicSolution.h"

class ConvertSortedArrayToBinarySearchTree: public BasicSolution {
public:
	ConvertSortedArrayToBinarySearchTree();
	virtual ~ConvertSortedArrayToBinarySearchTree();

	TreeNode * CreateTree(vector<int> & nums, int begin, int end)
	{
		TreeNode * root = NULL;

		if(begin <= end)
		{
			int middle = (begin + end) / 2;
			root = new TreeNode(nums[middle]);
			root->left = CreateTree(nums, begin, middle - 1);
			root->right = CreateTree(nums, middle + 1, end);
		}

		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode * root = NULL;

		int n = nums.size();
		if(n)
		{
			root = CreateTree(nums, 0, n - 1);
		}
		return root;
	}

	void TestSuite();
};

#endif /* P101_150_CONVERTSORTEDARRAYTOBINARYSEARCHTREE_H_ */
