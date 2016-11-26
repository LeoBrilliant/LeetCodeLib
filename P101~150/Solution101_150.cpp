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
#include "BinaryTreeZigzagLevelOrderTraversal.h"
#include "MaximumDepthOfBinaryTree.h"
#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.h"
#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.h"
#include "BinaryTreeLevelOrderTraversalII.h"
#include "MinStack.h"
#include "IntersectionOfTwoLinkedLists.h"

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
	SolutionSet.push_back(new BinaryTreeZigzagLevelOrderTraversal());
	SolutionSet.push_back(new MaximumDepthOfBinaryTree());
	SolutionSet.push_back(new ConstructBinaryTreeFromPreorderAndInorderTraversal());
	SolutionSet.push_back(new ConstructBinaryTreeFromInorderAndPostorderTraversal());
	SolutionSet.push_back(new BinaryTreeLevelOrderTraversalII());
	SolutionSet.push_back(new MinStack());
	SolutionSet.push_back(new IntersectionOfTwoLinkedLists());
}

void Solution101_150::DeleteSolutions() {
	for(; SolutionSet.size();)
	{
		BasicSolution * last = SolutionSet.back();
		SolutionSet.pop_back();
		delete last;
	}
}
