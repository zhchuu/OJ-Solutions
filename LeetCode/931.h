/*
    931. Minimum Falling Path Sum
    DP
*/
class Solution {
public:
    /*
        dp[i][j] represents the minimum value(0 ~ i rows) when selecting A[i][j]
        dp[i][j] = A[i][j] + min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1])
    */
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows == 0)
            return 0;
        int cols = A[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        for(int j=0; j<cols; j++)
            dp[0][j] = A[0][j];

        for(int i=1; i<rows; i++){
            for(int j=0; j<cols; j++){
                int left = max(0, j-1);
                int right = min(cols-1, j+1);
                int res = INT_MAX;
                for(int k=left; k<=right; k++){
                    res = min(res, A[i][j] + dp[i-1][k]);
                }//for
                dp[i][j] = res;
            }//for
        }//for

        int ans = INT_MAX;
        for(int j=0; j<cols; j++)
            ans = min(ans, dp[rows-1][j]);

        return ans;
    }
};
