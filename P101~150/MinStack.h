/*
 * MinStack.h
 *
 *  Created on: 2016年11月25日
 *      Author: user
 */

#ifndef P101_150_MINSTACK_H_
#define P101_150_MINSTACK_H_

#include "../Interface/BasicSolution.h"

class MinStack: public BasicSolution {
public:
    MinStack() {

    }

    void push(int x) {
    	container.push(x);
    	if(min_index.empty() || x < min_index.top().second)
    	{
    		min_index.push(make_pair(container.size(), x));
    	}
    }

    void pop() {
    	container.pop();
    	if(min_index.top().first > container.size())
    	{
    		min_index.pop();
    	}
    }

    int top() {
    	return container.top();
    }

    int getMin() {
    	return min_index.top().second;
    }

    int size()
    {
    	return container.size();
    }

//private:
    stack<int> container;
    stack<pair<int, int>> min_index;
	virtual ~MinStack();

	void TestSuite();
};

#endif /* P101_150_MINSTACK_H_ */
