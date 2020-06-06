/*
    148. Sort List
    Time: O(nlogn)
    Space: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }//while
        prev->next = NULL;  // cut two lists

        ListNode* new_h = mergeSort(head);
        ListNode* new_s = mergeSort(slow);
        
        return merge(new_h, new_s);
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* h;

        if(l1->val <= l2->val){
            h = l1;
            l1 = l1->next;
        }else{
            h = l2;
            l2 = l2->next;
        }

        ListNode* cur = h;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }//while

        if(l1 != NULL)
            cur->next = l1;
        if(l2 != NULL)
            cur->next = l2;

        return h;
    }
};
