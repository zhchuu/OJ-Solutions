/*
    105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, 0, inorder.size());
    }

    TreeNode* solve(vector<int>& pre, vector<int>& in, int idxPre, int from, int to){
        if(from >= to)
            return NULL;
        int valRoot = pre[idxPre];
        int idxRoot;
        for(idxRoot=from; idxRoot<to; idxRoot++){
            if(in[idxRoot] == valRoot)
                break;
        }//for

        TreeNode* r = new TreeNode();
        r->val = valRoot;

        r->left = solve(pre, in, idxPre+1, from, idxRoot);
        r->right = solve(pre, in, idxPre + idxRoot-from + 1, idxRoot+1, to);

        return r;
    }
};
