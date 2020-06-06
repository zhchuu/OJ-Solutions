/*
    236. Lowest Common Ancestor of a Binary Tree
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return false;
        bool foundInLeft = dfs(root->left, p, q);
        bool foundInRight = dfs(root->right, p, q);
        
        bool foundInRoot = false;
        if(root->val == p->val || root->val == q->val)
            foundInRoot = true;

        if((foundInRoot && foundInLeft) || (foundInRoot && foundInRight) || (foundInLeft && foundInRight)){
            ans = root;
        }

        return foundInRoot || foundInLeft || foundInRight;
    }
};
