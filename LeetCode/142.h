/*
    142. Linked List Cycle II
    Time: O(n)
    Space: O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return NULL;
        ListNode *pFast = head->next->next;
        ListNode *pSlow = head;
        while(pFast != pSlow){
            if(pFast == NULL || pFast->next == NULL)
                return NULL;
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }//while
        int cnt = 1;
        pFast = pFast->next;
        while(pFast != pSlow){
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            cnt++;
        }//while
        
        //cout << cnt << endl;
        
        pFast = head;
        pSlow = head;
        for(int i=0; i<cnt; i++)
            pFast = pFast->next;

        while(pFast != pSlow){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }//while

        return pFast;
    }
};
