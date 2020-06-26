/*
    746. Min Cost Climbing Stairs
    DP
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0 || n == 1)
            return 0;
        if(n == 2)
            return min(cost[0], cost[1]);
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++){
            dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
        }//for
        return min(dp[n-1], dp[n-2]);
    }
};
