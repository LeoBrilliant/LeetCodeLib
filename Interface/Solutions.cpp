/*
 * Solutions.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#include "Solutions.h"

#include "../P101~150/Solution101_150.h"

Solutions::Solutions() {
	// TODO Auto-generated constructor stub
	InitSolutionCollections();
}

Solutions::~Solutions() {
	// TODO Auto-generated destructor stub
	DeleteSolutionCollections();
}

void Solutions::TestLastSolutions() {
	if(Sols.size())
	{
		SolutionCollections * last = Sols.back();
		last->RunLastTestSuite();
	}
}
void Solutions::InitSolutionCollections() {
	Sols.push_back(new Solution101_150());
}

void Solutions::DeleteSolutionCollections() {
	for(; Sols.size();)
	{
		SolutionCollections * last = Sols.back();
		Sols.pop_back();
		delete last;
	}
}
