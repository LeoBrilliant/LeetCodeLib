/*
 * ValidPalindrome.h
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_VALIDPALINDROME_H_
#define P101_150_VALIDPALINDROME_H_

#include "../Interface/BasicSolution.h"

class ValidPalindrome: public BasicSolution {
public:
	ValidPalindrome();
	virtual ~ValidPalindrome();

    bool isPalindrome(string s) {
        bool ret = true;

        if(s.length())
        {
        	int b = 0;
        	int e = s.length() - 1;
        	int n = s.length();
        	while(b <= e)
        	{
        		while(b < n - 1 && !isalnum(s[b])) b++;
        		while(e > b && !isalnum(s[e])) e--;

        		if(b >= e)
        		{
        			break;
        		}

        		//这里的写法可以优化一次
        		//if(isalnum(s[b]) && isalnum(s[e]) && (s[b] == s[e] || (tolower(s[b]) == tolower (s[e]))))
        		if((s[b] == s[e] || (tolower(s[b]) == tolower (s[e]))))
        		{
        			b++;
        			e--;
        			continue;
        		}
        		else
        		{
        			ret = false;
        			break;
        		}
        	}
        }
        return ret;
    }

    void TestSuite();
};

#endif /* P101_150_VALIDPALINDROME_H_ */
