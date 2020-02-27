class Solution {
 public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ret;
		perm(ret, nums, 0, nums.size()-1);
		return ret;
	}
	void perm(vector<vector<int>>& ans, vector<int>& nums, int from, int to){
		if(from == to)
			ans.push_back(nums);

		for(int i=from; i<=to; i++){
			swap(nums, from, i);
			perm(ans, nums, from+1, to);
			swap(nums, from, i);
		}
	}

	void swap(vector<int>& nums, int i, int j){
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
};
