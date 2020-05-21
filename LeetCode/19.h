/*
    19. Remove Nth Node From End of List
    Time: O(n)
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pFast = head;
		ListNode* pSlow = head;
		for(int i=0; i<n; i++)
			pFast = pFast->next;
		if(pFast == NULL)
			return head->next;

		ListNode* pre = head;
		pSlow = pSlow->next;
		pFast = pFast->next;
		while(pFast != NULL){
			pFast = pFast->next;
			pSlow = pSlow->next;
			pre = pre->next;
		}//while
		pre->next = pSlow->next;
		pSlow->next = NULL;
		return head;
	}
};
