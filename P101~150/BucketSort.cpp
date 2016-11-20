/*
 * BucketSort.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: LeoBrilliant
 */

#include "BucketSort.h"

BucketSort::BucketSort() {
	// TODO Auto-generated constructor stub

}

BucketSort::~BucketSort() {
	// TODO Auto-generated destructor stub
}

void BucketSort::TestSuite() {
	vector<int> nums;
	vector<int> cpy;
	vector<int> index;
	int ret;

	cout << "test case 1" << endl;
	nums = {};
	cpy = nums;
	Sort(nums);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);

	cout << "test case 2" << endl;
	nums = {0, 1, 2, 3, 4};
	cpy = nums;
	Sort(nums);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);

	cout << "test case 3" << endl;
	nums = {4, 3 ,2, 1, 0};
	cpy = nums;
	Sort(nums);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);

	cout << "test case 4" << endl;
	nums = {4, 3 ,2, 1, 0, 9, 8, 7, 6, 5};
	cpy = nums;
	Sort(nums);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);

	cout << "test case 5" << endl;
	nums = {0, 1, 2, 3, 4};
	index = nums;
	cpy = nums;
	Sort(nums, index);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);
	DumpVector(index);

	cout << "test case 6" << endl;
	nums = {4, 3 ,2, 1, 0};
	index = nums;
	cpy = nums;
	Sort(nums, index);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);
	DumpVector(index);

	cout << "test case 7" << endl;
	nums = {4, 3 ,2, 1, 0, 9, 8, 7, 6, 5};
	index = nums;
	cpy = nums;
	Sort(nums, index);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(nums, cpy);
	assert(ret == 0);
	DumpVector(nums);
	DumpVector(index);

	cout << "test case 8" << endl;
	nums = {0, 1, 2, 3, 4};
	index = {4, 3 ,2, 1, 0};
	cpy = nums;
	Sort(nums, index);
	sort(cpy.begin(), cpy.end());
	ret = CmpVector(index, cpy);
	assert(ret == 0);
	DumpVector(nums);
	DumpVector(index);
}
