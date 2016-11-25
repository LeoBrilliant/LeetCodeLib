/*
 * ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"

ConstructBinaryTreeFromInorderAndPostorderTraversal::ConstructBinaryTreeFromInorderAndPostorderTraversal() {
	// TODO Auto-generated constructor stub

}

ConstructBinaryTreeFromInorderAndPostorderTraversal::~ConstructBinaryTreeFromInorderAndPostorderTraversal() {
	// TODO Auto-generated destructor stub
}

void ConstructBinaryTreeFromInorderAndPostorderTraversal::TestSuite() {
	vector<int> inorder;
	vector<int> postorder;
	TreeNode * root;
	int ret;
	vector<int> buf;

	cout << "test case 1" << endl;
	postorder = {};
	inorder = {};
	root = buildTree(inorder, postorder);
	assert(root == NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 2" << endl;
	postorder = {1};
	inorder = {1};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 3" << endl;
	postorder = {1, 2, 3};
	inorder = {2, 1, 3};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 4" << endl;
	postorder = {1, 2, 4};
	inorder = {4, 2, 1};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 5" << endl;
	postorder = {1, 3, 7};
	inorder = {1, 3, 7};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 6" << endl;
	postorder = {7, 3, 1};
	inorder = {1, 3, 7};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 7" << endl;
	postorder = {4, 2, 1};
	inorder = {4, 2, 1};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();

	cout << "test case 8" << endl;
	postorder = {2, 3, 1};
	inorder = {2, 1, 3};
	root = buildTree(inorder, postorder);
	assert(root != NULL);
	PostOrderTraversal(root, buf);
	ret = CmpVector(postorder, buf);
	assert(ret == 0);
	DumpVector(postorder);
	DumpVector(buf);
	buf.clear();
	InOrderTraversal(root, buf);
	ret = CmpVector(inorder, buf);
	assert(ret == 0);
	DumpVector(inorder);
	DumpVector(buf);
	buf.clear();
}
