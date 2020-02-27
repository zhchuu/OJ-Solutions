#pragma once
#include<iostream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class Solution
{
public:
	Solution();
	~Solution();
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		stack<int> s1, s2;
		int carry = 0, sum = 0, remainder = 0;
		ListNode *p = l1, *q = l2, *dummyhead = new ListNode(0), *Node = NULL, *newNode;
		while (p != NULL) {
			s1.push(p->val); p = p->next;
		}
		while (q != NULL) {
			s2.push(q->val); q = q->next;
		}
		while (!s1.empty() || !s2.empty() || carry > 0) {
			sum = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + carry;
			carry = sum / 10;
			remainder = sum % 10;
			newNode = new ListNode(remainder);
			//连接，前插法
			dummyhead->next = newNode;
			newNode->next = Node;
			Node = newNode;
			if (!s1.empty())	s1.pop();
			if (!s2.empty())	s2.pop();
		}
		return dummyhead->next;
	}
};

