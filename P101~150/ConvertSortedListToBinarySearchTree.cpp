/*
 * ConvertSortedListToBinarySearchTree.cpp
 *
 *  Created on: 2016年12月2日
 *      Author: user
 */

#include "ConvertSortedListToBinarySearchTree.h"

ConvertSortedListToBinarySearchTree::ConvertSortedListToBinarySearchTree() {
	// TODO Auto-generated constructor stub

}

ConvertSortedListToBinarySearchTree::~ConvertSortedListToBinarySearchTree() {
	// TODO Auto-generated destructor stub
}

void ConvertSortedListToBinarySearchTree::TestSuite() {
	ListNode * head;
	TreeNode * root;
	vector<int> nums;
	ListNode * middle;

	cout << "test case 1" << endl;
	nums = {};
	head = GenListFromVector(nums);
	assert(head == NULL);
	middle = this->GetMiddleOfList(head);
	assert(middle == NULL);
	DumpListNode(head);
	DumpListNode(middle);

	cout << "test case 2" << endl;
	nums = {1};
	head = GenListFromVector(nums);
	assert(head != NULL);
	middle = this->GetMiddleOfList(head);
	assert(middle != NULL);
	assert(middle == head);
	DumpListNode(head);
	DumpListNode(middle);

	cout << "test case 3" << endl;
	nums = {1, 2};
	head = GenListFromVector(nums);
	assert(head != NULL);
	middle = this->GetMiddleOfList(head);
	assert(middle != NULL);
	assert(middle == head);
	assert(middle->val == 1);
	DumpListNode(head);
	DumpListNode(middle);

	cout << "test case 4" << endl;
	nums = {1, 2, 3};
	head = GenListFromVector(nums);
	assert(head != NULL);
	middle = this->GetMiddleOfList(head);
	assert(middle != NULL);
	assert(middle == head->next);
	assert(middle->val == 2);
	DumpListNode(head);
	DumpListNode(middle);

	cout << "test case 5" << endl;
	nums = {1, 2, 3, 4};
	head = GenListFromVector(nums);
	assert(head != NULL);
	middle = this->GetMiddleOfList(head);
	assert(middle != NULL);
	assert(middle == head->next);
	assert(middle->val == 2);
	DumpListNode(head);
	DumpListNode(middle);

	cout << "test case 6" << endl;
	nums = {1, 2, 3, 4, 5};
	head = GenListFromVector(nums);
	assert(head != NULL);
	middle = this->GetMiddleOfList(head);
	assert(middle != NULL);
	assert(middle == head->next->next);
	assert(middle->val == 3);
	DumpListNode(head);
	DumpListNode(middle);

	cout << "test case 7" << endl;
	nums = {};
	head = GenListFromVector(nums);
	root = this->sortedListToBST(head);
	assert(root == NULL);
	DumpTreeByPosition(root);

	cout << "test case 7" << endl;
	nums = {1};
	head = GenListFromVector(nums);
	root = this->sortedListToBST(head);
	assert(root != NULL);
	assert(root->val == 1);
	DumpTreeByPosition(root);

	cout << "test case 8" << endl;
	nums = {1, 2};
	head = GenListFromVector(nums);
	root = this->sortedListToBST(head);
	assert(root != NULL);
	assert(root->val == 1);
	DumpTreeByPosition(root);

	cout << "test case 9" << endl;
	nums = {1, 2, 3};
	head = GenListFromVector(nums);
	root = this->sortedListToBST(head);
	assert(root != NULL);
	assert(root->val == 2);
	DumpTreeByPosition(root);

	cout << "test case 10" << endl;
	nums = {1, 2, 3, 4};
	head = GenListFromVector(nums);
	root = this->sortedListToBST(head);
	assert(root != NULL);
	assert(root->val == 2);
	DumpTreeByPosition(root);

	cout << "test case 11" << endl;
	nums = {1, 2, 3, 4, 5};
	head = GenListFromVector(nums);
	root = this->sortedListToBST(head);
	assert(root != NULL);
	assert(root->val == 3);
	DumpTreeByPosition(root);

}
