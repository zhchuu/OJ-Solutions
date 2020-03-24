/*
 * LeetCode 21. Merge Two Sorted Lists
 */
class Solution {
 public:
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
