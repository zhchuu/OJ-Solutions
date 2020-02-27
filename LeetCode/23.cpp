/*
 * Leetcode 23.Merge k Sorted Lists
 * */

#include<stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> num;
        for(int i=0; i<lists.size(); i++){
            ListNode* node = lists[i];
            while(node!=NULL){
                num.push_back(node->val);
                node = node->next;
            }
        }
        sort(num.begin(), num.end());
        vector<int>::iterator it;
        ListNode dummy(0);
        ListNode *pos = &dummy;
        for(it=num.begin(); it!=num.end(); it++){
            ListNode temp = ListNode(*it);
            pos->next = &temp;
            pos = pos->next;
        }
        return dummy.next;
    }
};
