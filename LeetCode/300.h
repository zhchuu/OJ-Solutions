/*
    300. Longest Increasing Subsequence
    Time: O(nlogn) / O(n^2)
    Space: O(n)
*/

class Solution {
 public:
	int lengthOfLIS(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		// O(n^2)
		// dp[i]: the length of LIS from 0 to i (nums[i] must be the last number)
		/*
        int dp[nums.size()+1], ans=INT_MIN;
        for(int i=0; i<nums.size(); i++)
            dp[i] = 1;
        for(int i=0; i<nums.size(); i++){
		            for(int j=i; j<nums.size(); j++){
					                if(nums[i] < nums[j])
                    dp[j] = max(dp[j], dp[i] + 1);
            }//for
        }//for
        for(int i=0; i<nums.size(); i++)
            ans = max(dp[i], ans);
        return ans;
        */

		// O(nlogn)
		// dp[i]: the last number's index of LIS with length i
		int dp[nums.size()+1], len=0;
		dp[0] = 0;
		for(int i=1; i<nums.size(); i++){
			if(nums[i] > nums[dp[len]]){
				len++;
				dp[len] = i;
			}else{
				int last_idx = binSearch(nums, dp, 0, len, nums[i]);  // find the last index
				dp[last_idx] = i;
			}
		}//for
		return len+1;
	}

	int binSearch(vector<int>& nums, int dp[], int start, int end, int n){
		while(start < end){
			int mid = (end - start) / 2 + start;
			if(nums[dp[mid]] >= n)  // must be >=
				end = mid;
			else
				start = mid+1;
		}//while
		return start;
	}
};
