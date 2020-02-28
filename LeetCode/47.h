/*
 * Leetcode 47.
 */

class Solution {
 private:
	vector<vector<int>> ans;
 public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> list;
		bool used[nums.size()];
		memset(used, 0, sizeof(used));
		dfs(nums, used, list);
		return ans;
	}

	void dfs(vector<int>& nums, bool used[], vector<int>& list){
		if(list.size() == nums.size()){
			ans.push_back(list);
			return;
		}
		for(int i=0; i<nums.size(); i++){
			if(used[i] == true)
				continue;
			if(i>0 && nums[i]==nums[i-1] && !used[i-1])
				continue;
			used[i] = true;
			list.push_back(nums[i]);
			dfs(nums, used, list);
			list.erase(list.end()-1);
			used[i] = false;
		}//for
	}
};
