/*
 * Leetcode 24.Swap Nodes in Pairs
 * */

#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* pre = NULL;
        ListNode* newHead = right;
        while(left != NULL && right != NULL){
            left->next = right->next;
            right->next = left;
            if(pre != NULL)
                pre->next = right;
            if(left->next == NULL)
                break;
            pre = left;
            left = left->next;
            right = left->next;
        }
        return newHead;
    }
};

int main(){
	return 0;
}

