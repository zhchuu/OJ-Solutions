/**
 * 25. Reverse Nodes in k-Group
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * new_head = reverse(head, k);
        return new_head;
    };
public:
    ListNode* reverse(ListNode* group_head, int k) {
        ListNode* nxt_head = group_head;
        for(int i=0; i<k; i++){
            if(nxt_head != NULL)
                nxt_head = nxt_head->next;
        }
        ListNode* new_group_head;
        if(nxt_head != NULL)
            new_group_head = reverse(nxt_head, k);
        
        if(nxt_head == NULL){
            int cnt = 0;
            ListNode* pos = group_head;
            while(pos != NULL){
                cnt += 1;
                pos = pos->next;
            }
            if(cnt < k)
                return group_head;
            else
                new_group_head = nxt_head;
        }
        
        ListNode* nxt = new_group_head;
        ListNode* cur = group_head;
        ListNode* pos = group_head->next;
        cur->next = nxt;
        for(int i=1; i<k; i++){
            nxt = cur;
            cur = pos;
            pos = pos->next;
            cur->next = nxt;
        }
        return cur;
    };
};
