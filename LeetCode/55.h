/*
    55. Jump Game
*/
class Solution {
 public:
	bool canJump(vector<int>& nums) {
		int canJumpFrom = nums.size() - 1;
		for(int i=nums.size()-2; i>=0; i--){
			if(nums[i] + i >= canJumpFrom)
				canJumpFrom = i;
		}//for
		return canJumpFrom == 0;
	}
};
