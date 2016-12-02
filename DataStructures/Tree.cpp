/*
 * Tree.cpp
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#include "Tree.h"
#include "VectorFuncs.h"

// 根节点的索引是1
TreeNode* GenBinaryTreeFromMap(map<int, int>& nodes) {
	TreeNode * root = NULL;
	TreeNode * curr = NULL;

	int leftindex = -1;
	int rightindex = -1;

	list<TreeNode *> buffer;

	for(auto node : nodes)
	{
		if(!root)
		{
			curr = new TreeNode(node.second);
			root = curr;
			buffer.push_back(root);
		}

		curr = buffer.front();
		leftindex = node.first * 2;
		rightindex = node.first * 2 + 1;

		if(nodes.find(leftindex) != nodes.end())
		{
			TreeNode * left = new TreeNode(nodes[leftindex]);
			curr->left = left;
			buffer.push_back(left);
		}

		if(nodes.find(rightindex) != nodes.end())
		{
			TreeNode * right = new TreeNode(nodes[rightindex]);
			curr->right = right;
			buffer.push_back(right);
		}

		buffer.pop_front();
	}

	return root;
}

void InOrderTraversalHandler(TreeNode* root) {
	if(!root)
		return;

	if(root->left)
		InOrderTraversalHandler(root->left);
	cout << root->val << ", ";
	if(root->right)
		InOrderTraversalHandler(root->right);
}

void InOrderTraversal(TreeNode* root)
{
	cout << "[ ";
	InOrderTraversalHandler(root);
	cout << "] " << endl;
}

void PreOrderTraversalHandler(TreeNode* root) {
	if(!root)
		return;
	cout << root->val << ", ";

	PreOrderTraversalHandler(root->left);

	if(root->right)
		PreOrderTraversalHandler(root->right);
}

void PreOrderTraversal(TreeNode* root)
{
	cout << "[ ";
	PreOrderTraversalHandler(root);
	cout << "] " << endl;
}

void PostOrderTraversalHandler(TreeNode* root) {
	if(!root)
		return;
	if(root->left)
		PostOrderTraversalHandler(root->left);

	if(root->right)
		PostOrderTraversalHandler(root->right);

	cout << root->val << ", ";

}

void PostOrderTraversal(TreeNode* root)
{
	cout << "[ ";
	PostOrderTraversalHandler(root);
	cout << "] " << endl;
}

void BreadthTraversal(TreeNode* root) {
	if(!root)
		return;

	list<TreeNode *> buffer;
	vector<int> value;

	buffer.push_back(root);

	while(!buffer.empty())
	{
		TreeNode * curr = buffer.front();
		if(curr->left)
			buffer.push_back(curr->left);
		if(curr->right)
			buffer.push_back(curr->right);

		value.push_back(curr->val);
		buffer.pop_front();
	}

	DumpVector(value);
}

void InOrderTraversal(TreeNode* root, vector<int>& buf) {
	if(!root)
		return;

	if(root->left)
		InOrderTraversal(root->left, buf);
	buf.push_back(root->val);
	if(root->right)
		InOrderTraversal(root->right, buf);
}

void PreOrderTraversal(TreeNode* root, vector<int>& buf) {
	if(!root)
		return;

	buf.push_back(root->val);
	if(root->left)
		PreOrderTraversal(root->left, buf);
	if(root->right)
		PreOrderTraversal(root->right, buf);
}

void PostOrderTraversal(TreeNode* root, vector<int>& buf) {
	if(!root)
		return;

	if(root->left)
		PostOrderTraversal(root->left, buf);
	if(root->right)
		PostOrderTraversal(root->right, buf);
	buf.push_back(root->val);
}

void BreadthTraversal(TreeNode* root, vector<int>& buf) {
	if(!root)
		return;

	list<TreeNode *> buffer;

	buffer.push_back(root);

	while(!buffer.empty())
	{
		TreeNode * curr = buffer.front();
		if(curr->left)
			buffer.push_back(curr->left);
		if(curr->right)
			buffer.push_back(curr->right);

		buf.push_back(curr->val);
		buffer.pop_front();
	}
}

void BreadthTraversal(TreeNode* root, vector<pair<int, int> >& buf) {
	if(!root)
		return;

	list<pair<int, TreeNode*>> buffer;

	buffer.push_back(make_pair(1, root));
	buffer.push_back(make_pair(-1, (TreeNode*)NULL));

	pair<int, TreeNode*> curr;
	while(!buffer.empty())
	{
		curr = buffer.front();
		if(curr.first != -1)
		{
			if(curr.second->left)
				buffer.push_back(make_pair(curr.first * 2, curr.second->left));
			if(curr.second->right)
				buffer.push_back(make_pair(curr.first * 2 + 1, curr.second->right));

			buf.push_back(make_pair(curr.first, curr.second->val));
		}
		else
		{
			if(buffer.size() > 1)
			{
				buffer.push_back(make_pair(-1, (TreeNode*)NULL));
			}
			buf.push_back(make_pair(-1, -1));
		}
		buffer.pop_front();
	}
}

void DumpTreeByPosition(TreeNode* root) {
	vector<pair<int, int>> buf;
	BreadthTraversal(root, buf);
	DumpTreeByPosition(buf);
}

void DumpTreeByPosition(vector<pair<int, int> >& buf) {
	cout << "[";
	size_t i = 1;
	for(auto t : buf)
	{
		if(t.first != -1)
		{
			cout << "<" << t.first << ", " << t.second << ">";
			if(i < buf.size())
			{
				cout << ", ";
			}
		}
		else
		{
			cout << endl;
		}
		++i;
	}
	cout << "]" << endl;
}
