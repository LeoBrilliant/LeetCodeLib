/*
 * WordBreak.h
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#ifndef P101_150_WORDBREAK_H_
#define P101_150_WORDBREAK_H_

#include "../Interface/BasicSolution.h"

class WordBreak: public BasicSolution {
public:
	WordBreak();
	virtual ~WordBreak();

	void GetWords(string s, unordered_set<string> & dict,
			vector<string> & holder, int currlen, int len)
	{
		if(currlen == len)
		{
			return;
		}
		int n = s.length();
		// int l = 0;
		for(int i = 1; i <= n; ++i)
		{
			string word = s.substr(0, i);
			if(dict.find(word) != dict.end())
			{
				holder.push_back(word);
				GetWords(s.substr(i, n - i), dict, holder, currlen + i, len);
				holder.pop_back();
			}
		}
	}

	//TLE
	bool CanBreak(string s, int begin, unordered_set<string> & dict, int currlen)
	{
		bool ret = false;
		int n = s.length();

		if(currlen == n)
		{
			return true;
		}

		for(int i = 1; i <= n - begin; ++i)
		{
			string word = s.substr(begin, i);
			if(dict.find(word) != dict.end())
			{
				ret = CanBreak(s, begin + i, dict, currlen + i);
				if(ret)
					break;
			}
		}
		return ret;
	}

	bool CanBreak(string s, unordered_set<string> & dict)
	{
		bool ret = false;
		int n = s.length();

		if(n)
		{
			vector<string> holder;
			int len = 0;
			int begin = 0;
			while(len != n)
			{
				string tmp;
				for(int i = 1; i <= n - begin; ++i)
				{
					tmp = s.substr(begin, i);

					if(dict.find(tmp) != dict.end())
					{
						holder.push_back(tmp);
					}
				}
			}
		}
		return ret;
	}

    bool wordBreak1(string s, unordered_set<string>& wordDict) {
    	bool ret = false;

    	if(s.length())
    	{
    		ret = CanBreak(s, 0, wordDict, 0);
    	}
    	return ret;
    }

    // 如果内存循环使用了break，就演变成贪心算法
    bool wordBreak(string s, unordered_set<string> & wordDict)
    {
    	bool ret = false;
    	int n = s.length();
    	if(n)
    	{
    		vector<bool> flags(n, false);
    		for(int i = 0; i < n; ++ i)
    		{
    			for(int j = i; j >= 0; j--)
    			{
    				if(i == j && wordDict.find(s.substr(0, i + 1)) != wordDict.end())
    				{
    					flags[i] = true;
    					break;
    				}
    				else if(flags[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end())
    				{
    					flags[i] = true;
    					break;
    				}
    			}
    		}
    		ret = flags[n - 1];
    	}
    	return ret;
    }

    void TestSuite1();

    void TestSuite();
};

#endif /* P101_150_WORDBREAK_H_ */
