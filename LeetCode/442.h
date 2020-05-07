/*
    442. Find All Duplicates in an Array
    Time: O(n)
    Space: O(1)
*/

class Solution {
 public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> ans;
		for(int i=0; i<nums.size(); i++){
			int pos = abs(nums[i]) - 1;
			if(nums[pos] > 0)
				nums[pos] = -nums[pos];
			else
				ans.push_back(pos+1);
		}//for
		return ans;
	}
};
