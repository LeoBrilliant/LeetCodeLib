/*
 * BestTimeToBuyAndSellStockII.h
 *
 *  Created on: 2016年12月9日
 *      Author: user
 */

#ifndef P101_150_BESTTIMETOBUYANDSELLSTOCKII_H_
#define P101_150_BESTTIMETOBUYANDSELLSTOCKII_H_

#include "../Interface/BasicSolution.h"

class BestTimeToBuyAndSellStockII: public BasicSolution {
public:
	BestTimeToBuyAndSellStockII();
	virtual ~BestTimeToBuyAndSellStockII();

    int maxProfit1(vector<int>& prices) {
    	int ret = 0;

    	int n = prices.size();

    	if(n > 1)
    	{
    		stack<int> calc;
    		int buy = 0;
    		int sell = 0;
    		int profit = 0;

    		for(auto i : prices)
    		{
    			if(calc.empty() || i >= calc.top())
    			{
    				calc.push(i);
    			}
    			else
    			{
    				if(calc.size() > 1)
    				{
    					sell = calc.top();
    					while(calc.size() != 1)
    					{
    						calc.pop();
    					}
    					buy = calc.top();

    					profit = sell - buy;
    					ret += profit;
    				}
    				calc.pop();
    				calc.push(i);
    			}
    		}

    		if(calc.size() > 1)
    		{
    			sell = calc.top();
				while(calc.size() != 1)
				{
					calc.pop();
				}
				buy = calc.top();

				profit = sell - buy;
				ret += profit;
    		}
    	}
    	return ret;
    }

    int maxProfit(vector<int>& prices) {
    	int ret = 0;

    	int n = prices.size();

    	if(n > 1)
    	{
    		int buy = prices[0];
    		int sell = 0;
    		int profit = 0;
    		for(int i = 1; i < n; ++i)
    		{
    			int curr = prices[i];
    			if(i == n - 1 || curr > prices[i + 1])
    			{
    				sell = curr;
    				profit = sell - buy;
    				if(profit > 0)
    					ret += profit;
    				buy = prices[i + 1];
    			}

    			if(curr < buy)
    			{
    				buy = curr;
    			}
    		}
    	}
    	return ret;
    }
    void TestSuite();
};

#endif /* P101_150_BESTTIMETOBUYANDSELLSTOCKII_H_ */
