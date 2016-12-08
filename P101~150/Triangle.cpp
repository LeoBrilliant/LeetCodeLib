/*
 * Triangle.cpp
 *
 *  Created on: 2016年12月5日
 *      Author: LeoBrilliant
 */

#include "Triangle.h"

Triangle::Triangle() {
	// TODO Auto-generated constructor stub

}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

void Triangle::TestSuite() {
	vector<vector<int>> vvi;
	int ret;

	cout << "test case 1" << endl;
	vvi = {};
	ret = this->minimumTotal(vvi);
	assert(ret == 0);

	cout << "test case 2" << endl;
	vvi = {{1}};
	ret = this->minimumTotal(vvi);
	assert(ret == 1);

	cout << "test case 3" << endl;
	vvi = {{1}, {2}};
	ret = this->minimumTotal(vvi);
	assert(ret == 3);

	cout << "test case 4" << endl;
	vvi = {{1}, {2}, {3}};
	ret = this->minimumTotal(vvi);
	assert(ret == 6);

	cout << "test case 5" << endl;
	vvi = {{1}, {2, 2}, {3, 3, 3}};
	ret = this->minimumTotal(vvi);
	assert(ret == 6);

	cout << "test case 6" << endl;
	vvi = {{1}, {2, 3}, {3, 1, 2}};
 	ret = this->minimumTotal(vvi);
	assert(ret == 4);

	cout << "test case 7" << endl;
	vvi = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	ret = this->minimumTotal(vvi);
	assert(ret == 11);

	cout << "test case 8" << endl;
	vvi = {{-1}, {3, 2}, {-3, 1, -1}};
	ret = this->minimumTotal(vvi);
	assert(ret == -1);

}
