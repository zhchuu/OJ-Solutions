/*
    41. First Missing Positive
    Time: O(n)
    Space: O(1)
*/
class Solution {
 public:
	int firstMissingPositive(vector<int>& nums) {
		int ans = nums.size() + 1;
		for(int i=0; i<nums.size(); i++){
			while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
				swap(nums[i], nums[nums[i] - 1]);
		}//for
		for(int i=0; i<nums.size(); i++){
			if(nums[i] != i+1){
				ans = i+1;
				break;
			}
		}//for
		return ans;
	}
};
