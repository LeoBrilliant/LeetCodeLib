/*
 * FlattenBinaryTreeToLinkedList.cpp
 *
 *  Created on: 2016年12月5日
 *      Author: user
 */

#include "FlattenBinaryTreeToLinkedList.h"

FlattenBinaryTreeToLinkedList::FlattenBinaryTreeToLinkedList() {
	// TODO Auto-generated constructor stub

}

FlattenBinaryTreeToLinkedList::~FlattenBinaryTreeToLinkedList() {
	// TODO Auto-generated destructor stub
}

void FlattenBinaryTreeToLinkedList::TestSuite() {
	TreeNode * root;
	map<int, int> nodes;

	cout << "test case 1" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	this->flatten(root);
	assert(root == NULL);
	this->DumpRightNodes(root);

	cout << "test case 2" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	this->flatten(root);
	assert(root != NULL);
	assert(root->left == NULL);
	assert(root->right == NULL);
	this->DumpRightNodes(root);

	cout << "test case 3" << endl;
	nodes = {{1, 1}, {2, 2}};
	root = GenBinaryTreeFromMap(nodes);
	this->flatten(root);
	assert(root != NULL);
	assert(root->left == NULL);
	assert(root->right != NULL);
	assert(root->right->val == 2);
	this->DumpRightNodes(root);

	cout << "test case 4" << endl;
	nodes = {{1, 1}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	this->flatten(root);
	assert(root != NULL);
	assert(root->left == NULL);
	assert(root->right != NULL);
	assert(root->right->val == 3);
	this->DumpRightNodes(root);

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	this->flatten(root);
	assert(root != NULL);
	assert(root->left == NULL);
	assert(root->right != NULL);
	assert(root->right->val == 2);
	assert(root->right->right->val == 3);
	this->DumpRightNodes(root);

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 5}, {4, 3}, {5, 4}, {7, 6}};
	root = GenBinaryTreeFromMap(nodes);
	this->flatten(root);
	assert(root != NULL);
	assert(root->left == NULL);
	assert(root->right != NULL);
	assert(root->right->val == 2);
	assert(root->right->right->val == 3);
	this->DumpRightNodes(root);
}

void FlattenBinaryTreeToLinkedList::DumpRightNodes(TreeNode* root) {
	cout << "[";
	while(root)
	{
		cout << root->val;
		if(root->right)
		{
			cout << ", ";
		}
		root = root->right;
	}
	cout << "]" << endl;
}
