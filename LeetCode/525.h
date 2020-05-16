/*
    525. Contiguous Array
    Time: O(n)
    Space: O(n)
*/
class Solution {
 public:
	int findMaxLength(vector<int>& nums) {
		int ans = 0, curSum = 0;
		int pos[nums.size()*2+1];
		for(int i=0; i<2*nums.size(); i++)
			pos[i] = -2;
		pos[nums.size()] = -1;

		for(int i=0; i<nums.size(); i++){
			curSum += (nums[i] == 1 ? 1:-1);
			if(pos[curSum + nums.size()] >= -1)
				ans = max(ans, i-pos[curSum + nums.size()]);
			else
				pos[curSum + nums.size()] = i;
		}//for

		return ans;
	}
};
