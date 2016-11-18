/*
 * Solution101150.h
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#ifndef P101_150_SOLUTION101_150_H_
#define P101_150_SOLUTION101_150_H_

#include "../Common.h"
#include "../Interface/SolutionCollections.h"

class BasicSolution;

class Solution101_150 : public SolutionCollections{
public:
	Solution101_150();
	virtual ~Solution101_150();

	void RunLastTestSuite();

private:
//	vector<BasicSolution*> SolutionSet;
	void InitSolutions();
	void DeleteSolutions();
};

#endif /* P101_150_SOLUTION101_150_H_ */
