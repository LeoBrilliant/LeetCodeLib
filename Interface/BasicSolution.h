/*
 * BasicSolution.h
 *
 *  Created on: 2016年10月23日
 *      Author: LeoBrilliant
 */

#ifndef BASICSOLUTION_H_
#define BASICSOLUTION_H_

#include "../Common.h"

class BasicSolution {
public:
	BasicSolution();
	virtual ~BasicSolution();
	virtual void TestSuite() = 0;
};

#endif /* BASICSOLUTION_H_ */
