/*
 * NQueens.cpp
 *
 *  Created on: 2016年10月25日
 *      Author: user
 */

#include "P51~100.h"

bool CheckXY(vector<string> & board, int x, int y)
{
	bool ret = true;
	char c;
	char t = 'Q';
	int n = board.size();

	// Check Row
	for(int i = 0; i < n; ++i)
	{
		c = board[x][i];
		if(i != y && c == t)
			return false;
	}

	// Check Column
	for(size_t j = 0; j < n; ++j)
	{
		c = board[j][y];
		if(j != x && c == t)
			return false;
	}

	int row = x;
	int col = y;
	// Check diagonal
	for(row = row + 1, col = col + 1; row < n && col < n; ++ row, ++ col)
	{
		c = board[row][col];
		if(c == t)
			return false;
	}
	for(row = x -1, col = y - 1; row >= 0 && col >= 0; --row, --col)
	{
		c = board[row][col];
		if(c == t)
			return false;
	}

	// Check anti-diagonal
	for(row = x + 1, col = y - 1; row < n && col >= 0; ++ row, -- col)
	{
		c = board[row][col];
		if(c == t)
			return false;
	}
	for(row = x - 1, col = y + 1; row >= 0 && col < n; -- row, ++col)
	{
		c = board[row][col];
		if(c == t)
			return false;
	}
	return ret;
}

vector<vector<string>> solveNQueens(int n) {

	vector<vector<string>> ret;

	string s(n, '.');
	vector<string> vs;
	stack<pair<int, int>> cord;
	pair<int, int> xy;
	bool check = true;

	// 初始化棋盘
	for(int i = 0; i < n; ++i)
		vs.push_back(s);

	int x, y;
	int tmpy = 0;
	for(x = 0; x < n; ++x)
	{
		for(y = tmpy; y < n; ++y)
		{
			tmpy = 0;
			vs[x][y] = 'Q';
			// 检查当前位置，如果检查通过则记录该位置，扫描下一行。
			// 如果检查不通过，则恢复棋盘
			check = CheckXY(vs, x, y);
			if(check)
			{
				xy = make_pair(x, y);
				cord.push(xy);
				break;
			}
			else
			{
				vs[x][y] = '.';
			}

			// 如果栈内有已经扫描过的位置，并且扫描至当前行最后一个位置时没有找到合适的放置
			// 位置，则回溯至上一个保存位置的下一个元素进行扫描
			while(cord.size() && y == n - 1 && !check)
			{
				xy = cord.top();
				cord.pop();
				x = xy.first;
				y = xy.second;
				vs[x][y] = '.';
			}
			check = false;
			//tmpy = y + 1;
		}

		// 如果第一行扫描至最后一个位置，并且没有找到合适的位置，则扫描结束
		if(y == n && !check && cord.empty())
			break;

		if(x == n - 1 && check)
		{
			//DumpVectorOfStringByChar(vs);
			if(cord.size() == n)
				ret.push_back(vs);

			if(cord.size())
			{
				xy = cord.top();
				cord.pop();
				x = xy.first;
				y = xy.second;
				vs[x][y] = '.';
				x --;
				tmpy = y + 1;
			}
			//if(tmpy == n)
			//	break;
		}
	}
	return ret;
}

void SolveNQueensTest()
{
	vector<vector<string>> ret;

	ret = solveNQueens(5);

	DumpVectorOfVectorOfStringByChar(ret);
}
