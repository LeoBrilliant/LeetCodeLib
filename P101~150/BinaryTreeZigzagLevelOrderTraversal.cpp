/*
 * BinaryTreeZigzagzigzagLevelOrderTraversal.cpp
 *
 *  Created on: 2016年11月21日
 *      Author: user
 */

#include "BinaryTreeZigzagLevelOrderTraversal.h"

BinaryTreeZigzagLevelOrderTraversal::BinaryTreeZigzagLevelOrderTraversal() {
	// TODO Auto-generated constructor stub

}

BinaryTreeZigzagLevelOrderTraversal::~BinaryTreeZigzagLevelOrderTraversal() {
	// TODO Auto-generated destructor stub
}

void BinaryTreeZigzagLevelOrderTraversal::TestSuite() {
	vector<vector<int>> ret;
	TreeNode * root;
	map<int, int> nodes;

	cout << "test case 1" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 0);
	DumpVectorOfVector(ret);

	cout << "test case 2" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	nodes = {{1, 1}, {2, 2}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 4" << endl;
	nodes = {{1, 1}, {3, 2}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 3);
	DumpVectorOfVector(ret);

	cout << "test case 7" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}, {6, 6}, {7, 7}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 3);
	DumpVectorOfVector(ret);

	cout << "test case 8" << endl;
	nodes = {{1, 3}, {2, 9}, {3, 20}, {6, 15}, {7, 7}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 3);
	DumpVectorOfVector(ret);

	cout << "test case 9" << endl;
	nodes = {{1, 3}, {2, 9}, {3, 20}, {6, 15}, {7, 7}, {12, 12}, {13, 13}};
	root = GenBinaryTreeFromMap(nodes);
	ret = zigzagLevelOrder(root);
	assert(ret.size() == 4);
	DumpVectorOfVector(ret);

}
