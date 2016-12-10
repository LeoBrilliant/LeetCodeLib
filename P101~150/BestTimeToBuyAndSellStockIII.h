/*
 * BestTimeToBuyAndSellStockIII.h
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_BESTTIMETOBUYANDSELLSTOCKIII_H_
#define P101_150_BESTTIMETOBUYANDSELLSTOCKIII_H_

#include "../Interface/BasicSolution.h"

class BestTimeToBuyAndSellStockIII: public BasicSolution {
public:
	BestTimeToBuyAndSellStockIII();
	virtual ~BestTimeToBuyAndSellStockIII();

    int maxProfit(vector<int>& prices, int begin, int end) {
    	int ret = 0;

    	int n = end - begin + 1;

    	if(n <= 1)
    		return ret;

    	int buy = prices[begin];
    	int sell = prices[begin];

    	for(int i = begin + 1; i <= end; ++i)
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


    // TLE
    int maxProfit1(vector<int>& prices) {
    	int ret = 0;

    	int n = prices.size();

    	if(n > 1)
    	{
    		int profit1 = 0;
    		int profit2 = 0;
    		for(int i = 1; i < n; ++i)
    		{
    			profit1 = maxProfit(prices, 0, i);
    			profit2 = maxProfit(prices, i + 1, n - 1);

    			if(profit1 + profit2 > ret)
    			{
    				ret = profit1 + profit2;
    			}
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
    		vector<int> p;
    		for(int i = 1; i < n; ++i)
    		{
    			int curr = prices[i];
    			if(i == n - 1 || curr > prices[i + 1])
    			{
    				sell = curr;
    				if(sell > buy)
    				{
    					p.push_back(buy);
    					p.push_back(sell);
    				}
    				buy = prices[i + 1];
    			}

    			if(curr < buy)
    			{
    				buy = curr;
    			}
    		}

    		int profit1 = 0;
    		int profit2 = 0;
    		int size = p.size();
    		for(int i = 1; i < size; i += 2)
    		{
    			profit1 = maxProfit(p, 0, i);
    			profit2 = maxProfit(p, i + 1, size - 1);

    			if(profit1 + profit2 > ret)
    			{
    				ret = profit1 + profit2;
    			}
    		}
    	}
    	return ret;
    }

    void TestSuite();
};

#endif /* P101_150_BESTTIMETOBUYANDSELLSTOCKIII_H_ */
