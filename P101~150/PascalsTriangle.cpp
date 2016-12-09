/*
 * PascalsTriangle.cpp
 *
 *  Created on: 2016年12月5日
 *      Author: user
 */

#include "PascalsTriangle.h"

PascalsTriangle::PascalsTriangle() {
	// TODO Auto-generated constructor stub

}

PascalsTriangle::~PascalsTriangle() {
	// TODO Auto-generated destructor stub
}

void PascalsTriangle::TestSuite() {
	vector<vector<int>> ret;
	int numRows;
	int size;

	cout << "test case 1" << endl;
	numRows = 0;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 0);
	DumpVectorOfVector(ret);

	cout << "test case 2" << endl;
	numRows = 1;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 1);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	numRows = 2;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 2);
	DumpVectorOfVector(ret);

	cout << "test case 4" << endl;
	numRows = 3;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 3);
	DumpVectorOfVector(ret);

	cout << "test case 5" << endl;
	numRows = 5;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 5);
	DumpVectorOfVector(ret);

	cout << "test case 6" << endl;
	numRows = -1;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 0);
	DumpVectorOfVector(ret);

	cout << "test case 7" << endl;
	numRows = 10;
	ret = this->generate(numRows);
	size = ret.size();
	assert(size == 10);
	DumpVectorOfVector(ret);

	cout << "test case 8" << endl;
	for(int i = -1; i < 10; ++i)
	{
		vector<int> vi = this->getRow(i);
		DumpVector(vi);
	}
}
