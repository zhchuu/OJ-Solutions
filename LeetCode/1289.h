/*
    1289. Minimum Falling Path Sum II
    DP
*/
class Solution {
public:
    /*
        Similar to LeetCode 931
        dp[i][j] represents the minimum value(0 ~ i rows) when selecting A[i][j]
        dp[i][j] = A[i][j] + min(dp[i-1][k]) for k != j
    */
    int minFallingPathSum(vector<vector<int>>& arr) {
        int rows = arr.size();
        if(rows == 0)
            return 0;
        int cols = arr[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        for(int j=0; j<cols; j++)
            dp[0][j] = arr[0][j];

        for(int i=1; i<rows; i++){
            for(int j=0; j<cols; j++){
                int res = INT_MAX / 2;
                for(int k=0; k<cols; k++){
                    if(k == j)
                        continue;
                    res = min(res, dp[i-1][k]);
                }
                dp[i][j] = res + arr[i][j];
            }//for
        }//for

        int ans = INT_MAX;
        for(int j=0; j<cols; j++){
            ans = min(ans, dp[rows-1][j]);
        }

        return ans;
    }
};
