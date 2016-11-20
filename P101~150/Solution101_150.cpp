/*
 * Solution101150.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#include "Solution101_150.h"
#include "SymmetricTree.h"
#include "BinaryTreeLevelOrderTraversal.h"
#include "BucketSort.h"

//class SymmetricTree;

Solution101_150::Solution101_150() {
	// TODO Auto-generated constructor stub
	InitSolutions();
}

Solution101_150::~Solution101_150() {
	// TODO Auto-generated destructor stub
	DeleteSolutions();
}

void Solution101_150::RunLastTestSuite() {
	BasicSolution * last = SolutionSet.back();
	last->TestSuite();
}

void Solution101_150::InitSolutions() {
	SolutionSet.push_back(new SymmetricTree());
	SolutionSet.push_back(new BinaryTreeLevelOrderTraversal());
	SolutionSet.push_back(new BucketSort());
}

void Solution101_150::DeleteSolutions() {
	for(; SolutionSet.size();)
	{
		BasicSolution * last = SolutionSet.back();
		SolutionSet.pop_back();
		delete last;
	}
}
