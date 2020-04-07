/**
 * LeetCode 16. 3Sum Closest
 */

class Solution {
 public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = target;
		sort(nums.begin(), nums.end());
		int gap = 10000000, sum, offset;
		for(int i=0; i<nums.size()-2; i++){
			if(i>0 && nums[i] == nums[i-1]) continue;
			int L = i+1, R = nums.size()-1;
			while(L < R){
				sum = nums[i] + nums[L] + nums[R];
				offset = abs(sum - target);
				if(offset < gap){
					ans = sum;
					gap = offset;
				}
				if(sum > target){
					while(R-1>L && nums[R-1]==nums[R]) R--;
					R--;
				}else if(sum < target){
					while(L+1<R && nums[L]==nums[L+1]) L++;
					L++;
				}else
					return target;
			}//while
		}//for
		return ans;
	}
};
