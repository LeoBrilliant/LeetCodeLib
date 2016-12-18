/*
 * WordBreak.cpp
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#include "WordBreak.h"

WordBreak::WordBreak() {
	// TODO Auto-generated constructor stub

}

WordBreak::~WordBreak() {
	// TODO Auto-generated destructor stub
}

void WordBreak::TestSuite1()
{
	string s;
	unordered_set<string> dict;
	bool ret;

	cout << "test case 1" << endl;
	s = "";
	dict = {};
	ret = this->wordBreak(s, dict);
	assert(ret == false);

	cout << "test case 2" << endl;
	s = "1";
	dict = {};
	ret = this->wordBreak(s, dict);
	assert(ret == false);

	cout << "test case 3" << endl;
	s = "";
	dict = {"1"};
	ret = this->wordBreak(s, dict);
	assert(ret == false);

	cout << "test case 4" << endl;
	s = "1";
	dict = {"1"};
	ret = this->wordBreak(s, dict);
	assert(ret == true);

	cout << "test case 5" << endl;
	s = "1a";
	dict = {"1"};
	ret = this->wordBreak(s, dict);
	assert(ret == false);

	cout << "test case 6" << endl;
	s = "1a";
	dict = {"1", "a"};
	ret = this->wordBreak(s, dict);
	assert(ret == true);

	cout << "test case 6" << endl;
	s = "1ab";
	dict = {"1", "a", "b"};
	ret = this->wordBreak(s, dict);
	assert(ret == true);

	cout << "test case 7" << endl;
	s = "leetcode";
	dict = {"1eet"};
	ret = this->wordBreak(s, dict);
	assert(ret == false);

	cout << "test case 8" << endl;
	s = "leetcode";
	dict = {"leet", "code"};
	ret = this->wordBreak(s, dict);
	assert(ret == true);

	cout << "test case 9" << endl;
	s = "leet code";
	dict = {"leet", "code"};
	ret = this->wordBreak(s, dict);
	assert(ret == false);

	cout << "test case 10" << endl;
	s = "leet code";
	dict = {"leet", "code", " "};
	ret = this->wordBreak(s, dict);
	assert(ret == true);

}
void WordBreak::TestSuite() {
	TestSuite1();
}
