/*
    334. Increasing Triplet Subsequence
    Time: O(n)
    Space: O(1)
*/
class Solution {
 public:
	bool increasingTriplet(vector<int>& nums) {
		int small = INT_MAX, medium = INT_MAX;
		for(int i=0; i<nums.size(); i++){
			if(nums[i] < small)
				small = nums[i];
			else if(nums[i] > small && nums[i] < medium)
				medium = nums[i];
			else if(nums[i] > medium)
				return true;
		}//for
		return false;
	}
};
