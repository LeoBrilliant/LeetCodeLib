/*
 * BestTimeToBuyAndSellStockIII.cpp
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#include "BestTimeToBuyAndSellStockIII.h"

BestTimeToBuyAndSellStockIII::BestTimeToBuyAndSellStockIII() {
	// TODO Auto-generated constructor stub

}

BestTimeToBuyAndSellStockIII::~BestTimeToBuyAndSellStockIII() {
	// TODO Auto-generated destructor stub
}

void BestTimeToBuyAndSellStockIII::TestSuite() {
	vector<int> prices;
	int ret;

	cout << "test case 1" << endl;
	prices = {};
	ret = this->maxProfit(prices);
	assert(ret == 0);

	cout << "test case 2" << endl;
	prices = {1};
	ret = this->maxProfit(prices);
	assert(ret == 0);

	cout << "test case 3" << endl;
	prices = {1, 2};
	ret = this->maxProfit(prices);
	assert(ret == 1);

	cout << "test case 4" << endl;
	prices = {1, 2, 3};
	ret = this->maxProfit(prices);
	assert(ret == 2);

	cout << "test case 5" << endl;
	prices = {1, 3, 2};
	ret = this->maxProfit(prices);
	assert(ret == 2);

	cout << "test case 6" << endl;
	prices = {2, 1};
	ret = this->maxProfit(prices);
	assert(ret == 0);

	cout << "test case 7" << endl;
	prices = {3, 2, 1};
	ret = this->maxProfit(prices);
	assert(ret == 0);

	cout << "test case 8" << endl;
	prices = {7, 1, 5, 3, 6, 4};
	ret = this->maxProfit(prices);
	cout << ret << endl;
	assert(ret == 7);

	cout << "test case 9" << endl;
	prices = {7, 6, 4, 3, 1};
	ret = this->maxProfit(prices);
	assert(ret == 0);

	cout << "test case 10" << endl;
	prices = {7, 1, 5, 3, 6, 4, 7};
	ret = this->maxProfit(prices);
	cout << ret << endl;
	assert(ret == 8);

}
