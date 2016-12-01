/*
 * EvaluateReversePolishNotation.h
 *
 *  Created on: 2016年11月30日
 *      Author: user
 */

#ifndef P101_150_EVALUATEREVERSEPOLISHNOTATION_H_
#define P101_150_EVALUATEREVERSEPOLISHNOTATION_H_

#include "../Interface/BasicSolution.h"

class EvaluateReversePolishNotation: public BasicSolution {
public:
	EvaluateReversePolishNotation();
	virtual ~EvaluateReversePolishNotation();

	int GetOperator(string & s)
	{
		int ret = 0;
		size_t begin = s.find_first_not_of(' ');
		size_t end = s.find_last_not_of(' ');

		if(begin != string::npos && end != string::npos)
		{
			 if(begin == end)
			 {
				 switch(s[begin])
				 {
				 case '+':
					 ret = -1;
					 break;
				 case '-':
					 ret = -2;
					 break;
				 case '*':
					 ret = -3;
					 break;
				 case '/':
					 ret = -4;
					 break;
				 }
			 }
		}

		return ret;
	}
	int evalRPN(vector<string>& tokens) {
		int ret = 0;
		stack<int> calc;
		int op1;
		int op2;
		int value;
		for(auto s : tokens)
		{
			value = GetOperator(s);

			switch(value)
			{
			case -1:
				op1 = calc.top();
				calc.pop();
				op2 = calc.top();
				calc.pop();
				value = op1 + op2;
				calc.push(value);
				break;
			case -2:
				op1 = calc.top();
				calc.pop();
				op2 = calc.top();
				calc.pop();
				value = op2 - op1;
				calc.push(value);
				break;
			case -3:
				op1 = calc.top();
				calc.pop();
				op2 = calc.top();
				calc.pop();
				value = op1 * op2;
				calc.push(value);
				break;
			case -4:
				op1 = calc.top();
				calc.pop();
				op2 = calc.top();
				calc.pop();
				value = op2 / op1;
				calc.push(value);
				break;
			default:
				value = atoi(s.c_str());
				calc.push(value);
			}
		}

		if(calc.size()){
			ret = calc.top();
			calc.pop();
		}
		return ret;
	}

	void TestSuite();
};

#endif /* P101_150_EVALUATEREVERSEPOLISHNOTATION_H_ */
