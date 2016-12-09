/*
 * BestTimeToBuyAndSellStock.h
 *
 *  Created on: 2016年12月8日
 *      Author: user
 */

#ifndef P101_150_BESTTIMETOBUYANDSELLSTOCK_H_
#define P101_150_BESTTIMETOBUYANDSELLSTOCK_H_

#include "../Interface/BasicSolution.h"

class BestTimeToBuyAndSellStock: public BasicSolution {
public:
	BestTimeToBuyAndSellStock();
	virtual ~BestTimeToBuyAndSellStock();

    int maxProfit1(vector<int>& prices) {
    	int buy = 0;
    	int sell = 0;
    	int ret = 0;

    	int n = prices.size();

    	for(int i = 0; i < n; ++i)
    	{
    		buy = prices[i];
    		for(int j = i + 1; j < n; ++j)
    		{
    			sell = prices[j];
    			int profit = sell - buy;
    			if(profit > ret)
    			{
    				ret = profit;
    			}
    		}
    	}
    	return ret;
    }

    int maxProfit(vector<int>& prices) {
    	int ret = 0;

    	int n = prices.size();

    	if(n <= 1)
    		return ret;

    	int buy = prices[0];
    	int sell = prices[0];

    	for(int i = 1; i < n; ++i)
    	{
    		if(prices[i] < buy)
    		{
    			buy = prices[i];
    		}
    		else
    		{
    			sell = prices[i];
    			int profit = sell - buy;
    			if(profit > ret)
    			{
    				ret = profit;
    			}
    		}
    	}

    	return ret;
    }
    void TestSuite();
};

#endif /* P101_150_BESTTIMETOBUYANDSELLSTOCK_H_ */
