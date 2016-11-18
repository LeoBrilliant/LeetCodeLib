/*
 * SolutionCollections.h
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#ifndef INTERFACE_SOLUTIONCOLLECTIONS_H_
#define INTERFACE_SOLUTIONCOLLECTIONS_H_

#include "../Common.h"

class BasicSolution;

class SolutionCollections {
public:
	SolutionCollections();
	virtual ~SolutionCollections();

	virtual void RunLastTestSuite() = 0;

protected:
	vector<BasicSolution*> SolutionSet;

private:
	virtual void InitSolutions();
	virtual void DeleteSolutions();

};

#endif /* INTERFACE_SOLUTIONCOLLECTIONS_H_ */
