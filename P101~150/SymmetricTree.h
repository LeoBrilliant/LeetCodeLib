/*
 * SymmetricTree.h
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#ifndef P101_150_SYMMETRICTREE_H_
#define P101_150_SYMMETRICTREE_H_

#include "../Interface/BasicSolution.h"

class SymmetricTree: public BasicSolution {
public:
	SymmetricTree();
	virtual ~SymmetricTree();
	bool IsSymmetricHelper(TreeNode * t1, TreeNode * t2);
	bool isSymmetric(TreeNode* root);
	void TestSuite();
};

#endif /* P101_150_SYMMETRICTREE_H_ */
