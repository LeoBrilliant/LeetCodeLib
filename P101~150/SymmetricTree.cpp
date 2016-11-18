/*
 * SymmetricTree.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#include "SymmetricTree.h"

SymmetricTree::SymmetricTree() {
	// TODO Auto-generated constructor stub

}

SymmetricTree::~SymmetricTree() {
	// TODO Auto-generated destructor stub
}

bool SymmetricTree::IsSymmetricHelper(TreeNode* t1, TreeNode* t2) {
	bool ret = false;
	if(!t1 && !t2)
	{
		ret = true;
	}
	else if(!t1 || !t2)
	{
		ret = false;
	}
	else
	{
		if(t1->val != t2->val)
			ret = false;
		else if(t1 == t2)
		{
			ret = IsSymmetricHelper(t1->left, t1->right);
		}
		else
		{
			ret = IsSymmetricHelper(t1->left, t2->right) && IsSymmetricHelper(t1->right, t2->left);
		}
	}
	return ret;
}

bool SymmetricTree::isSymmetric(TreeNode* root) {
	return IsSymmetricHelper(root, root);
}


void SymmetricTree::TestSuite()
{
	int total = 0;
	int passed = 0;

	TreeNode * root = NULL;
	map<int, int> nodes;
	bool ret;

	cout << "test case 1" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	ret = isSymmetric(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 2" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isSymmetric(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 3" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 2}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isSymmetric(root);
	assert(ret == true);
	cout << ret << endl;


	cout << "test case 4" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isSymmetric(root);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isSymmetric(root);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isSymmetric(root);
	assert(ret == false);
	cout << ret << endl;
}
