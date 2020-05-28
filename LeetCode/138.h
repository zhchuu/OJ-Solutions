/*
    138. Copy List with Random Pointer
    Time: O(n)
    Space: O(n)
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        map<Node*, Node*> m;
        Node* cur = head;
        while(cur != NULL){
            m[cur] = new Node(cur->val);
            cur = cur->next;
        }//while

        cur = head;
        while(cur != NULL){
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }//while

        return m[head];
    }
};
