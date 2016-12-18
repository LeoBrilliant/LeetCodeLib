/*
 * SingleNumberII.h
 *
 *  Created on: 2016年12月16日
 *      Author: user
 */

#ifndef P101_150_SINGLENUMBERII_H_
#define P101_150_SINGLENUMBERII_H_

#include "../Interface/BasicSolution.h"

class SingleNumberII: public BasicSolution {
public:
	SingleNumberII();
	virtual ~SingleNumberII();

	// 虽然是O(n)，但是系数比较高。AC
    int singleNumber1(vector<int>& nums) {
    	int ret = 0;

    	int n = nums.size();
    	if(n)
    	{
    		int count = 0;
    		int flag = 1;
    		for(int i = 0; i < 32; ++i)
    		{
    			for(int j = 0; j < n; ++j)
    			{
    				if(nums[j] & flag)
    					count++;
    			}
    			if(count % 3)
    			{
    				ret |= flag;
    			}
    			flag <<= 1;
    			count = 0;
    		}
    	}
    	return ret;
    }

    int singleNumber(vector<int>& nums) {
		int ret = 0;

		int n = nums.size();
		if(n)
		{
			int two = 0;
			int three = 0;
			for(int i = 0; i < n; ++i)
			{
				two |= nums[i] & ret;
				ret ^= nums[i];
				three = ret & two;
				ret &= ~three;
				two &= ~three;
			}
		}
		return ret;
	}


    void TestSuite();
};

#endif /* P101_150_SINGLENUMBERII_H_ */
