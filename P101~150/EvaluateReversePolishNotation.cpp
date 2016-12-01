/*
 * EvaluateReversePolishNotation.cpp
 *
 *  Created on: 2016年11月30日
 *      Author: user
 */

#include "EvaluateReversePolishNotation.h"

EvaluateReversePolishNotation::EvaluateReversePolishNotation() {
	// TODO Auto-generated constructor stub

}

EvaluateReversePolishNotation::~EvaluateReversePolishNotation() {
	// TODO Auto-generated destructor stub
}

void EvaluateReversePolishNotation::TestSuite() {
	vector<string> vs;
	int ret;

	cout << "test case 1" << endl;
	vs = {};
	ret = evalRPN(vs);
	assert(ret == 0);

	cout << "test case 2" << endl;
	vs = {""};
	ret = evalRPN(vs);
	assert(ret == 0);

	cout << "test case 3" << endl;
	vs = {" "};
	ret = evalRPN(vs);
	assert(ret == 0);

	cout << "test case 4" << endl;
	vs = {"1"};
	ret = evalRPN(vs);
	assert(ret == 1);

	cout << "test case 5" << endl;
	vs = {"1", "2", "+"};
	ret = evalRPN(vs);
	assert(ret == 3);
	cout << ret << endl;

	cout << "test case 6" << endl;
	vs = {"1", "2", "-"};
	ret = evalRPN(vs);
	assert(ret == -1);
	cout << ret << endl;

	cout << "test case 7" << endl;
	vs = {" 1", "2 ", " * "};
	ret = evalRPN(vs);
	assert(ret == 2);
	cout << ret << endl;

	cout << "test case 8" << endl;
	vs = {"1", "2", "/"};
	ret = evalRPN(vs);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 9" << endl;
	vs = {"2", "1", "+", "3", "*"};
	ret = evalRPN(vs);
	assert(ret == 9);
	cout << ret << endl;

	cout << "test case 10" << endl;
	vs = {"4", "13", "5", "/", "+"};
	ret = evalRPN(vs);
	assert(ret == 6);
	cout << ret << endl;

}
