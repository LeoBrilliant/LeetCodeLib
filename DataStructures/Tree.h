/*
 * Tree.h
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#ifndef TREE_H_
#define TREE_H_

#include "BasicHeaders.h"

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode * GenBinaryTreeFromMap(map<int, int> & nodes);

void InOrderTraversal(TreeNode * root);
void PreOrderTraversal(TreeNode * root);
void PostOrderTraversal(TreeNode * root);
void BreadthTraversal(TreeNode * root);

void InOrderTraversal(TreeNode * root, vector<int> & buf);
void PreOrderTraversal(TreeNode * root, vector<int> & buf);
void PostOrderTraversal(TreeNode * root, vector<int> & buf);
void BreadthTraversal(TreeNode * root, vector<int> & buf);
void BreadthTraversal(TreeNode * root, vector<pair<int, int>> & buf);

void DumpTreeByPosition(TreeNode * root);
void DumpTreeByPosition(vector<pair<int, int>> & buf);

#endif /* TREE_H_ */
