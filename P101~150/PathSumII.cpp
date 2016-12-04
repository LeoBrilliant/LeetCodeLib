/*
 * PathSumII.cpp
 *
 *  Created on: 2016年12月4日
 *      Author: LeoBrilliant
 */

#include "PathSumII.h"

PathSumII::PathSumII() {
	// TODO Auto-generated constructor stub

}

PathSumII::~PathSumII() {
	// TODO Auto-generated destructor stub
}

void PathSumII::TestSuite() {
	TreeNode * root;
	map<int, int> nodes;
	int sum;
	vector<vector<int>> ret;

	cout << "test case 1" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	sum = 0;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 0);

	cout << "test case 2" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 1;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 0;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 0);

	cout << "test case 4" << endl;
	nodes = {{1, 1}, {2, 2}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 3;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 1;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 0);

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 4;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 7" << endl;
	nodes = {{1, 5}, {2, 4}, {3, 8}, {4, 11}, {6, 13}, {7, 4}, {8, 7}, {9, 2}, {14, 5}, {15, 1}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 22;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 8" << endl;
	nodes = {{1, 1}, {3, 2}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 3;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 9" << endl;
	nodes = {{1, 1}, {3, 2}};
	root = GenBinaryTreeFromMap(nodes);
	sum = 1;
	ret = this->PathSum(root, sum);
	assert(ret.size() == 0);
}
