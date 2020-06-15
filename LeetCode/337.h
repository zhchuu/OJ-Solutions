/*
    337. House Robber III
    DFS with memorization
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
    unordered_map<TreeNode*, int> m1; // NotTakeItMap
    unordered_map<TreeNode*, int> m2;  // TakeItMap
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;

        int ans = dfs(root, 0);
        return ans;
    }

    int dfs(TreeNode* r, int val){
        if(r == NULL)
            return 0;

        int notTakeIt;
        if(m1.find(r) != m1.end())
            notTakeIt = m1[r];
        else{
            notTakeIt = dfs(r->left, val) + dfs(r->right, val);
            m1[r] = notTakeIt;
        }

        int takeIt;
        if(m2.find(r) != m2.end())
            takeIt = m2[r];
        else{
            takeIt = r->val;
            if(r->left != NULL)
                takeIt += dfs(r->left->left, val+r->val) + dfs(r->left->right, val+r->val);
            if(r->right != NULL)
                takeIt += dfs(r->right->left, val+r->val) + dfs(r->right->right, val+r->val);
            m2[r] = takeIt;
        }//if-else

        return max(notTakeIt, takeIt);
    }
};
