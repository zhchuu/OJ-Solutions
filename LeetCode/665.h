/*
    665. Non-decreasing Array
*/
class Solution {
 public:
	bool checkPossibility(vector<int>& nums) {
		int times = 0;
		for(int i=0; i<nums.size()-1 && times<=1; i++){
			if(nums[i] <= nums[i+1])
				continue;
			if(i==0){
				times++;
				continue;
			}else if(i+2 >= nums.size() || i+2 < nums.size() && nums[i] <= nums[i+2]){
				nums[i+1] = nums[i];
				times++;
			}else if(nums[i-1] <= nums[i+1]){
				nums[i] = nums[i-1];
				times++;
			}else
				return false;
		}//for
		return times<=1;
	}
};
