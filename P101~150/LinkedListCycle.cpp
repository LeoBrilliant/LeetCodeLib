/*
 * LinkedListCycle.cpp
 *
 *  Created on: 2016年12月10日
 *      Author: LeoBrilliant
 */

#include "LinkedListCycle.h"

LinkedListCycle::LinkedListCycle() {
	// TODO Auto-generated constructor stub

}

LinkedListCycle::~LinkedListCycle() {
	// TODO Auto-generated destructor stub
}

void LinkedListCycle::TestSuite() {
	vector<int> vi;
	ListNode * head;
	ListNode * tail;
	ListNode * common;
	bool ret;

	cout << "test case 1" << endl;
	vi = {};
	head = GenListFromVector(vi);
	ret = this->hasCycle(head);
	assert(ret == false);

	cout << "test case 2" << endl;
	vi = {1};
	head = GenListFromVector(vi);
	ret = this->hasCycle(head);
	assert(ret == false);

	cout << "test case 3" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	ret = this->hasCycle(head);
	assert(ret == false);

	cout << "test case 4" << endl;
	vi = {1, 2, 3};
	head = GenListFromVector(vi);
	ret = this->hasCycle(head);
	assert(ret == false);

	cout << "test case 5" << endl;
	vi = {1, 2, 3, 4};
	head = GenListFromVector(vi);
	ret = this->hasCycle(head);
	assert(ret == false);

	cout << "test case 6" << endl;
	vi = {1};
	head = GenListFromVector(vi);
	head->next = head;
	ret = this->hasCycle(head);
	assert(ret == true);

	cout << "test case 7" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head;
	ret = this->hasCycle(head);
	assert(ret == true);

	cout << "test case 8" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = tail;
	ret = this->hasCycle(head);
	assert(ret == true);

	cout << "test case 9" << endl;
	vi = {1, 2, 3};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head->next;
	ret = this->hasCycle(head);
	assert(ret == true);

	cout << "test case 10" << endl;
	vi = {1, 2, 3, 4};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head->next;
	ret = this->hasCycle(head);
	assert(ret == true);

	cout << "test case 11" << endl;
	vi = {};
	head = GenListFromVector(vi);
	common = this->detectCycle(head);
	assert(common == NULL);

	cout << "test case 12" << endl;
	vi = {1};
	head = GenListFromVector(vi);
	common = this->detectCycle(head);
	assert(common == NULL);

	cout << "test case 13" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	common = this->detectCycle(head);
	assert(common == NULL);

	cout << "test case 14" << endl;
	vi = {1};
	head = GenListFromVector(vi);
	head->next = head;
	common = this->detectCycle(head);
	assert(common == head);

	cout << "test case 15" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = tail;
	common = this->detectCycle(head);
	assert(common == tail);

	cout << "test case 16" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head;
	common = this->detectCycle(head);
	assert(common == head);

	cout << "test case 17" << endl;
	vi = {1, 2, 3};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head->next;
	common = this->detectCycle(head);
	assert(common == head->next);

	cout << "test case 18" << endl;
	vi = {1, 2, 3};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head;
	common = this->detectCycle(head);
	assert(common == head);

	cout << "test case 19" << endl;
	vi = {1, 2, 3};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = tail;
	common = this->detectCycle(head);
	assert(common == tail);

	cout << "test case 20" << endl;
	vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	head = GenListFromVector(vi);
	tail = GetLastNode(head);
	tail->next = head->next->next->next->next;
	common = this->detectCycle(head);
	assert(common == head->next->next->next->next);
	head = common;
	do{
		cout << head->val << " -> ";
		head = head->next;
	}
	while(head != common);
}
