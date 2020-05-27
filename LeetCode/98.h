/*
    98. Validate Binary Search Tree
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
    vector<int> inOrderTra;
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        inOrder(root);
        for(int i=0; i<inOrderTra.size()-1; i++){
            if(inOrderTra[i] >= inOrderTra[i+1])
                return false;
        }//for
        return true;
    }

    void inOrder(TreeNode* r){
        if(r == NULL)
            return;
        inOrder(r->left);
        inOrderTra.push_back(r->val);
        inOrder(r->right);
    }
};
