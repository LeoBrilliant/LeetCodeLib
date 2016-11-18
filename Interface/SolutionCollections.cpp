/*
 * SolutionCollections.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#include "SolutionCollections.h"
#include "BasicSolution.h"

SolutionCollections::SolutionCollections() {
	// TODO Auto-generated constructor stub

}

SolutionCollections::~SolutionCollections() {
	// TODO Auto-generated destructor stub
	DeleteSolutions();
}

void SolutionCollections::RunLastTestSuite() {
	BasicSolution * last = SolutionSet.back();
	last->TestSuite();
}

void SolutionCollections::InitSolutions() {

}

void SolutionCollections::DeleteSolutions() {
	for(; SolutionSet.size();)
	{
		BasicSolution * last = SolutionSet.back();
		SolutionSet.pop_back();
		delete last;
	}
}
