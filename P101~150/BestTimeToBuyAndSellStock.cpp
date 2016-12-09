/*
 * BestTimeToBuyAndSellStock.cpp
 *
 *  Created on: 2016年12月8日
 *      Author: user
 */

#include "BestTimeToBuyAndSellStock.h"

BestTimeToBuyAndSellStock::BestTimeToBuyAndSellStock() {
	// TODO Auto-generated constructor stub

}

BestTimeToBuyAndSellStock::~BestTimeToBuyAndSellStock() {
	// TODO Auto-generated destructor stub
}

void BestTimeToBuyAndSellStock::TestSuite() {
	vector<int> prices;
	int ret;

	cout << "test case 1" << endl;
	prices = {};
	ret = this->maxProfit(prices);
	assert(ret == 0);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 2" << endl;
	prices = {1};
	ret = this->maxProfit(prices);
	assert(ret == 0);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 3" << endl;
	prices = {1, 2};
	ret = this->maxProfit(prices);
	assert(ret == 1);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 4" << endl;
	prices = {1, 2, 3};
	ret = this->maxProfit(prices);
	assert(ret == 2);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 5" << endl;
	prices = {1, 3, 2};
	ret = this->maxProfit(prices);
	assert(ret == 2);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 6" << endl;
	prices = {2, 1};
	ret = this->maxProfit(prices);
	assert(ret == 0);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 7" << endl;
	prices = {3, 2, 1};
	ret = this->maxProfit(prices);
	assert(ret == 0);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 8" << endl;
	prices = {7, 1, 5, 3, 6, 4};
	ret = this->maxProfit(prices);
	assert(ret == 5);
	assert(ret == this->maxProfit1(prices));

	cout << "test case 9" << endl;
	prices = {7, 6, 4, 3, 1};
	ret = this->maxProfit(prices);
	assert(ret == 0);
	assert(ret == this->maxProfit1(prices));

}
