/*
 * PascalsTriangle.h
 *
 *  Created on: 2016年12月5日
 *      Author: user
 */

#ifndef P101_150_PASCALSTRIANGLE_H_
#define P101_150_PASCALSTRIANGLE_H_

#include "../Interface/BasicSolution.h"

class PascalsTriangle: public BasicSolution {
public:
	PascalsTriangle();
	virtual ~PascalsTriangle();

    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> ret;

    	if(numRows >= 1)
    	{
    		vector<int> vi;
    		vi.push_back(1);
    		ret.push_back(vi);
    	}
    	for(int i = 1; i < numRows; ++i)
    	{
    		vector<int> vi;
    		vi.push_back(1);
    		for(size_t j = 1; j < ret[i - 1].size(); ++j)
    		{
    			vi.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
    		}
    		vi.push_back(1);
    		ret.push_back(vi);
    	}
    	return ret;
    }

    vector<int> getRow(int rowIndex) {
    	vector<int> ret, vi;

		if(rowIndex >= 0)
		{
			ret.push_back(1);
		}
		for(int i = 1; i <= rowIndex; ++i)
		{
			vi.push_back(1);
			for(size_t j = 1; j < ret.size(); ++j)
			{
				vi.push_back(ret[j - 1] + ret[j]);
			}
			vi.push_back(1);
			ret = vi;
			vi.clear();
		}
		return ret;
    }

    void TestSuite();
};

#endif /* P101_150_PASCALSTRIANGLE_H_ */
