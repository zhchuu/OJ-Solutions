/*
    114. Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;

        flatten(root->left);
        flatten(root->right);
        
        if(root->left == NULL)  // Only need right tree
            return;

        // Concatenate tree
        TreeNode* tmpRight = root->right;
        TreeNode* tmpLeft = root->left;
        root->right = tmpLeft;
        root->left = NULL;
        while(tmpLeft->right != NULL)
            tmpLeft = tmpLeft->right;
        tmpLeft->right = tmpRight;
    }
};
