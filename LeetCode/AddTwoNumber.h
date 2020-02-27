#pragma once
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
	Solution();
	~Solution();
	ListNode* addTwoNumbers(ListNode* l1, ListNode *l2)
	{
		int carry = 0;//��λ
		ListNode *p = l1, *q = l2;
		ListNode *temp = NULL, *head = NULL;//tempʵ��������β
		while (p != NULL && q != NULL)
		{
			ListNode *L = new ListNode((p->val + q->val + carry) % 10);
			if (temp != NULL)
				temp->next = L;//����һ�������������
			else
				temp = head = L;//���temp==NULL����ôLΪͷ���
			temp = L;
			if ((p->val + q->val + carry) >= 10)//�жϽ�λ
				carry = 1;
			else
				carry = 0;
			p = p->next;
			q = q->next;//��һ�����
		}//while
		//��ʱ��һ�����ΪNULL��ʣ�µĽ����Ҫ������ӣ�������carry
		if (p == NULL&&q != NULL)//l1��Ϊ��
		{
			while(q!=NULL)
			{
				ListNode *L = new ListNode((q->val + carry) % 10);
				temp->next = L;
				temp = L;
				if (q->val + carry >= 10)
					carry = 1;
				else
					carry = 0;
				q = q->next;
			}//while
		}//if
		else if(p != NULL&&q == NULL)//l2��Ϊ��
		{
			while (p != NULL)
			{
				ListNode *L = new ListNode((p->val + carry) % 10);
				temp->next = L;
				temp = L;
				if (p->val + carry >= 10)
					carry = 1;
				else
					carry = 0;
				p = p->next;
			}//while
		}//else if
		//����һ����������һλ����󣬻��н�λ
		if (p == NULL&&q == NULL)
		{
			if (carry == 1)
			{
				ListNode *L = new ListNode(1);
				temp->next = L;
			}
		}
		return head;
	}
	ListNode* addTwoNumbers_2(ListNode* l1, ListNode*l2)
	{
		int carry = 0, sum = 0, remainder = 0;//��λ���ܺ͡�ʣ����
		ListNode *p = l1, *q = l2;
		ListNode *dummyhead = new ListNode(0), *Node = dummyhead;
		while (p != NULL || q != NULL || carry != 0)
		{
			sum = (q != NULL ? q->val : 0) + (p != NULL ? p->val : 0) + carry;
			carry = sum / 10;//��λ
			remainder = sum % 10;//ʣ����
			Node = Node->next = new ListNode(remainder);
			p = (p != NULL ? p->next : NULL);
			q = (q != NULL ? q->next : NULL);
		}
		return dummyhead->next;
	}
};

/**
 *You are given two non-empty linked lists representing two non-negative integers.
 *The digits are stored in reverse order and each of their nodes contain a single digit. 
 *Add the two numbers and return it as a linked list.
 *You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *Output: 7 -> 0 -> 8
 */

