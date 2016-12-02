/*
 * ConvertSortedArrayToBinarySearchTree.cpp
 *
 *  Created on: 2016年12月2日
 *      Author: user
 */

#include "ConvertSortedArrayToBinarySearchTree.h"

ConvertSortedArrayToBinarySearchTree::ConvertSortedArrayToBinarySearchTree() {
	// TODO Auto-generated constructor stub

}

ConvertSortedArrayToBinarySearchTree::~ConvertSortedArrayToBinarySearchTree() {
	// TODO Auto-generated destructor stub
}

void ConvertSortedArrayToBinarySearchTree::TestSuite() {
	TreeNode * root;
	vector<int> nums;

	cout << "test case 1" << endl;
	nums = {};
	root = this->sortedArrayToBST(nums);
	assert(root == NULL);
	DumpTreeByPosition(root);

	cout << "test case 2" << endl;
	nums = {1};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 1);
	DumpTreeByPosition(root);

	cout << "test case 3" << endl;
	nums = {1, 2};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 1);
	DumpTreeByPosition(root);

	cout << "test case 4" << endl;
	nums = {1, 2, 3};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 2);
	DumpTreeByPosition(root);

	cout << "test case 5" << endl;
	nums = {1, 2, 3, 4};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 2);
	DumpTreeByPosition(root);

	cout << "test case 6" << endl;
	nums = {1, 2, 3, 4, 5};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 3);
	DumpTreeByPosition(root);

	cout << "test case 7" << endl;
	nums = {1, 2, 3, 4, 5, 6};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 3);
	DumpTreeByPosition(root);

	cout << "test case 8" << endl;
	nums = {1, 2, 3, 4, 5, 6, 7};
	root = this->sortedArrayToBST(nums);
	assert(root != NULL);
	assert(root->val == 4);
	DumpTreeByPosition(root);
}
