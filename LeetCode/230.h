/*
    230. Kth Smallest Element in a BST
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
    vector<int> trav;
    int kthSmallest(TreeNode* root, int k) {
        inOrderTrav(root);
        return trav[k-1];
    }

    void inOrderTrav(TreeNode* root){
        if(root == NULL)
            return;
        inOrderTrav(root->left);
        trav.push_back(root->val);
        inOrderTrav(root->right);
    }
};
