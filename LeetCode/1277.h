/*
    1277. Count Square Submatrices with All Ones
*/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int ans = 0;

        for(int i=0; i<rows; i++){
            dp[i][0] = matrix[i][0] == 1 ? 1 : 0;
            ans += dp[i][0];
        }//for
            
        for(int j=1; j<cols; j++){
            dp[0][j] = matrix[0][j] == 1 ? 1 : 0;
            ans += dp[0][j];
        }//for

        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                ans += dp[i][j];
            }//for
        }//for

        return ans;
    }
};
