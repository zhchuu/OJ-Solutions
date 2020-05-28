/*
    102. Binary Tree Level Order Traversal
    Time: O(n)
    Space: O(n)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct MyNode {
        TreeNode* r;
        int depth;
    };
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<MyNode> st;
        MyNode node;
        node.r = root;
        node.depth = 0;
        st.push(node);

        while(!st.empty()){
            MyNode node = st.front();
            st.pop();
            if(node.r == NULL)
                continue;
            if(node.depth >= ans.size()){
                vector<int> vec;
                ans.push_back(vec);
            }//if
            ans[node.depth].push_back(node.r->val);

            MyNode nxt_l;
            nxt_l.r = node.r->left;
            nxt_l.depth = node.depth+1;
            st.push(nxt_l);
            
            MyNode nxt_r;
            nxt_r.r = node.r->right;
            nxt_r.depth = node.depth+1;
            st.push(nxt_r);
        }//while
        
        return ans;
    }
};
