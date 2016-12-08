/*
 * Triangle.h
 *
 *  Created on: 2016年12月5日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_TRIANGLE_H_
#define P101_150_TRIANGLE_H_

#include "../Interface/BasicSolution.h"

class Triangle: public BasicSolution {
public:
	Triangle();
	virtual ~Triangle();

    int minimumTotal(vector<vector<int>>& triangle) {
    	int ret = 0;

    	int n = triangle.size();

    	if(n)
    	{
			vector<int> vi = triangle[0];
			vector<int> tmp;
			for(int i = 1; i < n; ++i)
			{
				tmp = triangle[i];
				int m = tmp.size();
				for(int j = 0; j < m; ++j)
				{
					int size = vi.size();
					int begin = min(max(0, j - 1), size - 1);
					int end = min(size - 1, j);
					int s = vi[begin];

					for(int k = begin + 1; k <= end; ++k)
					{
						if(vi[k] < s)
						{
							s = vi[k];
						}
					}

					tmp[j] += s;
				}
				vi = tmp;
			}

			if(vi.size())
			{
				ret = vi[0];
				for(int i = 1; i < vi.size(); ++i)
				{
					if(ret > vi[i])
						ret = vi[i];
				}
			}
    	}
    	return ret;
    }

    void TestSuite();
};

#endif /* P101_150_TRIANGLE_H_ */
