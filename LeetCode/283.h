/*
    283. Move Zeroes
    Time: O(n)
    Space: O(1)
*/
class Solution {
 public:
	void moveZeroes(vector<int>& nums) {
		int pFirstZero, pos;
		for(pFirstZero=0; pFirstZero<nums.size(); pFirstZero++)
			if(nums[pFirstZero] == 0)
				break;
		for(pos=pFirstZero+1; pos<nums.size(); pos++){
			if(nums[pos] != 0){
				int tmp = nums[pos];
				nums[pos] = nums[pFirstZero];
				nums[pFirstZero] = tmp;
				pFirstZero++;
			}//if
		}//for
	}
};
