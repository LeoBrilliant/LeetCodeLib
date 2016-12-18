/*
 * SumRootToLeafNumbers.cpp
 *
 *  Created on: 2016年12月18日
 *      Author: LeoBrilliant
 */

#include "SumRootToLeafNumbers.h"

SumRootToLeafNumbers::SumRootToLeafNumbers() {
	// TODO Auto-generated constructor stub
}

SumRootToLeafNumbers::~SumRootToLeafNumbers() {
	// TODO Auto-generated destructor stub
}

#define SHOW(x) \
	cout << #x << "\t=\t" << x << endl

void SumRootToLeafNumbers::TestSuite() {
	TreeNode * root;
	map<int, int> nodes;
	int sum;

	cout << "test case 1" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	assert(sum == 0);
	SHOW(sum);

	cout << "test case 2" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 1);

	cout << "test case 3" << endl;
	nodes = {{1, 1}, {2, 2}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 12);

	cout << "test case 4" << endl;
	nodes = {{1, 1}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 13);

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 25);

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {2, 2}, {4, 4}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 124);

	cout << "test case 7" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 137);

	cout << "test case 8" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {6, 6}, {7, 7}, {8, 8}};
	root = GenBinaryTreeFromMap(nodes);
	sum = this->sumNumbers(root);
	SHOW(sum);
	assert(sum == 1521); // 1248 + 136 + 137
}
