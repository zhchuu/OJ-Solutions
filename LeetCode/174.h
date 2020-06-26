/*
    174. Dungeon Game
    Time: O(n^2)
    Space: O(n^2)
*/
class Solution {
public:
    /*
        dp[i][j] represents the minium health before stepping on board[i][j]
    */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        if(rows == 0)
            return 1;
        int cols = dungeon[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
        dp[rows-1][cols] = 1;
        dp[rows][cols-1] = 1;
        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1; j>=0; j--){
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 1);
            }//for
        }//for
        return dp[0][0];
    }
};
