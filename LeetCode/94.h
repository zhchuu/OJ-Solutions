/*
    94. Binary Tree Inorder Traversal
    Time: O(n)
    Space: O(logn)
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode* r){
        if(r == NULL)
            return;
        inOrder(r->left);
        ans.push_back(r->val);
        inOrder(r->right);
    }
};
