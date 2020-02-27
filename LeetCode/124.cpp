/*
 * LeetCode 124.Binary Tree Maximum Path Sum
 * */

#include<algorithm>
#include<math.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    int ans;
    int maxPathSum(TreeNode* root){
        ans = root->val;
        maxPathBelow(root);
        return ans;
    }

    int maxPathBelow(TreeNode* node){
        if(node == NULL)
            return 0;
        int left = maxPathBelow(node->left);
        int right = maxPathBelow(node->right);
        int maxValueHere = max(max(left, right) + node->val, node->val);//node may be negative integer
        ans = max(ans, max(left + right + node->val, maxValueHere));
        return maxValueHere;
    }
};
