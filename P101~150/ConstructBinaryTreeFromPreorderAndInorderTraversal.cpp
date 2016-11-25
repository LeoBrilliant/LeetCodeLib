/*
 * ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"

ConstructBinaryTreeFromPreorderAndInorderTraversal::ConstructBinaryTreeFromPreorderAndInorderTraversal() {
	// TODO Auto-generated constructor stub

}

ConstructBinaryTreeFromPreorderAndInorderTraversal::~ConstructBinaryTreeFromPreorderAndInorderTraversal() {
	// TODO Auto-generated destructor stub
}

void ConstructBinaryTreeFromPreorderAndInorderTraversal::TestSuite() {
	vector<int> preorder;
	vector<int> inorder;
	TreeNode * root;
	int ret;
	vector<int> buf;

	cout << "test case 1" << endl;
	preorder = {};
	inorder = {};
	root = buildTree(preorder, inorder);
	assert(root == NULL);
	PreOrderTraversal(root, buf);
	ret = CmpVector(preorder, buf);
	assert(ret == 0);
	DumpVector(preorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 2" << endl;
	preorder = {1};
	inorder = {1};
	root = buildTree(preorder, inorder);
	assert(root != NULL);
	PreOrderTraversal(root, buf);
	ret = CmpVector(preorder, buf);
	assert(ret == 0);
	DumpVector(preorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 3" << endl;
	preorder = {1, 2, 3};
	inorder = {2, 1, 3};
	root = buildTree(preorder, inorder);
	assert(root != NULL);
	PreOrderTraversal(root, buf);
	ret = CmpVector(preorder, buf);
	assert(ret == 0);
	DumpVector(preorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 4" << endl;
	preorder = {1, 2, 4};
	inorder = {4, 2, 1};
	root = buildTree(preorder, inorder);
	assert(root != NULL);
	PreOrderTraversal(root, buf);
	ret = CmpVector(preorder, buf);
	assert(ret == 0);
	DumpVector(preorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 5" << endl;
	preorder = {1, 3, 7};
	inorder = {1, 3, 7};
	root = buildTree(preorder, inorder);
	assert(root != NULL);
	PreOrderTraversal(root, buf);
	ret = CmpVector(preorder, buf);
	assert(ret == 0);
	DumpVector(preorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

}
