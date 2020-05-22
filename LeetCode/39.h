/*
    39. Combination Sum
*/
class Solution {
 public:
	vector<vector<int>> ans;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> tmp;
		dfs(candidates, 0, tmp, target);
		return ans;
	}

	void dfs(vector<int>& candidates, int startp, vector<int> cur, int left){
		if(left < 0)
			return;
		if(left == 0){
			ans.push_back(cur);
			return;
		}//if
		for(int i=startp; i<candidates.size(); i++){
			cur.push_back(candidates[i]);
			left -= candidates[i];
			dfs(candidates, i, cur, left);
			left += candidates[i];
			cur.pop_back();
		}
	}
};
