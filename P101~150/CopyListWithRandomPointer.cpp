/*
 * CopyListWithRandomPointer.cpp
 *
 *  Created on: 2016年12月16日
 *      Author: user
 */

#include "CopyListWithRandomPointer.h"

CopyListWithRandomPointer::CopyListWithRandomPointer() {
	// TODO Auto-generated constructor stub

}

CopyListWithRandomPointer::~CopyListWithRandomPointer() {
	// TODO Auto-generated destructor stub
}

RandomListNode* CopyListWithRandomPointer::GenRandomListNodeFromVector(vector<int>& nums) {
	RandomListNode * ret = NULL;
	RandomListNode * prev = NULL;
	for(auto i : nums)
	{
		RandomListNode * curr = new RandomListNode(i);
		if(prev)
		{
			prev->next = curr;
			prev = prev->next;
		}
		else
		{
			prev = curr;
			ret = prev;
		}
	}
	return ret;
}

void CopyListWithRandomPointer::DumpRandomListNode(RandomListNode* head) {
	cout << "[" ;
	while(head)
	{
		cout << "<";
		cout << head->label << "," ;
		if(head->random)
		{
			cout << head->random->label;
		}
		cout << ">";
		if(head->next)
		{
			cout << ", ";
		}
		head = head->next;
	}
	cout << "]" << endl;
}

int CopyListWithRandomPointer::IsEqualRandomListNode(RandomListNode* l1,
		RandomListNode* l2) {
	int ret = 1;

	while(l1 && l2)
	{
		if(l1->label == l2->label)
		{
			if(l1->random && l2->random)
			{
				if(l1->random->label == l2->random->label)
				{
					l1 = l1->next;
					l2 = l2->next;
				}
				else
				{
					ret = 0;
					break;
				}
			}
 			else if(!l1->random && !l2->random)
			{
 				l1 = l1->next;
 				l2 = l2->next;
			}
 			else
 			{
 				ret = 0;
 				break;
 			}
		}
		else
		{
			ret = 0;
			break;
		}
	}

	if(ret == 1 && (l1 || l2))
	{
		ret = 0;
	}
	return ret;
}

void CopyListWithRandomPointer::SetRandomPointerByIndex(RandomListNode* head,
		vector<int>& index) {
	vector<RandomListNode*> table;
	RandomListNode * curr = head;
	while(curr)
	{
		table.push_back(curr);
		curr = curr->next;
	}

	int n = index.size();
	if(n > table.size())
	{
		n = table.size();
	}

	curr = head;
	for(int i = 0; i < n; ++i)
	{
		if(index[i] >= 0)
		{
			curr->random = table[index[i]];
		}
		curr = curr->next;
	}
}

void CopyListWithRandomPointer::TestSuite() {
	RandomListNode * head;
	RandomListNode * cpy;
	vector<int> nums;
	vector<int> index;

	cout << "test case 1" << endl;
	nums = {};
	head = this->GenRandomListNodeFromVector(nums);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 2" << endl;
	nums = {1};
	head = this->GenRandomListNodeFromVector(nums);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 3" << endl;
	nums = {1, 2};
	head = this->GenRandomListNodeFromVector(nums);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 4" << endl;
	nums = {1, 2, 3, 4};
	head = this->GenRandomListNodeFromVector(nums);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 5" << endl;
	nums = {1};
	index = {0};
	head = this->GenRandomListNodeFromVector(nums);
	this->SetRandomPointerByIndex(head, index);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 6" << endl;
	nums = {1, 2};
	index = {1, 0};
	head = this->GenRandomListNodeFromVector(nums);
	this->SetRandomPointerByIndex(head, index);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 7" << endl;
	nums = {1, 2};
	index = {1, 1};
	head = this->GenRandomListNodeFromVector(nums);
	this->SetRandomPointerByIndex(head, index);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));

	cout << "test case 8" << endl;
	nums = {1, 2, 3};
	index = {1, 0, -1};
	head = this->GenRandomListNodeFromVector(nums);
	this->SetRandomPointerByIndex(head, index);
	cpy = this->copyRandomList(head);
	this->DumpRandomListNode(head);
	this->DumpRandomListNode(cpy);
	assert(this->IsEqualRandomListNode(head, cpy));
}
