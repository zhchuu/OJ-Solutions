/*
 * 23. Merge k Sorted Lists
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0)
			return NULL;
		int interval = 1, s = lists.size();
		while(interval < s){
			for(int i=0; i+interval<s; i+=2*interval){
				lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
			}//for
			interval *= 2;
		}//while
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* head;
		ListNode* h;
		if(p==NULL || q==NULL) return l1?l1:l2;
		if(p->val < q->val){
			head = p;
			p = p->next;
		}else{
			head = q;
			q = q->next;
		}
		h = head;
		while(p&&q){
			if(q->val < p->val){
				h->next = q;
				q = q->next;
			}else if(p->val <= q->val){
				h->next = p;
				p = p->next;
			}
			h = h->next;
		}//while
		h->next = p?p:q;

		return head;
	}
};
