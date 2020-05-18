/*
    1008. Construct Binary Search Tree from Preorder Traversal
    Time: O(n)
    Space: O(1)
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
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		if(preorder.empty())
			return NULL;
		return mySolve(preorder, 0, preorder.size());
	}

	TreeNode* mySolve(vector<int>& preorder, int start, int end){
		if(start >= end)
			return NULL;
		TreeNode *root = new TreeNode(preorder[start]);

		int pos = end;
		for(int i=start+1; i<end; i++){
			if(preorder[i] > preorder[start]){
				pos = i;
				break;
			}
		}//for

		root->left = mySolve(preorder, start+1, pos);
		root->right = mySolve(preorder, pos, end);

		return root;
	}
};
