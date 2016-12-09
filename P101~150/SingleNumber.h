/*
 * SingleNumber.h
 *
 *  Created on: 2016年12月8日
 *      Author: user
 */

#ifndef P101_150_SINGLENUMBER_H_
#define P101_150_SINGLENUMBER_H_

#include "../Interface/BasicSolution.h"

class SingleNumber: public BasicSolution {
public:
	SingleNumber();
	virtual ~SingleNumber();

    int singleNumber(vector<int>& nums) {
    	int flag = 0;
    	int n = nums.size();

    	for(int i = 0; i < n; ++i)
    	{
    		flag ^= nums[i];
    	}

    	return flag;
    }

    void TestSuite();
};

#endif /* P101_150_SINGLENUMBER_H_ */
