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

    int maxProfit2(vector<int>& prices) {
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
    		int size = p.size();

    		if(size)
    		{
        		int profit1 = 0;
        		int profit2 = 0;
        		int bestBuy = p[0];
        		int profit = 0;
    			for(int i = 1; i < size; i += 2)
				{
    				if(bestBuy > p[i - 1])
    				{
    					bestBuy = p[i - 1];
    				}
    				profit = p[i] - bestBuy;
    				if(profit > profit1)
    				{
    					profit1 = profit;
    				}
    				profit2 = 0;
    				if(i + 2 < size)
    				{
    					int bestBuy2 = p[i + 1];
    					int tmp = 0;
    					for(int j = i + 2; j < size; j += 2)
    					{
    	    				if(bestBuy2 > p[j - 1])
    	    				{
    	    					bestBuy2 = p[j - 1];
    	    				}
    	    				tmp = p[j] - bestBuy2;
    	    				if(tmp > profit2)
    	    				{
    	    					profit2 = tmp;
    	    				}
    					}
    				}
					if(profit1 + profit2 > ret)
					{
						ret = profit1 + profit2;
					}
				}
    		}
    	}
    	return ret;
    }

    int maxProfit(vector<int>& prices) {
		int buy1=numeric_limits<int>::min();
		int buy2=numeric_limits<int>::min();
		int sell1=0;
		int sell2=0;
		for(int i=0;i<prices.size();i++)
		{
			sell2=max(sell2,buy2+prices[i]);
			buy2=max(buy2,sell1-prices[i]);
			sell1=max(sell1,buy1+prices[i]);
			buy1=max(buy1,-prices[i]);
		}
		return sell2;
	}

    void TestSuite();
};

#endif /* P101_150_BESTTIMETOBUYANDSELLSTOCKIII_H_ */
