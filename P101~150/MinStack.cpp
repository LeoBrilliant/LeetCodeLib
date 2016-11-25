/*
 * MinStack.cpp
 *
 *  Created on: 2016年11月25日
 *      Author: user
 */

#include "MinStack.h"

/*MinStack::MinStack() {
	// TODO Auto-generated constructor stub

}*/

MinStack::~MinStack() {
	// TODO Auto-generated destructor stub
}

void MinStack::TestSuite() {
	MinStack ms;
	int ele;
	int top;
	int min_ele;

	cout << "test case 1" << endl;
	assert(ms.size() == 0);
	//top = ms.top();
	//min_ele = ms.getMin();

	cout << "test case 2" << endl;
	ele = 5;
	ms.push(ele);
	assert(ms.size() == 1);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 5);
	assert(min_ele == 5);

	cout << "test case 3" << endl;
	ele = 4;
	ms.push(ele);
	assert(ms.size() == 2);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 4);
	assert(min_ele == 4);

	cout << "test case 4" << endl;
	ele = 6;
	ms.push(ele);
	assert(ms.size() == 3);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 6);
	assert(min_ele == 4);

	cout << "test case 5" << endl;
	ele = 3;
	ms.push(ele);
	assert(ms.size() == 4);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 3);
	assert(min_ele == 3);

	cout << "test case 6" << endl;
	ms.pop();
	assert(ms.size() == 3);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 6);
	assert(min_ele == 4);

	cout << "test case 7" << endl;
	ms.pop();
	assert(ms.size() == 2);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 4);
	assert(min_ele == 4);

	cout << "test case 8" << endl;
	ms.pop();
	assert(ms.size() == 1);
	top = ms.top();
	min_ele = ms.getMin();
	assert(top == 5);
	assert(min_ele == 5);

	cout << "test case 9" << endl;
	ms.pop();
	assert(ms.size() == 0);
	//top = ms.top();
	//min_ele = ms.getMin();
//	assert(top == 4);
//	assert(min_ele == 4);

}
