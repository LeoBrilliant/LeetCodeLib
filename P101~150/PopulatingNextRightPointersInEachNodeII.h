/*
 * PopulatingNextRightPointersInEachNodeII.h
 *
 *  Created on: 2016年12月5日
 *      Author: user
 */

#ifndef P101_150_POPULATINGNEXTRIGHTPOINTERSINEACHNODEII_H_
#define P101_150_POPULATINGNEXTRIGHTPOINTERSINEACHNODEII_H_

#include "../Interface/BasicSolution.h"

class PopulatingNextRightPointersInEachNodeII: public BasicSolution {
public:
	PopulatingNextRightPointersInEachNodeII();
	virtual ~PopulatingNextRightPointersInEachNodeII();

	// Definition for binary tree with next pointer.
	struct TreeLinkNode {
		int val;
		TreeLinkNode *left, *right, *next;
		TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	};

	TreeLinkNode * GetFirstSon(TreeLinkNode * root)
	{
		TreeLinkNode * son = NULL;
		TreeLinkNode * curr = root;
		if(curr)
		{
/*			if(curr->left)
			{
				son = curr->left;
			}
			else if(curr->right)
			{
				son = curr->right;
			}*/
			son = curr->left ? curr->left : curr->right;
		}
		return son;
	}

	TreeLinkNode * GetFirstSiblingHasSon(TreeLinkNode * root)
	{
		TreeLinkNode * sibling = NULL;
		if(root)
		{
			sibling = root->next;
			while(sibling)
			{
				if(sibling->left || sibling->right)
				{
					break;
				}
				else
				{
					sibling = sibling->next;
				}
			}
		}
		return sibling;
	}

	TreeLinkNode * GetFirstSonOfNextLevel(TreeLinkNode * root)
	{
		TreeLinkNode * son = NULL;
		TreeLinkNode * curr = root;
		while(curr)
		{
			if(curr->left)
			{
				son = curr->left;
				break;
			}
			else if(curr->right)
			{
				son = curr->right;
				break;
			}
			else
			{
				curr = curr->next;
			}
		}
		return son;
	}

	void connect(TreeLinkNode *root) {
		if(!root)
			return;

		TreeLinkNode * curr = root;
		TreeLinkNode * son = GetFirstSon(root);
		TreeLinkNode * sibling = root->next;
		TreeLinkNode * firstSon = son;

		while(firstSon)
		{
			while(curr)
			{
				son = GetFirstSon(curr);
				sibling = GetFirstSiblingHasSon(curr);

				if(son)
				{
					if(son == curr->left)
					{
						if(curr->right)
						{
							son->next = curr->right;
							son = curr->right;
						}
					}
					if(sibling)
					son->next = GetFirstSon(sibling);
				}
				curr = sibling;
			}

			curr = firstSon;
			if(curr)
			firstSon = GetFirstSonOfNextLevel(curr);
		}
	}

};

#endif /* P101_150_POPULATINGNEXTRIGHTPOINTERSINEACHNODEII_H_ */
