/*
 * Solution101150.cpp
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#include "Solution101_150.h"/*
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
#include "MinimumDepthOfBinaryTree.h"
#include "BalancedBinaryTree.h"
#include "EvaluateReversePolishNotation.h"
#include "ConvertSortedArrayToBinarySearchTree.h"
#include "ConvertSortedListToBinarySearchTree.h"
#include "PathSum.h"
#include "PathSumII.h"
#include "FlattenBinaryTreeToLinkedList.h"
#include "PascalsTriangle.h"
#include "BestTimeToBuyAndSellStock.h"
#include "SingleNumber.h"
#include "BestTimeToBuyAndSellStockII.h"
#include "Triangle.h"*/
#include "BestTimeToBuyAndSellStockIII.h"
#include "ValidPalindrome.h"
#include "LinkedListCycle.h"
#include "WordBreak.h"
#include "SumRootToLeafNumbers.h"
#include "SingleNumberII.h"
#include "CopyListWithRandomPointer.h"
#include "MajorityElement.h"

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

void Solution101_150::InitSolutions() {/*
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
	SolutionSet.push_back(new MinimumDepthOfBinaryTree());
	SolutionSet.push_back(new BalancedBinaryTree());
	SolutionSet.push_back(new EvaluateReversePolishNotation());
	SolutionSet.push_back(new ConvertSortedArrayToBinarySearchTree());
	SolutionSet.push_back(new ConvertSortedListToBinarySearchTree());
	SolutionSet.push_back(new PathSum());
	SolutionSet.push_back(new PathSumII());
	SolutionSet.push_back(new FlattenBinaryTreeToLinkedList());
	SolutionSet.push_back(new PascalsTriangle());
	SolutionSet.push_back(new BestTimeToBuyAndSellStock());
	SolutionSet.push_back(new SingleNumber());
	SolutionSet.push_back(new BestTimeToBuyAndSellStockII());
	SolutionSet.push_back(new Triangle());*/
	SolutionSet.push_back(new BestTimeToBuyAndSellStockIII());
	SolutionSet.push_back(new ValidPalindrome());
	SolutionSet.push_back(new LinkedListCycle());
	SolutionSet.push_back(new SingleNumberII());
	SolutionSet.push_back(new CopyListWithRandomPointer());
	SolutionSet.push_back(new SumRootToLeafNumbers());
	SolutionSet.push_back(new WordBreak());
	SolutionSet.push_back(new MajorityElement());
}

void Solution101_150::DeleteSolutions() {
	for(; SolutionSet.size();)
	{
		BasicSolution * last = SolutionSet.back();
		SolutionSet.pop_back();
		delete last;
	}
}
