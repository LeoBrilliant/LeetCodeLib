/*
 * Solutions.h
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#ifndef INTERFACE_SOLUTIONS_H_
#define INTERFACE_SOLUTIONS_H_

#include "../Common.h"
#include "SolutionCollections.h"

class Solutions {
public:
	Solutions();
	virtual ~Solutions();

	virtual void TestLastSolutions();
private:
	vector<SolutionCollections*> Sols;
	virtual void InitSolutionCollections();
	virtual void DeleteSolutionCollections();
};

#endif /* INTERFACE_SOLUTIONS_H_ */
