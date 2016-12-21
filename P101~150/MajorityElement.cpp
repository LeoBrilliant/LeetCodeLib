/*
 * MajorityElement.cpp
 *
 *  Created on: 2016年12月21日
 *      Author: user
 */

#include "MajorityElement.h"

MajorityElement::MajorityElement() {
	// TODO Auto-generated constructor stub

}

MajorityElement::~MajorityElement() {
	// TODO Auto-generated destructor stub
}

void MajorityElement::TestSuite() {
	vector<int> nums;
	int major;

	cout << "test case 1" << endl;
	nums = {1};
	major = this->majorityElement(nums);
	SHOW(major);
	assert(major == 1);

	cout << "test case 2" << endl;
	nums = {1, 2};
	major = this->majorityElement(nums);
	SHOW(major);
	//assert(major == 0);

	cout << "test case 3" << endl;
	nums = {1, 2, 1};
	major = this->majorityElement(nums);
	SHOW(major);
	assert(major == 1);

	cout << "test case 4" << endl;
	nums = {1, 1, 1, 2};
	major = this->majorityElement(nums);
	SHOW(major);
	assert(major == 1);

	cout << "test case 5" << endl;
	nums = {1, 1, 2, 2};
	major = this->majorityElement(nums);
	SHOW(major);
	//assert(major == 0);

}
