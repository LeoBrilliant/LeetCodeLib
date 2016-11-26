/*
 * IntersectionOfTwoLinkedLists.cpp
 *
 *  Created on: 2016年11月26日
 *      Author: user
 */

#include "IntersectionOfTwoLinkedLists.h"

IntersectionOfTwoLinkedLists::IntersectionOfTwoLinkedLists() {
	// TODO Auto-generated constructor stub

}

IntersectionOfTwoLinkedLists::~IntersectionOfTwoLinkedLists() {
	// TODO Auto-generated destructor stub
}

void IntersectionOfTwoLinkedLists::TestSuite() {
	vector<int> a, b, c;
	ListNode * la, * lb, * lc;
	ListNode * ha, * hb, * hc, * ret;

	int lenA, lenB, lenC, lenR;

	cout << "test case 1" << endl;
	a = {};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	assert(ha == NULL);
	assert(la == NULL);
	assert(lenA == 0);

	cout << "test case 2" << endl;
	a = {1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	assert(ha != NULL);
	assert(ha->val == 1);
	assert(la == ha);
	assert(lenA == 1);

	cout << "test case 3" << endl;
	a = {1, 2};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	assert(ha != NULL);
	assert(ha->val == 1);
	assert(la != NULL);
	assert(la->val == 2);
	assert(ha->next == la);
	assert(lenA == 2);

	cout << "test case 4" << endl;
	a = {1, 2, 3};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	assert(ha != NULL);
	assert(ha->val == 1);
	assert(la != NULL);
	assert(la->val == 3);
	assert(ha->next->next == la);
	assert(lenA == 3);

	cout << "test case 5" << endl;
	a = {1, 2, 3};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	assert(ha != NULL);
	assert(ha->val == 1);
	assert(la != NULL);
	assert(la->val == 3);
	assert(ha->next->next == la);
	assert(lenA == 3);
	b = {4, 5, 6};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	assert(hb != NULL);
	assert(hb->val == 4);
	assert(lb != NULL);
	assert(lb->val == 6);
	assert(hb->next->next == lb);
	assert(lenB == 3);
	la->next = hb;
	lenA = GetListLen(ha);
	la = GetLastNode(ha);
	assert(lenA == 6);
	assert(la == lb);

	cout << "test case 6" << endl;
	a = {};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	ret = this->getIntersectionNode(ha, hb);
	assert(ret == NULL);

	cout << "test case 7" << endl;
	a = {1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	ret = this->getIntersectionNode(ha, hb);
	assert(ret == NULL);

	cout << "test case 8" << endl;
	a = {};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {1};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	ret = this->getIntersectionNode(ha, hb);
	assert(ret == NULL);

	cout << "test case 9" << endl;
	a = {1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {2};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	ret = this->getIntersectionNode(ha, hb);
	assert(ret == NULL);

	cout << "test case 10" << endl;
	a = {1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {2};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	la->next = hb;
	ret = this->getIntersectionNode(ha, hb);
	lenR = GetListLen(ret);
	assert(ret == hb);
	assert(lenR == lenB);

	cout << "test case 10" << endl;
	a = {1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {2};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	lb->next = ha;
	ret = this->getIntersectionNode(ha, hb);
	lenR = GetListLen(ret);
	assert(ret == ha);
	assert(lenR == lenA);

	cout << "test case 11" << endl;
	a = {1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {2};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	c = {3};
	hc = GenListFromVector(c);
	lc = GetLastNode(hc);
	lenC = GetListLen(hc);
	lb->next = hc;
	la->next = hc;
	ret = this->getIntersectionNode(ha, hb);
	lenR = GetListLen(ret);
	assert(ret == hc);
	assert(lenR == lenC);

	cout << "test case 12" << endl;
	a = {-1, 0, 1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {2, 3};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	c = {4, 5, 6};
	hc = GenListFromVector(c);
	lc = GetLastNode(hc);
	lenC = GetListLen(hc);
	lb->next = hc;
	la->next = hc;
	ret = this->getIntersectionNode(ha, hb);
	lenR = GetListLen(ret);
	assert(ret == hc);
	assert(lenR == lenC);

	cout << "test case 13" << endl;
	a = {0, 1};
	ha = GenListFromVector(a);
	la = GetLastNode(ha);
	lenA = GetListLen(ha);
	b = {1, 2, 3};
	hb = GenListFromVector(b);
	lb = GetLastNode(hb);
	lenB = GetListLen(hb);
	c = {4, 5, 6};
	hc = GenListFromVector(c);
	lc = GetLastNode(hc);
	lenC = GetListLen(hc);
	lb->next = hc;
	la->next = hc;
	ret = this->getIntersectionNode(ha, hb);
	lenR = GetListLen(ret);
	assert(ret == hc);
	assert(lenR == lenC);
}
