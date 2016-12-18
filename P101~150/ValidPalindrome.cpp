/*
 * ValidPalindrome.cpp
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#include "ValidPalindrome.h"

ValidPalindrome::ValidPalindrome() {
	// TODO Auto-generated constructor stub

}

ValidPalindrome::~ValidPalindrome() {
	// TODO Auto-generated destructor stub
}

#define SHOW(a) \
	cout << #a << "\t" << std::dec << a << "\t" << std::hex << std::showbase << a << endl

static void Show(int a)
{
	cout << "a:\t" << std::dec << a << "\t" << std::hex << std::showbase << a << endl;
}

static void CharTest()
{
	int a = 'a';
	int z = 'z';
	int A = 'A';
	int Z = 'Z';
	int zero = '0';
	int nine = '9';

//	cout << "a: " << std::dec << a << std::hex << a << endl;
//	cout << "z: " << std::dec << z << std::hex << z << endl;
	Show(a);
	Show(z);
	Show(A);
	Show(Z);
	Show(zero);
	Show(nine);

	SHOW(a);
	SHOW(z);
	SHOW(A);
	SHOW(Z);
	SHOW(zero);
	SHOW(nine);
}

void ValidPalindrome::TestSuite() {
	string s;
	bool ret;

	cout << "test case 1" << endl;
	s = "";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 2" << endl;
	s = " ";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 3" << endl;
	s = "  ";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 4" << endl;
	s = "1";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 5" << endl;
	s = "!";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 6" << endl;
	s = "!1";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 7" << endl;
	s = "!11";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 8" << endl;
	s = "1!1";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 9" << endl;
	s = "11!";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 10" << endl;
	s = "1!1!";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 11" << endl;
	s = "1!a1!";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 12" << endl;
	s = "1!aA1!";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 13" << endl;
	s = "1!ab1!";
	ret = this->isPalindrome(s);
	assert(ret == false);

	cout << "test case 14" << endl;
	s = "A man, a plan, a canal: Panama";
	ret = this->isPalindrome(s);
	assert(ret == true);

	cout << "test case 15" << endl;
	s = "race a car";
	ret = this->isPalindrome(s);
	assert(ret == false);

}
