/*
 * LeetCode 53.Maximum Subarray
 * Hint: dp
 * */

#include<vector>
#include<memory.h>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int dp[100000+5];
        int ret = nums[0];
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
