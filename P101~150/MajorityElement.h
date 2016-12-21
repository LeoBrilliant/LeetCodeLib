/*
 * MajorityElement.h
 *
 *  Created on: 2016年12月21日
 *      Author: user
 */

#ifndef P101_150_MAJORITYELEMENT_H_
#define P101_150_MAJORITYELEMENT_H_

#include "../Interface/BasicSolution.h"

class MajorityElement: public BasicSolution {
public:
	MajorityElement();
	virtual ~MajorityElement();

	// 速度慢，而且空间开销不小
    int majorityElement1(vector<int>& nums) {
    	int ret = 0;
    	unordered_map<int, int> counter;

    	int level = nums.size() / 2;

    	for(auto i : nums)
    	{
    		if(counter.find(i) == counter.end())
    		{
    			counter[i] = 1;
    		}
    		else
    		{
    			counter[i] ++;
    		}
    	}

    	for(const auto & pair : counter)
    	{
    		if(pair.second > level)
    		{
    			ret = pair.first;
    			break;
    		}
    	}
    	return ret;
    }

    // 一种投票方法
    int majorityElement2(vector<int>& nums) {
    	int ret = 0;
    	int curr = nums[0];
    	int counter = 1;

    	int n = nums.size();
    	for(int i = 1; i < n; ++i)
    	{
    		if(nums[i] == curr)
    		{
    			counter ++;
    		}
    		else
    		{
    			if(counter == 0)
    			{
    				curr = nums[i];
    				counter = 1;
    			}
    			else
    			{
    				counter --;
    			}
    		}
    	}
    	if(counter)
    		ret = curr;
    	return ret;
    }

    int GetMajorityElement(vector<int> & nums, int begin, int end)
    {
    	if(begin == end || begin == end - 1)
    	{
    		return nums[begin];
    	}

    	int middle = (begin + end) / 2;
    	int major1 = GetMajorityElement(nums, begin, middle);
    	int major2 = GetMajorityElement(nums, middle + 1, end);

    	int major;
    	if(major1 == major2)
    	{
    		major = major1;
    	}
    	else
    	{
    		int counter = 0;
    		for(int i = begin; i <= end; ++i)
    		{
    			if(nums[i] == major1)
    			{
    				counter ++;
    			}
    		}
    		if(counter > (end - begin + 1) / 2)
    		{
    			major = major1;
    		}
    		else
    		{
    			major = major2;
    		}
    	}

    	return major;
    }
    // 递归解法
    int majorityElement(vector<int>& nums) {
    	int ret = 0;

    	int n = nums.size();
    	ret = GetMajorityElement(nums, 0, n - 1);
    	return ret;
    }

    void TestSuite();
};

#endif /* P101_150_MAJORITYELEMENT_H_ */
