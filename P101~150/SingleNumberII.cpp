/*
 * SingleNumberII.cpp
 *
 *  Created on: 2016年12月16日
 *      Author: user
 */

#include "SingleNumberII.h"

SingleNumberII::SingleNumberII() {
	// TODO Auto-generated constructor stub

}

SingleNumberII::~SingleNumberII() {
	// TODO Auto-generated destructor stub
}

void SingleNumberII::TestSuite() {
	vector<int> nums;
	int ret;

	cout << "test case 1" << endl;
	nums = {};
	ret = this->singleNumber(nums);
	assert(ret == 0);

	cout << "test case 2" << endl;
	nums = {1, 1, 1};
	ret = this->singleNumber(nums);
	assert(ret == 0);

	cout << "test case 3" << endl;
	nums = {1, 1, 1, 2};
	ret = this->singleNumber(nums);
	assert(ret == 2);

	cout << "test case 4" << endl;
	nums = {1, 1, 1, 3};
	ret = this->singleNumber(nums);
	assert(ret == 3);

	cout << "test case 5" << endl;
	nums = {1, 1, 3, 1, 7, 3, 3};
	ret = this->singleNumber(nums);
	assert(ret == 7);

	cout << "test case 6" << endl;
	nums = {1, -1, 1, 3, 1, -1, 3, -1, 3,  -2};
	ret = this->singleNumber(nums);
	assert(ret == -2);

}
