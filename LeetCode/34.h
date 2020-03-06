class Solution {
 private:
	vector<int> ans;
 public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if(nums.size() == 0){
			ans.push_back(-1);
			ans.push_back(-1);
			return ans;
		}
		binSearch(nums, target, 0, nums.size()-1);
		return ans;
	}

	void binSearch(vector<int>& nums, int target, int from, int to){
		int mid = from + (to - from + 1) / 2;
		if(nums[mid] == target){
			int k = mid;
			while(k >= 0 && nums[k] == target)
				k--;
			ans.push_back(k+1);
			k = mid;
			while(k < nums.size() && nums[k] == target)
				k++;
			ans.push_back(k-1);
			return;
		}
		if(from >= to){
			ans.push_back(-1);
			ans.push_back(-1);
			return;
		}
		if(nums[mid] > target)
			binSearch(nums, target, from, mid-1);
		else
			binSearch(nums, target, mid, to);
	}
};
