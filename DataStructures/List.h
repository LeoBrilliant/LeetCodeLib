/*
 * List.h
 *
 *  Created on: 2016年11月18日
 *      Author: user
 */

#ifndef DATASTRUCTURES_LIST_H_
#define DATASTRUCTURES_LIST_H_

#include "BasicHeaders.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * GenListFromVector(vector<int> & nums);

void DumpListNode(ListNode * head);

void DumpListNode(ListNode * head, ListNode * tail);


#endif /* DATASTRUCTURES_LIST_H_ */
