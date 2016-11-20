/*
 * BucketSort.h
 *
 *  Created on: 2016年11月18日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_BUCKETSORT_H_
#define P101_150_BUCKETSORT_H_

#include "../Interface/BasicSolution.h"

class BucketSort: public BasicSolution {
public:
	BucketSort();
	virtual ~BucketSort();

	void Sort(vector<int> & nums)
	{
		int tmp;
		for(size_t i = 0; i < nums.size(); ++i)
		{
			while(nums[i] != i)
			{
				tmp = nums[nums[i]];
				nums[nums[i]] = nums[i];
				nums[i] = tmp;
			}
		}
	}

	void Sort(vector<int> & nums, vector<int> & index)
	{
		int tmp;
		int ind;
		for(size_t i = 0; i < nums.size(); ++i)
		{
			while(index[i] != i)
			{
				tmp = nums[index[i]];
				ind = index[index[i]];
				nums[index[i]] = nums[i];
				index[index[i]] = index[i];
				nums[i] = tmp;
				index[i] = ind;
			}
		}
	}

	void TestSuite();
};

#endif /* P101_150_BUCKETSORT_H_ */
