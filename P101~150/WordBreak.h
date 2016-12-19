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
    bool wordBreakI(string s, unordered_set<string> & wordDict)
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

    // 这是用递归就TLE的节奏啊
	void GetAllBreak(string s, unordered_set<string> & dict,
			vector<string> & holder, vector<string> & ret, int currlen, int len)
	{
		if(currlen == len)
		{
			string tmp;
			int n = holder.size();
			for(int i = 0; i < n; ++i)
			{
				tmp += holder[i];
				if(i != n - 1)
					tmp += " ";
			}
			ret.push_back(tmp);
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
				GetAllBreak(s.substr(i, n - i), dict, holder, ret, currlen + i, len);
				holder.pop_back();
			}
		}
	}

    vector<string> wordBreakII(string s, unordered_set<string>& wordDict) {
    	vector<string> ret;
    	int n = s.size();
    	if(n)
    	{
    		vector<string> holder;
    		GetAllBreak(s, wordDict, holder, ret, 0, n);
    	}
    	return ret;
    }

    void GetBreaks(string &s, vector<string> & ret, vector<unordered_set<int>> & flags, vector<string> & buf, int index)
    {
    	if(index <= 0)
    	{
			string tmp;
			int n = buf.size();
			for(int i = n - 1; i >= 0; --i)
			{
				tmp += buf[i];
				if(i != 0)
					tmp += " ";
			}
			ret.push_back(tmp);
			return;
    	}

    	while(!flags[index].size())
    	{
    		index--;
    	}

    	for(auto it = flags[index].begin(); it != flags[index].end(); ++it)
    	{
    		int begin = *it;
    		string word = s.substr(begin, index - begin);
    		//cout << "word = " << word << endl;
    		buf.push_back(word);
    		//if(begin != 0)
    			GetBreaks(s, ret, flags, buf, begin);
    		//else
    		//	GetBreaks(s, ret, flags, buf, -1);
    		buf.pop_back();
    	}
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    	vector<string> ret;
    	int n = s.size();
    	if(!n)
    	{
    		return ret;
    	}

		vector<unordered_set<int>> flags(n + 1);
		for(int i = 1; i <= n; ++ i)
		{
			for(int j = i; j > 0; j--)
			{
				if(i == j && wordDict.find(s.substr(0, i)) != wordDict.end())
				{
					if(flags[i].find(0) == flags[i].end())
					{
						flags[i].insert(0);
						//cout << s.substr(0, i) << endl;
					}
				}
				else if(flags[j].size() && wordDict.find(s.substr(j , i - j)) != wordDict.end())
				{
					if(flags[i].find(j) == flags[i].end())
					{
						flags[i].insert(j);
						//cout << s.substr(j, i - j) << endl;
					}
				}
			}
		}

		if(flags[n].size())
		{
			vector<string> buf;
			this->GetBreaks(s, ret, flags, buf, n);
		}
    	return ret;
    }

    void TestSuite1();

    void TestSuite2();

    void TestSuite();
};

#endif /* P101_150_WORDBREAK_H_ */
